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

// Extended file IO system

#ifndef IO_HPP
#define IO_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//namespace com {
//namespace ibhe {

class IO {
    
public:
    
    // Safe get line
    static std::istream& safeGetline
    (std::istream& is, std::string& t);
    
    // Split a line of strings
    static std::vector<std::string> split
    (const std::string& s);
    
    // Resolve file path
    // Part 1: file path
    // Part 2: file name
    // Part 3: file extention
    static std::vector<std::string> resolvePath
    (const std::string& path);
    
};



//}
//}

#endif /* IO_HPP */
