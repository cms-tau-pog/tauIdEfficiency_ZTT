# tauIdEfficiency_ZTT
package for measurement of tau identification efficiency in Z -> tautau events using Tag &amp; Probe

Ntuplization:
------------

With this code: https://github.com/LLRCMS/LLRHiggsTauTau

Skimmed trees:
-------------

Selection of mu-tau_h pair, rejection of events with extra leptons or bjets:

```shell
./Make.sh MuTau_Analysis.cc
./MuTau_Analysis.exe data(/mc) out.root in.root
```

Submission to local queue at T2_B2_IIHE
```shell
python filesBxl_divided.py
sh Submit.sh
```

Input files preparation:
-----------------------

Copy all files produced before in "ntuples/". 

With data-driven estimations:
```shell
sh do_all.sh
```

Everything from MC:
```shell
sh do_all_MC.sh
```
