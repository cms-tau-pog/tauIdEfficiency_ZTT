
#define ttbar_cxx
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include "TMultiGraph.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <TF1.h>
#include <TDirectoryFile.h>
#include <TRandom3.h>
#include "TLorentzVector.h"
#include "TString.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TKey.h"
#include "THashList.h"
#include "THStack.h"
#include "TPaveLabel.h"
#include "TFile.h"
#include "Corrector.h"
#include "myHelper.h"
#include "tr_Tree.h"
#include<fstream>

using namespace std;

int main(int argc, char** argv) {

    std::string input = *(argv + 1);
    std::string output = *(argv + 2);
    std::string sample = *(argv + 3);
    std::string anti = *(argv + 4);
    std::string isolation = *(argv + 5);
    std::string variable = *(argv + 6);
    float ptmin; float ptmax; float etamin=-10; float etamax=10; float pumin=0; float pumax=200; float tes=0;
    if (argc > 1) {
        tes = atof(argv[7]);
        ptmin = atof(argv[8]);
        ptmax = atof(argv[9]);
        etamin = atof(argv[10]);
        etamax = atof(argv[11]);
        pumin = atof(argv[12]);
        pumax = atof(argv[13]);
    }

    ofstream myfile;
    myfile.open ("eventlist_pass_Comb3L.txt");

    TFile *f_Double = new TFile(input.c_str());
    cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<endl;
    //TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    TTree *arbre = (TTree*) f_Double->Get("RLE_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nbevt");
    float ngen = nbevt->GetBinContent(2);

    float xs=1.0; float weight=1.0; float luminosity=1000.0;//40.24;//2.0400;//5.59 FIXME (luminosity in pb)
    if (sample=="DYB" or sample=="DYS120"){ xs=6025; weight=luminosity*xs/ngen;}
    else if (sample=="TT") {xs=831.76; weight=luminosity*xs/ngen;}
    else if (sample=="W") {xs=61526.7; weight=luminosity*xs/ngen;}
    else if (sample=="QCD") {xs=720648000*0.00042; weight=luminosity*xs/ngen;}
    else if (sample=="Data"){weight=1.0;}

    cout<<"ngen: "<<ngen<<endl;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    arbre->SetBranchAddress("run", &run);
    arbre->SetBranchAddress("lumi", &lumi);
    arbre->SetBranchAddress("evt", &evt);
    arbre->SetBranchAddress("cas", &cas);
    arbre->SetBranchAddress("mu_px", &mu_px);
    arbre->SetBranchAddress("mu_py", &mu_py);
    arbre->SetBranchAddress("mu_pz", &mu_pz);
    arbre->SetBranchAddress("mu_pt", &mu_pt);
    arbre->SetBranchAddress("mu_phi", &mu_phi);
    arbre->SetBranchAddress("mu_eta", &mu_eta);
    arbre->SetBranchAddress("mu_iso", &mu_iso);
    arbre->SetBranchAddress("mu_z", &mu_z);
    arbre->SetBranchAddress("mu_en", &mu_en);
    arbre->SetBranchAddress("mu_charge", &mu_charge);
    arbre->SetBranchAddress("nbtag", &nbtag);
    arbre->SetBranchAddress("tau_charge", &tau_charge);
    arbre->SetBranchAddress("tau_z", &tau_z);
    arbre->SetBranchAddress("tau_px", &tau_px);
    arbre->SetBranchAddress("tau_py", &tau_py);
    arbre->SetBranchAddress("tau_pz", &tau_pz);
    arbre->SetBranchAddress("tau_pt", &tau_pt);
    arbre->SetBranchAddress("tau_eta", &tau_eta);
    arbre->SetBranchAddress("tau_phi", &tau_phi);
    arbre->SetBranchAddress("met_py", &met_py);
    arbre->SetBranchAddress("met_pt", &met_pt);
    arbre->SetBranchAddress("met_px", &met_px);
    arbre->SetBranchAddress("tau_jetPt",&tau_jetPt);
    arbre->SetBranchAddress("tau_jetPx",&tau_jetPx);
    arbre->SetBranchAddress("tau_jetPy",&tau_jetPy);
    arbre->SetBranchAddress("tau_jetPz",&tau_jetPz);
    arbre->SetBranchAddress("tau_jetEn",&tau_jetEn);
    arbre->SetBranchAddress("tau_iso",&tau_iso);
    arbre->SetBranchAddress("tau_PhotonsIso",&tau_PhotonsIso);
    arbre->SetBranchAddress("tau_ChargedIso",&tau_ChargedIso);
    arbre->SetBranchAddress("tau_sumPt",&tau_sumPt);
    arbre->SetBranchAddress("tau_HPSisoLoose3Hits",&tau_HPSisoLoose3Hits);
    arbre->SetBranchAddress("tau_HPSisoMedium3Hits",&tau_HPSisoMedium3Hits);
    arbre->SetBranchAddress("tau_HPSisoTight3Hits",&tau_HPSisoTight3Hits);
    arbre->SetBranchAddress("tau_MVA3oldDMwLTLoose",&tau_MVA3oldDMwLTLoose);
    arbre->SetBranchAddress("tau_MVA3oldDMwLTMedium",&tau_MVA3oldDMwLTMedium);
    arbre->SetBranchAddress("tau_MVA3oldDMwLTTight", &tau_MVA3oldDMwLTTight);
    arbre->SetBranchAddress("tau_MVA3oldDMwLTVLoose",&tau_MVA3oldDMwLTVLoose);
    arbre->SetBranchAddress("tau_MVA3oldDMwLTVTight",&tau_MVA3oldDMwLTVTight);
    arbre->SetBranchAddress("tau_MVA3oldDMwLTVVTight",&tau_MVA3oldDMwLTVVTight);
    arbre->SetBranchAddress("tau_id",&tau_id);
    arbre->SetBranchAddress("tau_en",&tau_en);
    arbre->SetBranchAddress("tau_charge",&tau_charge);
    arbre->SetBranchAddress("tau_dmf",&tau_dmf);
    arbre->SetBranchAddress("tau_en",&tau_en);
    arbre->SetBranchAddress("tau_newDmf",&tau_newDmf);
    arbre->SetBranchAddress("tau_oldDmf",&tau_oldDmf);
    arbre->SetBranchAddress("tau_numChargedSignalCone",&tau_numChargedSignalCone);
    arbre->SetBranchAddress("tau_numChargedIsoCone",&tau_numChargedIsoCone);
    arbre->SetBranchAddress("tau_decayMode",&tau_decayMode);
    arbre->SetBranchAddress("tau_antiEleMVA",&tau_antiEleMVA);
    arbre->SetBranchAddress("tau_antiEleMVA5L",&tau_antiEleMVA5L);
    arbre->SetBranchAddress("tau_antiEleMVA5M",&tau_antiEleMVA5M);
    arbre->SetBranchAddress("tau_antiEleMVA5T",&tau_antiEleMVA5T);
    arbre->SetBranchAddress("tau_antiEleMVA5VL",&tau_antiEleMVA5VL);
    arbre->SetBranchAddress("tau_antiEleMVA5VT",&tau_antiEleMVA5VT);
    arbre->SetBranchAddress("tau_antiMu3L",&tau_antiMu3L);
    arbre->SetBranchAddress("tau_antiMu3T",&tau_antiMu3T);
    arbre->SetBranchAddress("tau_antiMuMVAL",&tau_antiMuMVAL);
    arbre->SetBranchAddress("tau_antiMuMVAM",&tau_antiMuMVAM);
    arbre->SetBranchAddress("tau_antiMuMVAT",&tau_antiMuMVAT);
    arbre->SetBranchAddress("dilepton_veto",&dilepton_veto);
    arbre->SetBranchAddress("extramuon_veto",&extramuon_veto);
    arbre->SetBranchAddress("extraelec_veto",&extraelec_veto);
    arbre->SetBranchAddress("isZmt",&isZmt);
    arbre->SetBranchAddress("aMCatNLO_weight",&aMCatNLO_weight);
    arbre->SetBranchAddress("pu_weight",&pu_weight);
    arbre->SetBranchAddress("trg_weight",&trg_weight);
	cout<<"arbre"<<endl;

   float bins[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250};
   float binsPass[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250};
   //float bins[] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160};//{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
   //float binsPass[] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160};//{1,2,3,4,5,6};
   //float bins[]={-100,-95,-90,-85,-80,-75,-70,-65,-60,-55,-50,-45,-40,-35,-30,-25,-20,-15,-10,-5,0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80};
   //float binsPass[]={-100,-95,-90,-85,-80,-75,-70,-65,-60,-55,-50,-45,-40,-35,-30,-25,-20,-15,-10,-5,0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80};
   int  binnum = sizeof(bins)/sizeof(Float_t) - 1;
   int  binnumPass = sizeof(binsPass)/sizeof(Float_t) - 1;

   TH1F *n70=new TH1F ("n70", "n70", 6,0,6);
   TH1F *mtPassH=new TH1F ("passOSMT","Invariant mass",binnumPass,binsPass);mtPassH->Sumw2();
   TH1F *mtFailH=new TH1F ("failOSMT","Invariant mass",binnum,bins);mtFailH->Sumw2();
   TH1F *mtPassSSH=new TH1F ("passSSMT","Invariant mass",binnumPass,binsPass);mtPassSSH->Sumw2();
   TH1F *mtFailSSH=new TH1F ("failSSMT","Invariant mass",binnum,bins);mtFailSSH->Sumw2();

   int nombre=0;int indexmu=0;int nbmu25=0; int nbextramu=0;
   float n70passOS=0; float n70failOS=0; float n70passSS=0; float n70failSS=0;
   Int_t nentries_wtn = (Int_t) arbre->GetEntries();
   for (Int_t i = 0; i < nentries_wtn; i++) {
        arbre->GetEntry(i);
        if (i % 20000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);
	bool print=false;
        if (nvtx<pumin or nvtx>=pumax) continue;
	if (dilepton_veto) continue;
  	if (extraelec_veto) continue;
	if (extramuon_veto) continue;
	if (nbtag>0) continue;
        bool tauIsolation;
	if (isolation=="comb3T")
           tauIsolation=tau_HPSisoTight3Hits;
        if (isolation=="comb3M")
           tauIsolation=tau_HPSisoMedium3Hits;
        if (isolation=="comb3L")
           tauIsolation=tau_HPSisoLoose3Hits;

	if (anti!="anti" && mu_iso>0.1) continue;
        if (anti=="anti" && mu_iso<0.3) continue;

	float taupt=tau_pt;
	if (tes==-1) taupt*=0.97;
	if (tes==1) taupt*=1.03;
	bool fillOS=false;
	bool fillSS=false;
	if (fabs(tau_eta)<2.3 && tau_antiEleMVA5VL && tau_antiMu3T && tau_oldDmf && taupt>ptmin && taupt<=ptmax){
	    if (tau_charge*mu_charge<0)
		fillOS=true;
	    else
		fillSS=true;
	}
	else continue;
	TLorentzVector mytau; 
	mytau.SetPxPyPzE(tau_px,tau_py,tau_pz,tau_en);

	//****************** Tau energy scale corrections ************************
	if (tes==1){
	   mytau*=1.03;
	   mytau*=1.03;
	}
	if (tes==-1){
           mytau*=0.97;
           mytau*=0.97;
        }

	//***************** Visible mass between the muon and the tau **************
	float mvis=InvarMass_F(mytau.E(),mu_en,mytau.Px(),mu_px,mytau.Py(),mu_py,mytau.Pz(),mu_pz);
	float aweight=weight*pu_weight*trg_weight*aMCatNLO_weight;//Get_SF(0,mu_eta[indexmu],mu_pt[indexmu]);//FIXME
	float poidsW=1.0;

	//********************* Separation between signal and DY others *******************
        if (sample=="DYS120" && (fabs(tau_id)!=15 or !isZmt)) {fillOS=false; fillSS=false;}
        if (sample=="DYB" && fabs(tau_id)==15 && isZmt) {fillOS=false; fillSS=false;}
        
        //********************** MT between muon and MET ***********************************
        float mt=0;
	float mex=met_px; float mey=met_py;
	if (tes==-1){
	   mex=mex+0.03*(mytau.Px()/0.97);
           mey=mey+0.03*(mytau.Py()/0.97);
	}
        if (tes==1){
           mex=mex-0.03*(mytau.Px()/1.03);
           mey=mey-0.03*(mytau.Py()/1.03);
        }
	mt=TMass_F(mu_pt,met_pt,mu_px,mex,mu_py,mey);

	//******************** W reweighting in high MT sideband ****************************
        if (fillOS && mt>80 && tauIsolation) n70passOS+=poidsW*aweight;
	if (fillSS && mt>80 && tauIsolation) n70passSS+=poidsW*aweight;
	if (fillOS && mt>80 && (!tauIsolation)) n70failOS+=poidsW*aweight;
        if (fillSS && mt>80 && (!tauIsolation)) n70failSS+=poidsW*aweight;

	//************************* Pzeta variable ***********************
	float norm_zeta=norm_F(mytau.Px()/mytau.Pt()+mu_px/mu_pt,mytau.Py()/mytau.Pt()+mu_py/mu_pt);
	float x_zeta= (mytau.Px()/mytau.Pt()+mu_px/mu_pt)/norm_zeta;
	float y_zeta= (mytau.Py()/mytau.Pt()+mu_py/mu_pt)/norm_zeta;
	float p_zeta_mis=met_px*x_zeta+met_py*y_zeta;
	float pzeta_vis=(mytau.Px()+mu_px)*x_zeta+(mytau.Py()+mu_py)*y_zeta;
	bool cut_zeta= true;//p_zeta_mis-0.85*pzeta_vis>-30;

	//************************* Fill histograms **********************
	float var=mt;//mvis;//p_zeta_mis-0.85*pzeta_vis;//mvis;
	if (variable=="Ntracks"){
	   var=tau_numChargedIsoCone+tau_numChargedSignalCone;
	}
        if (fillOS && cut_zeta && mt<550 && tauIsolation && fabs(tau_eta)>=etamin && fabs(tau_eta)<etamax ) {//Pass OS
            mtPassH->Fill(var,aweight*poidsW);
	    myfile<<evt<<" "<<var<<endl;
	}
        if (fillSS && cut_zeta && mt<550 &&  tauIsolation && fabs(tau_eta)>=etamin && fabs(tau_eta)<etamax ) //Pass SS
            mtPassSSH->Fill(var,aweight*poidsW);
        if (fillOS && cut_zeta && mt<550 && !tauIsolation && fabs(tau_eta)>=etamin && fabs(tau_eta)<etamax ) //Fail OS
            mtFailH->Fill(var,aweight*poidsW);
        if (fillSS && cut_zeta && mt<550 && !tauIsolation && fabs(tau_eta)>=etamin && fabs(tau_eta)<etamax ) //Fail SS
            mtFailSSH->Fill(var,aweight*poidsW);
				
    } // end of loop over events
    cout<<"n70: "<<n70passOS<<" "<<n70failOS<<" "<<n70passSS<<" "<<n70failSS<<endl;
    n70->SetBinContent(1,n70passOS);
    n70->SetBinContent(2,n70failOS);
    n70->SetBinContent(3,n70passSS);
    n70->SetBinContent(4,n70failSS);
    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    n70->Write();

    TString postfix="";
    if (tes==1)
	postfix="_TESUp";
    if (tes==-1)
        postfix="_TESDown";
    TDirectory *passOS =fout->mkdir("passOS");
    passOS->cd();
    mtPassH->SetBinContent(binnum+1,0);
    mtPassH->SetBinError(binnum+1,0);
    mtPassH->SetBinContent(0,0);
    mtPassH->SetBinError(0,0);
    for (int l=0; l<binnum;++l){
	if (mtPassH->GetBinContent(l+1)<0)
	   mtPassH->SetBinContent(l+1,0);
    }
    mtPassH->SetName(sample.c_str()+postfix);
    mtPassH->Write();
    TDirectory *failOS =fout->mkdir("failOS");
    failOS->cd();
    mtFailH->SetBinContent(binnum+1,0);
    mtFailH->SetBinError(binnum+1,0);
    mtFailH->SetBinContent(0,0);
    mtFailH->SetBinError(0,0);
    for (int l=0; l<binnum;++l){
        if (mtFailH->GetBinContent(l+1)<0)
           mtFailH->SetBinContent(l+1,0);
    }
    mtFailH->SetName(sample.c_str()+postfix);
    mtFailH->Write();
    TDirectory *passSS =fout->mkdir("passSS");
    passSS->cd();
    mtPassSSH->SetBinContent(binnum+1,0);
    mtPassSSH->SetBinError(binnum+1,0);
    mtPassSSH->SetBinContent(0,0);
    mtPassSSH->SetBinError(0,0);
    for (int l=0; l<binnum;++l){
        if (mtPassSSH->GetBinContent(l+1)<0)
           mtPassSSH->SetBinContent(l+1,0);
    }
    mtPassSSH->SetName(sample.c_str()+postfix);
    mtPassSSH->Write();
    TDirectory *failSS =fout->mkdir("failSS");
    failSS->cd();
    mtFailSSH->SetBinContent(binnum+1,0);
    mtFailSSH->SetBinError(binnum+1,0);
    mtFailSSH->SetBinContent(0,0);
    mtFailSSH->SetBinError(0,0);
    for (int l=0; l<binnum;++l){
        if (mtFailSSH->GetBinContent(l+1)<0)
           mtFailSSH->SetBinContent(l+1,0);
    }
    mtFailSSH->SetName(sample.c_str()+postfix);
    mtFailSSH->Write();
    myfile.close();
} 


