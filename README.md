# OpenJoy
(Not ready for use, for peer advising with partners)

-- LISCENSE --

  Licensed to the Apache Software Foundation (ASF) under one or more
  contributor license agreements.  See the NOTICE file distributed with
  this work for additional information regarding copyright ownership.
  The ASF licenses this file to You under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with
  the License.  You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,

WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

-- END OF LISCENSE --


This is work intending for simplying the usage for ACE/ENDF nuclear data files
This work is very very small portion compared to what a big system like NJOY done
But we derived the code from first principles

## Currently we support:

ACE:

1. Pack text ACE files into a SQlite database for space saving and version managerment
2. Extract ACE record into a computational friendly format for writting a code like OpenMC
3. Pointwise doppler broadening using Sigma1 method

ENDF:

1. Pack text ENDF files into a SQlite database for space saving and version managerment
2. Extract ENDF record into a computational friendly format
3. Cross section reconstruction and linearization in resolved resonance regions for SLBW, MLBW, AA, and RM expression

## Complation requires the library:
Protobuffer run time library V2.6.1 or newer

## Getting start:
Check the class interface:

ADLS.hpp for ACE library
NDLS.hpp for ENDF library

### Special thanks to IAPCM Beijing for the encouragement and guildance

## ACE Protocol
package proto.ace;

message MainRxn {
	required double total      = 1;
	required double elastic    = 2;
	required double absorption = 3;
	required double fission    = 4;
	required double heating    = 5;
};

message EnergyGridDataPoint {
	required double  x = 1;
	required MainRxn y = 2;
};

message EnergyGrid {
	repeated EnergyGridDataPoint data = 1;
};

message Xsec {
	required int64  start  = 1;
	repeated double sigmas = 2;
};

message Reaction {
	required int64 MT  = 1;
	required Xsec xsec = 8;
};

message NeutronData {
	required int64      ZA    = 1;
	required double     AWR   = 2;
	required double     TEMPK = 3;

	required EnergyGrid energyMevGrid = 4;
	repeated Reaction   reactions     = 5;
};

## ENDF Protocol
package proto.endf.raw;

message TableInterpLaw {
	required int64 INT = 1;
	required int64 NBT = 2;
}

message TableDataPoint {
	required double X = 1;
	required double Y = 2;
}

message Table {
	repeated TableInterpLaw interp_laws = 1;
	repeated TableDataPoint data_points = 2;
}

message BreitWigner {
	required double ER = 1;
	required double AJ = 2;
	required double GT = 3;
	required double GN = 4;
	required double GG = 5;
	required double GF = 6;
};

message ReichMoore {
	required double ER = 1;
	required double AJ = 2;
	required double GN = 3;
	required double GG = 4;
	required double GFA = 5;
	required double GFB = 6;
};

message Momentum {
	required double AWRI = 1;
	required double QX   = 2;
	required double L    = 3;
	required int64  LRX  = 4;
	required double APL  = 5;

	repeated BreitWigner BWTables = 6;
	repeated ReichMoore  RMTables = 7;
};

message Range {
	required double EL   = 1;
	required double EH   = 2;
	required int64  LRU  = 3;
	required int64  LRF  = 4;
	required int64  NRO  = 5;
	required int64  NAPS = 6;

	required double SPI  = 11;
	required double AP   = 12;
	required Table  APE  = 13;
	required int64  LAD  = 14;
	required int64  NLSC = 15;

	required int64  LI   = 21;
	required int64  NX   = 22;
	required double AWRI = 23;

	required int64  LSSF   = 31;
	repeated double URRBES = 32;

	repeated Momentum moments = 61;
};

message Resonance {
	required int64  ZAI    = 1;
	required double ABN    = 2;
	required int64  LFW    = 3;
	repeated Range  ranges = 8;
}

message NeutronData {
	required int64     ZA         = 1;
	required double    AWR        = 2;
	required double    TEMPK      = 3;
	repeated Resonance resonances = 8;
};
