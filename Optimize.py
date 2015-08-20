if __name__ == "__main__":

    import ROOT

    fDYB=ROOT.TFile("files_nominal/DYB.root","r")
    fDYS=ROOT.TFile("files_nominal/DYS.root","r")
    fW=ROOT.TFile("files_nominal/W.root","r")
    fTT=ROOT.TFile("files_nominal/TT.root","r")
    fQCD=ROOT.TFile("files_nominal/QCD.root","r")
    fout=ROOT.TFile("files_nominal/Data.root","recreate")

    QCDp=fQCD.Get("passOS/QCD")
    DYBp=fDYB.Get("passOS/DYB")
    TTp=fTT.Get("passOS/TT")
    Wp=fW.Get("passOS/W")
    DYSp=fDYS.Get("passOS/DYS120")

    QCDf=fQCD.Get("failOS/QCD")
    DYBf=fDYB.Get("failOS/DYB")
    TTf=fTT.Get("failOS/TT")
    Wf=fW.Get("failOS/W")
    DYSf=fDYS.Get("failOS/DYS120")

    c1=ROOT.TCanvas("c1","A Simple Graph Example",200,10,700,500)
    n=24
    x=[]
    yp=[]
    yf=[]

    import numpy
    x = numpy.ndarray( [34.] )
    yp = numpy.ndarray( [34.] )
    yf = numpy.ndarray( [34.] )
    #for i in range(len(x)):
    #   x[i] = -100+(i+1)*5
    #   sp=DYSp.Integral(i+1,36)
    #   bp=QCDp.Integral(i+1,36)+Wp.Integral(i+1,36)+TTp.Integral(i+1,36)+DYBp.Integral(i+1,36)
    #   sf=DYSf.Integral(i+1,36)
    #   bf=QCDf.Integral(i+1,36)+Wf.Integral(i+1,36)+TTf.Integral(i+1,36)+DYBf.Integral(i+1,36)
    #   yp[i]=sp/(sp+bp)**0.5
    #   yf[i]=sf/(sf+bf)**0.5
    for i in range(len(x)):
       x[i] = (i+1)*5
       sp=DYSp.Integral(0,i+1)
       bp=QCDp.Integral(0,i+1)+Wp.Integral(0,i+1)+TTp.Integral(0,i+1)+DYBp.Integral(0,i+1)
       sf=DYSf.Integral(0,i+1)
       bf=QCDf.Integral(0,i+1)+Wf.Integral(0,i+1)+TTf.Integral(0,i+1)+DYBf.Integral(0,i+1)
       print sp, bp, sf, bf
       yp[i]=sp/(bp)**0.5
       yf[i]=sf/(bf)**0.5
    grp = ROOT.TGraph(n,x,yp);
    grf = ROOT.TGraph(n,x,yf);
    grp.SetTitle("Pass")
    grp.GetXaxis().SetTitle("Maximum m_{T} (GeV)")#Minimum P_{#zeta} (GeV)")
    grp.GetYaxis().SetTitle("S/B")
    grp.GetYaxis().SetTitleOffset(1.3)
    grf.SetTitle("Fail")
    grf.GetXaxis().SetTitle("Maximum m_{T} (GeV)")#Minimum P_{#zeta} (GeV)")
    grf.GetYaxis().SetTitle("S/B")
    grf.GetYaxis().SetTitleOffset(1.3)
    grf.SetMarkerStyle(20)
    grp.SetMarkerStyle(20)
    c1.Divide(2,1)
    c1.cd(1)
    grp.Draw("ACP")
    c1.cd(2)
    grf.Draw("ACP");
    c1.SaveAs("opti.png")

