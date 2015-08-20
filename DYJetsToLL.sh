source $VO_CMS_SW_DIR/cmsset_default.sh 
cd /localgrid/ccaillol/Analyses_13TeV_slc6/CMSSW_7_2_0/src/tauIDefficiency_LLRntuples 
eval `scram runtime -sh` 
export scratchdir=/scratch/ 
export workdir=/localgrid/ccaillol/Analyses_13TeV_slc6/CMSSW_7_2_0/src/tauIDefficiency_LLRntuples 
mkdir -p $workdir/Out_DYJetsToLL
./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_1.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_1.root 
 mv  $scratchdir/HTauTauAnalysis_1.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_10.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_10.root 
 mv  $scratchdir/HTauTauAnalysis_10.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_11.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_11.root 
 mv  $scratchdir/HTauTauAnalysis_11.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_12.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_12.root 
 mv  $scratchdir/HTauTauAnalysis_12.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_13.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_13.root 
 mv  $scratchdir/HTauTauAnalysis_13.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_14.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_14.root 
 mv  $scratchdir/HTauTauAnalysis_14.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_15.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_15.root 
 mv  $scratchdir/HTauTauAnalysis_15.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_16.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_16.root 
 mv  $scratchdir/HTauTauAnalysis_16.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_17.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_17.root 
 mv  $scratchdir/HTauTauAnalysis_17.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_18.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_18.root 
 mv  $scratchdir/HTauTauAnalysis_18.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_19.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_19.root 
 mv  $scratchdir/HTauTauAnalysis_19.root	$workdir/Out_DYJetsToLL 



./MuTau_Analysis.exe mc $scratchdir/HTauTauAnalysis_2.root dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000//HTauTauAnalysis_2.root 
 mv  $scratchdir/HTauTauAnalysis_2.root	$workdir/Out_DYJetsToLL 


