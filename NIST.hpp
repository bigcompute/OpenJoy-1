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

// NIST nuclear data system

#ifndef NIST_HPP
#define NIST_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>

//namespace com {
//namespace ibhe {

// The NIST management system will preload all nuclear physics data
// Any isotope, element, molecule, or combination of them

// Define a NIST material, which is a tree of itsself
struct NISTMaterial {
    
    enum class Type {
        ISOTOPE  = 1,
        ISOTOPEM = 2,
        ELEMENT  = 3,
        NEUTRON  = 4,
        CUSTOM   = 9
    };
    
    NISTMaterial(Type _type = Type::CUSTOM) :type(_type) {}
    virtual ~NISTMaterial() {}
    
    // The type of the material
    Type type;
    
    // A list of chilren
    std::map<NISTMaterial*, double> components;
    
    // Virtual interfaces
    // Get the symbol for the material
    virtual std::string getSymbol() const = 0;
    
    // Get the relative atomic mass
    virtual double getAtomicMass() const = 0;
    
};

// Define the element information.
// a fundamental class, contains a vector of isotopes
struct NISTElement : NISTMaterial {
    
    // Element atomic number
    long atomicNumber = 0;
    
    // Element atomic symbol
    std::string atomicSymbol;
    
    // Element standard atomic weight
    double standardAtomicWeight = 0.;
    
    // Public interfaces
    NISTElement() :NISTMaterial(Type::ELEMENT) {}
    
    virtual ~NISTElement() {}
    
    // Get the symbol for the material
    virtual std::string getSymbol() const final {
        return atomicSymbol;
    }
    
    // Get the relative atomic mass
    virtual double getAtomicMass() const final {
        return standardAtomicWeight;
    }
    
};

// Define the isotope information,
// a fundamental class
struct NISTIsotope : NISTMaterial {
    
    // A pointer to element
    NISTElement* element = nullptr;
    
    // Isotope mass number
    long massNumber = 0;
    
    // Relative atomic mass, can be zero for
    // recent discovered non-evaluated isotopes
    double relativeAtomicMass = 0.;
    
    // Isotope symbol
    std::string isotopeSymbol;
    
    // Notes
    std::string notes;
    
    // Public interface
    NISTIsotope() :NISTMaterial(Type::ISOTOPE) {}
    
    virtual ~NISTIsotope() {}
    
    // Get the symbol for the material
    virtual std::string getSymbol() const final {
        return isotopeSymbol + "-" + std::to_string(massNumber);
    }
    
    // Get the relative atomic mass
    virtual double getAtomicMass() const final {
        return relativeAtomicMass;
    }
    
};

// Define isotope metastate
struct NISTIsotopeMetaState : NISTMaterial {
    
    // A pointer to corresponding isotope
    NISTIsotope* isotope = nullptr;
    
    // Level of isotope, first metatstate has level = 1
    long level = 0;
    
    std::string postfix() const {
        if (level == 0) {
            return "";
        } else if (level == 1) {
            return "m";
        } else {
            return "m" + std::to_string(level);
        }
    };
    
    // Public interface
    NISTIsotopeMetaState() :NISTMaterial(Type::ISOTOPEM) {}
    
    virtual ~NISTIsotopeMetaState() {}
    
    // Get the symbol for the material
    virtual std::string getSymbol() const final {
        return isotope->getSymbol() + postfix();
    }
    
    // Get the relative atomic mass
    virtual double getAtomicMass() const final {
        return isotope->relativeAtomicMass;
    }
    
    
};

// A special material: neutron
struct NISTNeutron : NISTMaterial {
    
    // Relative atomic mass
    double relativeAtomicMass = 0.;
    
    // Symbol
    std::string symbol = "N";
    
    // Public interface
    NISTNeutron() :NISTMaterial(Type::NEUTRON) {}
    
    virtual ~NISTNeutron() {}
    
    // Get the symbol for the material
    virtual std::string getSymbol() const final {
        return symbol;
    }
    
    // Get the relative atomic mass
    virtual double getAtomicMass() const final {
        return relativeAtomicMass;
    }
    
};

class NIST {
protected:
    // Control metastates levels
    constexpr static const long NMetaLevels = 1;
    
    // Fundamental materials
    // Elements, the key is atomic number
    static std::map<long, NISTElement>       elements;
    
    // Isotopes
    static std::vector<NISTIsotope>          isotopes;
    
    // Isotopes metastates
    static std::vector<NISTIsotopeMetaState> isotopems;
    
    // Special: neutron
    static NISTNeutron                       neutron;
    
    // Initialized, will be set for first use
    static bool                              initialized;
    
    // Clear function
    static void clear();
    
public:
    static bool loadFromJsonData(const std::string& json);
    static NISTElement* getElement(long atomicNumber);
    static NISTIsotope* getIsotope(long atomicNumber, long massNumber);
    static NISTIsotopeMetaState* getIsotopeM
    (long atomicNumber, long massNumber, long level);
};


//}
//}

#endif /* NIST_HPP */
