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

// Turn off the copy_n insecure warnings in visual studio
#ifndef _SCL_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#endif

#ifndef NDLS_HPP
#define NDLS_HPP

// Include the SQLite database header file
#include "sqlite3.h"

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <ccomplex>
#include <cmath>
#include <map>

#include "CMS.hpp"
#include "ENDF.hpp"

//namespace com {
//namespace ibhe {

// The NDLS class abstracts the database manager
// One could insert an ENDF file, or
// One could extract the neutron data from it
class NDLS {
    
protected:
    sqlite3* db = nullptr;
    
    bool maintainSchema();
    bool isReady() const;
    
    // Internal query functions
    
    // Material_Table APIs:
    
    // Obtain the EVALID for given information
    // Return -1 if no such entry found
    long getEvaluationId
    (long MAT, long NLIB, long NVER, long LREL,
     long NSUB, long NMOD, long LDRV, double TEMP);
    
    // Add a new material table entry
    // Return the EVALID for the table entry
    // Rerurn -1 if table entry already exist
    long addMaterialTableEntry
    (long MAT, long NLIB, long NVER, long LREL,
     long NSUB, long NMOD, long LDRV, double TEMP);
    
    // Get the current maximum EVALID
    long getMaxEvaluationId();
    
    
    // Description_Table APIs:
    
    // Add a new description table enrtry
    // Return -1 if already exist
    long addDescriptionTableEntry
    (long EVALID,
     const std::string& ZSYMAM,
     const std::string& ALAB,
     const std::string& EDATE,
     const std::string& AUTH,
     const std::string& REF,
     const std::string& DDATE,
     const std::string& RDATE,
     const std::string& ENDATE,
     const std::string& HSUB,
     const std::string& Summary,
     const std::string& Description);
    
    // Type_Table APIs:
    
    // Add a new type table entry
    // Return TYPEID if successful
    // Return -1 of already exist
    long addTypeTableEntry
    (long EVALID, long MF, long MT);
    
    // Get the type id of info given
    // Return -1 if not exist
    long getTypeId
    (long EVALID, long MF, long MT);
    
    // Get current max TYPEID
    long getMaxTypeId();
    
    
    // Header_Table APIs:
    
    // Add a new header table entry
    // Return RECORDID if successful
    // Return -1 if exist
    long addHeaderTableEntry
    (long TYPEID, const std::vector<double>& nums,
     long LVL, long IDX);
    
    // get current max RECORDID
    long getMaxRecordId();
    
    
    // Inheritance_Table APIs:
    
    // Add a new inheritance table entry
    // Return inheritance id if successful
    long addInheritanceTableEntry
    (long PARENTID, long CHILDID);
    
    // Get current max inheritance id
    long getMaxInheritanceId();
    
    
    // List_Table APIs:
    
    // Add a new list table entry
    // Return list id if successful
    long addListTableEntry
    (long RECORDID,
     const std::vector<double>& array);
    
    // Get current max list id
    long getMaxListId();
    
    
    // Interpolation_Table APIs:
    
    // Add a new interpolation table entry
    // Return interpolation id if successful
    long addInterpolationTableEntry
    (long RECORDID,
     const std::vector<long>& nbtArray,
     const std::vector<long>& intArray);
    
    // Get current max interpolation id
    long getMaxInterpolationId();
    
    
    // Function_Table APIs:
    
    // Add a new function table entry
    // Return function id if successful
    long addFunctionTableEntry
    (long RECORDID,
     const std::vector<double>& xArray,
     const std::vector<double>& yArray);
    
    // Get current max function id
    long getMaxFunctionId();
    
    
    // Userdata APIs
    
    // Retrieve the section headers of a given EVALID, MF
    std::vector<ENDFSectionHeader>
    getSectionHeaders(long EVALID, long MF);
    
    // Get the section header for given EVALID, MF, MT
    ENDFSectionHeader getSectionHeader(long EVALID, long MF, long MT);
    
    // Retrieve all material headers in the library
    // All for a filter, which is
    // a lambda function operating on NLIB, NVER, LREL
    std::vector<ENDFMaterialHeader>
    getLibraryMaterialHeaders
    (std::function<bool(long,long,long)> filter =
     [] (long,long,long) {return true;});
    
    // Retrieve the material headers for given MAT and
    // a lambda function operating on NLIB, NVER, LREL
    // Return an empty array if nothing found
    std::vector<ENDFMaterialHeader>
    getMaterialHeaders
    (long MAT, std::function<bool(long,long,long)> filter =
     [] (long,long,long) {return true;});
    
    // Retrieve the neutron data based on material header
    // Return a nullptr if not found
    // If not nullptr, it is the user's obligation to release memory
    ENDFNeutronData* getNeutronDataByHeader(const ENDFMaterialHeader& hmat);
    
    // Retrieve the ENDF children headers of the given record
    std::vector<long> getChildrenId(long PARENTID);
    
    // Retrieve the ENDF header based on record id
    ENDFHeader getHeader(long RECODDID);
    
    // Retrieve the ENDF list associated with the record id
    ENDFList getList(long RECORDID);
    
    // Retrieve the interpolation associated with the record id
    std::vector<ENDFInterpLaw> getInterpolation(long RECORDID);
    
    // Retrieve the function data points associated with the record id
    std::vector<ENDFDataPoint> getFunction(long RECORDID);
    
    // Retrieve the ENDF tab1 associated with the record id
    ENDFTab1 getTab1(long RECORDID);
    
    // Retrieve the ENDF tab2 list associated with record id
    ENDFTab2List getTab2List(long RECORDID);
    
    // Retrieve the ENDF tab2 tab1 associated with record id
    ENDFTab2Tab1 getTab2Tab1(long RECORDID);
    
    // Retrieve the ENDF tab2 tab2 tab1 associated with record id
    ENDFTab2Tab2Tab1 getTab2Tab2Tab1(long RECORDID);
    
    
public:
    NDLS(const std::string& dbFilepath);
    ~NDLS();
    
    // External interfaces
    // Open the database
    bool open(const std::string& dbFilepath);
    
    // Close the database
    void close();
    
    // Insert an ENDF text file into database
    bool insertENDFFile(const std::string& endfFilepath);
    
    // Obtain the neutron data
    // The material MAT and suggested NLIB can be given,
    // an optional filter function on NLIB, NVER, LREL can be given
    // Return nullptr if none such required material found
    // If not nullptr, it is the user's obligation to release memory
    ENDFNeutronData* getNeutronData
    (long MAT, std::function<bool(long,long,long)> filter =
     [] (long,long,long) {return true;});
    
    // Iterate over all materials in the library with
    // customer function operating on the neutron data
    // The iterator will be given an optional filter
    void iterateOverMaterials
    (std::function<void
     (const ENDFMaterialHeader& hmt,
      ENDFNeutronData* ndata)> operation,
     std::function<bool(long,long,long)> filter =
     [] (long,long,long) {return true;});
};



//}
//}

#endif /* NDLS_HPP */
