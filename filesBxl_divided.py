#! /usr/bin/python

import os
if __name__ == "__main__":
    location=os.getcwd();

    #pnfn="/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M50_Spring15_HTTntuples_July2015/150731_101445/0000"
    #pnfn="/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/WJetsToLNu_Spring15_HTTntuples_July2015/150731_102127/0000/"
    #pnfn="/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/TTJets_Spring15_HTTntuples_July2015/150731_102211/0000/"
    #pnfn="/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/MC/QCD_Pt-20toInf_MuEnrichedPt15_TuneCUETP8M1_13TeV_pythia8/QCD_Pt-20toInf_MuEnrichedPt15_Spring15_HTTntuples_July2015/150731_102150/0000/"
    pnfn="/pnfs/iihe/cms/store/user/ccaillol/NtuplesTauTau2015/74X/Data/SingleMuon/SingleMuon40pb/150731_151055/0000/"

    #myname="DYJetsToLL"
    #myname="WJetsToLNu"
    myname="Data"
    #myname="QCD"
    #myname="TTJets"
    submit_File = open("Submit_"+myname+".sh" , 'w')
    f=os.popen("ls -t " + pnfn + " | sort")
    dir = "dcap://maite.iihe.ac.be" +  pnfn  + "/"
    name_out =  myname + ".sh"
    outFile = open(name_out , 'w')
    command1 = "source $VO_CMS_SW_DIR/cmsset_default.sh " + "\n"
    command1 = command1 + "cd /localgrid/ccaillol/Analyses_13TeV_slc6/CMSSW_7_2_0/src/tauIDefficiency_LLRntuples " + "\n"
    command1 = command1 + "eval `scram runtime -sh` " + "\n"
    command1 = command1 + "export scratchdir=/scratch/ " + "\n"
    command1 = command1 + "export workdir=/localgrid/ccaillol/Analyses_13TeV_slc6/CMSSW_7_2_0/src/tauIDefficiency_LLRntuples " + "\n"
    command1 = command1 + "mkdir -p $workdir/Out_"+myname
    outFile.write(command1)
    command3 = "qsub -q localgrid@cream02 -o "+ myname +".stdout -e " +myname +".stderr -l walltime=06:30:00    " + name_out + "\n"
    submit_File.write(command3)
    ligne=0
    for i in f.readlines():
       #print ligne
       ligne=ligne+1
       if ligne%13==0:
           outFile.close()
           outFile = open("test"+str(ligne/13)+name_out , 'w')
           command1 = "source $VO_CMS_SW_DIR/cmsset_default.sh " + "\n"
           command1 = command1 + "cd /localgrid/ccaillol/Analyses_13TeV_slc6/CMSSW_7_2_0/src/tauIDefficiency_LLRntuples " + "\n"
           command1 = command1 + "eval `scram runtime -sh` " + "\n"
           command1 = command1 + "export scratchdir=/scratch/ " + "\n"
           command1 = command1 + "export workdir=/localgrid/ccaillol/Analyses_13TeV_slc6/CMSSW_7_2_0/src/tauIDefficiency_LLRntuples " + "\n"
	   command1 = command1 + "mkdir -p $workdir/Out_"+myname
           outFile.write(command1)
           command3 = "qsub -q localgrid@cream02 -o "+ "test"+str(ligne/13)+myname +".stdout -e " +"test"+str(ligne/13)+myname +".stderr -l walltime=06:30:00    " + "test"+str(ligne/13)+name_out + "\n"
           submit_File.write(command3)
       command2 = "\n" + "./MuTau_Analysis.exe data " + "$scratchdir/" +  i[0:-1]+ " " +   dir+ "/"+ i[0:-1]   
       command2 = command2 + " \n"+ " mv  $scratchdir/" + i[0:-1] + "\t" + "$workdir/Out_"+myname
       command2 = command2 + " \n\n\n"
       outFile.write(command2)
    
    outFile.close()
    submit_File.close()
