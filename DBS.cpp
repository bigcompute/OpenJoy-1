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

#include "DBS.hpp"
#include "CMS.hpp"
#include "ENDF.hpp"

#include <iostream>
#include <cmath>
#include <exception>
#include <vector>

// Define constants
static const double sqrtPiInv = 1.0/sqrt(M_PI);

static double exponentialThreshold = 4.0;

struct FFunc {
    double zero  = 0.;
    double one   = 0.;
    double two   = 0.;
    double three = 0.;
    double four  = 0.;
};

// Define an operator
inline static FFunc operator-(const FFunc& f, const FFunc& g) {
    FFunc fmg;
    
    fmg.zero  = f.zero  - g.zero;
    fmg.one   = f.one   - g.one;
    fmg.two   = f.two   - g.two;
    fmg.three = f.three - g.three;
    fmg.four  = f.four  - g.four;
    
    return fmg;
};

inline static FFunc CalculateF(double a) {
    FFunc f;
    
    f.zero  = 0.5*erfc(a);
    f.one   = 0.5*sqrtPiInv*exp(-a*a);
    f.two   = 0.5*f.zero + a*f.one;
    f.three = f.one*(1.0 + a*a);
    f.four  = 0.75*f.zero + f.one*a*(1.5 + a*a);
    
    return f;
}

void DBS::proceedWithSigma1
(ENDFInterpolationFunction& xsec, double AWR, double tempK) {
    
    if (!xsec.isLinear()) {
        throw std::logic_error("xsec func is not linear!");
    }
    
    // Check inputs
    if (AWR <= 0.) {
        throw std::logic_error("mass ratio must be positive!");
    }
    if (tempK < 0.) {
        throw std::logic_error("temperature difference must be non-negative!");
    }
    
    // Do nothing for zero temperature difference
    if (tempK == 0.) {
        return;
    }
    
    // Do nothing for empty cross section points
    long N = xsec.data().size();
    if (N == 0) {
        return;
    }
    
    // Define the sqrt(M/mkT) parameter
    double factor = sqrt(AWR / CMS::BoltzmannEvK / tempK);
    
    // Construct "cold" x values, and cross section
    std::vector<double> xvec(N, 0.), xsvec(N, 0.);
    std::transform
    (xsec.data().begin(), xsec.data().end(), xvec.begin(),
     [factor](const ENDFDataPoint& dp) -> double {
         return sqrt(factor * dp.x);
     });
    std::transform
    (xsec.data().begin(), xsec.data().end(), xsvec.begin(),
     [factor](const ENDFDataPoint& dp) -> double {
         return dp.y;
     });
    
    // Loop over all energy point
    for (long i=0; i<N; i++) {
        
        // Doppler broadened cross section
        double sigma = 0.;
        
        // The y value, and related constants
        double y      = xvec[i];
        double ySq    = y*y;
        double yInv   = 1./y;
        double yInvSq = yInv/y;
        
        // Perform calculations
        
        // Evaluate first term from x[k] - y = 0 to - (exponential thres.)
        {
        long   k  = i;
        double a  = 0.;
        auto   Fa = CalculateF(a);
        
        for (; k>0; k--) {
            
            // Check evaluate limits
            if (a < -exponentialThreshold) break;
            
            // The point next
            auto Fb = Fa;
            a       = xvec[k-1] - y;
            
            // Calculate F function and H function
            Fa      = CalculateF(a);
            auto H  = Fa - Fb;
            
            // Calcuate Ak, Bk and slope terms
            auto Ak = yInvSq*H.two  + 2.0*yInv*H.one   + H.zero;
            auto Bk = yInvSq*H.four + 4.0*yInv*H.three + 6.0*H.two +
                      4.0*y*H.one + ySq*H.zero;
            auto slope = (xsvec[k] - xsvec[k-1]) /
            (xvec[k]*xvec[k] - xvec[k-1]*xvec[k-1]);
            
            // Add contribution to broadened cross section
            sigma += Ak*(xvec[k-1] - slope*xvec[k-1]*xvec[k-1]) + slope*Bk;
            
        }
        
        // Extend cross section to 0 assuming 1/v
        if (k == 0 && a >= -exponentialThreshold) {
            
            // Extended point
            auto Fb = Fa;
            a       = -y;
            
            // Calculate F and H function
            Fa      = CalculateF(a);
            auto H  = Fa - Fb;
            
            // Add constribution to broadened cross section
            sigma += xsvec[0]*xvec[0]*(yInvSq*H.one + yInv*H.zero);
            
        }
        }
        
        // Evaluate first term from x[k] - y = 0 to (exponential thres.)
        {
        long   k  = i;
        double b  = 0.;
        auto   Fb = CalculateF(b);
        
        for (; k<N-1; k++) {
            
            // Check evaluate limits
            if (b > exponentialThreshold) break;
            
            // The point next
            auto Fa = Fb;
            b       = xvec[k+1] - y;
            
            // Calculate F and H functions
            Fb      = CalculateF(b);
            auto H  = Fa - Fb;
            
            // Calculate Ak, Bk and slope terms
            auto Ak = yInvSq*H.two  + 2.0*yInv*H.one   + H.zero;
            auto Bk = yInvSq*H.four + 4.0*yInv*H.three + 6.0*H.two +
                      4.0*y*H.one + ySq*H.zero;
            auto slope = (xsvec[k+1] - xsvec[k]) /
            (xvec[k+1]*xvec[k+1] - xvec[k]*xvec[k]);
            
            // Add contribution to the broadedn cross section
            sigma += Ak*(xsvec[k+1] - slope*xvec[k+1]*xvec[k+1]) + slope*Bk;
            
        }
        
        // Extend cross section to infinity assuming constant shape
        if (k == N-1 && b <= exponentialThreshold) {
            
            // Calculate F function at last energy point
            auto a  = xvec[N-1] - y;
            auto Fa = CalculateF(a);
            
            // Add contribution to broadened cross section
            sigma += xsvec[N-1]*(yInvSq*Fa.two + 2.0*yInv*Fa.one + Fa.zero);
            
        }
        }
        
        // Evaluate second term from 0 to (exponential thres.)
        // Check whether y already exceeds the exponential limit
        if (y >= exponentialThreshold) {
            continue;
        }
        
        // Change sign of y and yinv
        y       = -y;
        yInv    = - yInv;
        
        // Extend cross section to 0 assuming 1/v
        auto b  = xvec[0] - y;
        auto Fb = CalculateF(b);
        
        {
            // Calculate F and H functions
            auto a  = -y;
            auto Fa = CalculateF(a);
            auto H  = Fa - Fb;
            
            // Add contribution to broadened cross section
            sigma += - xsvec[0]*xvec[0]*(yInvSq*H.one + yInv*H.zero);
        }
        
        // The summed terms in the second integrals
        for (long k=0; k<N-1; k++) {
            
            // The point next
            auto Fa = Fb;
            b       = xvec[k+1] - y;
            
            // Calculate the F and H function
            Fb      = CalculateF(b);
            auto H  = Fa - Fb;
            
            // Calculate Ak, Bk and slope terms
            auto Ak = yInvSq*H.two  + 2.0*yInv*H.one   + H.zero;
            auto Bk = yInvSq*H.four + 4.0*yInv*H.three + 6.0*H.two +
                      4.0*y*H.one + ySq*H.zero;
            auto slope = (xsvec[k+1] - xsvec[k]) /
            (xvec[k+1]*xvec[k+1] - xvec[k]*xvec[k]);
            
            // Add contribution to broadened cross section
            sigma -= Ak*(xsvec[k+1] - slope*xvec[k+1]*xvec[k+1]) - slope*Bk;
            
        }
        
        // Set the broadened cross section
        xsec.data(i).y = sigma;
    }
    
}