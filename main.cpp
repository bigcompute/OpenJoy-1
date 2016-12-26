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
    
//    NDLS ndls("/Users/changyuan/Desktop/endf.db");
//    auto result = ndls.insertENDFFile
//    ("/Users/changyuan/Documents/NDLS/NDLS Old/ENDF-B-VII.1/neutrons/n-001_H_001.endf");
//    
//    ENDFLib endf("/Users/changyuan/Desktop/endf2.db");
//    auto result2 = endf.loadENDFFile
//    ("/Users/changyuan/Documents/NDLS/NDLS Old/ENDF-B-VII.1/neutrons/n-001_H_001.endf");
//    
//    std::cout
//    << "Construction result is "
//    << (result ? "yes" : "no") << std::endl;
//    
//    std::cout
//    << "Construction result2 is "
//    << (result2 ? "yes" : "no") << std::endl;
    
    // Open database
    NDLS ndls("/Users/changyuan/Desktop/endf.db");
    ADLS adls("/Users/changyuan/Desktop/ace.db");
    
//     ndls.insertENDFFile("/Users/changyuan/Desktop/neutrons/n-045_Rh_105.endf");
    
    /* Check computational neutron data info */
    
//    auto ndata = ndls.getNeutronData
//    (528, [](long NLIB, long NVER, long LREL) {
//        return NLIB == 0 && NVER == 7 && LREL == 0;
//    });
//    
//    auto ace_ndata = adls.getNeutronData("5011", "70c");
    
//    auto ndata = ndls.getNeutronData
//    (925, [](long NLIB, long NVER, long LREL) {
//        return NLIB == 0 && NVER == 7 && LREL == 0;
//    });
//    
//    auto ace_ndata = adls.getNeutronData("9019", "70c");
    
//    auto ndata = ndls.getNeutronData
//    (600, [](long NLIB, long NVER, long LREL) {
//        return NLIB == 0 && NVER == 7 && LREL == 0;
//    });
//    
//    auto ace_ndata = adls.getNeutronData("6000", "70c");
    
//    auto ndata = ndls.getNeutronData
//    (128, [](long NLIB, long NVER, long LREL) {
//        return NLIB == 0 && NVER == 7 && LREL == 0;
//    });
//    
//    auto ace_ndata = adls.getNeutronData("1002", "70c");
    
//    auto ndata = ndls.getNeutronData
//    (9228, [](long NLIB, long NVER, long LREL) {
//        return NLIB == 0 && NVER == 7 && LREL == 0;
//    });
//
//    auto ace_ndata = adls.getNeutronData("92235", "70c");
    
//    auto ndata = ndls.getNeutronData
//    (131, [](long NLIB, long NVER, long LREL) {
//        return NLIB == 0 && NVER == 7 && LREL == 0;
//    });
//    
//    auto ace_ndata = adls.getNeutronData("1003", "70c");
    
//    auto ndata = ndls.getNeutronData
//    (2725, [](long NLIB, long NVER, long LREL) {
//        return NLIB == 0 && NVER == 7 && LREL == 0;
//    });
//    
//    auto ace_ndata = adls.getNeutronData("27059", "70c");
    
//    auto ndata = ndls.getNeutronData
//    (9222, [](long NLIB, long NVER, long LREL) {
//        return NLIB == 0 && NVER == 7 && LREL == 0;
//    });
//    
//    auto ace_ndata = adls.getNeutronData("92233", "70c");
    
    
    
    
//    auto ndata = ndls.getNeutronData
//    (9228, [](long NLIB, long NVER, long LREL) {
//        return NLIB == 0 && NVER == 7 && LREL == 0;
//    });
    
    
    auto ndata = ndls.getNeutronData
    (1625, [](long NLIB, long NVER, long LREL) {
        return NLIB == 0 && NVER == 7 && LREL == 0;
    });

    
    auto ace_ndata = adls.getNeutronData("16032", "70c");
    auto ace_cndata = new CFSNeutronData(ace_ndata);
    
    auto cndata = new CFSNeutronData(ndata);
    
    long a = 1;
    
    

//    
//    // Create exchange data format
//    auto xdata = DES::getRawNeutronData(ndata);
//    if (xdata == nullptr) {
//        std::cout<<"[MAIN]: get raw ndata error!"<<std::endl;
//    }
//    auto axdata = DES::getNeutronData(ace_ndata);
//    if (axdata == nullptr) {
//        std::cout<<"[MAIN]: get ace ndata error!"<<std::endl;
//    }
//    
//    // Serialize to file
//    std::ofstream os("/Users/changyuan/Desktop/Pu239.pb");
//    if (!os.is_open()) {
//        std::cout<<"[MAIN]: open raw ndata pb file error!"<<std::endl;
//    }
//    if(!xdata->SerializeToOstream(&os)) {
//        std::cout<<"[MAIN]: serialize raw ndata error!"<<std::endl;
//    }
//    os.close();
//    
//    os.open("/Users/changyuan/Desktop/Pu239_ACE.pb");
//    if (!os.is_open()) {
//        std::cout<<"[MAIN]: open ace ndata pb file error!"<<std::endl;
//    }
//    if(!axdata->SerializeToOstream(&os)) {
//        std::cout<<"[MAIN]: serialize raw ndata error!"<<std::endl;
//    }
//    os.close();
//    
//    auto& range = ndata->resonances[0].ranges[0];
//    auto xsec = range.generate(100, ndata->resonances[0].LFW);
//    
//    
//    
//    long n = 1;
//
//    // Compare the two CN data
//    if(!CFS::compareNeutronData(cndata, ace_cndata)) {
//        std::cout<<"[MAIN]: comparison error!"<<std::endl;
//    }
    
    
//
//    if (!cndata->valid()) {
//        
//        std::cerr<<"Load CFS neutron data fails!"<<std::endl;
//        
//    } else {
//        
//        if (cndata->total != nullptr) {
//            auto& totalBgXsec = cndata->total->bgXsec;
//            auto totalBgXsecLin = XLS::linearizeENDFInterpFunc
//            (totalBgXsec, CMS::defaultTol);
//            
//            long N = totalBgXsecLin.data.size();
//            std::vector<double> xvec, yvec;
//            xvec.resize(N, 0.);
//            yvec.resize(N, 0.);
//            for (long i=0; i<N; i++) {
//                xvec[i] = totalBgXsecLin.data[i].x;
//                yvec[i] = totalBgXsecLin.data[i].y;
//            }
//            auto svg = SVGPlot2D
//            (900, 600, xvec, yvec, SVGPlot2D::LineStyle::LOGLOG);
//            
//            svg.printToFile("/Users/changyuan/Desktop/total.svg");
//        }
//        
//        if (cndata->elastic != nullptr) {
//            auto& elasticBgXsec = cndata->elastic->bgXsec;
//            auto elasticBgXsecLin = XLS::linearizeENDFInterpFunc
//            (elasticBgXsec, CMS::defaultTol);
//            
//            long N = elasticBgXsecLin.data.size();
//            std::vector<double> xvec, yvec;
//            xvec.resize(N, 0.);
//            yvec.resize(N, 0.);
//            for (long i=0; i<N; i++) {
//                xvec[i] = elasticBgXsecLin.data[i].x;
//                yvec[i] = elasticBgXsecLin.data[i].y;
//            }
//            auto svg = SVGPlot2D
//            (900, 600, xvec, yvec, SVGPlot2D::LineStyle::LOGLOG);
//            
//            svg.printToFile("/Users/changyuan/Desktop/elastic.svg");
//        }
//        
//        if (cndata->capture != nullptr) {
//            auto& captureBgXsec = cndata->capture->bgXsec;
//            auto captureBgXsecLin = XLS::linearizeENDFInterpFunc
//            (captureBgXsec, CMS::defaultTol);
//            
//            long N = captureBgXsecLin.data.size();
//            std::vector<double> xvec, yvec;
//            xvec.resize(N, 0.);
//            yvec.resize(N, 0.);
//            for (long i=0; i<N; i++) {
//                xvec[i] = captureBgXsecLin.data[i].x;
//                yvec[i] = captureBgXsecLin.data[i].y;
//            }
//            auto svg = SVGPlot2D
//            (900, 600, xvec, yvec, SVGPlot2D::LineStyle::LOGLOG);
//            
//            svg.printToFile("/Users/changyuan/Desktop/capture.svg");
//        }
//    }
    
//
//    
//    
//    if (ndata != nullptr) {
//        delete ndata;
//        ndata = nullptr;
//    }
//    if (cndata != nullptr) {
//        delete cndata;
//        cndata = nullptr;
//    }
    
    // Process resolved resonance
    // auto dps = XRS::processResolvedResonance(ndata, 0.001);
    
    // auto xsec = ndata->resonances[0].ranges[0].generate0K
    //(2.53E-2, ndata->resonances[0].LFW);
    
    
    // Create a directory
    
//    DIR           *pdir = nullptr;
//    struct dirent *pent = nullptr;
//    
//    std::string dataFilepath;
//    std::string dataFilename;
    
    //dataFilepath = "/Users/changyuan/Documents/NDLS/NDLS Old/ENDF-B-VII.0/mod/";
    // dataFilepath = "/Users/changyuan/Documents/NDLS/NDLS Old/ENDF-B-VII.1/neutrons/";
    // dataFilepath = "/Users/changyuan/Documents/NDLS/NDLS Old/ENDF-B-VII.1/thermal_scatt/";
    // dataFilepath = "path to the folder with data";
    
    
//    pdir = opendir(dataFilepath.c_str());
//    if (pdir == nullptr) {
//        std::cout<<"Open directory fails!"<<std::endl;
//        return -1;
//    }
//    while ( (pent = readdir(pdir)) ) {
//        if (pent == nullptr) {
//            std::cout<<"pent could not be initialized correctly!"<<std::endl;
//            return -1;
//        }
//        std::cout<<pent->d_name<<std::endl;
//        if (pent->d_type == DT_REG) {
//            dataFilename = pent->d_name;
//            if(!ndls.insertENDFFile(dataFilepath+dataFilename)){
//                std::cout<<"Load endf file "<<dataFilepath+dataFilename<<" fails!"<<std::endl;
//            }
//        }
//        
//    }
//    closedir(pdir);
    
    //    ndls.iterateOverMaterials
    //    ([] (const ENDFMaterialHeader& hmt, ENDFNeutronData* ndata) {
    //        if (ndata == nullptr) {
    //            return;
    //        }
    //        if (ndata->resonances.empty()) {
    //            return;
    //        }
    //        if (ndata->resonances[0].ranges.empty()) {
    //            return;
    //        }
    //        if (ndata->resonances[0].ranges[0].LRU == 1 &&
    //            ndata->resonances[0].ranges[0].LRF == 1) {
    //            std::cout << "SLBW for MAT=" << hmt.MAT << std::endl;
    //        }
    //    });
    
    /* Get all reaction numbers */
    
    
//    ndls.iterateOverMaterials
//    ([&] (const ENDFMaterialHeader& hmt, ENDFNeutronData* ndata) {
//        if (ndata == nullptr) {
//            return;
//        }
//        std::cout<<"["<<ENDF::getNameFromID(hmt.MAT)<<"] : "<<std::endl;
//        if (!ndata->resonances.empty()) {
//            auto& resonance = ndata->resonances.front();
//            for (auto& range : resonance.ranges) {
//                if (range.LRU == 1) {
//                    std::cout<<"\tResolved Resonance LRF = "<<range.LRF<<std::endl;
//                } else if (range.LRU == 2) {
//                    std::cout<<"\tUnresolved Resonance LRF = "<<range.LRF<<std::endl;
//                }
//            }
//        }
//    });
    
    
//    std::set<long> MF3Rxn, MF4Rxn, MF5Rxn, MF6Rxn, MF5Laws, MF6Laws, MF6NLaws;
//    std::set<long> MF5Law1Rxn, MF5Law5Rxn, MF5Law7Rxn, MF5Law9Rxn, MF5Law11Rxn, MF5Law12Rxn;
//    std::set<long> MF6Law1Rxn, MF6Law2Rxn, MF6Law3Rxn, MF6Law4Rxn, MF6Law5Rxn, MF6Law6Rxn, MF6Law7Rxn;
//    
//    ndls.iterateOverMaterials
//    ([&] (const ENDFMaterialHeader& hmt, ENDFNeutronData* ndata) {
//        if (ndata == nullptr) {
//            return;
//        }
//        std::cout<<"["<<ENDF::getNameFromID(hmt.MAT)<<"] : "<<std::endl;
//        std::cout<<"\tMF=3 (Xsec): ";
//        for (auto& rxn: ndata->reactions) {
//            std::cout<<rxn.MT<<" ";
//            MF3Rxn.insert(rxn.MT);
//        }
//        std::cout<<std::endl;
//        std::cout<<"\tMF=4 (ADist): ";
//        for (auto& rxn: ndata->angularDists) {
//            std::cout<<"\n\t"<<rxn.MT<<": ";
//            MF4Rxn.insert(rxn.MT);
//            // Check interpolation laws
//            std::cout<<"("<<(long)rxn.type<<") ";
//            switch (rxn.type) {
//                case ENDFNeutronData::AngularDist::Type::ISOTROPIC:
//                {
//                    break;
//                }
//                case ENDFNeutronData::AngularDist::Type::LEGENDRE:
//                {
//                    std::cout<<"( ";
//                    for (auto& law : rxn.legendFunc2.interp) {
//                        std::cout<<law.INT<<"/"<<law.NBT<<" ";
//                    }
//                    std::cout<<") ";
//                    break;
//                }
//                case ENDFNeutronData::AngularDist::Type::TABULATED:
//                {
//                    std::cout<<"( ";
//                    for (auto& law : rxn.interpFunc2.interp) {
//                        std::cout<<law.INT<<"/"<<law.NBT<<" ";
//                    }
//                    std::cout<<") ";
//                    break;
//                }
//                case ENDFNeutronData::AngularDist::Type::MIXED:
//                {
//                    std::cout<<"( ";
//                    for (auto& law : rxn.legendFunc2.interp) {
//                        std::cout<<law.INT<<"/"<<law.NBT<<" ";
//                    }
//                    std::cout<<") ";
//                    std::cout<<"( ";
//                    for (auto& law : rxn.interpFunc2.interp) {
//                        std::cout<<law.INT<<"/"<<law.NBT<<" ";
//                    }
//                    std::cout<<") ";
//                    break;
//                }
//            }
//        }
//        std::cout<<std::endl;
//        std::cout<<"\tMF=5 (EDist): ";
//        for (auto& rxn: ndata->energyDists) {
//            std::cout<<"\n\t"<<rxn.MT<<": ";
//            MF5Rxn.insert(rxn.MT);
//            // Loop over partial reactions
//            for (auto& p : rxn.partialDists) {
//                // Check energy laws
//                std::cout<<"("<<(long)p.law<<") ";
//                MF5Laws.insert((long)p.law);
//                if ((long)p.law == 1) {
//                    MF5Law1Rxn.insert(rxn.MT);
//                } else if ((long)p.law == 5) {
//                    MF5Law5Rxn.insert(rxn.MT);
//                } else if ((long)p.law == 7) {
//                    MF5Law7Rxn.insert(rxn.MT);
//                } else if ((long)p.law == 9) {
//                    MF5Law9Rxn.insert(rxn.MT);
//                } else if ((long)p.law == 11) {
//                    MF5Law11Rxn.insert(rxn.MT);
//                } else if ((long)p.law == 12) {
//                    MF5Law12Rxn.insert(rxn.MT);
//                }
//            }
//        }
//        std::cout<<std::endl;
//        std::cout<<"\tMF=6 (EADist): ";
//        for (auto& rxn: ndata->energyAngleDists) {
//            std::cout<<"\n\t"<<rxn.MT<<": ";
//            MF6Rxn.insert(rxn.MT);
//            // Loop over product
//            for (auto& p : rxn.products) {
//                // Check energy laws
//                std::cout<<"("
//                <<p.ZAP<<"/"<<p.LIP<<"/"<<p.AWP<<": "
//                <<(long)p.law<<") ";
//                MF6Laws.insert((long)p.law);
//                if (p.ZAP == 1) {
//                    MF6NLaws.insert((long)p.law);
//                }
//                if ((long)p.law == 1) {
//                    MF6Law1Rxn.insert(rxn.MT);
//                } else if ((long)p.law == 2) {
//                    MF6Law2Rxn.insert(rxn.MT);
//                } else if ((long)p.law == 3) {
//                    MF6Law3Rxn.insert(rxn.MT);
//                    if (p.ZAP == 1) {
//                        std::cout<<" (MF6 NLaw 3 "<<rxn.MT<<") ";
//                    }
//                } else if ((long)p.law == 4) {
//                    MF6Law4Rxn.insert(rxn.MT);
//                } else if ((long)p.law == 5) {
//                    MF6Law5Rxn.insert(rxn.MT);
//                } else if ((long)p.law == 6) {
//                    MF6Law6Rxn.insert(rxn.MT);
//                } else if ((long)p.law == 7) {
//                    MF6Law7Rxn.insert(rxn.MT);
//                }
//            }
//            
//        }
//        std::cout<<std::endl;
//        
//        // Check reaction MT = 5 particle type
//        for (auto& rxn: ndata->energyAngleDists) {
//            if (rxn.MT == 5) {
//                std::cout<<"\t\tMT = 5 particles: ";
//                for (auto& product : rxn.products) {
//                    long Z = product.ZAP/1000;
//                    long A = product.ZAP%1000;
//                    std::string symbol;
//                    if (product.ZAP == 0) {
//                        symbol = "gamma";
//                    } else if (A == 0) {
//                        symbol = "electron";
//                    } else if (Z == 0 && A == 1) {
//                        symbol = "neutron";
//                    }else {
//                        auto is = NIST::getIsotope(Z, A);
//                        if (is != nullptr) {
//                            symbol = is->getSymbol();
//                        } else {
//                            symbol = "[" + std::to_string(product.ZAP) + "]";
//                        }
//                    }
//                    std::cout<<" "<<symbol;
//                }
//                std::cout<<std::endl;
//            }
//        }
//        
//        // Check cndata
////        auto cndata = new CFSNeutronData(ndata);
////        
////        if (!cndata->valid()) {
////            std::cerr<<"\tLoad CFS neutron data fails!"<<std::endl;
////        }
////        
////        if (cndata != nullptr) {
////            delete cndata;
////            cndata = nullptr;
////        }
//        
//    }, [](long NLIB, long NVER, long LREL) {
//        return NLIB == 0 && NVER == 7 && LREL == 0;
//    });
    
//    std::cout << "MF = 3 reactions: ";
//    for (long MT : MF3Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//
//    std::cout << "MF = 4 reactions: ";
//    for (long MT : MF4Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF = 5 reactions: ";
//    for (long MT : MF5Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF = 6 reactions: ";
//    for (long MT : MF6Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF5 laws: ";
//    for (long law : MF5Laws) {
//        std::cout<<law<<" ";
//    }
//    std::cout<<std::endl;
//
//    
//    std::cout << "MF6 laws: ";
//    for (long law : MF6Laws) {
//        std::cout<<law<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF6 Neutron laws: ";
//    for (long law : MF6NLaws) {
//        std::cout<<law<<" ";
//    }
//    std::cout<<std::endl;
//
//    std::cout << "MF5 Law 1 Rxn: ";
//    for (long MT : MF5Law1Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF5 Law 5 Rxn: ";
//    for (long MT : MF5Law5Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF5 Law 7 Rxn: ";
//    for (long MT : MF5Law7Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF5 Law 9 Rxn: ";
//    for (long MT : MF5Law9Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF5 Law 11 Rxn: ";
//    for (long MT : MF5Law11Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF5 Law 12 Rxn: ";
//    for (long MT : MF5Law12Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF6 Law 1 Rxn: ";
//    for (long MT : MF6Law1Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF6 Law 2 Rxn: ";
//    for (long MT : MF6Law2Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF6 Law 3 Rxn: ";
//    for (long MT : MF6Law3Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF6 Law 4 Rxn: ";
//    for (long MT : MF6Law4Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF6 Law 5 Rxn: ";
//    for (long MT : MF6Law5Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF6 Law 6 Rxn: ";
//    for (long MT : MF6Law6Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "MF6 Law 7 Rxn: ";
//    for (long MT : MF6Law7Rxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;

    
//    auto el = NIST::getElement(1);
//    auto is = NIST::getIsotope(92, 235);
//    auto i0 = NIST::getIsotope(1, 3);
//    auto ism = NIST::getIsotopeM(26, 56, 1);
//    
//    std::cout<<is->getSymbol()<<std::endl;
//    std::cout<<i0->getSymbol()<<std::endl;
//    std::cout<<ism->getSymbol()<<std::endl;
    
     /* Test ACE  */
     std::string line = "Hello World";
     
     auto token = IO::split(line);
    
    //ADLS adls("/Users/changyuan/Desktop/ace.db");
    // adls.insertACELibrary("/Users/changyuan/LANL/MCNP_DATA/xsdir");

    auto andata = adls.getNeutronData("5010", "70c");

    long m = 2;
    
//
//    for(auto& rxn : ndata->reactions) {
//        if (rxn.MT == 102) {
//            
//            long I = rxn.xsec.start;
//            long N = rxn.xsec.sigmas.size();
//            std::vector<double> xvec, yvec;
//            xvec.resize(N, 0.);
//            yvec.resize(N, 0.);
//            for (long i=0; i<N; i++) {
//                xvec[i] = ndata->energyMevGrid.data[I+i].x;
//                yvec[i] = rxn.xsec.sigmas[i];
//            }
//            auto svg = SVGPlot2D
//            (900, 600, xvec, yvec, SVGPlot2D::LineStyle::LOGLOG);
//            
//            svg.printToFile("/Users/changyuan/Desktop/capture.svg");
//        }
//    }
//    
//    long n = 1;
//    
//    if (ndata != nullptr) {
//        delete ndata;
//        ndata = nullptr;
//    }
    
//    std::set<long> xsecRxn, adistRxn, edistRxn, elaws;
//    
//    adls.iterateOverMaterials
//    ([&] (const ACETable& table, ACENeutronData* ndata) {
//        std::cout<<"["<<ACE::getNameFromZAID(table.name)
//        <<"/"<<table.library<<"]: "<<std::endl;
//        std::cout<<"\tReactions: \n";
//        for (auto& rxn : ndata->reactions) {
//            std::cout<<"\t\t"<<rxn.MT<<": ";
//            if (!rxn.xsec.sigmas.empty()) {
//                xsecRxn.insert(rxn.MT);
//            }
//            if (labs(rxn.TY) > 100) {
//                std::cout<<"[CFS]: yield func for rxn MT="<<rxn.MT<<std::endl;
//            }
//            if (rxn.adist.valid()) {
//                std::cout<<" (adist: "<<(rxn.adist.isotropic?"I":"T");
//                if (!rxn.adist.isotropic) {
//                    long N = rxn.adist.ergInMevFunc.data.size();
//                    std::cout<<" "<<N;
//                }
//                std::cout<<")";
//                adistRxn.insert(rxn.MT);
//            }
//            if (rxn.edist.valid()) {
//                std::cout<<" (edist: ";
//                for (auto& p : rxn.edist.partialDists) {
//                    std::cout<<(long)(p.law)<<" ";
//                    elaws.insert((long)p.law);
//                    if ((long)p.law == 4) {
//                        for (auto& d : p.law4.ergInMevFunc.data) {
//                            if(d.y.info.ND != 0) {
//                                long n = 1;
//                            }
//                        }
//                    } else if ((long)p.law == 44) {
//                        for (auto& d : p.law44.ergInMevFunc.data) {
//                            if(d.y.info.ND != 0) {
//                                long n = 1;
//                            }
//                        }
//                    } else if ((long)p.law == 61) {
//                        for (auto& d : p.law61.ergInMevFunc.data) {
//                            if(d.y.info.ND != 0) {
//                                long n = 1;
//                            }
//                        }
//                    }
//                    if ((long)p.law == 44 || (long)p.law == 61 ||
//                        (long)p.law == 66 || (long)p.law == 67) {
//                        std::cout<<" (#pdist = "<<rxn.edist.partialDists.size()<<") ";
//                        if (rxn.edist.partialDists.size() != 1) {
//                            long n = 4;
//                        }
//                    }
//                }
//                std::cout<<")";
//                edistRxn.insert(rxn.MT);
//            }
//            std::cout<<"\n";
//        }
//    },
//     [&] (const ACETable& table) {
//         // Do nothing if not 70 lib
//         return table.getIdentifier() == 70;
//     });
//    
//    std::cout << "Xsec reactions: ";
//    for (long MT : adistRxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "Adist reactions: ";
//    for (long MT : adistRxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "Edist reactions: ";
//    for (long MT : edistRxn) {
//        std::cout<<MT<<" ";
//    }
//    std::cout<<std::endl;
//    
//    std::cout << "Edist laws: ";
//    for (long law : elaws) {
//        std::cout<<law<<" ";
//    }
//    std::cout<<std::endl;
    
//    std::regex pattern(R"(([\S]+)\.([\S]+))");
//    std::smatch match;
//    std::string text = "92235.70c";
//    
//    std::vector<std::string> components;
//    if (std::regex_match(text,match,pattern)) {
//        for (auto& m : match) {
//            components.push_back(m.str());
//        }
//        components.erase(components.begin());
//    }
//
    
    std::cout << "Hello, World!\n";
    return 0;
}
