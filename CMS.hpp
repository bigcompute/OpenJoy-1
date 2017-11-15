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

// Constants Maintanance System (CMS)

#ifndef CMS_HPP
#define CMS_HPP

#include <iostream>


//namespace com {
//namespace ibhe {

class CMS {
public:
    // Boltzmann Constants
    constexpr static const double BoltzmannMevK = 8.6173324e-11;
    constexpr static const double BoltzmannEvK  = 8.6173324e-5;
    
    // Default relative tolerance
    constexpr static const double defaultTol = 0.001;
    
    // Angular linearization tolerance
    // Legendre polynomial
    constexpr static const double angleLegLinTol = 0.001;
    // Tabular form
    constexpr static const double angleTabLinTol = 0.001;
    
    // Zero threshold
    constexpr static const double zeroThres = 1E-10;
    
    // Thermal energy
    constexpr static const double thermalEnergyEv = 2.53E-2;
    
    // Energy conversion factors
    constexpr static const double evPerMev = 1E6;
};

//}
//}

#endif /* CMS_HPP */
