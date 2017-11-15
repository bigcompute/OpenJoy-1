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

// Data Exchange System

#ifndef DES_HPP
#define DES_HPP

#include <iostream>

#include "ENDF.hpp"
#include "ACE.hpp"
#include "ENDFRAW.pb.h"
#include "ACE.pb.h"

class DES {
    
private:
    // Conversion of the ENDFInterpolationFunction
    // to ENDF raw data table
    static proto::endf::raw::Table* getRawTable
    (const ENDFInterpolationFunction* func);
    
public:
    
    // Conversion of the ENDF neutron data
    // to ENDF raw data file format
    static proto::endf::raw::NeutronData* getRawNeutronData
    (const ENDFNeutronData* ndata);
    
    // Conversion of the ACE neutron data
    // to ACE pb data file format
    static proto::ace::NeutronData* getNeutronData
    (const ACENeutronData* ndata);
    
};




#endif /* DES_HEPP */
