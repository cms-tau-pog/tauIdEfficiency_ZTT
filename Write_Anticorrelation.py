if __name__ == "__main__":

    import ROOT

    fDYS=ROOT.TFile("files_nominal/DYS.root","r")
    fout = open('norm_tauID.txt', 'w')
    factor=(0.5*fDYS.Get("passOS/DYS120").Integral()+fDYS.Get("failOS/DYS120").Integral())/fDYS.Get("failOS/DYS120").Integral()
    fout.write(str(factor))
    fout.close()
    

