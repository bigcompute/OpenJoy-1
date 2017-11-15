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

#include "ADLS.hpp"
#include "ACE.hpp"
#include "IO.hpp"

#include <map>
#include <set>

//namespace com {
//namespace ibhe {

ADLS::ADLS(const std::string& dbFilepath) {
    open(dbFilepath);
}

ADLS::~ADLS() {
    close();
}

bool ADLS::maintainSchema() {
    
    // Check whether database is open
    if (db == nullptr) {
        std::cout << "[ADLS]: database is not open!" << std::endl;
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
         (
          TABLEID     INTEGER NOT NULL,
          NAME        TEXT    NOT NULL,
          LIBRARY     TEXT    NOT NULL,
          TEMPMEV     REAL    NOT NULL,
          AWR         REAL    NOT NULL,
          DESCRIPTION TEXT    NOT NULL,
          NXS         BLOB    NOT NULL,
          JXS         BLOB    NOT NULL,
          XSS         BLOB    NOT NULL,
          PRIMARY KEY (TABLEID),
          UNIQUE(NAME, LIBRARY)
         )
        )"
        , -1, &stmt, nullptr);
        if (rc != SQLITE_OK)   return false;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) return false;
        sqlite3_finalize(stmt);
    }
    
    return true;
}

bool ADLS::isReady() const {
    return db != nullptr;
}

long ADLS::getTableID
(const std::string& name,
 const std::string& lib) {
    
    long TABLEID=-1;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    
    rc = sqlite3_prepare_v2
    (db, R"(
     SELECT TABLEID FROM Material_Table
     WHERE NAME =:NAME AND LIBRARY=:LIBRARY
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return -1;
    
    idx = sqlite3_bind_parameter_index(stmt, ":NAME");
    sqlite3_bind_text
    (stmt, idx, name.data(), (int)name.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":LIBRARY");
    sqlite3_bind_text
    (stmt, idx, lib.data(), (int)lib.length(), SQLITE_STATIC);
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    TABLEID = sqlite3_column_int64(stmt, 0);
    
    sqlite3_finalize(stmt);
    
    return TABLEID;
}

// Add a new material table entry
// Return the TABLEID for the table entry
// Rerurn -1 if table entry already exist
long ADLS::addMaterialTableEntry
(const ACETable& table) {
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    int idx            = -1;
    
    rc = sqlite3_prepare_v2
    (db,
     R"(
     INSERT INTO Material_Table
     ( TABLEID, NAME, LIBRARY, TEMPMEV, AWR, DESCRIPTION, NXS, JXS, XSS )
     VALUES
     ( (SELECT MAX (TABLEID) FROM Material_Table) + 1,
      :NAME, :LIBRARY, :TEMPMEV, :AWR, :DESCRIPTION, :NXS, :JXS, :XSS )
     )"
    , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return -1;
    
    idx = sqlite3_bind_parameter_index(stmt, ":NAME");
    sqlite3_bind_text
    (stmt, idx, table.name.data(),
     (int)table.name.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":LIBRARY");
    sqlite3_bind_text
    (stmt, idx, table.library.data(),
     (int)table.library.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":TEMPMEV");
    sqlite3_bind_double(stmt, idx, table.tempMev);
    
    idx = sqlite3_bind_parameter_index(stmt, ":AWR");
    sqlite3_bind_double(stmt, idx, table.AWR);
    
    idx = sqlite3_bind_parameter_index(stmt, ":DESCRIPTION");
    sqlite3_bind_text
    (stmt, idx, table.description.data(),
     (int)table.description.length(), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":NXS");
    sqlite3_bind_blob
    (stmt, idx, table.NXS.data(),
     (int)table.NXS.size()*sizeof(long), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":JXS");
    sqlite3_bind_blob
    (stmt, idx, table.JXS.data(),
     (int)table.JXS.size()*sizeof(long), SQLITE_STATIC);
    
    idx = sqlite3_bind_parameter_index(stmt, ":XSS");
    sqlite3_bind_blob
    (stmt, idx,table.XSS.data(),
     (int)table.XSS.size()*sizeof(double), SQLITE_STATIC);
    
    rc = sqlite3_step(stmt);
    if ( (rc != SQLITE_DONE)) return -1;
    // SQLITE_CONSTRAINT: data exist
    
    sqlite3_finalize(stmt);
    
    return getMaxTableId();
}

// Get the current maximum TABLEID
long ADLS::getMaxTableId() {
    
    long TABLEID = -1;
    
    sqlite3_stmt *stmt = nullptr;
    int rc             = -1;
    
    rc = sqlite3_prepare_v2
    (db, R"(SELECT MAX (TABLEID) FROM Material_Table)"
     , -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return -1;
    }
    
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        return -1;
    }
    TABLEID = sqlite3_column_int64(stmt, 0);
    
    sqlite3_finalize(stmt);
    
    return TABLEID;
}

// Get the ACE table from database
ACETable ADLS::getMaterialTable
(const std::string& name, const std::string& lib) {
    
    ACETable table;
    
    try {
        
        sqlite3_stmt *stmt = nullptr;
        int rc             = -1;
        int idx            = -1;
        
        rc = sqlite3_prepare_v2
        (db, R"(
         SELECT * FROM Material_Table
         WHERE NAME =:NAME AND LIBRARY=:LIBRARY
         )"
        , -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            throw std::logic_error("prepare stmt error!");
        }
        
        idx = sqlite3_bind_parameter_index(stmt, ":NAME");
        sqlite3_bind_text
        (stmt, idx, name.data(),
         (int)name.length(), SQLITE_STATIC);
        
        idx = sqlite3_bind_parameter_index(stmt, ":LIBRARY");
        sqlite3_bind_text
        (stmt, idx, lib.data(),
         (int)lib.length(), SQLITE_STATIC);
        
        while ( sqlite3_step(stmt) == SQLITE_ROW ) {
            
            //Obtain number of columns
            long nid = sqlite3_column_count(stmt);
            
            //Loop over columns
            for (long idx = 0; idx < nid; idx++) {
                
                //Extract column name
                const char *columnName =
                sqlite3_column_name(stmt, (int)idx);
                
                // Bufferes
                const unsigned char* buf_ptr = nullptr;
                int buf_len = 0;
                
                // Extract NAME
                if (!strcmp(columnName, "NAME")) {
                    
                    buf_ptr = sqlite3_column_text(stmt, (int)idx);
                    buf_len = sqlite3_column_bytes(stmt, (int)idx);
                    if (buf_len > 0) {
                        table.name = (const char*)buf_ptr;
                    }
                    
                }
                // Extract LIBRARY
                else if (!strcmp(columnName, "LIBRARY")) {
                    
                    buf_ptr = sqlite3_column_text(stmt, (int)idx);
                    buf_len = sqlite3_column_bytes(stmt, (int)idx);
                    if (buf_len > 0) {
                        table.library = (const char*)buf_ptr;
                    }
                    
                }
                // Extract TEMPMEV
                else if (!strcmp(columnName, "TEMPMEV")) {
                    
                    table.tempMev =
                    sqlite3_column_double(stmt, (int)idx);
                    
                }
                // Extract AWR
                else if (!strcmp(columnName, "AWR")) {
                    
                    table.AWR =
                    sqlite3_column_double(stmt, (int)idx);
                    
                }
                // Extract DESCRIPTION
                else if (!strcmp(columnName, "DESCRIPTION")) {
                    
                    buf_ptr = sqlite3_column_text(stmt, (int)idx);
                    buf_len = sqlite3_column_bytes(stmt, (int)idx);
                    if (buf_len > 0) {
                        table.description = (const char*)buf_ptr;
                    }
                    
                }
                // Extract NXS
                else if (!strcmp(columnName, "NXS")) {
                    
                    
                    buf_ptr = sqlite3_column_text(stmt, (int)idx);
                    buf_len = sqlite3_column_bytes(stmt, (int)idx);
                    if (buf_len > 0 ) {
                        if (buf_len != NXSLength*sizeof(long)) {
                            throw std::logic_error("NXS len. error!");
                        }
                        memcpy((char*)table.NXS.data(),
                               (char*)buf_ptr, buf_len);
                    }
                    
                }
                // Extract JXS
                else if (!strcmp(columnName, "JXS")) {
                    
                    buf_ptr = sqlite3_column_text(stmt, (int)idx);
                    buf_len = sqlite3_column_bytes(stmt, (int)idx);
                    if (buf_len > 0 ) {
                        if (buf_len != JXSLength*sizeof(long)) {
                            throw std::logic_error("JXS len. error!");
                        }
                        memcpy((char*)table.JXS.data(),
                               (char*)buf_ptr, buf_len);
                    }
                    
                }
                // Extract XSS
                else if (!strcmp(columnName, "XSS")) {
                    
                    buf_ptr = sqlite3_column_text(stmt, (int)idx);
                    buf_len = sqlite3_column_bytes(stmt, (int)idx);
                    
                    //Allocate memory
                    table.XSS.resize(buf_len/sizeof(double), 0.);
                    
                    if (buf_len > 0 ) {
                        memcpy((char*)table.XSS.data(),
                               (char*)buf_ptr, buf_len);
                    }
                }
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[sqlite]: " << sqlite3_errmsg(db) << std::endl;
        std::cerr << "[ACE]: error msg - " << e.what() << std::endl;
        table.clear();
        return table;
    }
    
    return table;
}

bool ADLS::open(const std::string& dbFilepath) {
    
    int rc = 0;
    
    // Initialize SQLite enviroment
    rc = sqlite3_initialize();
    if (rc != SQLITE_OK) {
        std::cerr << "[sqlite]: " << sqlite3_errmsg(db) << std::endl;
        std::cout << "[ADLS]: can't initialize SQLite!" << std::endl;
        return false;
    }
    
    // Open the database at given filepath
    rc = sqlite3_open_v2
    (dbFilepath.c_str(), &db,
     SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr);
    if (rc != SQLITE_OK || db == nullptr) {
        std::cerr << "[sqlite]: " << sqlite3_errmsg(db) << std::endl;
        std::cout << "[ADLS]: can't open database "
        << dbFilepath << "!" << std::endl;
        return false;
    }
    
    // Maintain database schema
    if (!maintainSchema()) {
        std::cout << "[ADLS]: database schema error, close database!"
        << std::endl;
        if (db != nullptr) {
            sqlite3_close_v2(db);
            db = nullptr;
        }
        return false;
    }
    
    return true;
}

void ADLS::close() {
    if (db != nullptr) {
        sqlite3_close_v2(db);
        db = nullptr;
    }
    sqlite3_shutdown();
}

bool ADLS::insertACELibrary(const std::string& aceDirFilepath) {
    
    try {
        
        // Check whether database ready
        if (!isReady()) {
            throw std::logic_error("db not ready!");
        }
    
        // Create directory
        ACEDirectory dir;
    
        // Open library file
        if (!dir.loadFromFile(aceDirFilepath)) {
            throw std::logic_error("can't load ir file!");
        }
        
        // Categorize headers
        typedef std::pair< std::string, std::vector<ACETableHeader*> > Entry;
        std::vector<Entry>categorizedHeader;
        
        for (auto& header : dir.headers) {
            auto it = std::find_if
            (categorizedHeader.begin(), categorizedHeader.end(),
             [&] (const Entry& p) {
                 return p.first == header.filename;
             });
            if (it == categorizedHeader.end()) {
                Entry p;
                p.first = header.filename;
                p.second.push_back(&header);
                categorizedHeader.push_back(p);
            } else {
                it->second.push_back(&header);
            }
        }
        
        // Sort according to header ZAID
        std::sort
        (categorizedHeader.begin(),
         categorizedHeader.end(),
         [] (const Entry& p1, const Entry& p2) {
             long zaid1 = 0, zaid2 = 0;
             try {
                 zaid1 = std::stol(p1.second.front()->namelib);
             } catch (std::exception& e) {
                 // Do nothing
             }
             try {
                 zaid2 = std::stol(p2.second.front()->namelib);
             } catch (std::exception& e) {
                 // Do nothing
             }
             return zaid1<zaid2;
         });
        
        // Add into db
        for (auto& p : categorizedHeader) {
            
            // Sort headers
            auto& v = p.second;
            std::sort
            (v.begin(), v.end(),
             [](ACETableHeader* h1, ACETableHeader* h2){
                 return h1->address < h2->address;
            });
            
            // Load ACE file
            auto dirpath  = IO::resolvePath(aceDirFilepath).front();
            auto filepath = dirpath + p.first;
            
            std::ifstream in(filepath);
            if (!in.is_open()) {
                throw std::logic_error("can't open ace file!");
            }
            
            long lnum = 0, read = 0, hcnt = 0;
            std::string line;
            do {
                
                if (lnum + 1 == v[hcnt]->address) {
                    
                    // Create ACETable
                    ACETable table;
                    if(!table.loadFromFile(in, read)) {
                        throw std::logic_error("unable to load ace file!");
                    }
                    
                    // Update counter
                    hcnt ++;
                    lnum += read;
                    
                    // Load ACETable
                    long TABLEID = -1;
                    
                    // Check existance
                    if ((TABLEID = getTableID
                         (table.name, table.library)) == -1) {
                        
                        if ((TABLEID = addMaterialTableEntry
                             (table)) == -1) {
                            throw std::logic_error
                            ("add material table entry error!");
                        }
                        
                        std::cout
                        << "[ADLS]: Add table NAME = " << table.name
                        << ", LIB = " << table.library
                        << std::endl;
                        
                    } else {
                        // Table already exist, not treat as an error
                        std::cout
                        << "[ADLS]: TABLEID=" << TABLEID <<" already exist!"
                        << std::endl;
                    }
                    
                } else {
                    
                    std::getline(in, line);
                    lnum ++;
                    
                }
                
            } while (!in.bad() && !in.eof() && hcnt < v.size());
            
            in.close();
        }
        
    } catch (std::exception& e) {
        // Print a db error msg as well
        std::cerr << "[sqlite]: " << sqlite3_errmsg(db) << std::endl;
        std::cerr << "[ADLS]: error msg - " << e.what() << std::endl;
        return false;
    }
    
    return true;
}

ACENeutronData* ADLS::getNeutronData
(const std::string& name,
 const std::string& lib) {
    
    ACENeutronData* ndata = nullptr;
    
    try {
        
        // Check whether database ready
        if (!isReady()) {
            throw std::logic_error("db not ready!");
        }
        
        // Obtain ACE table
        auto table = getMaterialTable(name, lib);
        if (table.empty()) {
            throw std::logic_error("get material table error!");
        }
        
        // Allocate memory
        ndata = new ACENeutronData;
        if (ndata == nullptr) {
            throw std::logic_error("alloc. mem ace ndata!");
        }
        
        // Load ACE table
        if(!ndata->loadACETable(table)) {
            throw std::logic_error("unable to get ndata from ace table!");
        }
        
        
    } catch (std::exception& e) {
        // Print a db error msg as well
        std::cerr << "[sqlite]: " << sqlite3_errmsg(db) << std::endl;
        std::cerr << "[ADLS]: error msg - " << e.what() << std::endl;
        if (ndata != nullptr) {
            delete ndata;
            ndata = nullptr;
        }
        return nullptr;
    }
    
    return ndata;
}

void ADLS::iterateOverMaterials
(std::function
 <void(const ACETable& table, ACENeutronData* ndata)> action,
 std::function<bool(const ACETable& table)> filter) {
     
     try {
         
         // Check library validity
         if (!isReady()) {
             throw std::logic_error("Library not ready!");
         }
         
         // Loop over the database
         sqlite3_stmt *stmt = nullptr;
         int rc             = -1;
         std::string columnName;
         
         // Prepare statement
         rc = sqlite3_prepare_v2
         (db, R"(
          SELECT * FROM Material_Table
          )"
         , -1, &stmt, NULL);
         if (rc != SQLITE_OK) {
             throw std::logic_error("invalid stmt!");
         }
         
         // Extract row data one by one
         while ( sqlite3_step(stmt) == SQLITE_ROW ) {
             
             // Obtain table
             ACETable table;
             
             //Obtain number of columns
             long nid = sqlite3_column_count(stmt);
             
             //Loop over columns
             for (long idx = 0; idx < nid; idx++) {
                 
                 //Extract column name
                 const char *columnName =
                 sqlite3_column_name(stmt, (int)idx);
                 
                 // Bufferes
                 const unsigned char* buf_ptr = nullptr;
                 int buf_len = 0;
                 
                 // Extract NAME
                 if (!strcmp(columnName, "NAME")) {
                     
                     buf_ptr = sqlite3_column_text(stmt, (int)idx);
                     buf_len = sqlite3_column_bytes(stmt, (int)idx);
                     if (buf_len > 0) {
                         table.name = (const char*)buf_ptr;
                     }
                     
                 }
                 // Extract LIBRARY
                 else if (!strcmp(columnName, "LIBRARY")) {
                     
                     buf_ptr = sqlite3_column_text(stmt, (int)idx);
                     buf_len = sqlite3_column_bytes(stmt, (int)idx);
                     if (buf_len > 0) {
                         table.library = (const char*)buf_ptr;
                     }
                     
                 }
                 // Extract TEMPMEV
                 else if (!strcmp(columnName, "TEMPMEV")) {
                     
                     table.tempMev =
                     sqlite3_column_double(stmt, (int)idx);
                     
                 }
                 // Extract AWR
                 else if (!strcmp(columnName, "AWR")) {
                     
                     table.AWR =
                     sqlite3_column_double(stmt, (int)idx);
                     
                 }
                 // Extract DESCRIPTION
                 else if (!strcmp(columnName, "DESCRIPTION")) {
                     
                     buf_ptr = sqlite3_column_text(stmt, (int)idx);
                     buf_len = sqlite3_column_bytes(stmt, (int)idx);
                     if (buf_len > 0) {
                         table.description = (const char*)buf_ptr;
                     }
                     
                 }
                 // Extract NXS
                 else if (!strcmp(columnName, "NXS")) {
                     
                     buf_ptr = sqlite3_column_text(stmt, (int)idx);
                     buf_len = sqlite3_column_bytes(stmt, (int)idx);
                     if (buf_len > 0 ) {
                         if (buf_len != NXSLength*sizeof(long)) {
                             throw std::logic_error("NXS len. error!");
                         }
                         memcpy((char*)table.NXS.data(),
                                (char*)buf_ptr, buf_len);
                     }
                     
                 }
                 // Extract JXS
                 else if (!strcmp(columnName, "JXS")) {
                     
                     buf_ptr = sqlite3_column_text(stmt, (int)idx);
                     buf_len = sqlite3_column_bytes(stmt, (int)idx);
                     if (buf_len > 0 ) {
                         if (buf_len != JXSLength*sizeof(long)) {
                             throw std::logic_error("JXS len. error!");
                         }
                         memcpy((char*)table.JXS.data(),
                                (char*)buf_ptr, buf_len);
                     }
                     
                 }
                 // Extract XSS
                 else if (!strcmp(columnName, "XSS")) {
                     
                     buf_ptr = sqlite3_column_text(stmt, (int)idx);
                     buf_len = sqlite3_column_bytes(stmt, (int)idx);
                     
                     //Allocate memory
                     table.XSS.resize(buf_len/sizeof(double), 0.);
                     
                     if (buf_len > 0 ) {
                         memcpy((char*)table.XSS.data(),
                                (char*)buf_ptr, buf_len);
                     }
                 }
             }
             
             // Skip non-neutron table
             // May remove later
             if (table.getType() !=
                 ACETableType::ACE_COUNTINUOUS_ENERGY_NEUTRON) {
                 continue;
             }
             
             // Check filter
             if (!filter(table)) {
                 continue;
             }
             
             // Obtain neutron data from table
             ACENeutronData ndata;
             
             // Load ACE table
             if(!ndata.loadACETable(table)) {
                 throw std::logic_error
                 ("can't get ACE ndata from table!");
             }
             
             // Apply operation
             action(table, &ndata);
             
         }
         
         if (rc != SQLITE_DONE && rc != SQLITE_OK) {
             throw std::logic_error("db loop error!");
         }
         
         sqlite3_finalize(stmt);
         
     } catch (std::exception& e) {
         // Print a db error msg as well
         std::cerr << "[sqlite]: " << sqlite3_errmsg(db) << std::endl;
         std::cerr << "[ADLS]: error msg - " << e.what() << std::endl;
         return;
     }
     
 }

//}
//}