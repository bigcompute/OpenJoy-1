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

#ifndef XRS_HPP
#define XRS_HPP

#include <iostream>

#include "ENDF.hpp"
#include "CMS.hpp"
#include "LS.hpp"

//namespace com {
//namespace ibhe {


struct XRSRRXsec {
    
    // Elastic scattering cross section, (MT = 2)
    double elastic   = 0.;
    
    // Fission cross section, (MT = 18)
    double fission   = 0.;
    
    // Capture cross section, (MT = 102)
    double capture   = 0.;
    
    // Potential scattering cross section
    double potential = 0.;
    
};

typedef ENDFObjectDataPoint<XRSRRXsec> XRSRRDataPoint;
typedef ENDFObjectInterpolationFunction<XRSRRXsec>  XRSRRFunction;

class XRS {
public:
    static XRSRRFunction processResolvedResonance
    (ENDFNeutronData* ndata, double tol);
    
};



//}
//}

#endif /* XRS_HPP */
