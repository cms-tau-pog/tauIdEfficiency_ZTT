#!/usr/bin/env python
from HttStyles import GetStyleHtt
from HttStyles import MakeCanvas
import ROOT
import re
from array import array

def add_lumi():
    lowX=0.62
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.045)
    lumi.SetTextFont (   42 )
    lumi.AddText("40.24 pb^{-1} (13 TeV)")
    return lumi

def add_AZh():
    lowX=0.18
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.04)
    lumi.SetTextFont (   62 )
    lumi.AddText("A#rightarrow Zh#rightarrow#it{ll}#tau#tau")
    return lumi

def add_CMS():
    lowX=0.21
    lowY=0.75
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.04)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    lumi.AddText("Preliminary")
    return lumi

def add_state():
    lumi  = ROOT.TPaveText(0.21, 0.7+0.013, 0.43, 0.7+0.155, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextSize ( 0.04 )
    lumi.SetTextColor(    1 )
    lumi.SetTextFont (   62 )
    lumi.AddText("#it{ll}#tau_{h}#tau_{h}")
    return lumi

def make_legend():
        output = ROOT.TLegend(0.67, 0.60, 0.92, 0.90, "", "brNDC")
        output.SetLineWidth(0)
        output.SetLineStyle(0)
        output.SetFillStyle(0)
        output.SetBorderSize(0)
        output.SetTextFont(62)
        return output

style1=GetStyleHtt()
style1.cd()
c=MakeCanvas("asdf","asdf",750,750)
c.cd()

#CMSPrelim("CMS Preliminary, 19.7 fb^{-1} at 8 TeV")

file=ROOT.TFile("final.root","r")

categories=["passOS","failOS"]
ncat=2

for i in range (0,ncat):
   QCD=file.Get(categories[i]).Get("QCD")
   W=file.Get(categories[i]).Get("W")
   TT=file.Get(categories[i]).Get("TT")
   DYB=file.Get(categories[i]).Get("DYB")
   DYS=file.Get(categories[i]).Get("DYS120")
   Data=file.Get(categories[i]).Get("data_obs")

   Data.GetXaxis().SetTitle("#bf{m_{vis} (GeV)}")
   Data.GetXaxis().SetTitleSize(0.04)
   Data.GetYaxis().SetTitleSize(0.04)
   Data.GetYaxis().SetTitleOffset(1.8)
   Data.GetYaxis().SetTitle("#bf{Events}")

   #QCD.GetXaxis().SetTitle("#bf{P_{#zeta} (GeV)}")
   #QCD.GetXaxis().SetTitleSize(0.04)
   #QCD.GetYaxis().SetTitleSize(0.04)
   #QCD.GetYaxis().SetTitleOffset(1.8)
   #QCD.GetYaxis().SetTitle("#bf{Events}")

   QCD.SetFillColor(ROOT.EColor.kPink+1)
   W.SetFillColor(ROOT.EColor.kPink-1)
   TT.SetFillColor(ROOT.EColor.kMagenta-6)
   DYB.SetFillColor(ROOT.EColor.kGreen-3)
   DYS.SetFillColor(ROOT.EColor.kOrange-2)
   Data.SetMarkerStyle(20)
   Data.SetMarkerSize(2)
   QCD.SetLineColor(ROOT.EColor.kBlack)
   W.SetLineColor(ROOT.EColor.kBlack)
   TT.SetLineColor(ROOT.EColor.kBlack)
   DYS.SetLineColor(ROOT.EColor.kBlack)
   DYB.SetLineColor(ROOT.EColor.kBlack)
   Data.SetLineColor(ROOT.EColor.kBlack)
   Data.SetLineWidth(2)

   stack=ROOT.THStack("stack","stack")
   stack.Add(QCD)
   stack.Add(W)
   stack.Add(TT)
   stack.Add(DYB)
   stack.Add(DYS)

   Data.SetMaximum(Data.GetMaximum()*1.27)
   Data.Draw("e")
   stack.Draw("histsame")
   Data.Draw("esame")
   #stack.Draw("hist")

   legende=make_legend()
   legende.AddEntry(DYS,"Z#rightarrow#tau#tau","f")
   legende.AddEntry(DYB,"DY others","f")
   legende.AddEntry(TT,"ttbar","f")
   legende.AddEntry(W,"W+jets","f")
   legende.AddEntry(QCD,"QCD multijet","f")
   legende.AddEntry(Data,"Observed","ep")
   legende.Draw()

   l1=add_lumi()
   l1.Draw("same")
   l2=add_CMS()
   l2.Draw("same")

   c.SaveAs("mvis_"+categories[i]+".pdf")
   c.SaveAs("mvis_"+categories[i]+".png")


