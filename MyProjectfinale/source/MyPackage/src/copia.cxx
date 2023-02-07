#include<iostream>
#include <cmath>
#include "MyDummyPackageAlg.h"
#include <stdlib.h> 
#include "xAODEventInfo/EventInfo.h"
#include "xAODTracking/TrackParticle.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODJet/JetContainer.h"
#include <AsgTools/MessageCheck.h>
#include "AsgTools/AnaToolHandle.h"
#include "JetCalibTools/IJetCalibrationTool.h"
#include "xAODRootAccess/TStore.h"
#include "xAODEgamma/Photon.h"
#include <string.h> 
#include <string> 
#include "xAODEgamma/PhotonContainer.h"
#include "xAODTruth/TruthEvent.h"
#include "xAODTruth/TruthEventContainer.h"
#include "xAODTruth/TruthParticle.h"
#include "xAODTruth/TruthParticleContainer.h"
#include "xAODTruth/TruthVertexContainer.h"


#define DARK_PHOTON_PDGID 3000001

MyDummyPackageAlg::MyDummyPackageAlg( const std::string& name, ISvcLocator* pSvcLocator ) : AthAnalysisAlgorithm( name, pSvcLocator ){  
}


MyDummyPackageAlg::~MyDummyPackageAlg() {}


StatusCode MyDummyPackageAlg::initialize() {
  ATH_MSG_INFO ("Initializing " << name() << "...");
  ////////////////////////////////////////////////////////////////////

  EMFrac1 =new TH1D("EMFrac1","EMFrac1",100,0,1.4 );
  CHECK( histSvc()->regHist("/MYSTREAM/ EMFrac1", EMFrac1));
  EMFrac1->SetTitle("Nevents vs EMFrac1 ;EMFrac1; NEvents");


  EMFrac2 =new TH1D("EMFrac2","EMFrac2",100,0,1.4 );
  CHECK( histSvc()->regHist("/MYSTREAM/ EMFrac2", EMFrac2));
  EMFrac2->SetTitle("Nevents vs EMFrac2 ;EMFrac2; NEvents");

  ANA_CHECK (m_trigDecisionTool.initialize());
  m_trigDecisionTool.setTypeAndName("Trig::TrigDecisionTool/TrigDecisionTool");

  Lxypercentage_vs_Pt=new TH2D("Lxypercentage_vs_Pt","Lxypercentage_vs_Pt",10,0,1000 ,50,1000,4500);
  CHECK( histSvc()->regHist("/MYSTREAM/ Lxypercentage_vs_Pt", Lxypercentage_vs_Pt));
  Lxypercentage_vs_Pt->SetTitle("Lxypercentage vs Pt ;Pt; Lxy");

  Lxy_vs_Pt =new TH2D("Lxy_vs_Pt","Lxy_vs_Pt",10,0,1000 ,50,1000,4500);
  CHECK( histSvc()->regHist("/MYSTREAM/ Lxy_vs_Pt", Lxy_vs_Pt));
  Lxy_vs_Pt->SetTitle("Lxy vs Pt ;Pt; Lxy");

  Histo1 =new TH1D("Histo1","Histo1",100,0,1000 );
  CHECK( histSvc()->regHist("/MYSTREAM/ Histo1", Histo1));
  Histo1->SetTitle("Nevents vs Pt ;Pt; NEvents");

  Efficiency=new TH1D("Efficiency","Efficiency",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ Efficiency",  Efficiency));
  Efficiency->SetTitle("Efficiency vs Pt ;Pt; NEvents");

  EfficiencyTotal=new TH1D("EfficiencyTotal","EfficiencyTotal",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ EfficiencyTotal",  EfficiencyTotal));
  EfficiencyTotal->SetTitle("EfficiencyTotal vs Pt ;Pt; NEvents");

  Efficiency2=new TH1D("Efficiency2","Efficiency2",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ Efficiency2",  Efficiency2));
  Efficiency2->SetTitle("Efficiency2 vs Pt ;Pt; NEvents");

  EfficiencyTotal2=new TH1D("EfficiencyTotal2","EfficiencyTotal2",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ EfficiencyTotal2",  EfficiencyTotal2));
  EfficiencyTotal2->SetTitle("EfficiencyTotal2 vs Pt ;Pt; NEvents");


  ///////////////////////////////////////////////////////////////////////////////////////////////


  Histo_Inclusive=new TH1D("Histo_Inclusive","Histo_Inclusive",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ Histo_Inclusive",  Histo_Inclusive));
  Histo_Inclusive->SetTitle("Histo_Inclusive vs Pt ;Pt; NEvents");

  Histo_TriggerFailed=new TH1D("Histo_TriggerFailed","Histo_TriggerFailed",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ Histo_TriggerFailed",  Histo_TriggerFailed));
  Histo_TriggerFailed->SetTitle("Histo_TriggerFailed vs Pt ;Pt; NEvents");

  Histo_TriggerPassed=new TH1D("Histo_TriggerPassed","Histo_TriggerPassed",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ Histo_TriggerPassed",  Histo_TriggerPassed));
  Histo_TriggerPassed->SetTitle("Histo_TriggerPassed vs Pt ;Pt; NEvents");

  Histo_FailedCHF=new TH1D("Histo_FailedCHF","Histo_FailedCHF",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ Histo_FailedCHF",  Histo_FailedCHF));
  Histo_FailedCHF->SetTitle("Histo_FailedCHF vs Pt ;Pt; NEvents");

  Histo_PassedCHF=new TH1D("Histo_PassedCHF","Histo_PassedCHF",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ Histo_PassedCHF",  Histo_PassedCHF));
  Histo_PassedCHF->SetTitle("Histo_PassedCHF vs Pt ;Pt; NEvents");
  
  Histo_FailedEMF=new TH1D("Histo_FailedEMF","Histo_FailedEMF",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ Histo_FailedEMF",  Histo_FailedEMF));
  Histo_FailedEMF->SetTitle("Histo_FailedEMF vs Pt ;Pt; NEvents");

  Histo_PassedEMF=new TH1D("Histo_PassedEMF","Histo_PassedEMF",40,0,400 );
  CHECK( histSvc()->regHist("/MYSTREAM/ Histo_PassedEMF",  Histo_PassedEMF));
  Histo_PassedEMF->SetTitle("Histo_PassedEMF vs Pt ;Pt; NEvents");


  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  Histo_Electron = new TH1D("Histo_Electron","Histo_Electron",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_Electron",Histo_Electron ) );
  Histo_Electron->SetTitle("Histo_Electron;EMfrac;Number_Events");

  Histo_Muon = new TH1D("Histo_Muon","Histo_Muon",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_Muon",Histo_Muon ) );
  Histo_Muon->SetTitle("Histo_Muon;EMfrac;Number_Events");

  Histo_QCD = new TH1D("Histo_QCD","Histo_QCD",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_QCD",Histo_QCD) );
  Histo_QCD->SetTitle("Histo_QCD; EMfrac;Number_Events");

  Histo_child1 = new TH1D("Histo_child1","Histo_child1",100,0,1000  );
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_child1",Histo_child1 ) );
  Histo_child1->SetTitle("Histo_child1;NumPDG;Number_Events");
 
  Histo_child1_1 = new TH1D("Histo_child1_1","Histo_child1_1",100 ,0,1000  );
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_child1_1",Histo_child1_1 ) );
  Histo_child1_1->SetTitle("Histo_child1_1;NumPDG;Number_Events");

  Histo_child1_2 = new TH1D("Histo_child1_2","Histo_child1_2",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_child1_2",Histo_child1_2) );
  Histo_child1_2->SetTitle("Histo_child1_2;NumPDG;Number_Events");

  ///////////////
  
  Histo_EMfrac= new TH1D("Histo_EMfrac","Histo_EMfrac",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_EMfrac ",Histo_EMfrac ) );
  Histo_EMfrac->SetTitle("Histo_EMfrac;EMfrac;Number_Events");

  Histo_mu_1= new TH1D("Histo_mu_1","Histo_mu_1",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_mu_1 ",Histo_mu_1 ) );
  Histo_mu_1->SetTitle("Histo_mu_1;EMfrac;Number_Events");

  Histo_mu_2= new TH1D("Histo_mu_2","Histo_mu_2",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_mu_2 ",Histo_mu_2 ) );
  Histo_mu_2->SetTitle("Histo_mu_2;EMfrac;Number_Events");

  Histo_mu_3= new TH1D("Histo_mu_3","Histo_mu_3",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_mu_3 ",Histo_mu_3 ) );
  Histo_mu_3->SetTitle("Histo_mu_3;EMfrac;Number_Events");

  Histo_mu_4= new TH1D("Histo_mu_4","Histo_mu_4",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_mu_4 ",Histo_mu_4 ) );
  Histo_mu_4->SetTitle("Histo_mu_4;EMfrac;Number_Events");



  HistoPi0_EMfrac= new TH1D("HistoPi0_EMfrac","HistoPi0_EMfrac",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/HistoPi0_EMfrac ",HistoPi0_EMfrac ) );
  HistoPi0_EMfrac->SetTitle("HistoPi0_EMfrac;EMfrac;Number_Events");


  EMFrac_vs_Pt=new TH2D("EMFrac_vs_Pt","EMFrac_vs_Pt",100,0,1000,100,0,1);
  CHECK( histSvc()->regHist("/MYSTREAM/EMFrac_vs_Pt", EMFrac_vs_Pt) );
  EMFrac_vs_Pt->SetTitle("EMFrac vs Pt ;Pt;EMFrac");

  /////////////////////////////////////  

  h_DP_R= new TH1D("h_DP_R","h_DP_R",10,0.,0.4);
  CHECK( histSvc()->regHist("/MYSTREAM/h_DP_R ",h_DP_R ) );
  h_DP_R->SetTitle("h_DP_R;R;Number_Events");


  h_DP_Pt= new TH1D("h_DP_Pt","h_DP_Pt",100,0.,1000000.0);
  CHECK( histSvc()->regHist("/MYSTREAM/h_DP_Pt ",h_DP_Pt ) );
  h_DP_Pt->SetTitle("h_DP_Pt;Pt;Number_Events");

  h_DP_eta= new TH1D("h_DP_eta","h_DP_eta",80,-8.0,8.0);
  CHECK( histSvc()->regHist("/MYSTREAM/h_DP_eta ",h_DP_eta ) );
  h_DP_eta->SetTitle("h_DP_eta;eta;Number_Events");

  h_DP_phi= new TH1D("h_DP_phi","h_DP_phi",60,-3.5,3.5);
  CHECK( histSvc()->regHist("/MYSTREAM/h_DP_phi ",h_DP_phi ) );
  h_DP_phi->SetTitle("h_DP_phi;phi;Number_Events");

  h_DP_Lxy=new TH1D("h_DP_Lxy","h_DP_Lxy",50,0,15000);
  CHECK( histSvc()->regHist("/MYSTREAM/h_DP_Lxy ",h_DP_Lxy ) );
  h_DP_Lxy->SetTitle("h_DP_Lxy;Lxy;Number_Events");

  h_DP_Lxy2=new TH1D("h_DP_Lxy2","h_DP_Lxy2",50,0,15000);
  CHECK( histSvc()->regHist("/MYSTREAM/h_DP_Lxy2 ",h_DP_Lxy2 ) );
  h_DP_Lxy2->SetTitle("h_DP_Lxy2;Lxy2;Number_Events");


  /////////////////////////////////////////////////
  h_DP_R2= new TH1D("h_DP_R2","h_DP_R2",10,0.,0.4);//10 0. 0.4
  CHECK( histSvc()->regHist("/MYSTREAM/h_DP_R2 ",h_DP_R2 ) );
  h_DP_R2->SetTitle("h_DP_R2;R2;Number_Events");


  h_DP_Pt2= new TH1D("h_DP_Pt2","h_DP_Pt2",100,0.,1000000.0);
  CHECK( histSvc()->regHist("/MYSTREAM/h_DP_Pt2 ",h_DP_Pt2 ) );
  h_DP_Pt2->SetTitle("h_DP_Pt2;Pt;Number_Events");

  h_DP_eta2= new TH1D("h_DP_eta2","h_DP_eta2",80,-8.0,8.0);
  CHECK( histSvc()->regHist("/MYSTREAM/h_DP_eta2 ",h_DP_eta2 ) );
  h_DP_eta2->SetTitle("h_DP_eta2;eta;Number_Events");

  h_DP_phi2= new TH1D("h_DP_phi2","h_DP_phi2",60,-3.5,3.5);
  CHECK( histSvc()->regHist("/MYSTREAM/h_DP_phi2 ",h_DP_phi2 ) );
  h_DP_phi2->SetTitle("h_DP_phi2;phi;Number_Events");

  
  Division= new TH1D("Division=","Division=",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/Division ",Division ) );
  Division->SetTitle("Division;Pt;Number_Events");
  

  Histo_evnts_vs_pt= new TH1D("Histo_evnts_vs_pt","Histo_evnts_vs_pt",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_evnts_vs_pt ", Histo_evnts_vs_pt ) );
  Histo_evnts_vs_pt->SetTitle("Histo_evnts_vs_pt;Pt;Number_Events");
  //////
  Ntracks=new TH2D("Ntracks","Ntracks",100,0,1000,100,0,100);
  CHECK( histSvc()->regHist("/MYSTREAM/Ntracks", Ntracks) );
  Ntracks->SetTitle("Ntracks vs Pt ;Pt;Ntracks");

  NtracksPercentage_vs_Pt=new TH2D("NtracksPercentage_vs_Pt","NtracksPercentage_vs_Pt",100,0,1000,100,0,100);
  CHECK( histSvc()->regHist("/MYSTREAM/NtracksPercentage_vs_Pt", NtracksPercentage_vs_Pt) );
  NtracksPercentage_vs_Pt->SetTitle("Ntracks_Percentage vs Pt ;Pt;Ntracks_Percentage");
  ///////
  Ntracks_0=new TH2D("Ntracks_0","Ntracks_0",100,0,1000,100,0,100);
  CHECK( histSvc()->regHist("/MYSTREAM/Ntracks_0", Ntracks_0) );
  Ntracks_0->SetTitle("Ntracks_0 vs Pt ;Pt;Ntracks_0");

  NtracksPercentage_0_vs_Pt=new TH2D("NtracksPercentage_0_vs_Pt","NtracksPercentage_0_vs_Pt",100,0,1000,100,0,100);
  CHECK( histSvc()->regHist("/MYSTREAM/NtracksPercentage_0_vs_Pt", NtracksPercentage_0_vs_Pt) );
  NtracksPercentage_0_vs_Pt->SetTitle("Ntracks_Percentage_0 vs Pt ;Pt;Ntracks_Percentage_0");


  
  ///////////////////////////////////////NTrackByMe////////////////////////////////////////////////////////////////
  
  NtracksCut_1=new TH1D("NtracksCut_1","NtracksCut_1",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/NtracksCut_1", NtracksCut_1) );
  NtracksCut_1->SetTitle("NtracksCut_1_vs_Pt vs Pt ;Pt");

  NtracksCut_2=new TH1D("NtracksCut_2","NtracksCut_2",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/NtracksCut_2", NtracksCut_2) );
  NtracksCut_2->SetTitle("NtracksCut_2_vs_Pt vs Pt ;Pt");

  NtracksCut_05=new TH1D("NtracksCut_05","NtracksCut_05",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/NtracksCut_05", NtracksCut_05) );
  NtracksCut_05->SetTitle("NtracksCut_05_vs_Pt vs Pt ;Pt");

  NtracksCut_01=new TH1D("NtracksCut_01","NtracksCut_01",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/NtracksCut_01", NtracksCut_01) );
  NtracksCut_01->SetTitle("NtracksCut_01_vs_Pt vs Pt ;Pt");


  
  ////////////////////////////////////NTrack_NmTrk(0)///////////////////////////////////////////////////////////////////
    
  NtracksCut0_1=new TH1D("NtracksCut0_1","NtracksCut0_1",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/NtracksCut0_1", NtracksCut0_1) );
  NtracksCut0_1->SetTitle("NtracksCut0_1_vs_Pt vs Pt ;Pt");
 
  NtracksCut0_2=new TH1D("NtracksCut0_2","NtracksCut0_2",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/NtracksCut0_2", NtracksCut0_2) );
  NtracksCut0_2->SetTitle("NtracksCut0_2_vs_Pt vs Pt ;Pt");
 
  NtracksCut0_05=new TH1D("NtracksCut0_05","NtracksCut0_05",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/NtracksCut0_05", NtracksCut0_05) );
  NtracksCut0_05->SetTitle("NtracksCut0_05_vs_Pt vs Pt ;Pt");
 
  NtracksCut0_01=new TH1D("NtracksCut0_01","NtracksCut0_01",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/NtracksCut0_01", NtracksCut0_01) );
  NtracksCut0_01->SetTitle("NtracksCut0_01_vs_Pt vs Pt ;Pt");
    
  ////////////////////////////////////////////////////////////////////////////////////////////////////
 
  Histo_CHF_20= new TH1D("Histo_CHF_20","Histo_CHF_20",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF_20 ", Histo_CHF_20 ) );
  Histo_CHF_20->SetTitle("Histo_CHF_20;CHF;Number_Events");
 
  Histo_CHF_bis_20= new TH1D("Histo_CHF_bis_20","Histo_CHF_bis_20",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF_bis_20 ", Histo_CHF_bis_20 ) );
  Histo_CHF_bis_20->SetTitle("Histo_CHF_bis_20;CHF;Number_Events");

  Histo_CHF_50= new TH1D("Histo_CHF_50","Histo_CHF_50",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF_50 ", Histo_CHF_50 ) );
  Histo_CHF_50->SetTitle("Histo_CHF_50;CHF;Number_Events");

  Histo_CHF_100= new TH1D("Histo_CHF_100","Histo_CHF_100",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF_100 ", Histo_CHF_100 ) );
  Histo_CHF_100->SetTitle("Histo_CHF_100;CHF;Number_Events");
  
  Histo_CHF_300= new TH1D("Histo_CHF_300","Histo_CHF_300",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF_300 ", Histo_CHF_300 ) );
  Histo_CHF_300->SetTitle("Histo_CHF_300;CHF;Number_Events");

  Histo_CHF_500= new TH1D("Histo_CHF_500","Histo_CHF_500",100,0,1.5);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF_500 ", Histo_CHF_500 ) );
  Histo_CHF_500->SetTitle("Histo_CHF_500;CHF;Number_Events");


  /////////////////////////////////////////////////////////////////////
 
 
  Histo_CHF2_20= new TH1D("Histo_CHF2_20","Histo_CHF2_20",50,0,1.2);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF2_20 ", Histo_CHF2_20 ) );
  Histo_CHF2_20->SetTitle("Histo_CHF2_20;CHF2;Number_Events");

  Histo_CHF2_bis_20= new TH1D("Histo_CHF2_bis_20","Histo_CHF2_bis_20",50,0,1.2);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF2_bis_20 ", Histo_CHF2_bis_20 ) );
  Histo_CHF2_bis_20->SetTitle("Histo_CHF2_bis_20;CHF2;Number_Events");

  Histo_CHF2_50= new TH1D("Histo_CHF2_50","Histo_CHF2_50",50,0,1.2);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF2_50 ", Histo_CHF2_50 ) );
  Histo_CHF2_50->SetTitle("Histo_CHF2_50;CHF2;Number_Events");

  Histo_CHF2_100= new TH1D("Histo_CHF2_100","Histo_CHF2_100",50,-1,1.2);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF2_100 ", Histo_CHF2_100 ) );
  Histo_CHF2_100->SetTitle("Histo_CHF2_100;CHF2;Number_Events");


  Histo_CHF2_150= new TH1D("Histo_CHF2_150","Histo_CHF2_150",50,0,1.2);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF2_150 ", Histo_CHF2_150 ) );
  Histo_CHF2_150->SetTitle("Histo_CHF2_150;CHF2;Number_Events");

  Histo_CHF2_200= new TH1D("Histo_CHF2_200","Histo_CHF2_200",50,0,1.2);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF2_200 ", Histo_CHF2_200 ) );
  Histo_CHF2_200->SetTitle("Histo_CHF2_200;CHF2;Number_Events");


  Histo_CHF2_200_2= new TH1D("Histo_CHF2_200_2","Histo_CHF2_200_2",50,0,1.2);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF2_200_2 ", Histo_CHF2_200_2 ) );
  Histo_CHF2_200_2->SetTitle("Histo_CHF2_200_2;CHF2;Number_Events");

  Histo_CHF2_250= new TH1D("Histo_CHF2_250","Histo_CHF2_250",50,0,1.2);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF2_250 ", Histo_CHF2_250 ) );
  Histo_CHF2_250->SetTitle("Histo_CHF2_250;CHF2;Number_Events");


  Histo_CHF2_500= new TH1D("Histo_CHF2_500","Histo_CHF2_500",50,0,1.2);
  CHECK( histSvc()->regHist("/MYSTREAM/Histo_CHF2_500 ", Histo_CHF2_500 ) );
  Histo_CHF2_500->SetTitle("Histo_CHF2_500;CHF2;Number_Events");


  /////////////////////////CHF1///////////////////////////////////////////

  CHFcut_1= new TH1D("CHFcut_1","CHFcut_1",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/CHFcut_1", CHFcut_1) );
  CHFcut_1->SetTitle("CHFcut1 vs Pt ;Pt");

  CHFcut_2= new TH1D("CHFcut_2","CHFcut_2",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/CHFcut_2", CHFcut_2) );
  CHFcut_2->SetTitle("CHFcut2 vs Pt ;Pt");

  CHFcut_05= new TH1D("CHFcut_05","CHFcut_05",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/CHFcut_05", CHFcut_05) );
  CHFcut_05->SetTitle("CHFcut05 vs Pt ;Pt");

  CHFcut_01= new TH1D("CHFcut_01","CHFcut_01",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/CHFcut_01", CHFcut_01) );
  CHFcut_01->SetTitle("CHFcut01 vs Pt ;Pt");

  EMF_cut05=new TH1D("  EMF_cut05","EMF_cut05",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/EMF_cut05",EMF_cut05) );
  EMF_cut05->SetTitle("EMF_cut05 vs Pt ;Pt");

  //////////////////////////CHF2////////////////////////////////////////////

  CHF2cut_1= new TH1D("CHF2cut_1","CHF2cut_1",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/CHF2cut_1", CHF2cut_1) );
  CHF2cut_1->SetTitle("CHF2cut1 vs Pt ;Pt");

  CHF2cut_2= new TH1D("CHF2cut_2","CHF2cut_2",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/CHF2cut_2", CHF2cut_2) );
  CHF2cut_2->SetTitle("CHF2cut2 vs Pt ;Pt");

  CHF2cut_05= new TH1D("CHF2cut_05","CHF2cut_05",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/CHF2cut_05", CHF2cut_05) );
  CHF2cut_05->SetTitle("CHF2cut05 vs Pt ;Pt");

  CHF2cut_01= new TH1D("CHF2cut_01","CHF2cut_01",100,0,1000);
  CHECK( histSvc()->regHist("/MYSTREAM/CHF2cut_01", CHF2cut_01) );
  CHF2cut_01->SetTitle("CHF2cut01 vs Pt ;Pt");

  //////////////////////////////////////////////////////////////////////////////////////
  CHF_vs_Pt=new TH2D("CHF_vs_Pt","CHF_vs_Pt",100,0,1000,100,0,1);
  CHECK( histSvc()->regHist("/MYSTREAM/CHF_vs_Pt", CHF_vs_Pt) );
  CHF_vs_Pt->SetTitle("CHF vs Pt ;Pt;CHF");

  CHFpercentage_vs_Pt=new TH2D("CHFpercentage_vs_Pt","CHFpercentage_vs_Pt",100,0,1000,100,0,1);
  CHECK( histSvc()->regHist("/MYSTREAM/CHFpercentage_vs_Pt", CHFpercentage_vs_Pt) );
  CHFpercentage_vs_Pt->SetTitle("CHF (percentage) vs Pt ;Pt;CHF");

  EMFrac_Percentage_vs_Pt=new TH2D("EMFrac_Percentage_vs_Pt","EMFrac_Percentage_vs_Pt",100,0,1000,100,0,1);
  CHECK( histSvc()->regHist("/MYSTREAM/EMFrac_Percentage_vs_Pt", EMFrac_Percentage_vs_Pt) );
  EMFrac_Percentage_vs_Pt->SetTitle("EMFrac (percentage) vs Pt ;Pt;EMFrac");

  //////////////////////////////////////////////////////////////////////////////

  CHF2_vs_Pt=new TH2D("CHF2_vs_Pt","CHF2_vs_Pt",100,0,1000,100,0,1);
  CHECK( histSvc()->regHist("/MYSTREAM/CHF2_vs_Pt", CHF2_vs_Pt) );
  CHF2_vs_Pt->SetTitle("CHF2 vs Pt ;Pt;CHF2");

  //prima era 100
  CHF2percentage_vs_Pt=new TH2D("CHF2percentage_vs_Pt","CHF2percentage_vs_Pt",50,0,1000,100,0,1);
  CHECK( histSvc()->regHist("/MYSTREAM/CHF2percentage_vs_Pt", CHF2percentage_vs_Pt) );
  CHF2percentage_vs_Pt->SetTitle("CHF2 (percentage) vs Pt ;Pt;CHF2");
  //////////////////////////////////////////////////////////////////////////////

  PointThree= new TH2D("PointThree","PointThree",100,0,1000,100,0,100);
  CHECK( histSvc()->regHist("/MYSTREAM/PointThree", PointThree) );
  PointThree->SetTitle("Cut_Percentage VS Pt ;Pt ;Cut_Percentage");  


  NoCalibration = new TH1D("NoCalibration ","NoCalibration ",100,0,100);                                                                  
  CHECK( histSvc()->regHist("/MYSTREAM/NoCalibration ", NoCalibration ) );                       
  NoCalibration->SetTitle("Jet;Pt(GeV)");


  Calibration = new TH1D("Calibration ","Calibration ",100,0,100);
  CHECK( histSvc()->regHist("/MYSTREAM/Calibration ", Calibration ) );                        
  Calibration->SetTitle("Jet;Pt(GeV)");


  Hist_Ntrack_NotNorm = new TH2D("NotNorm","NotNorm",100,0,1000,100,0,100);
  CHECK( histSvc()->regHist("/MYSTREAM/Notnorm", Hist_Ntrack_NotNorm) );
  Hist_Ntrack_NotNorm->SetTitle("NTracks vs Pt ;Pt;NTracks");
 

  Hist_Ntrack_Norm = new TH2D("Norm","Norm",100,0,1000,100,0,100);       
  CHECK( histSvc()->regHist("/MYSTREAM/Norm", Hist_Ntrack_Norm) );               
  Hist_Ntrack_Norm->SetTitle("NTracks vs Pt (Normalized Area);Pt;NTracks");
                                                                       
  
  Hist_Ntrack_NormColumn = new TH2D("NormColumn","NormColumn",100,0,1000,100,0,100);
  CHECK( histSvc()->regHist("/MYSTREAM/NormColumn", Hist_Ntrack_NormColumn) );
  Hist_Ntrack_NormColumn->SetTitle("NTracks vs Pt (Normalized Columns);Pt;NTracks");


  Ntracce= new TH1D("Ntracce"," Ntracce",100,0,100);
  CHECK( histSvc()->regHist("/MYSTREAM/Ntracce",  Ntracce) );
  Ntracce->SetTitle("NTracce vs Number_Events;Ntracce;Number_Events");


  Ntracce2= new TH1D("Ntracce2"," Ntracce2",100,0,100);
  CHECK( histSvc()->regHist("/MYSTREAM/Ntracce2",  Ntracce2) );
  Ntracce2->SetTitle("NTracce vs Number_Events;Ntracce;Number_Events");

  return StatusCode::SUCCESS;
}





//PUNTO 2: NORM COLUMN

void normalize_percentage(TH2D* histogram1, TH2D* histogram2)
{

  Int_t h=1;
  Int_t g=1;
  Int_t m=1;
  Int_t n=1;
  Int_t k=1;
  Double_t normcolumn=0;
  Double_t  valore ;
  Double_t sum;
  Double_t sommA=0;


  for(g=1; g<=histogram1->GetNbinsX(); g++){
    normcolumn =histogram1->Integral(g,g,1,histogram1->GetNbinsY());

    for(h=1; h<=histogram1->GetNbinsY(); h++){


      if(normcolumn==0){

	histogram1->SetBinContent(g,h,0);
      }
      else{
	valore = ((histogram1->GetBinContent(g,h))/normcolumn);
	histogram1->SetBinContent(g,h,valore);
      }

    }

  }


  //PUNTO 3:
  //Percentuale

  for(n=1;n<=histogram1->GetNbinsX(); n++){                                                                                           
    sum=0.001;
    
    for(m=1; m<=histogram1->GetNbinsY();m++){
      sum+=histogram1->GetBinContent(n,m);
       
      histogram2->SetBinContent(n,m,sum);   
    }
  
  }
  
} 


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void funzione2(const xAOD::Jet*jet, double valore, std::vector<const xAOD::TrackParticle*> Tracks, TH1D* histo){
  Double_t CHF;
  Double_t Somma=0;
  Int_t m;



  if (jet->pt() > valore){

    for (size_t m = 0; m < Tracks.size() ; ++m){
      if (!Tracks.at(m)) {
      }
      else if(Tracks.at(m)->pt()>1000){
	Somma+= Tracks.at(m)->pt();

      }

    }

    CHF=Somma/jet->pt();
    if(CHF>0){
      histo->Fill(CHF);}
  }
}


void funzione3(const xAOD::Jet*jet, double valore,TH1D* histo, std::vector<float> Sum){
  Double_t CHF2;

  if (jet->pt() > valore){

    CHF2=Sum.at(0)/jet->pt();
    histo->Fill(CHF2);
       
  }

}

Double_t CHF(const xAOD::Jet*jet,/* const xAOD::JetContainer* JetCont,*/ std::vector<float> Sum){
  Double_t CHF8;
  CHF8=Sum.at(0)/jet->pt(); 
    //JetCont->at(0)->pt();

  return CHF8;}


void funzione4(const xAOD::Jet*jet, std::vector<const xAOD::TrackParticle*> Tracks, TH2D*CHF_vs_Pt){

  Double_t CHF;
  Double_t Somma=0;
  Int_t f;


  if (jet->pt()>20.e3){

    for (size_t f=0; f<Tracks.size();++f){
      if (!Tracks.at(f)) {
      }
      else if(Tracks.at(f)->pt()>1000){
	Somma+=Tracks.at(f)->pt();
      }
    }

    CHF=Somma/jet->pt();
    if(CHF>0){
      CHF_vs_Pt->Fill(jet->pt()*0.001,CHF);}
  }
}

//////////////////////////////////////////////////////////////////

void funzione5(Double_t limite, TH2D*histo1, TH1D*histo2 ){

  Int_t x,y;
  Double_t valore;
  for(x=1; x<=histo1->GetNbinsX(); x++){                                                                             

    for(y=1; y<=histo1->GetNbinsY(); y++){

      valore=histo1->GetBinContent(x,y);                                                                     
      if(valore<=limite){
	histo2->SetBinContent(x,histo1->GetYaxis()->GetBinCenter(y));
      }                                                                                                                                
    }
  }

}



StatusCode MyDummyPackageAlg::finalize() {
  ATH_MSG_INFO("Finalizing " << name() << "...");

  Double_t HistoEMf=  Histo_EMfrac->Integral(0,53);
  std::cout<<"Integral fino a 0.795 di Histo_EMFrac: "<< HistoEMf<<std::endl;

  Double_t HistoEMfm=  Histo_EMfrac->Integral(0,56);
  std::cout<<"Integral fino a 0.84 di Histo_EMFrac: "<< HistoEMfm<<std::endl;

  Double_t HistoEMftot= Histo_EMfrac->Integral(0,100);
  std::cout<<"Integral fino a 1.5 di Histo_EMFrac: "<< HistoEMftot<<std::endl;


  //////////////////////////////////////////////////////////
  Double_t HistoCHF= Histo_CHF2_150->Integral(0,4);
  std::cout<<"Integral fino a 0.1 per CHF2_150: "<< HistoCHF <<std::endl;

  Double_t HistoCHFT= Histo_CHF2_150->Integral(0,50);
  std::cout<<"Integral fino a 1.2 per CHF2_150: "<< HistoCHFT <<std::endl;

  Double_t HistoCHFs= Histo_CHF2_250->Integral(0,4);
  std::cout<<"Integral fino a 0.1 per CHF2_250: "<< HistoCHFs <<std::endl;

  Double_t HistoCHFTm= Histo_CHF2_250->Integral(0,50);
  std::cout<<"Integral fino a 1.2 per CHF2_250: "<< HistoCHFTm <<std::endl;

  Double_t HistoCHFt= Histo_CHF2_200->Integral(0,4);
  std::cout<<"Integral fino a 0.1 per CHF2_200: "<< HistoCHFt <<std::endl;

  Double_t HistoCHFTv= Histo_CHF2_200->Integral(0,50);
  std::cout<<"Integral fino a 1.2 per CHF2_200: "<< HistoCHFTv <<std::endl;

  Double_t HistoCHFts= Histo_CHF2_20->Integral(0,4);
  std::cout<<"Integral fino a 0.1 per CHF2_20: "<< HistoCHFts <<std::endl;

  Double_t HistoCHFTvs= Histo_CHF2_20->Integral(0,50);
  std::cout<<"Integral fino a 1.2 per CHF2_20: "<< HistoCHFTvs <<std::endl;

  ////////////////////////////////////////////////////
  Double_t Histo1tot= Histo1->Integral(0,100);
  std::cout<<"Integrale totale per Histo1: "<< Histo1tot <<std::endl;

  Double_t Histo1_150= Histo1->Integral(0,15);
  std::cout<<"Integrale fino a 150 per Histo1: "<< Histo1_150 <<std::endl;

  Double_t Histo1_20= Histo1->Integral(0,2);
  std::cout<<"Integrale fino a 20 per Histo1: "<<Histo1_20<<std::endl;

  Double_t Histo1_200= Histo1->Integral(0,20);
  std::cout<<"Integrale fino a 200 per Histo1: "<< Histo1_200 <<std::endl;

  Double_t Histo1_250= Histo1->Integral(0,25);
  std::cout<<"Integrale fino a 250 per Histo1: "<< Histo1_250 <<std::endl;
 

  Double_t norm = Hist_Ntrack_Norm->Integral();
  Hist_Ntrack_Norm->Scale(1/norm);
   
  Double_t norm1 = Histo_CHF_100->Integral();
  Histo_CHF_100->Scale(1/norm1);

  Double_t norm2 = Histo_CHF_50->Integral();
  Histo_CHF_50->Scale(1/norm2);

  Double_t norm3 = Histo_CHF_20->Integral();
  Histo_CHF_20->Scale(1/norm3);
  
  Double_t norm4 = Histo_CHF2_100->Integral();
  Histo_CHF2_100->Scale(1/norm4);

  Double_t norm5 = Histo_CHF2_50->Integral();
  Histo_CHF2_50->Scale(1/norm5);

  Double_t norm6 = Histo_CHF2_20->Integral();
  Histo_CHF2_20->Scale(1/norm6);
    
  Double_t norm7 = Histo_CHF_bis_20->Integral();
  Histo_CHF_bis_20->Scale(1/norm7);

  Double_t norm8 = Histo_CHF2_bis_20->Integral();
  Histo_CHF2_bis_20->Scale(1/norm8);


  Double_t norm9 = Histo_CHF_300->Integral();
  Histo_CHF_300->Scale(1/norm9);

  Double_t norm10 = Histo_CHF_500->Integral();
  Histo_CHF_500->Scale(1/norm10);

  //Double_t norm11 = Histo_CHF2_300->Integral();
  //Histo_CHF2_300->Scale(1/norm11);

  Double_t norm12 = Histo_CHF2_500->Integral();
  Histo_CHF2_500->Scale(1/norm12);


  Double_t norm13 = Histo_mu_1->Integral();
  Histo_mu_1->Scale(1/norm13);

  Double_t norm14 = Histo_mu_2->Integral();
  Histo_mu_2->Scale(1/norm14);

  Double_t norm15 = Histo_mu_3->Integral();
  Histo_mu_3->Scale(1/norm15);

  Double_t norm16 = Histo_mu_4->Integral();
  Histo_mu_4->Scale(1/norm16);


  normalize_percentage(Lxy_vs_Pt,Lxypercentage_vs_Pt);

  normalize_percentage(Hist_Ntrack_NormColumn,PointThree);

  normalize_percentage(CHF2_vs_Pt,CHF2percentage_vs_Pt);

  normalize_percentage(CHF_vs_Pt, CHFpercentage_vs_Pt);
  
  normalize_percentage(EMFrac_vs_Pt, EMFrac_Percentage_vs_Pt);


  funzione5(0.005, EMFrac_Percentage_vs_Pt, EMF_cut05);  

  funzione5(0.01,CHFpercentage_vs_Pt, CHFcut_1);
  funzione5(0.02,CHFpercentage_vs_Pt, CHFcut_2);
  funzione5(0.005,CHFpercentage_vs_Pt, CHFcut_05);
  funzione5(0.001,CHFpercentage_vs_Pt, CHFcut_01);
  
  funzione5(0.01,CHF2percentage_vs_Pt, CHF2cut_1);
  funzione5(0.02,CHF2percentage_vs_Pt, CHF2cut_2);
  funzione5(0.005,CHF2percentage_vs_Pt, CHF2cut_05);
  funzione5(0.001,CHF2percentage_vs_Pt, CHF2cut_01);   


  normalize_percentage(Ntracks, NtracksPercentage_vs_Pt);
  
  funzione5(0.01,NtracksPercentage_vs_Pt, NtracksCut_1);
  funzione5(0.02,NtracksPercentage_vs_Pt, NtracksCut_2);
  funzione5(0.005,NtracksPercentage_vs_Pt, NtracksCut_05);
  funzione5(0.001,NtracksPercentage_vs_Pt, NtracksCut_01);

  normalize_percentage(Ntracks_0, NtracksPercentage_0_vs_Pt);
  
  funzione5(0.01,NtracksPercentage_0_vs_Pt, NtracksCut0_1);
  funzione5(0.02,NtracksPercentage_0_vs_Pt, NtracksCut0_2);
  funzione5(0.005,NtracksPercentage_0_vs_Pt, NtracksCut0_05);
  funzione5(0.001,NtracksPercentage_vs_Pt, NtracksCut0_01);
  
  return StatusCode::SUCCESS;}


StatusCode MyDummyPackageAlg::execute() {  
  ATH_MSG_DEBUG ("Executing " << name() << "...");
  setFilterPassed(false); 

  static long long unsigned int numEvents = 0;
  if (numEvents % 1000 == 0)
    std::cout << "Processing event number " << numEvents << std::endl;
  numEvents++;


  const xAOD::JetContainer* JetCont = 0;
  CHECK(evtStore()->retrieve( JetCont,"AntiKt4EMTopoJets"));
  
  const xAOD::JetContainer* TrigJetCont = 0;
  CHECK(evtStore()->retrieve( TrigJetCont,"HLT_xAOD__JetContainer_a4tcemsubjesISFSftk"));



  const xAOD::EventInfo* Info = 0;
  CHECK(evtStore()->retrieve( Info,"EventInfo"));

  Double_t mu = Info->averageInteractionsPerCrossing();

  const xAOD::Jet* jet;

  const xAOD::TruthParticleContainer* truthContainer = nullptr;
  CHECK (evtStore()->retrieve (truthContainer, "TruthParticles"));
  
  const xAOD::PhotonContainer* photon = 0;
  CHECK(evtStore()->retrieve(photon,"Photons"));

   
  //////////////////////////////////////////////////////////////
  
  Double_t CHF3, CHF4, CHF5, CHF7, valore2, valore3, limite=0.01, Somma3=0, R, R2, R3=10, Lxy=0, value=0, max_value=0 ;
  Int_t   k, w, t, j, sum=0;

  Int_t cont_i,  n_events=0, nDarkPhoton=0, nToElectrons = 0, nToMuons = 0 , nToQuarks = 0;

  bool isElectron = false;
  bool isMuon = false;
  bool isQCD = false;

  //////////////////////////////////////////AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
  
#ifdef NEVER  

  //LOOP OVER THE SIGNAL-> DarkPhotons   
  //////////////////////////////////////////////////  
  
  xAOD::TruthParticleContainer::const_iterator truth_itr = truthContainer->begin();
  xAOD::TruthParticleContainer::const_iterator truth_end = truthContainer->end();
  //I start to iterate on truth particles

  for( ; truth_itr != truth_end ; ++truth_itr){
    const xAOD::TruthParticle* truth = *truth_itr;
    //I want only Dark Photons

    if(truth->pdgId()==DARK_PHOTON_PDGID && truth->hasDecayVtx()){

      //I define the decay vertex of DarkPhoton
      const xAOD::TruthVertex* decayVtx_p = truth->decayVtx();
      Lxy=TMath::Sqrt(decayVtx_p->x()*decayVtx_p->x()+decayVtx_p->y()*decayVtx_p->y());

      //I controll that the DarkPhoton goes only in 2 particles
      if ( !(decayVtx_p->nOutgoingParticles() == 2)){
	ANA_MSG_INFO("Dark photon not decaying in" << decayVtx_p->nOutgoingParticles() << " particles");
	continue;
      }

      const xAOD::TruthParticle* child1 = decayVtx_p->outgoingParticle(0);
      const xAOD::TruthParticle* child2 = decayVtx_p->outgoingParticle(1);

      // check child pointers
      if (child1==NULL || child2==NULL){
	ANA_MSG_INFO("NULL child pointers");
	continue;
      }

      //I select only displaced Dark Photons
      if (Lxy<4500 && Lxy>1000 ){

	for(size_t t=0; t<JetCont->size(); t++){

	  // Histo1->Fill(JetCont->at(0)->pt()*0.001, Lxy);  
	  jet=JetCont->at(t);
	 
	  std::vector<float> Sum;
	  bool bin = jet->getAttribute("SumPtTrkPt1000",Sum);

	  //match between Truth Particle and recostructed particle. 
	  R=TMath::Sqrt((jet->eta()-truth->eta())*(jet->eta()-truth->eta()) + (jet->phi()-truth->phi())*(jet->phi()-truth->phi()));
	       
	  //?{

	  if(R<0.4){

	    funzione3(jet, 150.e3,Histo_CHF2_150, Sum);
	    funzione3(jet, 200.e3,Histo_CHF2_200, Sum);
	    funzione3(jet, 250.e3,Histo_CHF2_250, Sum);
	    funzione3(jet, 20.e3,Histo_CHF2_20, Sum);
  
	    Lxy_vs_Pt->Fill(jet->pt()*0.001, Lxy);
	    
	    Histo1->Fill(jet->pt()*0.001); 	    

	    float EMFrac;
	    bool em = jet->getAttribute("EMFrac",EMFrac);

	    std::vector<float> Sum;
	    bool bin = jet->getAttribute("SumPtTrkPt1000",Sum);
	   
	    /////////////////////////
	    const xAOD::TruthVertex* decayVtx_c1 = child1->decayVtx();
	    const xAOD::TruthVertex* decayVtx_c2 = child2->decayVtx();
	    
	    if(!(decayVtx_c1) || !(decayVtx_c2)){
	      //std::cout<<"problem"<<std::endl;
	      continue;}

	    if(decayVtx_c1->nOutgoingParticles() == 2 && decayVtx_c2->nOutgoingParticles() == 2 ){
	    

	      if((decayVtx_c1->outgoingParticle(0) == decayVtx_c2->outgoingParticle(0) && decayVtx_c1->outgoingParticle(0)->absPdgId()== 111) || (decayVtx_c1->outgoingParticle(0) == decayVtx_c2->outgoingParticle(1) && decayVtx_c1->outgoingParticle(0)->absPdgId()== 111) || (decayVtx_c1->outgoingParticle(1) == decayVtx_c2->outgoingParticle(0) && decayVtx_c2->outgoingParticle(0)->absPdgId()== 111) || (decayVtx_c1->outgoingParticle(1) == decayVtx_c2->outgoingParticle(1) && decayVtx_c1->outgoingParticle(1)->absPdgId()== 111)){


		HistoPi0_EMfrac->Fill(EMFrac);	
	      }


	    }
 

	    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	    if( (child1->absPdgId() == 11) && (child2->absPdgId() == 11)){
	      isElectron = true;
	      isMuon = false;
	      isQCD = false;
	      nToElectrons++;
	    }else if((child1->absPdgId() == 13) && (child2->absPdgId() == 13)){
	      isElectron = false;
	      isMuon = true;
	      isQCD = false;
	      nToMuons++;
	    }
	    else if ( (child1->absPdgId() > 0 && child1->absPdgId() < 2) && (child2->absPdgId() > 0 && child2->absPdgId() < 2) ){
	      isElectron = false;
	      isMuon = false;
	      isQCD = true;
	      nToQuarks++;
       
	    }else{

	      isElectron = false;
	      isMuon = false;
	      isQCD = false;
	    }

	    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	    if ( isElectron ){ 
	      Histo_Electron->Fill(EMFrac);
	    }

	    if ( isMuon ){
	      Histo_Muon->Fill(EMFrac); 
	    }

	    if ( isQCD ){
	      Histo_QCD->Fill(EMFrac);
	    }		
	  
	  }

	}

	
	//	}
       
      }
      
    } //end Lxy 
      
  }//end of truth loop 	
   

  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //INZIO FOR-> FOR che mi da tutti i jet con tutti i Pt  di AntiKt4EMTopoJets!


  /*
    Step 1:
    For each event, is there a jet?
    If no, skip the event
    If yes, fill the inclusive histogram
    For each event, did the trigger pass?
    If no, fill the "failed trigger" efficiency histogram
    If yes, start a new block {} and within this block...
    Fill the "successful trigger" efficiency histogram
    For the leading = at(0) jet, does it pass the CHF cut?
    If no, fill the "failed CHF" efficiency histogram
    If yes, start a new block {} and within this block...
    Fill the "successful CHF" efficiency histogram
    For the leading jet, does it pass the EMF cut?
    If no, fill the "failed EMF" efficiency histogram
    If yes, start a new block {} and within this block...
    Fill the "successful EMF" efficiency histogram
    That's it, we're done

    Step 2:
    Same as the above, but check EITHER jet 0 or jet 1

        If no, fill the "failed CHF" efficiency histogram                                                                                         
    If yes, start a new block {} and within this block...  Step hard:
    Do the above, but check if any jet passes the CHF, EMF selections BUT it has to be the SAME jet that passes both CHF and EMF
       
    For each event, is there a jet?                              
    If no, skip the event                                                                                                               
    If yes, fill the inclusive histogram                                                                                           
    For each event, did the trigger pass?                                                                                               
    If no, fill the "failed trigger" efficiency histogram                                                                              
    If yes, start a new block {} and within this block...                                                                              
    for every jet in the collection (loop), ask if:
    Does the jet pass the CHF cut?
    If not, skip to the next jet
    If yes, does the same jet also pass the EMF cut?
    If not, skip to the next jet
    If yes, we are done
    Ok, we now have a jet that may pass everything, or it may pass only CHF, or it may pass nothing
    If there is no jet that passes the CHF cut, fill the trigger histogram with jet pt 0
    If there is a jet that passes the CHF cut, but not the EMF cut, fill the trigger histogram with the first jet that passes the CHF cut
    If there is a jet that passes the CHF and EMF cuts, fill the trigger histogram with the first jet that passes both cuts
	   
  */

    

  //#endif
    
 
  ///////////////////////////////////////////////////////////////////

  //std::cout << "Initially found " << JetCont->size() << " jets" << std::endl;

  if (JetCont->size() > 0)
    {
    bool centralJet = false;
    for (size_t i=0; i<JetCont->size(); i++)
      {
	jet = JetCont->at(i);
	if (std::abs(jet->eta())<2.5)
      {
	centralJet = true;
	break;
      }
      
      }
    
    if (centralJet)
      {
	//	std::cout << "Found " << JetCont->size() << " jets" << std::endl;
	size_t darkPhotonIndex = 0;
	bool foundFirstDarkPhoton = false;

	xAOD::TruthParticleContainer::const_iterator truth_itr = truthContainer->begin();
	xAOD::TruthParticleContainer::const_iterator truth_end = truthContainer->end();
	//I start to iterate on truth particles                                                                                                                                                                              
	for( ; truth_itr != truth_end ; ++truth_itr){
	  const xAOD::TruthParticle* truth = *truth_itr;
	  //I want only Dark Photons                                                                                                                                                                                
	  if(truth->pdgId()==DARK_PHOTON_PDGID && truth->hasDecayVtx()){

	    //I define the decay vertex of DarkPhoton                                                                                                                                                                       
	    const xAOD::TruthVertex* decayVtx_p = truth->decayVtx();
	    Lxy=TMath::Sqrt(decayVtx_p->x()*decayVtx_p->x()+decayVtx_p->y()*decayVtx_p->y());

	    //I controll that the DarkPhoton goes only in 2 particles                                                                                                                                                
	    if ( !(decayVtx_p->nOutgoingParticles() == 2)){
	      ANA_MSG_INFO("Dark photon not decaying in" << decayVtx_p->nOutgoingParticles() << " particles");
	      continue;
	    }

	    const xAOD::TruthParticle* child1 = decayVtx_p->outgoingParticle(0);
	    const xAOD::TruthParticle* child2 = decayVtx_p->outgoingParticle(1);
	    // check child pointers                                                                                                                                                                                 
	    if (child1==NULL || child2==NULL){
	      ANA_MSG_INFO("NULL child pointers");
	      continue;
	    }
	    //I select only displaced Dark Photons                                                                                                                                                                   
	    if (Lxy<4500 && Lxy>1000 ){

	      for(size_t t=0; t<JetCont->size(); t++){
       
		jet=JetCont->at(t);

		std::vector<float> Sum;
		bool bin = jet->getAttribute("SumPtTrkPt1000",Sum);

		//match between Truth Particle and recostructed particle.                                                                                    
		R=TMath::Sqrt((jet->eta()-truth->eta())*(jet->eta()-truth->eta()) + (jet->phi()-truth->phi())*(jet->phi()-truth->phi()));

		//?{                                                                                                                                                                                                        
		if(R<0.4){
		  if (!foundFirstDarkPhoton)
		    {

		      darkPhotonIndex=t;
		      foundFirstDarkPhoton=true;
		    }
		  break;
		}

	      }
	    }

	    if (foundFirstDarkPhoton)
	      break;
	  }
      
	}//?

    bool passTrig = false;
    bool passCHF = false;
    bool passEMF = false;
    size_t jetIndexCHF = 0;
    size_t jetIndexEMF = 0;

    Histo_Inclusive->Fill(JetCont->at(darkPhotonIndex)->pt()*0.001);

    for (size_t i=0; i<JetCont->size(); i++)
      {
	jet = JetCont->at(i);
	if (std::abs(jet->eta())<2.5)
	  {

	    // Trigger
	    auto chainGroup = m_trigDecisionTool->getChainGroup("L1_TAU60");
	    std::map<std::string,int> triggerCounts;
	    for(auto &trig : chainGroup->getListOfTriggers()) {

	      auto cg = m_trigDecisionTool->getChainGroup(trig);
	      std::string thisTrig = trig;

	      if( cg->isPassed() ==1 )
		{
		  passTrig = true;
		}
	    }
	      
	      // CHF
	      if (passTrig)
		{
		  std::vector<float> Sum;
		  bool bin = jet->getAttribute("SumPtTrkPt1000",Sum);
		 

		  if (CHF(jet,Sum)<0.1)
		    {

		      if (!passCHF)
			{
			  jetIndexCHF = i;
			}

		      passCHF = true;

		      //      jetIndexCHF = i;
		      
		      // EMF
		      float EMFrac;
		      bool em = jet->getAttribute("EMFrac",EMFrac);
		 
		      if (EMFrac < 0.8)
			{
			  
			  if (!passEMF)
			     {
			       jetIndexEMF = i;
			     }
		      

			  passEMF = true;
			  //  	  jetIndexEMF = i;
			}
		  
		    }
	    
		}
	  }

      }
	
            if(passTrig)
	     {
	     Histo_TriggerPassed->Fill(JetCont->at(darkPhotonIndex)->pt()*0.001);  
	     }


	    if(passTrig && passCHF){
	    Histo_PassedCHF->Fill(JetCont->at(darkPhotonIndex)->pt()*0.001);
	    }


	    if(passTrig && passCHF && passEMF){
	      Histo_PassedEMF->Fill(JetCont->at(darkPhotonIndex)->pt()*0.001);
	    }

	    if (!passTrig)
	      {
		Histo_TriggerFailed->Fill(JetCont->at(darkPhotonIndex)->pt()*0.001);              //at(0)
	      }

	    if (passTrig && !passCHF)
	      {
		Histo_FailedCHF->Fill(JetCont->at(darkPhotonIndex)->pt()*0.001); 	//at(0)
	      }
	    
	    if (passTrig && passCHF && !passEMF)
	      {
		Histo_FailedEMF->Fill(JetCont->at(darkPhotonIndex)->pt()*0.001);   //at(OBJetIndexCHF)
	      }
	    
	  }
      }


#endif
  //////////////////////////////////////////////////

  //NUOVO CHECK
 
  /*
  auto chainGroup = m_trigDecisionTool->getChainGroup("L1_TAU60");
  std::map<std::string,int> triggerCounts;
  for(auto &trig : chainGroup->getListOfTriggers()) {

    auto cg = m_trigDecisionTool->getChainGroup(trig);
    std::string thisTrig = trig;

    if(cg->isPassed() == 1)
      {

	
	xAOD::TruthParticleContainer::const_iterator truth_itr = truthContainer->begin();
	xAOD::TruthParticleContainer::const_iterator truth_end = truthContainer->end();
        //I start to iterate on truth particles                                                                                                                                                                                                                  
        for( ; truth_itr != truth_end ; ++truth_itr){
          const xAOD::TruthParticle* truth = *truth_itr;
          //I want only Dark Photons                                                                                                                                                                                                                             
          if(truth->pdgId()==DARK_PHOTON_PDGID && truth->hasDecayVtx()){

            //I define the decay vertex of DarkPhoton                                                                                                                                                                                                            
            const xAOD::TruthVertex* decayVtx_p = truth->decayVtx();
            Lxy=TMath::Sqrt(decayVtx_p->x()*decayVtx_p->x()+decayVtx_p->y()*decayVtx_p->y());

            //I controll that the DarkPhoton goes only in 2 particles                                                                                                                                                                                            
            if ( !(decayVtx_p->nOutgoingParticles() == 2)){
              ANA_MSG_INFO("Dark photon not decaying in" << decayVtx_p->nOutgoingParticles() << " particles");
              continue;
            }

            const xAOD::TruthParticle* child1 = decayVtx_p->outgoingParticle(0);
            const xAOD::TruthParticle* child2 = decayVtx_p->outgoingParticle(1);
            // check child pointers                                                                                                                                                                                                                              
            if (child1==NULL || child2==NULL){
              ANA_MSG_INFO("NULL child pointers");
              continue;
            }
            //I select only displaced Dark Photons                                                                                                                                                                                                               
            if (Lxy<4500 && Lxy>1000 ){

              for(size_t t=0; t<JetCont->size(); t++){

                jet=JetCont->at(t);

		//	float EMFrac;
		//bool em = jet->getAttribute("EMFrac",EMFrac);

		std::vector<float> Sum;
                bool bin = jet->getAttribute("SumPtTrkPt1000",Sum);

                //match between Truth Particle and recostructed particle.                                                                                                                                                                                        
                R=TMath::Sqrt((jet->eta()-truth->eta())*(jet->eta()-truth->eta()) + (jet->phi()-truth->phi())*(jet->phi()-truth->phi()));

                //?{                                                                                                                                                                                                                                             
                if(R<0.4){
		  float EMFrac;
		  bool em = jet->getAttribute("EMFrac",EMFrac);

		  Histo_EMfrac->Fill(EMFrac);
		
		  if(mu <25){Histo_mu_1->Fill(EMFrac);}
		  if( mu>25 && mu<35){Histo_mu_2->Fill(EMFrac);}
		  if( mu>35 && mu<50){Histo_mu_3->Fill(EMFrac);}
		  if(mu>50){Histo_mu_4->Fill(EMFrac);}
		  

      }
	      }
	    }
	  }
	}
	  }
	 }


	*/
  //////////////////////////////////////////////////////////////////////
    /*Commentato ad agosto	*/


  for (size_t i=0; i<TrigJetCont->size(); i++){
    jet=TrigJetCont->at(i);

    std::vector<float> Sum;
    bool bin = jet->getAttribute("SumPtTrkPt1000",Sum);

    float EMFrac;
    bool em = jet->getAttribute("EMFrac",EMFrac);

    auto chainGroup = m_trigDecisionTool->getChainGroup("L1_TAU60");
    std::map<std::string,int> triggerCounts;
    for(auto &trig : chainGroup->getListOfTriggers()) {

      auto cg = m_trigDecisionTool->getChainGroup(trig);
      std::string thisTrig = trig;

      if(cg->isPassed() == 1)
        {


	  funzione3(jet, 200.e3,Histo_CHF2_200_2, Sum);


	  EMFrac1->Fill(EMFrac);
 

	}
    }





  }

  ////////////////////////////////////

    for (size_t i=0; i<JetCont->size(); i++){
  
  jet=JetCont->at(i);




  
  if(abs(jet->eta())<2.5){
    //    jet=JetCont->at(i);

      //      Histo1->Fill(jet->pt()*0.001); 

    std::vector<float> Sum;
    bool bin = jet->getAttribute("SumPtTrkPt1000",Sum);
  
    float EMFrac;
    bool em = jet->getAttribute("EMFrac",EMFrac);


    ///////////////////////////////////////////
    /*auto chainGroup = m_trigDecisionTool->getChainGroup("L1_TAU60");
    std::map<std::string,int> triggerCounts;
    for(auto &trig : chainGroup->getListOfTriggers()) {

      auto cg = m_trigDecisionTool->getChainGroup(trig);
      std::string thisTrig = trig;

      if(cg->isPassed() == 1)
	{
	  if(mu <25){Histo_mu_1->Fill(EMFrac);}
	  if( mu>25 && mu<35){Histo_mu_2->Fill(EMFrac);}
	  if( mu>35 && mu<50){Histo_mu_3->Fill(EMFrac);}
	  if(mu>50){Histo_mu_4->Fill(EMFrac);}

	}

    }


    */
      ///////////////////////////////////////////////7
      /*auto chainGroup = m_trigDecisionTool->getChainGroup("L1_TAU60");
      std::map<std::string,int> triggerCounts;
      for(auto &trig : chainGroup->getListOfTriggers()) {

	auto cg = m_trigDecisionTool->getChainGroup(trig);
	std::string thisTrig = trig;

	if ( JetCont->size()>0 ){
	  Histo_Inclusive->Fill(JetCont->at(0)->pt()*0.001);
	}
	else continue;

	if( cg->isPassed() == 0){
	  Histo_TriggerFailed->Fill(JetCont->at(0)->pt()*0.001);
	}else{Histo_TriggerPassed->Fill(JetCont->at(0)->pt()*0.001);
	  //For the leading = at(0) jet, does it pass the CHF cut?                                                                                    
	  if(CHF(jet,Sum)>0.1){Histo_FailedCHF->Fill(JetCont->at(0)->pt()*0.001);
	  }else{Histo_PassedCHF->Fill(JetCont->at(0)->pt()*0.001);

	    if(EMFrac > 0.8){Histo_FailedEMF->Fill(JetCont->at(0)->pt()*0.001);
	    }else{Histo_PassedEMF->Fill(JetCont->at(0)->pt()*0.001);
	    }
	  }
	}
      }
    
        
      */
  



      ////////////////////////// first reques
      /*
	funzione3(jet, 150.e3,Histo_CHF2_150, Sum);
	funzione3(jet, 200.e3,Histo_CHF2_200, Sum);
	funzione3(jet, 250.e3,Histo_CHF2_250, Sum);
	funzione3(jet, 20.e3,Histo_CHF2_20, Sum);
      */


      // Histo1->Fill(jet->pt()*0.001);
     
      /*if(i==0){ 
	auto chainGroup = m_trigDecisionTool->getChainGroup("L1_TAU60");
	std::map<std::string,int> triggerCounts;
	std::cout << "Before loop" << std::endl;
	for(auto &trig : chainGroup->getListOfTriggers()) {

	auto cg = m_trigDecisionTool->getChainGroup(trig);
	std::string thisTrig = trig;

	if ( JetCont->size()==0 ){

	continue;
	}
	//	std::cout<<"Inside loop"<<std::endl;

	EfficiencyTotal->Fill(JetCont->at(0)->pt()*0.001 );
	if( cg->isPassed() == 1){
      
	Efficiency->Fill(JetCont->at(0)->pt()*0.001 );
      
       
	}
	}
	}
	}
    

      */
  

      /////////////////////////////////////////////////////////////////

      /*commentato ad agosto*/

    auto chainGroup = m_trigDecisionTool->getChainGroup("L1_TAU60");
    std::map<std::string,int> triggerCounts;
    for(auto &trig : chainGroup->getListOfTriggers()) {

      auto cg = m_trigDecisionTool->getChainGroup(trig);
      std::string thisTrig = trig;

      if(cg->isPassed() == 1)
        {

	  EMFrac2->Fill(EMFrac);

	  funzione3(jet, 200.e3,Histo_CHF2_200, Sum);
	  /*
	 xAOD::PhotonContainer::const_iterator phot_itr = photon->begin();
	 xAOD::PhotonContainer::const_iterator phot_end = photon->end();

	 //    float EMFrac;
	 // bool em = jet->getAttribute("EMFrac",EMFrac);

    
	 for( ; phot_itr != phot_end ; ++phot_itr){

	 const xAOD::Photon* phot = *phot_itr;

	 bool isPhoton;
	 if (! phot->passSelection(isPhoton,"Tight"))
	 {
	 std::cout << "WARNING: Cannot determine photon type" << std::endl;
	 }
	 if (isPhoton)
	 {

	   R2=TMath::Sqrt((jet->eta()-phot->eta())*(jet->eta()-phot->eta()) + (jet->phi()-phot->phi())*(jet->phi()-phot->phi()));

	 if(R2<0.4){

	   	 funzione3(jet, 150.e3,Histo_CHF2_150, Sum);
	   funzione3(jet, 200.e3,Histo_CHF2_200, Sum);
	   funzione3(jet, 250.e3,Histo_CHF2_250, Sum);
	   funzione3(jet, 20.e3,Histo_CHF2_20, Sum);
	
	   
	   if(mu <25){Histo_mu_1->Fill(EMFrac);}
	   if( mu>25 && mu<35){Histo_mu_2->Fill(EMFrac);}
	   if( mu>35 && mu<50){Histo_mu_3->Fill(EMFrac);}
	   if(mu>50){Histo_mu_4->Fill(EMFrac);}
	   


	   //      	 Histo_EMfrac->Fill(EMFrac);                                                                                                   
	 }
	 }
	 EMFrac_vs_Pt->Fill(jet->pt()*0.001,EMFrac);
       
	 }

	  */
	}
    }	 

       
      ////////////////////////////////////////////////////////
						
    
      //Tracks                                                                                                                    
      std::vector<const xAOD::TrackParticle*> Tracks;
      bool  status = jet->getAssociatedObjects("GhostTrack", Tracks);
    
      
      Ntracks->Fill(jet->pt()*0.001,Tracks.size());
      Ntracce2->Fill(Tracks.size());

      //funzione2(jet, 500.e3,  Tracks,  Histo_CHF_500);
      //funzione2(jet, 300.e3,  Tracks,  Histo_CHF_300);
      //funzione2(jet, 100.e3,  Tracks,  Histo_CHF_100);
      //funzione2(jet, 50.e3, Tracks, Histo_CHF_50);
      //funzione2(jet, 20.e3,  Tracks,  Histo_CHF_20);

      //funzione4(jet, Tracks, CHF_vs_Pt);
    
      Histo_evnts_vs_pt->Fill(jet->pt()*0.001);
    
      ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    	
      std::vector<int> NumTrk;
      bool worked = jet->getAttribute("NumTrkPt1000", NumTrk);
    
       
      Ntracks_0->Fill(jet->pt()*0.001, NumTrk.at(0));

      
      float JVT;
      bool chi = jet->getAttribute("Jvt",JVT);
      if(JVT>0.59 && jet->pt()>20.e3){
	funzione3(jet, 20.e3,Histo_CHF2_bis_20,Sum);
	funzione2(jet, 20.e3,  Tracks,  Histo_CHF_bis_20);      
	Ntracce->Fill(NumTrk.at(0));      
      }

     
     
      
      //Calibration
      TString jetAlgo    = "AntiKt4EMTopo" ;
 
      TString config     = "JES_data2017_2016_2015_Consolidated_EMTopo_2018_Rel21.config" ;  // Global config (see below)                      
      TString calibSeq  = "JetArea_Residual_EtaJES_GSC_Insitu" ; // Calibration sequence to apply (see below)                                  
      TString calibArea = "00-04-82"; // Calibration Area tag (see below)                                                                      
      bool isData  = true ; // bool describing if the events are data or from simulation                                               
 
      asg::AnaToolHandle<IJetCalibrationTool> JetCalibrationTool_handle;
 
      JetCalibrationTool_handle.setTypeAndName("JetCalibrationTool/name");
      if( !JetCalibrationTool_handle.isUserConfigured() ){
	ANA_CHECK( JetCalibrationTool_handle.setProperty("JetCollection",jetAlgo.Data()) );
	ANA_CHECK( JetCalibrationTool_handle.setProperty("ConfigFile",config.Data()) );
	ANA_CHECK( JetCalibrationTool_handle.setProperty("CalibSequence",calibSeq.Data()) );
	ANA_CHECK( JetCalibrationTool_handle.setProperty("CalibArea",calibArea.Data()) );
	ANA_CHECK( JetCalibrationTool_handle.setProperty("IsData",isData) );
	ANA_CHECK( JetCalibrationTool_handle.retrieve() );
      }

      xAOD::TStore store;
      const xAOD::JetContainer* my_jets=0;
      std::string jetCollectionName = "AntiKt4EMTopoJets"; 
      ANA_CHECK(evtStore()->retrieve(my_jets,jetCollectionName));

      for ( auto *ijet : *my_jets ) {
	xAOD::Jet *jet = 0;
	JetCalibrationTool_handle->calibratedCopy(*ijet,jet); 
    
	Calibration->Fill(jet->pt()/ijet->pt());
	NoCalibration->Fill(ijet->pt()*0.001);

    
	delete jet;
  
      }
      
      Hist_Ntrack_NotNorm->Fill(jet->pt()*0.001, NumTrk.at(0));                                                                          
      Hist_Ntrack_Norm->Fill(jet->pt()*0.001, NumTrk.at(0));


      //Punto 2:Normalizzare sulle colonne                                                                                               
      Hist_Ntrack_NormColumn->Fill(jet->pt()*0.001, NumTrk.at(0));
 
    }

  }
  // #endif
 
      
 
 setFilterPassed(true); 
  return StatusCode::SUCCESS;
}
 
StatusCode MyDummyPackageAlg::beginInputFile() { 
 
  return StatusCode::SUCCESS;
}





