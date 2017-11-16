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

#include <iostream>
#include <set>
#include <regex>
#include <string>

#include <dirent.h>

#include "NIST.hpp"
#include "NDLS.hpp"
#include "XRS.hpp"
#include "CFS.hpp"

#include "SVG.hpp"
#include "IO.hpp"
#include "ACE.hpp"
#include "ADLS.hpp"

#include "DES.hpp"

int main(int argc, const char * argv[]) {
    
    /* Read ACE Library */
    ADLS adls("/path/to/new_ace_db_file_you_name.db");
    adls.insertACELibrary("/path/to/ace_library");

    auto andata = adls.getNeutronData("5010", "70c");

    return 0;

}
