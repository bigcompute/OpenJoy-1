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

// The linearization system (LS)

#ifndef LS_HPP
#define LS_HPP

#include <iostream>
#include <vector>

#include "ENDF.hpp"

//namespace com {
//namespace ibhe {

class LS {
public:
    
    static ENDFInterpolationFunction linearize
    (const ENDFInterpolationFunction& ifunc,
     double tol, double zeroThres);
    
    // Need try one's best to eliminate negative value
    // During the evaluation of legendre polynomial,
    // one could assign 1E-10 to any value less than this
    // This gives satisfactory results
//    static ENDFInterpolationFunction linearize
//    (const ENDFLegendreFunction& lfunc, double tol);
    
    static ENDFTabularDistribution<> linearize
    (const ENDFLegendreDistribution& ldist, double tol);
    
};


//}
//}


#endif /* LS_HPP */
