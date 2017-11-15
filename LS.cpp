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

#include "LS.hpp"
#include "ENDF.hpp"

#include <iostream>
#include <list>
#include <cassert>

//namespace com {
//namespace ibhe {

ENDFInterpolationFunction LS::linearize
(const ENDFInterpolationFunction& ifunc, double tol, double zeroThres) {
    
    // Create data structure
    ENDFInterpolationFunction func;
    
    // Set zero threshold
    const double thres = zeroThres;
    
    // Lambda function for determing the convergence
    auto converged = [&]
    (double s1, double s2, double s3) -> bool {
        
        // Check zero threshold
        if (fabs(s1) <= thres && fabs(s2) <= thres) {
            return true;
        }
        
        // Check middle point convergence
        if (fabs(s3 - 0.5*(s1 + s2)) <= tol) {
            return true;
        }
        
        // Return false otherwise
        return false;
    };
    
    // Try-Catch, will capture exceptions
    try {
        
        // Provide a stack for work with
        std::list< std::pair<double, double> > stack;
        
        // Loop over all regions
        long iend = 0;
        for (long r=0; r<ifunc.interp().size(); r++) {
            auto info   = ifunc.interp(r);
            long istart = iend;
            iend        = info.NBT - 1;
            
            // Local energy stack
            std::list< std::pair<double, double> > lstack;
            
            // Lambda function
            auto int1func = [&] () {
                // Histgram interpolation
                // Loop over all energy data points
                for (long i=istart; i<=iend; i++) {
                    
                    // Get a reference to the data
                    auto& d = ifunc.data(i);
                    
                    // Check stack empty, if true add point
                    if (lstack.empty() && stack.empty()) {
                        lstack.push_back({d.x, d.y});
                        continue;
                    }
                    
                    // Check whether internal point
                    if ( (lstack.empty() && d.x == stack.back().first) ||
                        (d.x == lstack.front().first) ) {
                        
                        // Beginning boundary point
                        // Add to stack
                        lstack.push_back({d.x, d.y});
                        
                    } else if (i == iend) {
                        
                        // Ending boundary point
                        // Add to stack if not in last region
                        if (r + 1 < ifunc.interp().size()) {
                            lstack.push_back({d.x, d.y});
                        }
                        
                    } else {
                        
                        // Internal point
                        // Make a copy
                        if (lstack.empty()) {
                            lstack.push_back({d.x, stack.back().second});
                        } else {
                            lstack.push_back({d.x, lstack.back().second});
                        }
                        
                        // Add data point
                        lstack.push_back({d.x, d.y});
                    }
                    
                }
            };
            
            auto int2func = [&] () {
                
                // Linear-Linear interpolation
                // Loop over all energy data points
                for (long i=istart; i<=iend; i++) {
                    
                    // Get a reference to the data
                    auto& d = ifunc.data(i);
                    
                    // Add the data point into local statck
                    lstack.push_back({d.x, d.y});
                    
                }
                
            };
            
            auto int345func = [&] () {
                
                // More complicated interpolations
                
                // Determine the inverted stack algorithm
                // applied regions
                
                for (long i=istart; i <= iend; i++) {
                    
                    // Get a reference to the data
                    auto& d = ifunc.data(i);
                    
                    // Determine whether a region begins
                    // If ever the first point
                    if (lstack.empty() && stack.empty()) {
                        
                        // Add point to local stack
                        lstack.push_back({d.x, d.y});
                        
                        // Move to next point
                        continue;
                        
                    }
                    
                    if ((lstack.empty() && d.x == stack.back().first) ||
                        (d.x == lstack.front().first) ) {
                        
                        // Beginning boundary point
                        // Add to stack
                        lstack.push_back({d.x, d.y});
                        
                    } else {
                        
                        // An interval in-between
                        // Last data point
                        auto& pm = lstack.back();
                        
                        // Current data point
                        auto  p  = std::make_pair(d.x, d.y);
                        
                        // Additional check wether there is a jump
                        if (pm.first == p.first) {
                            
                            // Add current point into stack
                            lstack.push_back(p);
                            
                            // Move to next point
                            continue;
                        }
                        
                        // Define inverted stack
                        std::list< std::pair<double, double> > istack;
                        
                        // Add boundary points into istack
                        istack.push_back(pm);
                        istack.push_back(p);
                        
                        // Begin inverted stack loop
                        decltype(istack)::iterator it, next;
                        while (istack.size() >= 2) {
                            
                            // Initialize iterator
                            it = istack.begin();
                            next = std::next(it);
                            
                            // Obtain middle point values
                            double xmid = 0.5*(it->first + next->first);
                            auto   ymid = ENDFInterpEval
                            (it->first, it->second,
                             next->first, next->second,
                             xmid, info.INT);
                            
                            // Check ymid evaluation
                            if (std::isnan(ymid) || std::isinf(ymid)) {
                                throw std::logic_error("numeric error!");
                            }
                            
                            // Check convergence
                            if (!converged(it->second, next->second, ymid)) {
                                istack.insert
                                (next, std::make_pair(xmid, ymid));
                            } else {
                                // Do not put the sub region begining point
                                if (istack.size() > 2) {
                                    lstack.push_back(istack.front());
                                }
                                istack.pop_front();
                            }
                        }
                        
                        // Add the last data point
                        lstack.push_back(istack.front());
                        istack.pop_front();
                        
                    }
                    
                } // end for
                
            };
            
            // Take actions according to interp law
            switch (info.INT) {
                case 1:
                {
                    int1func();
                    break;
                }
                case 2:
                {
                    int2func();
                    break;
                }
                case 3:
                case 4:
                case 5:
                {
                    int345func();
                    break;
                } // end case
                    
                default:
                    throw std::logic_error("unknown interp law!");
                    break;
            }
            
            // Local stack to global stack
            for (auto& p : lstack) {
                stack.push_back(p);
            }
            
        }
        
        // Post processing:
        // 1) Make zero below thres and
        // 2) Eliminate duplicated points
        auto it = stack.begin();
        for (; it != stack.end(); ) {
            if (fabs(it->second) <= thres) {
                it->second = 0.;
            }
            if (it == stack.begin()) {
                // Need to move iterator manually
                it ++;
                continue;
            }
            auto itprev = std::prev(it);
            if (it->first == itprev->first &&
                fabs(it->second - itprev->second) < thres) {
                it = stack.erase(it);
            } else {
                it ++;
            }
        }
        
        // Add points on the stack to grid
        func.init(stack.size());
        long i = 0;
        for (auto& p : stack) {
            func.data(i).x = p.first;
            func.data(i).y = p.second;
            i ++;
        }
        
    } catch (std::exception& e) {
        std::cerr << "[LS]: error msg - " << e.what() << std::endl;
        
        // Return an empty func
        func.clear();
        return func;
    }
    
    return func;
}

//ENDFInterpolationFunction LS::linearize
//(const ENDFLegendreFunction& legend, double tol) {
//    
//    // Linerized func
//    ENDFInterpolationFunction func;
//    
//    try {
//        
//        // Prepare data container
//        std::vector<ENDFDataPoint> data;
//        
//        // Get a constant reference to func
//        auto& f = legend;
//        
//        // Test invert stack approximation
//        std::list < std::pair<double, double> > stack;
//        
//        // Insert points
//        // The zero middle point need inserted
//        {
//            long N = 1000;
//            double DX = 1./N;
//            stack.push_back({-1., f.evaluate(-1.)});
//            for (long i=0; i<N-1; i++) {
//                auto x = -1. + (i+1)*DX;
//                stack.push_back({x, f.evaluate(x)});
//            }
//            stack.push_back({0., f.evaluate(0.)});
//            for (long i=0; i<N-1; i++) {
//                auto x = 0. + (i+1)*DX;
//                stack.push_back({x, f.evaluate(x)});
//            }
//            stack.push_back({1., f.evaluate(1.)});
//        }
//        
//        // Convergece function
//        auto converged = [&]
//        (double p1, double p2, double p3) -> bool {
//            return fabs(p3 - 0.5*(p1+p2)) <= tol*p3;
//        };
//        
//        // Perform the inverted stack methods
//        while (stack.size() >= 2) {
//            auto it = stack.begin();
//            
//            // Find first not converged
//            auto itcur = std::next(it);
//            do {
////                if (itcur->first == 0.) {
////                    break;
////                }
//                double x0 = 0.5*(it->first + itcur->first);
//                auto   y0 = f.evaluate(x0);
//                if (!converged(it->second, itcur->second, y0)) {
//                    break;
//                }
//                itcur ++;
//            } while (itcur != stack.end());
//            
//            // Remove all before last
//            if (std::distance(it, itcur) >= 2) {
//                stack.erase(std::next(it), std::prev(itcur));
//            }
//            
//            assert(stack.size() >= 2);
//            
//            auto& dp = stack.front();
//            data.emplace_back(dp.first, dp.second);
//            stack.pop_front();
//        }
//        
//        auto& dp = stack.front();
//        data.emplace_back(dp.first, dp.second);
//        stack.pop_front();
//        
//        // Check whether only 2 points
//        if (data.size() == 2) {
//            data.push_back(data[1]);
//            data[1].x = 0.;
//            data[1].y = f.evaluate(0.);
//        }
//        
//        // Perform integral
//        double integral = 0.;
//        for (long i=0; i<data.size()-1; i++) {
//            auto& p1 = data[i];
//            auto& p2 = data[i+1];
//            integral += 0.5*(p1.y+p2.y)*(p2.x-p1.x);
//        }
//        
//        // Normalization is f0
//        
//        // Normalize
//        for (auto& d : data) {
//            d.y /= integral;
//        }
//        
//        // Construct function w/ right reference
//        func.init(std::move(data));
//        
//    } catch (std::exception& e) {
//        std::cerr << "[LS]: error msg - " << e.what() << std::endl;
//        
//        // Return an empty func
//        func.clear();
//        return func;
//    }
//    
//    return func;
//    
//}

ENDFTabularDistribution<> LS::linearize
(const ENDFLegendreDistribution& ldist, double tol) {
    
    // Linerized func
    ENDFTabularDistribution<> dist;
    
    try {
        
        // Prepare data container
        std::vector<ENDFDataPoint> data;
        
        // Get a constant reference to func
        auto& f = ldist;
        
        // Test invert stack approximation
        std::list < std::pair<double, double> > stack;
        
        // Insert points
        // The zero middle point need inserted
        {
            long N = 1000;
            double DX = 1./N;
            stack.push_back({-1., f.evaluate(-1.)});
            for (long i=0; i<N-1; i++) {
                auto x = -1. + (i+1)*DX;
                stack.push_back({x, f.evaluate(x)});
            }
            stack.push_back({0., f.evaluate(0.)});
            for (long i=0; i<N-1; i++) {
                auto x = 0. + (i+1)*DX;
                stack.push_back({x, f.evaluate(x)});
            }
            stack.push_back({1., f.evaluate(1.)});
        }
        
        // Convergece function
        auto converged = [&]
        (double p1, double p2, double p3) -> bool {
            return fabs(p3 - 0.5*(p1+p2)) <= tol*p3;
        };
        
        // Perform the inverted stack methods
        while (stack.size() >= 2) {
            auto it = stack.begin();
            
            // Find first not converged
            auto itcur = std::next(it);
            do {
                double x0 = 0.5*(it->first + itcur->first);
                auto   y0 = f.evaluate(x0);
                if (!converged(it->second, itcur->second, y0)) {
                    break;
                }
                itcur ++;
            } while (itcur != stack.end());
            
            // Remove all before last
            if (std::distance(it, itcur) >= 2) {
                stack.erase(std::next(it), std::prev(itcur));
            }
            
            assert(stack.size() >= 2);
            
            auto& dp = stack.front();
            data.emplace_back(dp.first, dp.second);
            stack.pop_front();
        }
        
        auto& dp = stack.front();
        data.emplace_back(dp.first, dp.second);
        stack.pop_front();
        
        // Check whether only 2 points
        // If so, insert 0.
        if (data.size() == 2) {
            data.push_back(data[1]);
            data[1].x = 0.;
            data[1].y = f.evaluate(0.);
        }
        
        // Set dist
        if (!dist.init
            (data, ENDFTabularDistributionType::LINEAR_LINEAR))
        {
            throw std::logic_error("init tab. dist. error!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[LS]: error msg - " << e.what() << std::endl;
        
        // Return an empty func
        dist.clear();
        return dist;
    }
    
    return dist;
}


//}
//}