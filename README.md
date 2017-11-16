# OpenJoy

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

Special thanks to the encouragement from IAPCM Beijing
