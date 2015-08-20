if __name__ == "__main__":

    import ROOT

    fDYB=ROOT.TFile("files_nominal/DYB.root","r")
    fDYS=ROOT.TFile("files_nominal/DYS.root","r")
    fW=ROOT.TFile("files_nominal/W.root","r")
    fTT=ROOT.TFile("files_nominal/TT.root","r")
    fQCD=ROOT.TFile("files_nominal/QCD.root","r")
    fout=ROOT.TFile("files_nominal/Data.root","recreate")

    #hOS_pass=ROOT.TH1F("p","p",25,10,250)
    #for i in range(0,25):
    #	hOS_pass.SetBinContent(i+1,fQCD.Get("passOS/QCD").GetBinContent(i+1)+fW.Get("passOS/W").GetBinContent(i+1)+fTT.Get("passOS/TT").GetBinContent(i+1)+fDYB.Get("passOS/DYB").GetBinContent(i+1)+fDYS.Get("passOS/DYS120").GetBinContent(i+1))

    #hOS_fail=ROOT.TH1F("f","f",25,10,250)
    #for i in range(0,25):
    #    hOS_fail.SetBinContent(i+1,fQCD.Get("failOS/QCD").GetBinContent(i+1)+fW.Get("failOS/W").GetBinContent(i+1)+fTT.Get("failOS/TT").GetBinContent(i+1)+fDYB.Get("failOS/DYB").GetBinContent(i+1)+fDYS.Get("failOS/DYS120").GetBinContent(i+1))

    hOS_pass=fQCD.Get("passOS/QCD").Clone()
    hOS_pass.Add(fDYB.Get("passOS/DYB"))
    hOS_pass.Add(fTT.Get("passOS/TT"))
    hOS_pass.Add(fW.Get("passOS/W"))
    hOS_pass.Add(fDYS.Get("passOS/DYS120"),1.0)

    hOS_fail=fQCD.Get("failOS/QCD").Clone()
    hOS_fail.Add(fDYB.Get("failOS/DYB"))
    hOS_fail.Add(fTT.Get("failOS/TT"))
    hOS_fail.Add(fW.Get("failOS/W"))
    hOS_fail.Add(fDYS.Get("failOS/DYS120"),1.0)

    hOS_pass.SetName("data_obs")
    hOS_fail.SetName("data_obs")

    fout.cd()
    dirFailOS=fout.mkdir("failOS")
    dirFailOS.cd()
    hOS_fail.Write()
    dirPassOS=fout.mkdir("passOS")
    dirPassOS.cd()
    hOS_pass.Write()

