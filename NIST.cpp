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

#include "NIST.hpp"
#include "rapidjson/document.h"

#include <string>
#include <iostream>
#include <exception>
#include <sstream>

static const std::string NISTJsonData =
R"(
{
    
"Number of Elements" : "118",

"Neutron Mass" : "1.008664916",

"Isotopes" :
    
[

{
"Atomic Number" : "1",
"Atomic Symbol" : "H",
"Mass Number" : "1",
"Relative Atomic Mass" : "1.00782503207",
"Isotopic Composition" : "0.999885",
"Standard Atomic Weight" : "1.00794",
"Notes" : "g,m,r,b,w"
},

{
"Atomic Number" : "1",
"Atomic Symbol" : "H",
"Mass Number" : "2",
"Relative Atomic Mass" : "2.0141017778",
"Isotopic Composition" : "0.000115",
"Standard Atomic Weight" : "1.00794",
"Notes" : "g,m,r,b,w"
},

{
"Atomic Number" : "1",
"Atomic Symbol" : "H",
"Mass Number" : "3",
"Relative Atomic Mass" : "3.0160492777",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "1.00794",
"Notes" : "g,m,r,b,w"
},

{
"Atomic Number" : "1",
"Atomic Symbol" : "H",
"Mass Number" : "4",
"Relative Atomic Mass" : "4.02781",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "1.00794",
"Notes" : "g,m,r,b,w"
},

{
"Atomic Number" : "1",
"Atomic Symbol" : "H",
"Mass Number" : "5",
"Relative Atomic Mass" : "5.03531",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "1.00794",
"Notes" : "g,m,r,b,w"
},

{
"Atomic Number" : "1",
"Atomic Symbol" : "H",
"Mass Number" : "6",
"Relative Atomic Mass" : "6.04494",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "1.00794",
"Notes" : "g,m,r,b,w"
},

{
"Atomic Number" : "1",
"Atomic Symbol" : "H",
"Mass Number" : "7",
"Relative Atomic Mass" : "7.05275",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "1.00794",
"Notes" : "g,m,r,b,w"
},

{
"Atomic Number" : "2",
"Atomic Symbol" : "He",
"Mass Number" : "3",
"Relative Atomic Mass" : "3.0160293191",
"Isotopic Composition" : "0.00000134",
"Standard Atomic Weight" : "4.002602",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "2",
"Atomic Symbol" : "He",
"Mass Number" : "4",
"Relative Atomic Mass" : "4.00260325415",
"Isotopic Composition" : "0.99999866",
"Standard Atomic Weight" : "4.002602",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "2",
"Atomic Symbol" : "He",
"Mass Number" : "5",
"Relative Atomic Mass" : "5.012220",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "4.002602",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "2",
"Atomic Symbol" : "He",
"Mass Number" : "6",
"Relative Atomic Mass" : "6.0188891",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "4.002602",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "2",
"Atomic Symbol" : "He",
"Mass Number" : "7",
"Relative Atomic Mass" : "7.028021",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "4.002602",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "2",
"Atomic Symbol" : "He",
"Mass Number" : "8",
"Relative Atomic Mass" : "8.033922",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "4.002602",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "2",
"Atomic Symbol" : "He",
"Mass Number" : "9",
"Relative Atomic Mass" : "9.043950",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "4.002602",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "2",
"Atomic Symbol" : "He",
"Mass Number" : "10",
"Relative Atomic Mass" : "10.052400",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "4.002602",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "3",
"Atomic Symbol" : "Li",
"Mass Number" : "3",
"Relative Atomic Mass" : "3.03078",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "6.941",
"Notes" : "g,m,r,c,i"
},

{
"Atomic Number" : "3",
"Atomic Symbol" : "Li",
"Mass Number" : "4",
"Relative Atomic Mass" : "4.02719",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "6.941",
"Notes" : "g,m,r,c,i"
},

{
"Atomic Number" : "3",
"Atomic Symbol" : "Li",
"Mass Number" : "5",
"Relative Atomic Mass" : "5.012540",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "6.941",
"Notes" : "g,m,r,c,i"
},

{
"Atomic Number" : "3",
"Atomic Symbol" : "Li",
"Mass Number" : "6",
"Relative Atomic Mass" : "6.015122795",
"Isotopic Composition" : "0.0759",
"Standard Atomic Weight" : "6.941",
"Notes" : "g,m,r,c,i"
},

{
"Atomic Number" : "3",
"Atomic Symbol" : "Li",
"Mass Number" : "7",
"Relative Atomic Mass" : "7.01600455",
"Isotopic Composition" : "0.9241",
"Standard Atomic Weight" : "6.941",
"Notes" : "g,m,r,c,i"
},

{
"Atomic Number" : "3",
"Atomic Symbol" : "Li",
"Mass Number" : "8",
"Relative Atomic Mass" : "8.02248736",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "6.941",
"Notes" : "g,m,r,c,i"
},

{
"Atomic Number" : "3",
"Atomic Symbol" : "Li",
"Mass Number" : "9",
"Relative Atomic Mass" : "9.0267895",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "6.941",
"Notes" : "g,m,r,c,i"
},

{
"Atomic Number" : "3",
"Atomic Symbol" : "Li",
"Mass Number" : "10",
"Relative Atomic Mass" : "10.035481",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "6.941",
"Notes" : "g,m,r,c,i"
},

{
"Atomic Number" : "3",
"Atomic Symbol" : "Li",
"Mass Number" : "11",
"Relative Atomic Mass" : "11.043798",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "6.941",
"Notes" : "g,m,r,c,i"
},

{
"Atomic Number" : "3",
"Atomic Symbol" : "Li",
"Mass Number" : "12",
"Relative Atomic Mass" : "12.05378",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "6.941",
"Notes" : "g,m,r,c,i"
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "5",
"Relative Atomic Mass" : "5.04079",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "6",
"Relative Atomic Mass" : "6.019726",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "7",
"Relative Atomic Mass" : "7.01692983",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "8",
"Relative Atomic Mass" : "8.00530510",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "9",
"Relative Atomic Mass" : "9.0121822",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "10",
"Relative Atomic Mass" : "10.0135338",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "11",
"Relative Atomic Mass" : "11.021658",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "12",
"Relative Atomic Mass" : "12.026921",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "13",
"Relative Atomic Mass" : "13.035690",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "14",
"Relative Atomic Mass" : "14.04289",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "15",
"Relative Atomic Mass" : "15.05346",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "4",
"Atomic Symbol" : "Be",
"Mass Number" : "16",
"Relative Atomic Mass" : "16.06192",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "9.012182",
"Notes" : " "
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "6",
"Relative Atomic Mass" : "6.04681",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "7",
"Relative Atomic Mass" : "7.029920",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "8",
"Relative Atomic Mass" : "8.0246072",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "9",
"Relative Atomic Mass" : "9.0133288",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "10",
"Relative Atomic Mass" : "10.0129370",
"Isotopic Composition" : "0.199",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "11",
"Relative Atomic Mass" : "11.0093054",
"Isotopic Composition" : "0.801",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "12",
"Relative Atomic Mass" : "12.0143521",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "13",
"Relative Atomic Mass" : "13.0177802",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "14",
"Relative Atomic Mass" : "14.025404",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "15",
"Relative Atomic Mass" : "15.031103",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "16",
"Relative Atomic Mass" : "16.039810",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "17",
"Relative Atomic Mass" : "17.04699",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "18",
"Relative Atomic Mass" : "18.05617",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "5",
"Atomic Symbol" : "B",
"Mass Number" : "19",
"Relative Atomic Mass" : "19.06373",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "10.811",
"Notes" : "g,m,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "8",
"Relative Atomic Mass" : "8.037675",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "9",
"Relative Atomic Mass" : "9.0310367",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "10",
"Relative Atomic Mass" : "10.0168532",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "11",
"Relative Atomic Mass" : "11.0114336",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "12",
"Relative Atomic Mass" : "12.0000000",
"Isotopic Composition" : "0.9893",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "13",
"Relative Atomic Mass" : "13.0033548378",
"Isotopic Composition" : "0.0107",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "14",
"Relative Atomic Mass" : "14.003241989",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "15",
"Relative Atomic Mass" : "15.0105993",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "16",
"Relative Atomic Mass" : "16.014701",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "17",
"Relative Atomic Mass" : "17.022586",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "18",
"Relative Atomic Mass" : "18.026760",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "19",
"Relative Atomic Mass" : "19.03481",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "20",
"Relative Atomic Mass" : "20.04032",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "21",
"Relative Atomic Mass" : "21.04934",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "6",
"Atomic Symbol" : "C",
"Mass Number" : "22",
"Relative Atomic Mass" : "22.05720",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "12.0107",
"Notes" : "g,r"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "10",
"Relative Atomic Mass" : "10.04165",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "11",
"Relative Atomic Mass" : "11.026090",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "12",
"Relative Atomic Mass" : "12.0186132",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "13",
"Relative Atomic Mass" : "13.00573861",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "14",
"Relative Atomic Mass" : "14.0030740048",
"Isotopic Composition" : "0.99636",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "15",
"Relative Atomic Mass" : "15.0001088982",
"Isotopic Composition" : "0.00364",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "16",
"Relative Atomic Mass" : "16.0061017",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "17",
"Relative Atomic Mass" : "17.008450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "18",
"Relative Atomic Mass" : "18.014079",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "19",
"Relative Atomic Mass" : "19.017029",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "20",
"Relative Atomic Mass" : "20.023370",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "21",
"Relative Atomic Mass" : "21.02711",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "22",
"Relative Atomic Mass" : "22.03439",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "23",
"Relative Atomic Mass" : "23.04122",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "24",
"Relative Atomic Mass" : "24.05104",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "7",
"Atomic Symbol" : "N",
"Mass Number" : "25",
"Relative Atomic Mass" : "25.06066",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "14.0067",
"Notes" : "g,r,a,d"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "12",
"Relative Atomic Mass" : "12.034405",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "13",
"Relative Atomic Mass" : "13.024812",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "14",
"Relative Atomic Mass" : "14.00859625",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "15",
"Relative Atomic Mass" : "15.0030656",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "16",
"Relative Atomic Mass" : "15.99491461956",
"Isotopic Composition" : "0.99757",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "17",
"Relative Atomic Mass" : "16.99913170",
"Isotopic Composition" : "0.00038",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "18",
"Relative Atomic Mass" : "17.9991610",
"Isotopic Composition" : "0.00205",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "19",
"Relative Atomic Mass" : "19.003580",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "20",
"Relative Atomic Mass" : "20.0040767",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "21",
"Relative Atomic Mass" : "21.008656",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "22",
"Relative Atomic Mass" : "22.009970",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "23",
"Relative Atomic Mass" : "23.01569",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "24",
"Relative Atomic Mass" : "24.02047",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "25",
"Relative Atomic Mass" : "25.02946",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "26",
"Relative Atomic Mass" : "26.03834",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "27",
"Relative Atomic Mass" : "27.04826",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "8",
"Atomic Symbol" : "O",
"Mass Number" : "28",
"Relative Atomic Mass" : "28.05781",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "15.9994",
"Notes" : "g,r,e,w"
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "14",
"Relative Atomic Mass" : "14.03506",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "15",
"Relative Atomic Mass" : "15.01801",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "16",
"Relative Atomic Mass" : "16.011466",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "17",
"Relative Atomic Mass" : "17.00209524",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "18",
"Relative Atomic Mass" : "18.0009380",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "19",
"Relative Atomic Mass" : "18.99840322",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "20",
"Relative Atomic Mass" : "19.99998132",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "21",
"Relative Atomic Mass" : "20.9999490",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "22",
"Relative Atomic Mass" : "22.002999",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "23",
"Relative Atomic Mass" : "23.003570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "24",
"Relative Atomic Mass" : "24.008120",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "25",
"Relative Atomic Mass" : "25.01210",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "26",
"Relative Atomic Mass" : "26.01962",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "27",
"Relative Atomic Mass" : "27.02676",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "28",
"Relative Atomic Mass" : "28.03567",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "29",
"Relative Atomic Mass" : "29.04326",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "30",
"Relative Atomic Mass" : "30.05250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "9",
"Atomic Symbol" : "F",
"Mass Number" : "31",
"Relative Atomic Mass" : "31.06043",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "18.9984032",
"Notes" : " "
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "16",
"Relative Atomic Mass" : "16.025761",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "17",
"Relative Atomic Mass" : "17.017672",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "18",
"Relative Atomic Mass" : "18.0057082",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "19",
"Relative Atomic Mass" : "19.0018802",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "20",
"Relative Atomic Mass" : "19.9924401754",
"Isotopic Composition" : "0.9048",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "21",
"Relative Atomic Mass" : "20.99384668",
"Isotopic Composition" : "0.0027",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "22",
"Relative Atomic Mass" : "21.991385114",
"Isotopic Composition" : "0.0925",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "23",
"Relative Atomic Mass" : "22.99446690",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "24",
"Relative Atomic Mass" : "23.9936108",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "25",
"Relative Atomic Mass" : "24.997737",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "26",
"Relative Atomic Mass" : "26.000461",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "27",
"Relative Atomic Mass" : "27.00759",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "28",
"Relative Atomic Mass" : "28.01207",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "29",
"Relative Atomic Mass" : "29.01939",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "30",
"Relative Atomic Mass" : "30.02480",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "31",
"Relative Atomic Mass" : "31.03311",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "32",
"Relative Atomic Mass" : "32.04002",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "33",
"Relative Atomic Mass" : "33.04938",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "10",
"Atomic Symbol" : "Ne",
"Mass Number" : "34",
"Relative Atomic Mass" : "34.05703",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "20.1797",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "18",
"Relative Atomic Mass" : "18.025970",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "19",
"Relative Atomic Mass" : "19.013877",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "20",
"Relative Atomic Mass" : "20.007351",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "21",
"Relative Atomic Mass" : "20.9976552",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "22",
"Relative Atomic Mass" : "21.9944364",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "23",
"Relative Atomic Mass" : "22.9897692809",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "24",
"Relative Atomic Mass" : "23.99096278",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "25",
"Relative Atomic Mass" : "24.9899540",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "26",
"Relative Atomic Mass" : "25.992633",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "27",
"Relative Atomic Mass" : "26.994077",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "28",
"Relative Atomic Mass" : "27.998938",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "29",
"Relative Atomic Mass" : "29.002861",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "30",
"Relative Atomic Mass" : "30.008976",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "31",
"Relative Atomic Mass" : "31.01359",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "32",
"Relative Atomic Mass" : "32.02047",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "33",
"Relative Atomic Mass" : "33.02672",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "34",
"Relative Atomic Mass" : "34.03517",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "35",
"Relative Atomic Mass" : "35.04249",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "36",
"Relative Atomic Mass" : "36.05148",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "11",
"Atomic Symbol" : "Na",
"Mass Number" : "37",
"Relative Atomic Mass" : "37.05934",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "22.98976928",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "19",
"Relative Atomic Mass" : "19.03547",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "20",
"Relative Atomic Mass" : "20.018863",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "21",
"Relative Atomic Mass" : "21.011713",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "22",
"Relative Atomic Mass" : "21.9995738",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "23",
"Relative Atomic Mass" : "22.9941237",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "24",
"Relative Atomic Mass" : "23.985041700",
"Isotopic Composition" : "0.7899",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "25",
"Relative Atomic Mass" : "24.98583692",
"Isotopic Composition" : "0.1000",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "26",
"Relative Atomic Mass" : "25.982592929",
"Isotopic Composition" : "0.1101",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "27",
"Relative Atomic Mass" : "26.98434059",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "28",
"Relative Atomic Mass" : "27.9838768",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "29",
"Relative Atomic Mass" : "28.988600",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "30",
"Relative Atomic Mass" : "29.990434",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "31",
"Relative Atomic Mass" : "30.996546",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "32",
"Relative Atomic Mass" : "31.998975",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "33",
"Relative Atomic Mass" : "33.005254",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "34",
"Relative Atomic Mass" : "34.00946",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "35",
"Relative Atomic Mass" : "35.01734",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "36",
"Relative Atomic Mass" : "36.02300",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "37",
"Relative Atomic Mass" : "37.03140",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "38",
"Relative Atomic Mass" : "38.03757",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "39",
"Relative Atomic Mass" : "39.04677",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "12",
"Atomic Symbol" : "Mg",
"Mass Number" : "40",
"Relative Atomic Mass" : "40.05393",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "24.3050",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "21",
"Relative Atomic Mass" : "21.02804",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "22",
"Relative Atomic Mass" : "22.01952",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "23",
"Relative Atomic Mass" : "23.007267",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "24",
"Relative Atomic Mass" : "23.9999389",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "25",
"Relative Atomic Mass" : "24.9904281",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "26",
"Relative Atomic Mass" : "25.98689169",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "27",
"Relative Atomic Mass" : "26.98153863",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "28",
"Relative Atomic Mass" : "27.98191031",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "29",
"Relative Atomic Mass" : "28.9804450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "30",
"Relative Atomic Mass" : "29.982960",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "31",
"Relative Atomic Mass" : "30.983947",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "32",
"Relative Atomic Mass" : "31.988120",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "33",
"Relative Atomic Mass" : "32.990840",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "34",
"Relative Atomic Mass" : "33.99685",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "35",
"Relative Atomic Mass" : "34.99986",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "36",
"Relative Atomic Mass" : "36.00621",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "37",
"Relative Atomic Mass" : "37.01068",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "38",
"Relative Atomic Mass" : "38.01723",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "39",
"Relative Atomic Mass" : "39.02297",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "40",
"Relative Atomic Mass" : "40.03145",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "41",
"Relative Atomic Mass" : "41.03833",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "13",
"Atomic Symbol" : "Al",
"Mass Number" : "42",
"Relative Atomic Mass" : "42.04689",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "26.9815386",
"Notes" : " "
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "22",
"Relative Atomic Mass" : "22.03453",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "23",
"Relative Atomic Mass" : "23.02552",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "24",
"Relative Atomic Mass" : "24.011546",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "25",
"Relative Atomic Mass" : "25.004106",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "26",
"Relative Atomic Mass" : "25.992330",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "27",
"Relative Atomic Mass" : "26.98670491",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "28",
"Relative Atomic Mass" : "27.9769265325",
"Isotopic Composition" : "0.92223",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "29",
"Relative Atomic Mass" : "28.976494700",
"Isotopic Composition" : "0.04685",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "30",
"Relative Atomic Mass" : "29.97377017",
"Isotopic Composition" : "0.03092",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "31",
"Relative Atomic Mass" : "30.97536323",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "32",
"Relative Atomic Mass" : "31.97414808",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "33",
"Relative Atomic Mass" : "32.978000",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "34",
"Relative Atomic Mass" : "33.978576",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "35",
"Relative Atomic Mass" : "34.984580",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "36",
"Relative Atomic Mass" : "35.98660",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "37",
"Relative Atomic Mass" : "36.99294",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "38",
"Relative Atomic Mass" : "37.99563",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "39",
"Relative Atomic Mass" : "39.00207",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "40",
"Relative Atomic Mass" : "40.00587",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "41",
"Relative Atomic Mass" : "41.01456",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "42",
"Relative Atomic Mass" : "42.01979",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "43",
"Relative Atomic Mass" : "43.02866",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "14",
"Atomic Symbol" : "Si",
"Mass Number" : "44",
"Relative Atomic Mass" : "44.03526",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "28.0855",
"Notes" : "r"
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "24",
"Relative Atomic Mass" : "24.03435",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "25",
"Relative Atomic Mass" : "25.02026",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "26",
"Relative Atomic Mass" : "26.01178",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "27",
"Relative Atomic Mass" : "26.999230",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "28",
"Relative Atomic Mass" : "27.992315",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "29",
"Relative Atomic Mass" : "28.9818006",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "30",
"Relative Atomic Mass" : "29.9783138",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "31",
"Relative Atomic Mass" : "30.97376163",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "32",
"Relative Atomic Mass" : "31.97390727",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "33",
"Relative Atomic Mass" : "32.9717255",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "34",
"Relative Atomic Mass" : "33.973636",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "35",
"Relative Atomic Mass" : "34.9733141",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "36",
"Relative Atomic Mass" : "35.978260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "37",
"Relative Atomic Mass" : "36.979610",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "38",
"Relative Atomic Mass" : "37.98416",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "39",
"Relative Atomic Mass" : "38.98618",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "40",
"Relative Atomic Mass" : "39.99130",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "41",
"Relative Atomic Mass" : "40.99434",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "42",
"Relative Atomic Mass" : "42.00101",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "43",
"Relative Atomic Mass" : "43.00619",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "44",
"Relative Atomic Mass" : "44.01299",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "45",
"Relative Atomic Mass" : "45.01922",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "15",
"Atomic Symbol" : "P",
"Mass Number" : "46",
"Relative Atomic Mass" : "46.02738",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "30.973762",
"Notes" : " "
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "26",
"Relative Atomic Mass" : "26.02788",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "27",
"Relative Atomic Mass" : "27.01883",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "28",
"Relative Atomic Mass" : "28.00437",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "29",
"Relative Atomic Mass" : "28.996610",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "30",
"Relative Atomic Mass" : "29.984903",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "31",
"Relative Atomic Mass" : "30.9795547",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "32",
"Relative Atomic Mass" : "31.97207100",
"Isotopic Composition" : "0.9499",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "33",
"Relative Atomic Mass" : "32.97145876",
"Isotopic Composition" : "0.0075",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "34",
"Relative Atomic Mass" : "33.96786690",
"Isotopic Composition" : "0.0425",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "35",
"Relative Atomic Mass" : "34.96903216",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "36",
"Relative Atomic Mass" : "35.96708076",
"Isotopic Composition" : "0.0001",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "37",
"Relative Atomic Mass" : "36.97112557",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "38",
"Relative Atomic Mass" : "37.971163",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "39",
"Relative Atomic Mass" : "38.975130",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "40",
"Relative Atomic Mass" : "39.97545",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "41",
"Relative Atomic Mass" : "40.97958",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "42",
"Relative Atomic Mass" : "41.98102",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "43",
"Relative Atomic Mass" : "42.98715",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "44",
"Relative Atomic Mass" : "43.99021",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "45",
"Relative Atomic Mass" : "44.99651",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "46",
"Relative Atomic Mass" : "46.00075",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "47",
"Relative Atomic Mass" : "47.00859",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "48",
"Relative Atomic Mass" : "48.01417",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "16",
"Atomic Symbol" : "S",
"Mass Number" : "49",
"Relative Atomic Mass" : "49.02362",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "32.065",
"Notes" : "g,r"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "28",
"Relative Atomic Mass" : "28.02851",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "29",
"Relative Atomic Mass" : "29.01411",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "30",
"Relative Atomic Mass" : "30.00477",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "31",
"Relative Atomic Mass" : "30.992410",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "32",
"Relative Atomic Mass" : "31.985690",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "33",
"Relative Atomic Mass" : "32.9774519",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "34",
"Relative Atomic Mass" : "33.97376282",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "35",
"Relative Atomic Mass" : "34.96885268",
"Isotopic Composition" : "0.7576",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "36",
"Relative Atomic Mass" : "35.96830698",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "37",
"Relative Atomic Mass" : "36.96590259",
"Isotopic Composition" : "0.2424",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "38",
"Relative Atomic Mass" : "37.96801043",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "39",
"Relative Atomic Mass" : "38.9680082",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "40",
"Relative Atomic Mass" : "39.970420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "41",
"Relative Atomic Mass" : "40.970680",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "42",
"Relative Atomic Mass" : "41.97325",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "43",
"Relative Atomic Mass" : "42.97405",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "44",
"Relative Atomic Mass" : "43.97828",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "45",
"Relative Atomic Mass" : "44.98029",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "46",
"Relative Atomic Mass" : "45.98421",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "47",
"Relative Atomic Mass" : "46.98871",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "48",
"Relative Atomic Mass" : "47.99495",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "49",
"Relative Atomic Mass" : "49.00032",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "50",
"Relative Atomic Mass" : "50.00784",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "17",
"Atomic Symbol" : "Cl",
"Mass Number" : "51",
"Relative Atomic Mass" : "51.01449",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "35.453",
"Notes" : "m"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "30",
"Relative Atomic Mass" : "30.02156",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "31",
"Relative Atomic Mass" : "31.01212",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "32",
"Relative Atomic Mass" : "31.9976380",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "33",
"Relative Atomic Mass" : "32.9899257",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "34",
"Relative Atomic Mass" : "33.9802712",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "35",
"Relative Atomic Mass" : "34.9752576",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "36",
"Relative Atomic Mass" : "35.967545106",
"Isotopic Composition" : "0.003365",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "37",
"Relative Atomic Mass" : "36.96677632",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "38",
"Relative Atomic Mass" : "37.9627324",
"Isotopic Composition" : "0.000632",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "39",
"Relative Atomic Mass" : "38.964313",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "40",
"Relative Atomic Mass" : "39.9623831225",
"Isotopic Composition" : "0.996003",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "41",
"Relative Atomic Mass" : "40.9645006",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "42",
"Relative Atomic Mass" : "41.963046",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "43",
"Relative Atomic Mass" : "42.965636",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "44",
"Relative Atomic Mass" : "43.9649240",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "45",
"Relative Atomic Mass" : "44.9680400",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "46",
"Relative Atomic Mass" : "45.968090",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "47",
"Relative Atomic Mass" : "46.97219",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "48",
"Relative Atomic Mass" : "47.97454",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "49",
"Relative Atomic Mass" : "48.98052",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.98443",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.99163",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.99678",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "18",
"Atomic Symbol" : "Ar",
"Mass Number" : "53",
"Relative Atomic Mass" : "53.00494",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.948",
"Notes" : "g,r,a"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "32",
"Relative Atomic Mass" : "32.02192",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "33",
"Relative Atomic Mass" : "33.00726",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "34",
"Relative Atomic Mass" : "33.99841",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "35",
"Relative Atomic Mass" : "34.988010",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "36",
"Relative Atomic Mass" : "35.981292",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "37",
"Relative Atomic Mass" : "36.97337589",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "38",
"Relative Atomic Mass" : "37.9690812",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "39",
"Relative Atomic Mass" : "38.96370668",
"Isotopic Composition" : "0.932581",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "40",
"Relative Atomic Mass" : "39.96399848",
"Isotopic Composition" : "0.000117",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "41",
"Relative Atomic Mass" : "40.96182576",
"Isotopic Composition" : "0.067302",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "42",
"Relative Atomic Mass" : "41.96240281",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "43",
"Relative Atomic Mass" : "42.960716",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "44",
"Relative Atomic Mass" : "43.961560",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "45",
"Relative Atomic Mass" : "44.960699",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "46",
"Relative Atomic Mass" : "45.961977",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "47",
"Relative Atomic Mass" : "46.961678",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "48",
"Relative Atomic Mass" : "47.965514",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "49",
"Relative Atomic Mass" : "48.967450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.97278",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.97638",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.98261",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.98712",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.99420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "19",
"Atomic Symbol" : "K",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.99971",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "39.0983",
"Notes" : "g"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "34",
"Relative Atomic Mass" : "34.01412",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "35",
"Relative Atomic Mass" : "35.00494",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "36",
"Relative Atomic Mass" : "35.993090",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "37",
"Relative Atomic Mass" : "36.985870",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "38",
"Relative Atomic Mass" : "37.976318",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "39",
"Relative Atomic Mass" : "38.9707197",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "40",
"Relative Atomic Mass" : "39.96259098",
"Isotopic Composition" : "0.96941",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "41",
"Relative Atomic Mass" : "40.96227806",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "42",
"Relative Atomic Mass" : "41.95861801",
"Isotopic Composition" : "0.00647",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "43",
"Relative Atomic Mass" : "42.9587666",
"Isotopic Composition" : "0.00135",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "44",
"Relative Atomic Mass" : "43.9554818",
"Isotopic Composition" : "0.02086",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "45",
"Relative Atomic Mass" : "44.9561866",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "46",
"Relative Atomic Mass" : "45.9536926",
"Isotopic Composition" : "0.00004",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "47",
"Relative Atomic Mass" : "46.9545460",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "48",
"Relative Atomic Mass" : "47.952534",
"Isotopic Composition" : "0.00187",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "49",
"Relative Atomic Mass" : "48.955674",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.957519",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.96150",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.96510",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.97005",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.97435",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.98055",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.98557",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "20",
"Atomic Symbol" : "Ca",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.99236",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "40.078",
"Notes" : "g,f"
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "36",
"Relative Atomic Mass" : "36.01492",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "37",
"Relative Atomic Mass" : "37.00305",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "38",
"Relative Atomic Mass" : "37.99470",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "39",
"Relative Atomic Mass" : "38.984790",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "40",
"Relative Atomic Mass" : "39.977967",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "41",
"Relative Atomic Mass" : "40.96925113",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "42",
"Relative Atomic Mass" : "41.96551643",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "43",
"Relative Atomic Mass" : "42.9611507",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "44",
"Relative Atomic Mass" : "43.9594028",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "45",
"Relative Atomic Mass" : "44.9559119",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "46",
"Relative Atomic Mass" : "45.9551719",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "47",
"Relative Atomic Mass" : "46.9524075",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "48",
"Relative Atomic Mass" : "47.952231",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "49",
"Relative Atomic Mass" : "48.950024",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.952188",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.953603",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.95668",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.95961",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.96326",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.96824",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.97287",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.97779",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.98371",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.98922",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "21",
"Atomic Symbol" : "Sc",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.99571",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "44.955912",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "38",
"Relative Atomic Mass" : "38.00977",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "39",
"Relative Atomic Mass" : "39.00161",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "40",
"Relative Atomic Mass" : "39.99050",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "41",
"Relative Atomic Mass" : "40.98315",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "42",
"Relative Atomic Mass" : "41.973031",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "43",
"Relative Atomic Mass" : "42.968522",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "44",
"Relative Atomic Mass" : "43.9596901",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "45",
"Relative Atomic Mass" : "44.9581256",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "46",
"Relative Atomic Mass" : "45.9526316",
"Isotopic Composition" : "0.0825",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "47",
"Relative Atomic Mass" : "46.9517631",
"Isotopic Composition" : "0.0744",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "48",
"Relative Atomic Mass" : "47.9479463",
"Isotopic Composition" : "0.7372",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "49",
"Relative Atomic Mass" : "48.9478700",
"Isotopic Composition" : "0.0541",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.9447912",
"Isotopic Composition" : "0.0518",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.9466150",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.946897",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.94973",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.95105",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.95527",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.95820",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.96399",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.96697",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.97293",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.97676",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.98320",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.98749",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "22",
"Atomic Symbol" : "Ti",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.99442",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "47.867",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "40",
"Relative Atomic Mass" : "40.01109",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "41",
"Relative Atomic Mass" : "40.99978",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "42",
"Relative Atomic Mass" : "41.99123",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "43",
"Relative Atomic Mass" : "42.98065",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "44",
"Relative Atomic Mass" : "43.97411",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "45",
"Relative Atomic Mass" : "44.965776",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "46",
"Relative Atomic Mass" : "45.9602005",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "47",
"Relative Atomic Mass" : "46.9549089",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "48",
"Relative Atomic Mass" : "47.9522537",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "49",
"Relative Atomic Mass" : "48.9485161",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.9471585",
"Isotopic Composition" : "0.00250",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.9439595",
"Isotopic Composition" : "0.99750",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.9447755",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.944338",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.946440",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.94723",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.95053",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.95256",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.95683",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.96021",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.96503",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.96848",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.97378",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.97755",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.98347",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "23",
"Atomic Symbol" : "V",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.98792",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "50.9415",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "42",
"Relative Atomic Mass" : "42.00643",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "43",
"Relative Atomic Mass" : "42.99771",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "44",
"Relative Atomic Mass" : "43.985550",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "45",
"Relative Atomic Mass" : "44.97964",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "46",
"Relative Atomic Mass" : "45.968359",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "47",
"Relative Atomic Mass" : "46.962900",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "48",
"Relative Atomic Mass" : "47.954032",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "49",
"Relative Atomic Mass" : "48.9513357",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.9460442",
"Isotopic Composition" : "0.04345",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.9447674",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.9405075",
"Isotopic Composition" : "0.83789",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.9406494",
"Isotopic Composition" : "0.09501",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.9388804",
"Isotopic Composition" : "0.02365",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.9408397",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.9406531",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.9436130",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.94435",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.94859",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.95008",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.95472",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.95661",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.96186",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.96441",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.97016",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.97338",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "24",
"Atomic Symbol" : "Cr",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.97955",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "51.9961",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "44",
"Relative Atomic Mass" : "44.00687",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "45",
"Relative Atomic Mass" : "44.99451",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "46",
"Relative Atomic Mass" : "45.98672",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "47",
"Relative Atomic Mass" : "46.97610",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "48",
"Relative Atomic Mass" : "47.96852",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "49",
"Relative Atomic Mass" : "48.959618",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.9542382",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.9482108",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.9455655",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.9412901",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.9403589",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.9380451",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.9389049",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.9382854",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.939980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.940440",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.942910",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.94465",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.94843",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.95024",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.95425",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.95634",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.96108",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.96414",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.96930",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "25",
"Atomic Symbol" : "Mn",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.97284",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "54.938045",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "45",
"Relative Atomic Mass" : "45.01458",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "46",
"Relative Atomic Mass" : "46.00081",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "47",
"Relative Atomic Mass" : "46.99289",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "48",
"Relative Atomic Mass" : "47.980500",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "49",
"Relative Atomic Mass" : "48.97361",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.962990",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.956820",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.948114",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.9453079",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.9396105",
"Isotopic Composition" : "0.05845",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.9382934",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.9349375",
"Isotopic Composition" : "0.91754",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.9353940",
"Isotopic Composition" : "0.02119",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.9332756",
"Isotopic Composition" : "0.00282",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.9348755",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.934072",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.936745",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.936767",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.94037",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.94120",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.94538",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.94678",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.95095",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.95370",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.95878",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.96146",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.96672",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "26",
"Atomic Symbol" : "Fe",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.96962",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "55.845",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "47",
"Relative Atomic Mass" : "47.01149",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "48",
"Relative Atomic Mass" : "48.00176",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "49",
"Relative Atomic Mass" : "48.98972",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.98154",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.97072",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.963590",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.954219",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.9484596",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.9419990",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.9398393",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.9362914",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.9357528",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.9331950",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.9338171",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.9324758",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.934051",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.933612",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.935810",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.936478",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.93976",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.94089",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.94487",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.94632",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.95100",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.95290",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.95781",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.96024",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.96538",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "27",
"Atomic Symbol" : "Co",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.96833",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.933195",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "48",
"Relative Atomic Mass" : "48.01975",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "49",
"Relative Atomic Mass" : "49.00966",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "50",
"Relative Atomic Mass" : "49.99593",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "51",
"Relative Atomic Mass" : "50.98772",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.975680",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.96847",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.957910",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.951330",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.942132",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.9397935",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.9353429",
"Isotopic Composition" : "0.680769",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.9343467",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.9307864",
"Isotopic Composition" : "0.262231",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.9310560",
"Isotopic Composition" : "0.011399",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.9283451",
"Isotopic Composition" : "0.036345",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.9296694",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.9279660",
"Isotopic Composition" : "0.009256",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.9300843",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.9291393",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.931569",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.931869",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.935610",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.93650",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.94074",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.94209",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.94647",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.94807",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.95287",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.95533",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.96055",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "28",
"Atomic Symbol" : "Ni",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.96318",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "58.6934",
"Notes" : " "
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "52",
"Relative Atomic Mass" : "51.99718",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "53",
"Relative Atomic Mass" : "52.98555",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.97671",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.96605",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.95856",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.949211",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.9445385",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.9394980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.9373650",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.9334578",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.932584",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.9295975",
"Isotopic Composition" : "0.6915",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.9297642",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.9277895",
"Isotopic Composition" : "0.3085",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.9288688",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.9277303",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.9296109",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.9294293",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.9323923",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.9326768",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.9358203",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.936675",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.939875",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.94190",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.945275",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.94785",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.95196",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.95456",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "29",
"Atomic Symbol" : "Cu",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.96087",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "63.546",
"Notes" : "r"
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "54",
"Relative Atomic Mass" : "53.99295",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "55",
"Relative Atomic Mass" : "54.98398",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.97238",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.96479",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.954590",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.949260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.941827",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.939511",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.934330",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.9332116",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.9291422",
"Isotopic Composition" : "0.48268",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.9292410",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.9260334",
"Isotopic Composition" : "0.27975",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.9271273",
"Isotopic Composition" : "0.04102",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.9248442",
"Isotopic Composition" : "0.19024",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.9265503",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.9253193",
"Isotopic Composition" : "0.00631",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.927722",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.926858",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.929780",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.929460",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.932940",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.933290",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.93696",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.93844",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.94265",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.94434",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.95048",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.95442",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "30",
"Atomic Symbol" : "Zn",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.96103",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "65.38",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "56",
"Relative Atomic Mass" : "55.99491",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "57",
"Relative Atomic Mass" : "56.98293",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.97425",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.96337",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.95706",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.949450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.944175",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.9392942",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.9368387",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.9327348",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.931589",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.9282017",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.9279801",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.9255736",
"Isotopic Composition" : "0.60108",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.9260220",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.9247013",
"Isotopic Composition" : "0.39892",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.9263663",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.9251747",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.926946",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.9265002",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.9288276",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.9291543",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.9316082",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.93289",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.93652",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.93775",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.94299",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.94698",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.95265",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.95700",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "31",
"Atomic Symbol" : "Ga",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.96312",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "69.723",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "58",
"Relative Atomic Mass" : "57.99101",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "59",
"Relative Atomic Mass" : "58.98175",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.97019",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.96379",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.95465",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.94964",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.941650",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.93944",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.933840",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.932734",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.928094",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.9279645",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.9242474",
"Isotopic Composition" : "0.2038",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.9249510",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.9220758",
"Isotopic Composition" : "0.2731",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.9234589",
"Isotopic Composition" : "0.0776",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.9211778",
"Isotopic Composition" : "0.3672",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.9228589",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.9214026",
"Isotopic Composition" : "0.0783",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.9235486",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.922853",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.92540",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.925370",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.92882",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.92955",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.93462",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.93747",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.94303",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.94649",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.95251",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.95691",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "32",
"Atomic Symbol" : "Ge",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.96383",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "72.64",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "60",
"Relative Atomic Mass" : "59.99313",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "61",
"Relative Atomic Mass" : "60.98062",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "62",
"Relative Atomic Mass" : "61.97320",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "63",
"Relative Atomic Mass" : "62.96369",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "64",
"Relative Atomic Mass" : "63.95757",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.94956",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.94471",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.93919",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.936770",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.932270",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.930920",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.927112",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.926752",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.923825",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.9239287",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.9215965",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.9223940",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.9206473",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.921827",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.920948",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.922534",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.922132",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.92450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.92498",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.92906",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.93202",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.93650",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.93990",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.94494",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.94939",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.95550",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.96043",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "33",
"Atomic Symbol" : "As",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.96680",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "74.92160",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "65",
"Relative Atomic Mass" : "64.96466",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "66",
"Relative Atomic Mass" : "65.95521",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.95009",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.941800",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.939560",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.933390",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.932240",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.927112",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.926765",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.9224764",
"Isotopic Composition" : "0.0089",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.9225234",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.9192136",
"Isotopic Composition" : "0.0937",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.9199140",
"Isotopic Composition" : "0.0763",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.9173091",
"Isotopic Composition" : "0.2377",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.9184991",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.9165213",
"Isotopic Composition" : "0.4961",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.9179925",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.9166994",
"Isotopic Composition" : "0.0873",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.919118",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.918462",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.922250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.924272",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.928520",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.931420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.93645",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.93996",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.94596",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.94992",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.95629",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "34",
"Atomic Symbol" : "Se",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.96049",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "78.96",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "67",
"Relative Atomic Mass" : "66.96479",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "68",
"Relative Atomic Mass" : "67.95852",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.95011",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.94479",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.93874",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.936640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.931690",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.929891",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.925776",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.924541",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.921379",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.921146",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.9183371",
"Isotopic Composition" : "0.5069",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.9185293",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.9162906",
"Isotopic Composition" : "0.4931",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.9168041",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.915180",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.916479",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.915608",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.918798",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.920711",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.924070",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.926390",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.930630",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.933970",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.939260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.94305",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.94868",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.95287",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.95853",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "35",
"Atomic Symbol" : "Br",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.96280",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "79.904",
"Notes" : " "
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "69",
"Relative Atomic Mass" : "68.96518",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "70",
"Relative Atomic Mass" : "69.95526",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.94963",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.942092",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.939289",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.9330844",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.930946",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.925910",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.9246700",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.9203648",
"Isotopic Composition" : "0.00355",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.920082",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.9163790",
"Isotopic Composition" : "0.02286",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.9165920",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.9134836",
"Isotopic Composition" : "0.11593",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.914136",
"Isotopic Composition" : "0.11500",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.911507",
"Isotopic Composition" : "0.56987",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.9125273",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.91061073",
"Isotopic Composition" : "0.17279",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.91335486",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.914447",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.917630",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.919517",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.923450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.926156",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.93127",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.93436",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.93984",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.94307",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.94856",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.95191",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.95760",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "36",
"Atomic Symbol" : "Kr",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.96114",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "83.798",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "71",
"Relative Atomic Mass" : "70.96532",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "72",
"Relative Atomic Mass" : "71.95908",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.95056",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.944265",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.938570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.9350722",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.930408",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.928141",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.923989",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.922519",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.918996",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.9182086",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.915110",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.914385",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.911789738",
"Isotopic Composition" : "0.7217",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.91116742",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.909180527",
"Isotopic Composition" : "0.2783",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.91131559",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.912278",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.914802",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.916537",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.919729",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.922042",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.926405",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.929303",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.934270",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.937350",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.941790",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.94538",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.94987",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.95320",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "37",
"Atomic Symbol" : "Rb",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.95887",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "85.4678",
"Notes" : "g"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "73",
"Relative Atomic Mass" : "72.96597",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "74",
"Relative Atomic Mass" : "73.95631",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "75",
"Relative Atomic Mass" : "74.94995",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.941770",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.937945",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.932180",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.929708",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.924521",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.923212",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.918402",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.917557",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.913425",
"Isotopic Composition" : "0.0056",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.912933",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.9092602",
"Isotopic Composition" : "0.0986",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.9088771",
"Isotopic Composition" : "0.0700",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.9056121",
"Isotopic Composition" : "0.8258",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.9074507",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.907738",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.910203",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.911038",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.914026",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.915361",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.919359",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.921697",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.926153",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.928453",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.933240",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.93535",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.94052",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.94302",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.94895",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.95233",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "38",
"Atomic Symbol" : "Sr",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.95858",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "87.62",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "76",
"Relative Atomic Mass" : "75.95845",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "77",
"Relative Atomic Mass" : "76.949650",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.94361",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.93735",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.93428",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.929130",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.92679",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.922350",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.92039",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.916433",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.914886",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.9108757",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.9095011",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.9058483",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.9071519",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.907305",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.908949",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.909583",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.911595",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.912821",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.915891",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.918134",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.922203",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.924636",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.927760",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.93031",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.933560",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.93673",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.94105",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.94487",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.94979",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.95414",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "39",
"Atomic Symbol" : "Y",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.95948",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "88.90585",
"Notes" : " "
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "78",
"Relative Atomic Mass" : "77.95523",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "79",
"Relative Atomic Mass" : "78.94916",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "80",
"Relative Atomic Mass" : "79.94040",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.93721",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.93109",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.92865",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.92325",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.92147",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.916470",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.914816",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.910227",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.908890",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.9047044",
"Isotopic Composition" : "0.5145",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.9056458",
"Isotopic Composition" : "0.1122",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.9050408",
"Isotopic Composition" : "0.1715",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.9064760",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.9063152",
"Isotopic Composition" : "0.1738",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.9080426",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.9082734",
"Isotopic Composition" : "0.0280",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.9109531",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.912735",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.916512",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.917760",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.921140",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.922980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.92660",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.92878",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.93305",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.93591",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.94075",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.94396",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.94924",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "40",
"Atomic Symbol" : "Zr",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.95287",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "91.224",
"Notes" : "g"
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "81",
"Relative Atomic Mass" : "80.94903",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "82",
"Relative Atomic Mass" : "81.94313",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.93671",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.93357",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.92791",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.925040",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.920360",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.91833",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.913418",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.911265",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.906996",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.907194",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.9063781",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.9072839",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.9068358",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.908101",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.9080986",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.910328",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.911618",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.914182",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.915252",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.918040",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.919140",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.92246",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.92394",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.92797",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.93031",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.93484",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.93763",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.94244",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.94565",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.95083",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "41",
"Atomic Symbol" : "Nb",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.95470",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "92.90638",
"Notes" : " "
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "83",
"Relative Atomic Mass" : "82.94874",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "84",
"Relative Atomic Mass" : "83.94009",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.93655",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.93070",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.92733",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.921953",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.919480",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.913937",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.911750",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.906811",
"Isotopic Composition" : "0.1477",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.906813",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.9050883",
"Isotopic Composition" : "0.0923",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.9058421",
"Isotopic Composition" : "0.1590",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.9046795",
"Isotopic Composition" : "0.1668",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.9060215",
"Isotopic Composition" : "0.0956",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.9054082",
"Isotopic Composition" : "0.2419",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.9077119",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.907477",
"Isotopic Composition" : "0.0967",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.910347",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.910297",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.913210",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.913760",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.916970",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.918137",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.92169",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.92345",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.92781",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.92973",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.93441",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.93684",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.94188",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.94492",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "42",
"Atomic Symbol" : "Mo",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.95029",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "95.96",
"Notes" : "g"
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "85",
"Relative Atomic Mass" : "84.94883",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "86",
"Relative Atomic Mass" : "85.94288",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.93653",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.93268",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.92717",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.92356",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.91843",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.915260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.910249",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.909657",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.907657",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.907871",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.906365",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.907216",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.9062547",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.9076578",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.907315",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.909215",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.909181",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.911450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.911660",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.914358",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.91508",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.91846",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.91998",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.923820",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.92569",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.92915",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.93159",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.93588",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.93869",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.94337",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.94648",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "43",
"Atomic Symbol" : "Tc",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.95148",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "98",
"Notes" : " "
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "87",
"Relative Atomic Mass" : "86.94918",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "88",
"Relative Atomic Mass" : "87.94026",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.93611",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.92989",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.92629",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.92012",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.917050",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.911360",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.910413",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.907598",
"Isotopic Composition" : "0.0554",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.907555",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.905287",
"Isotopic Composition" : "0.0187",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.9059393",
"Isotopic Composition" : "0.1276",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.9042195",
"Isotopic Composition" : "0.1260",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.9055821",
"Isotopic Composition" : "0.1706",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.9043493",
"Isotopic Composition" : "0.3155",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.9063238",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.905433",
"Isotopic Composition" : "0.1862",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.907753",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.907329",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.90991",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.91017",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.913200",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.914140",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.917700",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.918970",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.922490",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.92428",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.92869",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.93081",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.93558",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.93782",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.94284",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "44",
"Atomic Symbol" : "Ru",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.94531",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "101.07",
"Notes" : "g"
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "89",
"Relative Atomic Mass" : "88.94884",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "90",
"Relative Atomic Mass" : "89.94287",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.93655",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.93198",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.92574",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.92170",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.91590",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.914461",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.911340",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.910708",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.908132",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.908122",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.906164",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.906843",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.905504",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.906656",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.905694",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.907287",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.906748",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.90873",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.908737",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.911140",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.911590",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.914390",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.915530",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.91881",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.920330",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.92406",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.92598",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.93007",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.93211",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.93641",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.93872",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "45",
"Atomic Symbol" : "Rh",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.94321",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "102.90550",
"Notes" : " "
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "91",
"Relative Atomic Mass" : "90.94911",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "92",
"Relative Atomic Mass" : "91.94042",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.93591",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.92877",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.92469",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.91816",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.91648",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.912721",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.911768",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.908506",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.908289",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.905609",
"Isotopic Composition" : "0.0102",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.906087",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.904036",
"Isotopic Composition" : "0.1114",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.905085",
"Isotopic Composition" : "0.2233",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.903486",
"Isotopic Composition" : "0.2733",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.905133",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.903892",
"Isotopic Composition" : "0.2646",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.905950",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.905153",
"Isotopic Composition" : "0.1172",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.907671",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.907314",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.910150",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.910363",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.913680",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.914160",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.917840",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.91898",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.92311",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.92469",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.92887",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.93055",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.93493",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "46",
"Atomic Symbol" : "Pd",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.93688",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "106.42",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "93",
"Relative Atomic Mass" : "92.94978",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "94",
"Relative Atomic Mass" : "93.94278",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.93548",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.93068",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.92397",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.921570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.91760",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.916100",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.91280",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.911690",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.908973",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.908629",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.906529",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.906669",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.905097",
"Isotopic Composition" : "0.51839",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.905956",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.904752",
"Isotopic Composition" : "0.48161",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.906107",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.905291",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.907005",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.906567",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.908804",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.908760",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.911360",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.911680",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.914580",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.91567",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.918790",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.91985",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.92353",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.92490",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.92864",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.93043",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.93450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.93677",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.94117",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.94369",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "47",
"Atomic Symbol" : "Ag",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.95045",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "107.8682",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "95",
"Relative Atomic Mass" : "94.94987",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "96",
"Relative Atomic Mass" : "95.93977",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.93494",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.927400",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.92501",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.92029",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.91868",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.914460",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.913419",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.909849",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.909468",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.906459",
"Isotopic Composition" : "0.0125",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.906618",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.904184",
"Isotopic Composition" : "0.0089",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.904982",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.9030021",
"Isotopic Composition" : "0.1249",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.9041781",
"Isotopic Composition" : "0.1280",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.9027578",
"Isotopic Composition" : "0.2413",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.9044017",
"Isotopic Composition" : "0.1222",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.9033585",
"Isotopic Composition" : "0.2873",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.9054310",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.904756",
"Isotopic Composition" : "0.0749",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.907219",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.906915",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.909920",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.909850",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.912980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.913330",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.917000",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.917650",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.921250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.922350",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.926440",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.92776",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.93215",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.93390",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.94067",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "48",
"Atomic Symbol" : "Cd",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.94555",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "112.411",
"Notes" : "g"
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "97",
"Relative Atomic Mass" : "96.94954",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "98",
"Relative Atomic Mass" : "97.94214",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.93422",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.93111",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.92634",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.92409",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.919914",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.918300",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.914674",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.913465",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.910295",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.909698",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.907151",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.907165",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.905103",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.905532",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.904058",
"Isotopic Composition" : "0.0429",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.904914",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.903878",
"Isotopic Composition" : "0.9571",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.905260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.904514",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.906354",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.905845",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.907960",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.907846",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.910280",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.910438",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.913180",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.913600",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.916460",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.917350",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.920170",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.921700",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.924970",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.926850",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.932990",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.93781",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.94415",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "49",
"Atomic Symbol" : "In",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.94933",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "114.818",
"Notes" : " "
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "99",
"Relative Atomic Mass" : "98.94933",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "100",
"Relative Atomic Mass" : "99.93904",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "101",
"Relative Atomic Mass" : "100.93606",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "102",
"Relative Atomic Mass" : "101.93030",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.92810",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.92314",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.921350",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.916880",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.915640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.911925",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.911283",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.907843",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.907734",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.904818",
"Isotopic Composition" : "0.0097",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.905171",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.902779",
"Isotopic Composition" : "0.0066",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.903342",
"Isotopic Composition" : "0.0034",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.901741",
"Isotopic Composition" : "0.1454",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.902952",
"Isotopic Composition" : "0.0768",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.901603",
"Isotopic Composition" : "0.2422",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.903308",
"Isotopic Composition" : "0.0859",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.9021947",
"Isotopic Composition" : "0.3258",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.9042355",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.9034390",
"Isotopic Composition" : "0.0463",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.9057208",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.9052739",
"Isotopic Composition" : "0.0579",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.9077841",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.907653",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.910360",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.910537",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.913480",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.913967",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.917000",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.917816",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.923830",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.92829",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.93473",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.93934",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "50",
"Atomic Symbol" : "Sn",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.94599",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "118.710",
"Notes" : "g,e"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "103",
"Relative Atomic Mass" : "102.93969",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "104",
"Relative Atomic Mass" : "103.93647",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.93149",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.92879",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.92415",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.92216",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.918132",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.91675",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.913160",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.912398",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.909372",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.909270",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.906598",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.906794",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.904836",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.905529",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.903942",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.905072",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.9038157",
"Isotopic Composition" : "0.5721",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.9051737",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.9042140",
"Isotopic Composition" : "0.4279",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.9059357",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.9052538",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.907250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.906924",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.909169",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.909148",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.911656",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.911982",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.914467",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.915252",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.920380",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.92517",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.93035",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.93531",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.94079",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "51",
"Atomic Symbol" : "Sb",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.94598",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "121.760",
"Notes" : "g"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "105",
"Relative Atomic Mass" : "104.94364",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "106",
"Relative Atomic Mass" : "105.93750",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "107",
"Relative Atomic Mass" : "106.93501",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.92944",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.927420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.922410",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.921110",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.91701",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.915890",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.912090",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.911900",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.908460",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.908645",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.905828",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.906404",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.904020",
"Isotopic Composition" : "0.0009",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.904936",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.9030439",
"Isotopic Composition" : "0.0255",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.9042700",
"Isotopic Composition" : "0.0089",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.9028179",
"Isotopic Composition" : "0.0474",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.9044307",
"Isotopic Composition" : "0.0707",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.9033117",
"Isotopic Composition" : "0.1884",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.9052263",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.9044631",
"Isotopic Composition" : "0.3174",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.9065982",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.9062244",
"Isotopic Composition" : "0.3408",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.9085239",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.908553",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.910955",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.911369",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.91645",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.920100",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.92532",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.92922",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.93473",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.93885",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.94465",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "52",
"Atomic Symbol" : "Te",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.94908",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "127.60",
"Notes" : "g,h"
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "108",
"Relative Atomic Mass" : "107.94348",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "109",
"Relative Atomic Mass" : "108.93815",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.93524",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.93028",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.92797",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.923640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.92185",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.918050",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.91681",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.913650",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.913074",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.910070",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.910048",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.907367",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.907589",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.905589",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.9062099",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.9046302",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.905624",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.904473",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.905809",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.904988",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.906674",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.9061246",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.907997",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.907797",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.909744",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.910048",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.914650",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.917871",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.922350",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.926100",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.93100",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.93503",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.94018",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.94456",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "53",
"Atomic Symbol" : "I",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.94999",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "126.90447",
"Notes" : " "
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "110",
"Relative Atomic Mass" : "109.94428",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "111",
"Relative Atomic Mass" : "110.94160",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.93562",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.933340",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.927980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.926294",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.921581",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.920359",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.916179",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.915411",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.911784",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.911462",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.908368",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.908482",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.9058930",
"Isotopic Composition" : "0.000952",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.9063955",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.904274",
"Isotopic Composition" : "0.000890",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.905184",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.9035313",
"Isotopic Composition" : "0.019102",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.9047794",
"Isotopic Composition" : "0.264006",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.9035080",
"Isotopic Composition" : "0.040710",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.9050824",
"Isotopic Composition" : "0.212324",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.9041535",
"Isotopic Composition" : "0.269086",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.9059107",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.9053945",
"Isotopic Composition" : "0.104357",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.907227",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.907219",
"Isotopic Composition" : "0.088573",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.911562",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.913950",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.918793",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.921640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.92665",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.92971",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.93511",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.93851",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.94407",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.94775",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "54",
"Atomic Symbol" : "Xe",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.95356",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "131.293",
"Notes" : "g,m,a"
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "112",
"Relative Atomic Mass" : "111.95030",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "113",
"Relative Atomic Mass" : "112.94449",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.94145",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.93591",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.93337",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.928670",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.926559",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.922377",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.920677",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.917229",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.916110",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.912996",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.912258",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.909728",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.909452",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.907418",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.907749",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.906064",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.906709",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.905464",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.9064343",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.905451933",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.906718475",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.9059770",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.9073116",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.9070895",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.911017",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.913364",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.917282",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.920046",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.924299",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.927352",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.932077",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.935526",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.940290",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.944160",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.94922",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.95293",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.95817",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "55",
"Atomic Symbol" : "Cs",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.96219",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "132.9054519",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "114",
"Relative Atomic Mass" : "113.95068",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "115",
"Relative Atomic Mass" : "114.94737",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "116",
"Relative Atomic Mass" : "115.94138",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.93850",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.93304",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.93066",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.92604",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.92405",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.919900",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.918781",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.915094",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.914473",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.911250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.911094",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.908318",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.908679",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.9063208",
"Isotopic Composition" : "0.00106",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.906941",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.9050613",
"Isotopic Composition" : "0.00101",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.9060075",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.9045084",
"Isotopic Composition" : "0.02417",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.9056886",
"Isotopic Composition" : "0.06592",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.9045759",
"Isotopic Composition" : "0.07854",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.9058274",
"Isotopic Composition" : "0.11232",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.9052472",
"Isotopic Composition" : "0.71698",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.9088413",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.910605",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.914411",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.916453",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.920627",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.922953",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.927630",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.930220",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.93495",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.937720",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.94258",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.94568",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.95081",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.95427",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "56",
"Atomic Symbol" : "Ba",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.95961",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "137.327",
"Notes" : " "
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "117",
"Relative Atomic Mass" : "116.95007",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "118",
"Relative Atomic Mass" : "117.94673",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.94099",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.93807",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.93301",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.93071",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.92624",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.924570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.920816",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.91951",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.916375",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.915590",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.912693",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.912369",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.910070",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.910100",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.908220",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.908514",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.906977",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.907640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.906494",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.907112",
"Isotopic Composition" : "0.00090",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.9063533",
"Isotopic Composition" : "0.99910",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.9094776",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.910962",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.914079",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.916063",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.919600",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.92165",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.925790",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.928240",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.932230",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.93473",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.93877",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.94172",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.94625",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.94962",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.95450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "57",
"Atomic Symbol" : "La",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.95835",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "138.90547",
"Notes" : "g"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "119",
"Relative Atomic Mass" : "118.95276",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "120",
"Relative Atomic Mass" : "119.94664",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.94342",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.93791",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.93540",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.93041",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.92844",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.923970",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.922730",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.918910",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.918100",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.914740",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.914420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.911460",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.911515",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.908925",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.909151",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.907172",
"Isotopic Composition" : "0.00185",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.907806",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.905991",
"Isotopic Composition" : "0.00251",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.906653",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.9054387",
"Isotopic Composition" : "0.88450",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.9082763",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.909244",
"Isotopic Composition" : "0.11114",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.912386",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.913647",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.917230",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.918760",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.922670",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.924430",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.92840",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.930410",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.93398",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.93654",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.94058",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.94342",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.94804",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.95126",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "58",
"Atomic Symbol" : "Ce",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.95634",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.116",
"Notes" : "g,f"
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "121",
"Relative Atomic Mass" : "120.95536",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "122",
"Relative Atomic Mass" : "121.95181",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "123",
"Relative Atomic Mass" : "122.94596",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.94296",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.93783",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.93531",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.93083",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.928790",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.925100",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.923590",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.920260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.919260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.916331",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.915710",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.913112",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.912692",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.910705",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.910755",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.908938",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.909076",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.9076528",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.9100448",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.9108169",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.913305",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.914512",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.917640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.918996",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.922135",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.923720",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.926673",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.928319",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.93150",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.93384",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.93752",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.94012",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.94427",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.94743",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.95198",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "59",
"Atomic Symbol" : "Pr",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.95550",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "140.90765",
"Notes" : " "
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "124",
"Relative Atomic Mass" : "123.95223",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "125",
"Relative Atomic Mass" : "124.94888",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.94322",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.94050",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.93539",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.93319",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.928510",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.927250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.923321",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.922350",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.918790",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.918181",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.914976",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.914567",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.911950",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.911978",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.909550",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.909610",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.9077233",
"Isotopic Composition" : "0.272",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.9098143",
"Isotopic Composition" : "0.122",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.9100873",
"Isotopic Composition" : "0.238",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.9125736",
"Isotopic Composition" : "0.083",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.9131169",
"Isotopic Composition" : "0.172",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.9161004",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.916893",
"Isotopic Composition" : "0.057",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.920149",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.920891",
"Isotopic Composition" : "0.056",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.923829",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.924682",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.927698",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.92948",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.93293",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.93502",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.93903",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.94160",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.94609",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.94909",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "60",
"Atomic Symbol" : "Nd",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.95388",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "144.242",
"Notes" : "g,f"
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "126",
"Relative Atomic Mass" : "125.95752",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "127",
"Relative Atomic Mass" : "126.95163",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.94842",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.94316",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.94045",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.93587",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.93375",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.929780",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.928350",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.924880",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.923570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.920479",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.919548",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.916804",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.916040",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.913555",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.912874",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.910933",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.912591",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.912749",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.914696",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.9151385",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.917475",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.918334",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.920984",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.921207",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.923497",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.924117",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.926460",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.928100",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.931060",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.93304",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.93656",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.93897",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.94299",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.94586",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.95029",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "61",
"Atomic Symbol" : "Pm",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.95368",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "145",
"Notes" : " "
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "128",
"Relative Atomic Mass" : "127.95808",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "129",
"Relative Atomic Mass" : "128.95464",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.94892",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.94611",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.94069",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.93867",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.93397",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.93252",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.928276",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.926970",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.923244",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.922297",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.918995",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.918476",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.915198",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.914628",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.911999",
"Isotopic Composition" : "0.0307",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.913410",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.913041",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.9148979",
"Isotopic Composition" : "0.1499",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.9148227",
"Isotopic Composition" : "0.1124",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.9171847",
"Isotopic Composition" : "0.1382",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.9172755",
"Isotopic Composition" : "0.0738",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.9199324",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.9197324",
"Isotopic Composition" : "0.2675",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.9220974",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.9222093",
"Isotopic Composition" : "0.2275",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.9246402",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.925528",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.928360",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.929990",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.93321",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.93514",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.93883",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.94122",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.94536",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.94828",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "62",
"Atomic Symbol" : "Sm",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.95298",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "150.36",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "130",
"Relative Atomic Mass" : "129.96357",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "131",
"Relative Atomic Mass" : "130.95775",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "132",
"Relative Atomic Mass" : "131.95437",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "133",
"Relative Atomic Mass" : "132.94924",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.94651",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.94182",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.93960",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.93557",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.933710",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.929792",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.928090",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.924931",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.923430",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.920298",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.918817",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.916265",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.917206",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.916746",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.918086",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.917931",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.919702",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.9198502",
"Isotopic Composition" : "0.4781",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.9217445",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.9212303",
"Isotopic Composition" : "0.5219",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.9229792",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.9228933",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.924752",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.925424",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.927850",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.929089",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.93197",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.93368",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.93704",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.93921",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.94299",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.94572",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.94997",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "63",
"Atomic Symbol" : "Eu",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.95321",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "151.964",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "134",
"Relative Atomic Mass" : "133.95537",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "135",
"Relative Atomic Mass" : "134.95257",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.94734",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.94502",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.94012",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.93824",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.933670",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.932126",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.928120",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.92675",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.922960",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.921709",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.918311",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.919094",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.918115",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.919341",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.918659",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.920348",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.9197910",
"Isotopic Composition" : "0.0020",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.9217495",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.9208656",
"Isotopic Composition" : "0.0218",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.9226220",
"Isotopic Composition" : "0.1480",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.9221227",
"Isotopic Composition" : "0.2047",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.9239601",
"Isotopic Composition" : "0.1565",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.9241039",
"Isotopic Composition" : "0.2484",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.9263887",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.9270541",
"Isotopic Composition" : "0.2186",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.9296692",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.930985",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.93399",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.93586",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.93938",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.94160",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.94557",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.94836",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "64",
"Atomic Symbol" : "Gd",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.95287",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "157.25",
"Notes" : "g"
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "136",
"Relative Atomic Mass" : "135.96138",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "137",
"Relative Atomic Mass" : "136.95598",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.95316",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.94829",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.94581",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.94145",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.93874",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.935120",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.933050",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.929270",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.927250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.924045",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.924272",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.923246",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.923660",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.923103",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.924070",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.923435",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.924680",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.923505",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.924747",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.9240246",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.9254131",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.9253468",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.9271676",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.9275699",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.929490",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.930648",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.93335",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.93488",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.93799",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.94005",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.94364",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.94622",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.95025",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "65",
"Atomic Symbol" : "Tb",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.95330",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "158.92535",
"Notes" : " "
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "138",
"Relative Atomic Mass" : "137.96249",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "139",
"Relative Atomic Mass" : "138.95954",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.95401",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.95135",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.94637",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.94383",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.939250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.937430",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.932845",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.931092",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.927150",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.927305",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.925585",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.926185",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.924718",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.925765",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.924424",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.925754",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.924283",
"Isotopic Composition" : "0.00056",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.925466",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.924409",
"Isotopic Composition" : "0.00095",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.9257392",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.9251975",
"Isotopic Composition" : "0.02329",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.9269334",
"Isotopic Composition" : "0.18889",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.9267984",
"Isotopic Composition" : "0.25475",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.9287312",
"Isotopic Composition" : "0.24896",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.9291748",
"Isotopic Composition" : "0.28260",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.9317033",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.9328067",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.935660",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.93713",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.94031",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.94239",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.94620",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.94876",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "66",
"Atomic Symbol" : "Dy",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.95300",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "162.500",
"Notes" : "g"
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "140",
"Relative Atomic Mass" : "139.96854",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "141",
"Relative Atomic Mass" : "140.96310",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "142",
"Relative Atomic Mass" : "141.95977",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.95461",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.95148",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.94720",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.94464",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.940060",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.93772",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.933775",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.933496",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.931688",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.931714",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.930199",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.930602",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.929103",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.929840",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.928256",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.928941",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.927712",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.928729",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.927855",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.929096",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.9287339",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.9302335",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.9303221",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.9322842",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.933133",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.935520",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.936872",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.939620",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.94147",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.94482",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.94729",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.95115",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "67",
"Atomic Symbol" : "Ho",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.95405",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "164.93032",
"Notes" : " "
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "143",
"Relative Atomic Mass" : "142.96634",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "144",
"Relative Atomic Mass" : "143.96038",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.95739",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.95200",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.94949",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.94455",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.942310",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.937914",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.937449",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.935050",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.935063",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.932783",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.933209",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.931065",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.931920",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.929893",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.930684",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.929083",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.929995",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.928778",
"Isotopic Composition" : "0.00139",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.930033",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.929200",
"Isotopic Composition" : "0.01601",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.930726",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.9302931",
"Isotopic Composition" : "0.33503",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.9320482",
"Isotopic Composition" : "0.22869",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.9323702",
"Isotopic Composition" : "0.26978",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.9345904",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.9354643",
"Isotopic Composition" : "0.14910",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.9380298",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.939356",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.94240",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.94423",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.94777",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.95008",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "68",
"Atomic Symbol" : "Er",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.95405",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "167.259",
"Notes" : "g"
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "145",
"Relative Atomic Mass" : "144.97007",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "146",
"Relative Atomic Mass" : "145.96643",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "147",
"Relative Atomic Mass" : "146.96096",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.95784",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.95272",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.94996",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.945483",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.944420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.942012",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.941568",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.939199",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.938980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.936970",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.936980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.934980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.935260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.933550",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.933995",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.932651",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.933560",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.932435",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.933554",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.9328516",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.934173",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.9342133",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.9358014",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.9364294",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.938400",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.939604",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.942170",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.943840",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.94699",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.94904",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.95264",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.95534",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},
 
{
"Atomic Number" : "69",
"Atomic Symbol" : "Tm",
"Mass Number" : "180",
"Relative Atomic Mass" : "",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "168.93421",
"Notes" : " "
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "148",
"Relative Atomic Mass" : "147.96742",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "149",
"Relative Atomic Mass" : "148.96404",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.95842",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.95540",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.95029",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.94948",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.946394",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.945782",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.942818",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.942628",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.939866",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.940050",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.937552",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.937902",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.935768",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.936334",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.934489",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.935280",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.933882",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.934950",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.933897",
"Isotopic Composition" : "0.0013",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.935190",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.9347618",
"Isotopic Composition" : "0.0304",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.9363258",
"Isotopic Composition" : "0.1428",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.9363815",
"Isotopic Composition" : "0.2183",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.9382108",
"Isotopic Composition" : "0.1613",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.9388621",
"Isotopic Composition" : "0.3183",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.9412765",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.9425717",
"Isotopic Composition" : "0.1276",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.9452608",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.946647",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.95017",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.95233",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "70",
"Atomic Symbol" : "Yb",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.95615",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "173.054",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "150",
"Relative Atomic Mass" : "149.97323",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "151",
"Relative Atomic Mass" : "150.96758",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "152",
"Relative Atomic Mass" : "151.96412",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.95877",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.95752",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.954316",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.953030",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.950098",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.949313",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.946630",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.946030",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.943570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.943280",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.941180",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.941340",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.939407",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.939860",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.938270",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.938740",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.937651",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.938475",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.9379131",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.939086",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.9389306",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.9403375",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.9407718",
"Isotopic Composition" : "0.9741",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.9426863",
"Isotopic Composition" : "0.0259",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.9437581",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.945955",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.947327",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.949880",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.95197",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.95504",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.95757",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "71",
"Atomic Symbol" : "Lu",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.96091",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "174.9668",
"Notes" : "g"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "153",
"Relative Atomic Mass" : "152.97069",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "154",
"Relative Atomic Mass" : "153.96486",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.96339",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.95936",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.95840",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.954799",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.953995",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.950684",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.950275",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.947210",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.947090",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.944367",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.944570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.942180",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.942600",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.940570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.941260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.939610",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.940490",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.939448",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.940510",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.940046",
"Isotopic Composition" : "0.0016",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.941509",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.9414086",
"Isotopic Composition" : "0.0526",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.9432207",
"Isotopic Composition" : "0.1860",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.9436988",
"Isotopic Composition" : "0.2728",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.9458161",
"Isotopic Composition" : "0.1362",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.9465500",
"Isotopic Composition" : "0.3508",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.9491012",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.950554",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.953530",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.955450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.95882",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.96089",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.96459",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "72",
"Atomic Symbol" : "Hf",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.96685",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "178.49",
"Notes" : "f"
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "155",
"Relative Atomic Mass" : "154.97459",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "156",
"Relative Atomic Mass" : "155.97230",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "157",
"Relative Atomic Mass" : "156.96819",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.96670",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.963018",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.96149",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.958420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.957290",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.954330",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.953530",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.950773",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.950510",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.948090",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.948050",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.946010",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.946180",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.944480",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.944900",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.943750",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.944450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.943740",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.944860",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.944472",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.945778",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.9459295",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.9474648",
"Isotopic Composition" : "0.00012",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.9479958",
"Isotopic Composition" : "0.99988",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.9501518",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.9513726",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.954008",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.955559",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.958550",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.96053",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.96370",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.96583",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "73",
"Atomic Symbol" : "Ta",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.96923",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "180.94788",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "158",
"Relative Atomic Mass" : "157.97456",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "159",
"Relative Atomic Mass" : "158.97292",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.96848",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.96736",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.963497",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.962520",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.958954",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.958280",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.955027",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.954816",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.951808",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.951779",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.949228",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.949450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.947290",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.947690",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.946080",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.946720",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.945630",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.946640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.945876",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.947070",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.946704",
"Isotopic Composition" : "0.0012",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.948197",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.9482042",
"Isotopic Composition" : "0.2650",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.9502230",
"Isotopic Composition" : "0.1431",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.9509312",
"Isotopic Composition" : "0.3064",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.9534193",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.9543641",
"Isotopic Composition" : "0.2843",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.9571605",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.958489",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.96191",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.96318",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.96660",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "74",
"Atomic Symbol" : "W",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.96817",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "183.84",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "160",
"Relative Atomic Mass" : "159.98212",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "161",
"Relative Atomic Mass" : "160.97759",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.97600",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.972081",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.97032",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.967089",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.965810",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.962600",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.961570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.958790",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.958220",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.955720",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.955420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.953240",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.953120",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.951380",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.951620",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.950330",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.950990",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.949988",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.950789",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.950068",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.95121",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.950820",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.952521",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.9529550",
"Isotopic Composition" : "0.3740",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.9549861",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.9557531",
"Isotopic Composition" : "0.6260",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.9581144",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.959229",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.96182",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.963125",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.96596",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.96747",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "75",
"Atomic Symbol" : "Re",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.97042",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "186.207",
"Notes" : " "
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "162",
"Relative Atomic Mass" : "161.98443",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "163",
"Relative Atomic Mass" : "162.98269",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.97804",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.97676",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.972691",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.971550",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.967804",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.967019",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.963577",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.963185",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.960023",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.959808",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.957062",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.956946",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.954810",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.954965",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.953251",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.953816",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.952379",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.953240",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.952110",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.953130",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.9524891",
"Isotopic Composition" : "0.0002",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.9540423",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.9538382",
"Isotopic Composition" : "0.0159",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.9557505",
"Isotopic Composition" : "0.0196",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.9558382",
"Isotopic Composition" : "0.1324",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.9581475",
"Isotopic Composition" : "0.1615",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.9584470",
"Isotopic Composition" : "0.2626",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.9609297",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.9614807",
"Isotopic Composition" : "0.4078",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.9641516",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.9651821",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "195",
"Relative Atomic Mass" : "194.96813",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "76",
"Atomic Symbol" : "Os",
"Mass Number" : "196",
"Relative Atomic Mass" : "195.969640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "190.23",
"Notes" : "g,f"
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "164",
"Relative Atomic Mass" : "163.99220",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "165",
"Relative Atomic Mass" : "164.98752",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.98582",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.981665",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.97988",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.976295",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.97497",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.971630",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.97046",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.967502",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.966861",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.964113",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.963649",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.961302",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.961082",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.959122",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.959229",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.957625",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.958076",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.956846",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.957480",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.956700",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.957946",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.957363",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.958853",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.958719",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.9605460",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.9605940",
"Isotopic Composition" : "0.373",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.9626050",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.9629264",
"Isotopic Composition" : "0.627",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.9650784",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "195",
"Relative Atomic Mass" : "194.9659796",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "196",
"Relative Atomic Mass" : "195.968400",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "197",
"Relative Atomic Mass" : "196.969653",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "198",
"Relative Atomic Mass" : "197.97228",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "77",
"Atomic Symbol" : "Ir",
"Mass Number" : "199",
"Relative Atomic Mass" : "198.973800",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "192.217",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "166",
"Relative Atomic Mass" : "165.99486",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "167",
"Relative Atomic Mass" : "166.99298",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "168",
"Relative Atomic Mass" : "167.98815",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.98672",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.982495",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.981240",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.977347",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.976440",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.972819",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.972421",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.968945",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.968469",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.965649",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.965363",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.963031",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.963097",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.961171",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.961597",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.959922",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.960620",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.959351",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.960590",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.959395",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.960834",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.959932",
"Isotopic Composition" : "0.00014",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.961677",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.9610380",
"Isotopic Composition" : "0.00782",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.9629874",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.9626803",
"Isotopic Composition" : "0.32967",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "195",
"Relative Atomic Mass" : "194.9647911",
"Isotopic Composition" : "0.33832",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "196",
"Relative Atomic Mass" : "195.9649515",
"Isotopic Composition" : "0.25242",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "197",
"Relative Atomic Mass" : "196.9673402",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "198",
"Relative Atomic Mass" : "197.967893",
"Isotopic Composition" : "0.07163",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "199",
"Relative Atomic Mass" : "198.970593",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "200",
"Relative Atomic Mass" : "199.971441",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "201",
"Relative Atomic Mass" : "200.974510",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "202",
"Relative Atomic Mass" : "201.97574",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},
 
{
"Atomic Number" : "78",
"Atomic Symbol" : "Pt",
"Mass Number" : "203",
"Relative Atomic Mass" : "",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "195.084",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "169",
"Relative Atomic Mass" : "168.99808",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "170",
"Relative Atomic Mass" : "169.99612",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "171",
"Relative Atomic Mass" : "170.991879",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.99004",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.986237",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.98476",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.981270",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.98010",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.976865",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.976030",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.973213",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.972521",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.970079",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.969618",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.967593",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.967452",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.965789",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.965953",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.964568",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.965324",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.963948",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.964700",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.963700",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.964813",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.964150",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.965365",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "195",
"Relative Atomic Mass" : "194.9650346",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "196",
"Relative Atomic Mass" : "195.966570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "197",
"Relative Atomic Mass" : "196.9665687",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "198",
"Relative Atomic Mass" : "197.9682423",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "199",
"Relative Atomic Mass" : "198.9687652",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "200",
"Relative Atomic Mass" : "199.970730",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "201",
"Relative Atomic Mass" : "200.971657",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "202",
"Relative Atomic Mass" : "201.97381",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "203",
"Relative Atomic Mass" : "202.975155",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "204",
"Relative Atomic Mass" : "203.97772",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "79",
"Atomic Symbol" : "Au",
"Mass Number" : "205",
"Relative Atomic Mass" : "204.97987",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "196.966569",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "171",
"Relative Atomic Mass" : "171.00376",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "172",
"Relative Atomic Mass" : "171.99883",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "173",
"Relative Atomic Mass" : "172.99724",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "174",
"Relative Atomic Mass" : "173.992864",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "175",
"Relative Atomic Mass" : "174.99142",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "176",
"Relative Atomic Mass" : "175.987355",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.986280",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.982483",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.981834",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.978266",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.977819",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.974690",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.974450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.971713",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.971899",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.969362",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.969814",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.967577",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.968190",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.966322",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.967157",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.965634",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.966665",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.965439",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "195",
"Relative Atomic Mass" : "194.966720",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "196",
"Relative Atomic Mass" : "195.965833",
"Isotopic Composition" : "0.0015",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "197",
"Relative Atomic Mass" : "196.967213",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "198",
"Relative Atomic Mass" : "197.9667690",
"Isotopic Composition" : "0.0997",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "199",
"Relative Atomic Mass" : "198.9682799",
"Isotopic Composition" : "0.1687",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "200",
"Relative Atomic Mass" : "199.9683260",
"Isotopic Composition" : "0.2310",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "201",
"Relative Atomic Mass" : "200.9703023",
"Isotopic Composition" : "0.1318",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "202",
"Relative Atomic Mass" : "201.9706430",
"Isotopic Composition" : "0.2986",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "203",
"Relative Atomic Mass" : "202.9728725",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "204",
"Relative Atomic Mass" : "203.9734939",
"Isotopic Composition" : "0.0687",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "205",
"Relative Atomic Mass" : "204.976073",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "206",
"Relative Atomic Mass" : "205.977514",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "207",
"Relative Atomic Mass" : "206.98259",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "208",
"Relative Atomic Mass" : "207.98594",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "209",
"Relative Atomic Mass" : "208.99104",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "80",
"Atomic Symbol" : "Hg",
"Mass Number" : "210",
"Relative Atomic Mass" : "209.99451",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "200.59",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "176",
"Relative Atomic Mass" : "176.00059",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "177",
"Relative Atomic Mass" : "176.996427",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "178",
"Relative Atomic Mass" : "177.99490",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "179",
"Relative Atomic Mass" : "178.991090",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.98991",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.986257",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.985670",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.982193",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.981870",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.978790",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.97833",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.975906",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.976010",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.973588",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.973880",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.971786",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.972230",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.97067",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.97120",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "195",
"Relative Atomic Mass" : "194.969774",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "196",
"Relative Atomic Mass" : "195.970481",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "197",
"Relative Atomic Mass" : "196.969575",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "198",
"Relative Atomic Mass" : "197.970480",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "199",
"Relative Atomic Mass" : "198.969880",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "200",
"Relative Atomic Mass" : "199.970963",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "201",
"Relative Atomic Mass" : "200.970819",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "202",
"Relative Atomic Mass" : "201.972106",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "203",
"Relative Atomic Mass" : "202.9723442",
"Isotopic Composition" : "0.2952",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "204",
"Relative Atomic Mass" : "203.9738635",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "205",
"Relative Atomic Mass" : "204.9744275",
"Isotopic Composition" : "0.7048",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "206",
"Relative Atomic Mass" : "205.9761103",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "207",
"Relative Atomic Mass" : "206.977419",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "208",
"Relative Atomic Mass" : "207.9820187",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "209",
"Relative Atomic Mass" : "208.985359",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "210",
"Relative Atomic Mass" : "209.990074",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "211",
"Relative Atomic Mass" : "210.99348",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "81",
"Atomic Symbol" : "Tl",
"Mass Number" : "212",
"Relative Atomic Mass" : "211.99823",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "204.3833",
"Notes" : " "
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "178",
"Relative Atomic Mass" : "178.003830",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "179",
"Relative Atomic Mass" : "179.00215",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "180",
"Relative Atomic Mass" : "179.997918",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "181",
"Relative Atomic Mass" : "180.99662",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "182",
"Relative Atomic Mass" : "181.992672",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "183",
"Relative Atomic Mass" : "182.991870",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "184",
"Relative Atomic Mass" : "183.988142",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.987610",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.984239",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.983918",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.980874",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.980810",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.978082",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.978270",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.975785",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.976170",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.974012",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "195",
"Relative Atomic Mass" : "194.974542",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "196",
"Relative Atomic Mass" : "195.972774",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "197",
"Relative Atomic Mass" : "196.973431",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "198",
"Relative Atomic Mass" : "197.972034",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "199",
"Relative Atomic Mass" : "198.972917",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "200",
"Relative Atomic Mass" : "199.971827",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "201",
"Relative Atomic Mass" : "200.972885",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "202",
"Relative Atomic Mass" : "201.972159",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "203",
"Relative Atomic Mass" : "202.973391",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "204",
"Relative Atomic Mass" : "203.9730436",
"Isotopic Composition" : "0.014",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "205",
"Relative Atomic Mass" : "204.9744818",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "206",
"Relative Atomic Mass" : "205.9744653",
"Isotopic Composition" : "0.241",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "207",
"Relative Atomic Mass" : "206.9758969",
"Isotopic Composition" : "0.221",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "208",
"Relative Atomic Mass" : "207.9766521",
"Isotopic Composition" : "0.524",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "209",
"Relative Atomic Mass" : "208.9810901",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "210",
"Relative Atomic Mass" : "209.9841885",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "211",
"Relative Atomic Mass" : "210.9887370",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "212",
"Relative Atomic Mass" : "211.9918975",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "213",
"Relative Atomic Mass" : "212.996581",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "214",
"Relative Atomic Mass" : "213.9998054",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "82",
"Atomic Symbol" : "Pb",
"Mass Number" : "215",
"Relative Atomic Mass" : "215.00481",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "207.2",
"Notes" : "g,r,f"
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "184",
"Relative Atomic Mass" : "184.00112",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "185",
"Relative Atomic Mass" : "184.997630",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "186",
"Relative Atomic Mass" : "185.996600",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "187",
"Relative Atomic Mass" : "186.993158",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.992270",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.989200",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.98830",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.985786",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.985460",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.982960",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.982830",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "195",
"Relative Atomic Mass" : "194.980651",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "196",
"Relative Atomic Mass" : "195.980667",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "197",
"Relative Atomic Mass" : "196.978864",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "198",
"Relative Atomic Mass" : "197.979210",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "199",
"Relative Atomic Mass" : "198.977672",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "200",
"Relative Atomic Mass" : "199.978132",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "201",
"Relative Atomic Mass" : "200.977009",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "202",
"Relative Atomic Mass" : "201.977742",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "203",
"Relative Atomic Mass" : "202.976876",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "204",
"Relative Atomic Mass" : "203.977813",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "205",
"Relative Atomic Mass" : "204.977389",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "206",
"Relative Atomic Mass" : "205.978499",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "207",
"Relative Atomic Mass" : "206.9784707",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "208",
"Relative Atomic Mass" : "207.9797422",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "209",
"Relative Atomic Mass" : "208.9803987",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "210",
"Relative Atomic Mass" : "209.9841204",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "211",
"Relative Atomic Mass" : "210.987269",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "212",
"Relative Atomic Mass" : "211.9912857",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "213",
"Relative Atomic Mass" : "212.994385",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "214",
"Relative Atomic Mass" : "213.998712",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "215",
"Relative Atomic Mass" : "215.001770",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "216",
"Relative Atomic Mass" : "216.006306",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "217",
"Relative Atomic Mass" : "217.00947",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "83",
"Atomic Symbol" : "Bi",
"Mass Number" : "218",
"Relative Atomic Mass" : "218.01432",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "208.98040",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "188",
"Relative Atomic Mass" : "187.999422",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "189",
"Relative Atomic Mass" : "188.998481",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "190",
"Relative Atomic Mass" : "189.995101",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "191",
"Relative Atomic Mass" : "190.994574",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "192",
"Relative Atomic Mass" : "191.991335",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.991030",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.988186",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "195",
"Relative Atomic Mass" : "194.988110",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "196",
"Relative Atomic Mass" : "195.985535",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "197",
"Relative Atomic Mass" : "196.985660",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "198",
"Relative Atomic Mass" : "197.983389",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "199",
"Relative Atomic Mass" : "198.983666",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "200",
"Relative Atomic Mass" : "199.981799",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "201",
"Relative Atomic Mass" : "200.982260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "202",
"Relative Atomic Mass" : "201.980758",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "203",
"Relative Atomic Mass" : "202.981420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "204",
"Relative Atomic Mass" : "203.980318",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "205",
"Relative Atomic Mass" : "204.981203",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "206",
"Relative Atomic Mass" : "205.980481",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "207",
"Relative Atomic Mass" : "206.981593",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "208",
"Relative Atomic Mass" : "207.9812457",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "209",
"Relative Atomic Mass" : "208.9824304",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "210",
"Relative Atomic Mass" : "209.9828737",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "211",
"Relative Atomic Mass" : "210.9866532",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "212",
"Relative Atomic Mass" : "211.9888680",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "213",
"Relative Atomic Mass" : "212.992857",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "214",
"Relative Atomic Mass" : "213.9952014",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "215",
"Relative Atomic Mass" : "214.9994200",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "216",
"Relative Atomic Mass" : "216.0019150",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "217",
"Relative Atomic Mass" : "217.006335",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "218",
"Relative Atomic Mass" : "218.0089730",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "219",
"Relative Atomic Mass" : "219.01374",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "84",
"Atomic Symbol" : "Po",
"Mass Number" : "220",
"Relative Atomic Mass" : "220.01660",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "209",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "193",
"Relative Atomic Mass" : "192.999840",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "194",
"Relative Atomic Mass" : "193.99873",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "195",
"Relative Atomic Mass" : "194.996268",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "196",
"Relative Atomic Mass" : "195.995790",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "197",
"Relative Atomic Mass" : "196.993190",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "198",
"Relative Atomic Mass" : "197.992840",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "199",
"Relative Atomic Mass" : "198.990530",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "200",
"Relative Atomic Mass" : "199.990351",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "201",
"Relative Atomic Mass" : "200.988417",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "202",
"Relative Atomic Mass" : "201.988630",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "203",
"Relative Atomic Mass" : "202.986942",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "204",
"Relative Atomic Mass" : "203.987251",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "205",
"Relative Atomic Mass" : "204.986074",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "206",
"Relative Atomic Mass" : "205.986667",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "207",
"Relative Atomic Mass" : "206.985784",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "208",
"Relative Atomic Mass" : "207.986590",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "209",
"Relative Atomic Mass" : "208.986173",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "210",
"Relative Atomic Mass" : "209.987148",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "211",
"Relative Atomic Mass" : "210.9874963",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "212",
"Relative Atomic Mass" : "211.990745",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "213",
"Relative Atomic Mass" : "212.992937",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "214",
"Relative Atomic Mass" : "213.996372",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "215",
"Relative Atomic Mass" : "214.998653",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "216",
"Relative Atomic Mass" : "216.002423",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "217",
"Relative Atomic Mass" : "217.004719",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "218",
"Relative Atomic Mass" : "218.008694",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "219",
"Relative Atomic Mass" : "219.011162",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "220",
"Relative Atomic Mass" : "220.015410",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "221",
"Relative Atomic Mass" : "221.01805",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "222",
"Relative Atomic Mass" : "222.02233",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "85",
"Atomic Symbol" : "At",
"Mass Number" : "223",
"Relative Atomic Mass" : "223.02519",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "210",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "195",
"Relative Atomic Mass" : "195.005440",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "196",
"Relative Atomic Mass" : "196.002115",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "197",
"Relative Atomic Mass" : "197.001580",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "198",
"Relative Atomic Mass" : "197.998679",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "199",
"Relative Atomic Mass" : "198.998370",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "200",
"Relative Atomic Mass" : "199.995699",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "201",
"Relative Atomic Mass" : "200.995630",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "202",
"Relative Atomic Mass" : "201.993263",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "203",
"Relative Atomic Mass" : "202.993387",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "204",
"Relative Atomic Mass" : "203.991429",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "205",
"Relative Atomic Mass" : "204.991720",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "206",
"Relative Atomic Mass" : "205.990214",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "207",
"Relative Atomic Mass" : "206.990734",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "208",
"Relative Atomic Mass" : "207.989642",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "209",
"Relative Atomic Mass" : "208.990415",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "210",
"Relative Atomic Mass" : "209.989696",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "211",
"Relative Atomic Mass" : "210.990601",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "212",
"Relative Atomic Mass" : "211.990704",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "213",
"Relative Atomic Mass" : "212.993883",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "214",
"Relative Atomic Mass" : "213.995363",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "215",
"Relative Atomic Mass" : "214.998745",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "216",
"Relative Atomic Mass" : "216.000274",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "217",
"Relative Atomic Mass" : "217.003928",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "218",
"Relative Atomic Mass" : "218.0056013",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "219",
"Relative Atomic Mass" : "219.0094802",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "220",
"Relative Atomic Mass" : "220.0113940",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "221",
"Relative Atomic Mass" : "221.015537",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "222",
"Relative Atomic Mass" : "222.0175777",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "223",
"Relative Atomic Mass" : "223.02179",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "224",
"Relative Atomic Mass" : "224.02409",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "225",
"Relative Atomic Mass" : "225.02844",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "226",
"Relative Atomic Mass" : "226.03089",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "227",
"Relative Atomic Mass" : "227.03541",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "86",
"Atomic Symbol" : "Rn",
"Mass Number" : "228",
"Relative Atomic Mass" : "228.03799",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "222",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "199",
"Relative Atomic Mass" : "199.007260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "200",
"Relative Atomic Mass" : "200.006570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "201",
"Relative Atomic Mass" : "201.003860",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "202",
"Relative Atomic Mass" : "202.003370",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "203",
"Relative Atomic Mass" : "203.000925",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "204",
"Relative Atomic Mass" : "204.000653",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "205",
"Relative Atomic Mass" : "204.998594",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "206",
"Relative Atomic Mass" : "205.998670",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "207",
"Relative Atomic Mass" : "206.996950",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "208",
"Relative Atomic Mass" : "207.997140",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "209",
"Relative Atomic Mass" : "208.995954",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "210",
"Relative Atomic Mass" : "209.996408",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "211",
"Relative Atomic Mass" : "210.995537",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "212",
"Relative Atomic Mass" : "211.996202",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "213",
"Relative Atomic Mass" : "212.996189",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "214",
"Relative Atomic Mass" : "213.998971",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "215",
"Relative Atomic Mass" : "215.000341",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "216",
"Relative Atomic Mass" : "216.003198",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "217",
"Relative Atomic Mass" : "217.004632",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "218",
"Relative Atomic Mass" : "218.007578",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "219",
"Relative Atomic Mass" : "219.009252",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "220",
"Relative Atomic Mass" : "220.012327",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "221",
"Relative Atomic Mass" : "221.014255",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "222",
"Relative Atomic Mass" : "222.017552",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "223",
"Relative Atomic Mass" : "223.0197359",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "224",
"Relative Atomic Mass" : "224.023250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "225",
"Relative Atomic Mass" : "225.025570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "226",
"Relative Atomic Mass" : "226.02939",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "227",
"Relative Atomic Mass" : "227.03184",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "228",
"Relative Atomic Mass" : "228.03573",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "229",
"Relative Atomic Mass" : "229.038450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "230",
"Relative Atomic Mass" : "230.04251",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "231",
"Relative Atomic Mass" : "231.04544",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "87",
"Atomic Symbol" : "Fr",
"Mass Number" : "232",
"Relative Atomic Mass" : "232.04977",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "223",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "202",
"Relative Atomic Mass" : "202.009890",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "203",
"Relative Atomic Mass" : "203.009270",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "204",
"Relative Atomic Mass" : "204.006500",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "205",
"Relative Atomic Mass" : "205.006270",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "206",
"Relative Atomic Mass" : "206.003827",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "207",
"Relative Atomic Mass" : "207.003800",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "208",
"Relative Atomic Mass" : "208.001840",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "209",
"Relative Atomic Mass" : "209.001990",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "210",
"Relative Atomic Mass" : "210.000495",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "211",
"Relative Atomic Mass" : "211.000898",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "212",
"Relative Atomic Mass" : "211.999794",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "213",
"Relative Atomic Mass" : "213.000384",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "214",
"Relative Atomic Mass" : "214.000108",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "215",
"Relative Atomic Mass" : "215.002720",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "216",
"Relative Atomic Mass" : "216.003533",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "217",
"Relative Atomic Mass" : "217.006320",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "218",
"Relative Atomic Mass" : "218.007140",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "219",
"Relative Atomic Mass" : "219.010085",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "220",
"Relative Atomic Mass" : "220.011028",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "221",
"Relative Atomic Mass" : "221.013917",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "222",
"Relative Atomic Mass" : "222.015375",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "223",
"Relative Atomic Mass" : "223.0185022",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "224",
"Relative Atomic Mass" : "224.0202118",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "225",
"Relative Atomic Mass" : "225.023612",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "226",
"Relative Atomic Mass" : "226.0254098",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "227",
"Relative Atomic Mass" : "227.0291778",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "228",
"Relative Atomic Mass" : "228.0310703",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "229",
"Relative Atomic Mass" : "229.034958",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "230",
"Relative Atomic Mass" : "230.037056",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "231",
"Relative Atomic Mass" : "231.04122",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "232",
"Relative Atomic Mass" : "232.04364",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "233",
"Relative Atomic Mass" : "233.04806",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "88",
"Atomic Symbol" : "Ra",
"Mass Number" : "234",
"Relative Atomic Mass" : "234.05070",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "226",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "206",
"Relative Atomic Mass" : "206.014500",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "207",
"Relative Atomic Mass" : "207.011950",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "208",
"Relative Atomic Mass" : "208.011550",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "209",
"Relative Atomic Mass" : "209.009490",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "210",
"Relative Atomic Mass" : "210.009440",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "211",
"Relative Atomic Mass" : "211.007730",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "212",
"Relative Atomic Mass" : "212.007810",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "213",
"Relative Atomic Mass" : "213.006610",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "214",
"Relative Atomic Mass" : "214.006902",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "215",
"Relative Atomic Mass" : "215.006454",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "216",
"Relative Atomic Mass" : "216.008720",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "217",
"Relative Atomic Mass" : "217.009347",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "218",
"Relative Atomic Mass" : "218.011640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "219",
"Relative Atomic Mass" : "219.012420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "220",
"Relative Atomic Mass" : "220.014763",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "221",
"Relative Atomic Mass" : "221.015590",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "222",
"Relative Atomic Mass" : "222.017844",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "223",
"Relative Atomic Mass" : "223.019137",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "224",
"Relative Atomic Mass" : "224.021723",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "225",
"Relative Atomic Mass" : "225.023230",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "226",
"Relative Atomic Mass" : "226.026098",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "227",
"Relative Atomic Mass" : "227.0277521",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "228",
"Relative Atomic Mass" : "228.0310211",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "229",
"Relative Atomic Mass" : "229.033020",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "230",
"Relative Atomic Mass" : "230.03629",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "231",
"Relative Atomic Mass" : "231.03856",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "232",
"Relative Atomic Mass" : "232.04203",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "233",
"Relative Atomic Mass" : "233.04455",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "234",
"Relative Atomic Mass" : "234.04842",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "235",
"Relative Atomic Mass" : "235.05123",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "89",
"Atomic Symbol" : "Ac",
"Mass Number" : "236",
"Relative Atomic Mass" : "236.05530",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "227",
"Notes" : " "
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "209",
"Relative Atomic Mass" : "209.01772",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "210",
"Relative Atomic Mass" : "210.015075",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "211",
"Relative Atomic Mass" : "211.014930",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "212",
"Relative Atomic Mass" : "212.012980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "213",
"Relative Atomic Mass" : "213.013010",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "214",
"Relative Atomic Mass" : "214.011500",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "215",
"Relative Atomic Mass" : "215.011730",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "216",
"Relative Atomic Mass" : "216.011062",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "217",
"Relative Atomic Mass" : "217.013114",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "218",
"Relative Atomic Mass" : "218.013284",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "219",
"Relative Atomic Mass" : "219.015540",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "220",
"Relative Atomic Mass" : "220.015748",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "221",
"Relative Atomic Mass" : "221.018184",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "222",
"Relative Atomic Mass" : "222.018468",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "223",
"Relative Atomic Mass" : "223.020811",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "224",
"Relative Atomic Mass" : "224.021467",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "225",
"Relative Atomic Mass" : "225.023951",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "226",
"Relative Atomic Mass" : "226.024903",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "227",
"Relative Atomic Mass" : "227.0277041",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "228",
"Relative Atomic Mass" : "228.0287411",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "229",
"Relative Atomic Mass" : "229.031762",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "230",
"Relative Atomic Mass" : "230.0331338",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "231",
"Relative Atomic Mass" : "231.0363043",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "232",
"Relative Atomic Mass" : "232.0380553",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "233",
"Relative Atomic Mass" : "233.0415818",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "234",
"Relative Atomic Mass" : "234.043601",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "235",
"Relative Atomic Mass" : "235.047510",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "236",
"Relative Atomic Mass" : "236.04987",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "237",
"Relative Atomic Mass" : "237.05389",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "90",
"Atomic Symbol" : "Th",
"Mass Number" : "238",
"Relative Atomic Mass" : "238.05650",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "232.03806",
"Notes" : "g"
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "212",
"Relative Atomic Mass" : "212.023200",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "213",
"Relative Atomic Mass" : "213.021110",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "214",
"Relative Atomic Mass" : "214.020920",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "215",
"Relative Atomic Mass" : "215.019190",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "216",
"Relative Atomic Mass" : "216.019110",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "217",
"Relative Atomic Mass" : "217.018320",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "218",
"Relative Atomic Mass" : "218.020042",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "219",
"Relative Atomic Mass" : "219.019880",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "220",
"Relative Atomic Mass" : "220.021880",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "221",
"Relative Atomic Mass" : "221.021880",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "222",
"Relative Atomic Mass" : "222.023740",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "223",
"Relative Atomic Mass" : "223.023960",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "224",
"Relative Atomic Mass" : "224.025626",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "225",
"Relative Atomic Mass" : "225.026130",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "226",
"Relative Atomic Mass" : "226.027948",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "227",
"Relative Atomic Mass" : "227.028805",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "228",
"Relative Atomic Mass" : "228.031051",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "229",
"Relative Atomic Mass" : "229.0320968",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "230",
"Relative Atomic Mass" : "230.034541",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "231",
"Relative Atomic Mass" : "231.0358840",
"Isotopic Composition" : "1.0000",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "232",
"Relative Atomic Mass" : "232.038592",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "233",
"Relative Atomic Mass" : "233.0402473",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "234",
"Relative Atomic Mass" : "234.043308",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "235",
"Relative Atomic Mass" : "235.045440",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "236",
"Relative Atomic Mass" : "236.04868",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "237",
"Relative Atomic Mass" : "237.05115",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "238",
"Relative Atomic Mass" : "238.054500",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "239",
"Relative Atomic Mass" : "239.05726",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "91",
"Atomic Symbol" : "Pa",
"Mass Number" : "240",
"Relative Atomic Mass" : "240.06098",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "231.03588",
"Notes" : " "
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "217",
"Relative Atomic Mass" : "217.024370",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "218",
"Relative Atomic Mass" : "218.023540",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "219",
"Relative Atomic Mass" : "219.024920",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "220",
"Relative Atomic Mass" : "220.02472",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "221",
"Relative Atomic Mass" : "221.02640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "222",
"Relative Atomic Mass" : "222.02609",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "223",
"Relative Atomic Mass" : "223.027740",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "224",
"Relative Atomic Mass" : "224.027605",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "225",
"Relative Atomic Mass" : "225.029391",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "226",
"Relative Atomic Mass" : "226.029339",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "227",
"Relative Atomic Mass" : "227.031156",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "228",
"Relative Atomic Mass" : "228.031374",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "229",
"Relative Atomic Mass" : "229.033506",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "230",
"Relative Atomic Mass" : "230.033940",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "231",
"Relative Atomic Mass" : "231.036294",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "232",
"Relative Atomic Mass" : "232.0371562",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "233",
"Relative Atomic Mass" : "233.0396352",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "234",
"Relative Atomic Mass" : "234.0409521",
"Isotopic Composition" : "0.000054",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "235",
"Relative Atomic Mass" : "235.0439299",
"Isotopic Composition" : "0.007204",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "236",
"Relative Atomic Mass" : "236.0455680",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "237",
"Relative Atomic Mass" : "237.0487302",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "238",
"Relative Atomic Mass" : "238.0507882",
"Isotopic Composition" : "0.992742",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "239",
"Relative Atomic Mass" : "239.0542933",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "240",
"Relative Atomic Mass" : "240.056592",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "241",
"Relative Atomic Mass" : "241.06033",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "92",
"Atomic Symbol" : "U",
"Mass Number" : "242",
"Relative Atomic Mass" : "242.06293",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "238.02891",
"Notes" : "g,m,c"
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "225",
"Relative Atomic Mass" : "225.033910",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "226",
"Relative Atomic Mass" : "226.03515",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "227",
"Relative Atomic Mass" : "227.034960",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "228",
"Relative Atomic Mass" : "228.03618",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "229",
"Relative Atomic Mass" : "229.036260",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "230",
"Relative Atomic Mass" : "230.037830",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "231",
"Relative Atomic Mass" : "231.038250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "232",
"Relative Atomic Mass" : "232.04011",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "233",
"Relative Atomic Mass" : "233.040740",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "234",
"Relative Atomic Mass" : "234.042895",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "235",
"Relative Atomic Mass" : "235.0440633",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "236",
"Relative Atomic Mass" : "236.046570",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "237",
"Relative Atomic Mass" : "237.0481734",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "238",
"Relative Atomic Mass" : "238.0509464",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "239",
"Relative Atomic Mass" : "239.0529390",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "240",
"Relative Atomic Mass" : "240.056162",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "241",
"Relative Atomic Mass" : "241.058250",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "242",
"Relative Atomic Mass" : "242.06164",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "243",
"Relative Atomic Mass" : "243.064280",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "93",
"Atomic Symbol" : "Np",
"Mass Number" : "244",
"Relative Atomic Mass" : "244.06785",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "237",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "228",
"Relative Atomic Mass" : "228.038740",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "229",
"Relative Atomic Mass" : "229.040150",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "230",
"Relative Atomic Mass" : "230.039650",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "231",
"Relative Atomic Mass" : "231.041101",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "232",
"Relative Atomic Mass" : "232.041187",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "233",
"Relative Atomic Mass" : "233.043000",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "234",
"Relative Atomic Mass" : "234.043317",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "235",
"Relative Atomic Mass" : "235.045286",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "236",
"Relative Atomic Mass" : "236.0460580",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "237",
"Relative Atomic Mass" : "237.0484097",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "238",
"Relative Atomic Mass" : "238.0495599",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "239",
"Relative Atomic Mass" : "239.0521634",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "240",
"Relative Atomic Mass" : "240.0538135",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "241",
"Relative Atomic Mass" : "241.0568515",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "242",
"Relative Atomic Mass" : "242.0587426",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "243",
"Relative Atomic Mass" : "243.062003",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "244",
"Relative Atomic Mass" : "244.064204",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "245",
"Relative Atomic Mass" : "245.067747",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "246",
"Relative Atomic Mass" : "246.070205",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "94",
"Atomic Symbol" : "Pu",
"Mass Number" : "247",
"Relative Atomic Mass" : "247.07407",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "244",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "231",
"Relative Atomic Mass" : "231.04556",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "232",
"Relative Atomic Mass" : "232.04659",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "233",
"Relative Atomic Mass" : "233.04635",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "234",
"Relative Atomic Mass" : "234.04781",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "235",
"Relative Atomic Mass" : "235.04795",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "236",
"Relative Atomic Mass" : "236.04958",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "237",
"Relative Atomic Mass" : "237.050000",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "238",
"Relative Atomic Mass" : "238.051980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "239",
"Relative Atomic Mass" : "239.0530245",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "240",
"Relative Atomic Mass" : "240.055300",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "241",
"Relative Atomic Mass" : "241.0568291",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "242",
"Relative Atomic Mass" : "242.0595492",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "243",
"Relative Atomic Mass" : "243.0613811",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "244",
"Relative Atomic Mass" : "244.0642848",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "245",
"Relative Atomic Mass" : "245.066452",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "246",
"Relative Atomic Mass" : "246.069775",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "247",
"Relative Atomic Mass" : "247.07209",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "248",
"Relative Atomic Mass" : "248.07575",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "95",
"Atomic Symbol" : "Am",
"Mass Number" : "249",
"Relative Atomic Mass" : "249.07848",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "243",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "233",
"Relative Atomic Mass" : "233.050770",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "234",
"Relative Atomic Mass" : "234.050160",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "235",
"Relative Atomic Mass" : "235.05143",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "236",
"Relative Atomic Mass" : "236.05141",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "237",
"Relative Atomic Mass" : "237.05290",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "238",
"Relative Atomic Mass" : "238.053030",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "239",
"Relative Atomic Mass" : "239.05496",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "240",
"Relative Atomic Mass" : "240.0555295",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "241",
"Relative Atomic Mass" : "241.0576530",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "242",
"Relative Atomic Mass" : "242.0588358",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "243",
"Relative Atomic Mass" : "243.0613891",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "244",
"Relative Atomic Mass" : "244.0627526",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "245",
"Relative Atomic Mass" : "245.0654912",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "246",
"Relative Atomic Mass" : "246.0672237",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "247",
"Relative Atomic Mass" : "247.070354",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "248",
"Relative Atomic Mass" : "248.072349",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "249",
"Relative Atomic Mass" : "249.075953",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "250",
"Relative Atomic Mass" : "250.078357",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "251",
"Relative Atomic Mass" : "251.082285",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "96",
"Atomic Symbol" : "Cm",
"Mass Number" : "252",
"Relative Atomic Mass" : "252.08487",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "235",
"Relative Atomic Mass" : "235.05658",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "236",
"Relative Atomic Mass" : "236.05733",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "237",
"Relative Atomic Mass" : "237.05700",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "238",
"Relative Atomic Mass" : "238.05828",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "239",
"Relative Atomic Mass" : "239.05828",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "240",
"Relative Atomic Mass" : "240.05976",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "241",
"Relative Atomic Mass" : "241.06023",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "242",
"Relative Atomic Mass" : "242.06198",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "243",
"Relative Atomic Mass" : "243.063008",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "244",
"Relative Atomic Mass" : "244.065181",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "245",
"Relative Atomic Mass" : "245.0663616",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "246",
"Relative Atomic Mass" : "246.068670",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "247",
"Relative Atomic Mass" : "247.070307",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "248",
"Relative Atomic Mass" : "248.073090",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "249",
"Relative Atomic Mass" : "249.0749867",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "250",
"Relative Atomic Mass" : "250.078317",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "251",
"Relative Atomic Mass" : "251.080760",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "252",
"Relative Atomic Mass" : "252.08431",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "253",
"Relative Atomic Mass" : "253.08688",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "97",
"Atomic Symbol" : "Bk",
"Mass Number" : "254",
"Relative Atomic Mass" : "254.09060",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "247",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "237",
"Relative Atomic Mass" : "237.06207",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "238",
"Relative Atomic Mass" : "238.06141",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "239",
"Relative Atomic Mass" : "239.06242",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "240",
"Relative Atomic Mass" : "240.06230",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "241",
"Relative Atomic Mass" : "241.06373",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "242",
"Relative Atomic Mass" : "242.063700",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "243",
"Relative Atomic Mass" : "243.06543",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "244",
"Relative Atomic Mass" : "244.066001",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "245",
"Relative Atomic Mass" : "245.068049",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "246",
"Relative Atomic Mass" : "246.0688053",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "247",
"Relative Atomic Mass" : "247.071001",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "248",
"Relative Atomic Mass" : "248.072185",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "249",
"Relative Atomic Mass" : "249.0748535",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "250",
"Relative Atomic Mass" : "250.0764061",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "251",
"Relative Atomic Mass" : "251.079587",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "252",
"Relative Atomic Mass" : "252.081626",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "253",
"Relative Atomic Mass" : "253.085133",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "254",
"Relative Atomic Mass" : "254.087323",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "255",
"Relative Atomic Mass" : "255.09105",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "98",
"Atomic Symbol" : "Cf",
"Mass Number" : "256",
"Relative Atomic Mass" : "256.09344",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "251",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "240",
"Relative Atomic Mass" : "240.06892",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "241",
"Relative Atomic Mass" : "241.06854",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "242",
"Relative Atomic Mass" : "242.06975",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "243",
"Relative Atomic Mass" : "243.06955",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "244",
"Relative Atomic Mass" : "244.07088",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "245",
"Relative Atomic Mass" : "245.07132",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "246",
"Relative Atomic Mass" : "246.07290",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "247",
"Relative Atomic Mass" : "247.073660",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "248",
"Relative Atomic Mass" : "248.075470",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "249",
"Relative Atomic Mass" : "249.076410",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "250",
"Relative Atomic Mass" : "250.07861",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "251",
"Relative Atomic Mass" : "251.079992",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "252",
"Relative Atomic Mass" : "252.082980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "253",
"Relative Atomic Mass" : "253.0848247",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "254",
"Relative Atomic Mass" : "254.088022",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "255",
"Relative Atomic Mass" : "255.090273",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "256",
"Relative Atomic Mass" : "256.09360",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "257",
"Relative Atomic Mass" : "257.09598",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "99",
"Atomic Symbol" : "Es",
"Mass Number" : "258",
"Relative Atomic Mass" : "258.09952",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "252",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "242",
"Relative Atomic Mass" : "242.07343",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "243",
"Relative Atomic Mass" : "243.07435",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "244",
"Relative Atomic Mass" : "244.07408",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "245",
"Relative Atomic Mass" : "245.07539",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "246",
"Relative Atomic Mass" : "246.075300",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "247",
"Relative Atomic Mass" : "247.07685",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "248",
"Relative Atomic Mass" : "248.077195",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "249",
"Relative Atomic Mass" : "249.07903",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "250",
"Relative Atomic Mass" : "250.079521",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "251",
"Relative Atomic Mass" : "251.081575",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "252",
"Relative Atomic Mass" : "252.082467",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "253",
"Relative Atomic Mass" : "253.085185",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "254",
"Relative Atomic Mass" : "254.0868542",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "255",
"Relative Atomic Mass" : "255.089962",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "256",
"Relative Atomic Mass" : "256.091773",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "257",
"Relative Atomic Mass" : "257.095105",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "258",
"Relative Atomic Mass" : "258.09708",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "259",
"Relative Atomic Mass" : "259.10060",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "100",
"Atomic Symbol" : "Fm",
"Mass Number" : "260",
"Relative Atomic Mass" : "260.10268",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "257",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "245",
"Relative Atomic Mass" : "245.08083",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "246",
"Relative Atomic Mass" : "246.08189",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "247",
"Relative Atomic Mass" : "247.08164",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "248",
"Relative Atomic Mass" : "248.08282",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "249",
"Relative Atomic Mass" : "249.08301",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "250",
"Relative Atomic Mass" : "250.08442",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "251",
"Relative Atomic Mass" : "251.08484",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "252",
"Relative Atomic Mass" : "252.08656",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "253",
"Relative Atomic Mass" : "253.08728",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "254",
"Relative Atomic Mass" : "254.08966",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "255",
"Relative Atomic Mass" : "255.091083",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "256",
"Relative Atomic Mass" : "256.094060",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "257",
"Relative Atomic Mass" : "257.095541",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "258",
"Relative Atomic Mass" : "258.098431",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "259",
"Relative Atomic Mass" : "259.10051",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "260",
"Relative Atomic Mass" : "260.10365",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "261",
"Relative Atomic Mass" : "261.10572",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "101",
"Atomic Symbol" : "Md",
"Mass Number" : "262",
"Relative Atomic Mass" : "262.10887",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "258",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "248",
"Relative Atomic Mass" : "248.08660",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "249",
"Relative Atomic Mass" : "249.08783",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "250",
"Relative Atomic Mass" : "250.08751",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "251",
"Relative Atomic Mass" : "251.08901",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "252",
"Relative Atomic Mass" : "252.088977",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "253",
"Relative Atomic Mass" : "253.09068",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "254",
"Relative Atomic Mass" : "254.090955",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "255",
"Relative Atomic Mass" : "255.093241",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "256",
"Relative Atomic Mass" : "256.094283",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "257",
"Relative Atomic Mass" : "257.096877",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "258",
"Relative Atomic Mass" : "258.09821",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "259",
"Relative Atomic Mass" : "259.10103",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "260",
"Relative Atomic Mass" : "260.10264",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "261",
"Relative Atomic Mass" : "261.10575",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "262",
"Relative Atomic Mass" : "262.10730",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "263",
"Relative Atomic Mass" : "263.11055",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "102",
"Atomic Symbol" : "No",
"Mass Number" : "264",
"Relative Atomic Mass" : "264.11235",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "259",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "251",
"Relative Atomic Mass" : "251.09436",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "252",
"Relative Atomic Mass" : "252.09537",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "253",
"Relative Atomic Mass" : "253.09521",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "254",
"Relative Atomic Mass" : "254.09645",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "255",
"Relative Atomic Mass" : "255.09668",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "256",
"Relative Atomic Mass" : "256.09863",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "257",
"Relative Atomic Mass" : "257.09956",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "258",
"Relative Atomic Mass" : "258.10181",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "259",
"Relative Atomic Mass" : "259.102900",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "260",
"Relative Atomic Mass" : "260.10550",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "261",
"Relative Atomic Mass" : "261.10688",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "262",
"Relative Atomic Mass" : "262.10963",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "263",
"Relative Atomic Mass" : "263.11129",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "264",
"Relative Atomic Mass" : "264.11404",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "265",
"Relative Atomic Mass" : "265.11584",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "103",
"Atomic Symbol" : "Lr",
"Mass Number" : "266",
"Relative Atomic Mass" : "266.11931",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "262",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "253",
"Relative Atomic Mass" : "253.10069",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "254",
"Relative Atomic Mass" : "254.10018",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "255",
"Relative Atomic Mass" : "255.10134",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "256",
"Relative Atomic Mass" : "256.101166",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "257",
"Relative Atomic Mass" : "257.10299",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "258",
"Relative Atomic Mass" : "258.10349",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "259",
"Relative Atomic Mass" : "259.105640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "260",
"Relative Atomic Mass" : "260.10644",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "261",
"Relative Atomic Mass" : "261.108770",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "262",
"Relative Atomic Mass" : "262.10993",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "263",
"Relative Atomic Mass" : "263.11255",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "264",
"Relative Atomic Mass" : "264.11399",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "265",
"Relative Atomic Mass" : "265.11670",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "266",
"Relative Atomic Mass" : "266.11796",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "267",
"Relative Atomic Mass" : "267.12153",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "104",
"Atomic Symbol" : "Rf",
"Mass Number" : "268",
"Relative Atomic Mass" : "268.12364",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "265",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "255",
"Relative Atomic Mass" : "255.10740",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "256",
"Relative Atomic Mass" : "256.10813",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "257",
"Relative Atomic Mass" : "257.10772",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "258",
"Relative Atomic Mass" : "258.10923",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "259",
"Relative Atomic Mass" : "259.10961",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "260",
"Relative Atomic Mass" : "260.11130",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "261",
"Relative Atomic Mass" : "261.11206",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "262",
"Relative Atomic Mass" : "262.11408",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "263",
"Relative Atomic Mass" : "263.11499",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "264",
"Relative Atomic Mass" : "264.11740",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "265",
"Relative Atomic Mass" : "265.11860",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "266",
"Relative Atomic Mass" : "266.12103",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "267",
"Relative Atomic Mass" : "267.12238",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "268",
"Relative Atomic Mass" : "268.12545",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "269",
"Relative Atomic Mass" : "269.12746",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "105",
"Atomic Symbol" : "Db",
"Mass Number" : "270",
"Relative Atomic Mass" : "270.13071",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "268",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "258",
"Relative Atomic Mass" : "258.11317",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "259",
"Relative Atomic Mass" : "259.11450",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "260",
"Relative Atomic Mass" : "260.114420",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "261",
"Relative Atomic Mass" : "261.11612",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "262",
"Relative Atomic Mass" : "262.11640",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "263",
"Relative Atomic Mass" : "263.11832",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "264",
"Relative Atomic Mass" : "264.11893",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "265",
"Relative Atomic Mass" : "265.121110",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "266",
"Relative Atomic Mass" : "266.12207",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "267",
"Relative Atomic Mass" : "267.12443",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "268",
"Relative Atomic Mass" : "268.12561",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "269",
"Relative Atomic Mass" : "269.12876",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "270",
"Relative Atomic Mass" : "270.13033",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "271",
"Relative Atomic Mass" : "271.13347",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "272",
"Relative Atomic Mass" : "272.13516",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "106",
"Atomic Symbol" : "Sg",
"Mass Number" : "273",
"Relative Atomic Mass" : "273.13822",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "271",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "260",
"Relative Atomic Mass" : "260.12197",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "261",
"Relative Atomic Mass" : "261.12166",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "262",
"Relative Atomic Mass" : "262.12289",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "263",
"Relative Atomic Mass" : "263.12304",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "264",
"Relative Atomic Mass" : "264.12460",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "265",
"Relative Atomic Mass" : "265.12515",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "266",
"Relative Atomic Mass" : "266.12694",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "267",
"Relative Atomic Mass" : "267.12765",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "268",
"Relative Atomic Mass" : "268.12976",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "269",
"Relative Atomic Mass" : "269.13069",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "270",
"Relative Atomic Mass" : "270.13362",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "271",
"Relative Atomic Mass" : "271.13518",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "272",
"Relative Atomic Mass" : "272.13803",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "273",
"Relative Atomic Mass" : "273.13962",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "274",
"Relative Atomic Mass" : "274.14244",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "107",
"Atomic Symbol" : "Bh",
"Mass Number" : "275",
"Relative Atomic Mass" : "275.14425",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "272",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "263",
"Relative Atomic Mass" : "263.12856",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "264",
"Relative Atomic Mass" : "264.128390",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "265",
"Relative Atomic Mass" : "265.13009",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "266",
"Relative Atomic Mass" : "266.13010",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "267",
"Relative Atomic Mass" : "267.13179",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "268",
"Relative Atomic Mass" : "268.13216",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "269",
"Relative Atomic Mass" : "269.13406",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "270",
"Relative Atomic Mass" : "270.13465",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "271",
"Relative Atomic Mass" : "271.13766",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "272",
"Relative Atomic Mass" : "272.13905",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "273",
"Relative Atomic Mass" : "273.14199",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "274",
"Relative Atomic Mass" : "274.14313",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "275",
"Relative Atomic Mass" : "275.14595",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "276",
"Relative Atomic Mass" : "276.14721",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "108",
"Atomic Symbol" : "Hs",
"Mass Number" : "277",
"Relative Atomic Mass" : "277.14984",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "270",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "265",
"Relative Atomic Mass" : "265.13615",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "266",
"Relative Atomic Mass" : "266.13730",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "267",
"Relative Atomic Mass" : "267.13731",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "268",
"Relative Atomic Mass" : "268.13873",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "269",
"Relative Atomic Mass" : "269.13906",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "270",
"Relative Atomic Mass" : "270.14066",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "271",
"Relative Atomic Mass" : "271.14114",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "272",
"Relative Atomic Mass" : "272.14374",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "273",
"Relative Atomic Mass" : "273.14491",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "274",
"Relative Atomic Mass" : "274.14749",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "275",
"Relative Atomic Mass" : "275.14865",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "276",
"Relative Atomic Mass" : "276.15116",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "277",
"Relative Atomic Mass" : "277.15242",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "278",
"Relative Atomic Mass" : "278.15481",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "109",
"Atomic Symbol" : "Mt",
"Mass Number" : "279",
"Relative Atomic Mass" : "279.15619",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "276",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "267",
"Relative Atomic Mass" : "267.14434",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "268",
"Relative Atomic Mass" : "268.14380",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "269",
"Relative Atomic Mass" : "269.14512",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "270",
"Relative Atomic Mass" : "270.14472",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "271",
"Relative Atomic Mass" : "271.14606",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "272",
"Relative Atomic Mass" : "272.14632",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "273",
"Relative Atomic Mass" : "273.14886",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "274",
"Relative Atomic Mass" : "274.14949",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "275",
"Relative Atomic Mass" : "275.15218",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "276",
"Relative Atomic Mass" : "276.15303",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "277",
"Relative Atomic Mass" : "277.15565",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "278",
"Relative Atomic Mass" : "278.15647",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "279",
"Relative Atomic Mass" : "279.15886",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "280",
"Relative Atomic Mass" : "280.15980",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "110",
"Atomic Symbol" : "Ds",
"Mass Number" : "281",
"Relative Atomic Mass" : "281.16206",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "281",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "272",
"Relative Atomic Mass" : "272.15362",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "273",
"Relative Atomic Mass" : "273.15368",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "274",
"Relative Atomic Mass" : "274.15571",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "275",
"Relative Atomic Mass" : "275.15614",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "276",
"Relative Atomic Mass" : "276.15849",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "277",
"Relative Atomic Mass" : "277.15952",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "278",
"Relative Atomic Mass" : "278.16160",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "279",
"Relative Atomic Mass" : "279.16247",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "280",
"Relative Atomic Mass" : "280.16447",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "281",
"Relative Atomic Mass" : "281.16537",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "282",
"Relative Atomic Mass" : "282.16749",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "111",
"Atomic Symbol" : "Rg",
"Mass Number" : "283",
"Relative Atomic Mass" : "283.16842",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "280",
"Notes" : " "
},

{
"Atomic Number" : "112",
"Atomic Symbol" : "Cn",
"Mass Number" : "277",
"Relative Atomic Mass" : "277.16394",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "285",
"Notes" : " "
},

{
"Atomic Number" : "112",
"Atomic Symbol" : "Cn",
"Mass Number" : "278",
"Relative Atomic Mass" : "278.16431",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "285",
"Notes" : " "
},

{
"Atomic Number" : "112",
"Atomic Symbol" : "Cn",
"Mass Number" : "279",
"Relative Atomic Mass" : "279.16655",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "285",
"Notes" : " "
},

{
"Atomic Number" : "112",
"Atomic Symbol" : "Cn",
"Mass Number" : "280",
"Relative Atomic Mass" : "280.16704",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "285",
"Notes" : " "
},

{
"Atomic Number" : "112",
"Atomic Symbol" : "Cn",
"Mass Number" : "281",
"Relative Atomic Mass" : "281.16929",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "285",
"Notes" : " "
},

{
"Atomic Number" : "112",
"Atomic Symbol" : "Cn",
"Mass Number" : "282",
"Relative Atomic Mass" : "282.16977",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "285",
"Notes" : " "
},

{
"Atomic Number" : "112",
"Atomic Symbol" : "Cn",
"Mass Number" : "283",
"Relative Atomic Mass" : "283.17179",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "285",
"Notes" : " "
},

{
"Atomic Number" : "112",
"Atomic Symbol" : "Cn",
"Mass Number" : "284",
"Relative Atomic Mass" : "284.17238",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "285",
"Notes" : " "
},

{
"Atomic Number" : "112",
"Atomic Symbol" : "Cn",
"Mass Number" : "285",
"Relative Atomic Mass" : "285.17411",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "285",
"Notes" : " "
},

{
"Atomic Number" : "113",
"Atomic Symbol" : "Uut",
"Mass Number" : "283",
"Relative Atomic Mass" : "283.17645",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "284",
"Notes" : " "
},

{
"Atomic Number" : "113",
"Atomic Symbol" : "Uut",
"Mass Number" : "284",
"Relative Atomic Mass" : "284.17808",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "284",
"Notes" : " "
},

{
"Atomic Number" : "113",
"Atomic Symbol" : "Uut",
"Mass Number" : "285",
"Relative Atomic Mass" : "285.17873",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "284",
"Notes" : " "
},

{
"Atomic Number" : "113",
"Atomic Symbol" : "Uut",
"Mass Number" : "286",
"Relative Atomic Mass" : "286.18048",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "284",
"Notes" : " "
},

{
"Atomic Number" : "113",
"Atomic Symbol" : "Uut",
"Mass Number" : "287",
"Relative Atomic Mass" : "287.18105",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "284",
"Notes" : " "
},

{
"Atomic Number" : "114",
"Atomic Symbol" : "Uuq",
"Mass Number" : "285",
"Relative Atomic Mass" : "285.18370",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "289",
"Notes" : " "
},

{
"Atomic Number" : "114",
"Atomic Symbol" : "Uuq",
"Mass Number" : "286",
"Relative Atomic Mass" : "286.18386",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "289",
"Notes" : " "
},

{
"Atomic Number" : "114",
"Atomic Symbol" : "Uuq",
"Mass Number" : "287",
"Relative Atomic Mass" : "287.18560",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "289",
"Notes" : " "
},

{
"Atomic Number" : "114",
"Atomic Symbol" : "Uuq",
"Mass Number" : "288",
"Relative Atomic Mass" : "288.18569",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "289",
"Notes" : " "
},

{
"Atomic Number" : "114",
"Atomic Symbol" : "Uuq",
"Mass Number" : "289",
"Relative Atomic Mass" : "289.18728",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "289",
"Notes" : " "
},

{
"Atomic Number" : "115",
"Atomic Symbol" : "Uup",
"Mass Number" : "287",
"Relative Atomic Mass" : "287.19119",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "288",
"Notes" : " "
},

{
"Atomic Number" : "115",
"Atomic Symbol" : "Uup",
"Mass Number" : "288",
"Relative Atomic Mass" : "288.19249",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "288",
"Notes" : " "
},

{
"Atomic Number" : "115",
"Atomic Symbol" : "Uup",
"Mass Number" : "289",
"Relative Atomic Mass" : "289.19272",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "288",
"Notes" : " "
},

{
"Atomic Number" : "115",
"Atomic Symbol" : "Uup",
"Mass Number" : "290",
"Relative Atomic Mass" : "290.19414",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "288",
"Notes" : " "
},

{
"Atomic Number" : "115",
"Atomic Symbol" : "Uup",
"Mass Number" : "291",
"Relative Atomic Mass" : "291.19438",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "288",
"Notes" : " "
},

{
"Atomic Number" : "116",
"Atomic Symbol" : "Uuh",
"Mass Number" : "289",
"Relative Atomic Mass" : "289.19886",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "293",
"Notes" : " "
},

{
"Atomic Number" : "116",
"Atomic Symbol" : "Uuh",
"Mass Number" : "290",
"Relative Atomic Mass" : "290.19859",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "293",
"Notes" : " "
},

{
"Atomic Number" : "116",
"Atomic Symbol" : "Uuh",
"Mass Number" : "291",
"Relative Atomic Mass" : "291.20001",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "293",
"Notes" : " "
},

{
"Atomic Number" : "116",
"Atomic Symbol" : "Uuh",
"Mass Number" : "292",
"Relative Atomic Mass" : "292.19979",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "293",
"Notes" : " "
},

{
"Atomic Number" : "116",
"Atomic Symbol" : "Uuh",
"Mass Number" : "293",
"Relative Atomic Mass" : "",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "293",
"Notes" : " "
},

{
"Atomic Number" : "117",
"Atomic Symbol" : "Uus",
"Mass Number" : "291",
"Relative Atomic Mass" : "291.20656",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "292",
"Notes" : " "
},

{
"Atomic Number" : "117",
"Atomic Symbol" : "Uus",
"Mass Number" : "292",
"Relative Atomic Mass" : "292.20755",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "292",
"Notes" : " "
},

{
"Atomic Number" : "118",
"Atomic Symbol" : "Uuo",
"Mass Number" : "293",
"Relative Atomic Mass" : "293.21467",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "294",
"Notes" : " "
},

{
"Atomic Number" : "118",
"Atomic Symbol" : "Uuo",
"Mass Number" : "294",
"Relative Atomic Mass" : "",
"Isotopic Composition" : "",
"Standard Atomic Weight" : "294",
"Notes" : " "
}
 
]

}
)";

// More const strings as key

static const std::string StrNumberOfElements = "Number of Elements";
static const std::string StrNeutronMass = "Neutron Mass";
static const std::string StrIsotopes = "Isotopes";
static const std::string StrAtomicNumber = "Atomic Number";
static const std::string StrAtomicSymbol = "Atomic Symbol";
static const std::string StrMassNumber   = "Mass Number";
static const std::string StrRelativeAtomicMass = "Relative Atomic Mass";
static const std::string StrIsotopicComposition = "Isotopic Composition";
static const std::string StrStandardAtomicWeight = "Standard Atomic Weight";
static const std::string StrNotes = "Notes";

// Implementation of NIST

// Define and initialization
std::map<long, NISTElement>       NIST::elements;
std::vector<NISTIsotope>          NIST::isotopes;
std::vector<NISTIsotopeMetaState> NIST::isotopems;
NISTNeutron                       NIST::neutron;
bool                              NIST::initialized = false;

void NIST::clear() {
    
    elements.clear();
    isotopes.clear();
    initialized = false;
    
}

bool NIST::loadFromJsonData(const std::string &json) {
    
    try {
        
        // Simplified with namespaces
        using Document = rapidjson::Document;
        using Value    = rapidjson::Value;
        
        // Create a JSON document
        Document doc;
        
        // Parse document from string
        doc.Parse(json.c_str());
        
        // Extract information
        long numberOfElements = std::stol
        (doc[StrNumberOfElements.c_str()].GetString());
        
        // Extract neutron mass
        double neutronMass = std::stod
        (doc[StrNeutronMass.c_str()].GetString());
        
        // Create neutron
        neutron.relativeAtomicMass = neutronMass;
        neutron.symbol = "N";
        
        // Extract isotopes
        // Allocate memory for isotopes
        isotopes.resize(doc[StrIsotopes.c_str()].GetArray().Size());
        long i=0;
        for (auto& isotope : doc[StrIsotopes.c_str()].GetArray()) {
            
            // Temporary string
            std::string temp;
            
            // Obtain the atomic number
            long atomicNumber = std::stol
            (isotope[StrAtomicNumber.c_str()].GetString());
            
            // Obtain the atomic symbol
            std::string atomicSymbol = isotope
            [StrAtomicSymbol.c_str()].GetString();
            
            // Obtain the mass number
            long massNumber = std::stol
            (isotope[StrMassNumber.c_str()].GetString());
            
            // Obtain the relative atomic mass
            temp = isotope[StrRelativeAtomicMass.c_str()].GetString();
            double relativeAtomicMass =
            temp.empty() ? 0. : std::stod(temp);
            
            // Obtain the isotopic composition
            temp = isotope[StrIsotopicComposition.c_str()].GetString();
            double isotopicComposition =
            temp.empty() ? 0. : std::stod(temp);
            
            // Obtain the standard atomic weight
            temp = isotope[StrStandardAtomicWeight.c_str()].GetString();
            double standardAtomicWeight =
            temp.empty() ? 0. : std::stod(temp);
            
            // Obtain the notes
            std::string notes = isotope[StrNotes.c_str()].GetString();
            
            // Set element
            if (elements.find(atomicNumber) == elements.end()) {
                auto& el = elements[atomicNumber];
                el.atomicNumber = atomicNumber;
                el.atomicSymbol = atomicSymbol;
                el.standardAtomicWeight = standardAtomicWeight;
            }
            
            // Set isotope
            auto& is = isotopes[i++];
            auto& el = elements.at(atomicNumber);
            is.element = &el;
            is.massNumber = massNumber;
            is.relativeAtomicMass = relativeAtomicMass;
            is.isotopeSymbol = atomicSymbol;
            is.notes = notes;
            
            // Add isotope into element's composition
            el.components[&is] = isotopicComposition;
            
        }
        
        // Check number of elements
        if (elements.size() != numberOfElements ||
            std::any_of
            (elements.begin(), elements.end(),
             [numberOfElements](const std::pair<double, NISTElement>& p)
        {
            long A = p.first;
            return A < 1 || A > numberOfElements;
        })) {
            throw std::logic_error("library number of elements inconsistant!");
        }
        
        // Add isotope metastate
        isotopems.resize(isotopes.size()*NMetaLevels);
        for (long i=0; i<isotopes.size(); i++) {
            auto& is  = isotopes[i];
            for (long l=0; l<NMetaLevels; l++) {
                auto& ism = isotopems[i*NMetaLevels + l];
                ism.isotope = &(is);
                ism.level = l+1;
            }
        }
        
        
    } catch (std::exception& e) {
        std::cerr << "[NIST]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
}

NISTElement* NIST::getElement(long atomicNumber) {
    
    try {
        
        // Check initialization
        if (!NIST::initialized) {
            if(loadFromJsonData(NISTJsonData)) {
                NIST::initialized = true;
            } else {
                throw std::logic_error("unable to load json data!");
            }
        }
        
        // Continue fetch element
        auto it = elements.find(atomicNumber);
        if (it == elements.end()) {
            throw std::logic_error("no element for given atomic number!");
        }
        
        return &(it->second);
        
    } catch (std::exception& e) {
        std::cerr << "[NIST]: error msg - " << e.what() << std::endl;
        return nullptr;
    }
    
    return nullptr;
}

NISTIsotope* NIST::getIsotope(long atomicNumber, long massNumber) {
    
    try {
    
        // Check initialization
        if (!NIST::initialized) {
            if(loadFromJsonData(NISTJsonData)) {
                NIST::initialized = true;
            } else {
                throw std::logic_error("unable to load json data!");
            }
        }
        
        // Continue fetch isotope
        auto it = elements.find(atomicNumber);
        if (it == elements.end()) {
            throw std::logic_error("no element for given atomic number!");
        }
        
        auto& el = it->second;
        
        auto is = std::find_if
        (el.components.begin(), el.components.end(),
         [massNumber](const std::pair<NISTMaterial*, double>& p) {
             return dynamic_cast<NISTIsotope*>(p.first)->massNumber
             == massNumber;
         });
        
        if (is == el.components.end()) {
            throw std::logic_error
            ("no element for given atomic & mass number!");
        }
        
        return (dynamic_cast<NISTIsotope*>(is->first));
        
    } catch (std::exception& e) {
        std::cerr << "[NIST]: error msg - " << e.what() << std::endl;
        return nullptr;
    }
    
    return nullptr;
}

NISTIsotopeMetaState* NIST::getIsotopeM
(long atomicNumber, long massNumber, long level) {
    
    try {
        
        // Check initialization
        if (!NIST::initialized) {
            if(loadFromJsonData(NISTJsonData)) {
                NIST::initialized = true;
            } else {
                throw std::logic_error("unable to load json data!");
            }
        }
        
        // Continue fetch isotopem
        auto it = std::find_if
        (isotopems.begin(), isotopems.end(),
         [atomicNumber, massNumber, level]
         (const NISTIsotopeMetaState& ism) {
             auto is = ism.isotope;
             return
             (is != nullptr) &&
             (is->element->atomicNumber == atomicNumber) &&
             (is->massNumber == massNumber) &&
             (ism.level == level);
        });
        
        if (it == isotopems.end()) {
            throw std::logic_error("no isotope meta state!");
        }
        
        return &(*it);
        
    } catch (std::exception& e) {
        std::cerr << "[NIST]: error msg - " << e.what() << std::endl;
        return nullptr;
    }
    
    return nullptr;
    
}
