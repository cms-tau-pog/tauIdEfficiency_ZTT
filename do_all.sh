./Make.sh FinalSelection.cc
./FinalSelection.exe ntuples/Data.root files_nominal/Data.root data_obs iso comb3L mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_nominal/DYS.root DYS120 iso comb3L mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_nominal/DYB.root DYB iso comb3L mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/TT.root files_nominal/TT.root TT iso comb3L mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/W.root files_nominal/Wunscaled.root W iso comb3L mvis 0 20 4000 0 20 0 2000

./FinalSelection.exe ntuples/Data.root files_anti_nominal/Data.root data_obs anti comb3L mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_anti_nominal/DYS.root DYS120 anti comb3L mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_anti_nominal/DYB.root DYB anti comb3L mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/TT.root files_anti_nominal/TT.root TT anti comb3L mvis 0 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/W.root files_anti_nominal/Wunscaled.root W anti comb3L mvis 0 20 4000 0 20 0 2000

./FinalSelection.exe ntuples/DY.root files_up/DYS.root DYS120 iso comb3L mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_up/DYB.root DYB iso comb3L mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/TT.root files_up/TT.root TT iso comb3L mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/W.root files_up/Wunscaled.root W iso comb3L mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_down/DYS.root DYS120 iso comb3L mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_down/DYB.root DYB iso comb3L mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/TT.root files_down/TT.root TT iso comb3L mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/W.root files_down/Wunscaled.root W iso comb3L mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_anti_up/DYS.root DYS120 anti comb3L mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_anti_up/DYB.root DYB anti comb3L mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/TT.root files_anti_up/TT.root TT anti comb3L mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/W.root files_anti_up/Wunscaled.root W anti comb3L mvis 1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_anti_down/DYS.root DYS120 anti comb3L mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/DY.root files_anti_down/DYB.root DYB anti comb3L mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/TT.root files_anti_down/TT.root TT anti comb3L mvis -1 20 4000 0 20 0 2000
./FinalSelection.exe ntuples/W.root files_anti_down/Wunscaled.root W anti comb3L mvis -1 20 4000 0 20 0 2000

python Scale_W.py --scale nominal --anti iso
python Scale_W.py --scale up --anti iso
python Scale_W.py --scale down --anti iso
python Scale_W.py --scale nominal --anti anti
python Scale_W.py --scale up --anti anti
python Scale_W.py --scale down --anti anti
python Create_QCD.py --scale up 
python Create_QCD.py --scale nominal 
python Create_QCD.py --scale down
hadd -f final.root files_nominal/W.root files_nominal/Data.root files_nominal/DYS.root files_nominal/DYB.root files_nominal/TT.root files_nominal/QCD.root files_down/W.root files_down/DYS.root files_down/DYB.root files_down/TT.root files_up/W.root files_up/DYS.root files_up/DYB.root files_up/TT.root files_down/QCD.root files_up/QCD.root
python Draw.py
python Write_Anticorrelation.py
