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

// ENDF File descripsion system

// Turn off the copy_n insecure warnings in visual studio
#ifndef _SCL_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#endif

#ifndef ENDF_HPP
#define ENDF_HPP

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <ccomplex>
#include <cmath>
#include <map>
#include <fstream>

#include "NRS.hpp"
#include "CMS.hpp"
#include "NIST.hpp"

//namespace com {
//namespace ibhe {

/* Begin of ENDF fundamental format based data structures */

enum class ENDFTapeReadState
{
    ENDF_INIT,
    ENDF_BEGIN_TAPE,
    ENDF_BEGIN_MAT,
    ENDF_BEGIN_FILE,
    ENDF_BEGIN_SECTION,
    ENDF_READ_SECTION,
    ENDF_END_SECTION,
    ENDF_END_FILE,
    ENDF_END_MAT,
    ENDF_END_TAPE,
    ENDF_FINAL
};

enum class ENDFControlRecordType
{
    ENDF_NONE,
    ENDF_TPID,
    ENDF_SEND,
    ENDF_FEND,
    ENDF_MEND,
    ENDF_TEND
};

#define ENDFLineLength   80
#define ENDFMATLength     4
#define ENDFMFLength      2
#define ENDFMTLength      3
#define ENDFNSLength      5
#define ENDFMATStart     66
#define ENDFMFStart      70
#define ENDFMTStart      72
#define ENDFNSStart      75
#define ENDFNumPerLine    6
#define ENDFNumWidth     11
#define ENDFTextWidth    66
#define ENDFZSYMAMLength 11
#define ENDFALABLength   11
#define ENDFEDATELength  11
#define ENDFAUTHLength   33
#define ENDFREFLength    21
#define ENDFDDATELength  10
#define ENDFRDATELength  10
#define ENDFENDATELength  8
#define ENDFZSYMAMStart   0
#define ENDFALABStart    11
#define ENDFEDATEStart   22
#define ENDFAUTHStart    33
#define ENDFREFStart      1
#define ENDFDDATEStart   22
#define ENDFRDATStart    33
#define ENDFENDATEStart  55

struct ENDFRecord {
    std::vector<double> nums;
    long MAT = -1;
    long MF  = -1;
    long MT  = -1;
    long NS  = -1;
};

// A very special ENDF class
class ENDF {
protected:
    
    // Additional isometric states
    static std::map<long, NISTIsotopeMetaState*> isotopems;
    
    // The map from ENDF ID to NIST isotope
    static std::map<long, NISTIsotope*> isotopes;
    
    // The map from ENDF ID to NIST element
    static std::map<long, NISTElement*> elements;
    
    // May need other cateories of additional ENDF id numbers
    
    // Whether initialized
    static bool initialized;
    
    // Generate ENDF material
    static bool generateMaterials();
    
public:
    
    // Clear the library data
    static void clear();
    
    // Get the material name from ENDF id
    // if not found, an empty string is returned
    static std::string getNameFromID(long ID);
    
    // ENDF file access functions
    static void ReadLine(std::ifstream& inFile, std::string& line);
    
    static void ScanLine
    (std::string &line, long &MAT, long &MF, long &MT, long &NS);
    
    static ENDFControlRecordType GetRecordType
    (long MAT, long MF, long MT, long NS);
    
    static std::vector<double> ScanNums(const std::string& line);
    
    static std::string LibraryName(long NLIB, long NVER, long LREL);
    
    static ENDFRecord ReadRecord(std::ifstream& inFile);
    
    static std::vector<double> ReadNNumbers
    (std::ifstream& inFile, long N);
    
};

struct ENDFHeader {
    double C1 = 0.;
    double C2 = 0.;
    double L1 = 0.;
    double L2 = 0.;
    double N1 = 0.;
    double N2 = 0.;
};

struct ENDFList {
    ENDFHeader header;
    std::vector<double> array;
};

// The ENDF interpolation law is divided into several possibilities:
// INT = 1 to 5, standard Cartesian interpolation rules
// INT = 11 to 15, method of corresponding points interpolation rules
// INT = 21 to 25, unit base interpolation rules
struct ENDFInterpLaw {
    long INT = -1;
    long NBT = -1;
    
    ENDFInterpLaw() {};
    ENDFInterpLaw(long _INT, long _NBT) :INT(_INT), NBT(_NBT) {}
};

template <typename T>
struct ENDFObjectDataPoint {
    double x = 0.;
    T y;
    
    ENDFObjectDataPoint() {}
    ENDFObjectDataPoint(double _x, T _y): x(_x), y(_y) {}
};

template <typename T>
long ENDFTabLocateIdx
(const std::vector< ENDFObjectDataPoint<T> >& data, double x) {
    long i = 0;
    long j = (long)data.size() - 1;
    // Binary search
    while ( i + 1 < j ) {
        long m = ( i + j )/2;
        
        if (x >= data[m].x) {
            i = m;
        } else {
            j = m;
        }
    }
    return i;
}

typedef ENDFObjectDataPoint<double>   ENDFDataPoint;
typedef ENDFObjectDataPoint<ENDFList> ENDFListDataPoint;

struct ENDFTab1 {
    ENDFHeader header;
    std::vector<ENDFInterpLaw> interp;
    std::vector<ENDFDataPoint> data;
    
    ENDFTab1& eliminateDuplicatedZeros();
};

typedef ENDFObjectDataPoint<ENDFTab1> ENDFTab1DataPoint;

struct ENDFTab2List {
    ENDFHeader header;
    std::vector<ENDFInterpLaw>     interp;
    std::vector<ENDFListDataPoint> data;
};

struct ENDFTab2Tab1 {
    ENDFHeader header;
    std::vector<ENDFInterpLaw>     interp;
    std::vector<ENDFTab1DataPoint> data;
};

typedef ENDFObjectDataPoint<ENDFTab2Tab1> ENDFTab2Tab1DataPoint;

struct ENDFTab2Tab2Tab1 {
    ENDFHeader header;
    std::vector<ENDFInterpLaw>         interp;
    std::vector<ENDFTab2Tab1DataPoint> data;
};

// Linear evaluation
inline bool ENDFInterpIsLinearLinear
(const std::vector< ENDFInterpLaw >& interp) {
    return interp.size() == 1 && interp.front().INT == 2;
};

inline bool ENDFInterpIsHistgram
(const std::vector< ENDFInterpLaw >& interp) {
    return interp.size() == 1 && interp.front().INT == 2;
};

/* End of ENDF fundamental format based data structures */

/* Begin of ENDF computational data structures */

// Empty struct
struct ENDFEmpty {
    void clear() {}
};

// The ENDF object interpolation function is assumed to be always valid
// We enforce a strong gurantee interface to ensure the data
// capsualation.
template <typename T, typename H = ENDFEmpty>
struct ENDFObjectInterpolationFunction {
    
protected:
    // Header information
    H _info;
    
    // Interpolation rules
    std::vector< ENDFInterpLaw > _interp;
    
    // Interpolation data
    std::vector< ENDFObjectDataPoint<T> > _data;
    
public:
    
    // Constant access function
    
    const decltype(_interp)& interp() const {
        return _interp;
    }
    
    const decltype(_data)& data() const {
        return _data;
    }
    
    const H& info() const {
        return _info;
    }
    
    const ENDFInterpLaw& interp(long i) const {
        // Exception will be thrown for out of range value
        return _interp.at(i);
    }
    
    const ENDFObjectDataPoint<T>& data(long i) const {
        // Exception will be thrown for out of range value
        return _data.at(i);
    }
    
    // Value modification access function
    H& info() {
        return _info;
    }
    
    ENDFObjectDataPoint<T>& data(long i) {
        return _data.at(i);
    }
    
    // Initialization and clear
    
    // Init from size
    bool init(long size, long INT = 2) {
        clear();
        
        // Check parameters
        if (size < 0) {
            return false;
        }
        
        _data.resize(size);
        _interp.resize(1);
        _interp.front().INT = INT;
        _interp.front().NBT = size;
        
        return true;
    }
    
    // Constant reference constructor
    bool init
    (const decltype(_data)& data, long INT = 2) {
        clear();
        
        _data = data;
        _interp.resize(1);
        _interp.front().INT = INT;
        _interp.front().NBT = _data.size();
        
        return true;
    }
    
    // Right reference constructor
    bool init
    (decltype(_data)&& data, long INT = 2) {
        clear();
        
        _data = std::move(data);
        _interp.resize(1);
        _interp.front().INT = INT;
        _interp.front().NBT = _data.size();
        
        return true;
    }
    
    // Init from interp
    bool init
    (const decltype(_interp)& interp) {
        clear();
        
        // Check parameters
        if (!interp.empty()) {
            if (std::any_of
                (interp.begin(), interp.end(),
                 [](const ENDFInterpLaw& obj){
                     return obj.NBT < 1;
                 }))
            {
                return false;
            }
            for (long i=0; i<interp.size()-1; i++) {
                if (interp[i].NBT >= interp[i+1].NBT) {
                    return false;
                }
            }
        }
        
        // Copy interp
        _interp = interp;
        
        // Allocate memory
        _data.resize(_interp.back().NBT);
        
        return true;
    }
    
    bool init
    (decltype(_interp)&& interp) {
        clear();
        
        // Check parameters
        if (!interp.empty()) {
            if (std::any_of
                (interp.begin(), interp.end(),
                 [](const ENDFInterpLaw& obj){
                     return obj.NBT < 1;
                 }))
            {
                return false;
            }
            for (long i=0; i<interp.size()-1; i++) {
                if (interp[i].NBT >= interp[i+1].NBT) {
                    return false;
                }
            }
        }
        
        // Copy interp
        _interp = std::move(interp);
        
        // Allocate memory
        _data.resize(_interp.back().NBT);
        
        return true;
    }
    
    // Init from interp and data
    bool init
    (const decltype(_interp)& interp,
     const decltype(_data)& data) {
        clear();
        
        // Check parameters
        if (!interp.empty()) {
            if (std::any_of
                (interp.begin(), interp.end(),
                 [](const ENDFInterpLaw& obj){
                     return obj.NBT < 1;
                 }))
            {
                return false;
            }
            for (long i=0; i<interp.size()-1; i++) {
                if (interp[i].NBT >= interp[i+1].NBT) {
                    return false;
                }
            }
            if (interp.back().NBT != data.size()) {
                return false;
            }
        }
        
        // Copy data
        _interp = interp;
        _data = data;
        
        return true;
    }
    
    bool init
    (decltype(_interp)&& interp,
     const decltype(_data)& data) {
        clear();
        
        // Check parameters
        if (!interp.empty()) {
            if (std::any_of
                (interp.begin(), interp.end(),
                 [](const ENDFInterpLaw& obj){
                     return obj.NBT < 1;
                 }))
            {
                return false;
            }
            for (long i=0; i<interp.size()-1; i++) {
                if (interp[i].NBT >= interp[i+1].NBT) {
                    return false;
                }
            }
            if (interp.back().NBT != data.size()) {
                return false;
            }
        }
        
        // Copy data
        _interp = std::move(interp);
        _data = data;
        
        return true;
    }
    
    bool init
    (const decltype(_interp)& interp,
     decltype(_data)&& data) {
        clear();
        
        // Check parameters
        if (!interp.empty()) {
            if (std::any_of
                (interp.begin(), interp.end(),
                 [](const ENDFInterpLaw& obj){
                     return obj.NBT < 1;
                 }))
            {
                return false;
            }
            for (long i=0; i<interp.size()-1; i++) {
                if (interp[i].NBT >= interp[i+1].NBT) {
                    return false;
                }
            }
            if (interp.back().NBT != data.size()) {
                return false;
            }
        }
        
        // Copy data
        _interp = interp;
        _data = std::move(data);
        
        return true;
    }
    
    bool init
    (decltype(_interp)&& interp,
     decltype(_data)&& data) {
        clear();
        
        // Check parameters
        if (!interp.empty()) {
            if (std::any_of
                (interp.begin(), interp.end(),
                 [](const ENDFInterpLaw& obj){
                     return obj.NBT < 1;
                 }))
            {
                return false;
            }
            for (long i=0; i<interp.size()-1; i++) {
                if (interp[i].NBT >= interp[i+1].NBT) {
                    return false;
                }
            }
            if (interp.back().NBT != data.size()) {
                return false;
            }
        }
        
        // Copy data
        _interp = std::move(interp);
        _data = std::move(data);
        
        return true;
    }
    
    void clear() {
        _interp.clear();
        _data.clear();
    }
    
    // Here are a few linearization test
    bool isHist() const {
        return ENDFInterpIsHistgram(_interp);
    }
    
    bool isLinear() const {
        return ENDFInterpIsLinearLinear(_interp);
    }
    
    // Whether valid
    bool valid() const {
        return !_interp.empty() && !_data.empty();
    }
    
    // Iterate and transform data
    void transform
    (std::function<void(ENDFObjectDataPoint<T>&)> action) {
        
        for (auto& d : _data) {
            action(d);
        }
        
    }
    
};

/* ENDF functions that evaluate to double scalar value */

struct ENDFInterpolationFunction :
ENDFObjectInterpolationFunction<double> {
    
    // Evaluate the interpolation function at point x
    double evaluate(double x) const;
    
    // Check whether a constant
    bool isConst() const {
        if (_interp.size() != 1) {
            return false;
        }
        if (_data.size() != 2) {
            return false;
        }
        if (_data[0].y != _data[1].y) {
            return false;
        }
        return true;
    }
    
    // Get const if it is, otherwise return 0.
    double getConst() const {
        if (!isConst()) {
            return 0.;
        }
        return _data[0].y;
    }
    
};

// Some widely used interpolation functions
// Could replace the ENDFTERP1 function
// No explict exception thrown, may have div. 0 exception
inline double ENDFInterpEval
(double x1, double y1, double x2, double y2, double x, long law) {
    switch (law) {
        case 1:
            return y1;
        case 2:
        {
            double y = 0., r = 0.;
            r = (x - x1) / (x2 - x1);
            y = y1 + r * (y2 - y1);
            
            return y;
        }
        case 3:
        {
            double y = 0., r = 0.;
            if (x1 <= 0. || x2 <= 0.) {
                r = (x - x1) / (x2 - x1);
                y = y1 + r * (y2 - y1);
            } else {
                r = log(x / x1) / log(x2 / x1);
                y = y1 + r * (y2 - y1);
            }
            
            return y;
        }
        case 4:
        {
            double y = 0., r = 0.;
            if (y1 <= 0. || y2 <= 0.) {
                r = (x - x1) / (x2 - x1);
                y = y1 + r * (y2 - y1);
            } else {
                r = (x - x1) / (x2 - x1);
                y = y1 * pow(y2 / y1, r);
            }
            
            return y;
        }
        case 5:
        {
            double y = 0., r = 0.;
            bool xcond = x1 <= 0. || x2 <= 0.;
            bool ycond = y1 <= 0. || y2 <= 0.;
            
            if (ycond) {
                if (xcond) {
                    r = (x - x1) / (x2 - x1);
                    y = y1 + r * (y2 - y1);
                } else {
                    r = log(x / x1) / log(x2 / x1);
                    y = y1 + r * (y2 - y1);
                }
            } else if (xcond) {
                r = (x - x1) / (x2 - x1);
                y = y1 * pow(y2 / y1, r);
            } else {
                if (x <= 0.) {
                    r = log(x / x1) / log(x2 / x1);
                    y = y1 + r * (y2 - y1);
                } else {
                    r = log(x / x1) / log(x2 / x1);
                    y = y1 * pow(y2 / y1, r);
                }
            }
            
            return y;
        }
        default:
            return 0.;
    }
    
};

struct ENDFPolynomialFunction {
    std::vector<double> coefficents;
    
    // Evaluate the polynomial function value at x
    double evaluate(double x) const;
};

struct ENDFLegendreComplexFunction {
    std::vector< std::complex<double> > coefficients;
};

/* End of ENDF functions that evaluate to double scalar value */

enum class ENDFSpaceSystem {
    LAB = 1,
    CM  = 2
};

// A brand new concept of ENDF distribution
// It is important for the integer number to be consistant with ENDF law
enum class ENDFTabularDistributionType {
    HISTGRAM      = 1,
    LINEAR_LINEAR = 2,
    LINEAR_LOG    = 4
};

// Adding funtion
inline static double ENDFTabularDistributionAddFunc
(double x1, double x2, double y1, double y2,
 ENDFTabularDistributionType type) {
    if (type == ENDFTabularDistributionType::LINEAR_LINEAR) {
        return (x2-x1)*0.5*(y1+y2);
    } else if (type == ENDFTabularDistributionType::HISTGRAM) {
        return (x2-x1)*y1;
    } else if (type == ENDFTabularDistributionType::LINEAR_LOG) {
        if (y1 == y2) {
            return (x2-x1)*0.5*(y1+y2);
        } else {
            return (x2-x1)/(log(y2 / y1))*y2;
        }
        
    } else {
        throw std::logic_error("dist. law not supported!");
    }
}

// Static check normalization function
inline static bool ENDFCheckNormalization
(const std::vector< ENDFDataPoint >& data,
 ENDFTabularDistributionType type,
 std::vector<double> cdf = std::vector<double>()) {
    
    // If data empty, set true
    if (data.empty()) {
        return true;
    }
    
    // Skip LINER_LOG
    if (type == ENDFTabularDistributionType::LINEAR_LOG) {
        std::cerr<<"Warning: LINEAR_LOG, norm. not checked!"<<std::endl;
        return  true;
    }
    
    // Get summed integral
    double integral = 0.;
    
    for (long i=0; i+1<data.size(); i++) {
        double x1 = data[i].x;
        double x2 = data[i+1].x;
        double y1 = data[i].y;
        double y2 = data[i+1].y;
        
        integral += ENDFTabularDistributionAddFunc
        (x1, x2, y1, y2, type);
        
    }
    
    if (!NRSDBLEqual(integral, 1., 1E13)) {
        return false;
    }
    
    if (cdf.size() == data.size()) {
        // Check against cdf
        
    }
    
    return true;
}

// Obtain normalization factor
inline static double ENDFNormalizationFactor
(const std::vector< ENDFDataPoint >& data,
 ENDFTabularDistributionType type) {
    
    // Get summed integral
    double integral = 0.;
    
    for (long i=0; i+1<data.size(); i++) {
        double x1 = data[i].x;
        double x2 = data[i+1].x;
        double y1 = data[i].y;
        double y2 = data[i+1].y;
        
        integral += ENDFTabularDistributionAddFunc
        (x1, x2, y1, y2, type);
        
    }
    
    return integral;
}

template <typename T = ENDFEmpty>
struct ENDFObjectTabularDistributionDataPoint {
    
    // The value
    double x   = 0.;
    
    // The probability density
    double pdf = 0.;
    
    // The cumulative probability density
    // cdf provided for simplifying interation with ACE
    double cdf = 0.;
    
    T content;
    
    // Constructors
    ENDFObjectTabularDistributionDataPoint() {};
    
    ENDFObjectTabularDistributionDataPoint
    (double _x, double _pdf, T _content = T())
    :x(_x), pdf(_pdf), content(_content) {}
    
    ENDFObjectTabularDistributionDataPoint
    (double _x, double _pdf, double _cdf, T _content = T())
    :x(_x), pdf(_pdf), cdf(_cdf), content(_content) {}
    
};

// The distribution model a map from a value to its probability
// The data are normalized to be 1.
// Function values to zero for points out of range
template <typename T = ENDFEmpty, typename H = ENDFEmpty>
struct ENDFObjectTabularDistribution {
    
protected:
    
    // Header information
    H _info;
    
    // The type of the distribution
    ENDFTabularDistributionType _type;
    
    // The distribution data
    std::vector< ENDFObjectTabularDistributionDataPoint<T> > _data;
    
    void normalize() {
        
        // Skip empty data
        if (_data.empty()) {
            return;
        }
        
        // Get summed integral
        double integral = 0.;
        
        for (long i=0; i+1<_data.size(); i++) {
            double x1 = _data[i].x;
            double x2 = _data[i+1].x;
            double y1 = _data[i].pdf;
            double y2 = _data[i+1].pdf;
            
            integral += ENDFTabularDistributionAddFunc
            (x1, x2, y1, y2, this->_type);
        }
        
        // Normalize
        for (auto& d : _data) {
            d.pdf /= integral;
        }
        
        // Set cdf
        _data.front().cdf = 0.;
        _data.back().cdf  = 1.;
        
        for (long i=1; i+1<_data.size(); i++) {
            double x1 = _data[i-1].x;
            double x2 = _data[i].x;
            double y1 = _data[i-1].pdf;
            double y2 = _data[i].pdf;
            double c1 = _data[i-1].cdf;
            
            _data[i].cdf = c1 + ENDFTabularDistributionAddFunc
            (x1, x2, y1, y2, this->_type);
        }
    }
    
    long locateIdx(double x) const {
        long i = 0;
        long j = (long)_data.size() - 1;
        // Binary search
        while ( i + 1 < j ) {
            long m = ( i + j )/2;
            
            if (x >= _data[m].x) {
                i = m;
            } else {
                j = m;
            }
        }
        return i;
    }
    
public:
    
    // a special interfaces for initialization from
    // std::vector< ENDFDataPoint >
    inline bool init
    (const std::vector< ENDFDataPoint >& data,
     ENDFTabularDistributionType type, H info = H()) {
        
        this->clear();
        
        try {
            
            // Copy data
            this->_info = info;
            this->_data.resize(data.size());
            for (long i=0; i<data.size(); i++) {
                this->_data[i].x   = data[i].x;
                this->_data[i].pdf = data[i].y;
            }
            this->_type = type;
            
            // Normalize and construct cdf
            this->normalize();
            
            
        } catch (std::exception& e) {
            std::cerr << "[ENDF]: error msg - " << e.what() << std::endl;
            // Clear memory
            this->clear();
            return false;
        }
        
        return true;
    }
    
    std::vector< ENDFDataPoint > getPFunc() const {
        
        std::vector< ENDFDataPoint > data;
        data.resize(_data.size());
        for (long i=0; i<_data.size(); i++) {
            data[i].x = _data[i].x;
            data[i].y = _data[i].pdf;
        }
        
        return data;
    }
    
    double evaluateCDF(double x) const {
        
        double y = 0.;
        
        if (x < this->_data.front().x) {
            return this->_data.front().cdf;
        }
        
        if (x >= this->_data.back().x) {
            return this->_data.back().cdf;
        }
        
        long i   = locateIdx(x);
        long law = static_cast<long>(_type);
        
        // Perform intepolation
        y = ENDFInterpEval
        (this->_data[i].x, this->_data[i].cdf,
         this->_data[i+1].x, this->_data[i+1].cdf, x, law);
        
        if (isinf(y) || isnan(y)) {
            throw std::logic_error("evaluate data error!");
        }
        
        return y;
    }
    
    // Clear function
    void clear() {
        _type = static_cast<ENDFTabularDistributionType>(0);
        _data.clear();
    }
    
    // Obtain access to info
    const H& info() const {
        return _info;
    }
    H& info() {
        return _info;
    }
    
    // Will throw out_of_range exception for invalid indices
    // Enforce strong data access
    const decltype(_data)& data() const {
        return _data;
    }
    
    const ENDFObjectTabularDistributionDataPoint<T>&
    data(long i) const {
        return _data.at(i);
    }
    
    // Can obtain and modify the customer content at index i
    const T& content(long i) const {
        return _data.at(i).content;
    }
    
    T& content(long i) {
        return _data.at(i).content;
    }
    
    // Whether valid
    bool valid() const {
        return !_data.empty();
    }
    
    decltype(_type) type() const {
        return _type;
    }
    
    // Change the value points by factor
    void changeValueByFactor(double factor) {
        for (auto& d : _data) {
            d.x *= factor;
        }
        normalize();
    }
    
};

// Scalar version
typedef ENDFObjectTabularDistributionDataPoint<>
ENDFTabularDistributionDataPoint;

template <typename H = ENDFEmpty>
struct ENDFTabularDistribution :
ENDFObjectTabularDistribution< ENDFEmpty, H > {

    // Additonal interfaces
    
};

// Kalbach-Mann distribution,
// Normalized to be 1.0 of integration
struct ENDFkalbachMannDistribution {
    
    // The factor
    double r = 0.;
    
    // The slope
    double a = 0.;
    
};

// Legendre distribution,
// Normalized to be 1.0 of integration
struct ENDFLegendreDistribution {
    
    // The coefficients starting from the first order
    std::vector<double> coefficents;
    
    // Evaluate the legendre polynomial function value at x
    double evaluate(double x) const;
    
    // Isotropic, if all coeffs. are 0.
    bool isIsotropic() const;
    
};

// Provide a concept for scaled sitribution
template <typename T, typename H = ENDFEmpty>
struct ENDFScaledDistribution {
    
    // Header info
    H info;
    
    // Normalization factor
    double f0 = 0.;
    
    // Function
    T distribution;
    
};

/* End of ENDF computational data structures */

/* Definition of ENDF neutron data */

// The design goal of this structure is the compatability
// with the data format in the ENDF data file. Another guildance
// is that no 'high level' C++ feactures such as: STL
// data structures other than vector, and no pointers.
// This is to make the conversion to materialized format
// such as XML, JSON, GOOGLE PROTOBUF easy and intuitive.
// For comptational friendly format, look for CFS module.
struct ENDFNeutronData {
    
    enum class YieldFunctionType {
        INTERPOLATION = 1,
        POLYNOMIAL    = 2
    };
    
    struct YieldFunction {
        
        // The function type
        YieldFunctionType type;
        
        // The data for interpolation function
        ENDFInterpolationFunction interpFunc;
        
        // The data for polynomial function
        ENDFPolynomialFunction polyFunc;
        
    };
    
    struct Yield {
        
        struct Precursor {
            // Decay constant, lambda
            double decayConst = 0.;
            // Decayed-group abundance, alpha
            double groupAbundance = 0.;
        };
        
        struct Precursors {
            // List of precursors
            std::vector<Precursor> precursors;
        };
        
        // Comes from FILE=8, MF=454/459
        struct FissionProduct {
            long   ZAFP = -1;
            double FPS  = 0.;
            double Y    = 0.;
            double DY   = 0.;
        };
        
        struct FissionProducts {
            std::vector<FissionProduct> fissionProducts;
        };
        
        ~Yield();
        
        /* Fission yield spectrum */
        
        // Total neutron yield function
        YieldFunction *total = nullptr;
        
        // Prompt neutron yield function
        YieldFunction *prompt = nullptr;
        
        // Delayed neutron yield function
        YieldFunction *delayed = nullptr;
        
        /* Delayed precursor family information */
        
        // Whether precursor is energy dependent
        bool isPrecursorEnergyDependent = false;
        
        // Energy independent precursors
        Precursors energyIndependentPrecursors;
        
        // Energy dependent precursors
        ENDFObjectInterpolationFunction< Precursors >
        energyDependentPrecursors;
        
        /* Fission product information */
        ENDFObjectInterpolationFunction<FissionProducts>
        independentFissionProducts;
        
        ENDFObjectInterpolationFunction<FissionProducts>
        cummulativeFissionProducts;
    };
    
    struct Reaction {
        
        // Reaction number
        long   MT = -1;
        
        // Mass-difference Q value
        double QM = 0.;
        
        // Reaction Q value from the lowest energy state
        double QI = 0.;
        
        // Complex or "breakup" reaction flag
        long   LR = -1;
        
        // ENDF interpolated function for cross sections
        // The cross section may contain special continuity
        // information
        ENDFInterpolationFunction xsec;
        
    };
    
    struct Resonance {
        
        struct BreitWigner {
            // Resonance energy, in labroratory system, in unit of eV
            double ER = 0.;
            // Absolute value of the total angular momentum
            double AJ = 0.;
            // Resonance total width evaluated at energy ER
            double GT = 0.;
            // Resonance neutron total width evaluated at energy ER
            double GN = 0.;
            // Resonance radiation width, a constant
            double GG = 0.;
            // Resonance fission, a constant
            double GF = 0.;
        };
        
        struct ReichMoore {
            // Resonance energy, in labroratory system, in unit of eV
            double ER  = 0.;
            // Absolute value of the total angular momentum
            double AJ  = 0.;
            // Resonance neutron total width evaluated at energy ER
            double GN  = 0.;
            // Radiation width, a constant
            double GG  = 0.;
            // First partial fission width, a constant
            double GFA = 0.;
            // Second partial fission width, a constant
            double GFB = 0.;
        };
        
        struct AdlerAdler {
            
            // Coefficients
            struct ResonanceCoefficients {
                double DET = 0.;
                double DWT = 0.;
                double GRT = 0.;
                double GIT = 0.;
                double DEF = 0.;
                double DWF = 0.;
                double GRF = 0.;
                double GIF = 0.;
                double DEC = 0.;
                double DWC = 0.;
                double GRC = 0.;
                double GIC = 0.;
            };
            
            // Absolute value of the total angular momentum
            double AJ  = 0.;
            
            // Resonance coefficients
            std::vector<ResonanceCoefficients> coefficients;
        };
        
        struct URRA {
            // Average level spacing for resonances with spin J
            double D    = 0.;
            // Floating point value of total angular spin
            double AJ   = 0.;
            // Number of degrees of freedom
            // in the neutron width distribution (1.0<=AMUX<=2.0)
            double AMUN = 0.;
            // Average reduced neutron width
            double GNO  = 0.;
            // Average radiation width
            double GG   = 0.;
        };
        
        struct URRB {
            // Value of angular momentum
            double L    = 0.;
            // Integer value of the number of
            // degrees of freedom for fission widths (1.0<=AMUF<=4.0)
            double MUF  = 0.;
            // Average level spacing for resonances with spin J
            double D    = 0.;
            // Floating point value of total angular spin
            double AJ   = 0.;
            // Number of degrees of freedom
            // in the neutron width distribution (1.0<=AMUX<=2.0)
            double AMUN = 0.;
            // Average reduced neutron width
            double GNO  = 0.;
            // Average radiation width
            double GG   = 0.;
            // Average fission widths
            std::vector<double> GF;
        };
        
        struct URRCRecord {
            //
            double ES  = 0.;
            //
            double D   = 0.;
            //
            double GX  = 0.;
            //
            double GNO = 0.;
            //
            double GG  = 0.;
            //
            double GF  = 0.;
        };
        
        struct URRC {
            // Floating point value of total angular spin
            double AJ   = 0.;
            // Intepolation scheme to interpolate cross sections
            long   INT  = 0.;
            // Number of DOF in competitive width distributions
            double AMUX = 0.;
            // Number of DOF in neutron width distributions
            double AMUN = 0.;
            // Number of DOF in radiation width distributions
            double AMUG = 0.;
            // Number of DOF in fission widths
            double AMUF = 0.;
            
            // The URR type C records
            std::vector<URRCRecord> records;
        };
        
        struct URRTables {
            // URR type A tables
            std::vector<URRA> atable;
            // URR type B tables
            std::vector<URRB> btable;
            // URR type C tables
            std::vector<URRC> ctable;
        };
        
        struct AngularMomentum {
            // Ratio of particle mass to mass of neutron
            double AWRI = 0.;
            // Q-value
            double QX   = 0.;
            // Value of angular momentum
            double L    = 0.;
            // Flag for whether energy range contains a competitive width
            long   LRX  = -1;
            // L-dependent scattering radius, use AP if zero (only for LRF=3)
            double APL  = 0.;
            // The resonance parameter tables for Breit-Wigner resonance
            std::vector<BreitWigner> BWTables;
            // The resonance parameter tables for Reich-Moore resonance
            std::vector<ReichMoore> RMTables;
            // The resonance parameter tables for Adler-Adler resonance
            std::vector<AdlerAdler> AATables;
            // URR type tables
            URRTables URRTables;
            
        };
        
        struct Xsec {
            // Total corss section
            // total = elastic + fission + capture
            double total     = 0.;
            // elastic scattering cross section
            double elastic   = 0.;
            // fission cross section
            double fission   = 0.;
            // capture cross section
            double capture   = 0.;
            // potential scattering cross section
            double potential = 0.;
        };
        
        struct AAParams {
            double AT1 = 0.;
            double AT2 = 0.;
            double AT3 = 0.;
            double AT4 = 0.;
            double BT1 = 0.;
            double BT2 = 0.;
            
            double AC1 = 0.;
            double AC2 = 0.;
            double AC3 = 0.;
            double AC4 = 0.;
            double BC1 = 0.;
            double BC2 = 0.;
            
            double AF1 = 0.;
            double AF2 = 0.;
            double AF3 = 0.;
            double AF4 = 0.;
            double BF1 = 0.;
            double BF2 = 0.;
        };
        
        struct Range {
            // Lower limit for an energy range
            double   EL   = 0.;
            // Upper limit for an energy range
            double   EH   = 0.;
            // Flag indicating the type of energy range
            long     LRU  = -1;
            // Flag indicating the representation form of this range
            long     LRF  = -1;
            // Flag indicating energy dependence of scattering daius
            long     NRO  = -1;
            // Flag indicating the use of two radii, the channel radius or AP
            long     NAPS = -1;
            
            /* Parameters for resolved resoance parameters (LRU=1) */
            
            // Spin of the target nucleus
            double   SPI  = 0.;
            // Scattering radius in units of 1E-12 cm
            double   AP   = 0.;
            // Energy dependent scattering radius
            ENDFInterpolationFunction APE;
            // Flag indicating whether parameters can be
            // used to compute angular distributions
            long     LAD  = -1;
            // Number of L-values used for convergence
            long     NLSC = -1;
            
            /* Parameters for Adler-Adler representation (LRU=1, LRF=4) */
            
            // Flag to indicate the kind of parameters given
            long     LI   = -1;
            // Number of sets of background constants given
            long     NX   = -1;
            // The ratio mass particle to neutron
            double   AWRI = 0.;
            
            /* AA paramters */
            AAParams aaParams;
            
            /* Table of angular moments parameters */
            std::vector<AngularMomentum> moments;
            
            
            /* Parameters for unresolved resoance parameters (LRU=2) */
            
            // The flag governing the interpretation of File 3 cross sections
            long     LSSF = -1;
            // The parameters
            std::vector<double> URRBES;
            
            
            /* Public query functions */
            
            // Evaluated cross sections at temperature 0K and energy E in eV
            // LFW is the flag controls whether average fission widths are given
            // total: total cross section
            // elastic: elastic scattering cross section
            // fission: neutron fission cross section
            // capture: neutron capture cross section
            // potential: neutron potential scattering cross section
            Xsec generate(double E, long LFW) const;
            
            // Specific function for different cases
            Xsec generateLRU1LRF1(double E) const;
            Xsec generateLRU1LRF2(double E) const;
            Xsec generateLRU1LRF3(double E) const;
            Xsec generateLRU1LRF4(double E) const;
            Xsec generateLRU2LRF1(double E, long LFW) const;
            Xsec generateLRU2LRF2(double E, long LFW) const;
        };
        
        // Z-A id of the isotope, for U-235 ZA = 92235
        // since U has 92 protos, and 235 nuclides
        long   ZAI = -1;
        // The abundance of the nuclide
        double ABN = 0.;
        // The flag indicating whether the average fission widths are given
        long   LFW = -1;
        // Resoanance ranges
        std::vector<Range> ranges;
        
    };
    
    struct AngularDist {
        
        enum class Type {
            // Purely Isotropic Angular Distributions
            ISOTROPIC = 1,
            // Legendre Polynomial Coefficients
            LEGENDRE  = 2,
            // Tabulated Probability Distributions
            TABULATED = 3,
            // Angular Distribution Over Two Energy Ranges
            MIXED     = 4
        };
        
        // Reaction number
        long MT        = -1;
        
        // Whether given in laboratory or center of mass system
        ENDFSpaceSystem system;
        
        // Type of formula
        Type type;
        
        // The two-dimensional function
        ENDFObjectInterpolationFunction
        < ENDFLegendreDistribution > legendFunc2;
        
        // The interpolation function will be
        // converted to a distribution in CFS
        // This is aviable by linearization system (LS)
        ENDFObjectInterpolationFunction
        < ENDFInterpolationFunction > interpFunc2;
        
    };
    
    struct EnergyDist {
        
        enum class Law {
            // Arbitrary Tabulated Function
            LAW1  = 1,
            // General Evaporation Spectrum
            LAW5  = 5,
            // Simple Maxwellian Fission Spectrum
            LAW7  = 7,
            // Evaporation Spectrum
            LAW9  = 9,
            // Energy-Dependent Watt Spectrum
            LAW11 = 11,
            // Energy-Dependent Fission Neutron Spectrum
            // (Madland and Nix)
            LAW12 = 12
        };
        
        // The interpolation function will be
        // converted to a distribution in CFS
        struct Law1Data {
            
            // A linearization may be required
            ENDFObjectInterpolationFunction
            < ENDFInterpolationFunction > table;
            
        };
        
        struct Law5Data {
            double U = 0.;
            ENDFInterpolationFunction theta;
            ENDFInterpolationFunction g;
        };
        
        struct Law7Data {
            double U = 0.;
            ENDFInterpolationFunction theta;
        };
        
        struct Law9Data {
            double U = 0.;
            ENDFInterpolationFunction theta;
        };
        
        struct Law11Data {
            double U = 0.;
            ENDFInterpolationFunction a;
            ENDFInterpolationFunction b;
        };
        
        struct Law12Data {
            double EFL = 0.;
            double EFH = 0.;
            ENDFInterpolationFunction TM;
        };
        
        struct PartialDist {
            
            // Law of distribution
            Law law;
            
            // Probability of validity
            ENDFInterpolationFunction validity;
            
            // Law data
            Law1Data  law1;
            Law5Data  law5;
            Law7Data  law7;
            Law9Data  law9;
            Law11Data law11;
            Law12Data law12;
            
        };
        
        // Reaction number
        long MT = -1;
        
        // Partial distributions
        std::vector<PartialDist> partialDists;
        
    };
    
    struct EnergyAngularDist {
        
        enum class Law {
            // Unknown distribution
            LAW0  = 0,
            // Continuum energy-angle distribution
            LAW1  = 1,
            // Two-body reaction angular distribution
            LAW2  = 2,
            // Isotrpic two-body distribution
            LAW3  = 3,
            // REcoil distribution of a two-body reaction
            LAW4  = 4,
            // Charged-particle elastic scattering
            LAW5  = 5,
            // N-body phase-space distribution
            LAW6  = 6,
            // Laboratory angle-energy law
            LAW7  = 7
        };
        
        // Photon lines
        struct DiscreteInfo {
            long ND = 0;
        };
        
        struct Law1Data {
            
            enum class Type {
                LEGENDRE    = 1,
                KALBACHMANN = 2,
                TABULAR     = 3
            };
            
            // Type
            Type type;
            
            // Legendre function
            ENDFObjectInterpolationFunction
            < ENDFObjectTabularDistribution
            < ENDFLegendreDistribution, DiscreteInfo > > legendreFunc2;
            
            // Kalbach-Mann function
            ENDFObjectInterpolationFunction
            < ENDFObjectTabularDistribution
            < ENDFkalbachMannDistribution, DiscreteInfo > > kalbachFunc2;
            
            // Tabular function
            ENDFObjectInterpolationFunction
            < ENDFObjectTabularDistribution
            < ENDFTabularDistribution<>, DiscreteInfo > > tabularFunc2;
            
        };
        
        struct Law2Data {
            
            enum class Type {
                LEGENDRE = 1,
                TABULAR  = 2
            };
            
            struct Distribution {
                
                // Distribution type
                Type type;
                
                // Distribution given by Legendre func. LANG = 0
                ENDFLegendreDistribution legendre;
                
                // Distribution given by Tabular func. LANG = 12/14
                ENDFTabularDistribution<> tabular;
                
            };
            
            // Probability function, possibility of the functions:
            // LANG = 0 : Legendre functionn
            // LANG = 12 : (mu, p) linear-linear tabular function
            // LANG = 14 : (mu, ln(p)) linear-log tabular function
            ENDFObjectInterpolationFunction< Distribution > probFunc;
            
        };
        
        struct Law5Data {
            
            enum class Type {
                AMPLITUDE    = 1,
                RESIDUAL     = 2,
                INTERFERENCE = 3
            };
            
            struct Param {
                
                // Type of the function
                Type type;
                
                // Data for LTP == 1
                ENDFLegendreComplexFunction  a;
                ENDFScaledDistribution
                < ENDFLegendreDistribution > b;
                
                // Data for LTP == 2
                ENDFScaledDistribution
                < ENDFLegendreDistribution > c;
                
                // Data for LTP > 2
                ENDFInterpolationFunction    p;
                
                // Implementation of more complicated interfacces
                
            };
            
            // Spin
            double SPIN = 0.;
            
            // Particle identification flag
            long   LIDP = -1;
            
            // The energy function of parameters
            ENDFObjectInterpolationFunction<Param> params;
            
        };
        
        struct Law6Data {
            double APSX = 0.;
            long   NPSX = -1;
        };
        
        struct Law7Data {
            
            ENDFObjectInterpolationFunction
            < ENDFObjectInterpolationFunction
            < ENDFInterpolationFunction > > f;
            
        };
        
        struct Product {
            
            // ZA identifier
            long   ZAP = -1;
            
            // Product mass in neutron units
            // or the energy of primary photon
            double AWP = 0.;
            
            // Product isomeric state
            // LIP = 0: ground state
            // LIP = 1: first isomeric state, etc
            long   LIP = -1;
            
            // Energy law
            Law    law;
            
            // The system of scattering
            ENDFSpaceSystem system;
            
            // Energy dependent yield
            ENDFInterpolationFunction yield;
            
            // Law data
            Law1Data law1;
            Law2Data law2;
            Law5Data law5;
            Law6Data law6;
            Law7Data law7;
        };
        
        // Reaction number
        long MT = -1;
        
        // Products
        std::vector<Product> products;
        
    };
    
    /* Key data structures for neutron data */
    
    // The ZA number
    long                         ZA    = 0;
    
    // The atomic mass ratio, relative to neutron mass
    double                       AWR   = 0.;
    
    // The temperature of the neutron data
    double                       tempK = 0.;
    
    // The fission yield information, from File 1, 8
    Yield                        fissionYield;
    
    // List of resonances information, from File 2
    std::vector<Resonance>       resonances;
    
    // List of reactions information, from File 3
    std::vector<Reaction>        reactions;
    
    // List of angular distribution data, from File 4
    std::vector<AngularDist>     angularDists;
    
    // List of energy distribution data, from File 5
    std::vector<EnergyDist>      energyDists;
    
    // List of energy-angle distribution data, from File 6
    std::vector<EnergyAngularDist> energyAngularDists;
    
    /* Public query functions */
    
    // Get the energy range of resolved resonance regions
    // The lower and upper limits are packed in
    // A C++ pair data structure:
    //  pair.first  = lower limit
    //  pair.second = upper limit
    // If no resolved resonance found, both limits are zero
    std::pair<double, double> getResolvedResonanceRange() const;
    
    // Generate the resolved resonance cross section at existing temperature
    Resonance::Xsec getResolvedResonanceXsec(double energy) const;
    
};

struct ENDFSectionHeader {
    long MT       = -1;
    long TYPEID   = -1;
    long RECORDID = -1;
    
    bool valid() {return MT != -1;}
};

struct ENDFMaterialHeader {
    long   MAT  = -1;
    long   NLIB = -1;
    long   NVER = -1;
    long   LREL = -1;
    long   NSUB = -1;
    long   NMOD = -1;
    long   LDRV = -1;
    double TEMP = 0.;
};

//}
//}

#endif /* ENDF_HPP */
