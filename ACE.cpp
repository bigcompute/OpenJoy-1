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

#include "ACE.hpp"
#include "IO.hpp"
#include "NIST.hpp"

#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>
#include <regex>

//namespace com {
//namespace ibhe {

void ACEDirectory::clear() {
    headers.clear();
}

bool ACEDirectory::loadFromFile
(const std::string& libFilepath) {
    
    // Open file
    std::ifstream in(libFilepath);
    
    try {
        
        // Check file open
        if (!in.is_open()) {
            throw std::logic_error("can't open ACE dirctory!");
        }
        
        // Begin scan the lines of file
        do {
            
            // Get a line
            std::string line;
            IO::safeGetline(in, line);
            
            // Split into tokens
            auto tokens = IO::split(line);
            
            // Skip emepty line
            if (tokens.empty()) {
                continue;
            }
            
            // Fetch header
            ACETableHeader header;
            
            if (tokens.size() != 10 &&
                tokens.size() != 11) {
                //throw std::logic_error
                //("header line token size error!");
                continue;
            }
            
            header.namelib  = tokens[0];
            header.AWR      = std::stod(tokens[1]);
            header.filename = tokens[2];
            header.route    = tokens[3];
            header.filetype = std::stol(tokens[4]);
            header.address  = std::stol(tokens[5]);
            header.length   = std::stol(tokens[6]);
            header.record   = std::stol(tokens[7]);
            header.entries  = std::stol(tokens[8]);
            header.tempMev  = std::stod(tokens[9]);
            
            if (tokens.size() == 10) {
                header.ptable = false;
            } else {
                if (tokens[10] == "ptable") {
                    header.ptable = true;
                } else {
                    throw std::logic_error("\"ptable\" expected!");
                }
            }
            
            headers.push_back(header);
            
        } while (!in.eof());
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        if (in.is_open()) {
            in.close();
        }
        return false;
    }
    
    in.close();
    
    return true;
}

void ACETable::clear() {
    
    name.clear();
    library.clear();
    AWR = 0.;
    tempMev = 0.;
    date.clear();
    description.clear();
    
    NXS.clear();
    JXS.clear();
    XSS.clear();
    
    NXS.resize(NXSLength, 0);
    JXS.resize(JXSLength, 0);
}

bool ACETable::validType() const {
    
    try {
        
        getType();
        return true;
    
    } catch (std::exception& e) {
        return false;
    }
    
}

bool ACETable::empty() const {
    return XSS.empty();
}

bool ACETable::loadFromFile(std::istream& in, long& index) {
    
    // Clear data
    clear();
    
    // Begin read file, capture exceptions
    try {
        
        index = 0;
        long loc = 0;
        std::string line;
        long ITL = 0;
        
        do {
            std::getline(in, line);
            
            switch (index) {
                case 0:
                {
                    auto tokens  = IO::split(line);
                    auto namelib = tokens[0];
                    
                    std::regex pattern(R"(([\S]+)\.([\S]+))");
                    std::smatch match;
                    std::vector<std::string> parts;
                    if (std::regex_match(namelib,match,pattern)) {
                        for (auto& m : match) {
                            parts.push_back(m.str());
                        }
                        parts.erase(parts.begin());
                    }
                    if (parts.size() != 2) {
                        throw std::logic_error("name lib format error!");
                    }
                    
                    name    = parts[0];
                    library = parts[1];
                    
                    if (name.empty() || library.empty()) {
                        throw std::logic_error("name lib format error!");
                    }
                    
                    // Check table type
                    if(!validType()) {
                        throw std::logic_error("type not valid!");
                    }
                    
                    AWR     = std::stod(tokens[1]);
                    tempMev = std::stod(tokens[2]);
                    date    = tokens[3];
                    break;
                }
                case 1:
                {
                    description = line;
                    break;
                }
                case 6:
                {
                    long i = 0;
                    long value = -1;
                    std::istringstream iss(line);
                    do {
                        iss>>value;
                        if (iss.fail()) {
                            break;
                        }
                        NXS[i] = value;
                        i++;
                    } while (!iss.eof());
                    if (i != 8) {
                        throw std::logic_error("no 8 blocks!");
                    }
                    // Set ITL
                    ITL = NXS[0];
                    XSS.resize(ITL, 0.);
                    break;
                }
                case 7:
                {
                    long i = 0;
                    long value = -1;
                    std::istringstream iss(line);
                    do {
                        iss>>value;
                        if (iss.fail()) {
                            break;
                        }
                        NXS[i+8] = value;
                        i++;
                    } while (!iss.eof());
                    if (i != 8) {
                        throw std::logic_error("no 8 blocks!");
                    }
                    break;
                }
                case 8:
                {
                    long i = 0;
                    long value = -1;
                    std::istringstream iss(line);
                    do {
                        iss>>value;
                        if (iss.fail()) {
                            break;
                        }
                        JXS[i] = value;
                        i++;
                    } while (!iss.eof());
                    if (i != 8) {
                        throw std::logic_error("no 8 blocks!");
                    }
                    break;
                }
                case 9:
                {
                    long i = 0;
                    long value = -1;
                    std::istringstream iss(line);
                    do {
                        iss>>value;
                        if (iss.fail()) {
                            break;
                        }
                        JXS[i+8] = value;
                        i++;
                    } while (!iss.eof());
                    if (i != 8) {
                        throw std::logic_error("no 8 blocks!");
                    }
                    break;
                }
                case 10:
                {
                    long i = 0;
                    long value = -1;
                    std::istringstream iss(line);
                    do {
                        iss>>value;
                        if (iss.fail()) {
                            break;
                        }
                        JXS[i+16] = value;
                        i++;
                    } while (!iss.eof());
                    if (i != 8) {
                        throw std::logic_error("no 8 blocks!");
                    }
                    break;
                }
                case 11:
                {
                    long i = 0;
                    long value = -1;
                    std::istringstream iss(line);
                    do {
                        iss>>value;
                        if (iss.fail()) {
                            break;
                        }
                        JXS[i+24] = value;
                        i++;
                    } while (!iss.eof());
                    if (i != 8) {
                        throw std::logic_error("no 8 blocks!");
                    }
                    break;
                }
                default:
                    break;
            }
            
            if (index >= 12) {
                
                double value = -1;
                std::istringstream iss(line);
                do {
                    iss>>value;
                    if (iss.fail()) {
                        break;
                    }
                    XSS[loc] = value;
                    loc ++;
                } while (!iss.eof());
                
            }
            
            index ++;
            
        } while ( (index < 12 || loc < ITL)
                 && !in.bad() && !in.eof());
        
        // Consistancy check
        if (loc != ITL) {
            throw std::logic_error("entries read inconsitant!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

ACETableType ACETable::getType() const {
    
    auto identifier = library.back();
    
    switch (identifier) {
        case 'c': case 'C':
            return ACETableType::ACE_COUNTINUOUS_ENERGY_NEUTRON;
        case 'd': case 'D':
            return ACETableType::ACE_DISCRETE_REACTION_NEUTRON;
        case 'y': case 'Y':
            return ACETableType::ACE_DOSIMETRY;
        case 't': case 'T':
            return ACETableType::ACE_THERMAL_S_A_B;
        case 'p': case 'P':
            return ACETableType::ACE_COUNTINUOUS_ENERGY_PHOTON;
        case 'm': case 'M':
            return ACETableType::ACE_MULTIGROUP_NEUTRON;
        case 'g': case 'G':
            return ACETableType::ACE_MULTIGROUP_PHOTON;
        case 'u': case 'U':
            return ACETableType::ACE_PHOTONUCLEAR;
        case 'e': case 'E':
            return ACETableType::ACE_COUNTINUOUS_ENERGY_ELECTRON;
        case 'h': case 'H':
            return ACETableType::ACE_PROTON;
        default:
            throw std::logic_error("unknown ACE table type!");
    }
    
}

long ACETable::getIdentifier() const {
    
    try {
        
        if (library.empty()) {
            return 0;
        }
        auto id = library.substr(0, library.size()-1);
        
        return std::stol(id);
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        return 0;
    }
    
}

long ACETable::getZZZAAA() const {
    
    try {
        
        if (name.empty()) {
            return 0;
        }
        
        return std::stol(name);
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        return 0;
    }
    
}

// Implementations for ACEAngularDist
void ACEAngularDist::clear() {
    
    ergInMevFunc.clear();
    isotropic = false;
    
}

bool ACEAngularDist::loadACEArray
(const std::vector<double>& XSS, long AND, long LOCB) {
    
    // Try-Catch block
    try {
        
        // Clear data
        clear();
        
        // Check LOCB
        if (LOCB == 0) {
            // isotropic
            isotropic = true;
            return true;
        }
        
        // Set not general isotropic
        isotropic = false;
        
        // Calculate initial location
        long addr = (AND + LOCB - 1) - 1;
        
        // Obtain number of energy
        long NE = XSS.at(addr);
        
        // Allocate energy function
        if(!ergInMevFunc.init(NE, 2)) {
            throw std::logic_error("init interp. func. error!");
        }
        
        // Loop over energy points
        for (long i=0; i<NE; i++) {
            
            // Extract ACE data
            double E  = XSS.at(addr+1+i);
            long   LC = XSS.at(addr+1+NE+i);
            
            // Obtain reference to data
            auto& d = ergInMevFunc.data(i);
            
            // Write energy point
            d.x = E;
            
            // Write angular distribution
            if (!d.y.loadACEArray(XSS, AND, LC)) {
                throw std::logic_error("load adist mufunc error!");
            }
            
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEAngularDist::isIsotropic() const {
    return isotropic;
}

bool ACEAngularDist::valid() const {
    return isotropic || ergInMevFunc.valid();
}

//Implementation of ACEAngularDistribution
void ACEAngularDistribution::clear() {
    
    law = static_cast<Law>(0);
    equiProb.clear();
    tabular.clear();
    
}

bool ACEAngularDistribution::loadACEArray
(const std::vector<double>& XSS, long AND, long LC) {
    
    try {
        
        // Check the type of distribution
        if (LC > 0) {
            law = Law::EQUIPROB;
            
            // Calculate the address
            long addr1 = (AND + LC - 1) - 1;
            
            // Write data
            equiProb.data.resize(EquiProbBins + 1, 0.);
            for (long j=0; j<EquiProbBins + 1; j++) {
                equiProb.data[j] = XSS.at(addr1 + j);
            }
            
        } else if (LC < 0) {
            law = Law::TABULAR;
            
            // Calculate the address
            long addr1 = (AND - LC - 1) - 1;
            
            // Interpolation flag
            ENDFTabularDistributionType type;
            long JJ = XSS.at(addr1);
            if (JJ == 1) {
                type = ENDFTabularDistributionType::HISTGRAM;
            } else if (JJ == 2) {
                type = ENDFTabularDistributionType::LINEAR_LINEAR;
            } else {
                throw std::logic_error("unknown interp. flag!");
            }
            
            // Number of points
            long NP = XSS.at(addr1 + 1);
            
            // Prepare x-pdf paris
            std::vector< ENDFDataPoint > data;
            std::vector< double > cdf;
            data.resize(NP);
            cdf.resize(NP);
            for (long j=0; j<NP; j++) {
                auto& dd = data[j];
                dd.x   = XSS.at(addr1 + 2 + j);
                dd.y   = XSS.at(addr1 + 2 + NP + j);
                cdf[j] = XSS.at(addr1 + 2 + 2*NP + j);
            }
            
            // Check normalization
            if (!ENDFCheckNormalization(data, type, cdf)) {
                throw std::logic_error("given data not normalized!");
            }
            
            // Init tabular dist
            if (!tabular.init(data, type)) {
                throw std::logic_error("init tab. dist. error!");
            }
            
        } else {
            law = Law::ISOTROPIC;
            
            // Do nothing!
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
    
}

// Implementations for ACEEnergyDist
void ACEEnergyDist::clear() {
    partialDists.clear();
}

/* Public access interfaces */
bool ACEEnergyDist::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long LOCC) {
    
    // Try-Catch blocks
    try {
        
        // Perform the loop on energy law
        long LNW = 0;
        
        do {
            
            // Address
            long addr = (DLW + LOCC - 1) - 1;
            
            // Obtain location of energy law
            // If LNW = 0, no next law
            LNW = XSS.at(addr);
            
            // Obtain the law number
            long LAW  = XSS.at(addr + 1);
            
            // Obtain location of the law data
            long IDAT = XSS.at(addr + 2);
            
            // Push back the energy law
            partialDists.emplace_back();
            
            // Get reference to the partial law
            auto& plaw = partialDists.back();
            
            // Input law validity data
            long NR = XSS.at(addr + 3);
            long NE = XSS.at(addr + 3 + 2*NR + 1);
            
            // Provide interpolation rules
            std::vector< ENDFInterpLaw > interp;
            std::vector< ENDFDataPoint > data;
            
            //auto& prob = plaw.ergInMevValidity;
            if (NR == 0) {
                interp.emplace_back(2, NE);
            } else {
                interp.resize(NR);
                for (long i=0; i<NR; i++) {
                    interp[i].NBT = XSS.at(addr + 4 + i);
                    interp[i].INT = XSS.at(addr + 4 + NR + i);
                }
            }
            
            // Add energy data points
            data.resize(NE);
            for (long i=0; i<NE; i++) {
                data[i].x = XSS.at(addr + 5 + 2*NR + i);
                data[i].y = XSS.at(addr + 5 + 2*NR + NE + i);
            }
            
            // Set law
            if (!plaw.ergInMevValidity.init
                (std::move(interp), std::move(data))) {
                throw std::logic_error("init interp. func. error!");
            }
            
            // Set law, and law data
            switch (LAW) {
                case 1:
                {
                    plaw.law = Law::LAW1;
                    if (!plaw.law1.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 2:
                {
                    plaw.law = Law::LAW2;
                    if (!plaw.law2.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 3:
                {
                    plaw.law = Law::LAW3;
                    if (!plaw.law3.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 4:
                {
                    plaw.law = Law::LAW4;
                    if (!plaw.law4.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 5:
                {
                    plaw.law = Law::LAW5;
                    if (!plaw.law5.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 7:
                {
                    plaw.law = Law::LAW7;
                    if (!plaw.law7.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 9:
                {
                    plaw.law = Law::LAW9;
                    if (!plaw.law9.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 11:
                {
                    plaw.law = Law::LAW11;
                    if (!plaw.law11.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 22:
                {
                    plaw.law = Law::LAW22;
                    if (!plaw.law22.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 24:
                {
                    plaw.law = Law::LAW24;
                    if (!plaw.law24.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 44:
                {
                    plaw.law = Law::LAW44;
                    if (!plaw.law44.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 61:
                {
                    plaw.law = Law::LAW61;
                    if (!plaw.law61.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 66:
                {
                    plaw.law = Law::LAW66;
                    if (!plaw.law66.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                case 67:
                {
                    plaw.law = Law::LAW67;
                    if (!plaw.law67.loadACEArray(XSS, DLW, AND, IDAT)) {
                        throw std::logic_error("load law data error!");
                    }
                    break;
                }
                    
                default:
                    throw std::logic_error("unknown erg. law!");
                    break;
            }
            
            // Move to next law
            LOCC = LNW;
            
        } while (LNW != 0);
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::valid() const {
    return !partialDists.empty();
}

// Implementations for laws data
bool ACEEnergyDist::Law1Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
    
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Input interp data
        long NR  = XSS.at(addr);
        long NE  = XSS.at(addr + 2*NR + 1);
        long NET = XSS.at(addr + 2 + 2*NR + NE);
        
        // Load interp data
        std::vector< ENDFInterpLaw > interp;
        std::vector< ENDFObjectDataPoint<ACEEquiProbFunc> > data;
        
        if (NR == 0 || XSS.at(addr + 1 + NR) == 1) {
            interp.emplace_back(2, NE);
        } else {
            interp.resize(NR);
            for (long i=0; i<NR; i++) {
                interp[i].NBT = XSS.at(addr + 1 + i);
                interp[i].INT = XSS.at(addr + 1 + NR + i);
            }
        }
        
        // Add energy data points
        data.resize(NE);
        for (long i=0; i<NE; i++) {
            data[i].x = XSS.at(addr + 2 + 2*NR + i);
            auto& v = data[i].y.data;
            v.resize(NET, 0.);
            for (long j=0; j<NET; j++) {
                v[j] = XSS.at(addr + 3 + 2*NR + NE + NET*i + j);
            }
        }
        
        // Copy to prob
        if (!ergInMevFunc.init
            (std::move(interp), std::move(data))) {
            throw std::logic_error("init interp. func. error!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law2Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Load data
        LP = XSS.at(addr);
        EG = XSS.at(addr + 1);
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law3Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Load data
        LDAT1 = XSS.at(addr);
        LDAT2 = XSS.at(addr + 1);
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law4Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Input interp data
        long NR  = XSS.at(addr);
        long NE  = XSS.at(addr + 2*NR + 1);
        
        // Load interp data
        std::vector< ENDFInterpLaw > interp;
        
        if (NR == 0) {
            interp.emplace_back(2, NE);
        } else {
            interp.resize(NR);
            for (long i=0; i<NR; i++) {
                interp[i].NBT = XSS.at(addr + 1 + i);
                interp[i].INT = XSS.at(addr + 1 + NR + i);
            }
        }
        
        std::vector
        < ENDFObjectDataPoint
        < ENDFTabularDistribution
        < DiscreteInfo > > > data;
        
        // Add energy data points
        data.resize(NE);
        long addr1last = addr + 2 + 2*NR + 2*NE;
        for (long i=0; i<NE; i++) {
            data[i].x = XSS.at(addr + 2 + 2*NR + i);
            
            // Loacator
            long LC = XSS.at(addr + 2 + 2*NR + NE + i);
            
            // Recalculate address
            long addr1 = (DLW + LC - 1) - 1;
            
            // Check array read
            if (addr1last != addr1) {
                throw std::logic_error("law4 addr error!");
            }
            
            // Load distribution
            auto& prob1 = data[i].y;
            long INTTp = XSS.at(addr1);
            long INTT = INTTp%10;
            long ND   = INTTp/10;
            ENDFTabularDistributionType type;
            if (INTT == 1) {
                type = ENDFTabularDistributionType::HISTGRAM;
            } else if (INTT == 2) {
                type = ENDFTabularDistributionType::LINEAR_LINEAR;
            } else {
                throw std::logic_error("unknown interp!");
            }
            
            // Number of data points
            long NP = XSS.at(addr1 + 1);
            
            // Prepare x-pdf paris
            std::vector< ENDFDataPoint > data1;
            std::vector< double > cdf;
            data1.resize(NP);
            cdf.resize(NP);
            
            for (long j=0; j<NP; j++) {
                auto& d = data1[j];
                d.x    = XSS.at(addr1 + 2 + j);
                d.y    = XSS.at(addr1 + 2 + NP + j);
                cdf[j] = XSS.at(addr1 + 2 + 2*NP + j);
            }
            
            // Check normalization
            if (!ENDFCheckNormalization(data1, type, cdf)) {
                throw std::logic_error("given data not normalized!");
            }
            
            // Init tabular dist
            if (!prob1.init(data1, type)) {
                throw std::logic_error("init tab. dist. error!");
            }
            
            // Set ND
            prob1.info().ND = ND;
            
            // Update addr1last
            addr1last += 2 + 3*NP;
        }
        
        // Copy to prob
        if (!ergInMevFunc.init
            (std::move(interp), std::move(data))) {
            throw std::logic_error("init interp. func. error!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law5Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Input interp data
        long NR  = XSS.at(addr);
        long NE  = XSS.at(addr + 2*NR + 1);
        
        
        // Load interp data
        std::vector< ENDFInterpLaw > interp;
        std::vector< ENDFDataPoint > data;
        
        if (NR == 0) {
            std::cerr<<"[ACE]: warning law5 no interp law!" << std::endl;
            interp.emplace_back(2, NE);
        } else {
            interp.resize(NR);
            for (long i=0; i<NR; i++) {
                interp[i].NBT = XSS.at(addr + 1 + i);
                interp[i].INT = XSS.at(addr + 1 + NR + i);
            }
        }
        
        // Add energy data points
        data.resize(NE);
        for (long i=0; i<NE; i++) {
            data[i].x = XSS.at(addr + 2 + 2*NR + i);
            data[i].y = XSS.at(addr + 2 + 2*NR + NE + i);
        }
        
        // Copy to prob
        if (!T.init(std::move(interp), std::move(data))) {
            throw std::logic_error("init interp. func. error!");
        }
        
        // Load X function
        long NET = XSS.at(addr + 2 + 2*NR + 2*NE);
        X.data.resize(NET, 0.);
        for (long i=0; i<NET; i++) {
            X.data[i] = XSS.at(addr + 3 + 2*NR + 2*NE + i);
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law7Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Input interp data
        long NR  = XSS.at(addr);
        long NE  = XSS.at(addr + 2*NR + 1);
        
        // Load interp data
        std::vector< ENDFInterpLaw > interp;
        std::vector< ENDFDataPoint > data;
        
        // Load interp data
        if (NR == 0) {
            interp.emplace_back(2, NE);
        } else {
            interp.resize(NR);
            for (long i=0; i<NR; i++) {
                interp[i].NBT = XSS.at(addr + 1 + i);
                interp[i].INT = XSS.at(addr + 1 + NR + i);
            }
        }
        
        // Add energy data points
        data.resize(NE);
        for (long i=0; i<NE; i++) {
            data[i].x = XSS.at(addr + 2 + 2*NR + i);
            data[i].y = XSS.at(addr + 2 + 2*NR + NE + i);
        }
        
        // Copy to prob
        if (!theta.init(std::move(interp), std::move(data))) {
            throw std::logic_error("init interp. func. error!");
        }
        
        
        // Load U
        U = XSS.at(addr + 2 + 2*NR + 2*NE);
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law9Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Input interp data
        long NR  = XSS.at(addr);
        long NE  = XSS.at(addr + 2*NR + 1);
        
        // Load interp data
        std::vector< ENDFInterpLaw > interp;
        std::vector< ENDFDataPoint > data;
        
        // Load interp data
        if (NR == 0) {
            interp.emplace_back(2, NE);
        } else {
            interp.resize(NR);
            for (long i=0; i<NR; i++) {
                interp[i].NBT = XSS.at(addr + 1 + i);
                interp[i].INT = XSS.at(addr + 1 + NR + i);
            }
        }
        
        // Add energy data points
        data.resize(NE);
        for (long i=0; i<NE; i++) {
            data[i].x = XSS.at(addr + 2 + 2*NR + i);
            data[i].y = XSS.at(addr + 2 + 2*NR + NE + i);
        }
        
        // Copy to prob
        if (!theta.init(std::move(interp), std::move(data))) {
            throw std::logic_error("init interp. func. error!");
        }
        
        // Load U
        U = XSS.at(addr + 2 + 2*NR + 2*NE);
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law11Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        {
            // Input interp data
            long NR  = XSS.at(addr);
            long NE  = XSS.at(addr + 2*NR + 1);
            
            // Load interp data
            std::vector< ENDFInterpLaw > interp;
            std::vector< ENDFDataPoint > data;
            
            // Load interp data
            if (NR == 0) {
                interp.emplace_back(2, NE);
            } else {
                interp.resize(NR);
                for (long i=0; i<NR; i++) {
                    interp[i].NBT = XSS.at(addr + 1 + i);
                    interp[i].INT = XSS.at(addr + 1 + NR + i);
                }
            }
            
            // Add energy data points
            data.resize(NE);
            for (long i=0; i<NE; i++) {
                data[i].x = XSS.at(addr + 2 + 2*NR + i);
                data[i].y = XSS.at(addr + 2 + 2*NR + NE + i);
            }
            
            // Copy to prob
            if (!a.init(std::move(interp), std::move(data))) {
                throw std::logic_error("init interp. func. error!");
            }
            
            // Update addr
            addr += 2 + 2*NR + 2*NE;
        }
        
        {
            // Input interp data
            long NR  = XSS.at(addr);
            long NE  = XSS.at(addr + 2*NR + 1);
            
            // Load interp data
            std::vector< ENDFInterpLaw > interp;
            std::vector< ENDFDataPoint > data;
            
            // Load interp data
            if (NR == 0) {
                interp.emplace_back(2, NE);
            } else {
                interp.resize(NR);
                for (long i=0; i<NR; i++) {
                    interp[i].NBT = XSS.at(addr + 1 + i);
                    interp[i].INT = XSS.at(addr + 1 + NR + i);
                }
            }
            
            // Add energy data points
            data.resize(NE);
            for (long i=0; i<NE; i++) {
                data[i].x = XSS.at(addr + 2 + 2*NR + i);
                data[i].y = XSS.at(addr + 2 + 2*NR + NE + i);
            }
            
            // Copy to prob
            if (!b.init(std::move(interp), std::move(data))) {
                throw std::logic_error("init interp. func. error!");
            }
            
            // Update addr
            addr += 2 + 2*NR + 2*NE;
        }
        
        // Load U
        U = XSS.at(addr);
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law22Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Input interp data
        long NR  = XSS.at(addr);
        long NE  = XSS.at(addr + 2*NR + 1);
        
        // Load interp data
        std::vector< ENDFInterpLaw > interp;
        std::vector< ENDFObjectDataPoint<ErgOutMevFunc> > data;
        
        // Histogram assumed
        interp.emplace_back(1, NE);
        
        // Add energy data points
        data.resize(NE);
        long addr1last = addr + 2 + 2*NR + 2*NE;
        for (long i=0; i<NE; i++) {
            data[i].x = XSS.at(addr + 2 + 2*NR + i);
            
            // Loacator
            long LC = XSS.at(addr + 2 + 2*NR + NE + i);
            
            // Recalculate address
            long addr1 = (DLW + LC - 1) - 1;
            
            // Check array read
            if (addr1last != addr1) {
                throw std::logic_error("law22 addr error!");
            }
            
            // Load distribution
            auto& prob1 = data[i].y;
            long NF = XSS.at(addr1);
            prob1.data.resize(NF);
            
            for (long j=0; j<NF; j++) {
                auto& d = prob1.data[j];
                d.P = XSS.at(addr1 + 1 + j);
                d.T = XSS.at(addr1 + 1 + NF + j);
                d.C = XSS.at(addr1 + 1 + 2*NF + j);
            }
            
            // Update addr1last
            addr1last += 1 + 3*NF;
        }
        
        if (!ergInMevFunc.init(std::move(interp), std::move(data))) {
            throw std::logic_error("init interp. func. error!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law24Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Input interp data
        long NR  = XSS.at(addr);
        long NE  = XSS.at(addr + 2*NR + 1);
        long NET = XSS.at(addr + 2 + 2*NR + NE);
        
        // Load interp data
        std::vector< ENDFInterpLaw > interp;
        std::vector< ENDFObjectDataPoint<ACEEquiProbFunc> > data;
        
        // Histogram assumed
        interp.emplace_back(1, NE);
        
        // Add energy data points
        data.resize(NE);
        for (long i=0; i<NE; i++) {
            data[i].x = XSS.at(addr + 2 + 2*NR + i);
            auto& v = data[i].y.data;
            v.resize(NET, 0.);
            for (long j=0; j<NET; j++) {
                v[j] = XSS.at(addr + 3 + 2*NR + NE + NET*i + j);
            }
        }
        
        if (!ergInMevFunc.init(std::move(interp), std::move(data))) {
            throw std::logic_error("init interp. func. error!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law44Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Input interp data
        long NR  = XSS.at(addr);
        long NE  = XSS.at(addr + 2*NR + 1);
        
        // Load interp data
        std::vector< ENDFInterpLaw > interp;
        if (NR == 0) {
            interp.emplace_back(2, NE);
        } else {
            interp.resize(NR);
            for (long i=0; i<NR; i++) {
                interp[i].NBT = XSS.at(addr + 1 + i);
                interp[i].INT = XSS.at(addr + 1 + NR + i);
            }
        }
        
        std::vector
        < ENDFObjectDataPoint
        < ENDFObjectTabularDistribution
        < ENDFkalbachMannDistribution, DiscreteInfo > > > data;
        
        // Add energy data points
        data.resize(NE);
        long addr1last = addr + 2 + 2*NR + 2*NE;
        for (long i=0; i<NE; i++) {
            data[i].x = XSS.at(addr + 2 + 2*NR + i);
            
            // Loacator
            long LC = XSS.at(addr + 2 + 2*NR + NE + i);
            
            // Recalculate address
            long addr1 = (DLW + LC - 1) - 1;
            
            // Check array read
            if (addr1last != addr1) {
                throw std::logic_error("law44 addr error!");
            }
            
            // Load distribution
            auto& prob1 = data[i].y;
            long INTTp = XSS.at(addr1);
            long INTT = INTTp%10;
            long ND   = INTTp/10;
            ENDFTabularDistributionType type;
            if (INTT == 1) {
                type = ENDFTabularDistributionType::HISTGRAM;
            } else if (INTT == 2) {
                type = ENDFTabularDistributionType::LINEAR_LINEAR;
            } else {
                throw std::logic_error("unknown interp!");
            }
            
            // Number of data points
            long NP = XSS.at(addr1 + 1);
            
            // Prepare x-pdf paris
            std::vector< ENDFDataPoint > data1;
            std::vector< double > cdf;
            data1.resize(NP);
            cdf.resize(NP);
            
            for (long j=0; j<NP; j++) {
                auto& d = data1[j];
                d.x     = XSS.at(addr1 + 2 + j);
                d.y     = XSS.at(addr1 + 2 + NP + j);
                cdf[j]  = XSS.at(addr1 + 2 + 2*NP + j);
            }
            
            // Check normalization
            if (!ENDFCheckNormalization(data1, type, cdf)) {
                throw std::logic_error("given data not normalized!");
            }
            
            // Init tabular dist
            if (!prob1.init(data1, type)) {
                throw std::logic_error("init tab. dist. error!");
            }
            
            // Set ND
            prob1.info().ND = ND;
            
            for (long j=0; j<NP; j++) {
                auto& d = prob1.content(j);
                d.r     = XSS.at(addr1 + 2 + 3*NP + j);
                d.a     = XSS.at(addr1 + 2 + 4*NP + j);
            }
            
            // Update addr1last
            addr1last += 2 + 5*NP;
        }
        
        if (!ergInMevFunc.init(std::move(interp), std::move(data))) {
            throw std::logic_error("init interp. func. error!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law61Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Input interp data
        long NR  = XSS.at(addr);
        long NE  = XSS.at(addr + 2*NR + 1);
        
        // Load interp data
        std::vector< ENDFInterpLaw > interp;
        if (NR == 0) {
            interp.emplace_back(2, NE);
        } else {
            interp.resize(NR);
            for (long i=0; i<NR; i++) {
                interp[i].NBT = XSS.at(addr + 1 + i);
                interp[i].INT = XSS.at(addr + 1 + NR + i);
            }
        }
        
        std::vector
        < ENDFObjectDataPoint
        < ENDFObjectTabularDistribution
        < ACEAngularDistribution, DiscreteInfo > > > data;
        
        // Add energy data points
        data.resize(NE);
        long addr1last = addr + 2 + 2*NR + 2*NE;
        for (long i=0; i<NE; i++) {
            data[i].x = XSS.at(addr + 2 + 2*NR + i);
            
            // Loacator
            long LC = XSS.at(addr + 2 + 2*NR + NE + i);
            
            // Recalculate address
            long addr1 = (DLW + LC - 1) - 1;
            
            // Check array read
            if (addr1last != addr1) {
                throw std::logic_error("law61 addr error!");
            }
            
            // Load distribution
            auto& prob1 = data[i].y;
            long INTTp = XSS.at(addr1);
            long INTT = INTTp%10;
            long ND   = INTTp/10;
            ENDFTabularDistributionType type;
            if (INTT == 1) {
                type = ENDFTabularDistributionType::HISTGRAM;
            } else if (INTT == 2) {
                type = ENDFTabularDistributionType::LINEAR_LINEAR;
            } else {
                throw std::logic_error("unknown interp!");
            }
            
            // Number of data points
            long NP = XSS.at(addr1 + 1);
            
            // Prepare x-pdf paris
            std::vector< ENDFDataPoint > data1;
            std::vector< double > cdf;
            data1.resize(NP);
            cdf.resize(NP);
            
            for (long j=0; j<NP; j++) {
                auto& d = data1[j];
                d.x     = XSS.at(addr1 + 2 + j);
                d.y     = XSS.at(addr1 + 2 + NP + j);
                cdf[j]  = XSS.at(addr1 + 2 + 2*NP + j);
            }
            
            // Check normalization
            if (!ENDFCheckNormalization(data1, type, cdf)) {
                throw std::logic_error("given data not normalized!");
            }
            
            // Init tabular dist
            if (!prob1.init(data1, type)) {
                throw std::logic_error("init tab. dist. error!");
            }
            
            // Set ND
            prob1.info().ND = ND;
            
            for (long j=0; j<NP; j++) {
                auto& d = prob1.content(j);
                long LC = XSS.at(addr1 + 2 + 3*NP + j);
                
                // Check LC
                if (LC < 0) {
                    throw std::logic_error
                    ("law61 32 equiprob not allowed!");
                }
                
                // Load angular distribution, flip LC sign
                if (!d.loadACEArray(XSS, DLW, -LC)) {
                    throw std::logic_error("law61 load error!");
                }
                
                // Obtain read length
                long len = 0;
                if (LC > 0) {
                    long addr2 = (DLW + LC - 1) - 1;
                    long NP = XSS.at(addr2+1);
                    len = 2 + 3*NP;
                }
                addr1last += len;
            }
            
            // Update addr1last
            addr1last += 2 + 4*NP;
        }
        
        if (!ergInMevFunc.init(std::move(interp), std::move(data))) {
            throw std::logic_error("init interp. func. error!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}


bool ACEEnergyDist::Law66Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Load data
        NPSX = XSS.at(addr);
        APSX = XSS.at(addr + 1);
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

bool ACEEnergyDist::Law67Data::loadACEArray
(const std::vector<double>& XSS,
 long DLW, long AND, long IDAT) {
    
    try {
        
        // Obtain address
        long addr = (DLW + IDAT - 1) - 1;
        
        // Input interp data
        long NR  = XSS.at(addr);
        long NE  = XSS.at(addr + 2*NR + 1);
        
        // Load interp data
        std::vector< ENDFInterpLaw > interp;
        if (NR == 0) {
            interp.emplace_back(2, NE);
        } else {
            interp.resize(NR);
            for (long i=0; i<NR; i++) {
                interp[i].NBT = XSS.at(addr + 1 + i);
                interp[i].INT = XSS.at(addr + 1 + NR + i);
            }
        }
        
        std::vector
        < ENDFObjectDataPoint
        < ENDFObjectTabularDistribution
        < ENDFObjectTabularDistribution<> > > > data;
        
        // Add energy data points
        data.resize(NE);
        long addr1last = addr + 2 + 2*NR + 2*NE;
        for (long i=0; i<NE; i++) {
            data[i].x = XSS.at(addr + 2 + 2*NR + i);
            
            // Loacator
            long LC = XSS.at(addr + 2 + 2*NR + NE + i);
            
            // Recalculate address
            long addr1 = (DLW + LC - 1) - 1;
            
            // Check array read
            if (addr1last != addr1) {
                throw std::logic_error("law67 addr error!");
            }
            
            // Load distribution
            auto& prob1 = data[i].y;
            long INTMU = XSS.at(addr1);
            ENDFTabularDistributionType type;
            if (INTMU == 1) {
                type = ENDFTabularDistributionType::HISTGRAM;
            } else if (INTMU == 2) {
                type = ENDFTabularDistributionType::LINEAR_LINEAR;
            } else {
                // The issue INTMU=0 raised in an earlier ACE table (<70)
                //throw std::logic_error("law67 unknown interp!");
                std::cout<<"[ACE]: warning zero INTMU, use HIST!"<<std::endl;
                type = ENDFTabularDistributionType::HISTGRAM;
            }
            
            // Number of angular data
            long NMU = XSS.at(addr1 + 1);
            
            // Prepare x-pdf paris
            std::vector< ENDFDataPoint >               data1;
            std::vector< std::vector<ENDFDataPoint> >  data2;
            std::vector< ENDFTabularDistributionType > types;
            data1.resize(NMU);
            data2.resize(NMU);
            types.resize(NMU);
            
            // Load data
            long addr2last = addr1 + 2 + 2*NMU;
            for (long j=0; j<NMU; j++) {
                
                // pdf
                data1[j].x = XSS.at(addr1 + 2 + j);
                
                // LC
                long LC = XSS.at(addr1 + 2 + NMU + j);
                
                // Recalculate address
                long addr2 = (DLW + LC - 1) - 1;
                
                // Check array read
                if (addr2last != addr2) {
                    throw std::logic_error("law67 addr error!");
                }
                
                // Load interp
                long INTEP = XSS.at(addr2);
                ENDFTabularDistributionType type1;
                if (INTEP == 1) {
                    type1 = ENDFTabularDistributionType::HISTGRAM;
                } else if (INTEP == 2) {
                    type1 = ENDFTabularDistributionType::LINEAR_LINEAR;
                } else {
                    throw std::logic_error("law67 unknown interp!");
                }
                types[j] = type1;
                
                // Number of points
                long NPEP = XSS.at(addr2 + 1);
                
                // Data array
                auto& data3 = data2[j];
                std::vector<double> cdf3;
                data3.resize(NPEP);
                cdf3.resize(NPEP);
                for (long k=0; k<NPEP; k++) {
                    auto& d = data3[k];
                    d.x     = XSS.at(addr2 + 2 + k);
                    d.y     = XSS.at(addr2 + 2 + NPEP + k);
                    cdf3[k] = XSS.at(addr2 + 2 + 2*NPEP + k);
                }
                
                // Calculate normalization factor
                double factor = ENDFNormalizationFactor
                (data3, type1);
                
                // Normalize
                for (auto& d : data3) {
                    d.y /= factor;
                }
                
                // Set data1 normalization factor
                data1[j].y = factor;
                
                // Check normalization
                if (!ENDFCheckNormalization(data3, type1, cdf3)) {
                    throw std::logic_error("given data not normalized!");
                }
                
                // Update addr2last, addr1last
                addr2last += 2 + 3*NPEP;
                addr1last += 2 + 3*NPEP;
                
            }
            
            // Update addr1last
            addr1last += 2 + 2*NMU;
            
            // Check normalization
            if (!ENDFCheckNormalization(data1, type)) {
                throw std::logic_error("given data not normalized!");
            }
            
            // Init tabular dist
            if (!prob1.init(data1, type)) {
                throw std::logic_error("init tab. dist. error!");
            }
            
            for (long j=0; j<NMU; j++) {
             
                // Obtain prob2
                auto& prob2 = prob1.content(j);
                
                // Set prob2
                if (!prob2.init(data2[j], types[j])) {
                    throw std::logic_error("init tab. dist. error!");
                }
                
            }
        }
        
        if (!ergInMevFunc.init(std::move(interp), std::move(data))) {
            throw std::logic_error("init interp. func. error!");
        }
        
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

// Implementations for ACENeutronData
ACENeutronData::~ACENeutronData() {
    
    clear();
    
}

void ACENeutronData::clear() {
    
    AWR = 0.;
    energyMevGrid.clear();
    reactions.clear();
    
}

bool ACENeutronData::loadACETable(const ACETable& table) {
    
    // Data array reference, constant
    const auto& NXS = table.NXS;
    const auto& JXS = table.JXS;
    const auto& XSS = table.XSS;
    
    // Const marks
    const long
         ESZ   = JXS[0],  NU   = JXS[1],
         LMT   = JXS[2],  LQR  = JXS[3],
         TYR   = JXS[4],  LXS  = JXS[5],
         SIG   = JXS[6],  LAND = JXS[7],
         AND   = JXS[8],  LED  = JXS[9],
         DLW   = JXS[10], LUNR = JXS[22],
         DNU   = JXS[23], BDD  = JXS[24],
         DNEDL = JXS[25], DNED = JXS[26];
    const long
         NES   = NXS[2],  NMT  = NXS[3],
         NR    = NXS[4],  NPCR = NXS[7];
    
    // Lambda to load header info
    auto readINFO = [&]() {
        
        ZA    = table.getZZZAAA();
        AWR   = table.AWR;
        tempK = table.tempMev / CMS::BoltzmannMevK;
        
    };
    
    // Lambda to load the ACE table
    auto readESZ = [&]() {
        
        energyMevGrid.data.resize(NES);
        for (long i=0; i<NES; i++) {
            auto& d = energyMevGrid.data[i];
            d.x            = XSS.at(ESZ-1+i);
            d.y.total      = XSS.at(ESZ-1+NES+i);
            d.y.absorption = XSS.at(ESZ-1+2*NES+i);
            d.y.elastic    = XSS.at(ESZ-1+3*NES+i);
            d.y.heating    = XSS.at(ESZ-1+4*NES+i);
        }
        
    };
    
    auto readRXN = [&]() {
        
        // Resize the array of reactions
        reactions.resize(NMT + 1);
        
        // Provide data for elastic reaction
        auto& elrnx    = reactions[0];
        elrnx.MT       = 2;
        elrnx.Q        = 0.;
        elrnx.system   = ENDFSpaceSystem::CM;
        elrnx.neutrons = 1;
        
        // Skip elastic cross sections
        
        // Skip if no reactions
        if (NMT == 0) {
            return;
        }
        
        // Loop over reactions
        for (long i=0; i < NMT; i++) {
            
            // Get reference to reaction
            auto& rxn = reactions[i+1];
            rxn.MT    = XSS.at(LMT+i-1);
            rxn.Q     = XSS.at(LQR+i-1);
            rxn.TY    = XSS.at(TYR+i-1);
            
            // Get the yield
            if (labs(rxn.TY) > 100) {
                
                rxn.yield.clear();
                
                // Address
                long addr = DLW+labs(rxn.TY)-101 - 1;

                long NR = XSS[addr];
                long NE = XSS[addr+2*NR+1];
                
                // Load interp data
                std::vector< ENDFInterpLaw > interp;
                std::vector< ENDFDataPoint > data;
                
                // Load interp data
                if (NR == 0) {
                    interp.emplace_back(2, NE);
                } else {
                    interp.resize(NR);
                    for (long i=0; i<NR; i++) {
                        interp[i].NBT = XSS.at(addr + 1 + i);
                        interp[i].INT = XSS.at(addr + 1 + NR + i);
                    }
                }
                
                // Add energy data points
                data.resize(NE);
                for (long i=0; i<NE; i++) {
                    data[i].x = XSS.at(addr + 2 + 2*NR + i);
                    data[i].y = XSS.at(addr + 2 + 2*NR + NE +i);
                }
                
                if (!rxn.yield.init(std::move(interp), std::move(data))) {
                    throw std::logic_error("init interp. func. error!");
                }
                
            }
            
            // Load cross sections
            long LOCA = XSS.at(LXS+i-1);
            long IE   = XSS.at(SIG+LOCA-2);
            long NE   = XSS.at(SIG+LOCA-1);
            rxn.xsec.start = IE - 1;
            rxn.xsec.sigmas.resize(NE, 0.);
            for (long n=0; n<NE; n++) {
                rxn.xsec.sigmas[n] = XSS.at(SIG+LOCA+n);
            }
            
        }
        
        // Add angular distributions
        for (long i = 0; i < NR + 1; i++) {
            
            // The locator
            long LOCB = XSS.at(LAND + i - 1);
            
            // The reference to reaction
            auto& rxn = reactions[i];
            
            // Skip, angular dist is put in edist law 44
            if (LOCB == -1) {
                continue;
            }
            
            // Load data
            if(!rxn.adist.loadACEArray(XSS, AND, LOCB)) {
                throw std::logic_error("load adist error!");
            }
            
        }
        
        // Add energy distributions
        for (long i = 0; i < NR; i++) {
            
            // The locator
            long LOCC = XSS.at(LED + i - 1);
            
            // The reference to reaction
            auto& rxn = reactions[i + 1];
            
            // Check LOCC
            if (LOCC == -1) {
                std::cout<<"[ACE]: warning LOCC = -1!";
            }
            
            // Load energy dist
            if (!rxn.edist.loadACEArray(XSS, DLW, AND, LOCC)) {
                throw std::logic_error("load edist error!");
            }
            
        }
        
    };
    
    try {
        
        // Clear data
        clear();
        
        // Check whether table is empty
        if (table.empty()) {
            throw std::logic_error("ACE table is empty!");
        }
        
        // Check table type
        if(table.getType() !=
           ACETableType::ACE_COUNTINUOUS_ENERGY_NEUTRON) {
            throw std::logic_error("not continuous neutron table!");
        }
        
        // Load header info
        readINFO();
        
        // Load ESZ block
        readESZ();
        
        // Load reactions
        readRXN();
        
        
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

// Implementation of ACE data class
std::string ACE::getNameFromZAID(std::string ZAID) {
    
    try {
        
        // Obtain the integer identifier
        long I = std::stol(ZAID);
        
        // Obtain the Z, A numbers
        long Z = I / 1000;
        long A = I % 1000;
        
        // Check element
        if (A == 0) {
            auto el = NIST::getElement(Z);
            return el->getSymbol();
        }
        // Check isotope metastate
        else if (A > 400) {
            auto ism = NIST::getIsotopeM(Z, A-400, 1);
            return ism->getSymbol();
        }
        // Check isotope
        else {
            auto is = NIST::getIsotope(Z, A);
            return is->getSymbol();
        }
        
        
    } catch (std::exception& e) {
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        return ZAID;
    }
    
    return ZAID;
}


//}
//}