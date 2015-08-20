if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down'], help="Which TES?")
    options = parser.parse_args()

    postfix=""
    if (options.scale=="up"):
        postfix="_TESUp"
    if (options.scale=="down"):
        postfix="_TESDown"

    fDYB_anti=ROOT.TFile("files_anti_"+options.scale+"/DYB.root","r")
    fDYS_anti=ROOT.TFile("files_anti_"+options.scale+"/DYS.root","r")
    fW_anti=ROOT.TFile("files_anti_"+options.scale+"/W.root","r")
    fTT_anti=ROOT.TFile("files_anti_"+options.scale+"/TT.root","r")
    fData_anti=ROOT.TFile("files_anti_nominal/Data.root","r")
    fDYB=ROOT.TFile("files_"+options.scale+"/DYB.root","r")
    fDYS=ROOT.TFile("files_"+options.scale+"/DYS.root","r")
    fW=ROOT.TFile("files_"+options.scale+"/W.root","r")
    fTT=ROOT.TFile("files_"+options.scale+"/TT.root","r")
    fData=ROOT.TFile("files_nominal/Data.root","r")
    fout=ROOT.TFile("files_"+options.scale+"/QCD.root","recreate")

    #hSSanti_pass=fData_anti.Get("passSS/data_obs")
    #hSSanti_pass.Add(fDYB_anti.Get("passSS/DYB"+postfix),-1)
    #hSSanti_pass.Add(fTT_anti.Get("passSS/TT"+postfix),-1)
    #hSSanti_pass.Add(fW_anti.Get("passSS/W"+postfix),-1)
    #hSSanti_pass.Add(fDYS_anti.Get("passSS/DYS"+postfix),-1)

    hSSanti_pass=fData.Get("passSS/data_obs")
    hSSanti_pass.Add(fDYB.Get("passSS/DYB"+postfix),-1)
    hSSanti_pass.Add(fTT.Get("passSS/TT"+postfix),-1)
    hSSanti_pass.Add(fW.Get("passSS/W"+postfix),-1)
    hSSanti_pass.Add(fDYS.Get("passSS/DYS120"+postfix),-1)

    hSS_pass=fData.Get("passSS/data_obs")
    hSS_pass.Add(fDYB.Get("passSS/DYB"+postfix),-1)
    hSS_pass.Add(fTT.Get("passSS/TT"+postfix),-1)
    hSS_pass.Add(fW.Get("passSS/W"+postfix),-1)
    hSS_pass.Add(fDYS.Get("passSS/DYS120"+postfix),-1)

    hSSanti_fail=fData_anti.Get("failSS/data_obs")
    hSSanti_fail.Add(fDYB_anti.Get("failSS/DYB"+postfix),-1)
    hSSanti_fail.Add(fTT_anti.Get("failSS/TT"+postfix),-1)
    hSSanti_fail.Add(fW_anti.Get("failSS/W"+postfix),-1)
    hSSanti_fail.Add(fDYS_anti.Get("failSS/DYS120"+postfix),-1)

    hSS_fail=fData.Get("failSS/data_obs")
    hSS_fail.Add(fDYB.Get("failSS/DYB"+postfix),-1)
    hSS_fail.Add(fTT.Get("failSS/TT"+postfix),-1)
    hSS_fail.Add(fW.Get("failSS/W"+postfix),-1)
    hSS_fail.Add(fDYS.Get("failSS/DYS120"+postfix),-1)

    hSSanti_pass.SetName("QCD"+postfix)
    hSSanti_pass.Scale(1.06*hSS_pass.Integral()/hSSanti_pass.Integral())
    hSSanti_fail.SetName("QCD"+postfix)
    hSSanti_fail.Scale(1.06*hSS_fail.Integral()/hSSanti_fail.Integral())

    fout.cd()
    dirFailOS=fout.mkdir("failOS")
    dirFailOS.cd()
    hSSanti_fail.Write()
    dirPassOS=fout.mkdir("passOS")
    dirPassOS.cd()
    hSSanti_pass.Write()

