//
//  Licensed to the Apache Software Foundation (ASF) under one or more
//  contributor license agreements.  See the NOTICE file distributed with
//  this work for additional information regarding copyright ownership.
//  The ASF licenses this file to You under the Apache License, Version 2.0
//  (the "License"); you may not use this file except in compliance with
//  the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#include "NRS.hpp"
#include "CFS.hpp"
#include "CMS.hpp"
#include "ENDF.hpp"
#include "XRS.hpp"
#include "DBS.hpp"

#include <iomanip>
#include <iostream>
#include <set>
#include <map>


// Implementation of CFS angular distribution
CFSAngularDistribution::~CFSAngularDistribution() {
    clear();
}

void CFSAngularDistribution::clear() {
    if (tabular != nullptr) {
        delete tabular;
        tabular = nullptr;
    }
}

bool CFSAngularDistribution::isIsotropic() const {
    return tabular == nullptr;
}

bool CFSAngularDistribution::setIsotropic() {
    clear();
    return true;
}

// Set tabular from normalized pdf function
bool CFSAngularDistribution::setTabular
(const ENDFInterpolationFunction& pfunc) {
    
    // Clear function value
    clear();
    
    try {
        
        if (!pfunc.isLinear()) {
            throw std::logic_error("given func is not linear!");
        }
        
        // Check normalization
        if (!ENDFCheckNormalization
            (pfunc.data(), ENDFTabularDistributionType::LINEAR_LINEAR))
        {
            throw std::logic_error("data check normalization error!");
        }
        
        tabular = new ENDFTabularDistribution<>;
        if (tabular == nullptr) {
            throw std::logic_error("mem. alloc. tabular!");
        }
        if(!tabular->init
           (pfunc.data(),
            ENDFTabularDistributionType::LINEAR_LINEAR))
        {
            throw std::logic_error("init tab. dist. error!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

bool CFSAngularDistribution::setTabular
(const ENDFTabularDistribution<>& dist) {
    
    // Clear function value
    clear();
    
    try {
        tabular = new ENDFTabularDistribution<>;
        if (tabular == nullptr) {
            throw std::logic_error("mem. alloc. tabular!");
        }

        // Copy distribution
        *tabular = dist;
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

bool CFSAngularDistribution::loadACE
(const ACEAngularDistribution& adist) {
    
    clear();
    
    try {
        
        switch (adist.law) {
            case ACEAngularDistribution::Law::ISOTROPIC:
            {
                setIsotropic();
                break;
            }
            case ACEAngularDistribution::Law::TABULAR:
            {
                if (adist.tabular.type() !=
                    ENDFTabularDistributionType::LINEAR_LINEAR) {
                    throw std::logic_error("interp not linear!");
                }
                if(!setTabular(adist.tabular)) {
                    throw std::logic_error("set tabular error!");
                }
                break;
            }
            case ACEAngularDistribution::Law::EQUIPROB:
            {
                throw std::logic_error("equiprob law not allowed!");
                break;
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Implementation of CFSAngularDist
void CFSAngularDist::clear() {
    system = static_cast<ENDFSpaceSystem>(0);
    if (ergInFunc != nullptr) {
        delete ergInFunc;
        ergInFunc = nullptr;
    }
}

bool CFSAngularDist::isIsotropic() const {
    return ergInFunc == nullptr;
}

bool CFSAngularDist::loadENDF
(const ENDFNeutronData::AngularDist& adist) {
    
    // Clear
    clear();
    
    // Define lambda functions for insering points
    auto insertLegendre = []
    (ENDFObjectDataPoint<ENDFLegendreDistribution> const& from,
     ENDFObjectDataPoint<CFSAngularDistribution>& to) {
        to.x = from.x;
        if (from.y.isIsotropic()) {
            if (!to.y.setIsotropic()) {
                throw std::logic_error("set isotropic error!");
            }
        } else {
            auto p = LS::linearize(from.y, CMS::angleLegLinTol);
            if (!p.valid()) {
                throw std::logic_error("legend. lin. error!");
            }
            if (!to.y.setTabular(p)) {
                throw std::logic_error("set tabular error!");
            }
        }
    };
    
    auto insertTabular = []
    (ENDFObjectDataPoint<ENDFInterpolationFunction> const& from,
     ENDFObjectDataPoint<CFSAngularDistribution>& to) {
        to.x = from.x;
        auto p = LS::linearize
        (from.y, CMS::angleTabLinTol, CMS::zeroThres);
        if (!p.valid()) {
            throw std::logic_error("endf tabular. lin. error!");
        }
        if (!to.y.setTabular(p)) {
            throw std::logic_error("set tabular error!");
        }
    };
    
    // Try-catch
    try {
        
        // Copy space system
        system = adist.system;
        
        // Check the type
        switch (adist.type) {
            case ENDFNeutronData::AngularDist::Type::ISOTROPIC:
            {
                // Do nothing!
                break;
            }
            case ENDFNeutronData::AngularDist::Type::LEGENDRE:
            {
                // Allocate energy func. memory
                ergInFunc = new ENDFObjectInterpolationFunction
                < CFSAngularDistribution >;
                if (ergInFunc == nullptr) {
                    throw std::logic_error("mem. alloc. erg. func.!");
                }
                
                long NE = adist.legendFunc2.data().size();
                if(!ergInFunc->init(adist.legendFunc2.interp())) {
                    throw std::logic_error("init interp. func. error!");
                }
                if(ergInFunc->data().size() != NE) {
                    throw std::logic_error("interp dim. error!");
                }
                // Linearize Legendre function
                for (long i=0; i<NE; i++) {
                    auto& from = adist.legendFunc2.data(i);
                    auto& to   = ergInFunc->data(i);
                    insertLegendre(from, to);
                }
                
                break;
            }
            case ENDFNeutronData::AngularDist::Type::TABULATED:
            {
                // Allocate energy func. memory
                ergInFunc = new ENDFObjectInterpolationFunction
                < CFSAngularDistribution >;
                if (ergInFunc == nullptr) {
                    throw std::logic_error("mem. alloc. erg. func.!");
                }
                
                long NE = adist.interpFunc2.data().size();
                if(!ergInFunc->init(adist.interpFunc2.interp())) {
                    throw std::logic_error("init interp. func. error!");
                }
                if(ergInFunc->data().size() != NE) {
                    throw std::logic_error("interp dim. error!");
                }
                // Linearize ENDF interpolation function
                for (long i=0; i<NE; i++) {
                    auto& from = adist.interpFunc2.data(i);
                    auto& to   = ergInFunc->data(i);
                    insertTabular(from, to);
                }
                
                break;
            }
            case ENDFNeutronData::AngularDist::Type::MIXED:
            {
                // Allocate energy func. memory
                ergInFunc = new ENDFObjectInterpolationFunction
                < CFSAngularDistribution >;
                if (ergInFunc == nullptr) {
                    throw std::logic_error("mem. alloc. erg. func.!");
                }
                
                // Combine interpolation rules
                std::vector< ENDFInterpLaw > interp;
                std::vector< ENDFObjectDataPoint<CFSAngularDistribution> > data;
                
                interp = adist.legendFunc2.interp();
                long NR1 = adist.legendFunc2.interp().back().NBT;
                for (auto& p : adist.interpFunc2.interp()) {
                    interp.emplace_back(p.INT, NR1 + p.NBT - 1);
                }
                
                // Allocate memory
                long NE1 = adist.legendFunc2.data().size();
                long NE2 = adist.interpFunc2.data().size();
                data.resize(NE1+NE2-1);

                // Linearize Legendre function
                for (long i=0; i<NE1-1; i++) {
                    auto& from = adist.legendFunc2.data(i);
                    auto& to   = data[i];
                    insertLegendre(from, to);
                }
                
                // Linearize ENDF interpolation function
                for (long i=0; i<NE2; i++) {
                    auto& from = adist.interpFunc2.data(i);
                    auto& to   = data[i+NE1-1];
                    insertTabular(from, to);
                }
                
                if(!ergInFunc->init
                   (std::move(interp), std::move(data))) {
                    throw std::logic_error
                    ("init interp. func. error!");
                }
                
                break;
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

bool CFSAngularDist::loadACE
(const ACEAngularDist& adist) {
    
    // Clear
    clear();
    
    // Try-catch
    try {
        
        // Check validity
//        if (!adist.valid()) {
//            throw std::logic_error("ACE adist. not valid!");
//        }
        
        // Check whether isotropic
        if (adist.isIsotropic()) {
            // Do nothing, automically isotropic
            return true;
        }
        
        // Not isotropic
        ergInFunc = new ENDFObjectInterpolationFunction
        < CFSAngularDistribution >;
        if (ergInFunc == nullptr) {
            std::logic_error("mem. alloc. erg. func.!");
        }
        
        // Set linear interp
        long NE = adist.ergInMevFunc.data().size();
        if (!ergInFunc->init(NE, 2)) {
            throw std::logic_error
            ("init interp. func. error!");
        }
        for (long i=0; i<NE; i++) {
            
            // Get reference
            auto& to   = ergInFunc->data(i);
            auto& from = adist.ergInMevFunc.data(i);
            
            // Convert energy from Mev to ev
            to.x = from.x * CMS::evPerMev;
            
            if (!to.y.loadACE(from.y)) {
                throw std::logic_error("load ACE adist error!");
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Implementations of CFSEnergyDist
bool CFSEnergyDist::loadENDF
(const ENDFNeutronData::EnergyDist& edist) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Allocate same partial laws
        long NP = edist.partialDists.size();
        partialDists.resize(NP);
        
        // Construct partial law
        for (long i=0; i<NP; i++) {
            
            // The reference to data system
            auto& from = edist.partialDists[i];
            auto& to   = partialDists[i];
            
            // Copy the validity
            to.validity = from.validity;
            
            // Enstablish the law according pre set laws
            switch (from.law) {
                case ENDFNeutronData::EnergyDist::Law::LAW1:
                {
                    // Set energy law
                    to.law = CFSEnergyDist::Law::LAW4;
                    
                    if (!to.law4.loadENDF(from.law1)) {
                        throw std::logic_error
                        ("load ENDF file 5 law 1 error!");
                    }
                    break;
                }
                case ENDFNeutronData::EnergyDist::Law::LAW5:
                {
                    // Set energy law
                    to.law = CFSEnergyDist::Law::LAW5;
                    
                    if (!to.law5.loadENDF(from.law5)) {
                        throw std::logic_error
                        ("load ENDF file 5 law 5 error!");
                    }
                    break;
                }
                case ENDFNeutronData::EnergyDist::Law::LAW7:
                {
                    // Set energy law
                    to.law = CFSEnergyDist::Law::LAW7;
                    
                    if (!to.law7.loadENDF(from.law7)) {
                        throw std::logic_error
                        ("load ENDF file 5 law 7 error!");
                    }
                    break;
                }
                case ENDFNeutronData::EnergyDist::Law::LAW9:
                {
                    // Set energy law
                    to.law = CFSEnergyDist::Law::LAW9;
                    
                    if (!to.law9.loadENDF(from.law9)) {
                        throw std::logic_error
                        ("load ENDF file 5 law 9 error!");
                    }
                    break;
                }
                case ENDFNeutronData::EnergyDist::Law::LAW11:
                {
                    // Set energy law
                    to.law = CFSEnergyDist::Law::LAW11;
                    
                    if (!to.law11.loadENDF(from.law11)) {
                        throw std::logic_error
                        ("load ENDF file 5 law 11 error!");
                    }
                    break;
                }
                case ENDFNeutronData::EnergyDist::Law::LAW12:
                {
                    // Set energy law
                    to.law = CFSEnergyDist::Law::LAW4;
                    
                    if (!to.law4.loadENDF(from.law12)) {
                        throw std::logic_error
                        ("load ENDF file 5 law 12 error!");
                    }
                    break;
                }
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    
    return true;
}

// Load the ACE version of energy distribution
bool CFSEnergyDist::loadACE
(const ACEEnergyDist& edist) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Allocate same partial laws
        long NP = edist.partialDists.size();
        partialDists.resize(NP);
        
        // Construct partial law
        for (long i=0; i<NP; i++) {
            
            // The reference to data system
            auto& from = edist.partialDists[i];
            auto& to   = partialDists[i];
            
            // Copy the validity
            to.validity = from.ergInMevValidity;
            
            // Normalize the units from Mev to ev
            for (long i=0; i<to.validity.data().size(); i++) {
                auto& d = to.validity.data(i);
                d.x *= CMS::evPerMev;
            }
            
            // Enstablish the law according pre set laws
            switch (from.law) {
                case ACEEnergyDist::Law::LAW4:
                {
                    // Set energy law
                    to.law = CFSEnergyDist::Law::LAW4;
                    
                    if (!to.law4.loadACE(from.law4)) {
                        throw std::logic_error
                        ("load ACE law 4 error!");
                    }
                    break;
                }
                case ACEEnergyDist::Law::LAW7:
                {
                    // Set energy law
                    to.law = CFSEnergyDist::Law::LAW7;
                    
                    if (!to.law7.loadACE(from.law7)) {
                        throw std::logic_error
                        ("load ACE law 7 error!");
                    }
                    break;
                }
                case ACEEnergyDist::Law::LAW9:
                {
                    // Set energy law
                    to.law = CFSEnergyDist::Law::LAW9;
                    
                    if (!to.law9.loadACE(from.law9)) {
                        throw std::logic_error
                        ("load ACE law 9 error!");
                    }
                    break;
                }
                case ACEEnergyDist::Law::LAW11:
                {
                    // Set energy law
                    to.law = CFSEnergyDist::Law::LAW11;
                    
                    if (!to.law11.loadACE(from.law11)) {
                        throw std::logic_error
                        ("load ACE law 11 error!");
                    }
                    break;
                }
                case ACEEnergyDist::Law::LAW44:
                {
                    break;
                }
                case ACEEnergyDist::Law::LAW61:
                {
                    break;
                }
                case ACEEnergyDist::Law::LAW67:
                {
                    break;
                }
                default:
                {
                    // Law currently not support
                    std::cout
                    << "[CFS]: warning converting from ACE law "
                    << static_cast<long>(from.law)
                    << " not support yet!" << std::endl;
                    break;
                }
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Implementation of energy laws
// Load the ENDF law data
bool CFSEnergyDist::Law4Data::loadENDF
(const ENDFNeutronData::EnergyDist::Law1Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Take the interpolation rules
        if (!func.init(data.table.interp())) {
            throw std::logic_error("init interp. func. error!");
        }
        
        // Construct distribution from function
        long N = func.data().size();
        for (long i=0; i<N; i++) {
            
            // Create data reference
            auto& from = data.table.data(i);
            auto& to   = func.data(i);
            
            // Copy energy point
            to.x = from.x;
            
            ENDFTabularDistributionType type;
            
            // Check interpolation linearization
            if (!from.y.isLinear()) {
                throw std::logic_error("interp. func. not linear!");
            }
            
            type = ENDFTabularDistributionType::LINEAR_LINEAR;
            
            // Check normalization
            if (!ENDFCheckNormalization(from.y.data(), type)) {
                throw std::logic_error("data not normalized!");
            }
            
            // Init tabular distribution
            if (!to.y.init(from.y.data(), type)) {
                throw std::logic_error("init tab. dist. error!");
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

bool CFSEnergyDist::Law4Data::loadENDF
(const ENDFNeutronData::EnergyDist::Law12Data&) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Currently not support
        std::cout
        << "[CFS]: warning converting from ENDF file 5 law 12 "
        << " not support yet!" << std::endl;
        
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ACE law data
bool CFSEnergyDist::Law4Data::loadACE
(const ACEEnergyDist::Law4Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Directly copy distribution
        func = data.ergInMevFunc;
        
        // Change the tabular energy
        long N = func.data().size();
        for (long i=0; i<N; i++) {
            
            // Get reference to data
            auto& d = func.data(i);
            d.x *= CMS::evPerMev;
            
            // Change value by factor tabular distribution
            d.y.changeValueByFactor(CMS::evPerMev);
            
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    
    return true;
}

bool CFSEnergyDist::Law5Data::loadENDF
(const ENDFNeutronData::EnergyDist::Law5Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        U     = data.U;
        theta = data.theta;
        g     = data.g;
        
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ENDF law data
bool CFSEnergyDist::Law7Data::loadENDF
(const ENDFNeutronData::EnergyDist::Law7Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        U     = data.U;
        theta = data.theta;
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ACE law data
bool CFSEnergyDist::Law7Data::loadACE
(const ACEEnergyDist::Law7Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        U     = data.U;
        theta = data.theta;
        
        // Change unit from Mev to ev
        U *= CMS::evPerMev;
        theta.transform([&](ENDFDataPoint& d) {
            d.x *= CMS::evPerMev;
            d.y *= CMS::evPerMev;
        });
        
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ENDF law data
bool CFSEnergyDist::Law9Data::loadENDF
(const ENDFNeutronData::EnergyDist::Law9Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        U     = data.U;
        theta = data.theta;
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ACE law data
bool CFSEnergyDist::Law9Data::loadACE
(const ACEEnergyDist::Law9Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        U     = data.U;
        theta = data.theta;
        
        // Change unit from Mev to ev
        U *= CMS::evPerMev;
        theta.transform([&](ENDFDataPoint& d) {
            d.x *= CMS::evPerMev;
            d.y *= CMS::evPerMev;
        });
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    
    return true;
}


// Load the ENDF law data
bool CFSEnergyDist::Law11Data::loadENDF
(const ENDFNeutronData::EnergyDist::Law11Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        U = data.U;
        a = data.a;
        b = data.b;
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ACE law data
bool CFSEnergyDist::Law11Data::loadACE
(const ACEEnergyDist::Law11Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        U = data.U;
        a = data.a;
        b = data.b;
        
        // Change unit from Mev to ev
        U *= CMS::evPerMev;
        a.transform([&](ENDFDataPoint& d) {
            d.x *= CMS::evPerMev;
            d.y *= CMS::evPerMev;
        });
        b.transform([&](ENDFDataPoint& d) {
            d.x *= CMS::evPerMev;
            d.y /= CMS::evPerMev;
        });
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Implementatios of EnergyAngularDist
// Load the ENDF version of energy distribution
bool CFSEnergyAngularDist::loadENDF
(const ENDFNeutronData::EnergyAngularDist& eadist) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Obtain the neutron products index
        std::vector<long> indices;
        for (long i=0; i<eadist.products.size(); i++) {
            // Get reference to product
            auto& p = eadist.products[i];
            
            // Check neutron, ZAP = 1
            if (p.ZAP == 1) {
                indices.push_back(i);
            }
        }
        
        // Allocate same partial laws
        long NP = indices.size();
        products.resize(NP);
        
        // Loop over products
        for (long i=0; i<NP; i++) {
            
            // Get reference to product
            auto& from = eadist.products[indices[i]];
            auto& to   = products[i];
            
            // Set space system
            to.system = from.system;
            
            // Load energy law data
            // Enstablish the law according pre set laws
            switch (from.law) {
                case ENDFNeutronData::EnergyAngularDist::Law::LAW0:
                {
                    throw std::logic_error("unknown energy angular law!");
                    break;
                }
                case ENDFNeutronData::EnergyAngularDist::Law::LAW1:
                {
                    // Check data expression
                    switch (from.law1.type) {
                        case ENDFNeutronData::EnergyAngularDist::
                            Law1Data::Type::LEGENDRE:
                        {
                            // Set energy law
                            to.law = CFSEnergyAngularDist::Law::LAW61;
                            
                            if (!to.law61.loadENDF(from.law1)) {
                                throw std::logic_error
                                ("load ENDF file 6 law 1 LEG error!");
                            }
                            break;
                        }
                        case ENDFNeutronData::EnergyAngularDist::
                            Law1Data::Type::KALBACHMANN:
                        {
                            // Set energy law
                            to.law = CFSEnergyAngularDist::Law::LAW44;
                            
                            if (!to.law44.loadENDF(from.law1)) {
                                throw std::logic_error
                                ("load ENDF file 6 law 1 KAL error!");
                            }
                            break;
                        }
                            
                        case ENDFNeutronData::EnergyAngularDist::
                            Law1Data::Type::TABULAR:
                        {
                            // Set energy law
                            to.law = CFSEnergyAngularDist::Law::LAW61;
                            
                            if (!to.law61.loadENDF(from.law1)) {
                                throw std::logic_error
                                ("load ENDF file 6 law 1 TAB error!");
                            }
                            break;
                        }
                    }
                    
                    break;
                }
                case ENDFNeutronData::EnergyAngularDist::Law::LAW2:
                {
                    // Do nothing
                    break;
                }
                case ENDFNeutronData::EnergyAngularDist::Law::LAW3:
                {
                    // Do nothing
                    break;
                }
                case ENDFNeutronData::EnergyAngularDist::Law::LAW4:
                {
                    // Do nothing
                    break;
                }
                case ENDFNeutronData::EnergyAngularDist::Law::LAW5:
                {
                    // Do nothing
                    break;
                }
                case ENDFNeutronData::EnergyAngularDist::Law::LAW6:
                {
                    // Set energy law
                    to.law = CFSEnergyAngularDist::Law::LAW66;
                    
                    if (!to.law66.loadENDF(from.law6)) {
                        throw std::logic_error
                        ("load ENDF file 6 law 6 error!");
                    }
                    break;
                }
                case ENDFNeutronData::EnergyAngularDist::Law::LAW7:
                {
                    // Currently use law 61
                    // Set energy law
                    to.law = CFSEnergyAngularDist::Law::LAW61;
                    
                    if (!to.law61.loadENDF(from.law7)) {
                        throw std::logic_error
                        ("load ENDF file 6 law 7 error!");
                    }
                    break;
                }
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ACE version of energy distribution
bool CFSEnergyAngularDist::loadACE(const ACEEnergyDist& eadist) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Allocate same partial laws
        long NP = eadist.partialDists.size();
        products.resize(NP);
        
        // Check the validity law
        // Should be equally distributed
        double factor = 1./NP;;
        
        for (auto& p : eadist.partialDists) {
            if (!p.ergInMevValidity.isConst()) {
                throw std::logic_error("non const validity!");
            }
            if (!NRSDBLEqual
                (p.ergInMevValidity.getConst(), factor, 1E13)) {
                throw std::logic_error
                ("validity const not expected!");
            }
        }
        
        // Construct partial law
        for (long i=0; i<NP; i++) {
            
            // The reference to data system
            auto& from = eadist.partialDists[i];
            auto& to   = products[i];
            
            // Need to set space system
            
            
            // Enstablish the law according pre set laws
            switch (from.law) {
                case ACEEnergyDist::Law::LAW4:
                {
                    break;
                }
                case ACEEnergyDist::Law::LAW7:
                {
                    break;
                }
                case ACEEnergyDist::Law::LAW9:
                {
                    break;
                }
                case ACEEnergyDist::Law::LAW11:
                {
                    break;
                }
                case ACEEnergyDist::Law::LAW44:
                {
                    // Set energy law
                    to.law = CFSEnergyAngularDist::Law::LAW44;
                    
                    if (!to.law44.loadACE(from.law44)) {
                        throw std::logic_error
                        ("load ACE law 44 error!");
                    }
                    break;
                }
                case ACEEnergyDist::Law::LAW61:
                {
                    // Set energy law
                    to.law = CFSEnergyAngularDist::Law::LAW61;
                    
                    if (!to.law61.loadACE(from.law61)) {
                        throw std::logic_error
                        ("load ACE law 61 error!");
                    }
                    break;
                }
                case ACEEnergyDist::Law::LAW66:
                {
                    // Set energy law
                    to.law = CFSEnergyAngularDist::Law::LAW66;
                    
                    if (!to.law66.loadACE(from.law66)) {
                        throw std::logic_error
                        ("load ACE law 66 error!");
                    }
                    break;
                }
                case ACEEnergyDist::Law::LAW67:
                {
                    // Set energy law
                    to.law = CFSEnergyAngularDist::Law::LAW67;
                    
                    if (!to.law67.loadACE(from.law67)) {
                        throw std::logic_error
                        ("load ACE law 67 error!");
                    }
                    break;
                }
                default:
                {
                    // Law currently not support
                    std::cout
                    << "[CFS]: warning converting from ACE law "
                    << static_cast<long>(from.law)
                    << " not support yet!" << std::endl;
                    break;
                    break;
                }
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    
    return true;
}

// Implementation of energy angular laws
bool CFSEnergyAngularDist::Law44Data::loadENDF
(const ENDFNeutronData::EnergyAngularDist::Law1Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Check data type
        if (data.type != ENDFNeutronData::EnergyAngularDist::
            Law1Data::Type::KALBACHMANN) {
            throw std::logic_error("Kalbach-Mann interp. expected!");
        }
        
        func = data.kalbachFunc2;
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    
    return true;
}

// Load the ACE law data
bool CFSEnergyAngularDist::Law44Data::loadACE
(const ACEEnergyDist::Law44Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Directly copy distribution
        func = data.ergInMevFunc;
        
        // Change the tabular energy
        long N = func.data().size();
        for (long i=0; i<N; i++) {
            
            // Get reference to data
            auto& d = func.data(i);
            d.x *= CMS::evPerMev;
            
            // Change value by factor tabular distribution
            d.y.changeValueByFactor(CMS::evPerMev);
            
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ENDF law data
bool CFSEnergyAngularDist::Law61Data::loadENDF
(const ENDFNeutronData::EnergyAngularDist::Law1Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Check data type
        if (data.type == ENDFNeutronData::EnergyAngularDist::
            Law1Data::Type::LEGENDRE) {
            
            // Take the interpolation rules
            if (!func.init(data.legendreFunc2.interp())) {
                throw std::logic_error("init interp. func. error!");
            }
            
            // Construct distribution from function
            long N = func.data().size();
            for (long i=0; i<N; i++) {
                
                // Create data reference
                auto& from = data.legendreFunc2.data(i);
                auto& to   = func.data(i);
                
                // Copy energy point
                to.x = from.x;
                
                // Make similar tab. dist. structure
                if (!to.y.init(from.y.getPFunc(), from.y.type())) {
                    throw std::logic_error("init tab. dist. error!");
                }
                
                // Copy data points
                long K = to.y.data().size();
                for (long j=0; j<K; j++) {
                    
                    // Create data references
                    auto& from1 = from.y.content(j);
                    auto& to1   = to.y.content(j);
                    
                    // Copy function to distribution
                    
                    // Linearize angular function
                    auto p = LS::linearize(from1, CMS::angleLegLinTol);
                    
                    if (!p.valid()) {
                        throw std::logic_error("legend. lin. error!");
                    }
                    if (!to1.setTabular(p)) {
                        throw std::logic_error("set tabular error!");
                    }
                }
            }
            
        } else if (data.type == ENDFNeutronData::EnergyAngularDist::
            Law1Data::Type::TABULAR ) {
            
            
            // Take the interpolation rules
            if (!func.init(data.tabularFunc2.interp())) {
                throw std::logic_error("init interp. func. error!");
            }
            
            // Construct distribution from function
            long N = func.data().size();
            for (long i=0; i<N; i++) {
                
                // Create data reference
                auto& from = data.tabularFunc2.data(i);
                auto& to   = func.data(i);
                
                // Copy energy point
                to.x = from.x;
                
                // Make similar tab. dist. structure
                if (!to.y.init(from.y.getPFunc(), from.y.type())) {
                    throw std::logic_error("init tab. dist. error!");
                }
                
                // Copy data points
                long K = to.y.data().size();
                for (long j=0; j<K; j++) {
                    
                    // Create data references
                    auto& from1 = from.y.content(j);
                    auto& to1   = to.y.content(j);
                    
                    // Copy function to distribution
                    if (!to1.setTabular(from1)) {
                        throw std::logic_error("set tabular error!");
                    }
                }
            }
            
        } else {
            throw std::logic_error("Legendre/Tabular interp. expected!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

bool CFSEnergyAngularDist::Law61Data::loadENDF
(const ENDFNeutronData::EnergyAngularDist::Law7Data&) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Currently not support
        std::cout
        << "[CFS]: warning converting from ENDF file 6 law 7 "
        << " not support yet!" << std::endl;
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ACE law data
bool CFSEnergyAngularDist::Law61Data::loadACE
(const ACEEnergyDist::Law61Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Create interpolation rules
        if (!func.init(data.ergInMevFunc.interp())) {
            throw std::logic_error("init. interp. error!");
        }
        
        // Create tabular distributions
        long N = func.data().size();
        for (long i=0; i<N; i++) {
            
            // Get reference to data points
            auto& from = data.ergInMevFunc.data(i);
            auto& to   = func.data(i);
            
            // Copy energy point, convert units
            to.x = from.x * CMS::evPerMev;
            
            // Create tabular dist.
            if (!to.y.init(from.y.getPFunc(), from.y.type())) {
                throw std::logic_error("init. tab. dist. error!");
            }
            
            // Factor secondary energy distribution
            to.y.changeValueByFactor(CMS::evPerMev);
            
            // Construct angular distributions
            long K = to.y.data().size();
            for (long j=0; j<K; j++) {
                
                // get
                auto& toc   = to.y.content(j);
                auto& fromc = from.y.content(j);
                
                if (!toc.loadACE(fromc)) {
                    throw std::logic_error("load ACE adist. error!");
                }
            }
            
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ENDF law data
bool CFSEnergyAngularDist::Law66Data::loadENDF
(const ENDFNeutronData::EnergyAngularDist::Law6Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        NPSX = data.NPSX;
        APSX = data.APSX;
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ACE law data
bool CFSEnergyAngularDist::Law66Data::loadACE
(const ACEEnergyDist::Law66Data& data) {
    
    // Clear the memory
    clear();
    
    try {
        
        NPSX = data.NPSX;
        APSX = data.APSX;
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ENDF law data
bool CFSEnergyAngularDist::Law67Data::loadENDF
(const ENDFNeutronData::EnergyAngularDist::Law7Data&) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Currently not support
        std::cout
        << "[CFS]: warning converting from ENDF file 6 law 7 "
        << " not support yet!" << std::endl;
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Load the ACE law data
bool CFSEnergyAngularDist::Law67Data::loadACE
(const ACEEnergyDist::Law67Data&) {
    
    // Clear the memory
    clear();
    
    try {
        
        // Currently not support
        std::cout
        << "[CFS]: warning converting from ACE law 67 "
        << " not support yet!" << std::endl;
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
        return false;
    }
    
    return true;
}

// Implementation of CFS neutron data
std::set<long> CFSNeutronData::supportedReactionNumbers() {
    std::set<long> rxns;
    for (long i=1; i<=999; i++) {
        if (i>=6 && i<=9) {
            continue;
        }
        if (i == 10) {
            continue;
        }
        if (i>=12 && i<=15) {
            continue;
        }
        if (i == 26 || i == 31 ||
            i == 39 || i == 40 ||
            i == 43) {
            continue;
        }
        if (i>=46 && i<=49) {
            continue;
        }
        if (i == 50) {
            continue;
        }
        if (i>=92 && i<=100) {
            continue;
        }
        if (i == 110) {
            continue;
        }
        if (i>=118 && i<=599) {
            continue;
        }
        if (i>=850) {
            continue;
        }
        rxns.insert(i);
    }
    
    return rxns;
}

CFSNeutronData::CFSNeutronData(const ENDFNeutronData* ndata) {
    
    // Try-Catch, will capture exceptions
    try {
        
        // Check incoming neutron data
        if (ndata == nullptr) {
            throw std::logic_error("invalid neutron data!");
        }
        
        // Copy the atomic mass ratio
        AWR = ndata->AWR;
        
        // Copy the temperature
        tempK = ndata->tempK;
        
        // Set description
        description = "ENDF";
        
        // Loop over the reaction cross sections, File 3
        for (auto& rxn : ndata->reactions) {
            
            // Check reaction MT number
            switch (rxn.MT) {
                case 1:
                {
                    total = new CFSTotal;
                    total->bgXsec = rxn.xsec;
                    break;
                }
                case 2:
                {
                    elastic = new CFSElastic;
                    elastic->bgXsec = rxn.xsec;
                    break;
                }
                case 3:
                {
                    nonelastic = new CFSNonelastic;
                    nonelastic->bgXsec = rxn.xsec;
                    break;
                }
                case 4:
                {
                    inelastic = new CFSInelastic;
                    inelastic->bgXsec = rxn.xsec;
                    break;
                }
                case 5:
                {
                    anything = new CFSAnything;
                    anything->bgXsec = rxn.xsec;
                    break;
                }
                case 11:
                {
                    n_2nd = new CFS2ND;
                    n_2nd->bgXsec = rxn.xsec;
                    break;
                }
                case 16:
                {
                    n_2n = new CFS2N;
                    n_2n->bgXsec = rxn.xsec;
                    break;
                }
                case 17:
                {
                    n_3n = new CFS3N;
                    n_3n->bgXsec = rxn.xsec;
                    break;
                }
                case 18:
                {
                    prompt = new CFSFission;
                    prompt->bgXsec = rxn.xsec;
                    break;
                }
                case 19:
                {
                    n_f = new CFSF;
                    n_f->bgXsec = rxn.xsec;
                    break;
                }
                case 20:
                {
                    n_nf = new CFSNF;
                    n_nf->bgXsec = rxn.xsec;
                    break;
                }
                case 21:
                {
                    n_2nf = new CFS2NF;
                    n_2nf->bgXsec = rxn.xsec;
                    break;
                }
                case 22:
                {
                    n_na = new CFSNA;
                    n_na->bgXsec = rxn.xsec;
                    break;
                }
                case 23:
                {
                    n_n3a = new CFSN3A;
                    n_n3a->bgXsec = rxn.xsec;
                    break;
                }
                case 24:
                {
                    n_2na = new CFS2NA;
                    n_2na->bgXsec = rxn.xsec;
                    break;
                }
                case 25:
                {
                    n_3na = new CFS3NA;
                    n_3na->bgXsec = rxn.xsec;
                    break;
                }
                case 27:
                {
                    absorption = new CFSAbsorption;
                    absorption->bgXsec = rxn.xsec;
                    break;
                }
                case 28:
                {
                    n_np = new CFSNP;
                    n_np->bgXsec = rxn.xsec;
                    break;
                }
                case 29:
                {
                    n_n2a = new CFSN2A;
                    n_n2a->bgXsec = rxn.xsec;
                    break;
                }
                case 30:
                {
                    n_2n2a = new CFS2N2A;
                    n_2n2a->bgXsec = rxn.xsec;
                    break;
                }
                case 32:
                {
                    n_nd = new CFSND;
                    n_nd->bgXsec = rxn.xsec;
                    break;
                }
                case 33:
                {
                    n_nt = new CFSNT;
                    n_nt->bgXsec = rxn.xsec;
                    break;
                }
                case 34:
                {
                    n_n3he = new CFSN3HE;
                    n_n3he->bgXsec = rxn.xsec;
                    break;
                }
                case 35:
                {
                    n_nd2a = new CFSND2A;
                    n_nd2a->bgXsec = rxn.xsec;
                    break;
                }
                case 36:
                {
                    n_nt2a = new CFSNT2A;
                    n_nt2a->bgXsec = rxn.xsec;
                    break;
                }
                case 37:
                {
                    n_4n = new CFS4N;
                    n_4n->bgXsec = rxn.xsec;
                    break;
                }
                case 38:
                {
                    n_3nf = new CFS3NF;
                    n_3nf->bgXsec = rxn.xsec;
                    break;
                }
                case 41:
                {
                    n_2np = new CFS2NP;
                    n_2np->bgXsec = rxn.xsec;
                    break;
                }
                case 42:
                {
                    n_3np = new CFS3NP;
                    n_3np->bgXsec = rxn.xsec;
                    break;
                }
                case 44:
                {
                    n_n2p = new CFSN2P;
                    n_n2p->bgXsec = rxn.xsec;
                    break;
                }
                case 45:
                {
                    n_npa = new CFSNPA;
                    n_npa->bgXsec = rxn.xsec;
                    break;
                }
                case 51: case 52: case 53: case 54:
                case 55: case 56: case 57: case 58:
                case 59: case 60: case 61: case 62:
                case 63: case 64: case 65: case 66:
                case 67: case 68: case 69: case 70:
                case 71: case 72: case 73: case 74:
                case 75: case 76: case 77: case 78:
                case 79: case 80: case 81: case 82:
                case 83: case 84: case 85: case 86: 
                case 87: case 88: case 89: case 90:
                {
                    long l = rxn.MT - 50;
                    levels[l] = new CFSLevel(l);
                    levels[l]->bgXsec = rxn.xsec;
                    break;
                }
                case 91:
                {
                    continuum = new CFSContinuum;
                    continuum->bgXsec = rxn.xsec;
                    break;
                }
                case 101:
                {
                    disappear = new CFSDisappear;
                    disappear->bgXsec = rxn.xsec;
                    break;
                }
                case 102:
                {
                    capture = new CFSCapture;
                    capture->bgXsec = rxn.xsec;
                    break;
                }
                case 103:
                {
                    proton = new CFSProton;
                    proton->bgXsec = rxn.xsec;
                    break;
                }
                case 104:
                {
                    deuteron = new CFSDeuteron;
                    deuteron->bgXsec = rxn.xsec;
                    break;
                }
                case 105:
                {
                    triton = new CFSTriton;
                    triton->bgXsec = rxn.xsec;
                    break;
                }
                case 106:
                {
                    helium3 = new CFSHelium3;
                    helium3->bgXsec = rxn.xsec;
                    break;
                }
                case 107:
                {
                    alpha = new CFSAlpha;
                    alpha->bgXsec = rxn.xsec;
                    break;
                }
                case 108:
                {
                    n_2a = new CFS2A;
                    n_2a->bgXsec = rxn.xsec;
                    break;
                }
                case 109:
                {
                    n_3a = new CFS3A;
                    n_3a->bgXsec = rxn.xsec;
                    break;
                }
                case 111:
                {
                    n_2p = new CFS2P;
                    n_2p->bgXsec = rxn.xsec;
                    break;
                }
                case 112:
                {
                    n_pa = new CFSPA;
                    n_pa->bgXsec = rxn.xsec;
                    break;
                }
                case 113:
                {
                    n_t2a = new CFST2A;
                    n_t2a->bgXsec = rxn.xsec;
                    break;
                }
                case 114:
                {
                    n_d2a = new CFSD2A;
                    n_d2a->bgXsec = rxn.xsec;
                    break;
                }
                case 115:
                {
                    n_pd = new CFSPD;
                    n_pd->bgXsec = rxn.xsec;
                    break;
                }
                case 116:
                {
                    n_pt = new CFSPT;
                    n_pt->bgXsec = rxn.xsec;
                    break;
                }
                case 117:
                {
                    n_da = new CFSDA;
                    n_da->bgXsec = rxn.xsec;
                    break;
                }
                // Some derived rxn number considered
                case 201: case 202: case 203: case 204:
                case 205: case 206: case 207: case 251:
                case 252: case 253:
                case 301: case 302: case 303: case 304:
                case 305: case 306: case 307: case 308:
                case 309: case 310: case 311: case 312:
                case 313: case 314: case 315: case 316:
                case 317: case 318: case 319: case 320:
                case 321: case 322: case 323: case 324:
                case 325: case 326: case 327: case 328:
                case 329: case 330: case 331: case 332:
                case 333: case 334: case 335: case 336:
                case 337: case 338: case 339: case 340:
                case 341: case 342: case 343: case 344:
                case 345: case 346: case 347: case 348:
                case 349: case 350: case 351: case 352:
                case 353: case 354: case 355: case 356:
                case 357: case 358: case 359: case 360:
                case 361: case 362: case 363: case 364:
                case 365: case 366: case 367: case 368:
                case 369: case 370: case 371: case 372:
                case 373: case 374: case 375: case 376:
                case 377: case 378: case 379: case 380:
                case 381: case 382: case 383: case 384:
                case 385: case 386: case 387: case 388:
                case 389: case 390: case 391: case 392:
                case 393: case 394: case 395: case 396:
                case 397: case 398: case 399: case 400:
                case 401: case 402: case 403: case 404:
                case 405: case 406: case 407: case 408:
                case 409: case 410: case 411: case 412:
                case 413: case 414: case 415: case 416: 
                case 417: case 418: case 419: case 420: 
                case 421: case 422: case 423: case 424: 
                case 425: case 426: case 427: case 428: 
                case 429: case 430: case 431: case 432: 
                case 433: case 434: case 435: case 436: 
                case 437: case 438: case 439: case 440: 
                case 441: case 442: case 443: case 444: 
                case 445: case 446: case 447: case 448: 
                case 449: case 450:
                {
                    std::cout
                    <<"[CFS]: ignore derived rxn MT = "
                    <<rxn.MT<<std::endl;
                    break;
                }
                case 600: case 601: case 602: case 603:
                case 604: case 605: case 606: case 607:
                case 608: case 609: case 610: case 611:
                case 612: case 613: case 614: case 615:
                case 616: case 617: case 618: case 619:
                case 620: case 621: case 622: case 623:
                case 624: case 625: case 626: case 627:
                case 628: case 629: case 630: case 631:
                case 632: case 633: case 634: case 635:
                case 636: case 637: case 638: case 639:
                case 640: case 641: case 642: case 643: 
                case 644: case 645: case 646: case 647: 
                case 648:
                {
                    long l = rxn.MT - 600;
                    protonLevels[l] = new CFSProtonLevel(l);
                    protonLevels[l]->bgXsec = rxn.xsec;
                    break;
                }
                case 649:
                {
                    protonContinuum = new CFSProtonContinuum;
                    protonContinuum->bgXsec = rxn.xsec;
                    break;
                }
                case 650: case 651: case 652: case 653:
                case 654: case 655: case 656: case 657:
                case 658: case 659: case 660: case 661:
                case 662: case 663: case 664: case 665:
                case 666: case 667: case 668: case 669:
                case 670: case 671: case 672: case 673:
                case 674: case 675: case 676: case 677:
                case 678: case 679: case 680: case 681:
                case 682: case 683: case 684: case 685:
                case 686: case 687: case 688: case 689:
                case 690: case 691: case 692: case 693: 
                case 694: case 695: case 696: case 697: 
                case 698:
                {
                    long l = rxn.MT - 650;
                    deuteronLevels[l] = new CFSDeuteronLevel(l);
                    deuteronLevels[l]->bgXsec = rxn.xsec;
                    break;
                }
                case 699:
                {
                    deuteronContinuum = new CFSDeuteronContinuum;
                    deuteronContinuum->bgXsec = rxn.xsec;
                    break;
                }
                case 700: case 701: case 702: case 703:
                case 704: case 705: case 706: case 707:
                case 708: case 709: case 710: case 711:
                case 712: case 713: case 714: case 715:
                case 716: case 717: case 718: case 719:
                case 720: case 721: case 722: case 723:
                case 724: case 725: case 726: case 727:
                case 728: case 729: case 730: case 731:
                case 732: case 733: case 734: case 735:
                case 736: case 737: case 738: case 739:
                case 740: case 741: case 742: case 743: 
                case 744: case 745: case 746: case 747: 
                case 748:
                {
                    long l = rxn.MT - 700;
                    tritonLevels[l] = new CFSTritonLevel(l);
                    tritonLevels[l]->bgXsec = rxn.xsec;
                    break;
                }
                case 749:
                {
                    tritonContinuum = new CFSTritonContinuum;
                    tritonContinuum->bgXsec = rxn.xsec;
                    break;
                }
                case 750: case 751: case 752: case 753:
                case 754: case 755: case 756: case 757:
                case 758: case 759: case 760: case 761:
                case 762: case 763: case 764: case 765:
                case 766: case 767: case 768: case 769:
                case 770: case 771: case 772: case 773:
                case 774: case 775: case 776: case 777:
                case 778: case 779: case 780: case 781:
                case 782: case 783: case 784: case 785:
                case 786: case 787: case 788: case 789:
                case 790: case 791: case 792: case 793: 
                case 794: case 795: case 796: case 797: 
                case 798:
                {
                    long l = rxn.MT - 750;
                    helium3Levels[l] = new CFSHelium3Level(l);
                    helium3Levels[l]->bgXsec = rxn.xsec;
                    break;
                }
                case 799:
                {
                    helium3Continuum = new CFSHelium3Continuum;
                    helium3Continuum->bgXsec = rxn.xsec;
                    break;
                }
                case 800: case 801: case 802: case 803:
                case 804: case 805: case 806: case 807:
                case 808: case 809: case 810: case 811:
                case 812: case 813: case 814: case 815:
                case 816: case 817: case 818: case 819:
                case 820: case 821: case 822: case 823:
                case 824: case 825: case 826: case 827:
                case 828: case 829: case 830: case 831:
                case 832: case 833: case 834: case 835:
                case 836: case 837: case 838: case 839:
                case 840: case 841: case 842: case 843: 
                case 844: case 845: case 846: case 847: 
                case 848:
                {
                    long l = rxn.MT - 800;
                    alphaLevels[l] = new CFSAlphaLevel(l);
                    alphaLevels[l]->bgXsec = rxn.xsec;
                    break;
                }
                case 849:
                {
                    alphaContinuum = new CFSAlphaContinuum;
                    alphaContinuum->bgXsec = rxn.xsec;
                    break;
                }
                    
                default:
                    std::cout
                    <<"[CFS]: unsupported rxn MT = "
                    <<rxn.MT<<std::endl;
                    throw std::logic_error("unsupported rxn");
                    break;
            }
            
        }
        
        // Loop over angular distributions, File 4
        for (auto& rxn : ndata->angularDists) {
            
            // Check reaction MT number
            switch (rxn.MT) {
                case 2:
                {
                    if (elastic == nullptr) {
                        throw std::logic_error("no elastic rxn!");
                    }
                    
                    elastic->adist = new CFSAngularDist;
                    if (!elastic->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 11:
                {
                    if (n_2nd == nullptr) {
                        throw std::logic_error("no (n,2nd) rxn!");
                    }
                    
                    n_2nd->adist = new CFSAngularDist;
                    if (!n_2nd->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 16:
                {
                    if (n_2n == nullptr) {
                        throw std::logic_error("no (n,2n) rxn!");
                    }
                    
                    n_2n->adist = new CFSAngularDist;
                    if (!n_2n->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 17:
                {
                    if (n_3n == nullptr) {
                        throw std::logic_error("no (n,3n) rxn!");
                    }
                    
                    n_3n->adist = new CFSAngularDist;
                    if (!n_3n->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 18:
                {
                    if (prompt == nullptr) {
                        throw std::logic_error("no (n,fission) rxn!");
                    }
                    
                    prompt->adist = new CFSAngularDist;
                    if (!prompt->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 19:
                {
                    if (n_f == nullptr) {
                        throw std::logic_error("no (n,f) rxn!");
                    }
                    
                    n_f->adist = new CFSAngularDist;
                    if (!n_f->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 20:
                {
                    if (n_nf == nullptr) {
                        throw std::logic_error("no (n,nf) rxn!");
                    }
                    
                    n_nf->adist = new CFSAngularDist;
                    if (!n_nf->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 21:
                {
                    if (n_2nf == nullptr) {
                        throw std::logic_error("no (n,2nf) rxn!");
                    }
                    
                    n_2nf->adist = new CFSAngularDist;
                    if (!n_2nf->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 22:
                {
                    if (n_na == nullptr) {
                        throw std::logic_error("no (n,na) rxn!");
                    }
                    
                    n_na->adist = new CFSAngularDist;
                    if (!n_na->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 23:
                {
                    if (n_n3a == nullptr) {
                        throw std::logic_error("no (n,n3a) rxn!");
                    }
                    
                    n_n3a->adist = new CFSAngularDist;
                    if (!n_n3a->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 24:
                {
                    if (n_2na == nullptr) {
                        throw std::logic_error("no (n,2na) rxn!");
                    }
                    
                    n_2na->adist = new CFSAngularDist;
                    if (!n_2na->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 25:
                {
                    if (n_3na == nullptr) {
                        throw std::logic_error("no (n,3na) rxn!");
                    }
                    
                    n_3na->adist = new CFSAngularDist;
                    if (!n_3na->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 28:
                {
                    if (n_np == nullptr) {
                        throw std::logic_error("no (n,np) rxn!");
                    }
                    
                    n_np->adist = new CFSAngularDist;
                    if (!n_np->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 29:
                {
                    if (n_n2a == nullptr) {
                        throw std::logic_error("no (n,n2a) rxn!");
                    }
                    
                    n_n2a->adist = new CFSAngularDist;
                    if (!n_n2a->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 30:
                {
                    if (n_2n2a == nullptr) {
                        throw std::logic_error("no (n,2n2a) rxn!");
                    }
                    
                    n_2n2a->adist = new CFSAngularDist;
                    if (!n_2n2a->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 32:
                {
                    if (n_nd == nullptr) {
                        throw std::logic_error("no (n,nd) rxn!");
                    }
                    
                    n_nd->adist = new CFSAngularDist;
                    if (!n_nd->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 33:
                {
                    if (n_nt == nullptr) {
                        throw std::logic_error("no (n,nt) rxn!");
                    }
                    
                    n_nt->adist = new CFSAngularDist;
                    if (!n_nt->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 34:
                {
                    if (n_n3he == nullptr) {
                        throw std::logic_error("no (n,n3he) rxn!");
                    }
                    
                    n_n3he->adist = new CFSAngularDist;
                    if (!n_n3he->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 35:
                {
                    if (n_nd2a == nullptr) {
                        throw std::logic_error("no (n,nd2a) rxn!");
                    }
                    
                    n_nd2a->adist = new CFSAngularDist;
                    if (!n_nd2a->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 36:
                {
                    if (n_nt2a == nullptr) {
                        throw std::logic_error("no (n,nt2a) rxn!");
                    }
                    
                    n_nt2a->adist = new CFSAngularDist;
                    if (!n_nt2a->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 37:
                {
                    if (n_4n == nullptr) {
                        throw std::logic_error("no (n,4n) rxn!");
                    }
                    
                    n_4n->adist = new CFSAngularDist;
                    if (!n_4n->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 38:
                {
                    if (n_3nf == nullptr) {
                        throw std::logic_error("no (n,3nf) rxn!");
                    }
                    
                    n_3nf->adist = new CFSAngularDist;
                    if (!n_3nf->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 41:
                {
                    if (n_2np == nullptr) {
                        throw std::logic_error("no (n,2np) rxn!");
                    }
                    
                    n_2np->adist = new CFSAngularDist;
                    if (!n_2np->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 42:
                {
                    if (n_3np == nullptr) {
                        throw std::logic_error("no (n,3np) rxn!");
                    }
                    
                    n_3np->adist = new CFSAngularDist;
                    if (!n_3np->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 44:
                {
                    if (n_n2p == nullptr) {
                        throw std::logic_error("no (n,n2p) rxn!");
                    }
                    
                    n_n2p->adist = new CFSAngularDist;
                    if (!n_n2p->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 45:
                {
                    if (n_npa == nullptr) {
                        throw std::logic_error("no (n,npa) rxn!");
                    }
                    
                    n_npa->adist = new CFSAngularDist;
                    if (!n_npa->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 51: case 52: case 53: case 54:
                case 55: case 56: case 57: case 58:
                case 59: case 60: case 61: case 62:
                case 63: case 64: case 65: case 66:
                case 67: case 68: case 69: case 70:
                case 71: case 72: case 73: case 74:
                case 75: case 76: case 77: case 78:
                case 79: case 80: case 81: case 82:
                case 83: case 84: case 85: case 86:
                case 87: case 88: case 89: case 90:
                {
                    long l = rxn.MT - 50;
                    if (levels[l] == nullptr) {
                        throw std::logic_error("no (n,ni) rxn!");
                    }
                    
                    levels[l]->adist = new CFSAngularDist;
                    if (!levels[l]->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 91:
                {
                    if (continuum == nullptr) {
                        throw std::logic_error("no (n,nc) rxn!");
                    }
                    
                    continuum->adist = new CFSAngularDist;
                    if (!continuum->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 600: case 601: case 602: case 603:
                case 604: case 605: case 606: case 607:
                case 608: case 609: case 610: case 611:
                case 612: case 613: case 614: case 615:
                case 616: case 617: case 618: case 619:
                case 620: case 621: case 622: case 623:
                case 624: case 625: case 626: case 627:
                case 628: case 629: case 630: case 631:
                case 632: case 633: case 634: case 635:
                case 636: case 637: case 638: case 639:
                case 640: case 641: case 642: case 643:
                case 644: case 645: case 646: case 647:
                case 648:
                {
                    long l = rxn.MT - 600;
                    if (protonLevels[l] == nullptr) {
                        throw std::logic_error("no (n,pi) rxn!");
                    }
                    
                    protonLevels[l]->adist = new CFSAngularDist;
                    if (!protonLevels[l]->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 649:
                {
                    if (protonContinuum == nullptr) {
                        throw std::logic_error("no (n,pc) rxn!");
                    }
                    
                    protonContinuum->adist = new CFSAngularDist;
                    if (!protonContinuum->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 650: case 651: case 652: case 653:
                case 654: case 655: case 656: case 657:
                case 658: case 659: case 660: case 661:
                case 662: case 663: case 664: case 665:
                case 666: case 667: case 668: case 669:
                case 670: case 671: case 672: case 673:
                case 674: case 675: case 676: case 677:
                case 678: case 679: case 680: case 681:
                case 682: case 683: case 684: case 685:
                case 686: case 687: case 688: case 689:
                case 690: case 691: case 692: case 693:
                case 694: case 695: case 696: case 697:
                case 698:
                {
                    long l = rxn.MT - 650;
                    if (deuteronLevels[l] == nullptr) {
                        throw std::logic_error("no (n,di) rxn!");
                    }
                    
                    deuteronLevels[l]->adist = new CFSAngularDist;
                    if (!deuteronLevels[l]->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 699:
                {
                    if (deuteronContinuum == nullptr) {
                        throw std::logic_error("no (n,dc) rxn!");
                    }
                    
                    deuteronContinuum->adist = new CFSAngularDist;
                    if (!deuteronContinuum->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 700: case 701: case 702: case 703:
                case 704: case 705: case 706: case 707:
                case 708: case 709: case 710: case 711:
                case 712: case 713: case 714: case 715:
                case 716: case 717: case 718: case 719:
                case 720: case 721: case 722: case 723:
                case 724: case 725: case 726: case 727:
                case 728: case 729: case 730: case 731:
                case 732: case 733: case 734: case 735:
                case 736: case 737: case 738: case 739:
                case 740: case 741: case 742: case 743:
                case 744: case 745: case 746: case 747:
                case 748:
                {
                    long l = rxn.MT - 700;
                    if (tritonLevels[l] == nullptr) {
                        throw std::logic_error("no (n,ti) rxn!");
                    }
                    
                    tritonLevels[l]->adist = new CFSAngularDist;
                    if (!tritonLevels[l]->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 749:
                {
                    if (tritonContinuum == nullptr) {
                        throw std::logic_error("no (n,tc) rxn!");
                    }
                    
                    tritonContinuum->adist = new CFSAngularDist;
                    if (!tritonContinuum->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 750: case 751: case 752: case 753:
                case 754: case 755: case 756: case 757:
                case 758: case 759: case 760: case 761:
                case 762: case 763: case 764: case 765:
                case 766: case 767: case 768: case 769:
                case 770: case 771: case 772: case 773:
                case 774: case 775: case 776: case 777:
                case 778: case 779: case 780: case 781:
                case 782: case 783: case 784: case 785:
                case 786: case 787: case 788: case 789:
                case 790: case 791: case 792: case 793:
                case 794: case 795: case 796: case 797:
                case 798:
                {
                    long l = rxn.MT - 750;
                    if (helium3Levels[l] == nullptr) {
                        throw std::logic_error("no (n,3hei) rxn!");
                    }
                    
                    helium3Levels[l]->adist = new CFSAngularDist;
                    if (!helium3Levels[l]->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 799:
                {
                    if (helium3Continuum == nullptr) {
                        throw std::logic_error("no (n,3hec) rxn!");
                    }
                    
                    helium3Continuum->adist = new CFSAngularDist;
                    if (!helium3Continuum->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }

                    break;
                }
                case 800: case 801: case 802: case 803:
                case 804: case 805: case 806: case 807:
                case 808: case 809: case 810: case 811:
                case 812: case 813: case 814: case 815:
                case 816: case 817: case 818: case 819:
                case 820: case 821: case 822: case 823:
                case 824: case 825: case 826: case 827:
                case 828: case 829: case 830: case 831:
                case 832: case 833: case 834: case 835:
                case 836: case 837: case 838: case 839:
                case 840: case 841: case 842: case 843:
                case 844: case 845: case 846: case 847:
                case 848:
                {
                    long l = rxn.MT - 800;
                    if (alphaLevels[l] == nullptr) {
                        throw std::logic_error("no (n,ai) rxn!");
                    }
                    
                    alphaLevels[l]->adist = new CFSAngularDist;
                    if (!alphaLevels[l]->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                case 849:
                {
                    if (alphaContinuum == nullptr) {
                        throw std::logic_error("no (n,ac) rxn!");
                    }
                    
                    alphaContinuum->adist = new CFSAngularDist;
                    if (!alphaContinuum->adist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load adist!");
                    }
                    
                    break;
                }
                    
                default:
                    std::cout
                    <<"[CFS]: unsupported rxn MT = "
                    <<rxn.MT<<" to have anugular dist."<<std::endl;
                    throw std::logic_error("unsupported rxn adist");
                    break;
            }
            
        }
        
        // Loop over angular distributions, File 5
        for (auto& rxn : ndata->energyDists) {
            
            // Check reaction MT number
            switch (rxn.MT) {
                case 11:
                {
                    if (n_2nd == nullptr) {
                        throw std::logic_error("no (n,2nd) rxn!");
                    }
                    
                    if (n_2nd->adist == nullptr) {
                        throw std::logic_error("no (n,2nd) adist!");
                    }
                    
                    n_2nd->edist = new CFSEnergyDist;
                    if (!n_2nd->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 16:
                {
                    if (n_2n == nullptr) {
                        throw std::logic_error("no (n,2n) rxn!");
                    }
                    
                    if (n_2n->adist == nullptr) {
                        throw std::logic_error("no (n,2n) adist!");
                    }
                    
                    n_2n->edist = new CFSEnergyDist;
                    if (!n_2n->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 17:
                {
                    if (n_3n == nullptr) {
                        throw std::logic_error("no (n,3n) rxn!");
                    }
                    
                    if (n_3n->adist == nullptr) {
                        throw std::logic_error("no (n,3n) adist!");
                    }
                    
                    n_3n->edist = new CFSEnergyDist;
                    if (!n_3n->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 18:
                {
                    if (prompt == nullptr) {
                        throw std::logic_error("no (n,fission) rxn!");
                    }
                    
                    if (prompt->adist == nullptr) {
                        // Make a fix by providing an isotropic adist
                        prompt->adist = new CFSAngularDist;
                        std::cerr<<
                        "[CFS]: no (n,fission) adist, one isotropic added!"
                        <<std::endl;
                    }
                    
                    prompt->edist = new CFSEnergyDist;
                    if (!prompt->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 19:
                {
                    if (n_f == nullptr) {
                        throw std::logic_error("no (n,f) rxn!");
                    }
                    
                    if (n_f->adist == nullptr) {
                        throw std::logic_error("no (n,f) adist!");
                    }
                    
                    n_f->edist = new CFSEnergyDist;
                    if (!n_f->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 20:
                {
                    if (n_nf == nullptr) {
                        throw std::logic_error("no (n,nf) rxn!");
                    }
                    
                    if (n_nf->adist == nullptr) {
                        throw std::logic_error("no (n,nf) adist!");
                    }
                    
                    n_nf->edist = new CFSEnergyDist;
                    if (!n_nf->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 21:
                {
                    if (n_2nf == nullptr) {
                        throw std::logic_error("no (n,2nf) rxn!");
                    }
                    
                    if (n_2nf->adist == nullptr) {
                        throw std::logic_error("no (n,2nf) adist!");
                    }
                    
                    n_2nf->edist = new CFSEnergyDist;
                    if (!n_2nf->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 22:
                {
                    if (n_na == nullptr) {
                        throw std::logic_error("no (n,na) rxn!");
                    }
                    
                    if (n_na->adist == nullptr) {
                        throw std::logic_error("no (n,na) adist!");
                    }
                    
                    n_na->edist = new CFSEnergyDist;
                    if (!n_na->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 23:
                {
                    if (n_n3a == nullptr) {
                        throw std::logic_error("no (n,n3a) rxn!");
                    }
                    
                    if (n_n3a->adist == nullptr) {
                        throw std::logic_error("no (n,n3a) adist!");
                    }
                    
                    n_n3a->edist = new CFSEnergyDist;
                    if (!n_n3a->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 24:
                {
                    if (n_2na == nullptr) {
                        throw std::logic_error("no (n,2na) rxn!");
                    }
                    
                    if (n_2na->adist == nullptr) {
                        throw std::logic_error("no (n,2na) adist!");
                    }
                    
                    n_2na->edist = new CFSEnergyDist;
                    if (!n_2na->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 25:
                {
                    if (n_3na == nullptr) {
                        throw std::logic_error("no (n,3na) rxn!");
                    }
                    
                    if (n_3na->adist == nullptr) {
                        throw std::logic_error("no (n,3na) adist!");
                    }
                    
                    n_3na->edist = new CFSEnergyDist;
                    if (!n_3na->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 28:
                {
                    if (n_np == nullptr) {
                        throw std::logic_error("no (n,np) rxn!");
                    }
                    
                    if (n_np->adist == nullptr) {
                        throw std::logic_error("no (n,np) adist!");
                    }
                    
                    n_np->edist = new CFSEnergyDist;
                    if (!n_np->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 29:
                {
                    if (n_n2a == nullptr) {
                        throw std::logic_error("no (n,n2a) rxn!");
                    }
                    
                    if (n_n2a->adist == nullptr) {
                        throw std::logic_error("no (n,n2a) adist!");
                    }
                    
                    n_n2a->edist = new CFSEnergyDist;
                    if (!n_n2a->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 30:
                {
                    if (n_2n2a == nullptr) {
                        throw std::logic_error("no (n,2n2a) rxn!");
                    }
                    
                    if (n_2n2a->adist == nullptr) {
                        throw std::logic_error("no (n,2n2a) adist!");
                    }
                    
                    n_2n2a->edist = new CFSEnergyDist;
                    if (!n_2n2a->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 32:
                {
                    if (n_nd == nullptr) {
                        throw std::logic_error("no (n,nd) rxn!");
                    }
                    
                    if (n_nd->adist == nullptr) {
                        throw std::logic_error("no (n,nd) adist!");
                    }
                    
                    n_nd->edist = new CFSEnergyDist;
                    if (!n_nd->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 33:
                {
                    if (n_nt == nullptr) {
                        throw std::logic_error("no (n,nt) rxn!");
                    }
                    
                    if (n_nt->adist == nullptr) {
                        throw std::logic_error("no (n,nt) adist!");
                    }
                    
                    n_nt->edist = new CFSEnergyDist;
                    if (!n_nt->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 34:
                {
                    if (n_n3he == nullptr) {
                        throw std::logic_error("no (n,n3he) rxn!");
                    }
                    
                    if (n_n3he->adist == nullptr) {
                        throw std::logic_error("no (n,n3he) adist!");
                    }
                    
                    n_n3he->edist = new CFSEnergyDist;
                    if (!n_n3he->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 35:
                {
                    if (n_nd2a == nullptr) {
                        throw std::logic_error("no (n,nd2a) rxn!");
                    }
                    
                    if (n_nd2a->adist == nullptr) {
                        throw std::logic_error("no (n,nd2a) adist!");
                    }
                    
                    n_nd2a->edist = new CFSEnergyDist;
                    if (!n_nd2a->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 36:
                {
                    if (n_nt2a == nullptr) {
                        throw std::logic_error("no (n,nt2a) rxn!");
                    }
                    
                    if (n_nt2a->adist == nullptr) {
                        throw std::logic_error("no (n,nt2a) adist!");
                    }
                    
                    n_nt2a->edist = new CFSEnergyDist;
                    if (!n_nt2a->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 37:
                {
                    if (n_4n == nullptr) {
                        throw std::logic_error("no (n,4n) rxn!");
                    }
                    
                    if (n_4n->adist == nullptr) {
                        throw std::logic_error("no (n,4n) adist!");
                    }
                    
                    n_4n->edist = new CFSEnergyDist;
                    if (!n_4n->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 38:
                {
                    if (n_3nf == nullptr) {
                        throw std::logic_error("no (n,3nf) rxn!");
                    }
                    
                    if (n_3nf->adist == nullptr) {
                        throw std::logic_error("no (n,3nf) adist!");
                    }
                    
                    n_3nf->edist = new CFSEnergyDist;
                    if (!n_3nf->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 41:
                {
                    if (n_2np == nullptr) {
                        throw std::logic_error("no (n,2np) rxn!");
                    }
                    
                    if (n_2np->adist == nullptr) {
                        throw std::logic_error("no (n,2np) adist!");
                    }
                    
                    n_2np->edist = new CFSEnergyDist;
                    if (!n_2np->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 42:
                {
                    if (n_3np == nullptr) {
                        throw std::logic_error("no (n,3np) rxn!");
                    }
                    
                    if (n_3np->adist == nullptr) {
                        throw std::logic_error("no (n,3np) adist!");
                    }
                    
                    n_3np->edist = new CFSEnergyDist;
                    if (!n_3np->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 44:
                {
                    if (n_n2p == nullptr) {
                        throw std::logic_error("no (n,n2p) rxn!");
                    }
                    
                    if (n_n2p->adist == nullptr) {
                        throw std::logic_error("no (n,n2p) adist!");
                    }
                    
                    n_n2p->edist = new CFSEnergyDist;
                    if (!n_n2p->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 45:
                {
                    if (n_npa == nullptr) {
                        throw std::logic_error("no (n,npa) rxn!");
                    }
                    
                    if (n_npa->adist == nullptr) {
                        throw std::logic_error("no (n,npa) adist!");
                    }
                    
                    n_npa->edist = new CFSEnergyDist;
                    if (!n_npa->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 91:
                {
                    if (continuum == nullptr) {
                        throw std::logic_error("no (n,nc) rxn!");
                    }
                    
                    if (continuum->adist == nullptr) {
                        throw std::logic_error("no (n,nc) adist!");
                    }
                    
                    continuum->edist = new CFSEnergyDist;
                    if (!continuum->edist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    break;
                }
                case 455:
                {
                    // Special procedure for file 455
                    std::cout<<"[CFS]: special procedure for MT = 455"
                    <<std::endl;
                    
                    break;
                }
                case 649:
                {
                    if (protonContinuum == nullptr) {
                        throw std::logic_error("no (n,pc) rxn!");
                    }
                    
                    if (protonContinuum->adist == nullptr) {
                        throw std::logic_error("no (n,pc) adist!");
                    }
                    
                    break;
                }
                case 699:
                {
                    if (deuteronContinuum == nullptr) {
                        throw std::logic_error("no (n,dc) rxn!");
                    }
                    
                    if (deuteronContinuum->adist == nullptr) {
                        throw std::logic_error("no (n,dc) adist!");
                    }
                    
                    break;
                }
                case 749:
                {
                    if (tritonContinuum == nullptr) {
                        throw std::logic_error("no (n,tc) rxn!");
                    }
                    
                    if (tritonContinuum->adist == nullptr) {
                        throw std::logic_error("no (n,tc) adist!");
                    }
                    
                    break;
                }
                case 799:
                {
                    if (helium3Continuum == nullptr) {
                        throw std::logic_error("no (n,3hec) rxn!");
                    }
                    
                    if (helium3Continuum->adist == nullptr) {
                        throw std::logic_error("no (n,3hec) adist!");
                    }
                    
                    break;
                }
                case 849:
                {
                    if (alphaContinuum == nullptr) {
                        throw std::logic_error("no (n,ac) rxn!");
                    }
                    
                    if (alphaContinuum->adist == nullptr) {
                        throw std::logic_error("no (n,ac) adist!");
                    }
                    
                    break;
                }
                    
                default:
                    std::cout
                    <<"[CFS]: unsupported rxn MT = "
                    <<rxn.MT<<" to have energy dist."<<std::endl;
                    throw std::logic_error("unsupported rxn edist");
                    break;
            }
            
        }
        
        // Loop over angular distributions, File 6
        for (auto& rxn : ndata->energyAngularDists) {
            
            // Check reaction MT number
            switch (rxn.MT) {
                case 5:
                {
                    if (anything == nullptr) {
                        throw std::logic_error("no (n,any) rxn!");
                    }
                    
                    anything->eadist = new CFSEnergyAngularDist;
                    if (!anything->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 11:
                {
                    if (n_2nd == nullptr) {
                        throw std::logic_error("no (n,2nd) rxn!");
                    }
                    
                    n_2nd->eadist = new CFSEnergyAngularDist;
                    if (!n_2nd->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 16:
                {
                    if (n_2n == nullptr) {
                        throw std::logic_error("no (n,2n) rxn!");
                    }
                    
                    n_2n->eadist = new CFSEnergyAngularDist;
                    if (!n_2n->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 17:
                {
                    if (n_3n == nullptr) {
                        throw std::logic_error("no (n,3n) rxn!");
                    }
                    
                    n_3n->eadist = new CFSEnergyAngularDist;
                    if (!n_3n->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 18:
                {
                    if (prompt == nullptr) {
                        throw std::logic_error("no (n,fission) rxn!");
                    }
                    
                    prompt->eadist = new CFSEnergyAngularDist;
                    if (!prompt->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 19:
                {
                    if (n_f == nullptr) {
                        throw std::logic_error("no (n,f) rxn!");
                    }
                    
                    n_f->eadist = new CFSEnergyAngularDist;
                    if (!n_f->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 20:
                {
                    if (n_nf == nullptr) {
                        throw std::logic_error("no (n,nf) rxn!");
                    }
                    
                    n_nf->eadist = new CFSEnergyAngularDist;
                    if (!n_nf->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 21:
                {
                    if (n_2nf == nullptr) {
                        throw std::logic_error("no (n,2nf) rxn!");
                    }
                    
                    n_2nf->eadist = new CFSEnergyAngularDist;
                    if (!n_2nf->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 22:
                {
                    if (n_na == nullptr) {
                        throw std::logic_error("no (n,na) rxn!");
                    }
                    
                    n_na->eadist = new CFSEnergyAngularDist;
                    if (!n_na->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 23:
                {
                    if (n_n3a == nullptr) {
                        throw std::logic_error("no (n,n3a) rxn!");
                    }
                    
                    n_n3a->eadist = new CFSEnergyAngularDist;
                    if (!n_n3a->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 24:
                {
                    if (n_2na == nullptr) {
                        throw std::logic_error("no (n,2na) rxn!");
                    }
                    
                    n_2na->eadist = new CFSEnergyAngularDist;
                    if (!n_2na->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 25:
                {
                    if (n_3na == nullptr) {
                        throw std::logic_error("no (n,3na) rxn!");
                    }
                    
                    n_3na->eadist = new CFSEnergyAngularDist;
                    if (!n_3na->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 28:
                {
                    if (n_np == nullptr) {
                        throw std::logic_error("no (n,np) rxn!");
                    }
                    
                    n_np->eadist = new CFSEnergyAngularDist;
                    if (!n_np->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 29:
                {
                    if (n_n2a == nullptr) {
                        throw std::logic_error("no (n,n2a) rxn!");
                    }
                    
                    n_n2a->eadist = new CFSEnergyAngularDist;
                    if (!n_n2a->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 30:
                {
                    if (n_2n2a == nullptr) {
                        throw std::logic_error("no (n,2n2a) rxn!");
                    }
                    
                    n_2n2a->eadist = new CFSEnergyAngularDist;
                    if (!n_2n2a->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 32:
                {
                    if (n_nd == nullptr) {
                        throw std::logic_error("no (n,nd) rxn!");
                    }
                    
                    n_nd->eadist = new CFSEnergyAngularDist;
                    if (!n_nd->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 33:
                {
                    if (n_nt == nullptr) {
                        throw std::logic_error("no (n,nt) rxn!");
                    }
 
                    n_nt->eadist = new CFSEnergyAngularDist;
                    if (!n_nt->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 34:
                {
                    if (n_n3he == nullptr) {
                        throw std::logic_error("no (n,n3he) rxn!");
                    }
                    
                    n_n3he->eadist = new CFSEnergyAngularDist;
                    if (!n_n3he->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 35:
                {
                    if (n_nd2a == nullptr) {
                        throw std::logic_error("no (n,nd2a) rxn!");
                    }
                    
                    n_nd2a->eadist = new CFSEnergyAngularDist;
                    if (!n_nd2a->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 36:
                {
                    if (n_nt2a == nullptr) {
                        throw std::logic_error("no (n,nt2a) rxn!");
                    }
                    
                    n_nt2a->eadist = new CFSEnergyAngularDist;
                    if (!n_nt2a->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 37:
                {
                    if (n_4n == nullptr) {
                        throw std::logic_error("no (n,4n) rxn!");
                    }
                    
                    n_4n->eadist = new CFSEnergyAngularDist;
                    if (!n_4n->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 38:
                {
                    if (n_3nf == nullptr) {
                        throw std::logic_error("no (n,3nf) rxn!");
                    }
                    
                    n_3nf->eadist = new CFSEnergyAngularDist;
                    if (!n_3nf->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 41:
                {
                    if (n_2np == nullptr) {
                        throw std::logic_error("no (n,2np) rxn!");
                    }
                    
                    n_2np->eadist = new CFSEnergyAngularDist;
                    if (!n_2np->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 42:
                {
                    if (n_3np == nullptr) {
                        throw std::logic_error("no (n,3np) rxn!");
                    }
                    
                    n_3np->eadist = new CFSEnergyAngularDist;
                    if (!n_3np->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 44:
                {
                    if (n_n2p == nullptr) {
                        throw std::logic_error("no (n,n2p) rxn!");
                    }
                    
                    n_n2p->eadist = new CFSEnergyAngularDist;
                    if (!n_n2p->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 45:
                {
                    if (n_npa == nullptr) {
                        throw std::logic_error("no (n,npa) rxn!");
                    }
                    
                    n_npa->eadist = new CFSEnergyAngularDist;
                    if (!n_npa->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 51: case 52: case 53: case 54:
                case 55: case 56: case 57: case 58:
                case 59: case 60: case 61: case 62:
                case 63: case 64: case 65: case 66:
                case 67: case 68: case 69: case 70:
                case 71: case 72: case 73: case 74:
                case 75: case 76: case 77: case 78:
                case 79: case 80: case 81: case 82:
                case 83: case 84: case 85: case 86:
                case 87: case 88: case 89: case 90:
                {
                    long l = rxn.MT - 50;
                    if (levels[l] == nullptr) {
                        throw std::logic_error("no (n,ni) rxn!");
                    }
                    
                    levels[l]->eadist = new CFSEnergyAngularDist;
                    if (!levels[l]->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 91:
                {
                    if (continuum == nullptr) {
                        throw std::logic_error("no (n,nc) rxn!");
                    }
                    
                    continuum->eadist = new CFSEnergyAngularDist;
                    if (!continuum->eadist->loadENDF(rxn)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                default:
                    std::cout
                    <<"[CFS]: unsupported rxn MT = "
                    <<rxn.MT<<" to have energy dist."<<std::endl;
                    break;
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
    }
    
}

CFSNeutronData::CFSNeutronData(const ACENeutronData* ndata) {
    
    try {
    
        // Check incoming neutron data
        if (ndata == nullptr) {
            throw std::logic_error("invalid neutron data!");
        }
        
        // Copy the atomic mass ratio
        AWR = ndata->AWR;
        
        // Copy the temperature
        tempK = ndata->tempK;
        
        // Set description
        description = "ACE";
        
        // Loop over the reaction cross sections
        for (auto& rxn : ndata->reactions) {
            
            // Check reaction MT number
            switch (rxn.MT) {
                case 1:
                {
                    total = new CFSTotal;
                    break;
                }
                case 2:
                {
                    elastic = new CFSElastic;
                    elastic->adist = new CFSAngularDist;
                    if (!elastic->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"<<std::endl;
                    }
                    
                    // NO Energy distribution, derived
                    
                    break;
                }
                case 3:
                {
                    nonelastic = new CFSNonelastic;
                    break;
                }
                case 4:
                {
                    inelastic = new CFSInelastic;
                    break;
                }
                case 5:
                {
                    anything = new CFSAnything;
                    
                    // Energy Angular distribution
                    anything->eadist = new CFSEnergyAngularDist;
                    if (!anything->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 11:
                {
                    n_2nd = new CFS2ND;
                    
                    // Angular distribution
                    n_2nd->adist = new CFSAngularDist;
                    if (!n_2nd->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_2nd->edist = new CFSEnergyDist;
                    if (!n_2nd->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy Angular distribution
                    n_2nd->eadist = new CFSEnergyAngularDist;
                    if (!n_2nd->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 16:
                {
                    n_2n = new CFS2N;
                    
                    // Angular distribution
                    n_2n->adist = new CFSAngularDist;
                    if (!n_2n->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_2n->edist = new CFSEnergyDist;
                    if (!n_2n->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_2n->eadist = new CFSEnergyAngularDist;
                    if (!n_2n->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 17:
                {
                    n_3n = new CFS3N;
                    n_3n->adist = new CFSAngularDist;
                    if (!n_3n->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_3n->edist = new CFSEnergyDist;
                    if (!n_3n->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular an distribution
                    n_3n->eadist = new CFSEnergyAngularDist;
                    if (!n_3n->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 18:
                {
                    prompt = new CFSFission;
                    prompt->adist = new CFSAngularDist;
                    if (!prompt->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    prompt->edist = new CFSEnergyDist;
                    if (!prompt->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    prompt->eadist = new CFSEnergyAngularDist;
                    if (!prompt->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 19:
                {
                    n_f = new CFSF;
                    n_f->adist = new CFSAngularDist;
                    if (!n_f->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_f->edist = new CFSEnergyDist;
                    if (!n_f->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_f->eadist = new CFSEnergyAngularDist;
                    if (!n_f->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 20:
                {
                    n_nf = new CFSNF;
                    n_nf->adist = new CFSAngularDist;
                    if (!n_nf->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_nf->edist = new CFSEnergyDist;
                    if (!n_nf->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_nf->eadist = new CFSEnergyAngularDist;
                    if (!n_nf->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 21:
                {
                    n_2nf = new CFS2NF;
                    n_2nf->adist = new CFSAngularDist;
                    if (!n_2nf->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_2nf->edist = new CFSEnergyDist;
                    if (!n_2nf->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_2nf->eadist = new CFSEnergyAngularDist;
                    if (!n_2nf->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 22:
                {
                    n_na = new CFSNA;
                    n_na->adist = new CFSAngularDist;
                    if (!n_na->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_na->edist = new CFSEnergyDist;
                    if (!n_na->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_na->eadist = new CFSEnergyAngularDist;
                    if (!n_na->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 23:
                {
                    n_n3a = new CFSN3A;
                    n_n3a->adist = new CFSAngularDist;
                    if (!n_n3a->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_n3a->edist = new CFSEnergyDist;
                    if (!n_n3a->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_n3a->eadist = new CFSEnergyAngularDist;
                    if (!n_n3a->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 24:
                {
                    n_2na = new CFS2NA;
                    n_2na->adist = new CFSAngularDist;
                    if (!n_2na->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_2na->edist = new CFSEnergyDist;
                    if (!n_2na->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_2na->eadist = new CFSEnergyAngularDist;
                    if (!n_2na->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 25:
                {
                    n_3na = new CFS3NA;
                    n_3na->adist = new CFSAngularDist;
                    if (!n_3na->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_3na->edist = new CFSEnergyDist;
                    if (!n_3na->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_3na->eadist = new CFSEnergyAngularDist;
                    if (!n_3na->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 27:
                {
                    absorption = new CFSAbsorption;
                    break;
                }
                case 28:
                {
                    n_np = new CFSNP;
                    n_np->adist = new CFSAngularDist;
                    if (!n_np->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_np->edist = new CFSEnergyDist;
                    if (!n_np->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_np->eadist = new CFSEnergyAngularDist;
                    if (!n_np->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 29:
                {
                    n_n2a = new CFSN2A;
                    n_n2a->adist = new CFSAngularDist;
                    if (!n_n2a->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_n2a->edist = new CFSEnergyDist;
                    if (!n_n2a->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy distribution
                    n_n2a->eadist = new CFSEnergyAngularDist;
                    if (!n_n2a->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 30:
                {
                    n_2n2a = new CFS2N2A;
                    n_2n2a->adist = new CFSAngularDist;
                    if (!n_2n2a->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_2n2a->edist = new CFSEnergyDist;
                    if (!n_2n2a->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_2n2a->eadist = new CFSEnergyAngularDist;
                    if (!n_2n2a->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 32:
                {
                    n_nd = new CFSND;
                    n_nd->adist = new CFSAngularDist;
                    if (!n_nd->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_nd->edist = new CFSEnergyDist;
                    if (!n_nd->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_nd->eadist = new CFSEnergyAngularDist;
                    if (!n_nd->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 33:
                {
                    n_nt = new CFSNT;
                    n_nt->adist = new CFSAngularDist;
                    if (!n_nt->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_nt->edist = new CFSEnergyDist;
                    if (!n_nt->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_nt->eadist = new CFSEnergyAngularDist;
                    if (!n_nt->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 34:
                {
                    n_n3he = new CFSN3HE;
                    n_n3he->adist = new CFSAngularDist;
                    if (!n_n3he->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_n3he->edist = new CFSEnergyDist;
                    if (!n_n3he->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_n3he->eadist = new CFSEnergyAngularDist;
                    if (!n_n3he->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 35:
                {
                    n_nd2a = new CFSND2A;
                    n_nd2a->adist = new CFSAngularDist;
                    if (!n_nd2a->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_nd2a->edist = new CFSEnergyDist;
                    if (!n_nd2a->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_nd2a->eadist = new CFSEnergyAngularDist;
                    if (!n_nd2a->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 36:
                {
                    n_nt2a = new CFSNT2A;
                    n_nt2a->adist = new CFSAngularDist;
                    if (!n_nt2a->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_nt2a->edist = new CFSEnergyDist;
                    if (!n_nt2a->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_nt2a->eadist = new CFSEnergyAngularDist;
                    if (!n_nt2a->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 37:
                {
                    n_4n = new CFS4N;
                    n_4n->adist = new CFSAngularDist;
                    if (!n_4n->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_4n->edist = new CFSEnergyDist;
                    if (!n_4n->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy anugular distribution
                    n_4n->eadist = new CFSEnergyAngularDist;
                    if (!n_4n->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 38:
                {
                    n_3nf = new CFS3NF;
                    n_3nf->adist = new CFSAngularDist;
                    if (!n_3nf->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_3nf->edist = new CFSEnergyDist;
                    if (!n_3nf->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_3nf->eadist = new CFSEnergyAngularDist;
                    if (!n_3nf->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 41:
                {
                    n_2np = new CFS2NP;
                    n_2np->adist = new CFSAngularDist;
                    if (!n_2np->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_2np->edist = new CFSEnergyDist;
                    if (!n_2np->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_2np->eadist = new CFSEnergyAngularDist;
                    if (!n_2np->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 42:
                {
                    n_3np = new CFS3NP;
                    n_3np->adist = new CFSAngularDist;
                    if (!n_3np->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_3np->edist = new CFSEnergyDist;
                    if (!n_3np->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angualar distribution
                    n_3np->eadist = new CFSEnergyAngularDist;
                    if (!n_3np->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 44:
                {
                    n_n2p = new CFSN2P;
                    n_n2p->adist = new CFSAngularDist;
                    if (!n_n2p->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_n2p->edist = new CFSEnergyDist;
                    if (!n_n2p->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    n_n2p->eadist = new CFSEnergyAngularDist;
                    if (!n_n2p->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 45:
                {
                    n_npa = new CFSNPA;
                    n_npa->adist = new CFSAngularDist;
                    if (!n_npa->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    n_npa->edist = new CFSEnergyDist;
                    if (!n_npa->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy distribution
                    n_npa->eadist = new CFSEnergyAngularDist;
                    if (!n_npa->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 51: case 52: case 53: case 54:
                case 55: case 56: case 57: case 58:
                case 59: case 60: case 61: case 62:
                case 63: case 64: case 65: case 66:
                case 67: case 68: case 69: case 70:
                case 71: case 72: case 73: case 74:
                case 75: case 76: case 77: case 78:
                case 79: case 80: case 81: case 82:
                case 83: case 84: case 85: case 86:
                case 87: case 88: case 89: case 90:
                {
                    long l = rxn.MT - 50;
                    levels[l] = new CFSLevel(l);
                    levels[l]->adist = new CFSAngularDist;
                    if (!levels[l]->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Load possible energy angular distribution
                    levels[l]->eadist = new CFSEnergyAngularDist;
                    if (!levels[l]->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 91:
                {
                    continuum = new CFSContinuum;
                    continuum->adist = new CFSAngularDist;
                    if (!continuum->adist->loadACE(rxn.adist)) {
                        std::cerr<<"[CFS]: warning :unable to load adist!"
                        <<std::endl;
                    }
                    
                    // Energy distribution
                    continuum->edist = new CFSEnergyDist;
                    if (!continuum->edist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load edist!");
                    }
                    
                    // Energy angular distribution
                    continuum->eadist = new CFSEnergyAngularDist;
                    if (!continuum->eadist->loadACE(rxn.edist)) {
                        throw std::logic_error("unable to load eadist!");
                    }
                    
                    break;
                }
                case 101:
                {
                    disappear = new CFSDisappear;
                    break;
                }
                case 102:
                {
                    capture = new CFSCapture;
                    break;
                }
                case 103:
                {
                    proton = new CFSProton;
                    break;
                }
                case 104:
                {
                    deuteron = new CFSDeuteron;
                    break;
                }
                case 105:
                {
                    triton = new CFSTriton;
                    break;
                }
                case 106:
                {
                    helium3 = new CFSHelium3;
                    break;
                }
                case 107:
                {
                    alpha = new CFSAlpha;
                    break;
                }
                case 108:
                {
                    n_2a = new CFS2A;
                    break;
                }
                case 109:
                {
                    n_3a = new CFS3A;
                    break;
                }
                case 111:
                {
                    n_2p = new CFS2P;
                    break;
                }
                case 112:
                {
                    n_pa = new CFSPA;
                    break;
                }
                case 113:
                {
                    n_t2a = new CFST2A;
                    break;
                }
                case 114:
                {
                    n_d2a = new CFSD2A;
                    break;
                }
                case 115:
                {
                    n_pd = new CFSPD;
                    break;
                }
                case 116:
                {
                    n_pt = new CFSPT;
                    break;
                }
                case 117:
                {
                    n_da = new CFSDA;
                    break;
                }
                    // Some derived rxn number considered
                case 201: case 202: case 203: case 204:
                case 205: case 206: case 207: case 251:
                case 252: case 253:
                case 301: case 302: case 303: case 304:
                case 305: case 306: case 307: case 308:
                case 309: case 310: case 311: case 312:
                case 313: case 314: case 315: case 316:
                case 317: case 318: case 319: case 320:
                case 321: case 322: case 323: case 324:
                case 325: case 326: case 327: case 328:
                case 329: case 330: case 331: case 332:
                case 333: case 334: case 335: case 336:
                case 337: case 338: case 339: case 340:
                case 341: case 342: case 343: case 344:
                case 345: case 346: case 347: case 348:
                case 349: case 350: case 351: case 352:
                case 353: case 354: case 355: case 356:
                case 357: case 358: case 359: case 360:
                case 361: case 362: case 363: case 364:
                case 365: case 366: case 367: case 368:
                case 369: case 370: case 371: case 372:
                case 373: case 374: case 375: case 376:
                case 377: case 378: case 379: case 380:
                case 381: case 382: case 383: case 384:
                case 385: case 386: case 387: case 388:
                case 389: case 390: case 391: case 392:
                case 393: case 394: case 395: case 396:
                case 397: case 398: case 399: case 400:
                case 401: case 402: case 403: case 404:
                case 405: case 406: case 407: case 408:
                case 409: case 410: case 411: case 412:
                case 413: case 414: case 415: case 416:
                case 417: case 418: case 419: case 420:
                case 421: case 422: case 423: case 424:
                case 425: case 426: case 427: case 428:
                case 429: case 430: case 431: case 432:
                case 433: case 434: case 435: case 436:
                case 437: case 438: case 439: case 440:
                case 441: case 442: case 443: case 444:
                case 445: case 446: case 447: case 448:
                case 449: case 450:
                {
                    std::cout
                    <<"[CFS]: ignore derived rxn MT = "
                    <<rxn.MT<<std::endl;
                    break;
                }
                case 600: case 601: case 602: case 603:
                case 604: case 605: case 606: case 607:
                case 608: case 609: case 610: case 611:
                case 612: case 613: case 614: case 615:
                case 616: case 617: case 618: case 619:
                case 620: case 621: case 622: case 623:
                case 624: case 625: case 626: case 627:
                case 628: case 629: case 630: case 631:
                case 632: case 633: case 634: case 635:
                case 636: case 637: case 638: case 639:
                case 640: case 641: case 642: case 643:
                case 644: case 645: case 646: case 647:
                case 648:
                {
                    long l = rxn.MT - 600;
                    protonLevels[l] = new CFSProtonLevel(l);
                    break;
                }
                case 649:
                {
                    protonContinuum = new CFSProtonContinuum;
                    break;
                }
                case 650: case 651: case 652: case 653:
                case 654: case 655: case 656: case 657:
                case 658: case 659: case 660: case 661:
                case 662: case 663: case 664: case 665:
                case 666: case 667: case 668: case 669:
                case 670: case 671: case 672: case 673:
                case 674: case 675: case 676: case 677:
                case 678: case 679: case 680: case 681:
                case 682: case 683: case 684: case 685:
                case 686: case 687: case 688: case 689:
                case 690: case 691: case 692: case 693:
                case 694: case 695: case 696: case 697:
                case 698:
                {
                    long l = rxn.MT - 650;
                    deuteronLevels[l] = new CFSDeuteronLevel(l);
                    break;
                }
                case 699:
                {
                    deuteronContinuum = new CFSDeuteronContinuum;
                    break;
                }
                case 700: case 701: case 702: case 703:
                case 704: case 705: case 706: case 707:
                case 708: case 709: case 710: case 711:
                case 712: case 713: case 714: case 715:
                case 716: case 717: case 718: case 719:
                case 720: case 721: case 722: case 723:
                case 724: case 725: case 726: case 727:
                case 728: case 729: case 730: case 731:
                case 732: case 733: case 734: case 735:
                case 736: case 737: case 738: case 739:
                case 740: case 741: case 742: case 743:
                case 744: case 745: case 746: case 747:
                case 748:
                {
                    long l = rxn.MT - 700;
                    tritonLevels[l] = new CFSTritonLevel(l);
                    break;
                }
                case 749:
                {
                    tritonContinuum = new CFSTritonContinuum;
                    break;
                }
                case 750: case 751: case 752: case 753:
                case 754: case 755: case 756: case 757:
                case 758: case 759: case 760: case 761:
                case 762: case 763: case 764: case 765:
                case 766: case 767: case 768: case 769:
                case 770: case 771: case 772: case 773:
                case 774: case 775: case 776: case 777:
                case 778: case 779: case 780: case 781:
                case 782: case 783: case 784: case 785:
                case 786: case 787: case 788: case 789:
                case 790: case 791: case 792: case 793:
                case 794: case 795: case 796: case 797:
                case 798:
                {
                    long l = rxn.MT - 750;
                    helium3Levels[l] = new CFSHelium3Level(l);
                    break;
                }
                case 799:
                {
                    helium3Continuum = new CFSHelium3Continuum;
                    break;
                }
                case 800: case 801: case 802: case 803:
                case 804: case 805: case 806: case 807:
                case 808: case 809: case 810: case 811:
                case 812: case 813: case 814: case 815:
                case 816: case 817: case 818: case 819:
                case 820: case 821: case 822: case 823:
                case 824: case 825: case 826: case 827:
                case 828: case 829: case 830: case 831:
                case 832: case 833: case 834: case 835:
                case 836: case 837: case 838: case 839:
                case 840: case 841: case 842: case 843:
                case 844: case 845: case 846: case 847:
                case 848:
                {
                    long l = rxn.MT - 800;
                    alphaLevels[l] = new CFSAlphaLevel(l);
                    break;
                }
                case 849:
                {
                    alphaContinuum = new CFSAlphaContinuum;
                    break;
                }
                    
                default:
                    std::cout
                    <<"[CFS]: unsupported rxn MT = "
                    <<rxn.MT<<std::endl;
                    throw std::logic_error("unsupported rxn");
                    break;
            }
            
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        // Clear memory
        clear();
    }
    
}

CFSNeutronData::~CFSNeutronData() {
    
    // Clear and release memory
    clear();
    
}

void CFSNeutronData::clear() {
    
    // Clear header info
    description = "";
    AWR   = 0.;
    tempK = 0.;
    
    // Release corresponding memory
    deleteReaction(total);
    deleteReaction(elastic);
    deleteReaction(nonelastic);
    deleteReaction(inelastic);
    deleteReaction(anything);
    deleteReaction(prompt);
    deleteReaction(absorption);
    deleteReaction(disappear);
    deleteReaction(capture);
    deleteReaction(proton);
    deleteReaction(deuteron);
    deleteReaction(triton);
    deleteReaction(helium3);
    deleteReaction(alpha);
    
    deleteReaction(n_2nd);
    deleteReaction(n_2n);
    deleteReaction(n_3n);
    deleteReaction(n_na);
    deleteReaction(n_n3a);
    deleteReaction(n_2na);
    deleteReaction(n_3na);
    deleteReaction(n_np);
    deleteReaction(n_n2a);
    deleteReaction(n_2n2a);
    deleteReaction(n_nd);
    deleteReaction(n_nt);
    deleteReaction(n_n3he);
    deleteReaction(n_nd2a);
    deleteReaction(n_nt2a);
    deleteReaction(n_4n);
    deleteReaction(n_2np);
    deleteReaction(n_3np);
    deleteReaction(n_n2p);
    deleteReaction(n_npa);
    
    for (auto& rxn : levels) {
        deleteReaction(rxn);
    }
    deleteReaction(continuum);
    
    deleteReaction(n_f);
    deleteReaction(n_nf);
    deleteReaction(n_2nf);
    deleteReaction(n_3nf);
    
    deleteReaction(n_2a);
    deleteReaction(n_3a);
    deleteReaction(n_2p);
    deleteReaction(n_pa);
    deleteReaction(n_t2a);
    deleteReaction(n_d2a);
    deleteReaction(n_pd);
    deleteReaction(n_pt);
    deleteReaction(n_da);
    
    for (auto& rxn : protonLevels) {
        deleteReaction(rxn);
    }
    deleteReaction(protonContinuum);
    
    for (auto& rxn : deuteronLevels) {
        deleteReaction(rxn);
    }
    deleteReaction(deuteronContinuum);
    
    for (auto& rxn : tritonLevels) {
        deleteReaction(rxn);
    }
    deleteReaction(tritonContinuum);
    
    for (auto& rxn : helium3Levels) {
        deleteReaction(rxn);
    }
    deleteReaction(helium3Continuum);
    
    for (auto& rxn : alphaLevels) {
        deleteReaction(rxn);
    }
    deleteReaction(alphaContinuum);
    
};

void CFSNeutronData::iterateNeutronReactions
(std::function<void(const CFSNeutronReaction*)> action) const {
    
    // Apply actions
    if (n_2nd  != nullptr) action(n_2nd);
    if (n_2n   != nullptr) action(n_2n);
    if (n_3n   != nullptr) action(n_3n);
    if (n_na   != nullptr) action(n_na);
    if (n_n3a  != nullptr) action(n_n3a);
    if (n_2na  != nullptr) action(n_2na);
    if (n_3na  != nullptr) action(n_3na);
    if (n_np   != nullptr) action(n_np);
    if (n_n2a  != nullptr) action(n_n2a);
    if (n_2n2a != nullptr) action(n_2n2a);
    if (n_nd   != nullptr) action(n_nd);
    if (n_nt   != nullptr) action(n_nt);
    if (n_n3he != nullptr) action(n_n3he);
    if (n_nd2a != nullptr) action(n_nd2a);
    if (n_nt2a != nullptr) action(n_nt2a);
    if (n_4n   != nullptr) action(n_4n);
    if (n_2np  != nullptr) action(n_2np);
    if (n_3np  != nullptr) action(n_3np);
    if (n_n2p  != nullptr) action(n_n2p);
    if (n_npa  != nullptr) action(n_npa);
    
    for (const auto rxn : levels) {
        if (rxn != nullptr) action(rxn);
    }
    
    if (continuum != nullptr) action(continuum);
    
}

// A valid data must have an elastic scattering rxn
bool CFSNeutronData::valid() const {
    return elastic != nullptr;
}

const CFSReaction* CFSNeutronData::getReactionByNumber(long MT) const {
    
    try {
        
        // Check reaction MT number
        switch (MT) {
            case 1:
            {
                return total;
            }
            case 2:
            {
                return elastic;
            }
            case 3:
            {
                return nonelastic;
            }
            case 4:
            {
                return inelastic;
            }
            case 5:
            {
                return anything;
            }
            case 11:
            {
                return n_2nd;
            }
            case 16:
            {
                return n_2n;
            }
            case 17:
            {
                return n_3n;
            }
            case 18:
            {
                return prompt;
            }
            case 19:
            {
                return n_f;
            }
            case 20:
            {
                return n_nf;
            }
            case 21:
            {
                return n_2nf;
            }
            case 22:
            {
                return n_na;
            }
            case 23:
            {
                return n_n3a;
            }
            case 24:
            {
                return n_2na;
            }
            case 25:
            {
                return n_3na;
            }
            case 27:
            {
                return absorption;
            }
            case 28:
            {
                return n_np;
            }
            case 29:
            {
                return n_n2a;
            }
            case 30:
            {
                return n_2n2a;
            }
            case 32:
            {
                return n_nd;
            }
            case 33:
            {
                return n_nt;
            }
            case 34:
            {
                return n_n3he;
            }
            case 35:
            {
                return n_nd2a;
            }
            case 36:
            {
                return n_nt2a;;
            }
            case 37:
            {
                return n_4n;
            }
            case 38:
            {
                return n_3nf;
            }
            case 41:
            {
                return n_2np;;
            }
            case 42:
            {
                return n_3np;
            }
            case 44:
            {
                return n_n2p;
            }
            case 45:
            {
                return n_npa;
            }
            case 51: case 52: case 53: case 54:
            case 55: case 56: case 57: case 58:
            case 59: case 60: case 61: case 62:
            case 63: case 64: case 65: case 66:
            case 67: case 68: case 69: case 70:
            case 71: case 72: case 73: case 74:
            case 75: case 76: case 77: case 78:
            case 79: case 80: case 81: case 82:
            case 83: case 84: case 85: case 86:
            case 87: case 88: case 89: case 90:
            {
                long l = MT - 50;
                return levels[l];
            }
            case 91:
            {
                return continuum;
            }
            case 101:
            {
                return disappear;
            }
            case 102:
            {
                return capture;
            }
            case 103:
            {
                return proton;
            }
            case 104:
            {
                return deuteron;
            }
            case 105:
            {
                return triton;
            }
            case 106:
            {
                return helium3;
            }
            case 107:
            {
                return alpha;
            }
            case 108:
            {
                return n_2a;
            }
            case 109:
            {
                return n_3a;
            }
            case 111:
            {
                return n_2p;
            }
            case 112:
            {
                return n_pa;
            }
            case 113:
            {
                return n_t2a;
            }
            case 114:
            {
                return n_d2a;
            }
            case 115:
            {
                return n_pd;
            }
            case 116:
            {
                return n_pt;
            }
            case 117:
            {
                return n_da;
            }
                // Some derived rxn number considered
            case 201: case 202: case 203: case 204:
            case 205: case 206: case 207: case 251:
            case 252: case 253:
            case 301: case 302: case 303: case 304:
            case 305: case 306: case 307: case 308:
            case 309: case 310: case 311: case 312:
            case 313: case 314: case 315: case 316:
            case 317: case 318: case 319: case 320:
            case 321: case 322: case 323: case 324:
            case 325: case 326: case 327: case 328:
            case 329: case 330: case 331: case 332:
            case 333: case 334: case 335: case 336:
            case 337: case 338: case 339: case 340:
            case 341: case 342: case 343: case 344:
            case 345: case 346: case 347: case 348:
            case 349: case 350: case 351: case 352:
            case 353: case 354: case 355: case 356:
            case 357: case 358: case 359: case 360:
            case 361: case 362: case 363: case 364:
            case 365: case 366: case 367: case 368:
            case 369: case 370: case 371: case 372:
            case 373: case 374: case 375: case 376:
            case 377: case 378: case 379: case 380:
            case 381: case 382: case 383: case 384:
            case 385: case 386: case 387: case 388:
            case 389: case 390: case 391: case 392:
            case 393: case 394: case 395: case 396:
            case 397: case 398: case 399: case 400:
            case 401: case 402: case 403: case 404:
            case 405: case 406: case 407: case 408:
            case 409: case 410: case 411: case 412:
            case 413: case 414: case 415: case 416:
            case 417: case 418: case 419: case 420:
            case 421: case 422: case 423: case 424:
            case 425: case 426: case 427: case 428:
            case 429: case 430: case 431: case 432:
            case 433: case 434: case 435: case 436:
            case 437: case 438: case 439: case 440:
            case 441: case 442: case 443: case 444:
            case 445: case 446: case 447: case 448:
            case 449: case 450:
            {
                std::cout
                <<"[CFS]: ignore derived rxn MT = "
                <<MT<<std::endl;
                return nullptr;
            }
            case 600: case 601: case 602: case 603:
            case 604: case 605: case 606: case 607:
            case 608: case 609: case 610: case 611:
            case 612: case 613: case 614: case 615:
            case 616: case 617: case 618: case 619:
            case 620: case 621: case 622: case 623:
            case 624: case 625: case 626: case 627:
            case 628: case 629: case 630: case 631:
            case 632: case 633: case 634: case 635:
            case 636: case 637: case 638: case 639:
            case 640: case 641: case 642: case 643:
            case 644: case 645: case 646: case 647:
            case 648:
            {
                long l = MT - 600;
                return protonLevels[l];
            }
            case 649:
            {
                return protonContinuum;
            }
            case 650: case 651: case 652: case 653:
            case 654: case 655: case 656: case 657:
            case 658: case 659: case 660: case 661:
            case 662: case 663: case 664: case 665:
            case 666: case 667: case 668: case 669:
            case 670: case 671: case 672: case 673:
            case 674: case 675: case 676: case 677:
            case 678: case 679: case 680: case 681:
            case 682: case 683: case 684: case 685:
            case 686: case 687: case 688: case 689:
            case 690: case 691: case 692: case 693:
            case 694: case 695: case 696: case 697:
            case 698:
            {
                long l = MT - 650;
                return deuteronLevels[l];
            }
            case 699:
            {
                return deuteronContinuum;
            }
            case 700: case 701: case 702: case 703:
            case 704: case 705: case 706: case 707:
            case 708: case 709: case 710: case 711:
            case 712: case 713: case 714: case 715:
            case 716: case 717: case 718: case 719:
            case 720: case 721: case 722: case 723:
            case 724: case 725: case 726: case 727:
            case 728: case 729: case 730: case 731:
            case 732: case 733: case 734: case 735:
            case 736: case 737: case 738: case 739:
            case 740: case 741: case 742: case 743:
            case 744: case 745: case 746: case 747:
            case 748:
            {
                long l = MT - 700;
                return tritonLevels[l];
            }
            case 749:
            {
                return tritonContinuum;
                break;
            }
            case 750: case 751: case 752: case 753:
            case 754: case 755: case 756: case 757:
            case 758: case 759: case 760: case 761:
            case 762: case 763: case 764: case 765:
            case 766: case 767: case 768: case 769:
            case 770: case 771: case 772: case 773:
            case 774: case 775: case 776: case 777:
            case 778: case 779: case 780: case 781:
            case 782: case 783: case 784: case 785:
            case 786: case 787: case 788: case 789:
            case 790: case 791: case 792: case 793:
            case 794: case 795: case 796: case 797:
            case 798:
            {
                long l = MT - 750;
                return helium3Levels[l];
            }
            case 799:
            {
                return helium3Continuum;
            }
            case 800: case 801: case 802: case 803:
            case 804: case 805: case 806: case 807:
            case 808: case 809: case 810: case 811:
            case 812: case 813: case 814: case 815:
            case 816: case 817: case 818: case 819:
            case 820: case 821: case 822: case 823:
            case 824: case 825: case 826: case 827:
            case 828: case 829: case 830: case 831:
            case 832: case 833: case 834: case 835:
            case 836: case 837: case 838: case 839:
            case 840: case 841: case 842: case 843:
            case 844: case 845: case 846: case 847:
            case 848:
            {
                long l = MT - 800;
                return alphaLevels[l];
            }
            case 849:
            {
                return alphaContinuum;
            }
                
            default:
                std::cout
                <<"[CFS]: unsupported rxn MT = "
                <<MT<<std::endl;
                throw std::logic_error("unsupported rxn");
                break;
        }
        
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        return nullptr;
    }
}

static long ENDFTabGetLaw
(const std::vector<ENDFInterpLaw>& interp, long i) {
    long m = -1, n = -1, law = -1;
    
    // Range check
    if (i<0 || i>(interp.back().NBT-2)) {
        return 0;
    }
    if (interp.empty()) {
        // Linear-Linear law
        law = 2;
    } else {
        // Obtain region number m
        m = 0, n = (long)interp.size();
        // Binary search
        while (m + 1 < n ) {
            // k >= 1 is garanteed
            long k = ( m + n )/2;
            if (i >= (interp[k-1].NBT-1)) {
                m = k;
            } else {
                n = k;
            }
        }
        // Assign law
        law = interp[m].INT;
    }
    
    return law;
}

// Implementations for CFS class
bool CFS::compareNeutronData
(CFSNeutronData* ndata1, CFSNeutronData* ndata2) {
    
    try {
    
        if (ndata1 == nullptr) {
            throw std::logic_error("invalid ndata 1!");
        }
        
        if (ndata2 == nullptr) {
            throw std::logic_error("invalid ndata 2!");
        }
        
        // Using the std namespace
        using namespace std;
        
        // Print general information comparison
        cout<<endl;
        cout
        << '|' << left << setw(16) << "General Info"
        << '|' << setw(10) << ndata1->description
        << '|' << setw(10) << ndata2->description
        << '|' << endl;
        cout
        << '|' << left << setw(16) << "Temp. K"
        << '|' << setw(10) << ndata1->tempK
        << '|' << setw(10) << ndata2->tempK
        << '|' << endl;
        cout
        << '|' << left << setw(16) << "AWR"
        << '|' << setw(10) << ndata1->AWR
        << '|' << setw(10) << ndata2->AWR
        << '|' << endl;
        
        
        // Print reaction summary information
        cout<<endl;
        cout
        << '|' << left << setw(16) << "Reactions "
        << '|' << setw(10) << ndata1->description
        << '|' << setw(10) << ndata2->description
        << '|' << endl;
        for (long MT : CFSNeutronData::supportedReactionNumbers()) {
            auto rxn1 = ndata1->getReactionByNumber(MT);
            auto rxn2 = ndata2->getReactionByNumber(MT);
            if (rxn1 != nullptr || rxn2 != nullptr) {
                cout
                << '|' << left << setw(16) << ("Has MT = " + std::to_string(MT))
                << '|' << setw(10) << ((rxn1 != nullptr)?"yes":"no")
                << '|' << setw(10) << ((rxn2 != nullptr)?"yes":"no")
                << '|' << endl;
            }
        }
        
        // Print indidividual reactions information
        for (long MT : CFSNeutronData::supportedReactionNumbers()) {
            auto rxn1 = ndata1->getReactionByNumber(MT);
            auto rxn2 = ndata2->getReactionByNumber(MT);
            if (rxn1 != nullptr && rxn2 != nullptr) {
                cout<<endl;
                cout
                << '|' << left << setw(16) << ("Rxn MT = " + std::to_string(MT))
                << '|' << setw(10) << ndata1->description
                << '|' << setw(10) << ndata2->description
                << '|' << endl;
                
                // Angular distribution
                cout
                << '|' << left << setw(16) << "Has adist."
                << '|' << setw(10) << ((rxn1 ->hasAdist())?"yes":"no")
                << '|' << setw(10) << ((rxn2 ->hasAdist())?"yes":"no")
                << '|' << endl;
                
                // Check angular distribution
                if (rxn1->hasAdist() && rxn2->hasAdist()) {
                    auto adist1 = rxn1->getAdist();
                    auto adist2 = rxn2->getAdist();
                    
                    // Print out the all adist info
                    cout<<endl;
                    cout
                    << '|' << left << setw(16) << ("Adist.")
                    << '|' << setw(10) << ndata1->description
                    << '|' << setw(10) << ndata2->description
                    << '|' << endl;
                    
                    // Check whether isotropic
                    cout
                    << '|' << left << setw(16) << " isotropic"
                    << '|' << setw(10) << ((adist1->isIsotropic())?"yes":"no")
                    << '|' << setw(10) << ((adist2->isIsotropic())?"yes":"no")
                    << '|' << endl;
                    
                    // If not all isotrpic print energy info.
                    if (!adist1->isIsotropic() && !adist2->isIsotropic()) {
                        cout
                        << '|' << left << setw(16) << " tabular pts."
                        << '|' << setw(10) << adist1->ergInFunc->data().size()
                        << '|' << setw(10) << adist2->ergInFunc->data().size()
                        << '|' << endl;
                        
                        // Check energy grid and interp law
                        long NE1 = adist1->ergInFunc->data().size();
                        long NE2 = adist2->ergInFunc->data().size();
                        
                        if (NE1 == NE2) {
                            // Check grid
                            cout
                            << '|' << left << setw(16) << " erg. grid idx."
                            << '|' << setw(10) << ""
                            << '|' << setw(10) << ""
                            << '|' << endl;
                            for (long i=0; i<NE1; i++) {
                                cout
                                << '|' << left << setw(16) << i
                                << '|' << setw(10) << adist1->ergInFunc->data(i).x
                                << '|' << setw(10) << adist2->ergInFunc->data(i).x
                                << '|' << endl;
                            }
                            // Check interp law
                            cout
                            << '|' << left << setw(16) << " interp law"
                            << '|' << setw(10) << ""
                            << '|' << setw(10) << ""
                            << '|' << endl;
                            for (long i=0; i<NE1; i++) {
                                cout
                                << '|' << left << setw(16) << i
                                << '|' << setw(10) <<
                                ENDFTabGetLaw(adist1->ergInFunc->interp(), i)
                                << '|' << setw(10) <<
                                ENDFTabGetLaw(adist2->ergInFunc->interp(), i)
                                << '|' << endl;
                            }
                            // Check anglar dist func.
                            cout
                            << '|' << left << setw(16) << " adist type"
                            << '|' << setw(10) << ""
                            << '|' << setw(10) << ""
                            << '|' << setw(10) << "max. rel. diff."
                            << '|' << endl;
                            for (long i=0; i<NE1; i++) {
                                auto& f1 = adist1->ergInFunc->data(i).y;
                                auto& f2 = adist2->ergInFunc->data(i).y;
                                
                                cout
                                << '|' << left << setw(16) << i
                                << '|' << setw(10) << (f1.isIsotropic()?"I":"T")
                                << '|' << setw(10) << (f2.isIsotropic()?"I":"T");
                                
                                if (!f1.isIsotropic() && !f2.isIsotropic()) {
                                    auto func1 = f1.tabular;
                                    auto func2 = f2.tabular;
                                    // Comutate function value difference
                                    // Number of segements
                                    long N  = 2000;
                                    double DX = 2.0/N;
                                    std::vector<double> xgrid(N+1, 0.);
                                    std::vector<double> ygrid1(N+1, 0.);
                                    std::vector<double> ygrid2(N+1, 0.);
                                    double maxRelDiff = 0.;
                                    double maxDiff = 0.;
                                    xgrid[0] = -1.;
                                    for (long n=0; n<N-1; n++) {
                                        xgrid[n+1] = -1. + DX*(n+1);
                                    }
                                    xgrid[N] = 1.;
                                    for (long n=0; n<N+1; n++) {
                                        auto  x  = xgrid[n];
                                        auto  y1 = func1->evaluateCDF(x);
                                        auto  y2 = func2->evaluateCDF(x);
                                        if (fabs(y1) > CMS::zeroThres && fabs(y2) > CMS::zeroThres) {
                                            maxRelDiff = std::max(maxRelDiff, fabs(y1-y2)/y2);
                                            maxDiff = std::max(maxDiff, fabs(y1-y2));
                                        }
                                        ygrid1[n] = y1;
                                        ygrid2[n] = y2;
                                    }
                                    cout << '|' << setw(10) << maxRelDiff;
                                    if (maxRelDiff > 0.05 && maxDiff > 0.01) {
                                        cout << '|' << setw(10) << "LARGE";
                                        cout << '|' << setw(10) << maxDiff;
                                        cout << "\nd1 = [" <<endl;
                                        for (long i=0; i<func1->data().size(); i++) {
                                            cout
                                            << func1->data(i).x <<" "
                                            << func1->data(i).cdf << endl;
                                        }
                                        cout << "]" <<endl;
                                        cout << "\nd2 = [" <<endl;
                                        for (long i=0; i<func2->data().size(); i++) {
                                            cout
                                            << func2->data(i).x <<" "
                                            << func2->data(i).cdf << endl;
                                        }
                                        cout << "]" <<endl;
                                    }
                                }
                                cout << '|' << endl;

                            }
                        }
                    }
                    
                }
                
                // Energy distribution
                cout
                << '|' << left << setw(16) << "Has edist."
                << '|' << setw(10) << ((rxn1 ->hasEdist())?"yes":"no")
                << '|' << setw(10) << ((rxn2 ->hasEdist())?"yes":"no")
                << '|' << endl;
            }
        }
    
    } catch (std::exception& e) {
        std::cerr << "[CFS]: error msg - " << e.what() << std::endl;
        return false;
    }
    
    return true;
}

/*
 
 // Copy the temperature from the ndata
 cndata->tempK = ndata->tempK;
 
 // Intermedia energy grid
 std::set<double> energyDataPointsEv;
 
 // Loop over all reactions:
 // 1) Prepare energy-cross section pairs, stored
 // 2) Accumulate energy grid points
 std::vector<XLSFunction> xsecs;
 xsecs.resize(ndata->reactions.size());
 for (long i=0; i < xsecs.size(); i++) {
 
 // Linearize cross section
 xsecs[i] = XLS::linearizeENDFInterpFunc
 (ndata->reactions[i].xsec, CMS::defaultTol);
 
 // Add cross section data points
 for (auto& dp : xsecs[i].data) {
 energyDataPointsEv.insert(dp.x);
 }
 
 }
 
 // Obtain the resolved resonance reconstructed cross sections
 auto rrxsec = XRS::processResolvedResonance(ndata, CMS::defaultTol);
 
 // Add resolved resonance data points to energy grid
 for (auto& p : rrxsec.data) {
 energyDataPointsEv.insert(p.x);
 }
 
 // Construct cross sections on the common energy grid
 
 */

