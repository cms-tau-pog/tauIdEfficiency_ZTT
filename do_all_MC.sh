./Make.sh FinalSelection.cc
./FinalSelection.exe ntuples/DY.root files_nominal/DYS.root DYS120 iso comb3T mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_nominal/DYB.root DYB iso comb3T mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/TT.root files_nominal/TT.root TT iso comb3T mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/W.root files_nominal/W.root W iso comb3T mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/QCD.root files_nominal/QCD.root QCD iso comb3T mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/Data.root files_nominal/Data.root data_obs iso comb3T mvis 0 20 4000 0 20 0 2000

./FinalSelection.exe ntuples/DY.root files_up/DYS.root DYS120 iso comb3T mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_up/DYB.root DYB iso comb3T mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/TT.root files_up/TT.root TT iso comb3T mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/W.root files_up/W.root W iso comb3T mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/QCD.root files_up/QCD.root QCD iso comb3T mvis 1 20 4000 0 20 0 2000

./FinalSelection.exe ntuples/DY.root files_down/DYS.root DYS120 iso comb3T mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_down/DYB.root DYB iso comb3T mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/TT.root files_down/TT.root TT iso comb3T mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/W.root files_down/W.root W iso comb3T mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/QCD.root files_down/QCD.root QCD iso comb3T mvis -1 20 4000 0 20 0 2000

python Write_Anticorrelation.py
python CreatePseudoData.py

hadd -f final.root files_nominal/W.root files_nominal/Data.root files_nominal/DYS.root files_nominal/DYB.root files_nominal/TT.root files_nominal/QCD.root files_down/W.root files_down/DYS.root files_down/DYB.root files_down/TT.root files_up/W.root files_up/DYS.root files_up/DYB.root files_up/TT.root files_down/QCD.root files_up/QCD.root
python Draw.py

