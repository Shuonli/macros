#ifndef MACRO_JETQA_C
#define MACRO_JETQA_C

#include <fun4all/Fun4AllServer.h>
#include <jetqa/ConstituentsinJets.h>
#include <jetqa/JetKinematicCheck.h>
#include <jetqa/JetQADefs.h>
#include <jetqa/JetSeedCount.h>
#include <jetqa/RhosinEvent.h>
#include <jetqa/StructureinJets.h>
#include <jetqa/TrksInJetQA.h>
#include <jetqa/CaloStatusMapper.h>//add a calo status header
#include <jetqa/DijetQA.h>
#include <jetqa/PhotonJetsKinematics.h>
#include <map>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include <HIJetReco.C>
#include <NoBkgdSubJetReco.C>
#include <QA.C>

R__LOAD_LIBRARY(libjetqa.so)



	// ----------------------------------------------------------------------------
	//! Namespace to collect various enums, default arguments, etc.
	// ----------------------------------------------------------------------------
	namespace JetQA
{

	// flags --------------------------------------------------------------------

	//! Set to true if input jets utilize tracks (e.g. via particle flow)
	bool HasTracks = false;

	//! Set to true if input jets utilize calorimeters(e.g. via particle flow)
	bool HasCalos = false;

	//! Set to true to generate histograms for no trigger selection
	bool DoInclusive = true;

	//! Set to true to generate histograms for a specified set of triggers
	bool DoTriggered = true;

	//! Set to true to restrict minimum jet pt to trigger threshold
	bool RestrictPtToTrig = false;

	//! Set to true to restrict jet eta acceptance by resolution parameter
	bool RestrictEtaByR = true;



	// enums --------------------------------------------------------------------

	enum Type
	{
		AntiKtTowerSubR02,
		AntiKtTowerSubR03,
		AntiKtTowerSubR04,
		AntiKtTowerSubR05,
		AntiKtTowerR02,
		AntiKtTowerR03,
		AntiKtTowerR04,
                AntiKtTowerR05,
		AntiKtTrackR02,
		AntiKtTrackR03,
		AntiKtTrackR04,
		AntiKtTrackR05
	};



	// constants ----------------------------------------------------------------

	//! Min jet pt in GeV/c
	double MinJetPt = 6.;

	//! Max jet pt in GeV/c
	double MaxJetPt = 100.;

	//! Min eta acceptance
	double MinAcceptEta = -1.1;

	//! Max eta acceptance
	double MaxAcceptEta = 1.1;

	//! Inclusive tag
	std::string InclusiveTag = "inclusive";



	// maps ---------------------------------------------------------------------

	//! Map from trigger to histogram tag
	std::map<uint32_t, std::string> GL1Tag = {
		{JetQADefs::GL1::Clock, "clock"},
		{JetQADefs::GL1::ZDCS, "zdcs"},
		{JetQADefs::GL1::ZDCN, "zdcn"},
		{JetQADefs::GL1::ZDCNS, "zdcns"},
		{JetQADefs::GL1::HCalSingle, "hcalsingle"},
		{JetQADefs::GL1::MBDS, "mbds"},
		{JetQADefs::GL1::MBDN, "mbdn"},
		{JetQADefs::GL1::MBDNS1, "mbdns1"},
		{JetQADefs::GL1::MBDNS2, "mbdns2"},
		{JetQADefs::GL1::MBDNSVtx10, "mbdnsvtx10"},
		{JetQADefs::GL1::MBDNSVtx30, "mbdnsvtx30"},
		{JetQADefs::GL1::MBDNSVtx60, "mbdnsvtx60"},
		{JetQADefs::GL1::MBDNSHCalSingle, "mbdnshcalsingle"},
		{JetQADefs::GL1::MBDNSJet1, "mbdnsjet1"},
		{JetQADefs::GL1::MBDNSJet2, "mbdnsjet2"},
		{JetQADefs::GL1::MBDNSJet3, "mbdnsjet3"},
		{JetQADefs::GL1::MBDNSJet4, "mbdnsjet4"},
		{JetQADefs::GL1::Jet1, "jet1"},
		{JetQADefs::GL1::Jet2, "jet2"},
		{JetQADefs::GL1::Jet3, "jet3"},
		{JetQADefs::GL1::Jet4, "jet4"},
		{JetQADefs::GL1::MBDNSPhoton1, "mbdnsphoton1"},
		{JetQADefs::GL1::MBDNSPhoton2, "mbdnsphoton2"},
		{JetQADefs::GL1::MBDNSPhoton3, "mbdnsphoton3"},
		{JetQADefs::GL1::MBDNSPhoton4, "mbdnsphoton4"},
		{JetQADefs::GL1::Photon1, "photon1"},
		{JetQADefs::GL1::Photon2, "photon2"},
		{JetQADefs::GL1::Photon3, "photon3"},
		{JetQADefs::GL1::Photon4, "photon4"} 
	};

	//! Map from jet type to input node
	std::map<uint32_t, std::string> JetInput = {
		{Type::AntiKtTowerSubR02, "AntiKt_Tower_r02_Sub1"},
		{Type::AntiKtTowerSubR03, "AntiKt_Tower_r03_Sub1"},
		{Type::AntiKtTowerSubR04, "AntiKt_Tower_r04_Sub1"},
		{Type::AntiKtTowerSubR05, "AntiKt_Tower_r05_Sub1"},
		{Type::AntiKtTowerR02, "AntiKt_Tower_r02"},
                {Type::AntiKtTowerR03, "AntiKt_Tower_r03"},
                {Type::AntiKtTowerR04, "AntiKt_Tower_r04"},
                {Type::AntiKtTowerR05, "AntiKt_Tower_r05"},
		{Type::AntiKtTrackR02, "AntiKt_Track_r02"},
                {Type::AntiKtTrackR03, "AntiKt_Track_r03"},
                {Type::AntiKtTrackR04, "AntiKt_Track_r04"},
                {Type::AntiKtTrackR05, "AntiKt_Track_r05"}

	};

	//! Map from jet type to histogram tag
	std::map<uint32_t, std::string> JetTag = {
		{Type::AntiKtTowerSubR02, "towersub1_antikt_r02"},
		{Type::AntiKtTowerSubR03, "towersub1_antikt_r03"},
		{Type::AntiKtTowerSubR04, "towersub1_antikt_r04"},
		{Type::AntiKtTowerSubR05, "towersub1_antikt_r05"},
	 	{Type::AntiKtTowerR02, "tower_antikt_r02"},
         	{Type::AntiKtTowerR03, "tower_antikt_r03"},
         	{Type::AntiKtTowerR04, "tower_antikt_r04"},
         	{Type::AntiKtTowerR05, "tower_antikt_r05"},
	 	{Type::AntiKtTrackR02, "track_antikt_r02"},
         	{Type::AntiKtTrackR03, "track_antikt_r03"},
         	{Type::AntiKtTrackR04, "track_antikt_r04"},
         	{Type::AntiKtTrackR05, "track_antikt_r05"}
	};

	//! Map from jet type to resolution parameter
	std::map<uint32_t, double> JetRes = {
		{Type::AntiKtTowerSubR02, 0.2},
		{Type::AntiKtTowerSubR03, 0.3},
		{Type::AntiKtTowerSubR04, 0.4},
		{Type::AntiKtTowerSubR05, 0.5},
                {Type::AntiKtTowerR02, 0.2},
                {Type::AntiKtTowerR03, 0.3},
                {Type::AntiKtTowerR04, 0.4},
                {Type::AntiKtTowerR05, 0.5},
	        {Type::AntiKtTrackR02, 0.2},
                {Type::AntiKtTrackR03, 0.3},
                {Type::AntiKtTrackR04, 0.4},
                {Type::AntiKtTrackR05, 0.5}
	};



	// methods ------------------------------------------------------------------

	// --------------------------------------------------------------------------
	//! Get trigger tag
	// --------------------------------------------------------------------------
	/*! If a trigger index is provided (i.e. a trigger is being selected),
	 *  function returns the correpsonding tag. Otherwise (i.e. NO trigger
	 *  is being selected), returns the inclusive tag.
	 */
	inline std::string GetTriggerTag(std::optional<uint32_t> trg = std::nullopt)
	{

		std::string tag("");
		if (trg.has_value())
		{
			tag.append("_" + GL1Tag[trg.value()]);
		}
		else
		{
			tag.append("_" + InclusiveTag);
		}
		return tag;

	}  // end 'GetTriggerTag(std::optional<uint32_t>)'



	// --------------------------------------------------------------------------
	//! Get minimum jet pt based on which trigger fired
	// --------------------------------------------------------------------------
	// FIXME it might be prudent to allow for thresholds to change vs. run
	//   number... Before run 46038, the Jet1, 2 thresholds were different
	inline double GetMinJetPt(const uint32_t trg = JetQADefs::GL1::MBDNSJet1)
	{

		// by defult, set min to global constant
		double ptJetMin = MinJetPt;

		// if restricting pt to trigger threhsold, pick out relevant threshold
		if (RestrictPtToTrig)
		{
			switch (trg)
			{
				// Jet4 threshold
				case JetQADefs::GL1::MBDNSJet4:
					[[fallthrough]];
				case JetQADefs::GL1::Jet4:
					ptJetMin = 11.;
					break;

					// Jet3 threshold
				case JetQADefs::GL1::MBDNSJet3:
					[[fallthrough]];
				case JetQADefs::GL1::Jet3:
					ptJetMin = 10.;
					break;

					// Jet2 threshold
				case JetQADefs::GL1::MBDNSJet2:
					[[fallthrough]];
				case JetQADefs::GL1::Jet2:
					ptJetMin = 9.;
					break;

					// Jet1 threshold (default value)
				case JetQADefs::GL1::MBDNSJet1:
					[[fallthrough]];
				case JetQADefs::GL1::Jet1:
					[[fallthrough]];
				default:
					ptJetMin = 6.;
					break;
			}
		}
		return ptJetMin;

	}  // end 'GetMinJetPt(uint32_t)'



	// --------------------------------------------------------------------------
	//! Get default jet pt range
	// --------------------------------------------------------------------------
	inline std::pair<double, double> GetJetPtRange(std::optional<uint32_t> trg = std::nullopt)
	{

		std::pair<double, double> ptJetRange;
		if (trg.has_value())
		{
			ptJetRange = {GetMinJetPt(trg.value()), MaxJetPt};
		}
		else
		{
			ptJetRange = {GetMinJetPt(), MaxJetPt};
		}
		return ptJetRange;

	}  // end 'GetJetPtRange(std::optional<uint32_t>)'



	// --------------------------------------------------------------------------
	//! Get default jet eta range
	// --------------------------------------------------------------------------
	inline std::pair<double, double> GetJetEtaRange(const double res = 0.)
	{

		// determine relevant min/max
		const double etaMin = RestrictEtaByR ? MinAcceptEta + res : MinAcceptEta;
		const double etaMax = RestrictEtaByR ? MaxAcceptEta - res : MaxAcceptEta;

		// return range
		std::pair<double, double> etaJetRange = {etaMin, etaMax};
		return etaJetRange;

	}  // end 'GetJetEtaRange(double)'



	// --------------------------------------------------------------------------
	//! Get default list of triggers to analyze
	// --------------------------------------------------------------------------
	inline std::vector<uint32_t> GetDefaultTriggerList()
	{

		// default jets for pp
		std::vector<uint32_t> vecDefaultTrigsPP = {
			JetQADefs::GL1::MBDNS1,
			JetQADefs::GL1::MBDNSJet1,
			JetQADefs::GL1::MBDNSJet2,
			JetQADefs::GL1::MBDNSJet3,
			JetQADefs::GL1::MBDNSJet4,
			JetQADefs::GL1::Jet1,
			JetQADefs::GL1::Jet2,
			JetQADefs::GL1::Jet3,
			JetQADefs::GL1::Jet4
		};

		// default jets for AuAu
		//   - n.b. the thresholds were changed 10, 60, and
		//     150 cm respectively during AuAu run
		std::vector<uint32_t> vecDefaultTrigsAA = {
			JetQADefs::GL1::MBDNSVtx10,  // actually 10 cm
			JetQADefs::GL1::MBDNSVtx30,  // actually 60 cm
			JetQADefs::GL1::MBDNSVtx60   // actually 150 cm 
		};

		if (HIJETS::is_pp)
		{
			return vecDefaultTrigsPP;
		}
		else
		{
			return vecDefaultTrigsAA;
		}

	}  // end 'GetDefaultTriggerList()'



	// --------------------------------------------------------------------------
	//! Get list of jets to analyze
	// --------------------------------------------------------------------------
	inline std::vector<uint32_t> GetJetsToQA()
	{

		std::vector<uint32_t> vecJetsToQA = {
			Type::AntiKtTowerSubR02,
			Type::AntiKtTowerSubR03,
			Type::AntiKtTowerSubR04,
			Type::AntiKtTowerSubR05,
			Type::AntiKtTowerR02,
                        Type::AntiKtTowerR03,
                        Type::AntiKtTowerR04,
                        Type::AntiKtTowerR05,
			Type::AntiKtTrackR02,
                        Type::AntiKtTrackR03,
                        Type::AntiKtTrackR04,
                        Type::AntiKtTrackR05
				
		};
		return vecJetsToQA;

	}  // end 'GetJetsToQA()'

}  // end JetQA namespace



// ----------------------------------------------------------------------------
//! Create QA modules for all jets, regardless of constituents
// ----------------------------------------------------------------------------
void CommonJetQA(std::optional<uint32_t> trg = std::nullopt)
{

	// set verbosity
	int verbosity = std::max({Enable::QA_VERBOSITY, Enable::HIJETS_VERBOSITY,Enable::NSJETS_VERBOSITY});

	// grab appropriate trigger tag
	std::string trig_tag = JetQA::GetTriggerTag(trg);

	// grab default pt, eta ranges
	std::pair<double, double> ptJetRange = JetQA::GetJetPtRange(trg);
	std::pair<double, double> etaJetMaxRange = JetQA::GetJetEtaRange();

	// get list of jet nodes to analyze
	std::vector<uint32_t> vecJetsToQA = JetQA::GetJetsToQA();

	// connect to f4a server
	Fun4AllServer* se = Fun4AllServer::instance();

	// create modules that are independent of/take multiple R values ------------

	// initialize and register mass, eta, and pt qa module
	// this part is for subtracted background towers 
	JetKinematicCheck* kinematicQA = new JetKinematicCheck(
			"JetKinematicCheck" + trig_tag + "_towersub1_antikt",
			JetQA::JetInput[JetQA::Type::AntiKtTowerSubR02],
			JetQA::JetInput[JetQA::Type::AntiKtTowerSubR03],
			JetQA::JetInput[JetQA::Type::AntiKtTowerSubR04],
			JetQA::JetInput[JetQA::Type::AntiKtTowerSubR05]
			);
	kinematicQA -> Verbosity(verbosity);
	kinematicQA -> setHistTag("");
	kinematicQA -> setRestrictEtaRange(JetQA::RestrictEtaByR);
	kinematicQA -> setPtRange(ptJetRange.first, ptJetRange.second);
	kinematicQA -> setEtaRange(etaJetMaxRange.first, etaJetMaxRange.second);
	if (trg.has_value())
	{
		kinematicQA -> setTrgToSelect(trg.value());
	}
	se -> registerSubsystem(kinematicQA);
	//this part is for no subtracted background towers
	JetKinematicCheck* kinematicQA_NoSub = new JetKinematicCheck(
                        "JetKinematicCheck" + trig_tag + "_tower_antikt",
                        JetQA::JetInput[JetQA::Type::AntiKtTowerR02],
                        JetQA::JetInput[JetQA::Type::AntiKtTowerR03],
                        JetQA::JetInput[JetQA::Type::AntiKtTowerR04],
                        JetQA::JetInput[JetQA::Type::AntiKtTowerR05]
                        );
        kinematicQA_NoSub -> Verbosity(verbosity);
        kinematicQA_NoSub -> setHistTag("");
        kinematicQA_NoSub -> setRestrictEtaRange(JetQA::RestrictEtaByR);
        kinematicQA_NoSub -> setPtRange(ptJetRange.first, ptJetRange.second);
        kinematicQA_NoSub -> setEtaRange(etaJetMaxRange.first, etaJetMaxRange.second);
        if (trg.has_value())
        {
                kinematicQA_NoSub -> setTrgToSelect(trg.value());
        }
        se -> registerSubsystem(kinematicQA_NoSub);

	//this part is for no subtracted background towers
	
        JetKinematicCheck* kinematicQA_Tracks = new JetKinematicCheck(
                        "JetKinematicCheck" + trig_tag + "_track_antikt",
                        JetQA::JetInput[JetQA::Type::AntiKtTrackR02],
                        JetQA::JetInput[JetQA::Type::AntiKtTrackR03],
                        JetQA::JetInput[JetQA::Type::AntiKtTrackR04],
                        JetQA::JetInput[JetQA::Type::AntiKtTrackR05]
                        );
        kinematicQA_Tracks -> Verbosity(verbosity);
        kinematicQA_Tracks -> setHistTag("");
        kinematicQA_Tracks -> setRestrictEtaRange(JetQA::RestrictEtaByR);
        kinematicQA_Tracks -> setPtRange(ptJetRange.first, ptJetRange.second);
        kinematicQA_Tracks -> setEtaRange(etaJetMaxRange.first, etaJetMaxRange.second);
        if (trg.has_value())
        {
                kinematicQA_Tracks -> setTrgToSelect(trg.value());
        }
        se -> registerSubsystem(kinematicQA_Tracks);	
	
	// create modules that take single R values ---------------------------------

	for (uint32_t jet : vecJetsToQA)
	{

		// get R-dependent eta range
		std::pair<double, double> etaJetRange = JetQA::GetJetEtaRange(JetQA::JetRes[jet]);

		// initialize and register jet seed counter qa module
		JetSeedCount* jetSeedQA = new JetSeedCount(
				"JetSeedCount" + trig_tag + "_" + JetQA::JetTag[jet],
				JetQA::JetInput[jet],
				"AntiKt_TowerInfo_HIRecoSeedsRaw_r02",
				"AntiKt_TowerInfo_HIRecoSeedsSub_r02"
				);
		jetSeedQA -> Verbosity(verbosity);
		jetSeedQA -> setHistTag("");
		jetSeedQA -> setPtRange(ptJetRange.first, ptJetRange.second);
		jetSeedQA -> setEtaRange(etaJetRange.first, etaJetRange.second);
		jetSeedQA -> setWriteToOutputFile(false);
		jetSeedQA -> setPPMode(HIJETS::is_pp);
		if (trg.has_value())
		{
			jetSeedQA -> setTrgToSelect(trg.value());
		}
		se -> registerSubsystem(jetSeedQA);

	}  // end jet loop
	return;

}  // end 'CommonJetQA(std::optional<uint32_t>)'



// ----------------------------------------------------------------------------
//! Create QA modules for jets with tracks
// ----------------------------------------------------------------------------
void JetsWithTracksQA(std::optional<uint32_t> trg = std::nullopt)
{

	// set verbosity
	int verbosity = std::max({Enable::QA_VERBOSITY, Enable::HIJETS_VERBOSITY,Enable::NSJETS_VERBOSITY});

	// grab appropriate trigger tag
	std::string trig_tag = JetQA::GetTriggerTag(trg);

	// grab default pt, eta ranges
	std::pair<double, double> ptJetRange = JetQA::GetJetPtRange(trg);
	std::pair<double, double> etaJetRange = JetQA::GetJetEtaRange();

	// get list of jet nodes to analyze
	std::vector<uint32_t> vecJetsToQA = JetQA::GetJetsToQA();

	// connect to f4a server
	Fun4AllServer* se = Fun4AllServer::instance();

	// create modules that take single R values ---------------------------------

	for (uint32_t jet : vecJetsToQA)
	{

		// intialize and register sum track vs. jet pt qa module
		StructureinJets* jetStructQA = new StructureinJets(
				"StructureInJets" + trig_tag + "_" + JetQA::JetTag[jet],
				JetQA::JetInput[jet],
				""
				);
		jetStructQA -> Verbosity(verbosity);
		jetStructQA -> writeToOutputFile(false);
		if (trg.has_value())
		{
			jetStructQA -> setTrgToSelect(trg.value());
		}
		se -> registerSubsystem(jetStructQA);

		// initialize and register track jet qa module
		TrksInJetQA* trksInJetQA = new TrksInJetQA("TrksInJet" + trig_tag + "_" + JetQA::JetTag[jet]);
		trksInJetQA -> SetHistSuffix("");
		trksInJetQA -> Configure(
				{
				.outMode     = TrksInJetQA::OutMode::QA,
				.verbose     = Enable::QA_VERBOSITY,
				.doDebug     = false,
				.doInclusive = false,
				.doInJet     = true,
				.doHitQA     = false,
				.doClustQA   = true,
				.doTrackQA   = true,
				.doJetQA     = true,
				.rJet        = 0.4,
				.jetInNode   = JetQA::JetInput[jet]
				}
				);
		if (trg.has_value())
		{
			trksInJetQA -> SetTrgToSelect(trg.value());
		}
		se -> registerSubsystem(trksInJetQA);

	}  // end jet loop
	return;

}  // end 'JetWithTracksQA(std::optional<uint32_t>)'

// ----------------------------------------------------------------------------
//! Create QA modules for jets with clusters(Calo)
// ----------------------------------------------------------------------------

void JetsWithCaloQA(std::optional<uint32_t> trg = std::nullopt)
{

	std::cout << ">>> Entering JetsWithCaloQA() with trg=" 
		<< (trg.has_value() ? std::to_string(trg.value()) : "none") 
		<< std::endl;

	// set verbosity
	int verbosity = std::max({Enable::QA_VERBOSITY, Enable::HIJETS_VERBOSITY,Enable::NSJETS_VERBOSITY});

	// grab appropriate trigger tag
	std::string trig_tag = JetQA::GetTriggerTag(trg);

	// grab default pt, eta ranges
	std::pair<double, double> ptJetRange = JetQA::GetJetPtRange(trg);
	std::pair<double, double> etaJetRange = JetQA::GetJetEtaRange();

	// get list of jet nodes to analyze
	std::vector<uint32_t> vecJetsToQA = JetQA::GetJetsToQA();

	// connect to f4a server
	Fun4AllServer* se = Fun4AllServer::instance();

	// Configure the CaloStatusMapper module
	CaloStatusMapper::Config caloMapCfg;
	caloMapCfg.debug = false;  // Enable debugging if desired
	// Append the trigger tag to the module name for clarity
	caloMapCfg.moduleName = "CaloStatusMapper" + trig_tag;
	// Optionally, you can set a histogram tag (empty string in this case)
	caloMapCfg.histTag = "";

	// Enable trigger selection if a trigger is provided
	if (trg.has_value())
	{
		caloMapCfg.doTrgSelect = true;
		caloMapCfg.trgToSelect = trg.value();
	}else{
	 caloMapCfg.doTrgSelect = false;
	}


	// Instantiate the CaloStatusMapper QA module using the configuration
	CaloStatusMapper* caloQA = new CaloStatusMapper(caloMapCfg);

	// Register the calorimeter QA module with the Fun4All server
	se->registerSubsystem(caloQA);

	// initialize and register photon jet kinematic QA
	
	std::string moduleName = "PhotonJetsKinematics" + trig_tag;
	  std::string inputNode = "CLUSTERINFO_CEMC";
	  std::string histTag = "";
	  PhotonJetsKinematics *photonJets = new PhotonJetsKinematics(moduleName, inputNode, histTag);
	  if (trg.has_value())
		  {
			    photonJets->SetTrgToSelect(trg.value());
			  }
	  se->registerSubsystem(photonJets);

	// initialize and register event-wise rho check
	
	RhosinEvent* evtRhoQA = new RhosinEvent("EventWiseRho" + trig_tag, "");
	evtRhoQA -> Verbosity(verbosity);
	evtRhoQA -> add_area_rho_node("TowerRho_AREA");
	evtRhoQA -> add_mult_rho_node("TowerRho_MULT");
	if (trg.has_value())
	{
		evtRhoQA -> setTrgToSelect(trg.value());
	}
	se -> registerSubsystem(evtRhoQA);
	for (uint32_t jet : vecJetsToQA)
	{

		// get R-dependent eta range
		std::pair<double, double> etaJetRange = JetQA::GetJetEtaRange(JetQA::JetRes[jet]);
		// initialize and register constituent checks
		ConstituentsinJets* jetCstQA = new ConstituentsinJets(
				"ConstituentsInJets" + trig_tag + "_" + JetQA::JetTag[jet],
				JetQA::JetInput[jet],
				"TowerInfoBackground_Sub1",
				""
				);
		jetCstQA -> Verbosity(verbosity);
		jetCstQA -> setPtRange(ptJetRange.first, ptJetRange.second);
		jetCstQA -> setEtaRange(etaJetRange.first, etaJetRange.second);
		if (trg.has_value())
		{
			jetCstQA -> setTrgToSelect(trg.value());
		}
		se -> registerSubsystem(jetCstQA); 
	}
	
	return;
}  // end 'JetsWithCaloQA(std::optional<uint32_t>)'


// ----------------------------------------------------------------------------
//! Run jet QA
// ----------------------------------------------------------------------------
void Jet_QA(std::vector<uint32_t> vecTrigsToUse = JetQA::GetDefaultTriggerList())
{

	// run in inclusive mode if needed
	if (JetQA::DoInclusive)
	{
		CommonJetQA();
		if (JetQA::HasTracks)
		{
			JetsWithTracksQA();
		}
		if (JetQA::HasCalos){
			JetsWithCaloQA();

		}

	}

	// run in triggered mode if needed
	if (JetQA::DoTriggered)
	{
		for (uint32_t trg : vecTrigsToUse)
		{
			CommonJetQA(trg);
			if (JetQA::HasTracks)
			{
				JetsWithTracksQA(trg);
			}

			if (JetQA::HasCalos){
				JetsWithCaloQA(trg);
			}
		}  // end trigger loop
	}
	return;

}  // end 'Jet_QA(std::vector<uint32_t>)'

#endif

// end ---------------------------------------------
