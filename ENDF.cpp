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

#include "CMS.hpp"
#include "ENDF.hpp"
#include "NIST.hpp"

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

// Static defined data

// Define and Initialize ENDF IDName
std::map<long, NISTIsotope*>          ENDF::isotopes;
std::map<long, NISTIsotopeMetaState*> ENDF::isotopems;
std::map<long, NISTElement*>          ENDF::elements;
bool ENDF::initialized = false;

// Implementation of ENDF functions
bool ENDF::generateMaterials() {
    
    try {
        
        isotopes[125]   = NIST::getIsotope(1, 1);
        isotopes[128]   = NIST::getIsotope(1, 2);
        isotopes[131]   = NIST::getIsotope(1, 3);
        isotopes[225]   = NIST::getIsotope(2, 3);
        isotopes[228]   = NIST::getIsotope(2, 4);
        isotopes[325]   = NIST::getIsotope(3, 6);
        isotopes[328]   = NIST::getIsotope(3, 7);
        isotopes[419]   = NIST::getIsotope(4, 7);
        isotopes[425]   = NIST::getIsotope(4, 9);
        isotopes[525]   = NIST::getIsotope(5, 10);
        
        isotopes[528]   = NIST::getIsotope(5, 11);
        elements[600]   = NIST::getElement(6);
        isotopes[725]   = NIST::getIsotope(7, 14);
        isotopes[728]   = NIST::getIsotope(7, 15);
        isotopes[825]   = NIST::getIsotope(8, 16);
        isotopes[828]   = NIST::getIsotope(8, 17);
        isotopes[925]   = NIST::getIsotope(9, 19);
        isotopes[1122]  = NIST::getIsotope(11, 22);
        isotopes[1125]  = NIST::getIsotope(11, 23);
        isotopes[1225]  = NIST::getIsotope(12, 24);
        
        isotopes[1228]  = NIST::getIsotope(12, 25);
        isotopes[1231]  = NIST::getIsotope(12, 26);
        isotopes[1325]  = NIST::getIsotope(13, 27);
        isotopes[1425]  = NIST::getIsotope(14, 28);
        isotopes[1428]  = NIST::getIsotope(14, 29);
        isotopes[1431]  = NIST::getIsotope(14, 30);
        isotopes[1525]  = NIST::getIsotope(15, 31);
        isotopes[1625]  = NIST::getIsotope(16, 32);
        isotopes[1628]  = NIST::getIsotope(16, 33);
        isotopes[1631]  = NIST::getIsotope(16, 34);
        
        isotopes[1637]  = NIST::getIsotope(16, 36);
        isotopes[1725]  = NIST::getIsotope(17, 35);
        isotopes[1731]  = NIST::getIsotope(17, 37);
        isotopes[1825]  = NIST::getIsotope(18, 36);
        isotopes[1831]  = NIST::getIsotope(18, 38);
        isotopes[1837]  = NIST::getIsotope(18, 40);
        isotopes[1925]  = NIST::getIsotope(19, 39);
        isotopes[1928]  = NIST::getIsotope(19, 40);
        isotopes[1931]  = NIST::getIsotope(19, 41);
        isotopes[2025]  = NIST::getIsotope(20, 40);
        
        isotopes[2031]  = NIST::getIsotope(20, 42);
        isotopes[2034]  = NIST::getIsotope(20, 43);
        isotopes[2037]  = NIST::getIsotope(20, 44);
        isotopes[2043]  = NIST::getIsotope(20, 46);
        isotopes[2049]  = NIST::getIsotope(20, 48);
        isotopes[2125]  = NIST::getIsotope(21, 45);
        isotopes[2225]  = NIST::getIsotope(22, 46);
        isotopes[2228]  = NIST::getIsotope(22, 47);
        isotopes[2231]  = NIST::getIsotope(22, 48);
        isotopes[2234]  = NIST::getIsotope(22, 49);
        isotopes[2237]  = NIST::getIsotope(22, 50);
        
        elements[2300]  = NIST::getElement(23);
        isotopes[2325]  = NIST::getIsotope(23, 50);
        isotopes[2328]  = NIST::getIsotope(23, 51);
        isotopes[2425]  = NIST::getIsotope(24, 50);
        isotopes[2431]  = NIST::getIsotope(24, 52);
        isotopes[2434]  = NIST::getIsotope(24, 53);
        isotopes[2437]  = NIST::getIsotope(24, 54);
        isotopes[2525]  = NIST::getIsotope(25, 55);
        isotopes[2625]  = NIST::getIsotope(26, 54);
        isotopes[2631]  = NIST::getIsotope(26, 56);
        isotopes[2634]  = NIST::getIsotope(26, 57);
        
        isotopes[2637]  = NIST::getIsotope(26, 58);
        isotopes[2722]  = NIST::getIsotope(27, 58);
        isotopems[2723] = NIST::getIsotopeM(27, 58, 1);
        isotopes[2725]  = NIST::getIsotope(27, 59);
        isotopes[2825]  = NIST::getIsotope(28, 58);
        isotopes[2828]  = NIST::getIsotope(28, 59);
        isotopes[2831]  = NIST::getIsotope(28, 60);
        isotopes[2834]  = NIST::getIsotope(28, 61);
        isotopes[2837]  = NIST::getIsotope(28, 62);
        isotopes[2843]  = NIST::getIsotope(28, 64);
        
        isotopes[2925]  = NIST::getIsotope(29, 63);
        isotopes[2931]  = NIST::getIsotope(29, 65);
        elements[3000]  = NIST::getElement(30);
        isotopes[3025]  = NIST::getIsotope(30, 64);
        isotopes[3028]  = NIST::getIsotope(30, 65);
        isotopes[3031]  = NIST::getIsotope(30, 66);
        isotopes[3034]  = NIST::getIsotope(30, 67);
        isotopes[3037]  = NIST::getIsotope(30, 68);
        isotopes[3043]  = NIST::getIsotope(30, 70);
        isotopes[3125]  = NIST::getIsotope(31, 69);
        isotopes[3131]  = NIST::getIsotope(31, 71);
        
        isotopes[3225]  = NIST::getIsotope(32, 70);
        isotopes[3231]  = NIST::getIsotope(32, 72);
        isotopes[3234]  = NIST::getIsotope(32, 73);
        isotopes[3237]  = NIST::getIsotope(32, 74);
        isotopes[3243]  = NIST::getIsotope(32, 76);
        isotopes[3322]  = NIST::getIsotope(33, 74);
        isotopes[3325]  = NIST::getIsotope(33, 75);
        isotopes[3425]  = NIST::getIsotope(34, 74);
        isotopes[3431]  = NIST::getIsotope(34, 76);
        isotopes[3434]  = NIST::getIsotope(34, 77);
        isotopes[3437]  = NIST::getIsotope(34, 78);
        
        isotopes[3440]  = NIST::getIsotope(34, 79);
        isotopes[3443]  = NIST::getIsotope(34, 80);
        isotopes[3449]  = NIST::getIsotope(34, 82);
        isotopes[3525]  = NIST::getIsotope(35, 79);
        isotopes[3531]  = NIST::getIsotope(35, 81);
        isotopes[3625]  = NIST::getIsotope(36, 78);
        isotopes[3631]  = NIST::getIsotope(36, 80);
        isotopes[3637]  = NIST::getIsotope(36, 82);
        isotopes[3640]  = NIST::getIsotope(36, 83);
        isotopes[3643]  = NIST::getIsotope(36, 84);
        
        isotopes[3646]  = NIST::getIsotope(36, 85);
        isotopes[3649]  = NIST::getIsotope(36, 86);
        isotopes[3725]  = NIST::getIsotope(37, 85);
        isotopes[3728]  = NIST::getIsotope(37, 86);
        isotopes[3731]  = NIST::getIsotope(37, 87);
        isotopes[3825]  = NIST::getIsotope(38, 84);
        isotopes[3831]  = NIST::getIsotope(38, 86);
        isotopes[3834]  = NIST::getIsotope(38, 87);
        isotopes[3837]  = NIST::getIsotope(38, 88);
        isotopes[3840]  = NIST::getIsotope(38, 89);
        
        isotopes[3843]  = NIST::getIsotope(38, 90);
        isotopes[3925]  = NIST::getIsotope(39, 89);
        isotopes[3928]  = NIST::getIsotope(39, 90);
        isotopes[3931]  = NIST::getIsotope(39, 91);
        isotopes[4025]  = NIST::getIsotope(40, 90);
        isotopes[4028]  = NIST::getIsotope(40, 91);
        isotopes[4031]  = NIST::getIsotope(40, 92);
        isotopes[4034]  = NIST::getIsotope(40, 93);
        isotopes[4037]  = NIST::getIsotope(40, 94);
        isotopes[4040]  = NIST::getIsotope(40, 95);
        
        isotopes[4043]  = NIST::getIsotope(40, 96);
        isotopes[4125]  = NIST::getIsotope(41, 93);
        isotopes[4128]  = NIST::getIsotope(41, 94);
        isotopes[4131]  = NIST::getIsotope(41, 95);
        isotopes[4225]  = NIST::getIsotope(42, 92);
        isotopes[4231]  = NIST::getIsotope(42, 94);
        isotopes[4234]  = NIST::getIsotope(42, 95);
        isotopes[4237]  = NIST::getIsotope(42, 96);
        isotopes[4240]  = NIST::getIsotope(42, 97);
        isotopes[4243]  = NIST::getIsotope(42, 98);
        isotopes[4246]  = NIST::getIsotope(42, 99);
        
        isotopes[4249]  = NIST::getIsotope(42, 100);
        isotopes[4325]  = NIST::getIsotope(43, 99);
        isotopes[4425]  = NIST::getIsotope(44, 96);
        isotopes[4431]  = NIST::getIsotope(44, 98);
        isotopes[4434]  = NIST::getIsotope(44, 99);
        isotopes[4437]  = NIST::getIsotope(44, 100);
        isotopes[4440]  = NIST::getIsotope(44, 101);
        isotopes[4443]  = NIST::getIsotope(44, 102);
        isotopes[4446]  = NIST::getIsotope(44, 103);
        isotopes[4449]  = NIST::getIsotope(44, 104);
        
        isotopes[4452]  = NIST::getIsotope(44, 105);
        isotopes[4455]  = NIST::getIsotope(44, 106);
        isotopes[4525]  = NIST::getIsotope(45, 103);
        isotopes[4531]  = NIST::getIsotope(45, 105);
        isotopes[4625]  = NIST::getIsotope(46, 102);
        isotopes[4631]  = NIST::getIsotope(46, 104);
        isotopes[4634]  = NIST::getIsotope(46, 105);
        isotopes[4637]  = NIST::getIsotope(46, 106);
        isotopes[4640]  = NIST::getIsotope(46, 107);
        isotopes[4643]  = NIST::getIsotope(46, 108);
        
        isotopes[4649]  = NIST::getIsotope(46, 110);
        isotopes[4725]  = NIST::getIsotope(47, 107);
        isotopes[4731]  = NIST::getIsotope(47, 109);
        isotopems[4735] = NIST::getIsotopeM(47, 110, 1);
        isotopes[4737]  = NIST::getIsotope(47, 111);
        isotopes[4825]  = NIST::getIsotope(48, 106);
        isotopes[4831]  = NIST::getIsotope(48, 108);
        isotopes[4837]  = NIST::getIsotope(48, 110);
        isotopes[4840]  = NIST::getIsotope(48, 111);
        isotopes[4843]  = NIST::getIsotope(48, 112);
        
        isotopes[4846]  = NIST::getIsotope(48, 113);
        isotopes[4849]  = NIST::getIsotope(48, 114);
        isotopems[4853] = NIST::getIsotopeM(48, 115, 1);
        isotopes[4855]  = NIST::getIsotope(48, 116);
        isotopes[4925]  = NIST::getIsotope(49, 113);
        isotopes[4931]  = NIST::getIsotope(49, 115);
        isotopes[5025]  = NIST::getIsotope(50, 112);
        isotopes[5028]  = NIST::getIsotope(50, 113);
        isotopes[5031]  = NIST::getIsotope(50, 114);
        isotopes[5034]  = NIST::getIsotope(50, 115);
        
        isotopes[5037]  = NIST::getIsotope(50, 116);
        isotopes[5040]  = NIST::getIsotope(50, 117);
        isotopes[5043]  = NIST::getIsotope(50, 118);
        isotopes[5046]  = NIST::getIsotope(50, 119);
        isotopes[5049]  = NIST::getIsotope(50, 120);
        isotopes[5055]  = NIST::getIsotope(50, 122);
        isotopes[5058]  = NIST::getIsotope(50, 123);
        isotopes[5061]  = NIST::getIsotope(50, 124);
        isotopes[5064]  = NIST::getIsotope(50, 125);
        isotopes[5067]  = NIST::getIsotope(50, 126);
        
        isotopes[5125]  = NIST::getIsotope(51, 121);
        isotopes[5131]  = NIST::getIsotope(51, 123);
        isotopes[5134]  = NIST::getIsotope(51, 124);
        isotopes[5137]  = NIST::getIsotope(51, 125);
        isotopes[5140]  = NIST::getIsotope(51, 126);
        isotopes[5225]  = NIST::getIsotope(52, 120);
        isotopes[5231]  = NIST::getIsotope(52, 122);
        isotopes[5234]  = NIST::getIsotope(52, 123);
        isotopes[5237]  = NIST::getIsotope(52, 124);
        isotopes[5240]  = NIST::getIsotope(52, 125);
        
        isotopes[5243]  = NIST::getIsotope(52, 126);
        isotopems[5247] = NIST::getIsotopeM(52, 127, 1);
        isotopes[5249]  = NIST::getIsotope(52, 128);
        isotopems[5253] = NIST::getIsotopeM(52, 129, 1);
        isotopes[5255]  = NIST::getIsotope(52, 130);
        isotopes[5261]  = NIST::getIsotope(52, 132);
        isotopes[5325]  = NIST::getIsotope(53, 127);
        isotopes[5331]  = NIST::getIsotope(53, 129);
        isotopes[5334]  = NIST::getIsotope(53, 130);
        isotopes[5337]  = NIST::getIsotope(53, 131);
        
        isotopes[5349]  = NIST::getIsotope(53, 135);
        isotopes[5422]  = NIST::getIsotope(54, 123);
        isotopes[5425]  = NIST::getIsotope(54, 124);
        isotopes[5431]  = NIST::getIsotope(54, 126);
        isotopes[5437]  = NIST::getIsotope(54, 128);
        isotopes[5440]  = NIST::getIsotope(54, 129);
        isotopes[5443]  = NIST::getIsotope(54, 130);
        isotopes[5446]  = NIST::getIsotope(54, 131);
        isotopes[5449]  = NIST::getIsotope(54, 132);
        isotopes[5452]  = NIST::getIsotope(54, 133);
        
        isotopes[5455]  = NIST::getIsotope(54, 134);
        isotopes[5458]  = NIST::getIsotope(54, 135);
        isotopes[5461]  = NIST::getIsotope(54, 136);
        isotopes[5525]  = NIST::getIsotope(55, 133);
        isotopes[5528]  = NIST::getIsotope(55, 134);
        isotopes[5531]  = NIST::getIsotope(55, 135);
        isotopes[5534]  = NIST::getIsotope(55, 136);
        isotopes[5537]  = NIST::getIsotope(55, 137);
        isotopes[5625]  = NIST::getIsotope(56, 130);
        isotopes[5631]  = NIST::getIsotope(56, 132);
        
        isotopes[5634]  = NIST::getIsotope(56, 133);
        isotopes[5637]  = NIST::getIsotope(56, 134);
        isotopes[5640]  = NIST::getIsotope(56, 135);
        isotopes[5643]  = NIST::getIsotope(56, 136);
        isotopes[5646]  = NIST::getIsotope(56, 137);
        isotopes[5649]  = NIST::getIsotope(56, 138);
        isotopes[5655]  = NIST::getIsotope(56, 140);
        isotopes[5725]  = NIST::getIsotope(57, 138);
        isotopes[5728]  = NIST::getIsotope(57, 139);
        isotopes[5731]  = NIST::getIsotope(57, 140);
        
        isotopes[5825]  = NIST::getIsotope(58, 136);
        isotopes[5831]  = NIST::getIsotope(58, 138);
        isotopes[5834]  = NIST::getIsotope(58, 139);
        isotopes[5837]  = NIST::getIsotope(58, 140);
        isotopes[5840]  = NIST::getIsotope(58, 141);
        isotopes[5843]  = NIST::getIsotope(58, 142);
        isotopes[5846]  = NIST::getIsotope(58, 143);
        isotopes[5849]  = NIST::getIsotope(58, 144);
        isotopes[5925]  = NIST::getIsotope(59, 141);
        isotopes[5928]  = NIST::getIsotope(59, 142);
        
        isotopes[5931]  = NIST::getIsotope(59, 143);
        isotopes[6025]  = NIST::getIsotope(60, 142);
        isotopes[6028]  = NIST::getIsotope(60, 143);
        isotopes[6031]  = NIST::getIsotope(60, 144);
        isotopes[6034]  = NIST::getIsotope(60, 145);
        isotopes[6037]  = NIST::getIsotope(60, 146);
        isotopes[6040]  = NIST::getIsotope(60, 147);
        isotopes[6043]  = NIST::getIsotope(60, 148);
        isotopes[6049]  = NIST::getIsotope(60, 150);
        isotopes[6149]  = NIST::getIsotope(61, 147);
        
        isotopes[6152]  = NIST::getIsotope(61, 148);
        isotopems[6153] = NIST::getIsotopeM(61, 148, 1);
        isotopes[6155]  = NIST::getIsotope(61, 149);
        isotopes[6161]  = NIST::getIsotope(61, 151);
        isotopes[6225]  = NIST::getIsotope(62, 144);
        isotopes[6234]  = NIST::getIsotope(62, 147);
        isotopes[6237]  = NIST::getIsotope(62, 148);
        isotopes[6240]  = NIST::getIsotope(62, 149);
        isotopes[6243]  = NIST::getIsotope(62, 150);
        isotopes[6246]  = NIST::getIsotope(62, 151);
        
        isotopes[6249]  = NIST::getIsotope(62, 152);
        isotopes[6252]  = NIST::getIsotope(62, 153);
        isotopes[6255]  = NIST::getIsotope(62, 154);
        isotopes[6325]  = NIST::getIsotope(63, 151);
        isotopes[6328]  = NIST::getIsotope(63, 152);
        isotopes[6331]  = NIST::getIsotope(63, 153);
        isotopes[6334]  = NIST::getIsotope(63, 154);
        isotopes[6337]  = NIST::getIsotope(63, 155);
        isotopes[6340]  = NIST::getIsotope(63, 156);
        isotopes[6343]  = NIST::getIsotope(63, 157);
        
        isotopes[6425]  = NIST::getIsotope(64, 152);
        isotopes[6428]  = NIST::getIsotope(64, 153);
        isotopes[6431]  = NIST::getIsotope(64, 154);
        isotopes[6434]  = NIST::getIsotope(64, 155);
        isotopes[6437]  = NIST::getIsotope(64, 156);
        isotopes[6440]  = NIST::getIsotope(64, 157);
        isotopes[6443]  = NIST::getIsotope(64, 158);
        isotopes[6449]  = NIST::getIsotope(64, 160);
        isotopes[6525]  = NIST::getIsotope(65, 159);
        isotopes[6528]  = NIST::getIsotope(65, 160);
        
        isotopes[6625]  = NIST::getIsotope(66, 156);
        isotopes[6631]  = NIST::getIsotope(66, 158);
        isotopes[6637]  = NIST::getIsotope(66, 160);
        isotopes[6640]  = NIST::getIsotope(66, 161);
        isotopes[6643]  = NIST::getIsotope(66, 162);
        isotopes[6646]  = NIST::getIsotope(66, 163);
        isotopes[6649]  = NIST::getIsotope(66, 164);
        isotopes[6725]  = NIST::getIsotope(67, 165);
        isotopems[6729] = NIST::getIsotopeM(67, 166, 1);
        isotopes[6825]  = NIST::getIsotope(68, 162);
        
        isotopes[6831]  = NIST::getIsotope(68, 164);
        isotopes[6837]  = NIST::getIsotope(68, 166);
        isotopes[6840]  = NIST::getIsotope(68, 167);
        isotopes[6843]  = NIST::getIsotope(68, 168);
        isotopes[6849]  = NIST::getIsotope(68, 170);
        isotopes[6922]  = NIST::getIsotope(69, 168);
        isotopes[6925]  = NIST::getIsotope(69, 169);
        isotopes[6928]  = NIST::getIsotope(69, 170);
        isotopes[7125]  = NIST::getIsotope(71, 175);
        isotopes[7128]  = NIST::getIsotope(71, 176);
        
        isotopes[7225]  = NIST::getIsotope(72, 174);
        isotopes[7231]  = NIST::getIsotope(72, 176);
        isotopes[7234]  = NIST::getIsotope(72, 177);
        isotopes[7237]  = NIST::getIsotope(72, 178);
        isotopes[7240]  = NIST::getIsotope(72, 179);
        isotopes[7243]  = NIST::getIsotope(72, 180);
        isotopes[7325]  = NIST::getIsotope(73, 180);
        isotopes[7328]  = NIST::getIsotope(73, 181);
        isotopes[7331]  = NIST::getIsotope(73, 182);
        isotopes[7425]  = NIST::getIsotope(74, 180);
        
        isotopes[7431]  = NIST::getIsotope(74, 182);
        isotopes[7434]  = NIST::getIsotope(74, 183);
        isotopes[7437]  = NIST::getIsotope(74, 184);
        isotopes[7443]  = NIST::getIsotope(74, 186);
        isotopes[7525]  = NIST::getIsotope(75, 185);
        isotopes[7531]  = NIST::getIsotope(75, 187);
        isotopes[7725]  = NIST::getIsotope(77, 191);
        isotopes[7731]  = NIST::getIsotope(77, 193);
        isotopes[7925]  = NIST::getIsotope(79, 197);
        isotopes[8025]  = NIST::getIsotope(80, 196);
        
        isotopes[8031]  = NIST::getIsotope(80, 198);
        isotopes[8034]  = NIST::getIsotope(80, 199);
        isotopes[8037]  = NIST::getIsotope(80, 200);
        isotopes[8040]  = NIST::getIsotope(80, 201);
        isotopes[8043]  = NIST::getIsotope(80, 202);
        isotopes[8049]  = NIST::getIsotope(80, 204);
        isotopes[8125]  = NIST::getIsotope(81, 203);
        isotopes[8131]  = NIST::getIsotope(81, 205);
        isotopes[8225]  = NIST::getIsotope(82, 204);
        isotopes[8231]  = NIST::getIsotope(82, 206);
        
        isotopes[8234]  = NIST::getIsotope(82, 207);
        isotopes[8237]  = NIST::getIsotope(82, 208);
        isotopes[8325]  = NIST::getIsotope(83, 209);
        isotopes[8825]  = NIST::getIsotope(88, 223);
        isotopes[8828]  = NIST::getIsotope(88, 224);
        isotopes[8831]  = NIST::getIsotope(88, 225);
        isotopes[8834]  = NIST::getIsotope(88, 226);
        isotopes[8925]  = NIST::getIsotope(89, 225);
        isotopes[8928]  = NIST::getIsotope(89, 226);
        isotopes[8931]  = NIST::getIsotope(89, 227);
        
        isotopes[9025]  = NIST::getIsotope(90, 227);
        isotopes[9028]  = NIST::getIsotope(90, 228);
        isotopes[9031]  = NIST::getIsotope(90, 229);
        isotopes[9034]  = NIST::getIsotope(90, 230);
        isotopes[9037]  = NIST::getIsotope(90, 231);
        isotopes[9040]  = NIST::getIsotope(90, 232);
        isotopes[9043]  = NIST::getIsotope(90, 233);
        isotopes[9046]  = NIST::getIsotope(90, 234);
        isotopes[9125]  = NIST::getIsotope(91, 229);
        isotopes[9128]  = NIST::getIsotope(91, 230);
        
        isotopes[9131]  = NIST::getIsotope(91, 231);
        isotopes[9134]  = NIST::getIsotope(91, 232);
        isotopes[9137]  = NIST::getIsotope(91, 233);
        isotopes[9213]  = NIST::getIsotope(92, 230);
        isotopes[9216]  = NIST::getIsotope(92, 231);
        isotopes[9219]  = NIST::getIsotope(92, 232);
        isotopes[9222]  = NIST::getIsotope(92, 233);
        isotopes[9225]  = NIST::getIsotope(92, 234);
        isotopes[9228]  = NIST::getIsotope(92, 235);
        isotopes[9231]  = NIST::getIsotope(92, 236);
        
        isotopes[9234]  = NIST::getIsotope(92, 237);
        isotopes[9237]  = NIST::getIsotope(92, 238);
        isotopes[9240]  = NIST::getIsotope(92, 239);
        isotopes[9243]  = NIST::getIsotope(92, 240);
        isotopes[9246]  = NIST::getIsotope(92, 241);
        isotopes[9337]  = NIST::getIsotope(93, 234);
        isotopes[9340]  = NIST::getIsotope(93, 235);
        isotopes[9343]  = NIST::getIsotope(93, 236);
        isotopes[9346]  = NIST::getIsotope(93, 237);
        isotopes[9349]  = NIST::getIsotope(93, 238);
        
        isotopes[9352]  = NIST::getIsotope(93, 239);
        isotopes[9428]  = NIST::getIsotope(94, 236);
        isotopes[9431]  = NIST::getIsotope(94, 237);
        isotopes[9434]  = NIST::getIsotope(94, 238);
        isotopes[9437]  = NIST::getIsotope(94, 239);
        isotopes[9440]  = NIST::getIsotope(94, 240);
        isotopes[9443]  = NIST::getIsotope(94, 241);
        isotopes[9446]  = NIST::getIsotope(94, 242);
        isotopes[9449]  = NIST::getIsotope(94, 243);
        isotopes[9452]  = NIST::getIsotope(94, 244);
        
        isotopes[9458]  = NIST::getIsotope(94, 246);
        isotopes[9540]  = NIST::getIsotope(95, 240);
        isotopes[9543]  = NIST::getIsotope(95, 241);
        isotopes[9546]  = NIST::getIsotope(95, 242);
        isotopems[9547] = NIST::getIsotopeM(95, 242, 1);
        isotopes[9549]  = NIST::getIsotope(95, 243);
        isotopes[9552]  = NIST::getIsotope(95, 244);
        isotopems[9553] = NIST::getIsotopeM(95, 244, 1);
        isotopes[9625]  = NIST::getIsotope(96, 240);
        isotopes[9628]  = NIST::getIsotope(96, 241);
        
        isotopes[9631]  = NIST::getIsotope(96, 242);
        isotopes[9634]  = NIST::getIsotope(96, 243);
        isotopes[9637]  = NIST::getIsotope(96, 244);
        isotopes[9640]  = NIST::getIsotope(96, 245);
        isotopes[9643]  = NIST::getIsotope(96, 246);
        isotopes[9646]  = NIST::getIsotope(96, 247);
        isotopes[9649]  = NIST::getIsotope(96, 248);
        isotopes[9652]  = NIST::getIsotope(96, 249);
        isotopes[9655]  = NIST::getIsotope(96, 250);
        isotopes[9740]  = NIST::getIsotope(97, 245);
        
        isotopes[9743]  = NIST::getIsotope(97, 246);
        isotopes[9746]  = NIST::getIsotope(97, 247);
        isotopes[9749]  = NIST::getIsotope(97, 248);
        isotopes[9752]  = NIST::getIsotope(97, 249);
        isotopes[9755]  = NIST::getIsotope(97, 250);
        isotopes[9843]  = NIST::getIsotope(98, 246);
        isotopes[9849]  = NIST::getIsotope(98, 248);
        isotopes[9852]  = NIST::getIsotope(98, 249);
        isotopes[9855]  = NIST::getIsotope(98, 250);
        isotopes[9858]  = NIST::getIsotope(98, 251);
        
        isotopes[9861]  = NIST::getIsotope(98, 252);
        isotopes[9864]  = NIST::getIsotope(98, 253);
        isotopes[9867]  = NIST::getIsotope(98, 254);
        isotopes[9911]  = NIST::getIsotope(99, 251);
        isotopes[9912]  = NIST::getIsotope(99, 252);
        isotopes[9913]  = NIST::getIsotope(99, 253);
        isotopes[9914]  = NIST::getIsotope(99, 254);
        isotopems[9915] = NIST::getIsotopeM(99, 254, 1);
        isotopes[9916]  = NIST::getIsotope(99, 255);
        isotopes[9936]  = NIST::getIsotope(99, 255);
        
        for (auto& p : isotopems) {
            if (p.second == nullptr) {
                throw std::logic_error("unable to get NIST isotope meta!");
            }
        }
        
        for (auto& p : isotopes) {
            if (p.second == nullptr) {
                throw std::logic_error("unable to get NIST isotope!");
            }
        }
        
        for (auto& p : elements) {
            if (p.second == nullptr) {
                throw std::logic_error("unable to get NIST element!");
            }
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ENDF]: error msg - " << e.what() << std::endl;
        clear();
        return false;
    }
    
    return true;
    
}

void ENDF::clear() {
    
    isotopems.clear();
    isotopes.clear();
    elements.clear();
    
}

std::string ENDF::getNameFromID(long ID) {
    
    try {
        
        // Check initialization
        if (!ENDF::initialized) {
            if(generateMaterials()) {
                ENDF::initialized = true;
            } else {
                throw std::logic_error("unable to generate materials!");
            }
        }
        
        // Lookup isotopes
        if (isotopes.find(ID) != isotopes.end()) {
            auto is = isotopes.at(ID);
            return is->getSymbol();
        } else if (elements.find(ID) != elements.end()) {
            auto el = elements.at(ID);
            return el->getSymbol();
        } else if (isotopems.find(ID) != isotopems.end()) {
            auto ism = isotopems.at(ID);
            return ism->getSymbol();
        }
        // Check others
        else {
            // Throw errors if no match
            std::cerr<<"[ENDF]: unknown id "<<ID<<std::endl;
            throw std::logic_error("no match ENDF ID!");
        }
        
    } catch (std::exception& e) {
        std::cerr << "[ENDF]: error msg - " << e.what() << std::endl;
        return "";
    }
    
    return "";
    
};

// Define commonly used legendre coefficients
struct ENDFLegendreCoefficients {
    long maxOrder = 64;
    std::vector<double> coeff1; // (2*L+1)/(L+1), L >= 0
    std::vector<double> coeff2; // - L/(L+1), L >= 0
    std::vector<double> multip; // (2*L+1)/2, L >= 0
    
    std::vector<double> buffer; // For user
    
    ENDFLegendreCoefficients();
};

ENDFLegendreCoefficients::ENDFLegendreCoefficients() {
    coeff1.resize(maxOrder, 0.);
    coeff2.resize(maxOrder, 0.);
    multip.resize(maxOrder, 0.);
    buffer.resize(maxOrder, 0.);
    
    multip[0] = .5;
    coeff1[0] = 1.;
    coeff2[0] = 0.;
    double con1 = 3., con2 = 1.;
    for (long l=1; l<maxOrder; l++) {
        multip[l] = multip[l-1] + 1.;
        coeff1[l] = con1 / (con2 + 1.);
        coeff2[l] = -con2 / (con2 + 1.);
        con1 += 2.;
        con2 += 1.;
    }
}

static ENDFLegendreCoefficients gENDFLegendreCoefficients;

// Define ENDF file related data structures

// Utility functions
void ENDF::ReadLine(std::ifstream& inFile, std::string& line) {
    std::getline(inFile, line);
    if(inFile.bad() || inFile.eof() || line.length()<ENDFLineLength) {
        throw std::logic_error("Unable to get a proper line!");
    }
}

void ENDF::ScanLine
(std::string &line, long &MAT, long &MF, long &MT, long &NS) {
    MAT = std::stol(line.substr(ENDFMATStart, ENDFMATLength));
    MF  = std::stol(line.substr(ENDFMFStart,  ENDFMFLength));
    MT  = std::stol(line.substr(ENDFMTStart,  ENDFMTLength));
    NS  = std::stol(line.substr(ENDFNSStart,  ENDFNSLength));
}

ENDFControlRecordType ENDF::GetRecordType
(long MAT, long MF, long MT, long NS) {
    if (MAT == 1 && MF == 0 && MT == 0) {
        return ENDFControlRecordType::ENDF_TPID;
    } else if (MAT == -1 && MF == 0 && MT == 0) {
        return ENDFControlRecordType::ENDF_TEND;
    } else if (MAT == 0 && MF == 0 && MT == 0) {
        return ENDFControlRecordType::ENDF_MEND;
    } else if (MAT != 0 && MF == 0 && MT == 0) {
        return ENDFControlRecordType::ENDF_FEND;
    } else if (MAT != 0 && MF != 0 && MT == 0) {
        return ENDFControlRecordType::ENDF_SEND;
    } else {
        return ENDFControlRecordType::ENDF_NONE;
    }
}

std::vector<double> ENDF::ScanNums(const std::string& line) {
    std::vector<double> nums(ENDFNumPerLine,0);
    std::string numberString, mantissaString;
    long l;
    double m;
    long sgnPos, e;
    
    for (long i=0; i<ENDFNumPerLine; i++) {
        numberString = line.substr
        (i*ENDFNumWidth, ENDFNumWidth);
        if (numberString.find_first_not_of(' ') ==
            std::string::npos) {
            // Empty chraters string
            nums[i] = 0;
        } else if (numberString[2] == '.') {
            // Floating number
            // Two pointer location
            if (numberString[8]=='-' ||
                numberString[8]=='+') {
                sgnPos = 8;
            } else if (numberString[9]=='-' ||
                       numberString[9]=='+') {
                sgnPos = 9;
            } else {
                std::cout
                <<" ENDF: Number format error!"
                <<std::endl;
                sgnPos  = 0;
                nums[i] = 0;
            }
            // Obtain exponential
            try {
                e = std::stol
                (numberString.substr(sgnPos, ENDFNumWidth-sgnPos));
            } catch (std::invalid_argument) {
                std::cout
                <<" ENDF: Number format error!"
                <<std::endl;
                e = 0;
            }
            // Obtain mantissa integer
            mantissaString = numberString.substr(0, sgnPos);
            mantissaString.erase(2,1);
            try {
                l = std::stol(mantissaString);
            } catch (std::invalid_argument) {
                std::cout
                <<" ENDF: Number format error!"
                <<std::endl;
                l = 0;
            }
            // Modifiy exponential
            e -= (sgnPos-3);
            // Peform exact integer representation for double
            m = l;
            if (e > 0) {
                for (long j = 0; j < e; j++) {
                    m *= 10;
                }
            } else if (e < 0) {
                for (long j = 0; j < -e; j++) {
                    m /= 10;
                }
            }
            nums[i] = m;
        } else {
            // Integer
            try {
                l = std::stol(numberString);
                nums[i] = l;
            } catch (std::invalid_argument) {
                std::cout
                <<" ENDF: Number format error!"
                <<std::endl;
                nums[i] = 0;
            }
        }
    }
    
    return nums;
};

ENDFRecord ENDF::ReadRecord(std::ifstream& inFile) {
    ENDFRecord record;
    std::string line;
    ENDF::ReadLine(inFile, line);
    ENDF::ScanLine(line, record.MAT, record.MF, record.MT, record.NS);
    record.nums = ENDF::ScanNums(line);
    
    return record;
};

std::vector<double> ENDF::ReadNNumbers
(std::ifstream& inFile, long N) {
    std::vector<double> numbers, nums;
    std::string line;
    
    // Check N dimension
    if (N <= 0) {
        return numbers;
    }
    
    numbers.reserve(N);
    nums.reserve(ENDFNumPerLine);
    long n=0;
    if (n >= N) {
        return numbers;
    }
    do {
        ENDF::ReadLine(inFile, line);
        nums = ENDF::ScanNums(line);
        
        if (n+ENDFNumPerLine >= N) {
            for (long i=0; i<N-n; i++) {
                numbers.push_back(nums[i]);
            }
        } else {
            for (long i=0; i<ENDFNumPerLine; i++) {
                numbers.push_back(nums[i]);
            }
        }
        n += ENDFNumPerLine;
    } while (n < N);
    
    return numbers;
}

std::string ENDF::LibraryName(long NLIB, long NVER, long LREL) {
    std::stringstream ss;
    std::string libString;
    switch (NLIB) {
        case 0:
            libString = "ENDF/B";
            break;
        case 1:
            libString = "ENDF/A";
            break;
        case 2:
            libString = "JEFF";
            break;
        case 3:
            libString = "EFF";
            break;
        case 4:
            libString = "ENDF/B High Energy";
            break;
        case 5:
            libString = "CENDL";
            break;
        case 6:
            libString = "JENDL";
            break;
        case 21:
            libString = "SG-23";
            break;
        case 31:
            libString = "INDL/V";
            break;
        case 32:
            libString = "INDL/A";
            break;
        case 33:
            libString = "FENDL";
            break;
        case 34:
            libString = "IRDF";
            break;
        case 35:
            libString = "BROND-IAEA";
            break;
        case 36:
            libString = "INGDB-90";
            break;
        case 37:
            libString = "FENDL/A";
            break;
        case 41:
            libString = "BROND";
            break;
        default:
            libString = "UNKNOWN";
            break;
    }
    ss<<libString<<" "<<NVER<<"."<<LREL;
    return ss.str();
}

// Implementations of material header
//static inline bool operator
// <(const ENDFMaterialHeader& h1, const ENDFMaterialHeader& h2) {
//    if (h1.MAT != h2.MAT) {
//        return h1.MAT < h2.MAT;
//    }
//    if (h1.NLIB != h2.NLIB) {
//        return h1.NLIB < h2.NLIB;
//    }
//    if (h1.NVER != h2.NVER) {
//        return h1.NVER < h2.NVER;
//    }
//    if (h1.LREL != h2.LREL) {
//        return h1.LREL < h2.LREL;
//    }
//    if (h1.NSUB != h2.NSUB) {
//        return h1.NSUB < h2.NSUB;
//    }
//    if (h1.NMOD != h2.NMOD) {
//        return h1.NMOD < h2.NMOD;
//    }
//    if (h1.LDRV != h2.LDRV) {
//        return h1.LDRV < h2.LDRV;
//    }
//    if (h1.TEMP != h2.TEMP) {
//        return h1.TEMP < h2.TEMP;
//    }
//
//    return false;
//};

static inline bool operator== (const ENDFMaterialHeader& h1, const ENDFMaterialHeader& h2) {
    return (h1.MAT == h2.MAT) && (h1.NLIB == h2.NLIB) && (h1.NVER == h2.NVER)
    && (h1.LREL == h2.LREL) && (h1.NSUB == h2.NSUB) && (h1.NMOD == h2.NMOD)
    && (h1.LDRV == h2.LDRV) && (h1.TEMP == h2.TEMP);
};

static long ENDFTabGetLaw
(const std::vector<ENDFInterpLaw>& interp, long i) {
    long m = -1, n = -1, law = -1;
    
    // Range check
    if (i<0 || i>(interp.back().NBT-2)) {
        return 0;
    }
    if (interp.empty()) {
        // Linear-Linear law
        law = 2;
    } else {
        // Obtain region number m
        m = 0, n = (long)interp.size();
        // Binary search
        while (m + 1 < n ) {
            // k >= 1 is garanteed
            long k = ( m + n )/2;
            if (i >= (interp[k-1].NBT-1)) {
                m = k;
            } else {
                n = k;
            }
        }
        // Assign law
        law = interp[m].INT;
    }
    
    return law;
}

// This function evaluates the interpolated value of an ENDF table
double ENDFInterpolationFunction::evaluate(double x) const {
    double y = 0.;
    
    if (x<_data.front().x) {
        return _data.front().y;
    }
    
    if (x>=_data.back().x) {
        return _data.back().y;
    }
    
    long i   = ENDFTabLocateIdx(_data, x);
    long law = ENDFTabGetLaw(_interp, i);
    
    // Perform intepolation
    if (law >= 1 && law <= 5) {
        y = ENDFInterpEval
        (_data[i].x, _data[i].y, _data[i+1].x, _data[i+1].y, x, law);
    } else {
        throw std::logic_error("unsupport ENDF law!");
    }
    
    if (isinf(y) || isnan(y)) {
        throw std::logic_error("evaluate data error!");
    }
    
    return y;
};

double ENDFPolynomialFunction::evaluate(double x) const {
    double y = 0., xn = 1.;
    for (auto c : coefficents) {
        y  += c*xn;
        xn *= x;
    }
    return y;
}

// Implementations of distribution
double ENDFLegendreDistribution::evaluate(double x) const {
    auto& L = gENDFLegendreCoefficients;
    if (coefficents.size() > L.maxOrder) {
        throw std::logic_error("max legendre order exceeds!");
    }
    auto& P = L.buffer;
    P[0] = 1.;
    P[1] = x;
    double y = L.multip[0]*P[0];
    for (long l=1; l<=coefficents.size(); l++) {
        if (l >= 2) {
            P[l] = L.coeff1[l-1]*x*P[l-1] + L.coeff2[l-1]*P[l-2];
        }
        y += L.multip[l]*coefficents[l-1]*P[l];
    }
    
    // Set to CMS::zeroThres if negative
    if (y < CMS::zeroThres) {
        y = CMS::zeroThres;
    }
    
    return y;
}

bool ENDFLegendreDistribution::isIsotropic() const {
    return std::all_of
    (coefficents.begin(), coefficents.end(),
     [](double v){return v == 0.;});
}

// ENDF Math functions
inline static double ENDFSLBWPenetrationFactor(long l, double rho) {
    if (l == 0) {
        return rho;
    } else if (l == 1) {
        auto rho2 = rho*rho;
        auto rho3 = rho2*rho;
        return rho3 / (1. + rho2);
    } else if (l == 2) {
        auto rho2 = rho*rho;
        auto rho4 = rho2*rho2;
        auto rho5 = rho4*rho;
        return rho5 / (9. + 3.*rho2 + rho4);
    } else if (l == 3) {
        auto rho2 = rho*rho;
        auto rho4 = rho2*rho2;
        auto rho6 = rho4*rho2;
        auto rho7 = rho6*rho;
        return rho7 / (225. + 45.*rho2 + 6.*rho4 + rho6);
    } else if (l == 4) {
        auto rho2 = rho*rho;
        auto rho4 = rho2*rho2;
        auto rho6 = rho4*rho2;
        auto rho8 = rho4*rho4;
        auto rho9 = rho8*rho;
        return rho9/(11025. + 1575.*rho2 + 135.*rho4 + 10.*rho6 + rho8);
    } else {
        throw std::logic_error("unsupport angular momentum!");
    }
}

inline static double ENDFSLBWPhaseShift(long l, double rho) {
    if (l == 0) {
        return rho;
    } else if (l == 1) {
        return rho-atan(rho);
    } else if (l == 2) {
        auto rho2 = rho*rho;
        return rho - atan(3.*rho/(3. - rho2));
    } else if (l == 3) {
        auto rho2 = rho*rho;
        auto rho3 = rho2*rho;
        return rho - atan((15.*rho - rho3)/(15. - 6.*rho2));
    } else if (l == 4) {
        auto rho2 = rho*rho;
        auto rho3 = rho2*rho;
        auto rho4 = rho2*rho2;
        return rho - atan((105.*rho - 10.*rho3)/(105. - 45.*rho2 + rho4));
    } else {
        throw std::logic_error("unsupport angular momentum!");
    }
}

inline static double ENDFSLBWShiftFactor(long l, double rho) {
    if (l == 0) {
        return 0.;
    } else if (l == 1) {
        auto rho2 = rho*rho;
        return -1./(1. + rho2);
    } else if (l == 2) {
        auto rho2 = rho*rho;
        auto rho4 = rho2*rho2;
        return -(18. + 3.*rho2) / (9. + 3.*rho2 + rho4);
    } else if (l == 3) {
        auto rho2 = rho*rho;
        auto rho4 = rho2*rho2;
        auto rho6 = rho4*rho2;
        return -(675. + 90.*rho2 + 6.*rho4) /
        (225. + 45.*rho2 + 6.*rho4 + rho6);
    } else if (l == 4) {
        auto rho2 = rho*rho;
        auto rho4 = rho2*rho2;
        auto rho6 = rho4*rho2;
        auto rho8 = rho4*rho4;
        return -(44100. + 4725.*rho2 + 270.*rho4 + 10.*rho6) /
        (11025. + 1575.*rho2 + 135.*rho4 + 10.*rho6 + rho8);
    } else {
        throw std::logic_error("unsupport angular momentum!");
    }
}

inline static double ENDFSLBWPsi0(double x) {
    return 1./(1. + x*x);
}

inline static double ENDFSLBWChi0(double x) {
    return x/(1. + x*x);
}

inline static double ENDFSqr(double x) {
    return x*x;
}

// Inverts symmetric matrix
static void ENDFSYMINV
(std::vector<std::vector<double>>& D, long N, long& KIMERR) {
    double FOOEY;
    std::vector<double> S(N,0);
    
    KIMERR = 0;
    for (long j=0; j<N; j++) {
        for (long i=0; i<=j; i++) {
            D[i][j] = -D[i][j];
            D[j][i] = D[i][j];
        }
        D[j][j] += 1;
    }
    for (long lr=0; lr<N; lr++) {
        FOOEY = 1-D[lr][lr];
        if (FOOEY == 0) {
            std::cout<<" ENDF: Matrix not invertable!"<<std::endl;
            KIMERR = 1;
            return;
        }
        D[lr][lr] = 1/FOOEY;
        for (long j=0; j<N; j++) {
            S[j] = D[lr][j];
            if (j != lr) {
                D[j][lr] *= D[lr][lr];
                D[lr][j] =  D[j][lr];
            }
        }
        for (long j=0; j<N; j++) {
            if (j != lr) {
                for (long i=0; i<=j; i++) {
                    if (i != lr) {
                        D[i][j] += D[i][lr]*S[j];
                        D[j][i] =  D[i][j];
                    }
                }
            }
        }
    }
}

// Matrix multiplication
static void ENDFABCMAT
(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B,
 std::vector<std::vector<double>>& C, long N) {
    for (long i=0; i<N; i++) {
        for (long j=0; j<N; j++) {
            C[i][j] = 0;
            for (long k=0; k<N; k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

//    THIS SUBROUTINE INVERTS A COMPLEX MATRIX WITH REAL AND IMAGINARY
//!     PARTS A AND B AND GIVES C AND D THE REAL AND IMAGINARY PARTS OF
//!     THE INVERSE. FROBENIUS-SCHUR METHOD OF INVERSION.
static void ENDFFROBNS
(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B,
 std::vector<std::vector<double>>& C, std::vector<std::vector<double>>& D,
 long N) {
    long IND;
    decltype(A) Q = A;
    
    C = A;
    ENDFSYMINV(A, N, IND);
    if (IND != 1) {
        ENDFABCMAT(A, B, Q, N);
        ENDFABCMAT(B, Q, D, N);
        for (long i=0; i<N; i++) {
            for (long j=0; j<N; j++) {
                C[i][j] += D[i][j];
            }
        }
        ENDFSYMINV(C, N, IND);
        if (IND != 1) {
            ENDFABCMAT(Q, C, D, N);
            for (long i=0; i<N; i++) {
                for (long j=0; j<N; j++) {
                    D[i][j] = -D[i][j];
                }
            }
        }
    }
}

static void ENDFGNRL
(double GALPHA, double GBETA, double GAMMA,
 long MU, long NU, long LAMBDA,
 double& S, double DF, long ID) {
    double XJ, WJ, XK, WK, XL, WL;
    std::vector<std::vector<double>> XX({
        {3.0013465E-03,1.3219203E-02,1.0004488E-03,1.3219203E-02},
        {7.8592886E-02,7.2349624E-02,2.6197629E-02,7.2349624E-02},
        {4.3282415E-01,1.9089473E-01,1.4427472E-01,1.9089473E-01},
        {1.3345267E+00,3.9528842E-01,4.4484223E-01,3.9528842E-01},
        {3.0481846E+00,7.4083443E-01,1.0160615E+00,7.4083443E-01},
        {5.8263198E+00,1.3498293E+00,1.9421066E+00,1.3498293E+00},
        {9.9452656E+00,2.5297983E+00,3.3150885E+00,2.5297983E+00},
        {1.5782128E+01,5.2384894E+00,5.2607092E+00,5.2384894E+00},
        {2.3996824E+01,1.3821772E+01,7.9989414E+00,1.3821772E+01},
        {3.6216208E+01,7.5647525E+01,1.2072069E+01,7.5647525E+01}
    });
    std::vector<std::vector<double>> WW({
        {1.1120413E-01,3.3773418E-02,3.3376214E-04,1.7623788E-03},
        {2.3546798E-01,7.9932171E-02,1.8506108E-02,2.1517749E-02},
        {2.8440987E-01,1.2835937E-01,1.2309946E-01,8.0979849E-02},
        {2.2419127E-01,1.7652616E-01,2.9918923E-01,1.8797998E-01},
        {1.0967668E-01,2.1347043E-01,3.3431475E-01,3.0156335E-01},
        {3.0493789E-02,2.1154965E-01,1.7766657E-01,2.9616091E-01},
        {4.2930874E-03,1.3365186E-01,4.2695894E-02,1.0775649E-01},
        {2.5827047E-04,2.2630659E-02,4.0760575E-03,2.5171914E-03},
        {4.9031965E-06,1.6313638E-05,1.1766115E-04,8.9630388E-10},
        {1.4079206E-08,0.0          ,5.0989546E-07,0.0}
    });
    
    if (NU < 1 || NU > 4) {
        NU = 4;
    }
    S = 0;
    if (GALPHA > 0) {
        if (GAMMA > 0) {
            if (GBETA > 0) {
                if (DF == 0) {
                    for (long j=0; j<10; j++) {
                        XJ = XX[j][MU];
                        WJ = WW[j][MU];
                        for (long k=0; k<10; k++) {
                            XK = XX[k][NU];
                            WK = WW[k][NU];
                            if (ID == 1) {
                                S += WJ*WK*((XJ*XJ)/(GALPHA*XJ+GBETA*XK+GAMMA));
                            } else if (ID == 2) {
                                S += WJ*WK*(XJ/(GALPHA*XJ+GBETA*XK+GAMMA));
                            } else if (ID == 3) {
                                S += WJ*WK*((XJ*XK)/(GALPHA*XJ+GBETA*XK+GAMMA));
                            }
                        }
                    }
                } else if (DF > 0) {
                    for (long j=0; j<10; j++) {
                        XJ = XX[j][MU];
                        WJ = WW[j][MU];
                        for (long k=0; k<10; k++) {
                            XK = XX[k][NU];
                            WK = WW[k][NU];
                            for (long l=0; l<10; l++) {
                                XL = XX[l][LAMBDA];
                                WL = WW[l][LAMBDA];
                                if (ID == 1) {
                                    S += WJ*WK*WL*
                                    ((XJ*XJ)/(GALPHA*XJ+GBETA*XK+GAMMA+DF*XL));
                                } else if (ID == 2) {
                                    S += WJ*WK*WL*
                                    (XJ/(GALPHA*XJ+GBETA*XK+GAMMA+DF*XL));
                                } else if (ID == 3) {
                                    S += WJ*WK*WL*
                                    ((XJ*XK)/(GALPHA*XJ+GBETA*XK+GAMMA+DF*XL));
                                }
                            }
                        }
                    }
                }
            } else if (GBETA == 0) {
                if (DF == 0) {
                    for (long j=0; j<10; j++) {
                        XJ = XX[j][MU];
                        WJ = WW[j][MU];
                        if (ID == 1) {
                            S += WJ*((XJ*XJ)/(GALPHA*XJ+GAMMA));
                        } else if (ID == 2) {
                            S += WJ*(XJ/(GALPHA*XJ+GAMMA));
                        }
                    }
                } else if (DF > 0) {
                    for (long j=0; j<10; j++) {
                        XJ = XX[j][MU];
                        WJ = WW[j][MU];
                        for (long k=0; k<10; k++) {
                            XK = XX[k][LAMBDA];
                            WK = WW[k][LAMBDA];
                            if (ID == 1) {
                                S += WJ*WK*((XJ*XJ)/(GALPHA*XJ+GAMMA+DF*XK));
                            } else if (ID == 2) {
                                S += WJ*WK*(XJ/(GALPHA*XJ+GAMMA+DF*XK));
                            }
                        }
                    }
                }
            }
        }
    }
}

static void ENDFFINDE
(double E, const std::vector<double>& ES,
 std::vector<double>& EG, long& NUME, long& IDG) {
    EG.resize(2,0);
    
    // Find relative location of E on the grid
    IDG = 0;
    for (long N=0; N<ES.size(); N++) {
        if (E == ES[N]) {
            // On fall thru E is greater than last point on grid.
            // EG is returned containing only last grid value
            IDG   = N;
            EG[0] = E;
            NUME  = 1;
            return;
        } else if (E < ES[N]) {
            // Bracketing values found
            
            if (N == 0) {
                // Energy is below lowest grid point.
                // EG is returned with only the lowest grid point
                IDG   = 0;
                EG[0] = E;
                NUME  = 1;
                return;
            } else {
                IDG   = N-1;
                EG[0] = ES[N-1];
                EG[1] = ES[N];
                NUME  = 2;
                return;
            }
        }
    }
}

static void ENDFTERP1
(double XA, double YA, double XB, double YB, double XI, double& YI, long I) {
    if (I == 1) {
        YI = YA;
    } else if (I == 2) {
        YI = YA + (XI-XA)*(YB-YA)/(XB-XA);
    } else if (I == 3) {
        if (XA <= 0 || XB <= 0) {
            YI = YA + (XI-XA)*(YB-YA)/(XB-XA);
        } else {
            YI = YA + log(XI/XA)*(YB-YA)/log(XB/XA);
        }
    } else if (I == 4) {
        if (YA <= 0 || YB <=0) {
            YI = YA + (XI-XA)*(YB-YA)/(XB-XA);
        } else {
            YI = YA*exp((XI-XA)*log(YB/YA)/(XB-XA));
        }
    } else if (I == 5) {
        if (YA <= 0 || YB <= 0) {
            if (XA <= 0 || XB <= 0) {
                YI = YA + (XI-XA)*(YB-YA)/(XB-XA);
            } else {
                YI = YA + log(XI/XA)*(YB-YA)/log(XB/XA);
            }
        } else if (XA <= 0 || XB <= 0) {
            YI = YA*exp((XI-XA)*log(YB/YA)/(XB-XA));
        } else {
            if (XI <= 0) {
                YI = YA + log(XI/XA)*(YB-YA)/log(XB/XA);
            } else {
                YI = YA*exp(log(XI/XA)*log(YB/YA)/log(XB/XA));
            }
        }
    }
}

// Implementations of ENDFNeutronData public query functions
std::pair<double, double> ENDFNeutronData::getResolvedResonanceRange() const {
    double EL = 0., EH = 0.;
    
    // If no resonances, return zero lower and upper limits
    for (auto& resonance : resonances) {
        bool hasRR = false;
        for (auto& range : resonance.ranges) {
            if(!hasRR && range.LRU == 1) {
                hasRR = true;
                if (EL == 0.) {
                    EL = range.EL;
                } else {
                    EL = std::min(EL, range.EL);
                }
                if (EH == 0.) {
                    EH = range.EH;
                } else {
                    EH = std::max(EH, range.EH);
                }
            } else if (hasRR && range.LRU == 1) {
                std::cerr
                << "[NDLS]: warning already have resolved resonance range!"
                << std::endl;
            }
        }
    }
    
    return std::make_pair(EL, EH);
}

ENDFNeutronData::Resonance::Xsec
ENDFNeutronData::getResolvedResonanceXsec(double energy) const {
    
    if (energy < 0.) {
        throw std::logic_error("negative energy!");
    }
    
    // Define alias for simplicity
    using Xsec = ENDFNeutronData::Resonance::Xsec;
    
    // The cross section will be summed
    Xsec xsec;
    for (auto& resonance : resonances) {
        bool hasRR = false;
        for (auto& range : resonance.ranges) {
            if(!hasRR && range.LRU == 1) {
                hasRR = true;
                auto addXsec = range.generate(energy, resonance.LFW);
                double ABN = resonance.ABN;
                xsec.capture   += ABN * addXsec.capture;
                xsec.elastic   += ABN * addXsec.elastic;
                xsec.fission   += ABN * addXsec.fission;
                xsec.potential += ABN * addXsec.potential;
                xsec.total     += ABN * addXsec.total;
            } else if (hasRR && range.LRU == 1) {
                std::cerr
                << "[NDLS]: warning already have resolved resonance range!"
                << std::endl;
            }
        }
    }
    
    return xsec;
}


// Other implementations in details
ENDFTab1& ENDFTab1::eliminateDuplicatedZeros() {
    long idxFirstNonZero=0;
    for (auto& v : data) {
        if (v.y == 0.) {
            idxFirstNonZero ++;
        } else {
            break;
        }
    }
    if (idxFirstNonZero == 0) {
        return *this;
    }
    for (long i=0; i<idxFirstNonZero-1; i++) {
        data.erase(data.begin());
    }
    for (auto& p : interp) {
        long& n = p.NBT;
        if (n >= (idxFirstNonZero-1)) {
            n -= (idxFirstNonZero-1);
        } else {
            n = 0;
        }
    }
    
    return *this;
}

ENDFNeutronData::Yield::~Yield() {
    if (total != nullptr) {
        delete total;
        total = nullptr;
    }
    if (prompt != nullptr) {
        delete prompt;
        prompt = nullptr;
    }
    if (delayed != nullptr) {
        delete delayed;
        delayed = nullptr;
    }
}

ENDFNeutronData::Resonance::Xsec
ENDFNeutronData::Resonance::Range::
generateLRU1LRF1(double E) const {
    // Implementation of Resonance reconstruction of SLBW representation
    ENDFNeutronData::Resonance::Xsec xsec;
    
    // SLBW, sample implementation
    double
    l, sigma_mr, phi_l, gamma_r_max,
    gamma_nr_max, gamma_fr, gamma_gr,
    g_J, I, J, k, kr, A, a, ER, ER_p,
    rho=0, rho_hat=0,
    P_l, P_l_max, gamma_r, gamma_nr, rho_max,
    x, psi, chi, rho_c=0, rho_c_max, gamma_xr,
    P_l_c, P_l_c_max;
    
    I = SPI;
    for (auto& momentum : moments) {
        A = momentum.AWRI;
        l = momentum.L;
        a = 0.123*pow(A, 1.0/3.0)+0.08;
        k = (2.196771E-3)*A/(A+1)*sqrt(fabs(E));
        // E in eV, k in (1E-12 cm)^(-1)
        if (NRO == 0) {
            if (NAPS == 0) {
                rho     = k * a;
                rho_hat = k * AP;
            } else if (NAPS == 1) {
                rho     = k * AP;
                rho_hat = k * AP;
            }
        } else if (NRO == 1) {
            if (NAPS == 0) {
                rho     = k * a;
                rho_hat = k * APE.evaluate(E);
            } else if (NAPS == 1) {
                rho     = k * APE.evaluate(E);
                rho_hat = k * APE.evaluate(E);
            } else if (NAPS == 2) {
                rho     = k * AP;
                rho_hat = k * APE.evaluate(E);
            }
        }
        phi_l = ENDFSLBWPhaseShift(l, rho_hat);
        xsec.potential += 4*M_PI/(k*k)*(2*l+1)*
        (sin(phi_l)*sin(phi_l));
        if (momentum.LRX != 0) {
            rho_c     = (2.196771E-3)*A/(A+1)*
            sqrt(fabs(E+A/(A+1)*momentum.QX));
        }
        for (auto& region : momentum.BWTables) {
            ER           = region.ER;
            kr           = (2.196771E-3)*A/(A+1)*
            sqrt(fabs(ER));
            rho_max      = rho/k*kr;
            J            = region.AJ;
            g_J          = (2*J+1)/(2*(2*I+1));
            gamma_r_max  = region.GT;
            gamma_nr_max = region.GN;
            gamma_gr     = region.GG;
            gamma_fr     = region.GF;
            P_l_max      =
            ENDFSLBWPenetrationFactor(l, rho_max);
            P_l          =
            ENDFSLBWPenetrationFactor(l, rho);
            gamma_nr     = gamma_nr_max*P_l/P_l_max;
            ER_p         = ER +
            (ENDFSLBWShiftFactor(l, rho_max)-
             ENDFSLBWShiftFactor(l, rho))
            /(2*P_l_max)*gamma_nr_max;
            gamma_xr     = gamma_gr + gamma_fr;
            if (momentum.LRX != 0) {
                rho_c_max= (2.196771E-3)*A/(A+1)*
                sqrt(fabs(ER+A/(A+1)*momentum.QX));
                P_l_c    =
                ENDFSLBWPenetrationFactor(l, rho_c);
                P_l_c_max=
                ENDFSLBWPenetrationFactor(l, rho_c_max);
                if (E < -A/(A+1)*momentum.QX) {
                    gamma_r  = gamma_nr + gamma_xr;
                } else {
                    gamma_r  =
                    gamma_nr + gamma_xr + P_l_c/P_l_c_max
                    *(gamma_r_max-gamma_xr-gamma_nr_max);
                }
            } else {
                gamma_r  = gamma_nr + gamma_xr;
            }
            sigma_mr     = 4*M_PI/(k*k)*g_J*gamma_nr/gamma_r;
            x            = 2*(E - ER_p)/gamma_r;
            psi          = ENDFSLBWPsi0(x);
            chi          = ENDFSLBWChi0(x);
            xsec.fission += sigma_mr/gamma_r*gamma_fr*psi;
            xsec.capture += sigma_mr/gamma_r*gamma_gr*psi;
            xsec.elastic += sigma_mr*
            ((cos(2*phi_l)-(1-gamma_nr/gamma_r))*psi
             + sin(2*phi_l)*chi);
        }
        // Add potential scattering
        xsec.elastic += xsec.potential;
    }
    // Sum to get total
    xsec.total = xsec.elastic + xsec.fission + xsec.capture;
    
    return xsec;
}

ENDFNeutronData::Resonance::Xsec
ENDFNeutronData::Resonance::Range::
generateLRU1LRF2(double E) const {
    // Implementation of Resonance reconstruction of MLBW representation
    ENDFNeutronData::Resonance::Xsec xsec;
    
    // MLBW, sample implementation
    double
    l, sigma_mr, phi_l, gamma_r_max,
    gamma_nr_max, gamma_fr, gamma_gr,
    g_J, I, J, k, kr, A, a, ER, ER_p,
    rho=0, rho_hat=0,
    P_l, P_l_max, gamma_r, gamma_nr,
    rho_max, rho_hat_max,
    x, psi, chi, rho_c=0,
    rho_c_max, gamma_xr, P_l_c, P_l_c_max;
    // Reference to the subroutine CSSLBW
    double SSUM, AJMIN, AJMAX, AJ, DIFF;
    long NUMJ;
    std::vector<double> GJ;
    std::vector<double> SIGJ1, SIGJ2;
    
    I = SPI;
    for (auto& momentum : moments) {
        A = momentum.AWRI;
        l = momentum.L;
        a = 0.123*pow(A, 1.0/3.0)+0.08;
        k = (2.196771E-3)*A/(A+1)*sqrt(fabs(E));
        // E in eV, k in (1E-12 cm)^(-1)
        if (NRO == 0) {
            if (NAPS == 0) {
                rho     = k * a;
                rho_hat = k * AP;
            } else if (NAPS == 1) {
                rho     = k * AP;
                rho_hat = k * AP;
            }
        } else if (NRO == 1) {
            if (NAPS == 0) {
                rho     = k * a;
                rho_hat = k * APE.evaluate(E);
            } else if (NAPS == 1) {
                rho     = k * APE.evaluate(E);
                rho_hat = k * APE.evaluate(E);
            } else if (NAPS == 2) {
                rho     = k * AP;
                rho_hat = k * APE.evaluate(E);
            }
        }
        phi_l = ENDFSLBWPhaseShift(l, rho_hat);
        xsec.potential += 4*M_PI/(k*k)*(2*l+1)*
        (sin(phi_l)*sin(phi_l));
        if (momentum.LRX != 0) {
            rho_c     = (2.196771E-3)*A/(A+1)*
            sqrt(fabs(E+A/(A+1)*momentum.QX));
        }
        
        // Calculate number of spins exists and ther gJ sum
        AJMIN = fabs(fabs(I-l)-0.5);
        AJMAX = I+l+0.5;
        NUMJ  = lround(AJMAX-AJMIN) + 1;
        AJ    = AJMIN;
        GJ.resize(NUMJ,0);
        SSUM  = 0;
        for (long j=0; j<NUMJ; j++) {
            GJ[j] = (2*AJ+1)/(2*(2*I+1));
            AJ++;
            SSUM += GJ[j];
        }
        DIFF = 2*l + 1 - SSUM;
        
        // Zero elastic components
        SIGJ1.resize(NUMJ, 0);
        SIGJ2.resize(NUMJ, 0);
        
        for (auto& region : momentum.BWTables) {
            ER           = region.ER;
            kr           = (2.196771E-3)*A/(A+1)*sqrt(fabs(ER));
            rho_max      = rho/k*kr;
            rho_hat_max  = rho_hat/k*kr;
            J            = region.AJ;
            g_J          = (2*J+1)/(2*(2*I+1));
            gamma_r_max  = region.GT;
            gamma_nr_max = region.GN;
            gamma_gr     = region.GG;
            gamma_fr     = region.GF;
            P_l_max      = ENDFSLBWPenetrationFactor(l, rho_max);
            P_l          = ENDFSLBWPenetrationFactor(l, rho);
            gamma_nr     = gamma_nr_max*P_l/P_l_max;
            ER_p         = ER +
            (ENDFSLBWShiftFactor(l, rho_max)-
             ENDFSLBWShiftFactor(l, rho))
            /(2*P_l_max)*gamma_nr_max;
            gamma_xr     = gamma_gr + gamma_fr;
            if (momentum.LRX != 0) {
                rho_c_max= (2.196771E-3)*A/(A+1)*
                sqrt(fabs(ER+A/(A+1)*momentum.QX));
                P_l_c    =
                ENDFSLBWPenetrationFactor(l, rho_c);
                P_l_c_max=
                ENDFSLBWPenetrationFactor(l, rho_c_max);
                if (E < -A/(A+1)*momentum.QX) {
                    gamma_r  = gamma_nr + gamma_xr;
                } else {
                    gamma_r  =
                    gamma_nr + gamma_xr + P_l_c/P_l_c_max
                    *(gamma_r_max-gamma_xr-gamma_nr_max);
                }
            } else {
                gamma_r  = gamma_nr + gamma_xr;
            }
            sigma_mr     = 4*M_PI/(k*k)*g_J*gamma_nr/gamma_r;
            x            = 2*(E - ER_p)/gamma_r;
            psi          = ENDFSLBWPsi0(x);
            chi          = ENDFSLBWChi0(x);
            xsec.fission += sigma_mr/gamma_r*gamma_fr*psi;
            xsec.capture += sigma_mr/gamma_r*gamma_gr*psi;
            
            // Elastic components
            SIGJ1[lround(J-AJMIN)] += 2*gamma_nr/gamma_r*psi;
            SIGJ2[lround(J-AJMIN)] += 2*gamma_nr/gamma_r*chi;
        }
        
        // Add potential cross section
        for (long j=0; j<NUMJ; j++) {
            xsec.elastic += GJ[j]*
            (ENDFSqr(1.0-cos(2*phi_l)-SIGJ1[j])
             + ENDFSqr(sin(2*phi_l)+SIGJ2[j])) * M_PI/(k*k);
        }
        xsec.elastic +=
        2*DIFF*(1.0-cos(2*phi_l))*M_PI/(k*k);
    }
    // Sum to get total
    xsec.total = xsec.elastic + xsec.fission + xsec.capture;
    
    return xsec;
}

ENDFNeutronData::Resonance::Xsec
ENDFNeutronData::Resonance::Range::
generateLRU1LRF3(double E) const {
    // Implementation of Resonance reconstruction of RM representation
    ENDFNeutronData::Resonance::Xsec xsec;
    
    // Reich-Moore
    double
    A, I, k, rho=0, rho_hat=0, l,
    a, phi_l, gJ, kr, rho_max;
    // Reference to the subroutine CSRMAT
    double
    SE, PE, ER, GN, GG, GF,
    PER, GC, DIFF, DEN,
    A1, A2, A3, DE2, GG4,
    SIGNNI, SIGNGI, SIGNFI, SIGNTI,
    AJMIN, AJMAX, AJC, AJ, AJPM;
    long
    NUMJ, JJL, KPSTV, KNGTV,
    ISKIP, IFIS=-1, KKKKKK, JJ;
    double
    P1, P2, U11R, U11I, TERMT, TERMN,
    TERMF, TERMG, T1, T2, T3, T4;
    std::vector< std::vector<double> > R, S, RI, SI;
    R.resize(3,{0,0,0});
    S.resize(3,{0,0,0});
    RI.resize(3,{0,0,0});
    SI.resize(3,{0,0,0});
    
    I = SPI;
    
    // Initialize partial cross sections
    SIGNNI = 0;
    SIGNGI = 0;
    SIGNFI = 0;
    SIGNTI = 0;
    
    for (auto& momentum : moments) {
        A = momentum.AWRI;
        l = momentum.L;
        a = 0.123*pow(A, 1.0/3.0)+0.08;
        k = (2.196771E-3)*A/(A+1)*sqrt(fabs(E));
        if (NRO == 0) {
            if (NAPS == 0) {
                rho     = k * a;
            } else if (NAPS == 1) {
                rho     = k *
                ((momentum.APL==0)?AP:momentum.APL);
            }
            rho_hat = k *
            ((momentum.APL==0)?AP:momentum.APL);
        } else if (NRO == 1) {
            if (NAPS == 0) {
                rho     = k * a;
            } else if (NAPS == 1) {
                rho     = k * APE.evaluate(E);
            } else if (NAPS == 2) {
                rho     = k * AP;
            }
            rho_hat = k * APE.evaluate(E);
        }
        SE    = ENDFSLBWShiftFactor(l, rho);
        PE    = ENDFSLBWPenetrationFactor(l, rho);
        phi_l = ENDFSLBWPhaseShift(l, rho_hat);
        P1    = cos(2*phi_l);
        P2    = sin(2*phi_l);
        
        // Loop ober possible J values
        AJMIN = fabs(fabs(I-l)-0.5);
        AJMAX = I+l+0.5;
        NUMJ  = lround(AJMAX-AJMIN) + 1;
        AJC   = AJMIN-1;
        
        if (l != 0 && (l > I-0.5 && l <= I)) {
            JJL = 0;
        } else {
            JJL = 1;
        }
        for (long j=0; j<NUMJ; j++) {
            JJ = j+1;
            AJC++;
            gJ = (2*AJC+1)/(2*(2*I+1));
            
            // Loop over possible channel spins
            // KCHANL = 1,2
            // Channel 1, skip negative, consider positive
            // Channel 2, skip positive, consider negative
            for (long KCHANL=1; KCHANL<3; KCHANL++) {
                KPSTV = 0; // Positive
                KNGTV = 0; // Negative
                
                // Initialize matrix
                for (long ii=0; ii<3; ii++) {
                    for (long jj=0; jj<3; jj++) {
                        S[ii][jj] = 0;
                        R[ii][jj] = 0;
                    }
                }
                for (long ii=0; ii<3; ii++) {
                    R[ii][ii] = 1;
                }
                
                // Loop over all resonances
                for (auto& resonance : momentum.RMTables) {
                    AJPM = resonance.AJ; // Signed quantivity
                    AJ   = fabs(AJPM);
                    
                    // Select only resonances with current J value
                    if (fabs(AJ-AJC) <= 0.01) {
                        if (AJPM < 0) {
                            KNGTV ++;
                        } else if (AJPM > 0) {
                            KPSTV ++;
                        }
                        if (KCHANL == 1 && AJPM < 0) {
                            ISKIP = 1;
                        } else if (KCHANL == 2 && AJPM >0) {
                            ISKIP = 1;
                        } else {
                            ISKIP = 0;
                        }
                        
                        // Process resonance
                        
                        if (ISKIP == 0) {
                            ER      = resonance.ER;
                            kr      =
                            (2.196771E-3)*A/(A+1)*
                            sqrt(fabs(ER));
                            rho_max = rho/k*kr;
                            GN      = resonance.GN;
                            GG      = resonance.GG;
                            GF      = resonance.GFA;
                            PER     =
                            ENDFSLBWPenetrationFactor
                            (l, rho_max);
                            GC      = resonance.GFB;
                            A1      = sqrt(GN*PE/PER);
                            if (GF != 0) {
                                A2  = sqrt(fabs(GF));
                                if (GF < 0) A2=-A2;
                            } else {
                                A2  = 0;
                            }
                            if (GC != 0) {
                                A3  = sqrt(fabs(GC));
                                if (GC < 0) A3=-A3;
                            } else {
                                A3  = 0;
                            }
                            DIFF = ER - E;
                            DEN  = DIFF*DIFF + 0.25*GG*GG;
                            DE2  = 0.5*DIFF/DEN;
                            GG4  = 0.25*GG/DEN;
                            if (GF == 0 && GC == 0) {
                                IFIS = 0;
                            } else {
                                IFIS = 1;
                            }
                            
                            // Calculate upper triangular matrix terms
                            R[0][0] += GG4*A1*A1;
                            S[0][0] -= DE2*A1*A1;
                            // Check whether contains fission channels
                            if (IFIS > 0) {
                                R[0][1] += GG4*A1*A2;
                                S[0][1] -= DE2*A1*A2;
                                R[0][2] += GG4*A1*A3;
                                S[0][2] -= DE2*A1*A3;
                                R[1][1] += GG4*A2*A2;
                                S[1][1] -= DE2*A2*A2;
                                R[2][2] += GG4*A3*A3;
                                S[2][2] -= DE2*A3*A3;
                                R[1][2] += GG4*A2*A3;
                                S[1][2] -= DE2*A2*A3;
                            }
                        }
                        
                    }
                }
                
                // Number of potential scatterings
                KKKKKK = 0;
                if (KCHANL == 1) {
                    if (KPSTV > 0) {
                        if (KNGTV == 0) {
                            if (JJ > JJL && JJ < NUMJ) {
                                KKKKKK = 2;
                            } else {
                                KKKKKK = 1;
                            }
                        } else if (KNGTV > 0) {
                            KKKKKK = 0;
                        }
                    } else if (KPSTV == 0) {
                        if (KNGTV == 0) {
                            if (JJ > JJL && JJ < NUMJ) {
                                KKKKKK = 2;
                            } else {
                                KKKKKK = 1;
                            }
                        } else if (KNGTV > 0) {
                            KKKKKK = 0;
                        }
                    }
                }else if (KCHANL == 2) {
                    if (KPSTV > 0) {
                        if (KNGTV > 0) {
                            KKKKKK = 1;
                        }
                    } else if (KPSTV == 0) {
                        if (KNGTV > 0) {
                            if (JJ > JJL && JJ < NUMJ) {
                                KKKKKK = 2;
                            } else {
                                KKKKKK = 1;
                            }
                        }
                    }
                }
                
                // Prepare to calculate the cross section
                if (KKKKKK != 0) {
                    if (IFIS == 0) {
                        // Special case of no fission
                        DEN      = R[0][0]*R[0][0] + S[0][0]*S[0][0];
                        RI[0][0] = R[0][0]/DEN;
                        SI[0][0] = -S[0][0]/DEN;
                    } else {
                        // Make symmetric marix
                        R[1][0] = R[0][1];
                        S[1][0] = S[0][1];
                        R[2][0] = R[0][2];
                        S[2][0] = S[0][2];
                        R[2][1] = R[1][2];
                        S[2][1] = S[1][2];
                        // Invert the complex matrix
                        ENDFFROBNS(R, S, RI, SI, 3);
                    }
                    
                    // Calculate the cross sections
                    U11R  = P1*(2*RI[0][0]-1) + 2*P2*SI[0][0];
                    U11I  = P2*(1-2*RI[0][0]) + 2*P1*SI[0][0];
                    TERMT = 2*gJ*(1-U11R);
                    TERMN = gJ*(ENDFSqr(1-U11R) + ENDFSqr(U11I));
                    // Add potential scattering
                    if (KKKKKK == 2) {
                        TERMN += 2*gJ*(1-P1);
                        TERMT += 2*gJ*(1-P1);
                    }
                    if (IFIS == 0) {
                        TERMF = 0;
                    } else {
                        T1    = RI[0][1];
                        T2    = SI[0][1];
                        T3    = RI[0][2];
                        T4    = SI[0][2];
                        TERMF = 4*gJ*(T1*T1+T2*T2+T3*T3+T4*T4);
                    }
                    TERMG  = TERMT-TERMF-TERMN;
                    SIGNNI += TERMN*M_PI/(k*k);
                    SIGNGI += TERMG*M_PI/(k*k);
                    SIGNFI += TERMF*M_PI/(k*k);
                    SIGNTI += TERMT*M_PI/(k*k);
                }
            }
        }
    }
    
    // Calculate cross section and store for return
    xsec.total   = SIGNTI;
    xsec.elastic = SIGNNI;
    xsec.fission = SIGNFI;
    xsec.capture = SIGNGI;
    
    return xsec;
}

ENDFNeutronData::Resonance::Xsec
ENDFNeutronData::Resonance::Range::
generateLRU1LRF4(double E) const {
    // Implementation of Resonance reconstruction of AA representation
    ENDFNeutronData::Resonance::Xsec xsec;
    
    // Adler-Adler
    double
    k, phi_0, a, rho, rho_hat,
    A, I, J, l, x, psi, chi;
    double AT1, AT2, AT3, AT4, BT1, BT2;
    double AC1, AC2, AC3, AC4, BC1, BC2;
    double AF1, AF2, AF3, AF4, BF1, BF2;
    double GT_r, HT_r, GC_r, HC_r, GF_r, HF_r;
    double muT_r, nuT_r, muC_r, nuC_r, muF_r, nuF_r;
    double BAKT, BAKF, BAKC;
    
    I = SPI;
    A = AWRI;
    a = 0.123*pow(A, 1.0/3.0)+0.08;
    k = (2.196771E-3)*A/(A+1)*sqrt(fabs(E));
    // E in eV, k in (1E-12 cm)^(-1)
    if (NRO == 0) {
        if (NAPS == 0) {
            rho     = k * a;
            rho_hat = k * AP;
        } else if (NAPS == 1) {
            rho     = k * AP;
            rho_hat = k * AP;
        }
    } else if (NRO == 1) {
        if (NAPS == 0) {
            rho     = k * a;
            rho_hat = k * APE.evaluate(E);
        } else if (NAPS == 1) {
            rho     = k * APE.evaluate(E);
            rho_hat = k * APE.evaluate(E);
        } else if (NAPS == 2) {
            rho     = k * AP;
            rho_hat = k * APE.evaluate(E);
        }
    }
    phi_0 = ENDFSLBWPhaseShift(0, rho_hat);
    
    AT1 = aaParams.AT1;
    AT2 = aaParams.AT2;
    AT3 = aaParams.AT3;
    AT4 = aaParams.AT4;
    BT1 = aaParams.BT1;
    BT2 = aaParams.BT2;
    
    AC1 = aaParams.AC1;
    AC2 = aaParams.AC2;
    AC3 = aaParams.AC3;
    AC4 = aaParams.AC4;
    BC1 = aaParams.BC1;
    BC2 = aaParams.BC2;
    
    AF1 = aaParams.AF1;
    AF2 = aaParams.AF2;
    AF3 = aaParams.AF3;
    AF4 = aaParams.AF4;
    BF1 = aaParams.BF1;
    BF2 = aaParams.BF2;
    
    // Calculate background
    BAKT = 0;
    BAKF = 0;
    BAKC = 0;
    if (LI <= 4) {
        std::cout
        <<" ENDF: no enough info for Adler-Adler Background!"
        <<std::endl;
        return xsec;
    }
    if (LI == 5 || LI == 7) {
        BAKT =
        AT1 + AT2/E + AT3/(E*E) +
        AT4/(E*E*E) + BT1*E + BT2*E*E;
    }
    if (LI != 5) {
        BAKF =
        AF1 + AF2/E + AF3/(E*E) +
        AF4/(E*E*E) + BF1*E + BF2*E*E;
    }
    BAKC =
    AC1 + AC2/E + AC3/(E*E) +
    AC4/(E*E*E) + BC1*E + BC2*E*E;
    
    for (auto& momentum : moments) {
        l = momentum.L;
        if (l != 0) continue; // Consider only L=0 case
        
        for (auto& spin : momentum.AATables) {
            J = spin.AJ;
            
            for (auto& resonance : spin.coefficients) {
                muT_r = resonance.DET;
                muF_r = resonance.DEF;
                muC_r = resonance.DEC;
                nuT_r = resonance.DWT;
                nuF_r = resonance.DWF;
                nuC_r = resonance.DWC;
                GT_r  = resonance.GRT;
                GF_r  = resonance.GRF;
                GC_r  = resonance.GRC;
                HT_r  = resonance.GIT;
                HF_r  = resonance.GIF;
                HC_r  = resonance.GIC;
                // Total
                x     = (muT_r - E)/nuT_r;
                psi   = ENDFSLBWPsi0(x);
                chi   = ENDFSLBWChi0(x);
                xsec.total += 1/nuT_r*
                ((GT_r*cos(2*phi_0)+HT_r*sin(2*phi_0))*psi
                 +(HT_r*cos(2*phi_0)-GT_r*sin(2*phi_0))*chi);
                // Fission
                x     = (muF_r - E)/nuF_r;
                psi   = ENDFSLBWPsi0(x);
                chi   = ENDFSLBWChi0(x);
                xsec.fission += 1/nuF_r*(GF_r*psi+HT_r*chi);
                // Capture
                x     = (muC_r - E)/nuC_r;
                psi   = ENDFSLBWPsi0(x);
                chi   = ENDFSLBWChi0(x);
                xsec.capture += 1/nuC_r*(GC_r*psi+HC_r*chi);
            }
        }
    }
    
    // Add background and factors
    xsec.total   =
    ((xsec.total + BAKT)*
     sqrt(fabs(E))+4*ENDFSqr(sin(phi_0)))*M_PI/(k*k);
    xsec.fission =
    (xsec.fission + BAKF)*
    sqrt(fabs(E))*M_PI/(k*k);
    xsec.capture =
    (xsec.capture + BAKC)*
    sqrt(fabs(E))*M_PI/(k*k);
    if (LI != 6) {
        xsec.elastic =
        xsec.total - (xsec.fission + xsec.capture);
    } else {
        xsec.total   =
        xsec.fission + xsec.capture;
    }
    
    return ENDFNeutronData::Resonance::Xsec();
}

ENDFNeutronData::Resonance::Xsec
ENDFNeutronData::Resonance::Range::
generateLRU2LRF1(double E, long LFW) const {
    // Implementation of unresolved resonance reconstruction
    // of SLBW representation
    ENDFNeutronData::Resonance::Xsec xsec;
    
    // Sample implementations
    // Energy independent parameters
    double a;
    long NUME, LL, MUF, MU, NU, LAMBDA, IDG=-1;
    double
    RAT, ENU, ER2, CONST, GFX, GXX, DX, AJ, GJ,
    AMUN, GNOX, GGX, GNX, A=0, AA=0, K,
    GC, GS, GFF, VL, PS, RHO, RHOC, SPOT,
    GAMMA, GALPHA, GBETA, DIFF, DEN,
    TEMP, TERG, TERS, TERF;
    std::vector<double> EG(2,0);
    std::vector<std::vector<double>> SIG({
        {0,0,0},
        {0,0,0}
    });
    
    // Find energies at which UR
    // cross sections must be calculated
    NUME  = 1;
    EG[0] = E;
    if (LFW != 0) {
        ENDFFINDE(E, URRBES, EG, NUME, IDG);
    }
    
    // Calculate at all energies
    for (long N=0; N<NUME; N++) {
        ENU = EG[N];
        ER2 = sqrt(ENU);
        
        // Loop over all L states
        for (auto& momentum : moments) {
            LL    = momentum.L;
            RAT   = momentum.AWRI/(momentum.AWRI+1);
            K     = 2.196771E-3*RAT*ER2;
            a     = 0.123*pow(momentum.AWRI, 1.0/3.0)+0.08;
            CONST = (2*M_PI*M_PI)/ENDFSqr(2.196771E-3*RAT);
            // Retrieve nuclide information
            if (NRO == 0) {
                if (NAPS == 0) {
                    AA = a;
                    A  = AP;
                } else if (NAPS == 1) {
                    AA = AP;
                    A  = AP;
                }
            } else if (NRO == 1) {
                if (NAPS == 0) {
                    AA = a;
                    A  = APE.evaluate(E);
                } else if (NAPS == 1) {
                    AA = APE.evaluate(E);
                    A  = APE.evaluate(E);
                } else if (NAPS == 2) {
                    AA =  AP;
                    A  = APE.evaluate(E);
                }
            }
            RHO    = K*AA;
            RHOC   = K*A;
            
            // Calculate phase shift (PS)
            PS = ENDFSLBWPhaseShift(LL, RHOC);
            
            // Calculate potential scattering
            SPOT = 4*M_PI*(2*LL+1)*ENDFSqr(sin(PS)/K);
            
            // Loop over all J States
            if (LFW == 0) {
                for (auto& table : momentum.URRTables.atable) {
                    GFX  = 0;
                    GXX  = 0;
                    MUF  = 0;
                    DX   = table.D;
                    AJ   = table.AJ;
                    AMUN = table.AMUN;
                    GNOX = table.GNO;
                    GGX  = table.GG;
                    
                    GJ     = (2*AJ+1)/(4*SPI+2);
                    MU     = AMUN;
                    NU     = MUF;
                    LAMBDA = 0;
                    
                    // Calculate penetrability (VL)
                    VL = ENDFSLBWPenetrationFactor(LL, RHO)
                    /RHO*AMUN;
                    VL *= ER2;
                    
                    GNX    = GNOX*VL;
                    GAMMA  = GGX;
                    GALPHA = GNX;
                    GBETA  = GFX;
                    DIFF   = GXX;
                    DEN    = ENU*DX;
                    TEMP   = CONST*GJ*GNX/DEN;
                    TERG   = TEMP*GAMMA;
                    TERS   = TEMP*GALPHA;
                    TERF   = TEMP*GBETA;
                    
                    // Calculate fluctuation integrals
                    ENDFGNRL
                    (GALPHA, GBETA, GAMMA, MU, NU,
                     LAMBDA, GS,  DIFF, 1);
                    ENDFGNRL
                    (GALPHA, GBETA, GAMMA, MU, NU,
                     LAMBDA, GC,  DIFF, 2);
                    ENDFGNRL
                    (GALPHA, GBETA, GAMMA, MU, NU,
                     LAMBDA, GFF, DIFF, 3);
                    GC  *= TERG;
                    GFF *= TERF;
                    GS  = GS*TERS -
                    CONST*GJ*2*GNX*ENDFSqr(sin(PS))/(ENU*DX);
                    
                    // Cross section
                    xsec.elastic += GS;
                    xsec.fission += GFF;
                    xsec.capture += GC;
                }
                
            } else if (LFW == 1) {
                for (auto& table : momentum.URRTables.btable) {
                    GFX  = 0;
                    GXX  = 0;
                    MUF  = table.MUF;
                    DX   = table.D;
                    AJ   = table.AJ;
                    AMUN = table.AMUN;
                    GNOX = table.GNO;
                    GGX  = table.GG;
                    GFX  = table.GF[IDG+N];
                    
                    GJ     = (2*AJ+1)/(4*SPI+2);
                    MU     = AMUN;
                    NU     = MUF;
                    LAMBDA = 0;
                    
                    // Calculate penetrability (VL)
                    VL =
                    ENDFSLBWPenetrationFactor
                    (LL, RHO)/RHO*AMUN;
                    VL *= ER2;
                    
                    GNX    = GNOX*VL;
                    GAMMA  = GGX;
                    GALPHA = GNX;
                    GBETA  = GFX;
                    DIFF   = GXX;
                    DEN    = ENU*DX;
                    TEMP   = CONST*GJ*GNX/DEN;
                    TERG   = TEMP*GAMMA;
                    TERS   = TEMP*GALPHA;
                    TERF   = TEMP*GBETA;
                    
                    // Calculate fluctuation integrals
                    ENDFGNRL
                    (GALPHA, GBETA, GAMMA, MU, NU,
                     LAMBDA, GS,  DIFF, 1);
                    ENDFGNRL
                    (GALPHA, GBETA, GAMMA, MU, NU,
                     LAMBDA, GC,  DIFF, 2);
                    ENDFGNRL
                    (GALPHA, GBETA, GAMMA, MU, NU,
                     LAMBDA, GFF, DIFF, 3);
                    GC  *= TERG;
                    GFF *= TERF;
                    GS  = GS*TERS -
                    CONST*GJ*2*GNX*ENDFSqr(sin(PS))/(ENU*DX);
                    
                    // Cross section
                    xsec.elastic += GS;
                    xsec.fission += GFF;
                    xsec.capture += GC;
                    
                }
            }
            
            // Add potential scattering
            xsec.elastic += SPOT;
        }
        
        // Interpolate to require energy
        if (NUME == 1) {
            break;
        }
        SIG[N][0] = xsec.elastic;
        SIG[N][1] = xsec.fission;
        SIG[N][2] = xsec.capture;
    }
    if (NUME == 2) {
        ENDFTERP1
        (EG[0], SIG[0][0], EG[1],
         SIG[1][0], E, xsec.elastic, 2);
        ENDFTERP1
        (EG[0], SIG[0][1], EG[1],
         SIG[1][1], E, xsec.fission, 2);
        ENDFTERP1
        (EG[0], SIG[0][2], EG[1],
         SIG[1][2], E, xsec.capture, 2);
    }
    
    // Sum to get total
    xsec.total = xsec.elastic +
    xsec.fission + xsec.capture;
    
    return xsec;
}

ENDFNeutronData::Resonance::Xsec
ENDFNeutronData::Resonance::Range::
generateLRU2LRF2(double E, long LFW) const {
    // Implementation of unresolved resonance reconstruction
    // of MLBW representation
    ENDFNeutronData::Resonance::Xsec xsec;
    
    // Energy dependent parameters
    double a;
    long NUME, LL, MU, NU, LAMBDA, IDG=-1, INTT;
    double
    RAT, ENU, ER2, CONST, GFX, GXX, DX,
    AJ, GJ, AMUN, GNOX, GGX, GNX, A=0, AA=0, K,
    GC, GS, GFF, VL, PS, RHO, RHOC, SPOT, GAMMA,
    GALPHA, GBETA, DIFF, DEN,
    TEMP, TERG, TERS, TERF, AMUX, AMUF;
    std::vector<double> EG(2,0);
    std::vector<std::vector<double>> SIG({
        {0,0,0},
        {0,0,0}
    });
    std::vector<double> ES;
    // Interpolation scheme
    if (moments.empty() ||
        moments[0].URRTables.ctable.empty()) {
        return xsec;
    }
    
    auto& records = moments[0].URRTables.ctable[0].records;
    
    ES.resize(records.size());
    for (long i=0; i<records.size();) {
        ES[i] = records[i].ES;
    }
    INTT = moments[0].URRTables.ctable[0].INT;
    
    // Find energies at which UR
    // cross sections must be calculated
    NUME  = 1;
    EG[0] = E;
    ENDFFINDE(E, ES, EG, NUME, IDG);
    
    // Calculate at all energies
    for (long N=0; N<NUME; N++) {
        ENU = EG[N];
        ER2 = sqrt(ENU);
        
        // Loop over all L states
        for (auto& momentum : moments) {
            LL    = momentum.L;
            RAT   = momentum.AWRI/(momentum.AWRI+1);
            K     = 2.196771E-3*RAT*ER2;
            a     = 0.123*pow(momentum.AWRI, 1.0/3.0)+0.08;
            CONST = (2*M_PI*M_PI)/ENDFSqr(2.196771E-3*RAT);
            // Retrieve nuclide information
            if (NRO == 0) {
                if (NAPS == 0) {
                    AA = a;
                    A  = AP;
                } else if (NAPS == 1) {
                    AA = AP;
                    A  = AP;
                }
            } else if (NRO == 1) {
                if (NAPS == 0) {
                    AA = a;
                    A  = APE.evaluate(E);
                } else if (NAPS == 1) {
                    AA = APE.evaluate(E);
                    A  = APE.evaluate(E);
                } else if (NAPS == 2) {
                    AA =  AP;
                    A  = APE.evaluate(E);
                }
            }
            RHO    = K*AA;
            RHOC   = K*A;
            
            // Calculate phase shift (PS)
            PS = ENDFSLBWPhaseShift(LL, RHOC);
            
            // Calculate potential scattering
            SPOT = 4*M_PI*(2*LL+1)*ENDFSqr(sin(PS)/K);
            
            // Loop over all J States
            for (auto& table : momentum.URRTables.ctable) {
                AJ     = table.AJ;
                AMUX   = table.AMUX;
                AMUN   = table.AMUN;
                AMUF   = table.AMUF;
                GJ     = (2*AJ+1)/(4*SPI+2);
                MU     = AMUN;
                NU     = AMUF;
                LAMBDA = AMUX;
                auto& record = table.records[IDG+N];
                DX     = record.D;
                GXX    = record.GX;
                GNOX   = record.GNO;
                GGX    = record.GG;
                GFX    = record.GF;
                
                // Calculate penetrability (VL)
                VL = ENDFSLBWPenetrationFactor
                (LL, RHO)/RHO*AMUN;
                VL *= ER2;
                
                GNX    = GNOX*VL;
                GAMMA  = GGX;
                GALPHA = GNX;
                GBETA  = GFX;
                DIFF   = GXX;
                DEN    = ENU*DX;
                TEMP   = CONST*GJ*GNX/DEN;
                TERG   = TEMP*GAMMA;
                TERS   = TEMP*GALPHA;
                TERF   = TEMP*GBETA;
                
                // Calculate fluctuation integrals
                ENDFGNRL
                (GALPHA, GBETA, GAMMA, MU, NU,
                 LAMBDA, GS,  DIFF, 1);
                ENDFGNRL
                (GALPHA, GBETA, GAMMA, MU, NU,
                 LAMBDA, GC,  DIFF, 2);
                ENDFGNRL
                (GALPHA, GBETA, GAMMA, MU, NU,
                 LAMBDA, GFF, DIFF, 3);
                GC  *= TERG;
                GFF *= TERF;
                GS  = GS*TERS -
                CONST*GJ*2*GNX*ENDFSqr(sin(PS))/(ENU*DX);
                
                // Cross section
                xsec.elastic += GS;
                xsec.fission += GFF;
                xsec.capture += GC;
            }
            
            // Add potential scattering
            xsec.elastic += SPOT;
            
        }
        
        // Interpolate to require energy
        if (NUME == 1) {
            break;
        }
        SIG[N][0] = xsec.elastic;
        SIG[N][1] = xsec.fission;
        SIG[N][2] = xsec.capture;
        
    }
    if (NUME == 2) {
        ENDFTERP1
        (EG[0], SIG[0][0], EG[1], SIG[1][0], E,
         xsec.elastic, INTT);
        ENDFTERP1
        (EG[0], SIG[0][1], EG[1], SIG[1][1], E,
         xsec.fission, INTT);
        ENDFTERP1
        (EG[0], SIG[0][2], EG[1], SIG[1][2], E,
         xsec.capture, INTT);
    }
    
    // Sum to get total
    xsec.total = xsec.elastic +
    xsec.fission + xsec.capture;
    
    return ENDFNeutronData::Resonance::Xsec();
}

ENDFNeutronData::Resonance::Xsec
ENDFNeutronData::Resonance::Range::generate(double E, long LFW) const {
    if (LRU == 1) {
        if (LRF == 1) {
            return generateLRU1LRF1(E);
        } else if (LRF == 2) {
            return generateLRU1LRF2(E);
        } else if (LRF == 3) {
            return generateLRU1LRF3(E);
        } else if (LRF == 4) {
            return generateLRU1LRF4(E);
        } else {
            throw std::logic_error("unsupport LRF for LRU = 1");
        }
    } else if (LRU == 2) {
        if (LRF == 1) {
            return generateLRU2LRF1(E, LFW);
        } else if (LRF == 2) {
            return generateLRU2LRF2(E, LFW);
        } else {
            throw std::logic_error("unsupport LRF for LRU = 2");
        }
    } else {
        throw std::logic_error("unsupport LRF");
    }
}

//} // End of namespace ibhe
//} // End of namespace com
