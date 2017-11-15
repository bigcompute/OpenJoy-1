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

// ACE file description system

#ifndef ACE_HPP
#define ACE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "CMS.hpp"
#include "NIST.hpp"
#include "ENDF.hpp"
#include "LS.hpp"

//namespace com {
//namespace ibhe {

//Name is following the below feature
//ZZZAAA.abC continuous-energy neutron
//ZZZAAA.abD discrete-reaction neutron
//ZZZAAA.abY dosimetry
//XXXXXX.abT thermal S(alpha,beta)
//ZZZ000.abP continuous-energy photon
//ZZZ000.abM neutron multigroup
//ZZZ000.abG photon multigroup
//ZZZ000.abU photonuclear
//ZZZ000.abE continuous-energy electron
//ZZZ000.abH proton

enum class ACETableType {
    ACE_COUNTINUOUS_ENERGY_NEUTRON = 0,
    ACE_DISCRETE_REACTION_NEUTRON,
    ACE_DOSIMETRY,
    ACE_THERMAL_S_A_B,
    ACE_COUNTINUOUS_ENERGY_PHOTON,
    ACE_MULTIGROUP_NEUTRON,
    ACE_MULTIGROUP_PHOTON,
    ACE_PHOTONUCLEAR,
    ACE_COUNTINUOUS_ENERGY_ELECTRON,
    ACE_PROTON
};

constexpr const long NXSLength = 16;
constexpr const long JXSLength = 32;

// ACE table header
struct ACETableHeader {
    
    std::string namelib  = "";
    double      AWR      = 0.;
    std::string filename = "";
    std::string route    = "";
    long        filetype = 0;
    long        address  = 0;
    long        length   = 0;
    long        record   = 0;
    long        entries  = 0;
    double      tempMev  = 0.;
    bool        ptable   = false;
    
};

// ACE directory
struct ACEDirectory {
    
    // The loaded table headers
    std::vector<ACETableHeader> headers;
    
    void clear();
    
    /* Interfaces */
    bool loadFromFile(const std::string& libFilepath);
    
};

// ACE table
struct ACETable {
    
    // Meta data
    std::string name        = "";
    std::string library     = "";
    double AWR              = 0.;
    double tempMev          = 0.;
    std::string date        = "";
    std::string description = "";
    
    // Table data
    std::vector<long>   NXS = std::vector<long>(NXSLength, 0);
    std::vector<long>   JXS = std::vector<long>(JXSLength, 0);
    std::vector<double> XSS;
    
    void clear();
    bool validType() const;
    
    /* Public interfaces */
    
    // Load from file stream
    bool loadFromFile(std::istream& in, long& index);
    
    // Check whether table is empty
    bool empty() const;
    
    // Table type
    ACETableType getType() const;
    
    // Table identifier
    long getIdentifier() const;
    
    // ZZZAAA, if can't be converted to number, return 0
    long getZZZAAA() const;
    
};

/* ACE neutron data structures */

struct ACEMainRxn {
    
    // Total cross section, MT = 1
    double total      = 0.;
    
    // Elastic scattering cross section, MT = 2
    double elastic    = 0.;
    
    // Absorption cross section, MT = 27 = 18 + 101
    double absorption = 0.;
    
    // Fission cross section, MT = 18
    double fission    = 0.;
    
    // Average heating
    double heating    = 0.;
    
};

// The energy grid along with key cross sections
struct ACEEnergyGrid {
    
    // Array of energy grid
    std::vector< ENDFObjectDataPoint<ACEMainRxn> > data;
    
    // Clear
    void clear() {
        data.clear();
    }
    
    // Destructor
    ~ACEEnergyGrid() {
        clear();
    }
    
};

struct ACEXsec {
    
    // The starting index of the cross section
    // on the energy grid, start from 0
    long start = 0;
    
    // The cross section data points in barn
    std::vector<double> sigmas;
    
};

// Fundamential data structures

// Equal probability function
struct ACEEquiProbFunc {
    std::vector<double> data;
    
    void clear() {
        data.clear();
    }
};

// ACE angular distribution
struct ACEAngularDistribution {
    
    constexpr static const long EquiProbBins = 32;
    
    // Type of angular law
    enum class Law {
        ISOTROPIC = 1,
        TABULAR   = 2,
        EQUIPROB  = 3
    };
    
    Law                       law;
    ACEEquiProbFunc           equiProb;
    ENDFTabularDistribution<> tabular;
    
    void clear();
    
    bool loadACEArray
    (const std::vector<double>& XSS, long AND, long LC);
};

struct ACEAngularDist {
    
    ENDFObjectInterpolationFunction
    < ACEAngularDistribution > ergInMevFunc;
    
    bool isotropic = false;
    
    void clear();
    
    /* Public access interfaces */
    bool loadACEArray
    (const std::vector<double>& XSS, long AND, long LOCB);
    
    bool isIsotropic() const;
    
    bool valid() const;
    
};

// In ACE data library, the energy distributions
// are suitable for both neutron and photon transport
struct ACEEnergyDist {
    
    enum class Law {
        LAW1  = 1,
        LAW2  = 2,
        LAW3  = 3,
        LAW4  = 4,
        LAW5  = 5,
        LAW7  = 7,
        LAW9  = 9,
        LAW11 = 11,
        LAW22 = 22,
        LAW24 = 24,
        LAW44 = 44,
        LAW61 = 61,
        LAW66 = 66,
        LAW67 = 67
    };
    
    struct Law1Data {
        
        ENDFObjectInterpolationFunction
        < ACEEquiProbFunc > ergInMevFunc;
        
        void clear() {
            ergInMevFunc.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct Law2Data {
        
        double LP = 0.;
        double EG = 0.;
        
        void clear() {
            LP = 0.;
            EG = 0.;
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct Law3Data {
        
        double LDAT1 = 0.;
        double LDAT2 = 0.;
        
        void clear() {
            LDAT1 = 0.;
            LDAT2 = 0.;
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct Law4Data {
        
        using DiscreteInfo =
        ENDFNeutronData::EnergyAngularDist::DiscreteInfo;
        
        ENDFObjectInterpolationFunction
        < ENDFTabularDistribution
        < DiscreteInfo > > ergInMevFunc;
        
        void clear() {
            ergInMevFunc.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct Law5Data {
        
        ENDFInterpolationFunction T;
        ACEEquiProbFunc X;
        
        void clear() {
            T.clear();
            X.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    // Reuse ENDF File 5 law 7
    struct Law7Data : ENDFNeutronData::EnergyDist::Law7Data {
        
        void clear() {
            U = 0.;
            theta.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    // Reuse ENDF File 5 law 9
    struct Law9Data  : ENDFNeutronData::EnergyDist::Law9Data {
        
        void clear() {
            U = 0.;
            theta.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    // Reuse ENDF File 5 law 11
    struct Law11Data : ENDFNeutronData::EnergyDist::Law11Data {
        
        void clear() {
            U = 0.;
            a.clear();
            b.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct Law22Data {
        
        struct TabularDataPoint {
            double P = 0.;
            double T = 0.;
            double C = 0.;
        };
        
        struct ErgOutMevFunc {
            std::vector<TabularDataPoint> data;
        };
        
        ENDFObjectInterpolationFunction
        < ErgOutMevFunc > ergInMevFunc;
        
        void clear() {
            ergInMevFunc.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct Law24Data {
        
        ENDFObjectInterpolationFunction
        < ACEEquiProbFunc > ergInMevFunc;
        
        void clear() {
            ergInMevFunc.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct Law44Data {
        
        using DiscreteInfo =
        ENDFNeutronData::EnergyAngularDist::DiscreteInfo;
        
        ENDFObjectInterpolationFunction
        < ENDFObjectTabularDistribution
        < ENDFkalbachMannDistribution, DiscreteInfo > > ergInMevFunc;
        
        void clear() {
            ergInMevFunc.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct Law61Data {
        
        using DiscreteInfo =
        ENDFNeutronData::EnergyAngularDist::DiscreteInfo;
        
        ENDFObjectInterpolationFunction
        < ENDFObjectTabularDistribution
        < ACEAngularDistribution, DiscreteInfo > > ergInMevFunc;
        
        void clear() {
            ergInMevFunc.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct Law66Data {
        
        double APSX = 0.;
        long   NPSX = 0;
        
        void clear() {
            APSX = 0.;
            NPSX = 0;
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct Law67Data {
        
        ENDFObjectInterpolationFunction
        < ENDFObjectTabularDistribution
        < ENDFObjectTabularDistribution<> > > ergInMevFunc;
        
        void clear() {
            ergInMevFunc.clear();
        }
        
        bool loadACEArray
        (const std::vector<double>& XSS,
         long DLW, long AND, long IDAT);
        
    };
    
    struct PartialDist {
        
        // Law of distribution
        Law law;
        
        // Probability of validity
        ENDFInterpolationFunction ergInMevValidity;
        
        // Law data
        Law1Data  law1;
        Law2Data  law2;
        Law3Data  law3;
        Law4Data  law4;
        Law5Data  law5;
        Law7Data  law7;
        Law9Data  law9;
        Law11Data law11;
        Law22Data law22;
        Law24Data law24;
        Law44Data law44;
        Law61Data law61;
        Law66Data law66;
        Law67Data law67;
        
    };
    
    std::vector<PartialDist> partialDists;
    
    void clear();
    
    /* Public access interfaces */
    bool loadACEArray
    (const std::vector<double>& XSS,
     long DLW, long AND, long LOCC);
    
    bool valid() const;
    
};

struct ACEReaction {
    
    // The reaction MT number
    long   MT = 0;
    
    // The reaction Q value
    double Q  = 0.;
    
    // The TY number
    long   TY = 0;
    
    // Yield function
    ENDFInterpolationFunction yield;
    
    // The frame system
    ENDFSpaceSystem system;
    
    // Number of neutron emitted
    long neutrons = 0;
    
    // The cross section
    ACEXsec xsec;
    
    // Angular distribution
    ACEAngularDist adist;
    
    // Energy distribution
    ACEEnergyDist edist;
    
};


// ACE neutron data
// The ACE neutron data describes the extracted neutron data information
// The design goal is for the simplification of computation
struct ACENeutronData {
    
    // The ZA number
    long   ZA    = 0;
    
    // Atomic weight ratio
    double AWR   = 0.;
    
    // Temperature
    double tempK = 0.;
    
    // Energy grid, along with main reactions
    ACEEnergyGrid energyMevGrid;
    
    // Reactions
    std::vector<ACEReaction> reactions;
    
    // Clear data
    void clear();
    
    /* Public interfaces */
    ~ACENeutronData();
    
    // Initialize from ACE table
    bool loadACETable(const ACETable& table);
    
};

// ACE class, provide some generic information
class ACE {
protected:
    
    
public:
    
    // Get the material name from ACE ZAID
    // if not found, an empty string is returned
    static std::string getNameFromZAID(std::string ZAID);
    
    
};


//}
//}


#endif /* ACE_HPP */
