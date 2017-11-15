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

// Computational Format System

#ifndef CFS_HPP
#define CFS_HPP

#include "NRS.hpp"
#include "CMS.hpp"
#include "ENDF.hpp"
#include "ACE.hpp"

#include <iostream>
#include <vector>
#include <functional>
#include <set>

//namespace com {
//namespace ibhe {

// Angular function
// In new evaluation, the 32-equirobable cosine bin format
// is not supported
// If tabular is nullptr, it is isotropic, otherwise tabular
// The result describes a distributin function
// for value between -1 and 1
// The angular distribution is assumed to
// have a normalization integral of 1.0
struct CFSAngularDistribution {
    
    ENDFTabularDistribution<>* tabular = nullptr;
    
    // CFSDistribution<>* tabular = nullptr;
    
    ~CFSAngularDistribution();
    
    void clear();
    
    bool isIsotropic() const;
    
    bool setIsotropic();
    
    // Set tabular from normalized pdf function
    bool setTabular(const ENDFInterpolationFunction& pfunc);
    bool setTabular(const ENDFTabularDistribution<>& dist);
    
    // Convert from ACE angular distribution
    bool loadACE(const ACEAngularDistribution& adist);
    
};

// The yield is used to describe the number of particles
// emitted from a reaction
struct CFSYield {
    
    // The constant expression
    long number = 0;
    
    // The function expression
    ENDFInterpolationFunction *function = nullptr;
    
    // Custom constrctor
    CFSYield() {};
    CFSYield(long _number) :number(_number) {}
    CFSYield(const ENDFInterpolationFunction& _function) {
        function = new ENDFInterpolationFunction;
        if (function != nullptr) {
            *function = _function;
        }
    }
    
    // Custom destructor
    virtual ~CFSYield() {
        clear();
    }
    
    // Clear the data structure
    void clear() {
        number = 0;
        if (function != nullptr) {
            delete function;
            function = nullptr;
        }
    }
    
    // If the function is a null pointer,
    // the yield is considered to be a constant
    bool constant() const {
        return function != nullptr;
    }
    
};

// Computational Neutron Data, this is the data structure that used for
// neutron transport software. We provide this data structure as an
// intermediate container for storing the generated neutron data
// in a form easy for doing transport calculation. Also it can be
// converted into other formats that the user desired.
// The CFS abstraction make it to be a central hub to the conversion
// between different format of cross sections.

struct CFSMainRxnDataPoint {
    
    // Total cross section, MT = 1
    double total      = 0.;
    
    // Elastic scattering cross section, MT = 2
    double elastic    = 0.;
    
    // Absorption cross section, MT = 27 = 18 + 101
    double absorption = 0.;
    
    // Fission cross section, MT = 18
    double fission    = 0.;
    
};

// The energy grid along with key cross sections
typedef ENDFObjectInterpolationFunction
<CFSMainRxnDataPoint> CFSEnergyGrid;

struct CFSXsec {
    
    // The starting index of the cross section on the energy grid
    long startIndex = 0;
    
    // The cross section data points in barn
    std::vector<double> sigmas;
    
};

// Angular distribution, the angular distribution is
// a compuational format describing the ditrinution
// f(mu, E), which is first interpolated on an energy
// grid, and then linearly interpolated in mu
struct CFSAngularDist {
    
    // Space system
    ENDFSpaceSystem system;
    
    // Energy function, if not exist, assume to be isotropic
    ENDFObjectInterpolationFunction
    < CFSAngularDistribution >* ergInFunc = nullptr;
    
    // Clear function
    void clear();
    
    /* Public interfaces */
    
    // Whether is purly isotropic
    bool isIsotropic() const;
    
    // Load the ENDF version of angular distribution
    bool loadENDF(const ENDFNeutronData::AngularDist&);
    
    // Load the ACE version of angular distribution
    bool loadACE(const ACEAngularDist&);
    
    // Sample function
    
};

// Energy distribution
// The design goal of this is to be computationally firendly
// The MCNP law 22 and 24 is not supported
struct CFSEnergyDist {
    
    // Energy law
    enum class Law {
        // Arbitrary Tabulated Function
        LAW4  = 4,
        // General Evaporation Spectrum
        LAW5  = 5,
        // Simple Maxwellian Fission Spectrum
        LAW7  = 7,
        // Evaporation Spectrum
        LAW9  = 9,
        // Energy-Dependent Watt Spectrum
        LAW11 = 11
    };
    
    struct Law4Data {
        
        using DiscreteInfo =
        ENDFNeutronData::EnergyAngularDist::DiscreteInfo;
        
        ENDFObjectInterpolationFunction
        < ENDFTabularDistribution
        < DiscreteInfo > > func;
        
        void clear() {
            func.clear();
        }
        
        // Load the ENDF law data
        bool loadENDF(const ENDFNeutronData::EnergyDist::Law1Data&);
        bool loadENDF(const ENDFNeutronData::EnergyDist::Law12Data&);
        
        // Load the ACE law data
        bool loadACE(const ACEEnergyDist::Law4Data&);
        
    };
    
    // Reuse ENDF file 5 law 5
    struct Law5Data : ENDFNeutronData::EnergyDist::Law5Data {
        
        void clear() {
            U = 0.;
            theta.clear();
            g.clear();
        }
        
        // Load the ENDF law data
        bool loadENDF(const ENDFNeutronData::EnergyDist::Law5Data&);
        
    };
    
    // Reuse ENDF file 5 law 7
    struct Law7Data : ENDFNeutronData::EnergyDist::Law7Data {
        
        void clear() {
            U = 0.;
            theta.clear();
        }
        
        // Load the ENDF law data
        bool loadENDF(const ENDFNeutronData::EnergyDist::Law7Data&);
        
        // Load the ACE law data
        bool loadACE(const ACEEnergyDist::Law7Data&);
        
    };
    
    // Reuse ENDF file 5 law 9
    struct Law9Data  : ENDFNeutronData::EnergyDist::Law9Data {
        
        void clear() {
            U = 0.;
            theta.clear();
        }
        
        // Load the ENDF law data
        bool loadENDF(const ENDFNeutronData::EnergyDist::Law9Data&);
        
        // Load the ACE law data
        bool loadACE(const ACEEnergyDist::Law9Data&);
        
    };
    
    // Reuse ENDF file 5 law 11
    struct Law11Data : ENDFNeutronData::EnergyDist::Law11Data {
        
        void clear() {
            U = 0.;
            a.clear();
            b.clear();
        }
        
        // Load the ENDF law data
        bool loadENDF(const ENDFNeutronData::EnergyDist::Law11Data&);
        
        // Load the ACE law data
        bool loadACE(const ACEEnergyDist::Law11Data&);

    };
    
    struct PartialDist {
        
        // Law
        Law law;
        
        // Validity
        ENDFInterpolationFunction validity;
        
        // Containers of law data
        Law4Data  law4;
        Law5Data  law5;
        Law7Data  law7;
        Law9Data  law9;
        Law11Data law11;
        
    };
    
    // Partial distributions
    std::vector<PartialDist> partialDists;
    
    // Clear data
    void clear() {
        partialDists.clear();
    }
    
    // Load the ENDF version of energy distribution
    bool loadENDF(const ENDFNeutronData::EnergyDist&);
    
    // Load the ACE version of energy distribution
    bool loadACE(const ACEEnergyDist&);
    
};

// Energy-Angle coupled distribution
// The design goal of this is to be computationally firendly
// In ACE labbray, this is combined with a single erg. dist.
// We combine as well.
struct CFSEnergyAngularDist {
    
    // Energy law, here the unknown law will raise
    // an exception during the code excution
    
    // Need to be considered later
    enum class Law {
        // Kalbach laws for angular dist
        LAW44  = 44,
        // Tabular angular dist
        LAW61  = 61,
        // Two-body reaction angular distribution
        LAW62  = 62,
        // Isotrpic two-body distribution
        LAW63  = 63,
        // N-body phase-space distribution
        LAW66  = 66,
        // Laboratory angle-energy law
        LAW67  = 67
    };
    
    // Define the law data
    struct Law44Data {
        
        using DiscreteInfo =
        ENDFNeutronData::EnergyAngularDist::DiscreteInfo;
        
        ENDFObjectInterpolationFunction
        < ENDFObjectTabularDistribution
        < ENDFkalbachMannDistribution, DiscreteInfo > > func;
        
        void clear() {
            func.clear();
        }
        
        // Load the ENDF law data
        bool loadENDF(const ENDFNeutronData::EnergyAngularDist::Law1Data&);
        
        // Load the ACE law data
        bool loadACE(const ACEEnergyDist::Law44Data&);
        
    };
    
    struct Law61Data {
        
        using DiscreteInfo =
        ENDFNeutronData::EnergyAngularDist::DiscreteInfo;
        
        ENDFObjectInterpolationFunction
        < ENDFObjectTabularDistribution
        < CFSAngularDistribution, DiscreteInfo > > func;
        
        void clear() {
            func.clear();
        }
        
        // Load the ENDF law data
        bool loadENDF(const ENDFNeutronData::EnergyAngularDist::Law1Data&);
        bool loadENDF(const ENDFNeutronData::EnergyAngularDist::Law7Data&);
        
        // Load the ACE law data
        bool loadACE(const ACEEnergyDist::Law61Data&);
        
    };
    
    struct Law66Data : ENDFNeutronData::EnergyAngularDist::Law6Data {
        
        void clear() {
            APSX = 0.;
            NPSX = 0.;
        }
        
        // Load the ENDF law data
        bool loadENDF(const ENDFNeutronData::EnergyAngularDist::Law6Data&);
        
        // Load the ACE law data
        bool loadACE(const ACEEnergyDist::Law66Data&);
        
    };
    
    struct Law67Data {
        
        ENDFObjectInterpolationFunction
        < ENDFObjectInterpolationFunction
        < ENDFObjectTabularDistribution<> > > func;
        
        void clear() {
            func.clear();
        }
        
        // Load the ENDF law data
        bool loadENDF(const ENDFNeutronData::EnergyAngularDist::Law7Data&);
        
        // Load the ACE law data
        bool loadACE(const ACEEnergyDist::Law67Data&);
        
    };
    
    struct Product {
        
        // Law
        Law law;
        
        // The system of scattering
        ENDFSpaceSystem system;
        
        // Containers of law data
        Law44Data law44;
        Law61Data law61;
        Law66Data law66;
        Law67Data law67;
        
    };
    
    // Partial distributions
    std::vector<Product> products;
    
    // Clear data
    void clear() {
        products.clear();
    }
    
    // Load the ENDF version of energy distribution
    // This function will load the neutron reaction
    // ZAP = 1
    bool loadENDF(const ENDFNeutronData::EnergyAngularDist&);
    
    // Load the ACE version of energy distribution
    bool loadACE(const ACEEnergyDist&);
    
};

// The outgoing particle distribution
// This is general discription for any partile, such as:
// neutron, gamma, proton, deuteron, triton, helium3, alpha, or other
// all of them are identified by the ZAP number

// The key design here is that it implicitly
struct CFSDist {
    
    // Could have the separated ang. dist and erg. dist
    CFSAngularDist *adist = nullptr;
    CFSEnergyDist  *edist = nullptr;
    
    // Or a coupled energy-angle dist
    CFSEnergyAngularDist *eadist = nullptr;
    
};


// The reaction is a common interface for different represnetations
// of all possible reactions. The design goal is simplying the
// queries in the transport calculations. The key is

struct CFSReaction {
    
    // Reaction MT number
    long   MT = 0;
    
    // Background cross section
    // Keep an original ENDF background cross section
    ENDFInterpolationFunction bgXsec;
    
    // Interfaces of a reaction
    CFSReaction(long _MT = 0) :MT(_MT) {}
    
    virtual ~CFSReaction() {}
    
    // Whether has an angular distribution
    virtual bool hasAdist() const {
        return false;
    }
    
    // Whether has an energy distribution
    virtual bool hasEdist() const {
        return false;
    }
    
    // Obtain the possible angular distribution
    virtual CFSAngularDist* getAdist() const {
        return nullptr;
    }
    
    // Obtain the possible energy distribution
    virtual CFSAngularDist* getEdist() const {
        return nullptr;
    }
    
};

// Mass-difference Q value
// double QM = 0.;

// Scattering in CM or LAB
// ENDFSpaceSystem system;

// It may be possible to explicitly categorize all reactions

// Main reaction, MT = 1, 2, 18, 27
struct CFSMainReaction : CFSReaction {
    
    // Interfaces
    
    
};

/* Reaction interfaces */

// Neutron production reactions, exclude fission
// MT = 11, 16, 17, 22-25, 28-30, 32-37, 41, 42, 44, 45, 51-91

struct CFSNeutronReaction : CFSReaction {
    
    /* Addtional member variables */
    
    // Number of neutrons
    long neutrons = 0;
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Energy distribution
    CFSEnergyDist  *edist = nullptr;
    
    // Energy angular distribution
    CFSEnergyAngularDist *eadist = nullptr;
    
    // Interfaces
    CFSNeutronReaction(long _MT, long _neutrons)
    :CFSReaction(_MT), neutrons(_neutrons) {}
    
    virtual ~CFSNeutronReaction() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
        if (edist != nullptr) {
            delete edist;
            edist = nullptr;
        }
        if (eadist != nullptr) {
            delete eadist;
            eadist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// Partial fission reactions
// MT = 19, 20, 21, 38

struct CFSPartialFissionReaction : CFSReaction {
    
    /* Addtional member variables */
    
    // Number of neutrons
    long chance = 0;
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Energy distribution
    CFSEnergyDist  *edist = nullptr;
    
    // Energy angular distribution
    CFSEnergyAngularDist *eadist = nullptr;
    
    // Interfaces
    CFSPartialFissionReaction(long _MT, long _chance)
    :CFSReaction(_MT), chance(_chance) {}
    
    virtual ~CFSPartialFissionReaction() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
        if (edist != nullptr) {
            delete edist;
            edist = nullptr;
        }
        if (eadist != nullptr) {
            delete eadist;
            eadist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};


/* Definition of individual reactions */

// Total reaction, MT = 1
struct CFSTotal : CFSReaction {
    
    // Interfaces
    CFSTotal() :CFSReaction(1) {}
    
};

// Elastic reaction, MT = 2
// Do not require energy distributions (File 5)
struct CFSElastic : CFSNeutronReaction {
    
    // Interfaces
    CFSElastic() :CFSNeutronReaction(2, 1) {}
    
};

// Nonelastic reaction, MT = 3
struct CFSNonelastic : CFSReaction {
    
    // Interfaces
    CFSNonelastic() :CFSReaction(3) {}
    
};

// Inelastic, MT = 4
struct CFSInelastic : CFSReaction {
    
    // Interfaces
    CFSInelastic() :CFSReaction(4) {}
    
};

// Anything, MT = 5
struct CFSAnything : CFSReaction {
    
    /* Addtional member variables */
    
    // Angular distribution
    CFSEnergyAngularDist *eadist = nullptr;
    
    // Interfaces
    CFSAnything() :CFSReaction(5) {}
    
    virtual ~CFSAnything() {
        if (eadist != nullptr) {
            delete eadist;
            eadist = nullptr;
        }
    }
    
};

// (z,2nd), MT = 11
struct CFS2ND : CFSNeutronReaction {
    
    // Interfaces
    CFS2ND() :CFSNeutronReaction(11, 2) {}
    
};

// (z,2n), MT = 16
struct CFS2N : CFSNeutronReaction {
    
    // Interfaces
    CFS2N() :CFSNeutronReaction(16, 2) {}
    
};

// (z,3n), MT = 17
struct CFS3N : CFSNeutronReaction {
    
    // Interfaces
    CFS3N() :CFSNeutronReaction(17, 3) {}
    
};

// Total fission, MT = 18
struct CFSFission : CFSReaction {
    
    /* Addtional member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Energy distribution
    CFSEnergyDist  *edist = nullptr;
    
    // Energy angular distribution
    CFSEnergyAngularDist *eadist = nullptr;
    
    // Interfaces
    CFSFission() :CFSReaction(18) {}
    
    virtual ~CFSFission() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
        if (edist != nullptr) {
            delete edist;
            edist = nullptr;
        }
        if (eadist != nullptr) {
            delete eadist;
            eadist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// (n,f), MT = 19
struct CFSF : CFSPartialFissionReaction {
    
    // Interfaces
    CFSF() :CFSPartialFissionReaction(19, 1) {}
    
};

// (n,nf), MT = 20
struct CFSNF : CFSPartialFissionReaction {
    
    // Interfaces
    CFSNF() :CFSPartialFissionReaction(20, 2) {}
    
};

// (n,2nf), MT = 21
struct CFS2NF : CFSPartialFissionReaction {
    
    // Interfaces
    CFS2NF() :CFSPartialFissionReaction(21, 3) {}
    
};

// (z,na), MT = 22
struct CFSNA : CFSNeutronReaction {
    
    // Interfaces
    CFSNA() :CFSNeutronReaction(22, 1) {}
    
};

// (n,n3a), MT = 23
struct CFSN3A : CFSNeutronReaction {
    
    // Interfaces
    CFSN3A() :CFSNeutronReaction(23, 1) {}
    
};

// (z,2na), MT = 24
struct CFS2NA : CFSNeutronReaction {
    
    // Interfaces
    CFS2NA() :CFSNeutronReaction(24, 2) {}
    
};

// (z,3na), MT = 25
struct CFS3NA : CFSNeutronReaction {
    
    // Interfaces
    CFS3NA() :CFSNeutronReaction(25, 3) {}
    
};

// (n,abs), MT = 27
struct CFSAbsorption : CFSReaction {
    
    // Interfaces
    CFSAbsorption() :CFSReaction(27) {}
    
};

// (z,np), MT = 28
struct CFSNP : CFSNeutronReaction {
    
    // Interfaces
    CFSNP() :CFSNeutronReaction(28, 1) {}
    
};

// (z,n2a), MT = 29
struct CFSN2A : CFSNeutronReaction {
    
    // Interfaces
    CFSN2A() :CFSNeutronReaction(29, 1) {}
    
};

// (z,2n2a), MT = 30
struct CFS2N2A : CFSNeutronReaction {
    
    // Interfaces
    CFS2N2A() :CFSNeutronReaction(30, 2) {}
    
};

// (z,nd), MT = 32
struct CFSND : CFSNeutronReaction {
    
    // Interfaces
    CFSND() :CFSNeutronReaction(32, 1) {}
    
};

// (z,nt), MT = 33
struct CFSNT : CFSNeutronReaction {
    
    // Interfaces
    CFSNT() :CFSNeutronReaction(33, 1) {}
    
};

// (z,n3he), MT = 34
struct CFSN3HE : CFSNeutronReaction {
    
    // Interfaces
    CFSN3HE() :CFSNeutronReaction(34, 1) {}
    
};

// (z,nd2a), MT = 35
struct CFSND2A : CFSNeutronReaction {
    
    // Interfaces
    CFSND2A() :CFSNeutronReaction(34, 1) {}
    
};

// (z,nt2a), MT = 36
struct CFSNT2A : CFSNeutronReaction {
    
    // Interfaces
    CFSNT2A() :CFSNeutronReaction(36, 1) {}
    
};

// (z,4n), MT = 37
struct CFS4N : CFSNeutronReaction {
    
    // Interfaces
    CFS4N() :CFSNeutronReaction(37, 4) {}
    
};

// (n,3nf), MT = 38
struct CFS3NF : CFSPartialFissionReaction {
    
    // Interfaces
    CFS3NF() :CFSPartialFissionReaction(38, 4) {}
    
};

// (z,2np), MT = 41
struct CFS2NP : CFSNeutronReaction {
    
    // Interfaces
    CFS2NP() :CFSNeutronReaction(41, 2) {}
    
};

// (z,3np), MT = 42
struct CFS3NP : CFSNeutronReaction {
    
    // Interfaces
    CFS3NP() :CFSNeutronReaction(42, 3) {}
    
};

// (z,n2p), MT = 44
struct CFSN2P : CFSNeutronReaction {
    
    // Interfaces
    CFSN2P() :CFSNeutronReaction(44, 1) {}
    
};

// (z,npa), MT = 45
struct CFSNPA : CFSNeutronReaction {
    
    // Interfaces
    CFSNPA() :CFSNeutronReaction(45, 1) {}
    
};

// (z,ni), level scattering, MT = 50 + i
// Do not require energy distributions (File 5)
struct CFSLevel : CFSNeutronReaction {
    
    /* Additional member variables */
    long level = 0;
    
    // Interfaces
    CFSLevel(long _level)
    :level(_level), CFSNeutronReaction(50+_level, 1) {}
    
};

// (z,nc), continuum scattering, MT = 91
struct CFSContinuum : CFSNeutronReaction {
    
    // Interfaces
    CFSContinuum() :CFSNeutronReaction(91, 1) {}
    
};

// Disappear, MT = 101
struct CFSDisappear : CFSReaction {
    
    // Interfaces
    CFSDisappear() :CFSReaction(101) {}
    
};

// Total Gamma (capture), MT = 102
struct CFSCapture : CFSReaction {
    
    // Interfaces
    CFSCapture() :CFSReaction(102) {}
    
};

// Total Proton, MT = 103
struct CFSProton : CFSReaction {
    
    // Interfaces
    CFSProton() :CFSReaction(103) {}
    
};

// Total Deuteron, MT = 104
struct CFSDeuteron : CFSReaction {
    
    // Interfaces
    CFSDeuteron() :CFSReaction(104) {}
    
};

// Total Triton, MT = 105
struct CFSTriton : CFSReaction {
    
    // Interfaces
    CFSTriton() :CFSReaction(105) {}
    
};

// Total Helium3, MT = 106
struct CFSHelium3 : CFSReaction {
    
    // Interfaces
    CFSHelium3() :CFSReaction(106) {}
    
};

// Total Alpha, MT = 107
struct CFSAlpha : CFSReaction {
    
    // Interfaces
    CFSAlpha() :CFSReaction(107) {}
    
};

// (z,2a), MT = 108
struct CFS2A : CFSReaction {
    
    // Interfaces
    CFS2A() :CFSReaction(108) {}
    
};

// (z,3a), MT = 109
struct CFS3A : CFSReaction {
    
    // Interfaces
    CFS3A() :CFSReaction(109) {}
    
};

// (z,2p), MT = 111
struct CFS2P : CFSReaction {
    
    // Interfaces
    CFS2P() :CFSReaction(111) {}
    
};

// (z,pa), MT = 112
struct CFSPA : CFSReaction {
    
    // Interfaces
    CFSPA() :CFSReaction(112) {}
    
};

// (z,t2a), MT = 113
struct CFST2A : CFSReaction {
    
    // Interfaces
    CFST2A() :CFSReaction(113) {}
    
};

// (z,d2a), MT = 114
struct CFSD2A : CFSReaction {
    
    // Interfaces
    CFSD2A() :CFSReaction(114) {}
    
};

// (z,pd), MT = 115
struct CFSPD : CFSReaction {
    
    // Interfaces
    CFSPD() :CFSReaction(115) {}
    
};

// (z,pt), MT = 116
struct CFSPT : CFSReaction {
    
    // Interfaces
    CFSPT() :CFSReaction(116) {}
    
};

// (z,da), MT = 117
struct CFSDA : CFSReaction {
    
    // Interfaces
    CFSDA() :CFSReaction(117) {}
    
};

// (z,pi), proton level scattering, MT = 600 + i
struct CFSProtonLevel : CFSReaction {
    
    /* Additonal member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Interfaces
    CFSProtonLevel(long level) :CFSReaction(600+level) {}
    
    virtual ~CFSProtonLevel() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// (z,pc), proton continuum scattering, MT = 649
struct CFSProtonContinuum : CFSReaction {
    
    /* Additonal member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Interfaces
    CFSProtonContinuum() :CFSReaction(649) {}
    
    virtual ~CFSProtonContinuum() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// (z,di), deuteron level scattering, MT = 650 + i
struct CFSDeuteronLevel : CFSReaction {
    
    /* Additonal member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Interfaces
    CFSDeuteronLevel(long level) :CFSReaction(650+level) {}
    
    virtual ~CFSDeuteronLevel() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// (z,dc), deuteron continuum scattering, MT = 699
struct CFSDeuteronContinuum : CFSReaction {
    
    /* Additonal member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Interfaces
    CFSDeuteronContinuum() :CFSReaction(699) {}
    
    virtual ~CFSDeuteronContinuum() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// (z,ti), triton level scattering, MT = 700 + i
struct CFSTritonLevel : CFSReaction {
    
    /* Additonal member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Interfaces
    CFSTritonLevel(long level) :CFSReaction(700+level) {}
    
    virtual ~CFSTritonLevel() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// (z,tc), triton continuum scattering, MT = 749
struct CFSTritonContinuum : CFSReaction {
    
    /* Additonal member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Interfaces
    CFSTritonContinuum() :CFSReaction(749) {}
    
    virtual ~CFSTritonContinuum() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// (z,3hei), helium-3 level scattering, MT = 750 + i
struct CFSHelium3Level : CFSReaction {
    
    /* Additonal member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Interfaces
    CFSHelium3Level(long level) :CFSReaction(750+level) {}
    
    virtual ~CFSHelium3Level() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// (z,3hec), helium-3 continuum scattering, MT = 799
struct CFSHelium3Continuum : CFSReaction {
    
    /* Additonal member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Interfaces
    CFSHelium3Continuum() :CFSReaction(799) {}
    
    virtual ~CFSHelium3Continuum() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// (z,ai), alpha level scattering, MT = 800 + i
struct CFSAlphaLevel : CFSReaction {
    
    /* Additonal member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Interfaces
    CFSAlphaLevel(long level) :CFSReaction(800+level) {}
    
    virtual ~CFSAlphaLevel() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// (z,ac), alpha continuum scattering, MT = 849
struct CFSAlphaContinuum : CFSReaction {
    
    /* Additonal member variables */
    
    // Angular distribution
    CFSAngularDist *adist = nullptr;
    
    // Interfaces
    CFSAlphaContinuum() :CFSReaction(849) {}
    
    virtual ~CFSAlphaContinuum() {
        if (adist != nullptr) {
            delete adist;
            adist = nullptr;
        }
    }
    
    virtual bool hasAdist() const {
        return adist != nullptr;
    }
    
    virtual CFSAngularDist* getAdist() const {
        return adist;
    }
};

// The CFS neutron data is designed with the goal
// to be as convenient as possible to the need of transport.
// The data structure reflects our thinking behind
// how to make the transport calculation as intuitive as possible.
// The CFS neutron data could accomondate both ACE/ENDF neutron data.

// ENDF cross section summation rules
// 1   = 2 + 3
// 3   = 4 + 5 + 11 + 16 + 17 + 18 + sum(22-26) + sum(28-37) +
//       41 + 42 + 44 + 45 + 101
// 4   = sum(50-91)
// 18  = sum(19-21) + 38
// 27  = 18 + 101
// 101 = sum(102-117)
// 103 = sum(600-649)
// 104 = sum(650-699)
// 105 = sum(700-749)
// 106 = sum(750-799)
// 107 = sum(800-849)

// Need access control

struct CFSNeutronData {
    
    // Static public interface
    static std::set<long> supportedReactionNumbers();
    
    // Description
    std::string description;
    
    // Atomic mass ratio, relative to neutron mass
    double AWR   = 0.;
    
    // Temparature of cross sections
    double tempK = 0.;
    
    // Need a special data structure to store reactions
    
    /* Summed reactions */
    CFSTotal      *total      = nullptr; // MT = 1
    CFSNonelastic *nonelastic = nullptr; // MT = 3
    CFSInelastic  *inelastic  = nullptr; // MT = 4
    CFSAnything   *anything   = nullptr; // MT = 5
    CFSFission    *prompt     = nullptr; // MT = 18
    CFSAbsorption *absorption = nullptr; // MT = 27
    CFSDisappear  *disappear  = nullptr; // MT = 101
    CFSCapture    *capture    = nullptr; // MT = 102
    CFSProton     *proton     = nullptr; // MT = 103
    CFSDeuteron   *deuteron   = nullptr; // MT = 104
    CFSTriton     *triton     = nullptr; // MT = 105
    CFSHelium3    *helium3    = nullptr; // MT = 106
    CFSAlpha      *alpha      = nullptr; // MT = 107
    
    /* Neutron production reactions */
    CFSElastic    *elastic    = nullptr; // MT = 2
    CFS2ND        *n_2nd      = nullptr; // MT = 11
    CFS2N         *n_2n       = nullptr; // MT = 16
    CFS3N         *n_3n       = nullptr; // MT = 17
    CFSNA         *n_na       = nullptr; // MT = 22
    CFSN3A        *n_n3a      = nullptr; // MT = 23
    CFS2NA        *n_2na      = nullptr; // MT = 24
    CFS3NA        *n_3na      = nullptr; // MT = 25
    CFSNP         *n_np       = nullptr; // MT = 28
    CFSN2A        *n_n2a      = nullptr; // MT = 29
    CFS2N2A       *n_2n2a     = nullptr; // MT = 30
    CFSND         *n_nd       = nullptr; // MT = 32
    CFSNT         *n_nt       = nullptr; // MT = 33
    CFSN3HE       *n_n3he     = nullptr; // MT = 34
    CFSND2A       *n_nd2a     = nullptr; // MT = 35
    CFSNT2A       *n_nt2a     = nullptr; // MT = 36
    CFS4N         *n_4n       = nullptr; // MT = 37
    CFS2NP        *n_2np      = nullptr; // MT = 41
    CFS3NP        *n_3np      = nullptr; // MT = 42
    CFSN2P        *n_n2p      = nullptr; // MT = 44
    CFSNPA        *n_npa      = nullptr; // MT = 45
    
    // Neutron level scattering, MT = 50 .. 90, (50 not allowed)
    std::vector<CFSLevel*> levels =
    std::vector<CFSLevel*>(41, nullptr);
    
    CFSContinuum  *continuum  = nullptr; // MT = 91
    
    /* Patial fission reactions */
    CFSF          *n_f        = nullptr; // MT = 19
    CFSNF         *n_nf       = nullptr; // MT = 20
    CFS2NF        *n_2nf      = nullptr; // MT = 21
    CFS3NF        *n_3nf      = nullptr; // MT = 38
    
    /* Other none neuton production reactions */
    CFS2A         *n_2a       = nullptr; // MT = 108
    CFS3A         *n_3a       = nullptr; // MT = 109
    CFS2P         *n_2p       = nullptr; // MT = 111
    CFSPA         *n_pa       = nullptr; // MT = 112
    CFST2A        *n_t2a      = nullptr; // MT = 113
    CFSD2A        *n_d2a      = nullptr; // MT = 114
    CFSPD         *n_pd       = nullptr; // MT = 115
    CFSPT         *n_pt       = nullptr; // MT = 116
    CFSDA         *n_da       = nullptr; // MT = 117
    
    // Proton level scattering, MT = 600 .. 648
    std::vector<CFSProtonLevel*> protonLevels =
    std::vector<CFSProtonLevel*>(49, nullptr);
    
    CFSProtonContinuum  *protonContinuum  = nullptr; // MT = 649
    
    // Deuteron level scattering, MT = 650 .. 698
    std::vector<CFSDeuteronLevel*> deuteronLevels =
    std::vector<CFSDeuteronLevel*>(49, nullptr);
    
    CFSDeuteronContinuum  *deuteronContinuum  = nullptr; // MT = 699
    
    // Triton level scattering, MT = 700 .. 748
    std::vector<CFSTritonLevel*> tritonLevels =
    std::vector<CFSTritonLevel*>(49, nullptr);
    
    CFSTritonContinuum  *tritonContinuum  = nullptr; // MT = 749
    
    // Helium-3 level scattering, MT = 750 .. 798
    std::vector<CFSHelium3Level*> helium3Levels =
    std::vector<CFSHelium3Level*>(49, nullptr);
    
    CFSHelium3Continuum  *helium3Continuum  = nullptr; // MT = 799
    
    // Alpha level scattering, MT = 800 .. 848
    std::vector<CFSAlphaLevel*> alphaLevels =
    std::vector<CFSAlphaLevel*>(49, nullptr);
    
    CFSAlphaContinuum  *alphaContinuum  = nullptr; // MT = 849
    
    // Reaction Operators
    template<typename T> void deleteReaction(T *&p) {
        if (p != nullptr) {
            delete p;
            p = nullptr;
        }
    }
    
    // Perform action on neutron production reactions
    // The action will be applied on all existing
    // neutron production reactions
    void iterateNeutronReactions
    (std::function<void(const CFSNeutronReaction*)> action) const;
    
    
    
    /* Interfaces exposed to outside */
    CFSNeutronData(const ENDFNeutronData* ndata);
    CFSNeutronData(const ACENeutronData* ndata);
    ~CFSNeutronData();
    
    // Get the reaction pointer given rxn number
    // If reaction number not valid or rxn not exist, return nullptr
    const CFSReaction* getReactionByNumber(long MT) const;
    
    
    
    
    
    
    // Universal energy grid, along with key cross sections
    CFSEnergyGrid energyGrid;
    
    
    
    // Clear the allocated memory
    void clear();
    
    // Check whether valid
    bool valid() const;
    
    // Whether the material is fissionable
    bool isFissionable() const;
    
    // Obtain the total cross section
    double getTotal(double energyEv) const;
    
    // Obtain elastic scattering cross section
    double getElastic(double energyEv) const;
    
    // Obtain the disappear cross section
    double getDisappear(double energyEv) const;
    
    // Obtain the fission cross section
    double getFission(double energyEv) const;
    
    // Ontain the fission neutron yield at given energy
    double getYield(double energyEv) const;
    
    // Sample particle energy from fission
    template<typename RNG>
    double sampleFission(RNG& e) const {
        
        return 0.;
    }
    
    

};

// A special CFS class for managing neutron data
class CFS {
public:
    
    // Compare two CFS neutron data
    static bool compareNeutronData
    (CFSNeutronData* ndata1, CFSNeutronData* ndata2);
    
    
};


//}
//}


#endif /* CFS_HPP */
