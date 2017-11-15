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

// Implementations of Data Exchange System

#include "DES.hpp"

proto::endf::raw::Table* DES::getRawTable
(const ENDFInterpolationFunction* func) {
    
    // Set namespace using
    using namespace proto::endf::raw;
    
    // Placeholder for ndata protocol
    Table* tproto = nullptr;
    
    // Begin try-catch block
    try {
        
        // Check input
        if (func == nullptr) {
            throw std::logic_error("invalid interp. func!");
        }
    
        // Allocate memory
        tproto = new Table;
        if (tproto == nullptr) {
            throw std::logic_error("alloc. table proto fails!");
        }
        
        // Copy interp data
        tproto->mutable_interp_laws()->Reserve
        ((int)func->interp().size());
        for (auto& interp : func->interp()) {
            auto iproto = tproto->add_interp_laws();
            iproto->set_int_(interp.INT);
            iproto->set_nbt(interp.NBT);
        }
        
        // Copy data points
        tproto->mutable_data_points()->Reserve
        ((int)func->data().size());
        for (auto& data : func->data()) {
            auto dproto = tproto->add_data_points();
            dproto->set_x(data.x);
            dproto->set_y(data.y);
        }
        
    } catch (std::exception& e) {
        std::cerr << "[DES]: error msg - " << e.what() << std::endl;
        
        // Clear memory allocated
        if (tproto != nullptr) {
            delete tproto;
            tproto = nullptr;
        }
        return nullptr;
    }
    
    return tproto;
}

proto::endf::raw::NeutronData* DES::getRawNeutronData
(const ENDFNeutronData* ndata) {
    
    // Set namespace using
    using namespace proto::endf::raw;
    
    // Placeholder for ndata protocol
    NeutronData* nproto = nullptr;
    
    // Begin try-catch block
    try {
        
        // Check input
        if (ndata == nullptr) {
            throw std::logic_error("invalid ENDF ndata!");
        }
        
        // Allocate memory
        nproto = new NeutronData;
        if (nproto == nullptr) {
            throw std::logic_error("alloc. neutron data proto fails!");
        }
        
        // Copy header information
        nproto->set_za(ndata->ZA);
        nproto->set_awr(ndata->AWR);
        nproto->set_tempk(ndata->tempK);
        
        // Copy resonance properties
        nproto->mutable_resonances()->Reserve
        ((int)ndata->resonances.size());
        for (auto& rdata : ndata->resonances) {
            auto rproto = nproto->add_resonances();
            if (rproto == nullptr) {
                throw std::logic_error("alloc. resonance proto fails!");
            }
            
            // Copy header information
            rproto->set_zai(rdata.ZAI);
            rproto->set_abn(rdata.ABN);
            rproto->set_lfw(rdata.LFW);
            
            // Copy resonance ranges
            rproto->mutable_ranges()->Reserve
            ((int)rdata.ranges.size());
            for (auto& gdata : rdata.ranges) {
                auto gproto = rproto->add_ranges();
                if (gproto == nullptr) {
                    throw std::logic_error("add range proto fails!");
                }
                
                // Copy header information
                gproto->set_el(gdata.EL);
                gproto->set_eh(gdata.EH);
                gproto->set_lru(gdata.LRU);
                gproto->set_lrf(gdata.LRF);
                gproto->set_nro(gdata.NRO);
                gproto->set_naps(gdata.NAPS);
                
                gproto->set_spi(gdata.SPI);
                gproto->set_ap(gdata.AP);
                auto tproto = getRawTable(&gdata.APE);
                if (tproto == nullptr) {
                    throw std::logic_error("get raw table fails!");
                }
                gproto->mutable_ape()->MergeFrom(*tproto);
                gproto->set_lad(gdata.LAD);
                gproto->set_nlsc(gdata.NLSC);
                
                gproto->set_li(gdata.LI);
                gproto->set_nx(gdata.NX);
                gproto->set_awri(gdata.AWRI);
                
                gproto->set_lssf(gdata.LSSF);
                gproto->mutable_urrbes()->Reserve
                ((int)gdata.URRBES.size());
                for (double v : gdata.URRBES) {
                    gproto->add_urrbes(v);
                }
                
                // Copy momements
                gproto->mutable_moments()->Reserve
                ((int)gdata.moments.size());
                for (auto& mdata : gdata.moments) {
                    auto mproto = gproto->add_moments();
                    if (mproto == nullptr) {
                        throw std::logic_error("add moment proto fails!");
                    }
                    
                    // Copy header information
                    mproto->set_awri(mdata.AWRI);
                    mproto->set_qx(mdata.QX);
                    mproto->set_l(mdata.L);
                    mproto->set_lrx(mdata.LRX);
                    mproto->set_apl(mdata.APL);
                    
                    // Copy BW tables
                    mproto->mutable_bwtables()->Reserve
                    ((int)mdata.BWTables.size());
                    for (auto& bwdata : mdata.BWTables) {
                        auto bwproto = mproto->add_bwtables();
                        if (bwproto == nullptr) {
                            throw std::logic_error("add BW proto fails!");
                        }
                        
                        // Copy information
                        bwproto->set_er(bwdata.ER);
                        bwproto->set_aj(bwdata.AJ);
                        bwproto->set_gt(bwdata.GT);
                        bwproto->set_gn(bwdata.GN);
                        bwproto->set_gg(bwdata.GG);
                        bwproto->set_gf(bwdata.GF);
                    }
                    
                    // Copy RM tables
                    mproto->mutable_rmtables()->Reserve
                    ((int)mdata.RMTables.size());
                    for (auto& rmdata : mdata.RMTables) {
                        auto rmproto = mproto->add_rmtables();
                        if (rmproto == nullptr) {
                            throw std::logic_error("add RM proto fails!");
                        }
                        
                        // Copy information
                        rmproto->set_er(rmdata.ER);
                        rmproto->set_aj(rmdata.AJ);
                        rmproto->set_gn(rmdata.GN);
                        rmproto->set_gg(rmdata.GG);
                        rmproto->set_gfa(rmdata.GFA);
                        rmproto->set_gfb(rmdata.GFB);
                    }
                    
                    
                }
            }
            
        }
        
    } catch (std::exception& e) {
        std::cerr << "[DES]: error msg - " << e.what() << std::endl;
        
        // Clear memory allocated
        if (nproto != nullptr) {
            delete nproto;
            nproto = nullptr;
        }
        return nullptr;
    }
    
    return nproto;
}

proto::ace::NeutronData* DES::getNeutronData
(const ACENeutronData* ndata) {
    
    // Set namespace using
    using namespace proto::ace;
    
    // Placeholder for ndata protocol
    NeutronData* nproto = nullptr;
    
    // Begin try-catch block
    try {
        
        // Check input
        if (ndata == nullptr) {
            throw std::logic_error("invalid ENDF ndata!");
        }
        
        // Allocate memory
        nproto = new NeutronData;
        if (nproto == nullptr) {
            throw std::logic_error("alloc. neutron data proto fails!");
        }
        
        // Copy header information
        nproto->set_za(ndata->ZA);
        nproto->set_awr(ndata->AWR);
        nproto->set_tempk(ndata->tempK);
        
        // Copy energy grid
        nproto->mutable_energymevgrid()->mutable_data()->Reserve
        ((int)ndata->energyMevGrid.data.size());
        for (auto& ddata : ndata->energyMevGrid.data) {
            auto dproto = nproto->mutable_energymevgrid()->add_data();
            if (dproto == nullptr) {
                throw std::logic_error("alloc. data proto fails!");
            }
            dproto->set_x(ddata.x);
            dproto->mutable_y()->set_total(ddata.y.total);
            dproto->mutable_y()->set_elastic(ddata.y.elastic);
            dproto->mutable_y()->set_fission(ddata.y.fission);
            dproto->mutable_y()->set_heating(ddata.y.heating);
            dproto->mutable_y()->set_absorption(ddata.y.absorption);
        }
        
        // Copy reactions
        nproto->mutable_reactions()->Reserve
        ((int)ndata->reactions.size());
        for (auto& rdata : ndata->reactions) {
            auto rproto = nproto->add_reactions();
            if (rproto == nullptr) {
                throw std::logic_error("alloc. reaction proto fails!");
            }
            
            // Copy header information
            rproto->set_mt(rdata.MT);
            
            // Copy cross section
            rproto->mutable_xsec()->set_start(rdata.xsec.start);
            rproto->mutable_xsec()->mutable_sigmas()->Reserve
            ((int)rdata.xsec.sigmas.size());
            for (double v : rdata.xsec.sigmas) {
                rproto->mutable_xsec()->add_sigmas(v);
            }
        }
        
        
    } catch (std::exception& e) {
        std::cerr << "[DES]: error msg - " << e.what() << std::endl;
        
        // Clear memory allocated
        if (nproto != nullptr) {
            delete nproto;
            nproto = nullptr;
        }
        return nullptr;
    }
    
    return nproto;
}