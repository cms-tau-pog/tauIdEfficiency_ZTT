if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down'], help="Which TES?")
    parser.add_argument('--anti', default="iso", choices=['iso', 'anti'], help="Which TES?")
    options = parser.parse_args()

    anti=""
    if (options.anti=="anti"):
        anti="anti_"

    postfix=""
    if (options.scale=="up"):
        postfix="_TESUp"
    if (options.scale=="down"):
        postfix="_TESDown"

    fDYB=ROOT.TFile("files_"+options.scale+"/DYB.root","r")
    fDYS=ROOT.TFile("files_"+options.scale+"/DYS.root","r")
    fW=ROOT.TFile("files_"+options.scale+"/Wunscaled.root","r")
    fTT=ROOT.TFile("files_"+options.scale+"/TT.root","r")
    fData=ROOT.TFile("files_nominal/Data.root","r")
    fout=ROOT.TFile("files_"+anti+options.scale+"/W.root","recreate")

    fW_=ROOT.TFile("files_"+anti+options.scale+"/Wunscaled.root","r")

    hWpassOS=fW_.Get("passOS/W"+postfix)
    hWpassOS.Scale((fData.Get("n70").GetBinContent(1)-fDYB.Get("n70").GetBinContent(1)-fDYS.Get("n70").GetBinContent(1)-fTT.Get("n70").GetBinContent(1))/fW.Get("n70").GetBinContent(1))
    print "SF pass OS: ",(fData.Get("n70").GetBinContent(1)-fDYB.Get("n70").GetBinContent(1)-fDYS.Get("n70").GetBinContent(1)-fTT.Get("n70").GetBinContent(1))/fW.Get("n70").GetBinContent(1)
    hWfailOS=fW_.Get("failOS/W"+postfix)
    hWfailOS.Scale((fData.Get("n70").GetBinContent(2)-fDYB.Get("n70").GetBinContent(2)-fDYS.Get("n70").GetBinContent(2)-fTT.Get("n70").GetBinContent(2))/fW.Get("n70").GetBinContent(2))
    print "SF fail OS: ",(fData.Get("n70").GetBinContent(2)-fDYB.Get("n70").GetBinContent(2)-fDYS.Get("n70").GetBinContent(2)-fTT.Get("n70").GetBinContent(2))/fW.Get("n70").GetBinContent(2)
    hWpassSS=fW_.Get("passSS/W"+postfix)
    hWpassSS.Scale((fData.Get("n70").GetBinContent(3)-fDYB.Get("n70").GetBinContent(3)-fDYS.Get("n70").GetBinContent(3)-fTT.Get("n70").GetBinContent(3))/fW.Get("n70").GetBinContent(3))
    print "SF pass SS: ",(fData.Get("n70").GetBinContent(3)-fDYB.Get("n70").GetBinContent(3)-fDYS.Get("n70").GetBinContent(3)-fTT.Get("n70").GetBinContent(3))/fW.Get("n70").GetBinContent(3)
    hWfailSS=fW_.Get("failSS/W"+postfix)
    hWfailSS.Scale((fData.Get("n70").GetBinContent(4)-fDYB.Get("n70").GetBinContent(4)-fDYS.Get("n70").GetBinContent(4)-fTT.Get("n70").GetBinContent(4))/fW.Get("n70").GetBinContent(4))
    print "SF fail SS: ",(fData.Get("n70").GetBinContent(4)-fDYB.Get("n70").GetBinContent(4)-fDYS.Get("n70").GetBinContent(4)-fTT.Get("n70").GetBinContent(4))/fW.Get("n70").GetBinContent(4)

    fout.cd()
    dirPassOS=fout.mkdir("passOS")
    dirPassOS.cd()
    hWpassOS.SetName("W"+postfix)
    hWpassOS.Write()
    dirFailOS=fout.mkdir("failOS")
    dirFailOS.cd()
    hWfailOS.SetName("W"+postfix)
    hWfailOS.Write()
    dirPassSS=fout.mkdir("passSS")
    dirPassSS.cd()
    hWpassSS.SetName("W"+postfix)
    hWpassSS.Write()
    dirFailSS=fout.mkdir("failSS")
    dirFailSS.cd()
    hWfailSS.SetName("W"+postfix)
    hWfailSS.Write()

