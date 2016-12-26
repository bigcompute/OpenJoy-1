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

#include "NDLS.hpp"
#include "ENDF.hpp"

#include <algorithm>
#include <numeric>
#include <exception>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <functional>
#include <cassert>
#include <cmath>

//namespace com {
//namespace ibhe {

// Implementations for NDLS functions
NDLS::NDLS(const std::string& dbFilepath) {
    open(dbFilepath);
}

NDLS::~NDLS() {
    close();
}

bool NDLS::open(const std::string& dbFilepath) {
    
    int rc = 0;
    
    // Initialize SQLite enviroment
    rc = sqlite3_initialize();
    if (rc != SQLITE_OK) {
        std::cout << "[NDLS]: can't initialize SQLite!" << std::endl;
        return false;
    }
    
    // Open the database at given filepath
    rc = sqlite3_open_v2
    (dbFilepath.c_str(), &db,
     SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr);
    if (rc != SQLITE_OK || db == nullptr) {
        std::cout << "[NDLS]: can't open database "
                  << dbFilepath << "!" << std::endl;
        return false;
    }
    
    // Maintain database schema
    if (!maintainSchema()) {
        std::cout << "[NDLS]: database schema error, close database!"
        << std::endl;
        if (db != nullptr) {
            sqlite3_close_v2(db);
            db = nullptr;
        }
        return false;
    }
    
    return true;
}

void NDLS::close() {
    if (db != nullptr) {
        sqlite3_close_v2(db);
        db = nullptr;
    }
    sqlite3_shutdown();
}

bool NDLS::maintainSchema() {
    
    // Check whether database is open
    if (db == nullptr) {
        std::cout << "[NDLS]: database is not open!" << std::endl;
        return false;
    }
    
    sqlite3_stmt *stmt = nullptr;
    int rc    = -1;
    int exist = -1;
    
    // Check existance of 'Material_Table'
    {
        rc = sqlite3_prepare_v2
        (db, R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='table' AND name='Material_Table'
        )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    // Create 'Material_Table' if not exist
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db, R"(
         CREATE TABLE Material_Table
         ( EVALID INTEGER NOT NULL, MAT  INTEGER NOT NULL,
          NLIB   INTEGER NOT NULL, NVER INTEGER NOT NULL,
          LREL   INTEGER NOT NULL, NSUB INTEGER NOT NULL,
          NMOD   INTEGER NOT NULL, LDRV INTEGER NOT NULL,
          TEMP   REAL NOT NULL,
          PRIMARY KEY (EVALID),
          UNIQUE (MAT, NLIB, NVER, LREL, NSUB, NMOD, LDRV, TEMP) )
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Check existance of 'Description_Table'
    {
        rc = sqlite3_prepare_v2
        (db, R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='table' AND name='Description_Table'
        )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    // Create 'Description_Table' if not existance
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db, R"(
         CREATE TABLE Description_Table
         ( EVALID INTEGER NOT NULL,
          ZSYMAM TEXT, ALAB   TEXT,
          EDATE  TEXT, AUTH   TEXT,
          REF    TEXT, DDATE  TEXT,
          RDATE  TEXT, ENDATE TEXT,
          HSUB   TEXT,
          Summary TEXT,
          Description TEXT,
          PRIMARY KEY (EVALID),
          UNIQUE (EVALID),
          FOREIGN KEY (EVALID) REFERENCES Material_Table (EVALID) )
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Check existance of 'Type_Table'
    {
        rc = sqlite3_prepare_v2
        (db, R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='table' AND name='Type_Table'
        )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    // Create 'Type_Table' if not exist
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db, R"(
         CREATE TABLE Type_Table
         ( TYPEID INTEGER NOT NULL,
          EVALID INTEGER NOT NULL,
          MF INTEGER NOT NULL,
          MT INTEGER NOT NULL,
          PRIMARY KEY (TYPEID),
          UNIQUE (TYPEID, MF, MT),
          FOREIGN KEY (EVALID) REFERENCES Material_Table (EVALID) )
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Check existance of 'Header_Table'
    {
        rc = sqlite3_prepare_v2
        (db, R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='table' AND name='Header_Table'
        )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    // Create 'Header_Table' if not exist
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db, R"(
         CREATE TABLE Header_Table
         ( RECORDID INTEGER NOT NULL,
          TYPEID INTEGER NOT NULL,
          C1 REAL NOT NULL,
          C2 REAL NOT NULL,
          L1 REAL NOT NULL,
          L2 REAL NOT NULL,
          N1 REAL NOT NULL,
          N2 REAL NOT NULL,
          LVL INTEGER NOT NULL,
          IDX INTEGER NOT NULL,
          PRIMARY KEY (RECORDID),
          FOREIGN KEY (TYPEID) REFERENCES Type_Table (TYPEID) )
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Check existance of 'Function_Table'
    {
        rc = sqlite3_prepare_v2
        (db, R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='table' AND name='Function_Table'
        )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    // Create 'Function_Table' if not exist
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         CREATE TABLE Function_Table
         ( FUNCID INTEGER NOT NULL,
          RECORDID INTEGER NOT NULL,
          X BLOB NOT NULL,
          Y BLOB NOT NULL,
          PRIMARY KEY (FUNCID),
          UNIQUE (RECORDID),
          FOREIGN KEY (RECORDID) REFERENCES Header_Table (RECORDID) )
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Check existance of 'List_Table'
    {
        rc = sqlite3_prepare_v2
        (db, R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='table' AND name='List_Table'
        )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    // Create 'List_Table' if not exist
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         CREATE TABLE List_Table
         ( LISTID INTEGER NOT NULL,
          RECORDID INTEGER NOT NULL,
          B BLOB NOT NULL,
          PRIMARY KEY (LISTID),
          UNIQUE (RECORDID),
          FOREIGN KEY (RECORDID) REFERENCES Header_Table (RECORDID) )
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Check existance of 'Interpolation_Table'
    {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='table' AND name='Interpolation_Table'
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    // Create 'Interpolation_Table' if not exist
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         CREATE TABLE Interpolation_Table
         ( INTERPID INTEGER NOT NULL,
          RECORDID INTEGER NOT NULL,
          INT BLOB NOT NULL,
          NBT BLOB NOT NULL,
          PRIMARY KEY (INTERPID),
          UNIQUE (RECORDID),
          FOREIGN KEY (RECORDID) REFERENCES Header_Table (RECORDID) )
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Check existance of 'Inheritance_Table'
    {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='table' AND name='Inheritance_Table')"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    // Create 'Inheritance_Table' if not exist
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         CREATE TABLE Inheritance_Table
         ( INHEREID INTEGER NOT NULL,
          PARENTID INTEGER NOT NULL,
          CHILDID INTEGER NOT NULL,
          PRIMARY KEY (INHEREID),
          UNIQUE (PARENTID, CHILDID),
          FOREIGN KEY (PARENTID) REFERENCES Header_Table (RECORDID),
          FOREIGN KEY (CHILDID) REFERENCES Header_Table (RECORDID))
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    
    // Create index on TYPEID of Header_Table
    {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='index' AND name='TYPEID_Header_Index')"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         CREATE INDEX TYPEID_Header_Index
         ON Header_Table (TYPEID)
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Create index on RECORDID of Interpolation_Table
    {
        rc = sqlite3_prepare_v2
        (db, R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='index' AND name='RECORDID_Interpolation_Index')"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         CREATE UNIQUE INDEX RECORDID_Interpolation_Index
         ON Interpolation_Table (RECORDID)
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Create index on RECORDID of Function_Table
    {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='index' AND name='RECORDID_Function_Index')"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         CREATE UNIQUE INDEX RECORDID_Function_Index
         ON Function_Table (RECORDID)
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Create index on RECORDID of List_Table
    {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='index' AND name='RECORDID_List_Index')"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         CREATE UNIQUE INDEX RECORDID_List_Index
         ON List_Table (RECORDID)
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    // Create index on PARENTID of Inheritance_Table
    {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         SELECT count(*) FROM sqlite_master
         WHERE type='index' AND name='PARENTID_Inheritance_Index')"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK) return false;
        while ( sqlite3_step(stmt) == SQLITE_ROW) {
            exist = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    if (!exist) {
        rc = sqlite3_prepare_v2
        (db,
         R"(
         CREATE INDEX PARENTID_Inheritance_Index
         ON Inheritance_Table (PARENTID)
         )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    
    return true;
}

bool NDLS::isReady() const {
    return db != nullptr;
}


bool NDLS::insertENDFFile(const std::string& endfFilepath) {
    
    // Check database whether ready
    if (!isReady()) {
        std::cerr << "[NDLS]: the database is not ready!" << std::endl;
        return false;
    }
    
    // Function whether successful
    bool successful = true;
    
    // Global variables, indicating current state
    std::string   line;
    std::ifstream inFile;
    long MAT=-1, MF=-1, MT=-1, NS=-1;
    ENDFTapeReadState state = ENDFTapeReadState::ENDF_INIT;
    long headerLocation = -1;
    long EVALID=-1, TYPEID=-1;
    
    // Define processing lambda functions
    auto InitFunc = [&] () {
        
        try {
            ENDF::ReadLine(inFile, line);
            ENDF::ScanLine(line, MAT, MF, MT, NS);
            if (ENDF::GetRecordType(MAT, MF, MT, NS) ==
                ENDFControlRecordType::ENDF_TPID) {
                state = ENDFTapeReadState::ENDF_BEGIN_TAPE;
            } else {
                state = ENDFTapeReadState::ENDF_FINAL;
            }
        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }
        
    };
    
    auto TapeBeginFunc = [&] () {
        
        try {
            headerLocation = inFile.tellg();
            ENDF::ReadLine(inFile, line);
            ENDF::ScanLine(line, MAT, MF, MT, NS);
            if (ENDF::GetRecordType(MAT, MF, MT, NS) ==
                ENDFControlRecordType::ENDF_NONE) {
                std::cout<<">>>>Begin TAPE"<<std::endl;
                state = ENDFTapeReadState::ENDF_BEGIN_MAT;
            } else {
                state = ENDFTapeReadState::ENDF_FINAL;
            }
        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }
        
    };
    
    auto ReadFile1Section451MetaInfo = [&] () {
        // Read first line
        auto nums = ENDF::ScanNums(line);
        long ZA   = nums[0];
        auto AWR  = nums[1];
        long LRP  = nums[2];
        long LFI  = nums[3];
        long NLIB = nums[4];
        long NMOD = nums[5];
        // Read second line
        ENDF::ReadLine(inFile, line);
        nums = ENDF::ScanNums(line);
        auto ELIS = nums[0];
        long STA  = nums[1];
        long LIS  = nums[2];
        long LISO = nums[3];
        long NFOR = nums[5];
        // Read third line
        ENDF::ReadLine(inFile, line);
        nums = ENDF::ScanNums(line);
        auto AWI  = nums[0];
        auto EMAX = nums[1];
        long LREL = nums[2];
        long NSUB = nums[4];
        long NVER = nums[5];
        // Read fouth line
        ENDF::ReadLine(inFile, line);
        nums = ENDF::ScanNums(line);
        auto TEMP = nums[0];
        long LDRV = nums[2];
        long NWD  = nums[4];
        long NXC  = nums[5];
        
        std::cout<<" ENDF: MAT "<<MAT<<" from "
        <<ENDF::LibraryName(NLIB, NVER, LREL)
        <<" (SUB="<<NSUB<<", MOD="<<NMOD
        <<", DRV="<<LDRV<<")"<<std::endl;
        // Put into database Material_Table
        // Check existance
        if ((EVALID = getEvaluationId
             (MAT, NLIB, NVER, LREL, NSUB,
              NMOD, LDRV, TEMP)) == -1) {
            
            if((EVALID = addMaterialTableEntry
                (MAT, NLIB, NVER, LREL, NSUB,
                 NMOD, LDRV, TEMP)) == -1) {
                throw std::logic_error(" add material table entry error!");
            }
            
            ENDF::ReadLine(inFile, line);
            std::string ZSYMAM = line.substr(ENDFZSYMAMStart, ENDFZSYMAMLength);
            std::string ALAB   = line.substr(ENDFALABStart,   ENDFALABLength);
            std::string EDATE  = line.substr(ENDFEDATEStart,  ENDFEDATELength);
            std::string AUTH   = line.substr(ENDFAUTHStart,   ENDFAUTHLength);
            ENDF::ReadLine(inFile, line);
            std::string REF    = line.substr(ENDFREFStart,    ENDFREFLength);
            std::string DDATE  = line.substr(ENDFDDATEStart,  ENDFDDATELength);
            std::string RDATE  = line.substr(ENDFRDATStart,   ENDFRDATELength);
            std::string ENDATE = line.substr(ENDFENDATEStart, ENDFENDATELength);
            ENDF::ReadLine(inFile, line);
            std::string HSUB;
            HSUB.append(line.substr(0,ENDFTextWidth));
            HSUB.append("\n");
            ENDF::ReadLine(inFile, line);
            HSUB.append(line.substr(0,ENDFTextWidth));
            HSUB.append("\n");
            ENDF::ReadLine(inFile, line);
            HSUB.append(line.substr(0,ENDFTextWidth));
            std::string Description;
            for (long i=0; i+5<NWD; i++) {
                ENDF::ReadLine(inFile, line);
                Description.append(line.substr(0,ENDFTextWidth));
                if (i+6<NWD) Description.append("\n");
            }
            if(addDescriptionTableEntry
               (EVALID, ZSYMAM, ALAB, EDATE, AUTH, REF,
                DDATE, RDATE, ENDATE, HSUB,
                "", Description) == -1) {
                   throw std::logic_error(" add description table error!");
               }
            // Return to file header
            inFile.seekg(headerLocation);
            ENDF::ReadLine(inFile, line);
            ENDF::ScanLine(line, MAT, MF, MT, NS);
        } else {
            // Table already exist, not treat as an error
            std::cout
            << "[NDLS]: EVALID=" << EVALID <<" already exist!"
            << std::endl;
        }
    };
    
    auto MatBeginFunc = [&] () {
        
        try {
            std::cout<<">>>>Begin MAT "<<MAT<<std::endl;
            state = ENDFTapeReadState::ENDF_BEGIN_FILE;
            if (MF == 1 && MT == 451) {
                ReadFile1Section451MetaInfo();
            } else {
                throw std::logic_error
                ("[NDLS]: MAT tape not start with MF=1, MT=451");
            }
        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }
        
    };
    
    auto FileBeginFunc = [&] () {
        
        try {
            std::cout<<">>>>Begin FILE "<<MF<<std::endl;
            state = ENDFTapeReadState::ENDF_BEGIN_SECTION;
        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }
        
    };
    
    // Fundamental file read functions
    auto ReadHeader = [&, this]
    ( const long LVL, long& IDX,
      std::function<void(const ENDFRecord&)> op = [] (const ENDFRecord&) {}
    ) -> long {
        auto record = ENDF::ReadRecord(inFile);
        
        // Execute given operation
        op (record);
        
        // Check consistency
        if (MAT != record.MAT || MF != record.MF || MT != record.MT) {
            throw std::logic_error("MAT/MF/MT consitancy check fails!");
        }
        
        // Add header into database
        long RECORDID = -1;
        if ( (RECORDID=addHeaderTableEntry
              (TYPEID, record.nums, LVL, IDX++)) == -1) {
            throw std::logic_error("add header error!");
        }
        
        return RECORDID;
    };
    
    auto ReadList = [&, this]
    ( const long LVL, long& IDX,
      std::function<void(const ENDFRecord&)> op1 = [] (const ENDFRecord&) {},
      std::function<void(const std::vector<double>&)> op2 =
     [] (const std::vector<double>&) {}
    ) -> long {
        long RECORDID = -1, N = -1;
        
        RECORDID = ReadHeader(LVL, IDX, [&] (const ENDFRecord& record) {
            // Perform custom operations on header numbers
            op1 (record);
            N = record.nums[4];
        });
        
        auto array = ENDF::ReadNNumbers(inFile, N);
        if (!array.empty()) {
            if (addListTableEntry(RECORDID, array) == -1) {
                throw std::logic_error(" add list error!");
            }
        }
        
        // Perfom custom operations on array data
        op2(array);
        
        return RECORDID;
    };
    
    auto ReadTab1 = [&, this]
    ( const long LVL, long& IDX,
      std::function<void(const ENDFRecord&)> op = [] (const ENDFRecord&) {}
    ) -> long {
        long RECORDID = -1, NR = -1, NP = -1;
        
        RECORDID = ReadHeader(LVL, IDX, [&] (const ENDFRecord& record) {
            // Perform custom operations on header numbers
            op (record);
            NR = record.nums[4];
            NP = record.nums[5];
        });
        
        // Read NBT-INT arrays
        auto array = ENDF::ReadNNumbers(inFile, 2*NR);
        std::vector<long> nbtArray, intArray;
        nbtArray.resize(NR);
        intArray.resize(NR);
        for (long i=0; i<NR; i++) {
            nbtArray[i] = array[2*i];
            intArray[i] = array[2*i+1];
        }
        if (!nbtArray.empty() && !intArray.empty()) {
            if(addInterpolationTableEntry
               (RECORDID, nbtArray, intArray) == -1) {
                throw std::logic_error(" add interp error!");
            }
        }
        
        // Read x-y arrays
        array = ENDF::ReadNNumbers(inFile, 2*NP);
        std::vector<double> xArray, yArray;
        xArray.resize(NP);
        yArray.resize(NP);
        for (long i=0; i<NP; i++) {
            xArray[i] = array[2*i];
            yArray[i] = array[2*i+1];
        }
        if (!xArray.empty() && !yArray.empty()) {
            if (addFunctionTableEntry
                (RECORDID, xArray, yArray)==-1) {
                throw std::logic_error(" add func error!");
            }
        }
        
        return RECORDID;
    };
    
    auto ReadTab2 = [&, this]
    ( const long LVL, long& IDX,
      std::function<void(const ENDFRecord&)> op = [] (const ENDFRecord&) {}
    ) -> long {
        long RECORDID = -1, NR = -1, NZ = -1;
        
        RECORDID = ReadHeader(LVL, IDX, [&] (const ENDFRecord& record) {
            // Perform custom operations on header numbers
            op (record);
            NR = record.nums[4];
            NZ = record.nums[5];
        });
        
        // Read NBT-INT arrays
        auto array = ENDF::ReadNNumbers(inFile, 2*NR);
        std::vector<long> nbtArray, intArray;
        nbtArray.resize(NR);
        intArray.resize(NR);
        for (long i=0; i<NR; i++) {
            nbtArray[i] = array[2*i];
            intArray[i] = array[2*i+1];
        }
        if (!nbtArray.empty() && !intArray.empty()) {
            if(addInterpolationTableEntry
               (RECORDID, nbtArray, intArray)==-1) {
                throw std::logic_error(" add interp error!");
            }
        }
        
        return RECORDID;
    };
    
    auto ReadTab2List = [&, this]
    ( const long LVL, long& IDX,
      std::function<void(const ENDFRecord&)> op = [] (const ENDFRecord&) {}
    ) -> long {
        long RECORDID = -1, NR = -1, NZ = -1;
        
        RECORDID = ReadTab2(LVL, IDX, [&] (const ENDFRecord& record) {
            // Perform custom operations on header numbers
            op (record);
            NR = record.nums[4];
            NZ = record.nums[5];
        });
        
        // Next level
        long PARENTID = RECORDID;
        long CHILDLVL = LVL + 1;
        long CHILDIDX = 0;
        long CHILDID  = -1;
        
        for (long i=0; i<NZ; i++) {
            CHILDID = ReadList(CHILDLVL, CHILDIDX);
            if ( addInheritanceTableEntry(PARENTID, CHILDID)==-1 ) {
                throw std::logic_error("add inheritance error!");
            }
        }
        
        return RECORDID;
    };
    
    auto ReadTab2Tab1 = [&, this]
    ( const long LVL, long& IDX,
     std::function<void(const ENDFRecord&)> op = [] (const ENDFRecord&) {}
     ) -> long {
        long RECORDID = -1, NR = -1, NZ = -1;
        
        RECORDID = ReadTab2(LVL, IDX, [&] (const ENDFRecord& record) {
            // Perform custom operations on header numbers
            op (record);
            NR = record.nums[4];
            NZ = record.nums[5];
        });
        
        // Next level
        long PARENTID = RECORDID;
        long CHILDLVL = LVL + 1;
        long CHILDIDX = 0;
        long CHILDID  = -1;
        
        for (long i=0; i<NZ; i++) {
            CHILDID = ReadTab1(CHILDLVL, CHILDIDX);
            if ( addInheritanceTableEntry(PARENTID, CHILDID)==-1 ) {
                throw std::logic_error("add inheritance error!");
            }
        }
        
        return RECORDID;
    };
    
    // Define level
    long LVL = -1;
    
    // Use IDX array to story the index in different levels
    std::vector<long> IDX(64,0);
    std::vector<long> ID(64,0);
    
    // Table header level functions
    auto InitLevel = [&] () {
        LVL = 0;
        IDX[LVL] = 0;
    };
    
    auto MoveToNextLevel = [&] () {
        LVL ++;
        IDX[LVL] = 0;
    };
    
    auto ReturnToLastLevel = [&] () {
        LVL --;
    };
    
    // Simplified High-Level processing functions
    
    
    // The level and idx arrays are only accisible to first level functions
    
    // File-Section read functions
    // All functions will be given the header record numbers
    auto ReadFile1Section451 = [&] (const std::vector<double>& nums) {
        long NWD = -1, NXC = -1;
        
        for (long i=0; i<3; i++) {
            auto op = (i == 2)
            ? std::function<void(const ENDFRecord&)>
            ([&] (const ENDFRecord& record) {
                NWD  = record.nums[4];
                NXC  = record.nums[5];
            })
            : std::function<void(const ENDFRecord&)>
            ([] (const ENDFRecord&) {} );
            ID[LVL] = ReadHeader(LVL, IDX[LVL], op);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
        
        for (long i=0; i<NWD; i++) {
            ENDF::ReadLine(inFile, line);
        }
        
        for (long i=0; i<NXC; i++) {
            ID[LVL] = ReadHeader(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL])  == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile1Section452And456 = [&] (const std::vector<double>& nums) {
        long LNU = nums[3];
        if (LNU == 1) {
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        } else if (LNU == 2) {
            ID[LVL] = ReadTab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile1Section455 = [&] (const std::vector<double>& nums) {
        long LDG = nums[2];
        long LNU = nums[3];
        if (LDG==0 && LNU==2) {
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            ID[LVL] = ReadTab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        } else if (LDG==1 && LNU==2) {
            ID[LVL] = ReadTab2List(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            ID[LVL] = ReadTab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        } else if (LDG==0 && LNU==1) {
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            // Polynomial expension should be a list
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        } else if (LDG==1 && LNU==1) {
            ID[LVL] = ReadTab2List(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL])  == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            // Polynomial expension should be a list
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile1Section458 = [&] (const std::vector<double>& nums) {
        ID[LVL] = ReadList(LVL, IDX[LVL]);
        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
            throw std::logic_error("add inheritance error!");
        }
    };
    
    auto ReadFile1Section460 = [&] (const std::vector<double>& nums) {
        long LO = nums[2];
        long NG = nums[4];
        if (LO == 1) {
            for (long i=0; i<NG; i++) {
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
        } else {
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile2Section151 = [&] (const std::vector<double>& nums) {
        long NIS = nums[4];
        
        // Modified per isotope
        long ZAI = -1, LFW = -1, NER = -1;
        double ABN = 0.;
        
        auto RangeLoopFunc = [&] () {
            long LRU = -1, LRF = -1, NRO = -1, NAPS = -1;
            double EL = 0., EH = 0.;
            
            ID[LVL]=ReadHeader(LVL, IDX[LVL], [&] (const ENDFRecord& record)
            {
                EL   = record.nums[0];
                EH   = record.nums[1];
                LRU  = record.nums[2];
                LRF  = record.nums[3];
                NRO  = record.nums[4];
                NAPS = record.nums[5];
            });
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            MoveToNextLevel();
            assert(LVL == 3);
            
            double SPI = 0., AP = 0.;
            long NLS = -1;
            
            if (LFW == 0 && NER == 1 && LRU == 0 && LRF == 0 && NAPS == 0) {
                // Special case
                if (NRO == 0) {
                    ID[LVL]=ReadHeader(LVL, IDX[LVL], [&] (const ENDFRecord& record)
                    {
                        SPI = record.nums[0];
                        AP  = record.nums[1];
                        NLS = record.nums[4];
                    });
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                } else if (NRO == 1) {
                    ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                }
            } else if (LRU == 1) {
                // Resolved resonance parameters
                if (LRF == 1 || LRF == 2) {
                    if (NRO != 0) {
                        ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                    }
                    
                    ID[LVL]=ReadHeader(LVL, IDX[LVL], [&] (const ENDFRecord& record)
                    {
                        SPI = record.nums[0];
                        AP  = record.nums[1];
                        NLS = record.nums[4];
                    });
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                    
                    MoveToNextLevel();
                    assert(LVL == 4);
                    
                    for (long l=0; l<NLS; l++) {
                        ID[LVL] = ReadList(LVL, IDX[LVL]);
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                    }
                    
                    ReturnToLastLevel();
                    assert(LVL == 3);
                    
                } else if (LRF == 3) {
                    long LAD = -1, NLSC = -1;
                    
                    if (NRO != 0) {
                        ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                    }
                    
                    ID[LVL]=ReadHeader(LVL, IDX[LVL], [&] (const ENDFRecord& record)
                    {
                        SPI  = record.nums[0];
                        AP   = record.nums[1];
                        LAD  = record.nums[2];
                        NLS  = record.nums[4];
                        NLSC = record.nums[5];
                    });
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                    
                    MoveToNextLevel();
                    assert(LVL == 4);
                    
                    for (long l=0; l<NLS; l++) {
                        ID[LVL] = ReadList(LVL, IDX[LVL]);
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                    }
                    
                    ReturnToLastLevel();
                    assert(LVL == 3);
                    
                } else if (LRF == 4) {
                    if (NRO != 0) {
                        ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                    }
                    
                    ID[LVL]=ReadHeader
                    (LVL, IDX[LVL], [&] (const ENDFRecord& record)
                    {
                        SPI  = record.nums[0];
                        AP   = record.nums[1];
                        NLS  = record.nums[4];
                    });
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                    
                    MoveToNextLevel();
                    assert(LVL == 4);
                    
                    for (long l=0; l<NLS; l++) {
                        long NJS = -1;
                        
                        ID[LVL]=ReadHeader
                        (LVL, IDX[LVL], [&] (const ENDFRecord& record)
                        {
                            NJS  = record.nums[4];
                        });
                        
                        MoveToNextLevel();
                        assert(LVL == 5);
                        
                        for (long j=0; j<NJS; j++) {
                            ID[LVL] = ReadList(LVL, IDX[LVL]);
                            if(addInheritanceTableEntry
                               (ID[LVL-1], ID[LVL]) == -1) {
                                throw std::logic_error("add inheritance error!");
                            }
                        }
                        
                        ReturnToLastLevel();
                        assert(LVL == 4);
                    }
                    
                    ReturnToLastLevel();
                    assert(LVL == 3);
                    
                } else if (LRF == 5 || LRF == 6) {
                    std::cout
                    <<R"( ENDF: Format no longer supported in ENDF-6)"
                    <<std::endl;
                    state = ENDFTapeReadState::ENDF_FINAL;
                    return;
                } else if (LRF == 7) {
                    long IFG = -1, KRM = -1, NJS = -1, KRL = -1;
                    
                    ID[LVL]=ReadHeader
                    (LVL, IDX[LVL], [&] (const ENDFRecord& record)
                    {
                        IFG = record.nums[2];
                        KRM = record.nums[3];
                        NJS = record.nums[4];
                        KRL = record.nums[5];
                    });
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                    
                    // Gamma plus compound
                    // nucleus pair for KRM=1,2,3
                    ID[LVL] = ReadList(LVL, IDX[LVL]);
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                    
                    MoveToNextLevel();
                    assert(LVL == 4);
                    
                    for (long j=0; j<NJS; j++) {
                        long KBK = -1, KPS = -1;
                        
                        ID[LVL]=ReadList(LVL, IDX[LVL], [&] (const ENDFRecord& record)
                        {
                            KBK = record.nums[2];
                            KPS = record.nums[3];
                        });
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                        
                        long NCH = -1;
                        
                        ID[LVL]=ReadList(LVL, IDX[LVL], [&] (const ENDFRecord& record)
                        {
                            NCH = record.nums[5];
                        });
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                        
                        // Optional information, KBK>0
                        if (KBK > 0) {
                            // Additional information
                            // for each channel
                            for (long ch=0; ch<NCH; ch++) {
                                long LBK = -1;
                                
                                ID[LVL]=ReadList
                                (LVL, IDX[LVL], [&] (const ENDFRecord& record)
                                {
                                    LBK = record.nums[4];
                                });
                                if(addInheritanceTableEntry
                                   (ID[LVL-1], ID[LVL]) == -1) {
                                    throw std::logic_error("add inheritance error!");
                                }
                                
                                if (LBK == 0) {
                                    // Option 0.
                                    // Dummy resonances
                                    
                                } else if (LBK == 1) {
                                    // Option 1. Tabular complex function of energy
                                    // Real parts
                                    ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                                    if(addInheritanceTableEntry
                                       (ID[LVL-1], ID[LVL]) == -1) {
                                        throw std::logic_error
                                        ("add inheritance error!");
                                    }
                                    
                                    // Imaginary parts
                                    ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                                    if(addInheritanceTableEntry
                                       (ID[LVL-1], ID[LVL]) == -1) {
                                        throw std::logic_error
                                        ("add inheritance error!");
                                    }
                                } else if (LBK == 2) {
                                    // Option 2. SAMMY's logarithmic parametrization
                                } else if (LBK == 3) {
                                    // Option 3. Froehner's parametrization
                                }
                            }
                        }
                        
                        // Optional information, KPS>0
                        if (KPS > 0) {
                            // Additional information
                            // for each channel
                            for (long ch=0; ch<NCH; ch++) {
                                long LPS = -1;
                                
                                ID[LVL]=ReadList(LVL, IDX[LVL], [&] (const ENDFRecord& record)
                                {
                                    LPS = record.nums[4];
                                });
                                if(addInheritanceTableEntry
                                   (ID[LVL-1], ID[LVL]) == -1) {
                                    throw std::logic_error
                                    ("add inheritance error!");
                                }
                                
                                if (LPS == 0) {
                                    // Option 0. Hard-sphere phase shifts
                                } else if (LPS == 1) {
                                    // Option 1. Phase shift is a tabular
                                    // complex function of energy
                                    
                                    // Real parts
                                    ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                                    if(addInheritanceTableEntry
                                       (ID[LVL-1], ID[LVL]) == -1) {
                                        throw std::logic_error
                                        ("add inheritance error!");
                                    }
                                    
                                    // Imaginary parts
                                    ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                                    if(addInheritanceTableEntry
                                       (ID[LVL-1], ID[LVL]) == -1) {
                                        throw std::logic_error
                                        ("add inheritance error!");
                                    }
                                }
                            }
                        }
                    }
                    
                    ReturnToLastLevel();
                    assert(LVL == 3);
                    
                }
                // End of LRF cases
            } else if (LRU == 2) {
                // Unresolved resonance parameters
                if (LFW == 0 && LRF == 1) {
                    // Case A
                    ID[LVL]=ReadHeader
                    (LVL, IDX[LVL], [&] (const ENDFRecord& record)
                    {
                        NLS  = record.nums[4];
                    });
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                    
                    MoveToNextLevel();
                    assert(LVL == 4);
                    
                    for (long l=0; l<NLS; l++) {
                        ID[LVL] = ReadList(LVL, IDX[LVL]);
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                    }
                    
                    ReturnToLastLevel();
                    assert(LVL == 3);
                    
                } else if (LFW == 1 && LRF == 1) {
                    // Case B
                    ID[LVL]=ReadList(LVL, IDX[LVL], [&] (const ENDFRecord& record)
                    {
                        NLS  = record.nums[5];
                    });
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                    
                    MoveToNextLevel();
                    assert(LVL == 4);
                    
                    for (long l=0; l<NLS; l++) {
                        long NJS = -1;
                        
                        ID[LVL]=ReadHeader(LVL, IDX[LVL], [&] (const ENDFRecord& record)
                        {
                            NJS  = record.nums[4];
                        });
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                        
                        MoveToNextLevel();
                        assert(LVL == 5);
                        
                        for (long j=0; j<NJS; j++) {
                            ID[LVL] = ReadList(LVL, IDX[LVL]);
                            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                                throw std::logic_error("add inheritance error!");
                            }
                        }
                        
                        ReturnToLastLevel();
                        assert(LVL == 4);
                        
                    }
                    
                    ReturnToLastLevel();
                    assert(LVL == 3);
                    
                } else if ( (LFW == 0 || LFW == 1) && LRF == 2) {
                    // Case C
                    ID[LVL]=ReadHeader
                    (LVL, IDX[LVL], [&] (const ENDFRecord& record)
                    {
                        NLS  = record.nums[4];
                    });
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                    
                    MoveToNextLevel();
                    assert(LVL == 4);
                    
                    for (long l=0; l<NLS; l++) {
                        long NJS = -1;
                        
                        ID[LVL]=ReadHeader(LVL, IDX[LVL], [&] (const ENDFRecord& record)
                        {
                            NJS  = record.nums[4];
                        });
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                        
                        MoveToNextLevel();
                        assert(LVL == 5);
                        
                        for (long j=0; j<NJS; j++) {
                            ID[LVL] = ReadList(LVL, IDX[LVL]);
                            if(addInheritanceTableEntry
                               (ID[LVL-1], ID[LVL]) == -1) {
                                throw std::logic_error("add inheritance error!");
                            }
                        }
                        
                        ReturnToLastLevel();
                        assert(LVL == 4);
                        
                    }
                    
                    ReturnToLastLevel();
                    assert(LVL == 3);
                    
                }
                // End LFW/LRF combinations
            }
            // End LRU cases
            
            ReturnToLastLevel();
            assert(LVL == 2);
        };
        
        auto IsotopeLoopFunc = [&] () {
            
            ID[LVL]=ReadHeader(LVL, IDX[LVL], [&] (const ENDFRecord& record)
            {
                ZAI = record.nums[0];
                ABN = record.nums[1];
                LFW = record.nums[3];
                NER = record.nums[4];
            });
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            MoveToNextLevel();
            assert(LVL == 2);
            
            // Loop over ranges
            for (long region=0; region<NER; region++) {
                RangeLoopFunc();
            }
            // End region loop
            
            ReturnToLastLevel();
            assert(LVL == 1);
        };
        
        // Loop over isotopes
        for (long isotope=0; isotope<NIS; isotope++) {
            IsotopeLoopFunc();
            if (state == ENDFTapeReadState::ENDF_FINAL) return;
        }
        // End isotope loop
    };
    
    auto ReadFile3 = [&] (const std::vector<double>& nums) {
        // Point cross sections
        ID[LVL] = ReadTab1(LVL, IDX[LVL]);
        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
            throw std::logic_error("add inheritance error!");
        }
    };
    
    auto ReadFile4 = [&] (const std::vector<double>& nums) {
        long LTT = nums[3];
    
        long LI = -1, LCT = -1;
        ID[LVL]=ReadHeader(LVL, IDX[LVL], [&] (const ENDFRecord& record)
        {
            LI   = record.nums[2];
            LCT  = record.nums[3];
        });
        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
            throw std::logic_error("add inheritance error!");
        }
        
        if (LTT == 1 && LI == 0) {
            // Legendre Polynomial Coefficients
            ID[LVL] = ReadTab2List(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        } else if (LTT == 2 && LI == 0) {
            // Tabulated probability distributions
            ID[LVL] = ReadTab2Tab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        } else if (LTT == 0 && LI == 1) {
            // Purely isotropic angular distribution
            // Nothing to read
            
        } else if (LTT == 3 && LI == 0) {
            // Angular distribution over two energy ranges
            // Legendre coefficients
            ID[LVL] = ReadTab2List(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            // Tabulated data
            ID[LVL] = ReadTab2Tab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
        }
    };
    
    auto ReadFile5 = [&] (const std::vector<double>& nums) {
        // Energy distributions for incident neutrons
        long NK = nums[4];
        
        for (long k=0; k<NK; k++) {
            long LF = -1;
            
            ID[LVL]=ReadTab1(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                LF = record.nums[3];
            });
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            MoveToNextLevel();
            assert(LVL == 2);
            
            if (LF == 1) {
                ID[LVL] = ReadTab2Tab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (LF == 5) {
                // Theta(E)
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
                
                // g(x)
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (LF == 7 || LF == 9) {
                // Theta(E)
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (LF == 11) {
                // a(E)
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
                
                // b(E)
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (LF == 12) {
                // TM(E)
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else {
                throw std::logic_error(" Unknown energy distribution error!");
            }
            
            ReturnToLastLevel();
            assert(LVL == 1);
            
            // End LF types
        }
    };
    
    auto ReadFile6 = [&] (const std::vector<double>& nums) {
        // Product energy-angle distribution
        long LCT = nums[3];
        long NK  = nums[4];
        
        for (long k=0; k<NK; k++) {
            long LAW = -1;
            
            ID[LVL] = ReadTab1(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                LAW = record.nums[3];
            });
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            MoveToNextLevel();
            assert(LVL == 2);
            
            if (LAW == 0) {
                // Unknown law
                // Nothing to do
            } else if (LAW == 1) {
                // Continuum Energy-Angle Distribution
                long LANG = -1;
                
                ID[LVL]=ReadTab2List
                (LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                    LANG = record.nums[2];
                });
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (LAW == 2) {
                // Discrete Two-Body Scattering
                ID[LVL]=ReadTab2List(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (LAW == 3) {
                // Isotropic Discrete Emission
                // No law-dependent structures
            } else if (LAW == 4) {
                // Discrete To-Bodt Recoils
                // No law-dependent structures
            } else if (LAW == 5) {
                // Charged-Particle Elastic Scattering
                ID[LVL]=ReadTab2List(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (LAW == 6) {
                // N-Body Phase-Space Distribution
                long APSX = -1, NPSX = -1;
                ID[LVL]=ReadHeader
                (LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                    APSX = record.nums[0];
                    NPSX = record.nums[5];
                });
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (LAW == 7) {
                long NR = -1, NE = -1;
                
                // Read Energy interpolation header
                ID[LVL]=ReadTab2
                (LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                    NR = record.nums[4];
                    NE = record.nums[5];
                });
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
                
                MoveToNextLevel();
                assert(LVL == 3);
                
                // Loop over all energies
                for (long e=0; e<NE; e++) {
                    ID[LVL] = ReadTab2Tab1(LVL, IDX[LVL]);
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                }
                
                ReturnToLastLevel();
                assert(LVL == 2);
            }
            
            ReturnToLastLevel();
            assert(LVL == 1);
            
            // End LAW
        }
    };
    
    auto ReadFile7Section2 = [&] (const std::vector<double>& nums) {
        long LTHR = nums[2];
        
        if (LTHR == 1) {
            // Coherent Elastic Scattering
            long LT = -1;
            
            ID[LVL]=ReadTab1(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                LT = record.nums[2];
            });
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            MoveToNextLevel();
            assert(LVL == 2);
            
            for (long t=0; t<LT; t++) {
                ID[LVL] = ReadList(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
            
            ReturnToLastLevel();
            assert(LVL == 1);
        } else if (LTHR == 2) {
            // Incoherent Elastic Scattering
            ID[LVL] = ReadTab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile7Section4 = [&] (const std::vector<double>& nums) {
        // Incoherent Inelastic Scattering
        long LAT = nums[3], LASYM = nums[4], NS0 = -1;
        std::vector<double> B;
        
        ID[LVL]=ReadList(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
            NS0 = record.nums[5];
        }, [&] (const std::vector<double>& array) {
            B = array;
        });
        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
            throw std::logic_error("add inheritance error!");
        }
        
        long NB = -1;
        ID[LVL]=ReadTab2(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
            NB = record.nums[5];
        });
        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
            throw std::logic_error("add inheritance error!");
        }
        
        MoveToNextLevel();
        assert(LVL == 2);
        
        for (long b=0; b<NB; b++) {
            long LT = -1;
            ID[LVL]=ReadTab1(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                LT = record.nums[2];
            });
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            MoveToNextLevel();
            assert(LVL == 3);
            
            for (long t=0; t<LT; t++) {
                ID[LVL] = ReadList(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
            
            ReturnToLastLevel();
            assert(LVL == 2);
        }
        
        ReturnToLastLevel();
        assert(LVL == 1);
        
        // Teff0
        ID[LVL] = ReadTab1(LVL, IDX[LVL]);
        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
            throw std::logic_error("add inheritance error!");
        }
        
        // Teff1
        if (NS0 >= 1) {
            if (B[6] == 0) {
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
        }
        
        // Teff2
        if (NS0 >= 2) {
            if (B[12] == 0) {
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
        }
        
        // Teff3
        if (NS0 >= 3) {
            if (B[18] == 0) {
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
        }
        
    };
    
    auto ReadFile8Section454And459 = [&] (const std::vector<double>& nums) {
        long LE = nums[2];
        for (long e=0; e<LE+1; e++) {
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile8Section457 = [&] (const std::vector<double>& nums) {
        long LIS = nums[2], LISO = nums[3], NST  = nums[4], NSP  = nums[5];
        
        if (NST == 0) {
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            MoveToNextLevel();
            assert(LVL == 2);
            
            for (long sp=0; sp<NSP; sp++) {
                long STYP = -1, LCON = -1, NER = -1;
                ID[LVL]=ReadList(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                    STYP = record.nums[1];
                    LCON = record.nums[2];
                    NER  = record.nums[5];
                });
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
                
                if (LCON != 1) {
                    MoveToNextLevel();
                    assert(LVL == 3);
                    
                    for (long er=0; er<NER; er++) {
                        ID[LVL] = ReadList(LVL, IDX[LVL]);
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                    }
                    
                    ReturnToLastLevel();
                    assert(LVL == 2);
                }
                
                if (LCON != 0) {
                    long LCOV = -1;
                    ID[LVL]=ReadTab1(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                        LCOV = record.nums[3];
                    });
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                    
                    if (LCOV != 0) {
                        ID[LVL] = ReadList(LVL, IDX[LVL]);
                        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                            throw std::logic_error("add inheritance error!");
                        }
                    }
                }
            }
            
            ReturnToLastLevel();
            assert(LVL == 1);
        } else if (NST == 1) {
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile8OtherSections = [&] (const std::vector<double>& nums) {
        long LIS = nums[2], LISO = nums[3], NS0  = nums[4], NO = nums[5];
        
        for (long s=0; s<NS0; s ++) {
            if (NO == 0) {
                ID[LVL] = ReadList(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (NO == 1) {
                ID[LVL] = ReadHeader(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
            
        }
    };
    
    auto ReadFile9 = [&] (const std::vector<double>& nums) {
        // Multiplicity of Radioactive Products
        long LIS = nums[2], NS0 = nums[4];
        for (long s=0; s<NS0; s ++) {
            ID[LVL] = ReadTab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile10 = [&] (const std::vector<double>& nums) {
        // Production Cross Section for Radionuclides
        long LIS = nums[2], NS0 = nums[4];
        for (long s=0; s<NS0; s ++) {
            ID[LVL] = ReadTab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile11 = [&] (const std::vector<double>& nums) {
        // General Comments on Photon Production
    };
    
    auto ReadFile12 = [&] (const std::vector<double>& nums) {
        // Photon Production Yield Data
        long LO = nums[2];
        if (LO == 1) {
            // Option 1: Multilicities
            long NK = nums[4];
            if (NK > 1) {
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
            
            MoveToNextLevel();
            assert(LVL == 2);
            
            for (long k=0; k<NK; k++) {
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
            
            ReturnToLastLevel();
            assert(LVL == 1);
            
        } else if (LO == 2) {
            // Option 2: Transition Probability Arrays
            long LG = nums[3], NS0 = nums[4];
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile13 = [&] (const std::vector<double>& nums) {
        // Photon Production Cross Sections
        long NK = nums[4];
        if (NK > 1) {
            ID[LVL] = ReadTab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
        
        MoveToNextLevel();
        assert(LVL == 2);
        
        for (long k=0; k<NK; k++) {
            ID[LVL] = ReadTab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
        
        ReturnToLastLevel();
        assert(LVL == 1);
    };
    
    auto ReadFile14 = [&] (const std::vector<double>& nums) {
        // Photon Angular Distributions
        long LI = nums[2], LTT = nums[3], NK = nums[4], NI = nums[5];
        if (LI == 1) {
            // Isotropic Distribution
            // Nothing to read
        } else if (LI == 0 && LTT == 1) {
            // Anisotropic Distribution with
            // Legendre Coefficient Representation
            for (long k=0; k<NK; k++) {
                if (k<NI) {
                    // Isotropic
                    ID[LVL] = ReadHeader(LVL, IDX[LVL]);
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                } else {
                    // Anisotropic
                    ID[LVL] = ReadTab2List(LVL, IDX[LVL]);
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                }
            }
        } else if (LI == 0 && LTT == 2) {
            // Anisotropic Distribution with
            // Tabulated Angular Distribution
            for (long k=0; k<NK; k++) {
                if (k<NI) {
                    // Isotropic
                    ID[LVL] = ReadHeader(LVL, IDX[LVL]);
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                } else {
                    // Anisotropic
                    ID[LVL] = ReadTab2Tab1(LVL, IDX[LVL]);
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                }
            }
        }
        // End angular type
    };
    
    auto ReadFile15 = [&] (const std::vector<double>& nums) {
        // Continous Photon Energy Spectra
        long NC = nums[4];
        for (long j=0; j<NC; j++) {
            long LF = -1;
            ID[LVL] = ReadTab1(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                LF  = record.nums[3];
            });
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            if (LF == 1) {
                ID[LVL] = ReadTab2Tab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
            // Other LF types remains to define
        }
    };
    
    auto ReadFile23 = [&] (const std::vector<double>& nums) {
        // Smooth Photon Interaction Cross Sections
        ID[LVL] = ReadTab1(LVL, IDX[LVL]);
        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
            throw std::logic_error("add inheritance error!");
        }
    };
    
    auto ReadFile26 = [&] (const std::vector<double>& nums) {
        // Secondary Distributions for
        // Photo-and Electro-Atomic Data
        long ZA = nums[0], NK = nums[4];
        for (long k=0; k<NK; k++) {
            ID[LVL] = ReadTab1(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            long ZAP = nums[0], LAW = nums[3];
            if (LAW == 1) {
                // Continuum Energy-Angle Distribution
                long LANG = -1;
                ID[LVL] = ReadTab2List(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                    LANG  = record.nums[2];
                });
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (LAW == 2) {
                // Discrete Two-Body Scattering
                ID[LVL] = ReadTab2List(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            } else if (LAW == 8) {
                // Law 8
                ID[LVL] = ReadTab1(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
        }
    };
    
    auto ReadFile27 = [&] (const std::vector<double>& nums) {
        // Atomic Form Factors or Scattering Functions
        ID[LVL] = ReadTab1(LVL, IDX[LVL]);
        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
            throw std::logic_error("add inheritance error!");
        }
    };
    
    auto ReadFile28 = [&] (const std::vector<double>& nums) {
        // Atomic Relaxation Data
        long NSS = nums[4];
        for (long ss=0; ss<NSS; ss++) {
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile30Section1 = [&] (const std::vector<double>& nums) {
        // Covariances of Models Parameters
        // Direction and Correspondence Table
        long NP = nums[5], NDIR = -1, NCTAB = -1;
        ID[LVL] = ReadHeader(LVL, IDX[LVL], [&] (const ENDFRecord& record) {
            NDIR  = record.nums[4];
            NCTAB = record.nums[5];
        });
        if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
            throw std::logic_error("add inheritance error!");
        }
        
        MoveToNextLevel();
        assert(LVL == 2);
        
        for (long dir=0; dir<NDIR; dir++) {
            ID[LVL] = ReadHeader(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
        
        for (long ctab=0; ctab<NCTAB; ctab++) {
            ID[LVL] = ReadHeader(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
        
        ReturnToLastLevel();
        assert(LVL == 1);
        
    };
    
    auto ReadFile30Section2 = [&] (const std::vector<double>& nums) {
        // Covariance Matrix
        long NP = nums[5];
        for (long p=0; p<NP; p++) {
            ID[LVL] = ReadList(LVL, IDX[LVL]);
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
        }
    };
    
    auto ReadFile30Section11To999 = [&] (const std::vector<double>& nums) {
        // Sensitivities
        long NL = nums[5], MP = MT-10;
        for (long l=0; l<NL; l++) {
            // Subsection structures
        }
    };
    
    auto ReadFile31 = [&] (const std::vector<double>& nums) {
        // Covariances of Fission NuBar
        long NL = nums[5];
        for (long l=0; l<NL; l++) {
            long NC = -1, NI = -1;
            ID[LVL] = ReadHeader
            (LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                NC = record.nums[4];
                NI = record.nums[5];
            });
            if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                throw std::logic_error("add inheritance error!");
            }
            
            MoveToNextLevel();
            assert(LVL == 2);
            
            // NC Type tables
            for (long c=0; c<NC; c++) {
                long LTY = -1;
                ID[LVL] = ReadHeader
                (LVL, IDX[LVL], [&] (const ENDFRecord& record) {
                    LTY = record.nums[3];
                });
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
                
                if (LTY == 0) {
                    ID[LVL] = ReadList(LVL, IDX[LVL]);
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                } else if (LTY == 1 || LTY == 2 || LTY == 3) {
                    ID[LVL] = ReadList(LVL, IDX[LVL]);
                    if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                        throw std::logic_error("add inheritance error!");
                    }
                }
            }
            
            // NI Type tables
            for (long i=0; i<NI; i++) {
                ID[LVL] = ReadList(LVL, IDX[LVL]);
                if(addInheritanceTableEntry(ID[LVL-1], ID[LVL]) == -1) {
                    throw std::logic_error("add inheritance error!");
                }
            }
            
            ReturnToLastLevel();
            assert(LVL == 1);
        }
    };
    
    auto SectionBeginFunc = [&] () {
        
        try {
            
            std::cout<<">>>>Begin SECTION "<<MT<<std::endl;
            if ( (TYPEID=getTypeId(EVALID, MF, MT)) == -1 ) {
                
                if ( (TYPEID=addTypeTableEntry
                      (EVALID, MF, MT)) == -1 ) {
                    throw std::logic_error(" Unable to get type table entry!");
                }
                
                InitLevel();
                assert(LVL == 0);
                
                // Read section header,
                // Only this place not using ReadHeader function
                auto nums = ENDF::ScanNums(line);
                if ( (ID[LVL]=addHeaderTableEntry
                      (TYPEID, nums, LVL, IDX[LVL]++)) == -1) {
                    throw std::logic_error(" Unable to add header table entry!");
                }
                
                // Read children
                MoveToNextLevel();
                assert(LVL == 1);
                
                if (MF == 1 && MT == 451) {
                    
                    ReadFile1Section451(nums);
                    
                } else if (MF == 1 && (MT == 452 || MT == 456) ) {
                    
                    ReadFile1Section452And456(nums);
                    
                } else if (MF == 1 && MT == 455) {
                    
                    ReadFile1Section455(nums);
                    
                } else if (MF == 1 && MT == 458) {
                    
                    ReadFile1Section458(nums);
                    
                } else if (MF == 1 && MT == 460) {
                    
                    ReadFile1Section460(nums);
                    
                } else if (MF == 2 && MT == 151) {
                    
                    ReadFile2Section151(nums);
                    
                } else if (MF == 3) {
                    
                    ReadFile3(nums);
                    
                } else if (MF == 4) {
                    
                    ReadFile4(nums);
                    
                } else if (MF == 5) {
                    
                    ReadFile5(nums);
                    
                } else if (MF == 6) {
                    
                    ReadFile6(nums);
                    
                } else if (MF == 7 && MT ==2) {
                    
                    ReadFile7Section2(nums);
                    
                } else if (MF == 7 && MT ==4) {
                    
                    ReadFile7Section4(nums);
                    
                } else if (MF == 8 && (MT == 454 || MT == 459) ) {
                    
                    ReadFile8Section454And459(nums);
                    
                } else if (MF == 8 && MT ==457) {
                    
                    ReadFile8Section457(nums);
                    
                } else if (MF == 8) {
                    
                    ReadFile8OtherSections(nums);
                    
                } else if (MF == 9) {
                    
                    ReadFile9(nums);
                    
                } else if (MF == 10) {
                    
                    ReadFile10(nums);
                    
                } else if (MF == 11) {
                    
                    ReadFile11(nums);
                    
                } else if (MF == 12) {
                    
                    ReadFile12(nums);
                    
                } else if (MF == 13) {
                    
                    ReadFile13(nums);
                    
                } else if (MF == 14) {
                    
                    ReadFile14(nums);
                    
                } else if (MF == 15) {
                    
                    ReadFile15(nums);
                    
                } else if (MF == 23) {
                    
                    ReadFile23(nums);
                    
                } else if (MF == 26) {
                    
                    ReadFile26(nums);
                    
                } else if (MF == 27) {
                    
                    ReadFile27(nums);
                    
                } else if (MF == 28) {
                    
                    ReadFile28(nums);
                    
                } else if (MF == 30 && MT == 1) {
                    
                    ReadFile30Section1(nums);
                    
                } else if (MF == 30 && MT == 2) {
                    
                    ReadFile30Section2(nums);
                    
                } else if (MF == 30 && (MT >= 11 && MT <= 999)) {
                    
                    ReadFile30Section11To999(nums);
                    
                } else if (MF == 31) {
                    
                    ReadFile31(nums);
                    
                }
                
                // Next MF and MT
                
                ReturnToLastLevel();
                assert(LVL == 0);
                
                ENDF::ReadLine(inFile, line);
                ENDF::ScanLine(line, MAT, MF, MT, NS);
                auto type = ENDF::GetRecordType(MAT, MF, MT, NS);
                if (type == ENDFControlRecordType::ENDF_NONE) {
                    state = ENDFTapeReadState::ENDF_READ_SECTION;
                } else if (type == ENDFControlRecordType::ENDF_SEND) {
                    state = ENDFTapeReadState::ENDF_END_SECTION;
                } else {
                    state = ENDFTapeReadState::ENDF_FINAL;
                }
                
            } else {
                std::cout
                << " ENDF: EVALID=" << EVALID << ", MF="
                << MF << ", MT=" << MT << " already exist!"
                << std::endl;
                // Skip read until section end
                do {
                    ENDF::ReadLine(inFile, line);
                    ENDF::ScanLine(line, MAT, MF, MT, NS);
                } while (ENDF::GetRecordType(MAT, MF, MT, NS)
                         != ENDFControlRecordType::ENDF_SEND);
                state = ENDFTapeReadState::ENDF_END_SECTION;
            }
            
        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }
        
    };
    
    auto SectionReadFunc = [&] () {
        
        try {
            // Perform current line
            if (MF == 1 && MT == 451) {
                // Nothing to do
                assert(false);
            } else if (MF == 1 && (MT == 452 || MT == 456) ) {
                // Nothing to do
                assert(false);
            } else if (MF == 1 && MT == 455) {
                // Nothing to do
                assert(false);
            } else if (MF == 1 && MT == 458) {
                // Nothing to do
                assert(false);
            } else if (MF == 2 && MT == 151) {
                // Nothing to do
                assert(false);
            } else if (MF == 3) {
                // Nothing to do
                assert(false);
            } else if (MF == 4) {
                // Nothing to do
                assert(false);
            } else if (MF == 5) {
                // Nothing to do
                assert(false);
            } else if (MF == 6) {
                // Nothing to do
                assert(false);
            } else if (MF == 7) {
                // Nothing to do
                assert(false);
            } else if (MF == 8) {
                // Nothing to do
                assert(false);
            } else if (MF == 9) {
                // Nothing to do
                assert(false);
            } else if (MF ==10) {
                // Nothing to do
                assert(false);
            } else if (MF == 11) {
                // Nothing to do
                assert(false);
            } else if (MF == 12) {
                // Nothing to do
                assert(false);
            } else if (MF == 13) {
                // Nothing to do
                assert(false);
            } else if (MF == 14) {
                // Nothing to do
                assert(false);
            } else if (MF == 15) {
                // Nothing to do
                assert(false);
            } else if (MF == 23) {
                // Nothing to do
                assert(false);
            } else if (MF == 26) {
                // Nothing to do
                assert(false);
            } else if (MF == 27) {
                // Nothing to do
                assert(false);
            } else if (MF == 28) {
                // Nothing to do
                assert(false);
            } else if (MF == 30) {
                // Nothing to do
            } else if (MF == 31) {
                // Nothing to do
                assert(false);
            }
            
            ENDF::ReadLine(inFile, line);
            ENDF::ScanLine(line, MAT, MF, MT, NS);
            auto type = ENDF::GetRecordType(MAT, MF, MT, NS);
            if (type == ENDFControlRecordType::ENDF_NONE) {
                // Nothing to do
            } else if (type == ENDFControlRecordType::ENDF_SEND) {
                state = ENDFTapeReadState::ENDF_END_SECTION;
            } else {
                state = ENDFTapeReadState::ENDF_FINAL;
            }
        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }
        
    };
    
    auto SectionEndFunc = [&] () {
        
        try {
            std::cout<<"<<<<End SECTION"<<std::endl;
            ENDF::ReadLine(inFile, line);
            ENDF::ScanLine(line, MAT, MF, MT, NS);
            auto type = ENDF::GetRecordType(MAT, MF, MT, NS);
            if (type == ENDFControlRecordType::ENDF_NONE) {
                state = ENDFTapeReadState::ENDF_BEGIN_SECTION;
            } else if (type == ENDFControlRecordType::ENDF_FEND) {
                state = ENDFTapeReadState::ENDF_END_FILE;
            } else {
                state = ENDFTapeReadState::ENDF_FINAL;
            }
        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }

    };
    
    auto FileEndFunc = [&] () {
        try {
            std::cout<<"<<<<End FILE"<<std::endl;
            ENDF::ReadLine(inFile, line);
            ENDF::ScanLine(line, MAT, MF, MT, NS);
            auto type = ENDF::GetRecordType(MAT, MF, MT, NS);
            if (type == ENDFControlRecordType::ENDF_NONE) {
                state = ENDFTapeReadState::ENDF_BEGIN_FILE;
            } else if (type == ENDFControlRecordType::ENDF_MEND) {
                state = ENDFTapeReadState::ENDF_END_MAT;
            } else {
                state = ENDFTapeReadState::ENDF_FINAL;
            }
        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }
    };
    
    auto MatEndFunc = [&] () {
        
        try {
            std::cout<<"<<<<End MAT"<<std::endl;
            headerLocation = inFile.tellg();
            ENDF::ReadLine(inFile, line);
            ENDF::ScanLine(line, MAT, MF, MT, NS);
            auto type = ENDF::GetRecordType(MAT, MF, MT, NS);
            if (type == ENDFControlRecordType::ENDF_NONE) {
                state = ENDFTapeReadState::ENDF_BEGIN_MAT;
            } else if (type == ENDFControlRecordType::ENDF_TEND) {
                state = ENDFTapeReadState::ENDF_END_TAPE;
            } else {
                state = ENDFTapeReadState::ENDF_FINAL;
            }
        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }
    };
    
    auto TapeEndFunc = [&] () {
        try {
            std::cout<<"<<<<End TAPE"<<std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }
    };
    
    auto FinalFunc = [&] () {
        try {

        } catch (std::exception& e) {
            std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
            state = ENDFTapeReadState::ENDF_FINAL;
            successful = false;
        }
    };
    
    // Open file
    try {
        // Open the file
        inFile.open(endfFilepath, std::ios::in);
        
        // Check database file open
        if (!inFile.is_open()) {
            throw std::logic_error(" open ENDF file fails!");
        }
    } catch (std::exception& e) {
        std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
        state = ENDFTapeReadState::ENDF_FINAL;
        successful = false;
    }
    
    // File read state machine
    // All errors are captured internally
    while (state != ENDFTapeReadState::ENDF_FINAL) {
        switch (state) {
            case ENDFTapeReadState::ENDF_INIT:
            {
                InitFunc();
                break;
            }
            case ENDFTapeReadState::ENDF_BEGIN_TAPE:
            {
                TapeBeginFunc();
                break;
            }
            case ENDFTapeReadState::ENDF_BEGIN_MAT:
            {
                MatBeginFunc();
                break;
            }
            case ENDFTapeReadState::ENDF_BEGIN_FILE:
            {
                FileBeginFunc();
                break;
            }
            case ENDFTapeReadState::ENDF_BEGIN_SECTION:
            {
                SectionBeginFunc();
                break;
            }
            case ENDFTapeReadState::ENDF_READ_SECTION:
            {
                SectionReadFunc();
                break;
            }
            case ENDFTapeReadState::ENDF_END_SECTION:
            {
                SectionEndFunc();
                break;
            }
            case ENDFTapeReadState::ENDF_END_FILE:
            {
                FileEndFunc();
                break;
            }
            case ENDFTapeReadState::ENDF_END_MAT:
            {
                MatEndFunc();
                
                break;
            }
            case ENDFTapeReadState::ENDF_END_TAPE:
            {
                TapeEndFunc();
                break;
            }
            case ENDFTapeReadState::ENDF_FINAL:
            {
                FinalFunc();
                break;
            }
        }
    }
    
    return successful;
}

long NDLS::getEvaluationId
(long MAT,  long NLIB, long NVER, long LREL,
 long NSUB, long NMOD, long LDRV, double TEMP) {
    long EVALID=-1;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    rc = sqlite3_prepare_v2
    (db, R"(
     SELECT EVALID FROM Material_Table
     WHERE
     MAT =:MAT  AND NLIB=:NLIB AND NVER=:NVER AND LREL=:LREL AND
     NSUB=:NSUB AND NMOD=:NMOD AND LDRV=:LDRV AND TEMP=:TEMP
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return false;
    
    idx = sqlite3_bind_parameter_index(stmt, ":MAT");
    sqlite3_bind_int64(stmt, idx, MAT);
    
    idx = sqlite3_bind_parameter_index(stmt, ":NLIB");
    sqlite3_bind_int64(stmt, idx, NLIB);
    
    idx = sqlite3_bind_parameter_index(stmt, ":NVER");
    sqlite3_bind_int64(stmt, idx, NVER);
    
    idx = sqlite3_bind_parameter_index(stmt, ":LREL");
    sqlite3_bind_int64(stmt, idx, LREL);
    
    idx = sqlite3_bind_parameter_index(stmt, ":NSUB");
    sqlite3_bind_int64(stmt, idx, NSUB);
    
    idx = sqlite3_bind_parameter_index(stmt, ":NMOD");
    sqlite3_bind_int64(stmt, idx, NMOD);
    
    idx = sqlite3_bind_parameter_index(stmt, ":LDRV");
    sqlite3_bind_int64(stmt, idx, LDRV);
    
    idx = sqlite3_bind_parameter_index(stmt, ":TEMP");
    sqlite3_bind_double(stmt, idx, TEMP);
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    EVALID = sqlite3_column_int64(stmt, 0);
    
    sqlite3_finalize(stmt);
    
    return EVALID;
}

long NDLS::addMaterialTableEntry
(long MAT,  long NLIB, long NVER, long   LREL,
 long NSUB, long NMOD, long LDRV, double TEMP) {
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     INSERT INTO Material_Table
     ( EVALID, MAT, NLIB, NVER, LREL, NSUB, NMOD, LDRV, TEMP )
     VALUES
     ( (SELECT MAX (EVALID) FROM Material_Table) + 1,
      :MAT, :NLIB, :NVER, :LREL, :NSUB, :NMOD, :LDRV, :TEMP )
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return -1;
    
    idx = sqlite3_bind_parameter_index(stmt, ":MAT");
    sqlite3_bind_int64(stmt, idx, MAT);
    
    idx = sqlite3_bind_parameter_index(stmt, ":NLIB");
    sqlite3_bind_int64(stmt, idx, NLIB);
    
    idx = sqlite3_bind_parameter_index(stmt, ":NVER");
    sqlite3_bind_int64(stmt, idx, NVER);
    
    idx = sqlite3_bind_parameter_index(stmt, ":LREL");
    sqlite3_bind_int64(stmt, idx, LREL);
    
    idx = sqlite3_bind_parameter_index(stmt, ":NSUB");
    sqlite3_bind_int64(stmt, idx, NSUB);
    
    idx = sqlite3_bind_parameter_index(stmt, ":NMOD");
    sqlite3_bind_int64(stmt, idx, NMOD);
    
    idx = sqlite3_bind_parameter_index(stmt, ":LDRV");
    sqlite3_bind_int64(stmt, idx, LDRV);
    
    idx = sqlite3_bind_parameter_index(stmt, ":TEMP");
    sqlite3_bind_double(stmt, idx, TEMP);
    
    rc = sqlite3_step(stmt);
    if ( (rc != SQLITE_DONE)) return -1;
    // SQLITE_CONSTRAINT: data exist
    
    sqlite3_finalize(stmt);
    
    return getMaxEvaluationId();
}

long NDLS::getMaxEvaluationId() {
    long EVALID = -1;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    
    rc = sqlite3_prepare_v2
    (db, R"(SELECT MAX (EVALID) FROM Material_Table)"
     , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return -1;
    }
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    EVALID = sqlite3_column_int64(stmt, 0);
    
    sqlite3_finalize(stmt);
    
    return EVALID;
}

long NDLS::addDescriptionTableEntry
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
 const std::string& Description) {
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    rc = sqlite3_prepare_v2
    (db, R"(
     INSERT INTO Description_Table
     ( EVALID, ZSYMAM, ALAB, EDATE, AUTH, REF, DDATE, RDATE, ENDATE,
      HSUB, Summary, Description )
     VALUES
     ( :EVALID, :ZSYMAM, :ALAB, :EDATE, :AUTH, :REF, :DDATE, :RDATE,
      :ENDATE, :HSUB, :Summary, :Description )
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return -1;
    
    idx = sqlite3_bind_parameter_index(stmt, ":EVALID");
    sqlite3_bind_int64(stmt, idx, EVALID);
    
    idx = sqlite3_bind_parameter_index(stmt, ":ZSYMAM");
    sqlite3_bind_text
    (stmt, idx, ZSYMAM.data(), (int)ZSYMAM.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":ALAB");
    sqlite3_bind_text
    (stmt, idx, ALAB.data(), (int)ALAB.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":EDATE");
    sqlite3_bind_text
    (stmt, idx, EDATE.data(), (int)EDATE.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":AUTH");
    sqlite3_bind_text
    (stmt, idx, AUTH.data(), (int)AUTH.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":REF");
    sqlite3_bind_text
    (stmt, idx, REF.data(), (int)REF.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":DDATE");
    sqlite3_bind_text
    (stmt, idx, DDATE.data(), (int)DDATE.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":RDATE");
    sqlite3_bind_text
    (stmt, idx, RDATE.data(), (int)RDATE.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":ENDATE");
    sqlite3_bind_text
    (stmt, idx, ENDATE.data(), (int)ENDATE.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":HSUB");
    sqlite3_bind_text
    (stmt, idx, HSUB.data(), (int)HSUB.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":ZSYMAM");
    sqlite3_bind_text
    (stmt, idx, ZSYMAM.data(), (int)ZSYMAM.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":Summary");
    sqlite3_bind_text
    (stmt, idx, Summary.data(), (int)Summary.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":Description");
    sqlite3_bind_text
    (stmt, idx, Description.data(),
     (int)Description.length(), SQLITE_STATIC);
    
    rc = sqlite3_step(stmt);
    if ( (rc != SQLITE_DONE)) return -1;
    
    sqlite3_finalize(stmt);
    
    return EVALID;
}

long NDLS::addTypeTableEntry(long EVALID, long MF, long MT) {
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     INSERT INTO Type_Table
     ( EVALID, MF, MT )
     VALUES
     ( :EVALID, :MF, :MT )
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return -1;
    
    idx = sqlite3_bind_parameter_index(stmt, ":EVALID");
    sqlite3_bind_int64(stmt, idx, EVALID);
    
    idx = sqlite3_bind_parameter_index(stmt, ":MF");
    sqlite3_bind_int64(stmt, idx, MF);
    
    idx = sqlite3_bind_parameter_index(stmt, ":MT");
    sqlite3_bind_int64(stmt, idx, MT);
    
    rc = sqlite3_step(stmt);
    if ( (rc != SQLITE_DONE)) return -1;
    sqlite3_finalize(stmt);
    
    return getMaxTypeId();
}

long NDLS::getTypeId(long EVALID, long MF, long MT) {
    long TYPEID=-1;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     SELECT TYPEID FROM Type_Table
     WHERE
     EVALID =:EVALID  AND MF=:MF AND MT=:MT
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return false;
    
    idx = sqlite3_bind_parameter_index(stmt, ":EVALID");
    sqlite3_bind_int64(stmt, idx, EVALID);
    
    idx = sqlite3_bind_parameter_index(stmt, ":MF");
    sqlite3_bind_int64(stmt, idx, MF);
    
    idx = sqlite3_bind_parameter_index(stmt, ":MT");
    sqlite3_bind_int64(stmt, idx, MT);
    
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    TYPEID = sqlite3_column_int64(stmt, 0);
    
    sqlite3_finalize(stmt);
    
    return TYPEID;
}

long NDLS::getMaxTypeId() {
    long TYPEID = -1;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    
    rc = sqlite3_prepare_v2
    (db, R"(SELECT MAX (TYPEID) FROM Type_Table)"
     , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return -1;
    }
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    TYPEID = sqlite3_column_int64(stmt, 0);
    sqlite3_finalize(stmt);
    
    return TYPEID;
}

long NDLS::addHeaderTableEntry
(long TYPEID, const std::vector<double>& nums,
 long LVL, long IDX) {
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     INSERT INTO Header_Table
     ( TYPEID, C1, C2, L1, L2, N1, N2, LVL, IDX )
     VALUES
     ( :TYPEID, :C1, :C2, :L1, :L2, :N1, :N2, :LVL, :IDX )
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return -1;
    
    idx = sqlite3_bind_parameter_index(stmt, ":TYPEID");
    sqlite3_bind_int64(stmt, idx, TYPEID);
    
    idx = sqlite3_bind_parameter_index(stmt, ":C1");
    sqlite3_bind_double(stmt, idx, nums[0]);
    
    idx = sqlite3_bind_parameter_index(stmt, ":C2");
    sqlite3_bind_double(stmt, idx, nums[1]);
    
    idx = sqlite3_bind_parameter_index(stmt, ":L1");
    sqlite3_bind_double(stmt, idx, nums[2]);
    
    idx = sqlite3_bind_parameter_index(stmt, ":L2");
    sqlite3_bind_double(stmt, idx, nums[3]);
    
    idx = sqlite3_bind_parameter_index(stmt, ":N1");
    sqlite3_bind_double(stmt, idx, nums[4]);
    
    idx = sqlite3_bind_parameter_index(stmt, ":N2");
    sqlite3_bind_double(stmt, idx, nums[5]);
    
    idx = sqlite3_bind_parameter_index(stmt, ":LVL");
    sqlite3_bind_int64(stmt, idx, LVL);
    
    idx = sqlite3_bind_parameter_index(stmt, ":IDX");
    sqlite3_bind_int64(stmt, idx, IDX);
    
    rc = sqlite3_step(stmt);
    if ( (rc != SQLITE_DONE)) return -1;
    sqlite3_finalize(stmt);
    
    return getMaxRecordId();
}

long NDLS::getMaxRecordId() {
    long RECORDID = -1;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    
    rc = sqlite3_prepare_v2
    (db,
     R"(
     SELECT MAX (RECORDID) FROM Header_Table)"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return -1;
    }
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    RECORDID = sqlite3_column_int64(stmt, 0);
    sqlite3_finalize(stmt);
    
    return RECORDID;
}

long NDLS::addInheritanceTableEntry
(long PARENTID, long CHILDID) {
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     INSERT INTO Inheritance_Table
     ( PARENTID, CHILDID )
     VALUES
     ( :PARENTID, :CHILDID )
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return -1;
    
    idx = sqlite3_bind_parameter_index
    (stmt, ":PARENTID");
    sqlite3_bind_int64(stmt, idx, PARENTID);
    
    idx = sqlite3_bind_parameter_index
    (stmt, ":CHILDID");
    sqlite3_bind_int64(stmt, idx, CHILDID);
    
    rc = sqlite3_step(stmt);
    if ( (rc != SQLITE_DONE)) return -1;
    sqlite3_finalize(stmt);
    
    return getMaxInheritanceId();
}

long NDLS::getMaxInheritanceId() {
    long INHEREID        = -1;
    sqlite3_stmt *stmt = NULL;
    int rc             = -1;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     SELECT MAX (INHEREID) FROM Inheritance_Table)"
    , -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        return -1;
    }
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    INHEREID = sqlite3_column_int64(stmt, 0);
    sqlite3_finalize(stmt);
    
    return INHEREID;
}

long NDLS::addListTableEntry
(long RECORDID, const std::vector<double>& array) {
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     INSERT INTO List_Table
     ( RECORDID, B )
     VALUES
     ( :RECORDID, :B )
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return -1;
    
    idx = sqlite3_bind_parameter_index
    (stmt, ":RECORDID");
    sqlite3_bind_int64(stmt, idx, RECORDID);
    
    idx = sqlite3_bind_parameter_index
    (stmt, ":B");
    sqlite3_bind_blob
    (stmt, idx, array.data(),
     (int)array.size()*sizeof(double), SQLITE_STATIC);
    
    rc = sqlite3_step(stmt);
    if ( (rc != SQLITE_DONE)) return -1;
    
    sqlite3_finalize(stmt);
    
    return getMaxListId();
}

long NDLS::getMaxListId() {
    long LISTID = -1;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    
    rc = sqlite3_prepare_v2
    (db,
     R"(
     SELECT MAX (LISTID) FROM List_Table)"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return -1;
    }
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    LISTID = sqlite3_column_int64(stmt, 0);
    sqlite3_finalize(stmt);
    
    return LISTID;
}

long NDLS::addInterpolationTableEntry
(long RECORDID,
 const std::vector<long>& nbtArray,
 const std::vector<long>& intArray)
{
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     INSERT INTO Interpolation_Table
     ( RECORDID, INT, NBT )
     VALUES
     ( :RECORDID, :INT, :NBT )
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return -1;
    
    idx = sqlite3_bind_parameter_index
    (stmt, ":RECORDID");
    sqlite3_bind_int64
    (stmt, idx, RECORDID);
    
    idx = sqlite3_bind_parameter_index
    (stmt, ":INT");
    sqlite3_bind_blob
    (stmt, idx, intArray.data(),
     (int)intArray.size()*sizeof(long), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index
    (stmt, ":NBT");
    sqlite3_bind_blob
    (stmt, idx, nbtArray.data(),
     (int)nbtArray.size()*sizeof(long), SQLITE_STATIC);
    
    rc = sqlite3_step(stmt);
    if ( (rc != SQLITE_DONE)) return -1;
    sqlite3_finalize(stmt);
    
    return getMaxInterpolationId();
}

long NDLS::getMaxInterpolationId()
{
    long INTERPID = -1;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    
    rc = sqlite3_prepare_v2
    (db,
     R"(
     SELECT MAX (INTERPID) FROM Interpolation_Table)"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return -1;
    }
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    INTERPID = sqlite3_column_int64(stmt, 0);
    sqlite3_finalize(stmt);
    
    return INTERPID;
}

long NDLS::addFunctionTableEntry
(long RECORDID,
 const std::vector<double>& xArray,
 const std::vector<double>& yArray) {
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     INSERT INTO Function_Table
     ( RECORDID, X, Y )
     VALUES
     ( :RECORDID, :X, :Y )
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return -1;
    
    idx = sqlite3_bind_parameter_index(stmt, ":RECORDID");
    sqlite3_bind_int64(stmt, idx, RECORDID);
    
    idx = sqlite3_bind_parameter_index(stmt, ":X");
    sqlite3_bind_blob
    (stmt, idx, xArray.data(),
     (int)xArray.size()*sizeof(double), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":Y");
    sqlite3_bind_blob
    (stmt, idx, yArray.data(),
     (int)yArray.size()*sizeof(double), SQLITE_STATIC);
    
    rc = sqlite3_step(stmt);
    if ( (rc != SQLITE_DONE)) return -1;
    sqlite3_finalize(stmt);
    
    return getMaxFunctionId();
}

long NDLS::getMaxFunctionId() {
    long FUNCID        = -1;
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     SELECT MAX (FUNCID) FROM Function_Table)"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return -1;
    }
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    FUNCID = sqlite3_column_int64(stmt, 0);
    sqlite3_finalize(stmt);
    
    return FUNCID;
}

std::vector<ENDFMaterialHeader>
NDLS::getLibraryMaterialHeaders
(std::function<bool(long,long,long)> filter) {
    std::vector<ENDFMaterialHeader> libInfo;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    long nid           = -1;
    std::string columnName;
    rc = sqlite3_prepare_v2
    (db, R"(
     SELECT * FROM Material_Table
     )"
    , -1, &stmt, NULL);
    if (rc != SQLITE_OK) return libInfo;
    
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW ) {
        ENDFMaterialHeader info;
        
        //Obtain number of columns
        nid = sqlite3_column_count(stmt);
        
        //Loop over columns
        for (idx = 0; idx < nid; idx++) {
            //Extract column name
            columnName = sqlite3_column_name(stmt, idx);
            
            if (columnName == "MAT") {
                info.MAT  = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "NLIB") {
                info.NLIB = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "NVER") {
                info.NVER = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "LREL") {
                info.LREL = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "NSUB") {
                info.NSUB = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "NMOD") {
                info.NMOD = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "LDRV") {
                info.LDRV = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "TEMP") {
                info.TEMP = sqlite3_column_double(stmt, idx);
            }
        }
        
        libInfo.push_back(info);
    }
    
    if (rc != SQLITE_DONE) {
        libInfo.clear();
        return libInfo;
    }
    
    sqlite3_finalize(stmt);
    
    // Filter the seleted functions
    for (auto iter=libInfo.begin(); iter!=libInfo.end(); ) {
        if (!filter(iter->NLIB, iter->NVER, iter->LREL)) {
            iter = libInfo.erase(iter);
        } else {
            iter ++;
        }
    }
    
    return libInfo;
}

std::vector<ENDFMaterialHeader> NDLS::getMaterialHeaders
(long MAT, std::function<bool(long,long,long)> filter) {
    
    std::vector<ENDFMaterialHeader> libInfo;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    long nid           = -1;
    std::string columnName;
    rc = sqlite3_prepare_v2
    (db, R"(
     SELECT * FROM Material_Table
     WHERE
     MAT =:MAT
     )"
    , -1, &stmt, NULL);
    if (rc != SQLITE_OK) return libInfo;
    
    idx = sqlite3_bind_parameter_index(stmt, ":MAT");
    sqlite3_bind_int64(stmt, idx, MAT);
    
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW ) {
        ENDFMaterialHeader info;
        
        //Obtain number of columns
        nid = sqlite3_column_count(stmt);
        
        //Loop over columns
        for (idx = 0; idx < nid; idx++) {
            //Extract column name
            columnName = sqlite3_column_name(stmt, idx);
            
            if (columnName == "MAT") {
                info.MAT  = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "NLIB") {
                info.NLIB = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "NVER") {
                info.NVER = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "LREL") {
                info.LREL = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "NSUB") {
                info.NSUB = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "NMOD") {
                info.NMOD = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "LDRV") {
                info.LDRV = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "TEMP") {
                info.TEMP = sqlite3_column_double(stmt, idx);
            }
        }
        
        libInfo.push_back(info);
    }
    
    if (rc != SQLITE_DONE) {
        libInfo.clear();
        return libInfo;
    }
    
    sqlite3_finalize(stmt);
    
    // Filter the seleted functions
    for (auto iter=libInfo.begin(); iter!=libInfo.end(); ) {
        if (!filter(iter->NLIB, iter->NVER, iter->LREL)) {
            iter = libInfo.erase(iter);
        } else {
            iter ++;
        }
    }
    std::sort
    (libInfo.begin(), libInfo.end(),
     [](ENDFMaterialHeader& m1, ENDFMaterialHeader& m2)
     {
         if (m1.NLIB != m2.NLIB) {
             return (m1.NLIB < m2.NLIB);
         }
         if (m1.NVER != m2.NVER) {
             return (m1.NVER > m2.NVER);
         }
         if (m1.LREL != m2.LREL) {
             return (m1.LREL > m2.LREL);
         }
         if (m1.NMOD != m2.NMOD) {
             return (m1.NMOD > m2.NMOD);
         }
         if (m1.LDRV != m2.LDRV) {
             return (m1.LDRV > m2.LDRV);
         }
         
         return true;
     });
    
    return libInfo;
}

std::vector<ENDFSectionHeader> NDLS::getSectionHeaders(long EVALID, long MF) {
    std::vector<ENDFSectionHeader> headers;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    long nid           = -1;
    std::string columnName;
    rc = sqlite3_prepare_v2
    (db, R"(
     SELECT TYPEID,MT FROM Type_Table
     WHERE
     EVALID =:EVALID AND MF =:MF
     )"
    , -1, &stmt, NULL);
    if (rc != SQLITE_OK) return headers;
    
    idx = sqlite3_bind_parameter_index(stmt, ":EVALID");
    sqlite3_bind_int64(stmt, idx, EVALID);
    
    idx = sqlite3_bind_parameter_index(stmt, ":MF");
    sqlite3_bind_int64(stmt, idx, MF);
    
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW ) {
        ENDFSectionHeader header;
        
        //Obtain number of columns
        nid = sqlite3_column_count(stmt);
        
        //Loop over columns
        for (idx = 0; idx < nid; idx++) {
            //Extract column name
            columnName = sqlite3_column_name(stmt, idx);
            
            if (columnName == "TYPEID") {
                header.TYPEID = sqlite3_column_int64(stmt, idx);
            } else if (columnName == "MT") {
                header.MT  = sqlite3_column_int64(stmt, idx);
            }
        }
        
        headers.push_back(header);
    }
    
    if (rc != SQLITE_DONE) {
        headers.clear();
        return headers;
    }
    
    sqlite3_finalize(stmt);
    
    for (auto& header : headers) {
        // Get the only header record id
        rc = sqlite3_prepare_v2
        (db,
         R"(
         SELECT RECORDID FROM Header_Table
         WHERE
         TYPEID =:TYPEID AND LVL = 0
         )"
        , -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            headers.clear();
            return headers;
        }
        
        idx = sqlite3_bind_parameter_index(stmt, ":TYPEID");
        sqlite3_bind_int64(stmt, idx, header.TYPEID);
        
        if ( sqlite3_step(stmt) == SQLITE_ROW) {
            header.RECORDID = sqlite3_column_int64(stmt, 0);
        }
        
        if ( sqlite3_step(stmt) != SQLITE_DONE) {
            headers.clear();
            return headers;
        }
        
        sqlite3_finalize(stmt);
    }
    
    return headers;
}

ENDFSectionHeader NDLS::getSectionHeader(long EVALID, long MF, long MT) {
    auto headers = getSectionHeaders(EVALID, MF);
    
    for (auto& h : headers) {
        if (h.MT == MT) {
            return h;
        }
    }
    
    return ENDFSectionHeader();
}

std::vector<long> NDLS::getChildrenId(long PARENTID) {
    std::vector<long> childrenId;
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    std::string columnName;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     SELECT CHILDID FROM Inheritance_Table
     WHERE
     PARENTID =:PARENTID
     )"
    , -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        throw std::logic_error("Get children id error!");
    }
    
    idx = sqlite3_bind_parameter_index(stmt, ":PARENTID");
    sqlite3_bind_int64(stmt, idx, PARENTID);
    
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        childrenId.push_back(sqlite3_column_int64(stmt, 0));
    }
    
    if (rc != SQLITE_DONE) {
        childrenId.clear();
        throw std::logic_error("Get children id error!");
    }
    
    return childrenId;
}

ENDFNeutronData* NDLS::getNeutronDataByHeader(const ENDFMaterialHeader& hmat) {
    
    ENDFNeutronData *ndata = nullptr;
    long EVALID = -1;
    
    // Processing functions
    auto getDescriptionData = [&,this] () {
        
        // The temperature in Kalvin
        ndata->tempK = hmat.TEMP;
        
    };
    
    auto getDataFromFile1 = [&,this] () {
        
        // Section 451
        auto hmt    = getSectionHeader(EVALID, 1, 451);
        if (!hmt.valid()) {
            throw std::logic_error("No file 1 section 451!");
        }
        auto header = getHeader(hmt.RECORDID);
        long ZA     = header.C1;
        double AWR  = header.C2;
        long LRP    = header.L1;
        long LFI    = header.L2;
        long NLIB   = header.N1;
        long NMOD   = header.N2;
        
        // Write the ZA number to description data
        ndata->ZA   = ZA;
        
        // Write the AWR to description data
        ndata->AWR  = AWR;
        
        // Section 452, total yield
        if (LFI == 1) {
            auto hmt = getSectionHeader(EVALID, 1, 452);
            if (!hmt.valid()) {
                throw std::logic_error("No file 1 section 452 for fission mat!");
            }
            auto header = getHeader(hmt.RECORDID);
            auto childrenId = getChildrenId(hmt.RECORDID);
            long childId = childrenId.front();
            
            auto& total = ndata->fissionYield.total;
            total = new ENDFNeutronData::YieldFunction;
            long LNU = header.L2;
            if (LNU == 1) {
                auto list = getList(childId);
                total->polyFunc.coefficents = list.array;
                total->type = decltype(total->type)::POLYNOMIAL;
            } else if (LNU == 2) {
                auto tab1 = getTab1(childId);
                if(!total->interpFunc.init
                   (std::move(tab1.interp), std::move(tab1.data))) {
                    throw std::logic_error("init lin. interp. error!");
                }
                total->type = decltype(total->type)::INTERPOLATION;
            }
        }
        
        // Section 455, delayed yield
        if (LFI == 1) {
            auto hmt = getSectionHeader(EVALID, 1, 455);
            if (hmt.valid()) {
                auto header = getHeader(hmt.RECORDID);
                auto childrenId = getChildrenId(hmt.RECORDID);
                if (childrenId.size() != 2) {
                    throw std::logic_error("children records number error!");
                }
                
                long LDG = header.L1;
                long LNU = header.L2;
                
                auto& delayed = ndata->fissionYield.delayed;
                delayed = new ENDFNeutronData::YieldFunction;
                if (LDG == 0) {
                    auto list = getList(childrenId[0]);
                    auto& p = ndata->fissionYield.energyIndependentPrecursors;
                    long NNF = list.array.size();
                    p.precursors.resize(NNF);
                    for (long i=0; i<NNF; i++) {
                        p.precursors[i].decayConst = list.array[i];
                    }
                    ndata->fissionYield.isPrecursorEnergyDependent = false;
                } else if (LDG == 1) {
                    auto tab2list =  getTab2List(childrenId[0]);
                    auto& p = ndata->fissionYield.energyDependentPrecursors;
                    if(!p.init(std::move(tab2list.interp))) {
                        throw std::logic_error("init interp. func. error!");
                    }
                    long NE = tab2list.data.size();
                    if(p.data().size() != NE) {
                        throw std::logic_error("interp dim. error!");
                    }
                    for (long i=0; i<NE; i++) {
                        auto& list = tab2list.data[i].y;
                        auto& d = p.data(i);
                        d.x = tab2list.data[i].x;
                        long NNF = list.array.size()/2;
                        d.y.precursors.resize(NNF);
                        for (long j=0; j<NNF; j++) {
                            d.y.precursors[j].decayConst = list.array[j*2];
                            d.y.precursors[j].groupAbundance = list.array[j*2+1];
                        }
                    }
                    ndata->fissionYield.isPrecursorEnergyDependent = true;
                } else {
                    throw std::logic_error("unsupportted LDG flag!");
                }
                if (LNU == 1) {
                    auto list = getList(childrenId[1]);
                    delayed->polyFunc.coefficents = std::move(list.array);
                    delayed->type = decltype(delayed->type)::POLYNOMIAL;
                } else if (LNU == 2) {
                    auto tab1 = getTab1(childrenId[1]);
                    if (!delayed->interpFunc.init
                        (std::move(tab1.interp), std::move(tab1.data))) {
                        throw std::logic_error("init interp. func. error!");
                    }
                    delayed->type = decltype(delayed->type)::INTERPOLATION;
                } else {
                    throw std::logic_error("unsupportted LNU flag!");
                }
            }
        }
        
        // Section 456, prompt yield
        if (LFI == 1) {
            auto hmt = getSectionHeader(EVALID, 1, 456);
            if (hmt.valid()) {
                auto header = getHeader(hmt.RECORDID);
                auto childrenId = getChildrenId(hmt.RECORDID);
                long childId = childrenId.front();
                
                auto& prompt = ndata->fissionYield.prompt;
                prompt = new ENDFNeutronData::YieldFunction;
                if (header.L2 == 1) {
                    auto list = getList(childId);
                    prompt->polyFunc.coefficents = list.array;
                    prompt->type = decltype(prompt->type)::POLYNOMIAL;
                } else if (header.L2 == 2) {
                    auto tab1 = getTab1(childId);
                    if (!prompt->interpFunc.init
                        (std::move(tab1.interp), std::move(tab1.data))) {
                        throw std::logic_error("init interp. func. error!");
                    }
                    prompt->type = decltype(prompt->type)::INTERPOLATION;
                }
            }
        }
    };
    
    auto readResonanceFile2LRU0 =
    [this] (ENDFNeutronData::Resonance::Range& range, long rangeChildId) {
        auto propertyChildrenId = getChildrenId(rangeChildId);
        // No resonance data
        if (range.NRO == 0) {
            // Energy independent AP
            auto propertyHeader1 = getHeader(propertyChildrenId[0]);
            range.SPI = propertyHeader1.C1;
            range.AP  = propertyHeader1.C2;
        } else if (range.NRO == 1) {
            // Energy dependent AP
            auto tab1 = getTab1(propertyChildrenId[0]);
            if (!range.APE.init
                (std::move(tab1.interp), std::move(tab1.data))) {
                throw std::logic_error("init interp. func. error!");
            }
        }
    };
    
    auto readResonanceFile2LRU1LRF1And2 =
    [this] (ENDFNeutronData::Resonance::Range& range, long rangeChildId) {
        auto propertyChildrenId = getChildrenId(rangeChildId);
        long idx = 0;
        if (range.NRO != 0) {
            // Energy dependent AP
            auto tab1 = getTab1(propertyChildrenId[idx++]);
            if (!range.APE.init
                (std::move(tab1.interp), std::move(tab1.data))) {
                throw std::logic_error("init interp. func. error!");
            }
        }
        auto header = getHeader(propertyChildrenId[idx++]);
        range.SPI = header.C1;
        if (range.NRO != 0 && (range.NAPS == 0 || range.NAPS == 1)) {
            range.AP = 0.;
        } else {
            range.AP = header.C2;
        }
        long NLS = header.N1;
        range.moments.resize(NLS);
        auto momentumChildrenId = getChildrenId(propertyChildrenId[idx-1]);
        
        for (long l=0; l<NLS; l++) {
            auto list = getList(momentumChildrenId[l]);
            auto& momentum = range.moments[l];
            momentum.AWRI = list.header.C1;
            momentum.QX   = list.header.C2;
            momentum.L    = list.header.L1;
            momentum.LRX  = list.header.L2;
            long NRS      = list.header.N2;
            momentum.BWTables.resize(NRS);
            
            for (long r=0; r<NRS; r++) {
                auto& table = momentum.BWTables[r];
                table.ER = list.array[6*r];
                table.AJ = list.array[6*r+1];
                table.GT = list.array[6*r+2];
                table.GN = list.array[6*r+3];
                table.GG = list.array[6*r+4];
                table.GF = list.array[6*r+5];
            }
        }
    };
    
    auto readResonanceFile2LRU1LRF3 =
    [this] (ENDFNeutronData::Resonance::Range& range, long rangeChildId) {
        auto propertyChildrenId = getChildrenId(rangeChildId);
        long idx = 0;
        if (range.NRO != 0) {
            // Energy dependent AP
            auto tab1 = getTab1(propertyChildrenId[idx++]);
            if (!range.APE.init
                (std::move(tab1.interp), std::move(tab1.data))) {
                throw std::logic_error("init interp. func. error!");
            }
        }
        auto header = getHeader(propertyChildrenId[idx++]);
        range.SPI  = header.C1;
        range.AP   = header.C2;
        range.LAD  = header.L1;
        range.NLSC = header.N2;
        long NLS = header.N1;
        range.moments.resize(NLS);
        auto momentumChildrenId = getChildrenId(propertyChildrenId[idx-1]);
        
        for (long l=0; l<NLS; l++) {
            auto list = getList(momentumChildrenId[l]);
            auto& momentum = range.moments[l];
            momentum.AWRI = list.header.C1;
            momentum.APL  = list.header.C2;
            momentum.L    = list.header.L1;
            long NRS      = list.header.N2;
            momentum.RMTables.resize(NRS);
            
            for (long r=0; r<NRS; r++) {
                auto& table = momentum.RMTables[r];
                table.ER  = list.array[6*r];
                table.AJ  = list.array[6*r+1];
                table.GN  = list.array[6*r+2];
                table.GG  = list.array[6*r+3];
                table.GFA = list.array[6*r+4];
                table.GFB = list.array[6*r+5];
            }
        }
    };
    
    auto readResonanceFile2LRU1LRF4 =
    [this] (ENDFNeutronData::Resonance::Range& range, long rangeChildId) {
        auto propertyChildrenId = getChildrenId(rangeChildId);
        
    };
    
    auto readResonanceFile2LRU1LRF7 =
    [this] (ENDFNeutronData::Resonance::Range& range, long rangeChildId) {
        auto propertyChildrenId = getChildrenId(rangeChildId);
        
    };
    
    auto readResonanceFile2LRU1 =
    [&,this] (ENDFNeutronData::Resonance::Range& range, long rangeChildId) {
        if (range.LRF == 1 || range.LRF == 2) {
            // SLBW and MLBW representation
            readResonanceFile2LRU1LRF1And2(range, rangeChildId);
        } else if (range.LRF == 3) {
            // Reich-Moore representation
            readResonanceFile2LRU1LRF3(range, rangeChildId);
        } else if (range.LRF == 4) {
            // Adler-Adler representation
            readResonanceFile2LRU1LRF4(range, rangeChildId);
        } else if (range.LRF == 7) {
            // R-matrix limited represnetation
            readResonanceFile2LRU1LRF7(range, rangeChildId);
        } else {
            throw std::logic_error("unknown range representation!");
        }
    };
    
    auto readResonanceFile2LRU2 =
    [&,this] (ENDFNeutronData::Resonance::Range& range, long rangeChildId) {
        
    };
    
    auto getDataFromFile2 = [&,this] () {
        
        // Read file 151
        auto hmt = getSectionHeader(EVALID, 2, 151);
        if (!hmt.valid()) {
            throw std::logic_error("No file 2 section 151!");
        }
        auto header = getHeader(hmt.RECORDID);
        long NIS = header.N1;
        auto isotopeChildrenId = getChildrenId(hmt.RECORDID);
        ndata->resonances.resize(NIS);
        
        for (long is=0; is<NIS; is++) {
            auto isotopeHeader = getHeader(isotopeChildrenId[is]);
            long NER = isotopeHeader.N1;
            auto& resonance = ndata->resonances[is];
            resonance.ZAI = isotopeHeader.C1;
            resonance.ABN = isotopeHeader.C2;
            resonance.LFW = isotopeHeader.L2;
            resonance.ranges.resize(NER);
            auto rangeChildrenId = getChildrenId(isotopeChildrenId[is]);
            
            for (long er=0; er<NER; er++) {
                auto rangeHeader = getHeader(rangeChildrenId[er]);
                auto& range = resonance.ranges[er];
                range.EL   = rangeHeader.C1;
                range.EH   = rangeHeader.C2;
                range.LRU  = rangeHeader.L1;
                range.LRF  = rangeHeader.L2;
                range.NRO  = rangeHeader.N1;
                range.NAPS = rangeHeader.N2;
                
                if (range.LRU == 0) {
                    readResonanceFile2LRU0(range, rangeChildrenId[er]);
                } else if (range.LRU == 1) {
                    readResonanceFile2LRU1(range, rangeChildrenId[er]);
                } else if (range.LRU == 2) {
                    readResonanceFile2LRU2(range, rangeChildrenId[er]);
                }
            }
        }
        
    };
    
    auto getDataFromFile3 = [&,this] () {
        
        auto hmts = getSectionHeaders(EVALID, 3);
        ndata->reactions.resize(hmts.size());
        for (long i=0; i<hmts.size(); i++) {
            auto& hmt = hmts[i];
            auto header = getHeader(hmt.RECORDID);
            auto childrenId = getChildrenId(hmt.RECORDID);
            long childId = childrenId.front();
            auto tab1 = getTab1(childId).eliminateDuplicatedZeros();
            
            auto& reaction = ndata->reactions[i];
            reaction.MT = hmt.MT;
            reaction.QM = tab1.header.C1;
            reaction.QI = tab1.header.C2;
            reaction.LR = tab1.header.L2;
            if (!reaction.xsec.init
                (std::move(tab1.interp), std::move(tab1.data))) {
                throw std::logic_error("init interp. func. error!");
            }
        }
        
    };
    
    auto getDataFromFile4 = [&,this] () {
        
        auto hmts = getSectionHeaders(EVALID, 4);
        ndata->angularDists.resize(hmts.size());
        for (long i=0; i<hmts.size(); i++) {
            auto& hmt = hmts[i];
            auto header = getHeader(hmt.RECORDID);
            long LTT = header.L2;
            auto childrenId = getChildrenId(hmt.RECORDID);
            long idx = 0;
            auto info = getHeader(childrenId[idx++]);
            long LI  = info.L1;
            long LCT = info.L2;
            
            auto& angularDist = ndata->angularDists[i];
            angularDist.MT = hmt.MT;
            if (LCT == 1) {
                angularDist.system = ENDFSpaceSystem::LAB;
            } else if (LCT == 2) {
                angularDist.system = ENDFSpaceSystem::CM;
            } else {
                throw std::logic_error("unknown space system!");
            }
            
            if (LTT == 0 && LI == 1) {
                angularDist.type =
                ENDFNeutronData::AngularDist::Type::ISOTROPIC;
            } else if (LTT == 1 && LI == 0) {
                auto tab2list = getTab2List(childrenId[idx++]);
                angularDist.type =
                ENDFNeutronData::AngularDist::Type::LEGENDRE;
                auto& lfunc2 = angularDist.legendFunc2;
                if(!lfunc2.init(std::move(tab2list.interp))) {
                    throw std::logic_error("init interp. func. error!");
                }
                long NE = tab2list.header.N2;
                if(lfunc2.data().size() != NE) {
                    throw std::logic_error("interp dim. error!");
                }
                for (long i=0; i<NE; i++) {
                    auto& objto = lfunc2.data(i);
                    auto& objfrom = tab2list.data[i];
                    objto.x = objfrom.x;
                    objto.y.coefficents = objfrom.y.array;
                }
            } else if (LTT == 2 && LI == 0) {
                auto tab2tab1 = getTab2Tab1(childrenId[idx++]);
                angularDist.type =
                ENDFNeutronData::AngularDist::Type::TABULATED;
                auto& ifunc2 = angularDist.interpFunc2;
                if(!ifunc2.init(std::move(tab2tab1.interp))) {
                    throw std::logic_error("init interp. func. error!");
                }
                long NE = tab2tab1.header.N2;
                if(ifunc2.data().size() != NE) {
                    throw std::logic_error("interp dim. error!");
                }
                for (long i=0; i<NE; i++) {
                    auto& objto = ifunc2.data(i);
                    auto& objfrom = tab2tab1.data[i];
                    objto.x = objfrom.x;
                    if (!objto.y.init
                        (std::move(objfrom.y.interp),
                         std::move(objfrom.y.data)))
                    {
                        throw std::logic_error("init interp. func. error!");
                    }
                }
            } else if (LTT == 3 && LI == 0) {
                auto tab2list = getTab2List(childrenId[idx++]);
                auto tab2tab1 = getTab2Tab1(childrenId[idx++]);
                angularDist.type =
                ENDFNeutronData::AngularDist::Type::MIXED;
                // Legendre representation
                auto& lfunc2 = angularDist.legendFunc2;
                if(!lfunc2.init(std::move(tab2list.interp))) {
                    throw std::logic_error("init interp. func. error!");
                }
                long NE1 = tab2list.header.N2;
                if(lfunc2.data().size() != NE1) {
                    throw std::logic_error("interp dim. error!");
                }
                for (long i=0; i<NE1; i++) {
                    auto& objto = lfunc2.data(i);
                    auto& objfrom = tab2list.data[i];
                    objto.x = objfrom.x;
                    objto.y.coefficents = objfrom.y.array;
                }
                // Tabular representation
                auto& ifunc2 = angularDist.interpFunc2;
                if(!ifunc2.init(std::move(tab2tab1.interp))) {
                    throw std::logic_error("init interp. func. error!");
                }
                long NE2 = tab2tab1.header.N2;
                if(ifunc2.data().size() != NE2) {
                    throw std::logic_error("interp dim. error!");
                }
                for (long i=0; i<NE2; i++) {
                    auto& objto = ifunc2.data(i);
                    auto& objfrom = tab2tab1.data[i];
                    objto.x = objfrom.x;
                    if (!objto.y.init
                        (std::move(objfrom.y.interp),
                         std::move(objfrom.y.data)))
                    {
                        throw std::logic_error("init interp. func. error!");
                    }
                }
            } else {
                throw std::logic_error("unknown angular format!");
            }
        }
        
    };
    
    auto getDataFromFile5 = [&,this] () {
        
        auto hmts = getSectionHeaders(EVALID, 5);
        ndata->energyDists.resize(hmts.size());
        for (long i=0; i<hmts.size(); i++) {
            auto& hmt = hmts[i];
            auto header = getHeader(hmt.RECORDID);
            long NK = header.N1;
            auto childrenId = getChildrenId(hmt.RECORDID);
            
            auto& energyDist = ndata->energyDists[i];
            energyDist.MT = hmt.MT;
            energyDist.partialDists.resize(NK);
            
            for (long j=0; j<NK; j++) {
                auto& partial = energyDist.partialDists[j];
                auto childId = childrenId[j];
                auto tab1_0 = getTab1(childId);
                long LF = tab1_0.header.L2;
                if (!partial.validity.init
                    (std::move(tab1_0.interp),
                     std::move(tab1_0.data)))
                {
                    throw std::logic_error("init interp. func. error!");
                }
                auto lawChildrenId = getChildrenId(childId);
                long idx = 0;
                if (LF == 1) {
                    partial.law = ENDFNeutronData::EnergyDist::Law::LAW1;
                    auto tab2tab1 = getTab2Tab1(lawChildrenId[idx++]);
                    if (!ENDFInterpIsLinearLinear(tab2tab1.interp)) {
                        std::cerr<<("Warning: File 5 LF = 1, linear-linear func expected!")
                        <<std::endl;
                    }
                    if(!partial.law1.table.init(std::move(tab2tab1.interp))) {
                        throw std::logic_error("init interp. func. error!");
                    }
                    if(partial.law1.table.data().size() !=
                       tab2tab1.data.size()) {
                        throw std::logic_error("interp dim. error!");
                    }
                    for (long i=0; i<tab2tab1.data.size(); i++) {
                        auto& objto = partial.law1.table.data(i);
                        auto& objfrom = tab2tab1.data[i];
                        // A hot fix
                        if (objfrom.y.interp.size() == 1 &&
                            objfrom.y.interp.front().NBT !=
                            objfrom.y.data.size()) {
                            objfrom.y.interp.front().NBT =
                            (long)objfrom.y.data.size();
                            std::cout<<"Warning: tab1 hot fix applied!"<<std::endl;
                        }
                        objto.x = objfrom.x;
                        auto tab1 = objfrom.y.eliminateDuplicatedZeros();
                        if (!objto.y.init
                            (std::move(tab1.interp), std::move(tab1.data))) {
                            throw std::logic_error
                            ("init interp. func. error!");
                        }
                        
//                        if (!ENDFInterpIsLinearLinear(tab1.interp)) {
//                            throw std::logic_error
//                            ("linear-linear func expected!");
//                        }
//                        if (!objto.y.init
//                            (std::move(tab1.data),
//                             ENDFTabularDistributionType::LINEAR_LINEAR))
//                        {
//                            throw std::logic_error
//                            ("init tab dist. error!");
//                        }
                    }
                } else if (LF == 5) {
                    partial.law = ENDFNeutronData::EnergyDist::Law::LAW5;
                    auto tab1_1 = getTab1(lawChildrenId[idx++]).
                    eliminateDuplicatedZeros();
                    auto tab1_2 = getTab1(lawChildrenId[idx++]).
                    eliminateDuplicatedZeros();
                    if (!partial.law5.theta.init
                        (std::move(tab1_1.interp),
                         std::move(tab1_1.data)))
                    {
                        throw std::logic_error("init interp. func. error!");
                    }
                    if (!partial.law5.g.init
                        (std::move(tab1_2.interp),
                         std::move(tab1_2.data)))
                    {
                        throw std::logic_error("init interp. func. error!");
                    }
                    partial.law5.U = tab1_0.header.C1;
                } else if (LF == 7) {
                    partial.law = ENDFNeutronData::EnergyDist::Law::LAW7;
                    auto tab1_1 = getTab1(lawChildrenId[idx++]).
                    eliminateDuplicatedZeros();
                    if (!partial.law7.theta.init
                        (std::move(tab1_1.interp),
                         std::move(tab1_1.data)))
                    {
                        throw std::logic_error("init interp. func. error!");
                    }
                    partial.law7.U = tab1_0.header.C1;
                } else if (LF == 9) {
                    partial.law = ENDFNeutronData::EnergyDist::Law::LAW9;
                    auto tab1_1 = getTab1(lawChildrenId[idx++]).
                    eliminateDuplicatedZeros();
                    if (!partial.law9.theta.init
                        (std::move(tab1_1.interp),
                         std::move(tab1_1.data)))
                    {
                        throw std::logic_error("init interp. func. error!");
                    }
                    partial.law9.U = tab1_0.header.C1;
                } else if (LF == 11) {
                    partial.law = ENDFNeutronData::EnergyDist::Law::LAW11;
                    auto tab1_1 = getTab1(lawChildrenId[idx++]).
                    eliminateDuplicatedZeros();
                    auto tab1_2 = getTab1(lawChildrenId[idx++]).
                    eliminateDuplicatedZeros();
                    if (!partial.law11.a.init
                        (std::move(tab1_1.interp),
                         std::move(tab1_1.data)))
                    {
                        throw std::logic_error("init interp. func. error!");
                    }
                    if (!partial.law11.b.init
                        (std::move(tab1_2.interp),
                         std::move(tab1_2.data)))
                    {
                        throw std::logic_error("init interp. func. error!");
                    }
                    partial.law11.U = tab1_0.header.C1;
                } else if (LF == 12) {
                    partial.law = ENDFNeutronData::EnergyDist::Law::LAW12;
                    auto tab1_1 = getTab1(lawChildrenId[idx++]).
                    eliminateDuplicatedZeros();
                    if (!partial.law12.TM.init
                        (std::move(tab1_1.interp),
                         std::move(tab1_1.data)))
                    {
                        throw std::logic_error("init interp. func. error!");
                    }
                    partial.law12.EFL = tab1_1.header.C1;
                    partial.law12.EFH = tab1_1.header.C2;
                } else {
                    throw std::logic_error("unknown energy distribution law!");
                }
            }
            
        }
        
    };
    
    auto getDataFromFile6 = [&,this] () {
        
        auto hmts = getSectionHeaders(EVALID, 6);
        ndata->energyAngularDists.resize(hmts.size());
        for (long i=0; i<hmts.size(); i++) {
            auto& hmt = hmts[i];
            auto header = getHeader(hmt.RECORDID);
            long NK = header.N1;
            long LCT = header.L2;
            auto childrenId = getChildrenId(hmt.RECORDID);
            
            auto& energyAngleDist = ndata->energyAngularDists[i];
            energyAngleDist.MT = hmt.MT;
            energyAngleDist.products.resize(NK);
            
            for (long k=0; k<NK; k++) {
                auto& product = energyAngleDist.products[k];
                auto childId = childrenId[k];
                auto tab1_0 = getTab1(childId);
                product.ZAP = tab1_0.header.C1;
                product.AWP = tab1_0.header.C2;
                product.LIP = tab1_0.header.L1;
                // Calculate product scattering system
                // based on LCT and ZAP
                if (LCT == 1) {
                    product.system = ENDFSpaceSystem::LAB;
                } else if (LCT == 2) {
                    product.system = ENDFSpaceSystem::CM;
                } else if (LCT == 3) {
                    long ZA = product.ZAP;
                    if (ZA < 1000 || ZA%1000 <= 4 ) {
                        product.system = ENDFSpaceSystem::CM;
                    } else {
                        product.system = ENDFSpaceSystem::LAB;
                    }
                } else {
                    throw std::logic_error("invalid space system!");
                }
                long LAW = tab1_0.header.L2;
                if (!product.yield.init
                    (std::move(tab1_0.interp),
                     std::move(tab1_0.data)))
                {
                    throw std::logic_error("init interp. func. error!");
                }
                auto lawChildrenId = getChildrenId(childId);
                long idx = 0;
                if (LAW == 0) {
                    product.law =
                    ENDFNeutronData::EnergyAngularDist::Law::LAW0;
                    // Nothing to do
                } else if (LAW == 1) {
                    product.law =
                    ENDFNeutronData::EnergyAngularDist::Law::LAW1;
                    auto tab2list = getTab2List(lawChildrenId[idx++]);
                    long LANG = tab2list.header.L1;
                    long LEP  = tab2list.header.L2;
                    if (LEP != 1 && LEP != 2) {
                        throw std::logic_error("invalid interp law!");
                    }
                    auto& ld = product.law1;
                    if (LANG == 1) {
                        // Legendre representation
                        ld.type = ENDFNeutronData::EnergyAngularDist::
                        Law1Data::Type::LEGENDRE;
                        auto& func = ld.legendreFunc2;
                        if(!func.init(std::move(tab2list.interp))) {
                            throw std::logic_error("init interp. func. error!");
                        }
                        if(func.data().size() != tab2list.data.size()) {
                            throw std::logic_error("interp dim. error!");
                        }
                        for (long i=0; i<tab2list.data.size(); i++) {
                            auto& objfrom = tab2list.data[i];
                            auto& objto = func.data(i);
                            objto.x = objfrom.x;
                            long ND = objfrom.y.header.L1;
                            long NA = objfrom.y.header.L2;
                            long NEP = objfrom.y.header.N2;
                            // Create x-pdf pairs
                            std::vector< ENDFDataPoint > data(NEP-ND);
                            for (long j=ND; j<NEP; j++) {
                                long offset = j*(NA+2);
                                data[j-ND].x = objfrom.y.array[offset];
                                data[j-ND].y = objfrom.y.array[offset+1];
                            }
                            // Create tab. dist. type
                            ENDFTabularDistributionType type;
                            if (LEP == 1) {
                                type = ENDFTabularDistributionType::HISTGRAM;
                            } else if (LEP == 2) {
                                type = ENDFTabularDistributionType::LINEAR_LINEAR;
                            } else {
                                throw std::logic_error
                                ("unknown tab. dist. type!");
                            }
                            
                            // Special procedure for data empty
                            
                            // Check normalization
                            // Do not check normalization if ND > 0
                            // Special approach provided later
                            if (ND > 0) {
                                std::cout<<"Warning: ND not empty, norm. not checked!"<<std::endl;
                            } else {
                                if (!ENDFCheckNormalization(data, type)) {
                                    throw std::logic_error
                                    ("tab. dist. check normaliation fail!");
                                }
                            }
                            
                            // Initialize
                            if (!objto.y.init(data, type)) {
                                throw std::logic_error
                                ("init tab. dist. error!");
                            }
                            objto.y.info().ND = ND;
                            
                            for (long j=ND; j<NEP; j++) {
                                long offset = j*(NA+2);
                                // The first item in the array is
                                // normalization factor
                                double f0 = objfrom.y.array[offset+1];
                                auto& content = objto.y.content(j-ND);
                                content.coefficents.resize(NA);
                                for (long k=1; k<=NA; k++) {
                                    content.coefficents[k-1] =
                                    (f0 == 0.) ? (0.) :
                                    (objfrom.y.array[offset+k+1] / f0);
                                }
                            }
                        }
                    } else if (LANG == 2) {
                        // Kalbach-Mann representation
                        ld.type = ENDFNeutronData::EnergyAngularDist::
                        Law1Data::Type::KALBACHMANN;
                        auto& func = ld.kalbachFunc2;
                        if(!func.init(std::move(tab2list.interp))) {
                            throw std::logic_error("init interp. func. error!");
                        }
                        if(func.data().size() != tab2list.data.size()) {
                            throw std::logic_error("interp dim. error!");
                        }
                        for (long i=0; i<tab2list.data.size(); i++) {
                            auto& objfrom = tab2list.data[i];
                            auto& objto = func.data(i);
                            objto.x = objfrom.x;
                            long ND = objfrom.y.header.L1;
                            long NA = objfrom.y.header.L2;
                            long NEP = objfrom.y.header.N2;
                            // Create x-pdf pairs
                            std::vector< ENDFDataPoint > data(NEP);
                            for (long j=0; j<NEP; j++) {
                                long offset = j*(NA+2);
                                data[j].x = objfrom.y.array[offset];
                                data[j].y = objfrom.y.array[offset+1];
                            }
                            // Create tab. dist. type
                            ENDFTabularDistributionType type;
                            if (LEP == 1) {
                                type = ENDFTabularDistributionType::HISTGRAM;
                            } else if (LEP == 2) {
                                type = ENDFTabularDistributionType::LINEAR_LINEAR;
                            } else {
                                throw std::logic_error
                                ("unknown tab. dist. type!");
                            }
                            // Check normalization
                            if (!ENDFCheckNormalization(data, type)) {
                                throw std::logic_error
                                ("tab. dist. check normaliation fail!");
                            }
                            // Initialize
                            if (!objto.y.init(data, type)) {
                                throw std::logic_error
                                ("init tab. dist. error!");
                            }
                            objto.y.info().ND = ND;
                            
                            for (long j=0; j<NEP; j++) {
                                long offset = j*(NA+2);
                                // The first item in the array is
                                // normalization factor
                                auto& content = objto.y.content(j);
                                if (NA == 1) {
                                    content.r = objfrom.y.array[offset+2];
                                } else if (NA == 2) {
                                    content.r = objfrom.y.array[offset+2];
                                    content.r = objfrom.y.array[offset+3];
                                } else {
                                    throw std::logic_error
                                    ("invalid NA for Kalbach!");
                                }
                            }
                        }
                    } else if (11 <= LANG && LANG <= 15) {
                        // Tabular representation
                        // The way to store data point needs revise
                        ld.type = ENDFNeutronData::EnergyAngularDist::
                        Law1Data::Type::TABULAR;
                        long law = LANG - 10;
                        auto& func = ld.tabularFunc2;
                        if(!func.init(std::move(tab2list.interp))) {
                            throw std::logic_error("init interp. func. error!");
                        }
                        if(func.data().size() != tab2list.data.size()) {
                            throw std::logic_error("interp dim. error!");
                        }
                        for (long i=0; i<tab2list.data.size(); i++) {
                            auto& objfrom = tab2list.data[i];
                            auto& objto = func.data(i);
                            objto.x = objfrom.x;
                            long ND = objfrom.y.header.L1;
                            long NA = objfrom.y.header.L2;
                            long NEP = objfrom.y.header.N2;
                            // Create x-pdf pairs
                            std::vector< ENDFDataPoint > data(NEP);
                            for (long j=0; j<NEP; j++) {
                                long offset = j*(NA+2);
                                data[j].x = objfrom.y.array[offset];
                                data[j].y = objfrom.y.array[offset+1];
                            }
                            // Create tab. dist. type
                            ENDFTabularDistributionType type;
                            if (LEP == 1) {
                                type = ENDFTabularDistributionType::HISTGRAM;
                            } else if (LEP == 2) {
                                type = ENDFTabularDistributionType::LINEAR_LINEAR;
                            } else {
                                throw std::logic_error
                                ("unknown tab. dist. type!");
                            }
                            // Check normalization
                            if (!ENDFCheckNormalization(data, type)) {
                                throw std::logic_error
                                ("tab. dist. check normaliation fail!");
                            }
                            // Initialize
                            if (!objto.y.init(data, type)) {
                                throw std::logic_error
                                ("init tab. dist. error!");
                            }
                            objto.y.info().ND = ND;
                            
                            for (long j=0; j<NEP; j++) {
                                long offset = j*(NA+2);
                                // The first item in the array is
                                // normalization factor
                                auto& content = objto.y.content(j);
                                
                                // Create temporary tabular data array
                                std::vector< ENDFDataPoint > tabdata;
                                
                                // Create tabular type variable
                                ENDFTabularDistributionType tabtype;
                                
                                // Obtain tabular type
                                if (law == 1) {
                                    tabtype = ENDFTabularDistributionType::
                                    HISTGRAM;
                                } else if (law == 2) {
                                    tabtype = ENDFTabularDistributionType::
                                    LINEAR_LINEAR;
                                } else if (law == 4) {
                                    tabtype = ENDFTabularDistributionType::
                                    LINEAR_LOG;
                                } else {
                                    throw std::logic_error
                                    ("law not supported!");
                                }
                                
                                // Obtain tab data
                                tabdata.resize(NA/2);
                                for (long k=0; k<NA/2; k++) {
                                    auto mu = objfrom.y.array[offset+2+2*k];
                                    // rn = 0.5*fn/f0
                                    auto r  = objfrom.y.array[offset+3+2*k];
                                    tabdata[k].x = mu;
                                    tabdata[k].y = r;
                                }
                                
                                // Check normalization
                                if(!ENDFCheckNormalization
                                   (tabdata, tabtype)) {
                                    throw std::logic_error
                                    ("tab data not normalized!");
                                }
                                
                                // Initialize
                                if (!content.init(tabdata, tabtype)) {
                                    throw std::logic_error
                                    ("init tab. dist. error!");
                                }
                            }
                        }
                    } else {
                        throw std::logic_error("unsupported LANG!");
                    }
                } else if (LAW == 2) {
                    product.law =
                    ENDFNeutronData::EnergyAngularDist::Law::LAW2;
                    auto tab2list = getTab2List(lawChildrenId[idx++]);
                    auto& func = product.law2.probFunc;
                    if(!func.init(std::move(tab2list.interp))) {
                        throw std::logic_error("init interp. func. error!");
                    }
                    long NE = tab2list.data.size();
                    if(func.data().size() != NE) {
                        throw std::logic_error("interp dim. error!");
                    }
                    for (long i=0; i<NE; i++) {
                        auto& objfrom = tab2list.data[i];
                        auto& objto = func.data(i);
                        objto.x = objfrom.x;
                        long LANG = objfrom.y.header.L1;
                        long NL = objfrom.y.header.N2;
                        if (LANG == 0) {
                            objto.y.type =
                            decltype(objto.y.type)::LEGENDRE;
                            auto& c = objto.y.legendre.coefficents;
                            c.resize(NL+1);
                            c[0] = 1.;
                            for (long i=0; i<NL; i++) {
                                c[i+1] = objfrom.y.array[i];
                            }
                        } else if (LANG == 12) {
                            // Set distribution type
                            objto.y.type =
                            decltype(objto.y.type)::TABULAR;
                            
                            // Obtain tab type
                            auto tabtype =
                            ENDFTabularDistributionType::LINEAR_LINEAR;
                            
                            // Obtain tab data
                            std::vector< ENDFDataPoint > tabdata;
                            
                            tabdata.resize(NL);
                            for (long i=0; i<NL; i++) {
                                tabdata[i].x = objfrom.y.array[2*i];
                                tabdata[i].y = objfrom.y.array[2*i+1];
                            }
                            
                            // Check normalization
                            if(!ENDFCheckNormalization
                               (tabdata, tabtype)) {
                                throw std::logic_error
                                ("tab data not normalized!");
                            }
                            
                            // Initialize
                            if (!objto.y.tabular.init(tabdata, tabtype)) {
                                throw std::logic_error
                                ("init tab. dist. error!");
                            }
                        } else if (LANG == 14) {
                            // Set distribution type
                            objto.y.type =
                            decltype(objto.y.type)::TABULAR;
                            
                            // Obtain tab type
                            auto tabtype =
                            ENDFTabularDistributionType::LINEAR_LOG;
                            
                            // Obtain tab data
                            std::vector< ENDFDataPoint > tabdata;
                            
                            tabdata.resize(NL);
                            for (long i=0; i<NL; i++) {
                                tabdata[i].x = objfrom.y.array[2*i];
                                tabdata[i].y = objfrom.y.array[2*i+1];
                            }
                            
                            // Check normalization
                            if(!ENDFCheckNormalization
                               (tabdata, tabtype)) {
                                throw std::logic_error
                                ("tab data not normalized!");
                            }
                            
                            // Initialize
                            if (!objto.y.tabular.init
                                (tabdata, tabtype)) {
                                throw std::logic_error
                                ("init tab. dist. error!");
                            }
                        } else {
                            throw std::logic_error("unknown LANG!");
                        }
                    }
                } else if (LAW == 3) {
                    product.law =
                    ENDFNeutronData::EnergyAngularDist::Law::LAW3;
                    // No law-dependent data
                } else if (LAW == 4) {
                    product.law =
                    ENDFNeutronData::EnergyAngularDist::Law::LAW4;
                    // No law-dependent data
                } else if (LAW == 5) {
                    product.law =
                    ENDFNeutronData::EnergyAngularDist::Law::LAW5;
                    auto tab2list = getTab2List(lawChildrenId[idx++]);
                    product.law5.SPIN = tab2list.header.C1;
                    product.law5.LIDP = tab2list.header.L1;
                    auto& params = product.law5.params;
                    if(!params.init(std::move(tab2list.interp))) {
                        throw std::logic_error("init interp. func. error!");
                    }
                    long NE = tab2list.data.size();
                    if(params.data().size() != NE) {
                        throw std::logic_error("interp dim. error!");
                    }
                    for (long i=0; i<NE; i++) {
                        auto& objfrom = tab2list.data[i];
                        auto& objto   = params.data(i);
                        objto.x = objfrom.x;
                        long LTP = objfrom.y.header.L1;
                        long NL  = objfrom.y.header.N2;
                        if (LTP == 1) {
                            objto.y.type =
                            ENDFNeutronData::EnergyAngularDist::
                            Law5Data::Type::AMPLITUDE;
                            objto.y.a.coefficients.resize(NL+1);
                            for (long j=0; j<NL+1; j++) {
                                objto.y.a.coefficients[j].real
                                (objfrom.y.array[2*NL+1+2*j]);
                                objto.y.a.coefficients[j].imag
                                (objfrom.y.array[2*NL+2+2*j]);
                            }
                            objto.y.b.distribution.
                            coefficents.resize(2*NL);
                            objto.y.b.f0 = objfrom.y.array[0];
                            for (long j=0; j<2*NL; j++) {
                                objto.y.b.distribution.
                                coefficents[j] = objfrom.y.array[j+1];
                            }
                        } else if (LTP == 2) {
                            objto.y.type =
                            ENDFNeutronData::EnergyAngularDist::
                            Law5Data::Type::RESIDUAL;
                            objto.y.c.distribution.
                            coefficents.resize(NL);
                            objto.y.b.f0 = objfrom.y.array[0];
                            for (long j=0; j<NL; j++) {
                                objto.y.c.distribution.
                                coefficents[j] = objfrom.y.array[j+1];
                            }
                        } else if (LTP == 12 || LTP == 14 || LTP == 15) {
                            objto.y.type =
                            ENDFNeutronData::EnergyAngularDist::
                            Law5Data::Type::INTERFERENCE;
                            if (!objto.y.p.init(NL, LTP-10)) {
                                throw std::logic_error
                                ("init interp. func. error!");
                            }
                            for (long j=0; j<NL; j++) {
                                objto.y.p.data(j).x = objfrom.y.array[2*j];
                                objto.y.p.data(j).y = objfrom.y.array[2*j+1];
                            }
                        } else {
                            throw std::logic_error("unknown LTP!");
                        }
                    }
                } else if (LAW == 6) {
                    product.law =
                    ENDFNeutronData::EnergyAngularDist::Law::LAW6;
                    auto cont = getHeader(lawChildrenId[idx++]);
                    auto& ld = product.law6;
                    ld.APSX = cont.C1;
                    ld.NPSX = cont.N2;
                } else if (LAW == 7) {
                    product.law =
                    ENDFNeutronData::EnergyAngularDist::Law::LAW7;
                    auto tab2tab2tab1 = getTab2Tab2Tab1(lawChildrenId[idx++]);
                    auto& ld = product.law7;
                    
                    if(!ld.f.init(std::move(tab2tab2tab1.interp))) {
                        throw std::logic_error("init interp. func. error!");
                    }
                    long NE = tab2tab2tab1.data.size();
                    if(ld.f.data().size() != NE) {
                        throw std::logic_error("interp dim. error!");
                    }
                    for (long i=0; i<NE; i++) {
                        ld.f.data(i).x = tab2tab2tab1.data[i].x;
                        long NMU = tab2tab2tab1.data[i].y.data.size();
                        if(!ld.f.data(i).y.init
                           (std::move(tab2tab2tab1.data[i].y.interp))) {
                            throw std::logic_error("init interp. func. error!");
                        }
                        if(ld.f.data(i).y.data().size() != NMU) {
                            throw std::logic_error("interp dim. error!");
                        }
                        for (long j=0; j<NMU; j++) {
                            ld.f.data(i).y.data(j).x =
                            tab2tab2tab1.data[i].y.data[j].x;
                            if (!ld.f.data(i).y.data(j).y.init
                                (std::move
                                 (tab2tab2tab1.data[i].y.data[j].y.interp),
                                 std::move
                                 (tab2tab2tab1.data[i].y.data[j].y.data)))
                            {
                                throw std::logic_error
                                ("init interp. func. error!");
                            }
                        }
                    }
                } else {
                    throw std::logic_error("unknown energy-angle law!");
                }
            }
        }
    };
    
    auto getDataFromFile8Section454 = [&,this] () {
        auto hmt = getSectionHeader(EVALID, 8, 454);
        if (!hmt.valid()) {
            return;
        }
        auto header = getHeader(hmt.RECORDID);
        long LE = header.L1;
        auto childrenId = getChildrenId(hmt.RECORDID);
        auto& fp = ndata->fissionYield.independentFissionProducts;
        
        std::vector< ENDFInterpLaw > interp;
        std::vector< ENDFObjectDataPoint
        <ENDFNeutronData::Yield::FissionProducts> > data;
        
        data.resize(LE+1);
        for (long e=0; e<LE+1; e++) {
            auto list = getList(childrenId[e]);
            auto& d = data[e];
            d.x = list.header.C1;
            long NFP = list.header.N2;
            d.y.fissionProducts.resize(NFP);
            for (long i=0; i<NFP; i++) {
                d.y.fissionProducts[i].ZAFP = list.array[4*i];
                d.y.fissionProducts[i].FPS  = list.array[4*i+1];
                d.y.fissionProducts[i].Y    = list.array[4*i+2];
                d.y.fissionProducts[i].DY   = list.array[4*i+3];
            }
            if (e > 0) {
                // Provide interpolation rules
                long I = list.header.L1;
                interp.emplace_back(I, e+1);
            }
        }
        
        if (!fp.init(interp, data)) {
            throw std::logic_error
            ("init interp. func. error!");
        }
        
    };
    
    auto getDataFromFile8Section459 = [&,this] () {
        auto hmt = getSectionHeader(EVALID, 8, 459);
        if (!hmt.valid()) {
            return;
        }
        auto header = getHeader(hmt.RECORDID);
        long LE = header.L1;
        auto childrenId = getChildrenId(hmt.RECORDID);
        auto& fp = ndata->fissionYield.cummulativeFissionProducts;
        
        std::vector< ENDFInterpLaw > interp;
        std::vector< ENDFObjectDataPoint
        <ENDFNeutronData::Yield::FissionProducts> > data;
        
        data.resize(LE+1);
        for (long e=0; e<LE+1; e++) {
            auto list = getList(childrenId[e]);
            auto& d = data[e];
            d.x = list.header.C1;
            long NFP = list.header.N2;
            d.y.fissionProducts.resize(NFP);
            for (long i=0; i<NFP; i++) {
                d.y.fissionProducts[i].ZAFP = list.array[4*i];
                d.y.fissionProducts[i].FPS  = list.array[4*i+1];
                d.y.fissionProducts[i].Y    = list.array[4*i+2];
                d.y.fissionProducts[i].DY   = list.array[4*i+3];
            }
            if (e > 0) {
                // Provide interpolation rules
                long I = list.header.L1;
                interp.emplace_back(I, e+1);
            }
        }
        
        if (!fp.init(interp, data)) {
            throw std::logic_error
            ("init interp. func. error!");
        }
        
    };
    
    auto getDataFromFile8 = [&,this] () {
        
        // Read Section 454
        getDataFromFile8Section454();
        
        // Read Section 459
        getDataFromFile8Section459();
        
    };
    
    try {
        
        // Get EVALID
        EVALID = getEvaluationId
        (hmat.MAT, hmat.NLIB, hmat.NVER, hmat.LREL,
         hmat.NSUB, hmat.NMOD, hmat.LDRV, hmat.TEMP);
        
        if (EVALID == -1) {
            throw std::logic_error("Unable to get EVALID!");
        }
        
        // Allocate memory for neutron data
        ndata = new ENDFNeutronData;
        if (ndata == nullptr) {
            throw std::logic_error
            ("No enough memory for allocating neutron data!");
        }
        
        // Read description data
        getDescriptionData();
        
        // Read file 1
        getDataFromFile1();
        
        // Read file 2
        getDataFromFile2();
        
        // Read file 3
        getDataFromFile3();
        
        // Read file 4
        getDataFromFile4();
        
        // Read file 5
        getDataFromFile5();
        
        // Read file 6
        getDataFromFile6();
        
        // Read file 8
        getDataFromFile8();
        
        
    } catch (std::exception& e) {
        std::cerr << "[NDLS]: error msg - " << e.what() << std::endl;
        if (ndata != nullptr) {
            delete ndata;
            ndata = nullptr;
        }
    }
    
    return ndata;
}

ENDFNeutronData* NDLS::getNeutronData
(long MAT, std::function<bool(long,long,long)> filter) {
    
    ENDFNeutronData* ndata = nullptr;
    auto hmats = getMaterialHeaders(MAT, filter);
    
    try {
        // Remove all NSUB not equal to 10
        for (auto iter=hmats.begin(); iter!=hmats.end(); ) {
            if (iter->NSUB != 10) {
                iter = hmats.erase(iter);
            } else {
                iter ++;
            }
        }
        
        // Check empty
        if (hmats.empty()) {
            throw std::logic_error("no material header!");
        }
        
        ndata = getNeutronDataByHeader(hmats.front());
        if (ndata == nullptr) {
            throw std::logic_error("unable to fetch ndata by header!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[NDLS]: error msg " << e.what() << std::endl;
        if (ndata != nullptr) {
            delete ndata;
            ndata = nullptr;
        }
    }
    
    return ndata;
}

ENDFHeader NDLS::getHeader(long RECORDID) {
    ENDFHeader header;
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    int nid            = -1;
    std::string columnName;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     SELECT * FROM Header_Table
     WHERE
     RECORDID =:RECORDID
     )"
    , -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        throw std::logic_error("unable to get header!");
    }
    
    idx = sqlite3_bind_parameter_index(stmt, ":RECORDID");
    sqlite3_bind_int64(stmt, idx, RECORDID);
    
    if ( sqlite3_step(stmt) == SQLITE_ROW) {
        nid = sqlite3_column_count(stmt);
        
        for (idx = 0; idx < nid; idx++) {
            columnName = sqlite3_column_name(stmt, idx);
            
            if (columnName == "C1") {
                header.C1 = sqlite3_column_double(stmt, idx);
            } else if (columnName == "C2") {
                header.C2 = sqlite3_column_double(stmt, idx);
            } else if (columnName == "L1") {
                header.L1 = sqlite3_column_double(stmt, idx);
            } else if (columnName == "L2") {
                header.L2 = sqlite3_column_double(stmt, idx);
            } else if (columnName == "N1") {
                header.N1 = sqlite3_column_double(stmt, idx);
            } else if (columnName == "N2") {
                header.N2 = sqlite3_column_double(stmt, idx);
            }
        }
    }
    
    if ( sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::logic_error("errors happen during read header!");
    }
    
    sqlite3_finalize(stmt);
    
    return header;
}

ENDFList NDLS::getList(long RECORDID) {
    ENDFList list;
    std::vector<long> childrenId;
    sqlite3_stmt *stmt  = NULL;
    int rc              = -1;
    int idx             = -1;
    int buf_len         = -1;
    const void* buf_ptr = nullptr;
    
    list.header = getHeader(RECORDID);
    childrenId  = getChildrenId(RECORDID);
    
    rc = sqlite3_prepare_v2
    (db,
     R"(
     SELECT B FROM List_Table
     WHERE
     RECORDID=:RECORDID
     )"
    , -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        throw std::logic_error("retrieve list error!");
    }
    
    idx = sqlite3_bind_parameter_index(stmt, ":RECORDID");
    sqlite3_bind_int64(stmt, idx, RECORDID);
    
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        buf_len = sqlite3_column_bytes(stmt, 0);
        buf_ptr = sqlite3_column_blob(stmt, 0);
        
        list.array.resize(buf_len/sizeof(double), 0);
        std::copy_n
        ((char*)buf_ptr, buf_len, (char*)list.array.data());
    } else {
        throw std::logic_error("retrieve list error!");
    }
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::logic_error("retrieve list error!");
    }
    
    sqlite3_finalize(stmt);
    
    return list;
}

std::vector<ENDFInterpLaw> NDLS::getInterpolation(long RECORDID) {
    std::vector<long> NBT, INT;
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    int nid            = -1;
    const void* buf_ptr= nullptr;
    int buf_len        = 0;
    std::string columnName;
    rc = sqlite3_prepare_v2
    (db,
     R"(
     SELECT INT, NBT FROM Interpolation_Table
     WHERE
     RECORDID =:RECORDID
     )"
    , -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        throw std::logic_error("retrieve intepolation error!");
    }
    
    idx = sqlite3_bind_parameter_index(stmt, ":RECORDID");
    sqlite3_bind_int64(stmt, idx, RECORDID);
    
    if ( sqlite3_step(stmt) == SQLITE_ROW) {
        nid = sqlite3_column_count(stmt);
        
        for (idx = 0; idx < nid; idx++) {
            columnName = sqlite3_column_name(stmt, idx);
            
            if (columnName == "INT") {
                buf_len = sqlite3_column_bytes(stmt, idx);
                buf_ptr = sqlite3_column_blob(stmt, idx);
                
                INT.resize(buf_len/sizeof(long), 0);
                std::copy_n
                ((char*)buf_ptr, buf_len, (char*)INT.data());
                
            } else if (columnName == "NBT") {
                buf_len = sqlite3_column_bytes(stmt, idx);
                buf_ptr = sqlite3_column_blob(stmt, idx);
                
                NBT.resize(buf_len/sizeof(long), 0);
                std::copy_n
                ((char*)buf_ptr, buf_len, (char*)NBT.data());
            }
        }
    }
    
    if ( sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::logic_error("retrieve intepolation error!");
    }
    
    if (NBT.size() != INT.size()) {
        throw std::logic_error("INT-NBT size not match");
    }
    
    sqlite3_finalize(stmt);
    
    std::vector<ENDFInterpLaw> interp;
    interp.resize(INT.size());
    for (long i=0; i<INT.size(); i++) {
        interp[i].NBT = NBT[i];
        interp[i].INT = INT[i];
    }
    
    return interp;
}

std::vector<ENDFDataPoint> NDLS::getFunction(long RECORDID) {
    std::vector<double> xData, yData;
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    int nid            = -1;
    const void* buf_ptr= nullptr;
    int buf_len        = 0;
    std::string columnName;
    rc = sqlite3_prepare_v2
    (db, R"(
     SELECT X,Y FROM Function_Table
     WHERE
     RECORDID =:RECORDID
     )"
    , -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        throw std::logic_error("get function error!");
    }
    
    idx = sqlite3_bind_parameter_index(stmt, ":RECORDID");
    sqlite3_bind_int64(stmt, idx, RECORDID);
    
    if ( sqlite3_step(stmt) == SQLITE_ROW) {
        nid = sqlite3_column_count(stmt);
        
        for (idx = 0; idx < nid; idx++) {
            columnName = sqlite3_column_name(stmt, idx);
            
            if (columnName == "X") {
                buf_len = sqlite3_column_bytes(stmt, idx);
                buf_ptr = sqlite3_column_blob(stmt, idx);
                
                xData.resize(buf_len/sizeof(double), 0);
                std::copy_n
                ((char*)buf_ptr, buf_len, (char*)xData.data());
                
            } else if (columnName == "Y") {
                buf_len = sqlite3_column_bytes(stmt, idx);
                buf_ptr = sqlite3_column_blob(stmt, idx);
                
                yData.resize(buf_len/sizeof(double), 0);
                std::copy_n
                ((char*)buf_ptr, buf_len, (char*)yData.data());
            }
        }
    }
    
    if ( sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::logic_error("get function error!");
    }
    
    sqlite3_finalize(stmt);
    
    std::vector<ENDFDataPoint> data;
    
    if (xData.size() != yData.size()) {
        throw std::logic_error("x-y data size not match!");
    }
    
    data.resize(xData.size());
    for (long i=0; i<xData.size(); i++) {
        data[i].x = xData[i];
        data[i].y = yData[i];
    }
    
    return data;
}

ENDFTab1 NDLS::getTab1(long RECORDID) {
    ENDFTab1 tab;
    
    tab.header = getHeader(RECORDID);
    tab.interp = getInterpolation(RECORDID);
    tab.data   = getFunction(RECORDID);
    
    return tab;
}

ENDFTab2List NDLS::getTab2List(long RECORDID) {
    ENDFTab2List tab2list;
    
    tab2list.header = getHeader(RECORDID);
    tab2list.interp = getInterpolation(RECORDID);
    
    auto childrenId = getChildrenId(RECORDID);
    tab2list.data.resize(childrenId.size());
    for (long i=0; i<childrenId.size(); i++) {
        long childId = childrenId[i];
        auto list = getList(childId);
        tab2list.data[i].x = list.header.C2;
        tab2list.data[i].y = list;
    }
    
    return tab2list;
}

ENDFTab2Tab1 NDLS::getTab2Tab1(long RECORDID) {
    ENDFTab2Tab1 tab2tab1;
    
    tab2tab1.header = getHeader(RECORDID);
    tab2tab1.interp = getInterpolation(RECORDID);
    
    auto childrenId = getChildrenId(RECORDID);
    tab2tab1.data.resize(childrenId.size());
    for (long i=0; i<childrenId.size(); i++) {
        long childId = childrenId[i];
        auto tab1 = getTab1(childId);
        tab2tab1.data[i].x = tab1.header.C2;
        tab2tab1.data[i].y = tab1;
    }
    
    return tab2tab1;
}

ENDFTab2Tab2Tab1 NDLS::getTab2Tab2Tab1(long RECORDID) {
    ENDFTab2Tab2Tab1 tab2tab2tab1;
    
    tab2tab2tab1.header = getHeader(RECORDID);
    tab2tab2tab1.interp = getInterpolation(RECORDID);
    
    auto childrenId = getChildrenId(RECORDID);
    tab2tab2tab1.data.resize(childrenId.size());
    for (long i=0; i<childrenId.size(); i++) {
        long childId = childrenId[i];
        auto tab2tab1 = getTab2Tab1(childId);
        auto& d = tab2tab2tab1.data[i];
        d.x = tab2tab1.header.C2;
        d.y = tab2tab1;
    }
    
    return tab2tab2tab1;
}

void NDLS::iterateOverMaterials
(std::function<void
 (const ENDFMaterialHeader& hmt,
  ENDFNeutronData* ndata)> operation,
 std::function<bool(long,long,long)> filter) {
    
    try {
        
        if (!isReady()) {
            throw std::logic_error("library not ready!");
        }
        
        auto hmts = getLibraryMaterialHeaders();
        
        for (auto& hmt : hmts) {
            if (!filter(hmt.NLIB,hmt.NVER,hmt.LREL)) {
                continue;
            }
            if (hmt.NSUB == 10) {
                auto ndata = getNeutronDataByHeader(hmt);
                if (ndata != nullptr) {
                    operation(hmt, ndata);
                    delete ndata;
                } else {
                    throw std::logic_error
                    ("unable to get neutron data by header!");
                }
            }
        }
        
    } catch (std::exception& e) {
        // Print a db error msg as well
        std::cerr << "[sqlite]: " << sqlite3_errmsg(db) << std::endl;
        std::cerr << "[NDLS]: error msg - " << e.what() << std::endl;
        return;
    }
    
}

//} // End of namespace ibhe
//} // End of namespace com
