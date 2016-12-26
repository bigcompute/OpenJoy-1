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

// ACE Data library system

#ifndef ADLS_HPP
#define ADLS_HPP

// Include the SQLite database header file
#include "sqlite3.h"

#include <iostream>

#include "ACE.hpp"

//namespace com {
//namespace ibhe {

// The ADLS class abstracts the database manager
// One could insert an ACE library, or
// One could extract the neutron data from it
class ADLS {
    
protected:
    sqlite3* db = nullptr;
    
    bool maintainSchema();
    bool isReady() const;
    
    // Material_Table APIs:
    
    // Obtain TABLEID for given information
    // If not found return -1
    long getTableID
    (const std::string& name,
     const std::string& lib);
    
    // Add a new material table entry
    // Return the TABLEID for the table entry
    // Rerurn -1 if table entry already exist
    long addMaterialTableEntry
    (const ACETable& table);
    
    // Get the current maximum TABLEID
    long getMaxTableId();
    
    // Extract a material table
    ACETable getMaterialTable
    (const std::string& name,
     const std::string& lib);
    
    
public:
    ADLS(const std::string& dbFilepath);
    ~ADLS();
    
    // External interfaces
    // Open the database
    bool open(const std::string& dbFilepath);
    
    // Close the database
    void close();
    
    // Insert an ACE library
    bool insertACELibrary(const std::string& aceDirFilepath);
    
    // Create an ACE neutron data
    ACENeutronData* getNeutronData
    (const std::string& name,
     const std::string& lib);
    
    // Iterate over all materials in the library with
    // customer function operating on the neutron data
    void iterateOverMaterials
    (std::function
     <void(const ACETable& table, ACENeutronData* ndata)> action,
     std::function<bool(const ACETable& table)> filter =
     [](const ACETable& table){return true;});
    
};

//}
//}

#endif /* ADLS_HPP */
