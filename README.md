
# OpenJoy
(Not ready for use, for peer advsing for partner)

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

Currently we support:

ACE:

1. Pack text ACE files into a SQlite database for space saving and version managerment
2. Extract ACE record into a computational friendly format for writting a code like OpenMC
3. Pointwise doppler broadening using Sigma1 method

ENDF:

1. Pack text ENDF files into a SQlite database for space saving and version managerment
2. Extract ENDF record into a computational friendly format
3. Cross section reconstruction and linearization in resolved resonance regions for SLBW, MLBW, AA, and RM expression

Complation requires the library:

- Protobuffer run time library V2.6.1 or newer

Special thanks to IAPCM Beijing for the encouragement and guildance
