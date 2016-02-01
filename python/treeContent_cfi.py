import FWCore.ParameterSet.Config as cms

##########################################################################
## TREE CONTENT
#########################################################################
    
ZVariablesToStore = cms.PSet(
    eta = cms.string("eta"),
    abseta = cms.string("abs(eta)"),
    pt  = cms.string("pt"),
    mass  = cms.string("mass"),
    )   

SCProbeVariablesToStore = cms.PSet(
    probe_sc_eta    = cms.string("eta"),
    probe_sc_abseta = cms.string("abs(eta)"),
    probe_sc_pt     = cms.string("pt"),
    probe_sc_et     = cms.string("et"),
    probe_sc_e      = cms.string("energy"),
    )

ProbeVariablesToStore = cms.PSet(
    probe_Ele_eta    = cms.string("eta"),
    probe_Ele_abseta = cms.string("abs(eta)"),
    probe_Ele_pt     = cms.string("pt"),
    probe_Ele_et     = cms.string("et"),
    probe_Ele_q      = cms.string("charge"),
    probe_Ele_phi    = cms.string("phi"),
    probe_Ele_isGap  = cms.string("isGap"),
    probe_Ele_isEBEEGap = cms.string("isEBEEGap"),
    probe_Ele_isEBEtaGap = cms.string("isEBEtaGap"),
    probe_Ele_isEBPhiGap = cms.string("isEBPhiGap"),
    probe_Ele_isEEDeeGap = cms.string("isEEDeeGap"),
    probe_Ele_isEERingGap = cms.string("isEERingGap"),
                                 
    ## 4-momentum of electron
    probe_Ele_px    = cms.string("px"),
    probe_Ele_py    = cms.string("py"),
    probe_Ele_pz    = cms.string("pz"),
    probe_Ele_e     = cms.string("energy"),

    
    ## super cluster quantities
    probe_sc_energy = cms.string("superCluster.energy"),
    probe_sc_et     = cms.string("superCluster.energy*sin(superClusterPosition.theta)"),    
    probe_sc_eta    = cms.string("superCluster.eta"),
    probe_sc_abseta = cms.string("abs(superCluster.eta)"),
    
    #id based
    probe_Ele_dEtaIn        = cms.string("deltaEtaSuperClusterTrackAtVtx"),
    probe_Ele_dPhiIn        = cms.string("deltaPhiSuperClusterTrackAtVtx"),
    probe_Ele_sigmaIEtaIEta = cms.string("sigmaIetaIeta"),
    probe_Ele_hoe           = cms.string("hadronicOverEm"),
    probe_Ele_ooemoop       = cms.string("(1.0/ecalEnergy - eSuperClusterOverP/ecalEnergy)"),

    probe_Ele_mHits         = cms.InputTag("eleVarHelper:missinghits"),
    probe_Ele_dz            = cms.InputTag("eleVarHelper:dz"),
    probe_Ele_dxy           = cms.InputTag("eleVarHelper:dxy"),
    probe_Ele_nonTrigMVA    = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
    probe_passing_MVA = cms.InputTag("eleVarHelper:passingSpring15NonTrig"),
     
    #sip
    probe_Ele_ip            = cms.InputTag("eleVarHelper:ip"),
    probe_Ele_iperror       = cms.InputTag("eleVarHelper:iperror"),
    probe_Ele_sip           = cms.InputTag("eleVarHelper:sip"),
                                 
    #isolation
    probe_Ele_chIso         = cms.string("pfIsolationVariables().sumChargedHadronPt"),
    probe_Ele_phoIso        = cms.string("pfIsolationVariables().sumPhotonEt"),
    probe_Ele_neuIso        = cms.string("pfIsolationVariables().sumNeutralHadronEt"),
    probe_Ele_effarea       = cms.InputTag("eleVarHelper:effarea"),
    probe_Ele_rho           = cms.InputTag("eleVarHelper:rho"),
    probe_Ele_ed            = cms.InputTag("eleVarHelper:enedens"),
    probe_Ele_iso           = cms.InputTag("eleVarHelper:iso"),
    probe_Ele_correctediso  = cms.InputTag("eleVarHelper:correctediso"),
    probe_Ele_trkIso        = cms.string("dr03IsolationVariables().tkSumPt"),
                                 
    #FSR photon
    probe_FSRcorr                = cms.InputTag("eleVarHelper:FSRcorr"),
    probe_FSRphoton_px           = cms.InputTag("eleVarHelper:FSRpx"),
    probe_FSRphoton_py           = cms.InputTag("eleVarHelper:FSRpy"),
    probe_FSRphoton_pz           = cms.InputTag("eleVarHelper:FSRpz"),
    probe_FSRphoton_e            = cms.InputTag("eleVarHelper:FSRe"),
                                 
    )

TagVariablesToStore = cms.PSet(
    Ele_eta    = cms.string("eta"),
    Ele_phi    = cms.string("phi"),
    Ele_abseta = cms.string("abs(eta)"),
    Ele_pt     = cms.string("pt"),
    Ele_et     = cms.string("et"),
    Ele_q      = cms.string("charge"),
    Ele_isGap  = cms.string("isGap"),
    
    ## 4-momentum of electron
    Ele_px    = cms.string("px"),
    Ele_py    = cms.string("py"),
    Ele_pz    = cms.string("pz"),
    Ele_e     = cms.string("energy"),
                               
    ## super cluster quantities
    sc_energy = cms.string("superCluster.energy"),
    sc_et     = cms.string("superCluster.energy*sin(superClusterPosition.theta)"),    
    sc_eta    = cms.string("superCluster.eta"),
    sc_abseta = cms.string("abs(superCluster.eta)"),
                               
    #FSR photon
    FSRphoton_px           = cms.InputTag("eleVarHelper:FSRpx"),
    FSRphoton_py           = cms.InputTag("eleVarHelper:FSRpy"),
    FSRphoton_pz           = cms.InputTag("eleVarHelper:FSRpz"),
    FSRphoton_e            = cms.InputTag("eleVarHelper:FSRe"),

    
    Ele_mHits         = cms.InputTag("eleVarHelper:missinghits"),
    Ele_dz            = cms.InputTag("eleVarHelper:dz"),
    Ele_dxy           = cms.InputTag("eleVarHelper:dxy"),
    Ele_nonTrigMVA    = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
    Ele_trigMVA       = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),

    )

CommonStuffForGsfElectronProbe = cms.PSet(
    variables = cms.PSet(ProbeVariablesToStore),
    ignoreExceptions =  cms.bool (True),
    addRunLumiInfo   =  cms.bool (True),
    pileupInfoTag = cms.InputTag("slimmedAddPileupInfo"),
    addEventVariablesInfo   =  cms.bool(True),
    vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices"),
    beamSpot = cms.InputTag("offlineBeamSpot"),
    #pfMet = cms.InputTag("slimmedMETsNoHF"),
    rho = cms.InputTag("fixedGridRhoAll"),
    pairVariables =  cms.PSet(ZVariablesToStore),
    pairFlags     =  cms.PSet(
        mass60to120 = cms.string("60 < mass < 120")
        ),
    tagVariables   =  cms.PSet(TagVariablesToStore),
    tagFlags       =  cms.PSet(passingVeto = cms.InputTag("goodElectronsTAGCutBasedVeto"),
                               passingLoose = cms.InputTag("goodElectronsTAGCutBasedLoose"),
                               passingMedium = cms.InputTag("goodElectronsTAGCutBasedMedium"),
                               passingTight = cms.InputTag("goodElectronsTAGCutBasedTight"),),
    )

CommonStuffForSuperClusterProbe = CommonStuffForGsfElectronProbe.clone()
CommonStuffForSuperClusterProbe.variables = cms.PSet(SCProbeVariablesToStore)

mcTruthCommonStuff = cms.PSet(
    isMC = cms.bool(True),
    #tagMatches = cms.InputTag("McMatchTag"),
    motherPdgId = cms.vint32(),
    #motherPdgId = cms.vint32(22,23),
    #motherPdgId = cms.vint32(443), # JPsi
    #motherPdgId = cms.vint32(553), # Yupsilon
    #makeMCUnbiasTree = cms.bool(False),
    #checkMotherInUnbiasEff = cms.bool(False),
    genParticles = cms.InputTag("prunedGenParticles"),
    useTauDecays = cms.bool(False),
    checkCharge = cms.bool(False),
    pdgId = cms.int32(11),
    mcVariables = cms.PSet(
        probe_eta = cms.string("eta"),
        probe_abseta = cms.string("abs(eta)"),
        probe_et  = cms.string("et"),
        probe_e  = cms.string("energy"),
        ),
    mcFlags     =  cms.PSet(
        probe_flag = cms.string("pt>0")
        ),      
    )

