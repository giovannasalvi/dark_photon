#Skeleton joboption for a simple analysis job

#---- Minimal job options -----

jps.AthenaCommonFlags.AccessMode = "ClassAccess"              #Choose from TreeAccess,BranchAccess,ClassAccess,AtheNaaccess,Poolaccess
#jps.AthenaCommonFlags.TreeName = "MyTree"                    #when using TreeAccess, must specify the input tree name

#jps.AthenaCommonFlags.HistOutputs = ["MYSTREAM:lastplot.root"]  #register output files like this. MYSTREAM is used in the code

#jps.AthenaCommonFlags.HistOutputs = ["MYSTREAM:myfile1.root"]
#jps.AthenaCommonFlags.HistOutputs = ["MYSTREAM:frac.root"]  
#jps.AthenaCommonFlags.HistOutputs = ["MYSTREAM:BACKGROUND_EMFRACTION.root"]  
#jps.AthenaCommonFlags.HistOutputs = ["MYSTREAM:GAMMA+JET.root"]  
jps.AthenaCommonFlags.HistOutputs = ["MYSTREAM:FTK.root"] 
athAlgSeq += CfgMgr.MyDummyPackageAlg()                               #adds an instance of your alg to the main alg sequence


#---- Options you could specify on command line -----
jps.AthenaCommonFlags.EvtMax=-1                          #set on command-line with: --evtMax=-1
#jps.AthenaCommonFlags.SkipEvents=0                       #set on command-line with: --skipEvents=0
#jps.AthenaCommonFlags.FilesInput = ["/cvmfs/atlas-nightlies.cern.ch/repo/data/data-art/CommonInputs/DAOD_PHYSVAL/mc16_13TeV.410501.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_nonallhad.DAOD_PHYSVAL.e5458_s3126_r9364_r9315_AthDerivation-21.2.1.0.root"]        #set on command-line with: --filesInput=...

#jps.AthenaCommonFlags.FilesInput = ["/afs/cern.ch/work/g/gsalvi/mc16_13TeV/DAOD_JETM1.14428996._000355.pool.root.1","/afs/cern.ch/work/g/gsalvi/mc16_13TeV/ DAOD_JETM1.14428996._000350.pool.root.1","/afs/cern.ch/work/g/gsalvi/mc16_13TeV/DAOD_JETM1.14428996._000295.pool.root.1 ","/afs/cern.ch/work/g/gsalvi/mc16_13TeV/DAOD_JETM1.14428996._000293.pool.root.1"]


#jps.AthenaCommonFlags.FilesInput =["/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev/AOD.16301669._000001.pool.root.1","/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev/AOD.16301669._000002.pool.root.1"]


#myfile1.root
#DECOMMENTASOLOQUESTOENONQUELLOSOTTO
#VECCHIO FILE BUONO QUI SOTTO, ORA ABBIAMO CAMBIATO LA PARTE FINALE IN R10201 INVECE CHE R10684
#jps.AthenaCommonFlags.FilesInput =["/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev/AOD.16301669._000001.pool.root.1","/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev/AOD.16301669._000002.pool.root.1","/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev/AOD.16301669._000003.pool.root.1","/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev/AOD.16301669._000004.pool.root.1","/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev/AOD.16301669._000006.pool.root.1"]

#QUELLI NUOVI MA  NON PER L'EMFRAC , SONO PER LA QCD
#jps.AthenaCommonFlags.FilesInput =["/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev_NUOVO/AOD.12911516._000005.pool.root.1","/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev_NUOVO/AOD.12911516._000006.pool.root.1 ","/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev_NUOVO/AOD.12911516._000007.pool.root.1 "]
 

#QUELLI NUOVI PER L'EMFRAC
#jps.AthenaCommonFlags.FilesInput =["/afs/cern.ch/work/g/gsalvi/EMfrac/AOD.12862944._000001.pool.root.1","/afs/cern.ch/work/g/gsalvi/EMfrac/AOD.12862944._000002.pool.root.1","/afs/cern.ch/work/g/gsalvi/EMfrac/AOD.12862944._000003.pool.root.1"]

#SIGNAL CRISTIANO-> DarkPhoton
#jps.AthenaCommonFlags.FilesInput =["/afs/cern.ch/work/g/gsalvi/SIGNAL/mc16_13TeV/AOD.17920917._000012.pool.root.1","/afs/cern.ch/work/g/gsalvi/SIGNAL/mc16_13TeV/AOD.17920917._000010.pool.root.1","/afs/cern.ch/work/g/gsalvi/SIGNAL/mc16_13TeV/AOD.17920917._000013.pool.root.1","/afs/cern.ch/work/g/gsalvi/SIGNAL/mc16_13TeV/AOD.17920917._elle applicate in aeroporto e le operazioni sono molto pi000011         semplici.


#SIGNAL CRISTIANO, QUELLI NUOVI PER E-MAIL (solo adronico)-> DarkPhoton
#jps.AthenaCommonFlags.FilesInput =["/afs/cern.ch/work/g/gsalvi/mc16_13TeV/AOD.17921370._000001.pool.root.1","/afs/cern.ch/work/g/gsalvi/mc16_13TeV/AOD.17921370._000002.pool.root.1", "/afs/cern.ch/work/g/gsalvi/mc16_13TeV/AOD.17921370._000003.pool.root.1"]  



#NON DECOMMENTARE,"/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev/AOD.16301669._000003.pool.root.1 ","/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev/AOD.16301669._000004.pool.root.1","/afs/cern.ch/work/g/gsalvi/AOD_mc16_13Tev/AOD.16301669._000006.pool.root.1"]

#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ0Files_0_tr3.root",


#jps.AthenaCommonFlags.FilesInput =["/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ0Files_0_tr2.root"]
#,"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ1Files_0_tr2.root","/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ1Files_0_tr3.root","/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ2Files_0_tr2.root","/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ2Files_0_tr3.root"]
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ2Files_0_tr2.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ2Files_0_tr3.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ3Files_0_tr2.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ3Files_0_tr3.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ4Files_0_tr2.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ4Files_0_tr3.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ5Files_0_tr2.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ5Files_0_tr3.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ6Files_0_tr2.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ6Files_0_tr3.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ7Files_0_tr2.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ7Files_0_tr3.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ0Files_0_tr4_nEventsFromAOD.root", 
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ1Files_0_tr4_nEventsFromAOD.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ2Files_0_tr4_nEventsFromAOD.root",     
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ2Files_0_tr5_nEventsFromMetaData.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ3Files_0_tr4_nEventsFromAOD.root",       
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ3Files_0_tr5_nEventsFromMetaData.root", 
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ4Files_0_tr4_nEventsFromAOD.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ4Files_0_tr5_nEventsFromMetaData.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ5Files_0_tr4_nEventsFromAOD.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ6Files_0_tr4_nEventsFromAOD.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ6Files_0_tr5_nEventsFromMetaData.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ7Files_0_tr4_nEventsFromAOD.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_JZ7Files_0_tr5_nEventsFromMetaData.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_tr2.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_tr3.root",
#"/afs/cern.ch/work/g/gsalvi/fromJuno/190418_SimpleSelector_tr4.root"]

#myfile2.root
#jps.AthenaCommonFlags.FilesInput =["/afs/cern.ch/work/g/gsalvi/Steven_AOD_mc16_13Tev/AOD.14326460._000001.pool.root.1","/afs/cern.ch/work/g/gsalvi/Steven_AOD_mc16_13Tev/AOD.14326476._000001.pool.root.1","/afs/cern.ch/work/g/gsalvi/Steven_AOD_mc16_13Tev/","/afs/cern.ch/work/g/gsalvi/Steven_AOD_mc16_13Tev/AOD.14397807._000001.pool.root.1","/afs/cern.ch/work/g/gsalvi/Steven_AOD_mc16_13Tev/AOD.14397820._000001.pool.root.1"]



#ENORME CON TUTTO IL SEGNALE DI DARK PHOTON DA 400GeV 900GeV 1000GeV e 2000GeV 
#jps.AthenaCommonFlags.FilesInput =["/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000001.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000003.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000004.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000005.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921274._000001.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921274._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921274._000003.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921274._000004.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921274._000005.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921741._000001.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921741._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921741._000003.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921741._000004.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921741._000005.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921797._000001.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921797._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921797._000003.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921797._000004.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921797._000005.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921797._000006.pool.root.1"]


#jps.AthenaCommonFlags.FilesInput =["/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000001.pool.root.1","eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000003.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000004.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000005.pool.root.1"]



#input 400
 
#jps.AthenaCommonFlags.FilesInput=["/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921370._000001.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921370._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921370._000003.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921370._000004.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921370._000005.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921370._000006.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921370._000007.pool.root.1"]


#,"/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000004.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r9364_r9315/AOD.17921194._000005.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921614._000001.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921614._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921614._000003.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921614._000005.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921614._000006.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921614._000007.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921614._000008.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311982.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd400_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921614._000009.pool.root.1"] 





#input 900
#jps.AthenaCommonFlags.FilesInput =["/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921430._000001.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921430._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921430._000003.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921430._000004.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921430._000005.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921430._000006.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311983.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd900_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921430._000007.pool.root.1"]

#input 2k
#jps.AthenaCommonFlags.FilesInput =["/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921484._000001.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921484._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921484._000003.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921484._000004.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921484._000005.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921484._000006.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311984.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd2k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921484._000007.pool.root.1"]

#input 6k
#jps.AthenaCommonFlags.FilesInput =["/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921533._000001.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921533._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921533._000003.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921533._000004.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921533._000005.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921533._000006.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10201_r10210/AOD.17921533._000007.pool.root.1"]



#Per FTK

#jps.AthenaCommonFlags.FilesInput =["/afs/cern.ch/user/g/gsalvi/mc16_13TeV/AOD.18580628._014988.pool.root.1"]

#,"/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921797._000001.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921797._000002.pool.root.1","/eos/user/g/gsalvi/mc16_13TeV.311985.MGPy8EG_A14NN23LO_FRVZ_2zd_mH800_mzd6k_qqbar.merge.AOD.e7464_e5984_s3126_r10724_r10726/AOD.17921797._000003.pool.root.1"]

include("AthAnalysisBaseComps/SuppressLogging.py")              #Optional include to suppress as much athena output as possible. Keep at bottom of joboptions so that it doesn't suppress the logging of the things you have configured above
