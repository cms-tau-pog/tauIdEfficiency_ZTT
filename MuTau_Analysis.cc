#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TTree.h"
#include "TChain.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TRandom.h"
#include "TLorentzVector.h"
#include "TRandom3.h"
#include "makeHisto.h"
#include "mutau_Tree.h"
#include "OfflineProducerHelper.h"

int main(int argc, char** argv) {

    using namespace std;
    myMap1 = new map<string, TH1F*>();
    myMap2 = new map<string, TH2F*>();

    string status_sample = *(argv + 1);
    bool isMC = false;
    bool isData = false;
    if (status_sample.compare("mc") == 0) isMC = true;
    if (status_sample.compare("data") == 0) isData = true;
    string out = *(argv + 2);
    string outname= out;
    TFile *fout = TFile::Open(outname.c_str(), "RECREATE");

    //TFile *fout = TFile::Open("test.root", "RECREATE");

    //TFile* fIn = new TFile ("ntuple29juillet.root");
    string in = *(argv + 3);
    string inname= in;
    TFile *fIn = TFile::Open(inname.c_str());
    TTree* treePtr = (TTree*) fIn->Get("HTauTauTree/HTauTauTree");
    TH1F *evCounter = (TH1F*) fIn->Get("HTauTauTree/Counters");
    HTauTauTree* tree = new HTauTauTree (treePtr);
    OfflineProducerHelper helper;

    //#################################################################################################
    TTree *Run_Tree = new TTree("RLE_tree", "RLE_tree");
    Run_Tree->SetDirectory(0);
    Run_Tree->Branch("run", &run, "run/I");
    Run_Tree->Branch("lumi", &lumi, "lumi/I");
    Run_Tree->Branch("evt", &evt, "evt/I");

    Run_Tree->Branch("NUP", &NUP, "NUP/I");
    Run_Tree->Branch("dilepton_veto", &dilepton_veto, "dilepton_veto/O");
    Run_Tree->Branch("extraelec_veto", &extraelec_veto, "extraelec_veto/O");
    Run_Tree->Branch("extramuon_veto", &extramuon_veto, "extramuon_veto/O");
    Run_Tree->Branch("isZmt", &isZmt, "isZmt/O");

    Run_Tree->Branch("trg_weight", &trg_weight, "trg_weight/F");
    Run_Tree->Branch("pu_weight", &pu_weight, "pu_weight/F");
    Run_Tree->Branch("aMCatNLO_weight", &aMCatNLO_weight, "aMCatNLO_weight/F");

    Run_Tree->Branch("mu_pt", &mu_pt, "mu_pt/F");
    Run_Tree->Branch("mu_en", &mu_en, "mu_en/F");
    Run_Tree->Branch("mu_px", &mu_px, "mu_px/F");
    Run_Tree->Branch("mu_py", &mu_py, "mu_py/F");
    Run_Tree->Branch("mu_pz", &mu_pz, "mu_pz/F");
    Run_Tree->Branch("mu_phi", &mu_phi, "mu_phi/F");
    Run_Tree->Branch("mu_eta", &mu_eta, "mu_eta/F");
    Run_Tree->Branch("mu_charge", &mu_charge, "mu_charge/F");
    Run_Tree->Branch("mu_d0", &mu_d0, "mu_d0/F");
    Run_Tree->Branch("mu_dZ", &mu_dZ, "mu_dZ/F");
    Run_Tree->Branch("mu_iso", &mu_iso, "mu_iso/F");

    Run_Tree->Branch("tau_pt", &tau_pt, "tau_pt/F");
    Run_Tree->Branch("tau_en", &tau_en, "tau_en/F");
    Run_Tree->Branch("tau_phi", &tau_phi, "tau_phi/F");
    Run_Tree->Branch("tau_eta", &tau_eta, "tau_eta/F");
    Run_Tree->Branch("tau_px", &tau_px, "tau_px/F");
    Run_Tree->Branch("tau_py", &tau_py, "tau_py/F");
    Run_Tree->Branch("tau_pz", &tau_pz, "tau_pz/F");
    Run_Tree->Branch("tau_charge", &tau_charge, "tau_charge/F");
    Run_Tree->Branch("tau_d0", &tau_d0, "tau_d0/F");
    Run_Tree->Branch("tau_dZ", &tau_dZ, "tau_dZ/F");
    Run_Tree->Branch("tau_HPSisoLoose3Hits", &tau_HPSisoLoose3Hits, "tau_HPSisoLoose3Hits/O");
    Run_Tree->Branch("tau_HPSisoMedium3Hits", &tau_HPSisoMedium3Hits, "tau_HPSisoMedium3Hits/O");
    Run_Tree->Branch("tau_HPSisoTight3Hits", &tau_HPSisoTight3Hits, "tau_HPSisoTight3Hits/O");
    Run_Tree->Branch("tau_antiEleMVA5L", &tau_antiEleMVA5L, "tau_antiEleMVA5L/O");
    Run_Tree->Branch("tau_antiEleMVA5M", &tau_antiEleMVA5M, "tau_antiEleMVA5M/O");
    Run_Tree->Branch("tau_antiEleMVA5T", &tau_antiEleMVA5T, "tau_antiEleMVA5T/O");
    Run_Tree->Branch("tau_antiEleMVA5VL", &tau_antiEleMVA5VL, "tau_antiEleMVA5VL/O");
    Run_Tree->Branch("tau_antiEleMVA5VT", &tau_antiEleMVA5VT, "tau_antiEleMVA5VT/O");
    Run_Tree->Branch("tau_antiMu3L", &tau_antiMu3L, "tau_antiMu3L/O");
    Run_Tree->Branch("tau_antiMu3T", &tau_antiMu3T, "tau_antiMu3T/O");
    Run_Tree->Branch("tau_newDmf", &tau_newDmf, "tau_newDmf/O");
    Run_Tree->Branch("tau_oldDmf", &tau_oldDmf, "tau_oldDmf/O");
    Run_Tree->Branch("tau_id", &tau_id, "tau_id/I");
    Run_Tree->Branch("tau_numChargedIsoCone", &tau_numChargedIsoCone, "tau_numChargedIsoCone/I");
    Run_Tree->Branch("tau_numChargedSignalCone", &tau_numChargedSignalCone, "tau_numChargedSignalCone/I");

    Run_Tree->Branch("met_pt", &met_pt, "met_pt/F");
    Run_Tree->Branch("met_px", &met_px, "met_px/F");
    Run_Tree->Branch("met_py", &met_py, "met_py/F");
    Run_Tree->Branch("met_phi", &met_phi, "met_phi/F");
    Run_Tree->Branch("nbtag", &nbtag, "nbtag/I");

    //#################################################################################################
    //
    /*std::vector<string> fileNames;
    for (int f = 3; f < argc; f++) {
                fileNames.push_back(*(argv + f));
                cout << fileNames[f - 3] << "\t";
    }
    string status_sample = *(argv + 1);
    bool isMC = false;
    bool isData = false;
    if (status_sample.compare("mc") == 0) isMC = true;
    if (status_sample.compare("data") == 0) isData = true;
    string out = *(argv + 2);
    string outname= out;
    TFile *fout = TFile::Open(outname.c_str(), "RECREATE");*/
    for (int iEntry = 0; iEntry < tree->GetEntries() ; iEntry++)
    {
        tree->GetEntry(iEntry);
	bool print=false;

	plotFill("nbevt",0,9,0,9);
	plotFill("nbevt",1,9,0,9,tree->aMCatNLOweight);

	   bool PassMuTrigger=false;
	   if (print) cout<<"Evenement n°"<<tree->EventNumber<<endl;
	   if (helper.IsTriggerFired(tree->triggerbit,helper.FindTriggerNumber("HLT_IsoMu24_eta2p1_v1"))) PassMuTrigger=true;
           if (helper.IsTriggerFired(tree->triggerbit,helper.FindTriggerNumber("HLT_IsoMu24_eta2p1_v2"))) PassMuTrigger=true;
	   //cout<<helper.IsTriggerFired(tree->triggerbit,helper.FindTriggerNumber("HLT_IsoMu24_eta2p1_v1"))<<helper.IsTriggerFired(tree->triggerbit,helper.FindTriggerNumber("HLT_IsoMu24_eta2p1_v2"))<<helper.IsTriggerFired(tree->triggerbit,helper.FindTriggerNumber("HLT_IsoMu24_eta2p1_IterTrk02_v1"))<<helper.IsTriggerFired(tree->triggerbit,helper.FindTriggerNumber("HLT_IsoMu24_eta2p1_IterTrk02_v2"))<<endl;
	   //if (helper.IsTriggerFired(tree->triggerbit,helper.FindTriggerNumber("HLT_IsoMu24_eta2p1_IterTrk02_v1"))) PassMuTrigger=true;
	   //if (helper.IsTriggerFired(tree->triggerbit,helper.FindTriggerNumber("HLT_IsoMu24_eta2p1_IterTrk02_v2"))) PassMuTrigger=true;
	   if (!PassMuTrigger) continue;
	   bool isData=false; int mucharge=1; int elecharge=1; bool jet_inbetween=false;
	   bool isPair=false; 
	   int dau1index=0; int dau2index=0; int pairindex=-1;
	   float metx=0; float mety=0;
           for (int iMoth = 0; iMoth < tree->mothers_px->size() && !isPair; iMoth++)
           {
              dau1index = tree->indexDau1->at(iMoth);
              dau2index = tree->indexDau2->at(iMoth);
	      if (print) cout<<"mutau decay"<<endl;
	      if (fabs(tree->particleType->at(dau1index) - tree->particleType->at(dau2index)) !=2) continue; //mutau
	      TLorentzVector dau1;
              TLorentzVector dau2;
	      dau1.SetPxPyPzE(tree->daughters_px->at(dau1index),tree->daughters_py->at(dau1index),tree->daughters_pz->at(dau1index),tree->daughters_e->at(dau1index));
	      dau2.SetPxPyPzE(tree->daughters_px->at(dau2index),tree->daughters_py->at(dau2index),tree->daughters_pz->at(dau2index),tree->daughters_e->at(dau2index));
//*****************************************
	      /*bool Zmt=false;
              int tauid=0; int indice_gen=0;
              if (isMC){
                 for (int iGen = 0; iGen < tree->genpart_px->size(); iGen++){
                    if (tree->genpart_pdg->at(iGen)==23){
                       if (tree->genpart_HZDecayMode->at(iGen)==0)
                          Zmt=true;
                   }
                 }
                 float newdr=0.5;
                 if (Zmt){
                    for (int iGen = 2; iGen < tree->genpart_pdg->size(); iGen++){
                       TLorentzVector g;
                       g.SetPxPyPzE(tree->genpart_px->at(iGen),tree->genpart_py->at(iGen),tree->genpart_pz->at(iGen),tree->genpart_e->at(iGen));
                       if ((fabs(tree->genpart_pdg->at(iGen))==11 or fabs(tree->genpart_pdg->at(iGen))==13 or fabs(tree->genpart_pdg->at(iGen))==15) && g.DeltaR(dau2)<0.5 && g.DeltaR(dau2)<newdr){
                          newdr=g.DeltaR(dau2);
                          indice_gen=iGen;
                       }
                    }
                    if (indice_gen==0){
                       for (int iGen = 2; iGen < tree->genpart_pdg->size(); iGen++){
                          TLorentzVector g;
                          g.SetPxPyPzE(tree->genpart_px->at(iGen),tree->genpart_py->at(iGen),tree->genpart_pz->at(iGen),tree->genpart_e->at(iGen));
                          if ((fabs(tree->genpart_pdg->at(iGen))<30) && g.DeltaR(dau2)<0.5 && g.DeltaR(dau2)<newdr){
                             newdr=g.DeltaR(dau2);
                             indice_gen=iGen;
                          }
                       }
                    }
                    tauid=tree->genpart_pdg->at(indice_gen);
                 }//end Zmt
		 if (Zmt && fabs(tauid)==15){
		     plotFill("Preselection bias",1,10,0,10);
		     bool overlapMuon1=false;
		     TLorentzVector lep1;
                     for (int iDau = 0; iDau < tree->daughters_px->size(); iDau++){
                         lep1.SetPxPyPzE(tree->daughters_px->at(iDau),tree->daughters_py->at(iDau),tree->daughters_pz->at(iDau),tree->daughters_e->at(iDau));
                         if (Overlap_2(dau2,lep1) && tree->particleType->at(iDau)==0 && fabs(lep.Eta())<2.4 && lep.Pt()>5 && ((tree->daughters_typeOfMuon->at(iDau) >> 0) & 1))
                              overlapMuon1=true;
                     }
		     if (!overlapMuon1 && tree->daughters_againstMuonTight3->at(dau2index) && tree->daughters_againstElectronVLooseMVA5->at(dau2index) && tree->daughters_decayModeFindingOldDMs->at(dau2index) && fabs(tree->dz->at(dau2index))<0.2)
			plotFill("Preselection bias",2,10,0,10);
		    if (overlapMuon1 or !tree->daughters_againstMuonTight3->at(dau2index) or !tree->daughters_againstElectronVLooseMVA5->at(dau2index) or !tree->daughters_decayModeFindingOldDMs->at(dau2index) or fabs(tree->dz->at(dau2index))>0.2)
                        plotFill("Preselection bias",3,10,0,10);
                    if ((overlapMuon1 or !tree->daughters_againstMuonTight3->at(dau2index) or !tree->daughters_againstElectronVLooseMVA5->at(dau2index) or !tree->daughters_decayModeFindingOldDMs->at(dau2index) or fabs(tree->dz->at(dau2index))>0.2) && tree->daughters_byLooseCombinedIsolationDeltaBetaCorr3Hits->at(dau2index))
                        plotFill("Preselection bias",4,10,0,10);
                    if ((overlapMuon1 or !tree->daughters_againstMuonTight3->at(dau2index) or !tree->daughters_againstElectronVLooseMVA5->at(dau2index) or !tree->daughters_decayModeFindingOldDMs->at(dau2index) or fabs(tree->dz->at(dau2index))>0.2) && tree->daughters_byMediumCombinedIsolationDeltaBetaCorr3Hits->at(dau2index))
                        plotFill("Preselection bias",5,10,0,10);
                    if ((overlapMuon1 or !tree->daughters_againstMuonTight3->at(dau2index) or !tree->daughters_againstElectronVLooseMVA5->at(dau2index) or !tree->daughters_decayModeFindingOldDMs->at(dau2index) or fabs(tree->dz->at(dau2index))>0.2) && tree->daughters_byTightCombinedIsolationDeltaBetaCorr3Hits->at(dau2index))
                        plotFill("Preselection bias",6,10,0,10);
		 }
              }*/
//***************************************************
	      if (print) cout<<"Trigger filter"<<endl;
              bool matchMuTrigger=helper.IsTriggerFired(tree->daughters_FilterFired->at(dau1index),helper.FindTriggerNumber("HLT_IsoMu24_eta2p1_v1"));
              //if (!matchMuTrigger) continue;
	      if (print) cout<<"Overlap"<<endl;
	      if (Overlap_2(dau1,dau2)) continue;//Overlap
	      if (print) cout<<"Overlap global muon"<<endl;
	      TLorentzVector lep;
	      bool overlapMuon=false;
	      for (int iDau = 0; iDau < tree->daughters_px->size(); iDau++){
                  lep.SetPxPyPzE(tree->daughters_px->at(iDau),tree->daughters_py->at(iDau),tree->daughters_pz->at(iDau),tree->daughters_e->at(iDau));
       		  if (Overlap_2(dau2,lep) && tree->particleType->at(iDau)==0 && fabs(lep.Eta())<2.4 && lep.Pt()>5 && ((tree->daughters_typeOfMuon->at(iDau) >> 0) & 1))
		      overlapMuon=true;
	      }
	      if (overlapMuon) continue;

	      if (print) cout<<"dxy"<<endl;
	      if (fabs(tree->dxy->at(dau1index))>0.045) continue;//Dxy
	      if (print) cout<<"dz"<<endl;
              if (fabs(tree->dz->at(dau1index))>0.2 or fabs(tree->dz->at(dau2index))>0.2) continue;//Dz
	      if (print) cout<<"pt"<<endl;
	      if (dau1.Pt()<25 or dau2.Pt()<20) continue;//Pt
	      if (print) cout<<"eta"<<endl;
	      if (fabs(dau1.Eta())>2.1 or fabs(dau2.Eta())>2.3) continue;//Eta
	      if (print) cout<<"muon ID"<<endl;
	      if (!((tree->daughters_muonID->at(dau1index) >> 2) & 1)) continue;
	      if (tree->daughters_trackRefPt->at(dau2index)<5) continue;
       	      pairindex=iMoth; 
	      isPair=true;
	  }
	  if (!isPair) continue;	
          metx=tree->METx->at(pairindex);
          mety=tree->METy->at(pairindex);
	  TLorentzVector tau1;
	  TLorentzVector tau2;
          tau2.SetPxPyPzE(tree->daughters_px->at(dau2index),tree->daughters_py->at(dau2index),tree->daughters_pz->at(dau2index),tree->daughters_e->at(dau2index));
          tau1.SetPxPyPzE(tree->daughters_px->at(dau1index),tree->daughters_py->at(dau1index),tree->daughters_pz->at(dau1index),tree->daughters_e->at(dau1index));
	  int nbJets=0; int nJets=0; int nJets20=0;
	  int b1_index=-1; int b2_index=-1; int j1_index=-1; int j2_index=-1;
	  TLorentzVector jetb1, jetb2, jet1, jet2;
          for (int iJet = 0; iJet < tree->bDiscriminator->size(); iJet++)
          {
	    TLorentzVector jet(tree->jets_px->at(iJet),tree->jets_py->at(iJet),tree->jets_pz->at(iJet),tree->jets_e->at(iJet));
	    if (Overlap_3(tau1,tau2,jet)) continue;
	    if (tree->PFjetID->at(iJet)==0) continue;
	    if (tree->bCSVscore->at(iJet)>0.814 && jet.Pt()>20 && fabs(jet.Eta()<2.4)){
		nbJets++;
	     	if (nbJets==1) {
	     	    jetb1.SetPxPyPzE(jet.Px(),jet.Py(),jet.Pz(),jet.E());
	     	    b1_index=iJet;
	     	}
	        else if (nbJets==2){
	           jetb2.SetPxPyPzE(jet.Px(),jet.Py(),jet.Pz(),jet.E());
	            b2_index=iJet;
	        }
	    }
            if (jet.Pt()>20 && fabs(jet.Eta()<4.7)){
                nJets20++;
                if (nJets20==1){
	           jet1.SetPxPyPzE(jet.Px(),jet.Py(),jet.Pz(),jet.E());
	           j1_index=iJet;
	        }
                else if (nJets20==2){
	           jet2.SetPxPyPzE(jet.Px(),jet.Py(),jet.Pz(),jet.E());
	           j2_index=iJet;
	        }
             }
             if (jet.Pt()>30 && fabs(jet.Eta()<4.7)){
                 nJets++;
	     }
          }
	  TLorentzVector met(metx,mety,0,0);
	  fillTree(Run_Tree,tree,iEntry,pairindex,dau1index,dau2index,j1_index,j2_index,b1_index,b2_index,met,nJets,nJets20,nbJets,isMC);
 //      }
    }//loop over events
    fout->cd();
    Run_Tree->Write();

    map<string, TH1F*>::const_iterator iMap1 = myMap1->begin();
    map<string, TH1F*>::const_iterator jMap1 = myMap1->end();

    for (; iMap1 != jMap1; ++iMap1)
        nplot1(iMap1->first)->Write();

    map<string, TH2F*>::const_iterator iMap2 = myMap2->begin();
    map<string, TH2F*>::const_iterator jMap2 = myMap2->end();

    for (; iMap2 != jMap2; ++iMap2)
        nplot2(iMap2->first)->Write();

    fout->Close();

    return 0;
}

