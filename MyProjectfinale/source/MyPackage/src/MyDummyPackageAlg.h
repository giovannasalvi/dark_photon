#ifndef MYDUMMYPACKAGE_MYDUMMYPACKAGEALG_H
#define MYDUMMYPACKAGE_MYDUMMYPACKAGEALG_H 1 

//#Include "Athanalysisbasecomps/Athanalysisalgorithm.h"
#include "AthAnalysisBaseComps/AthAnalysisAlgorithm.h"
#include <string>
#include "TCanvas.h"
#include"TEfficiency.h"
#include <AsgTools/MessageCheck.h>
#include "AsgTools/AnaToolHandle.h"
#include <TrigConfInterfaces/ITrigConfigTool.h>
#include <TrigDecisionTool/TrigDecisionTool.h>



asg::AnaToolHandle<Trig::TrigDecisionTool> m_trigDecisionTool;
//asg::AnaToolHandle<TrigConf::ITrigConfigTool> m_trigConfigTool;


class MyDummyPackageAlg: public ::AthAnalysisAlgorithm { 
 public: 
  MyDummyPackageAlg( const std::string& name, ISvcLocator* pSvcLocator );
  virtual ~MyDummyPackageAlg(); 

  ///uncomment and implement methods as required

  //IS EXECUTED:
  virtual StatusCode  initialize();     //once, before any input is loaded
  virtual StatusCode  beginInputFile(); //start of each input file, only metadata loaded
  //virtual StatusCode  firstExecute();   //once, after first eventdata is loaded (not per file)
  virtual StatusCode  execute();        //per event
  //virtual StatusCode  endInputFile();   //end of each input file
  //virtual StatusCode  metaDataStop();   //when outputMetaStore is populated by MetaDataTools
  virtual StatusCode  finalize();       //once, after all events processed
  

  ///Other useful methods provided by base class are:
  ///evtStore()        : ServiceHandle to main event data storegate
  ///inputMetaStore()  : ServiceHandle to input metadata storegate
  ///outputMetaStore() : ServiceHandle to output metadata storegate
  ///histSvc()         : ServiceHandle to output ROOT service (writing TObjects)
  ///currentFile()     : TFile* to the currently open input file
  ///retrieveMetadata(...): See twiki.cern.ch/twiki/bin/view/AtlasProtected/AthAnalysisBase#ReadingMetaDataInCpp


 private: 

  //Example algorithm property, see constructor for declaration:
  //int m_nProperty = 0;

  //Example histogram, see initialize method for registration to output histSvc
  //TH1D* m_myHist2 = 0;



  TH2D* m_myHist = 0;  

  TH2D* m_myHist2 = 0;
  TH2D* Hist_Ntrack_Norm = 0;
  TH1D* PointFour;
  TH2D* Hist_Ntrack_NotNorm = 0;
  TH1D* NoCalibration;
  TH1D* Calibration;
  TH2D* Hist_Ntrack_NormColumn;
  TH2D* PointThree;
  TH2D* Point_Five;
  

  TH1D* Histo_CHF_100;
  TH1D* Histo_CHF_50;
  TH1D* Histo_CHF_20;
  TH1D* Histo_CHF_bis_20;

  
  TH1D* Histo_CHF2_100;
  TH1D* Histo_CHF2_50;
  //TH1D* Histo_CHF2_20;

  TH2D* CHF_vs_Pt;
  TH2D* CHFpercentage_vs_Pt;
  TH2D* CHF2_vs_Pt;
  TH2D* CHF2percentage_vs_Pt;

  TH1D* Histo_CHF_1000;
  TH1D* Histo_CHF_300;
  TH1D* Histo_CHF_500;

  TH1D* Histo_CHF2_150;
  TH1D* Histo_CHF2_500;

  TH1D* Histo_CHF2_200;
  TH1D* Histo_CHF2_250;
  TH1D* Histo_CHF2_20;
  TH1D* Histo_CHF2_1000;
  TH1D* Histo_CHF2_bis_20;



  TH1D* Histo_CHF2_200_2;

  //TTree* m_myTree = 0;


  TH2D* Ntracks;
  TH2D* Ntracks_0;
  TH2D* NtracksPercentage_vs_Pt;
  TH2D* NtracksPercentage_0_vs_Pt;
  TH1D* NtracksPercentageCut_vs_Pt;
  TH1D*Histo_evnts_vs_pt;
  TCanvas* c1=0;
  TCanvas* c2=0;
  TCanvas* c3=0;
  TCanvas* c4=0;

  

  TH1D* CHFcut_1;
  TH1D* CHFcut_2;
  TH1D* CHFcut_01;
  TH1D* CHFcut_05;

  TH1D* CHF2cut_1;
  TH1D* CHF2cut_2;
  TH1D* CHF2cut_01;
  TH1D* CHF2cut_05;


  TH1D* NtracksCut_1;
  TH1D* NtracksCut_2;
  TH1D* NtracksCut_01;
  TH1D* NtracksCut_05;

  TH1D* NtracksCut0_1;
  TH1D* NtracksCut0_2;
  TH1D* NtracksCut0_01;
  TH1D* NtracksCut0_05;
  TH1D*Ntracce;
  TH1D*Ntracce2;
  TH1D*Division;
  TH1D*Histo_EMfrac;
  TH1D*HistoPi0_EMfrac;

  TH2D*EMFrac_Percentage_vs_Pt;
  TH2D*EMFrac_vs_Pt;
  TH1D*EMF_cut05;
  TH1D* h_DP_Pt;
  TH1D* h_DP_eta;
  TH1D* h_DP_phi;
  TH1D* h_DP_Lxy;
  TH1D* h_DP_Pt2;
  TH1D* h_DP_eta2;
  TH1D* h_DP_phi2;
  TH1D* h_DP_R;
  TH1D* h_DP_Lxy2;
  TH1D* h_DP_R2;

  //
  TH1D* Histo_Electron;
  TH1D* Histo_Muon;
  TH1D* Histo_QCD;
  TH1D* Histo_child1; 
  TH1D* Histo_child1_1;
  TH1D* Histo_child1_2; 
  //    TEfficiency* pEff;
    TH1D* Efficiency;
    TH1D* EfficiencyTotal;
    


    TH1D* Efficiency2;
    TH1D* EfficiencyTotal2;
    TH1D*Histo1;
    TH1D*Histo3;
    TH1D*Histo4;
    TH1D*CHF_Dark;
    TH2D* Lxy_vs_Pt;
    TH2D* Lxypercentage_vs_Pt;

    TH1D*Histo_Inclusive;
    TH1D*Histo_TriggerFailed;
    TH1D*Histo_TriggerPassed;

   TH1D*Histo_FailedCHF;
   TH1D*Histo_PassedCHF;
   TH1D*Histo_FailedEMF;
   TH1D*Histo_PassedEMF;

   TH1D*Histo_mu_1;
   TH1D*Histo_mu_2;
   TH1D*Histo_mu_3;
   TH1D*Histo_mu_4;


   TH1D*EMFrac1;
   TH1D*EMFrac2;

}; 

#endif //> !MYPACKAGE_MYPACKAGEALG_H
