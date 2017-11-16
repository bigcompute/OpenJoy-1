//
//  main.cpp
//  OpenJOY
//
//  Created by changyuan on 16/4/27.
//  Copyright © 2016年 changyuan. All rights reserved.
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
    ADLS adls("/ace.db");
    adls.insertACELibrary("/ADS/xsdir");

    auto andata = adls.getNeutronData("5010", "70c");

    return 0;

}
