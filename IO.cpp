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

#include "IO.hpp"

//namespace com {
//namespace ibhe {

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

std::istream& IO::safeGetline
(std::istream& is, std::string& t) {
    t.clear();
    
    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.
    // The sentry object performs various tasks,
    // such as thread synchronization and updating the stream state.
    
    std::istream::sentry se(is, true);
    std::streambuf* sb = is.rdbuf();
    
    for(;;) {
        int c = sb->sbumpc();
        switch (c) {
            case '\n':
                return is;
            case '\r':
                if(sb->sgetc() == '\n')
                    sb->sbumpc();
                return is;
            case EOF:
                // Also handle the case when the last line has no line ending
                if(t.empty())
                    is.setstate(std::ios::eofbit);
                return is;
            default:
                t += (char)c;
        }
    }
}

std::vector<std::string> IO::split
(const std::string& s) {
    
    std::vector<std::string> tokens;
    
    try {
        
        // Split a string with regular expression
        std::regex pattern("(\\S+)");
        std::smatch sm;
        std::string text = s;
        while (std::regex_search (text,sm,pattern)) {
            std::string str = sm[0].str();
            tokens.push_back(str);
            text = sm.suffix().str();
        }
        
    } catch (std::exception& e) {
        std::cerr << "[IO]: error msg - " << e.what() << std::endl;
        return std::vector<std::string>();
    }
    
    return tokens;
}

std::vector<std::string> IO::resolvePath
(const std::string& path) {
    
    std::vector<std::string> components;
    
    try {
        
        std::regex pattern
        (R"((.*[\\\/]|^)(.*?)(?:[\.]|$)([^\.\s]*$))");
        std::smatch match;
        std::string text = path;
        
        if (std::regex_match(text,match,pattern)) {
            for (auto& m : match) {
                components.push_back(m.str());
            }
            components.erase(components.begin());
        }
        
    } catch (std::exception& e) {
        std::cerr << "[IO]: error msg - " << e.what() << std::endl;
        return std::vector<std::string>();
    }
    
    return components;
}


//}
//}