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

#include "XRS.hpp"
#include "CMS.hpp"

#include <list>

//namespace com {
//namespace ibhesd {

XRSRRFunction XRS::processResolvedResonance
(ENDFNeutronData *ndata, double tol) {
    
    // Data points
    XRSRRFunction xsec;
    
    try {
        
        // Make a local copy of data
        std::vector<XRSRRDataPoint> data;
        
        if (ndata == nullptr) {
            throw std::logic_error("neutron data not valid!");
        }
        
        if (tol <= 0.) {
            throw std::logic_error("invalid tolerance!");
        }
        
        // Using alias for simplicities
        using Xsec = ENDFNeutronData::Resonance::Xsec;
        
        // Prepare the stack for invert stack method
        std::list< std::pair<double, Xsec> > stack;
        
        // Obtain the energy ranges of resolved resonance
        auto p = ndata->getResolvedResonanceRange();
        
        if (p.first == 0. && p.second == 0.) {
            // No resonance, not consider as error
            // throw std::logic_error("no resolved resonance!");
            return xsec;
        }
        
        // Set zero threshold
        const double thres = CMS::zeroThres; // barn
        
        // Lambda function for determing the convergence
        auto converged = [&]
        (const Xsec& p1, const Xsec& p2, const Xsec& p3) -> bool {
            // Check zero threshold
            if ((fabs(p1.fission) <= thres &&
                 fabs(p2.fission) <= thres) &&
                (fabs(p1.elastic) <= thres &&
                 fabs(p2.elastic) <= thres) &&
                (fabs(p1.capture) <= thres &&
                 fabs(p2.capture) <= thres) &&
                (fabs(p1.potential) <= thres &&
                 fabs(p2.potential) <= thres) )
            {
                return true;
            }
            // Check middle point convergence
            if ((fabs(p3.fission - 0.5*(p1.fission+p2.fission))
                <= tol*fabs(p3.fission)) &&
                (fabs(p3.capture - 0.5*(p1.capture+p2.capture))
                <= tol*fabs(p3.capture)) &&
                (fabs(p3.elastic - 0.5*(p1.elastic+p2.elastic))
                 <= tol*fabs(p3.elastic)) &&
                (fabs(p3.potential - 0.5*(p1.potential+p2.potential))
                 <= tol*fabs(p3.potential)))
            {
                return true;
            }
            // Return false otherwise
            return false;
        };
        
        // Lambda function for adding to result
        auto addToResult = [&] (const std::pair<double, Xsec>& pair) {
            XRSRRDataPoint dp;
            dp.x           = pair.first;
            dp.y.elastic   = pair.second.elastic;
            dp.y.fission   = pair.second.fission;
            dp.y.capture   = pair.second.capture;
            dp.y.potential = pair.second.potential;
            data.push_back(dp);
        };
        
        // Insert the lower and upper points
        stack.push_back
        ( std::make_pair(p.first, ndata->getResolvedResonanceXsec(p.first)) );
        stack.push_back
        ( std::make_pair(p.second, ndata->getResolvedResonanceXsec(p.second)) );
        
        // Perform inverted stack methods
        decltype(stack)::iterator it, itnext;
        while (stack.size() >= 2) {
            it = stack.begin();
            itnext = std::next(it);
            double em = 0.5*(it->first + itnext->first);
            auto   xm = ndata->getResolvedResonanceXsec(em);
            if (!converged(it->second, itnext->second, xm)) {
                stack.insert(itnext, std::make_pair(em, xm));
            } else {
                addToResult(stack.front());
                stack.pop_front();
                if (data.size() % 5000 == 0) {
                    std::cout << data.size() << " data points added!"
                    << std::endl;
                }
            }
        }
        
        // Add the last data point
        addToResult(stack.front());
        stack.pop_front();
        
        // Copy to xsec
        xsec.init(data);
        
    } catch (std::exception& e) {
        std::cerr << "[XRS]: error msg - " << e.what() << std::endl;
        xsec.clear();
    }
    
    return xsec;
}

//}
//}