import FWCore.ParameterSet.Config as cms

process = cms.Process("tnp")

process.source = cms.Source("PoolSource",
    eventsToProcess = cms.untracked.VEventRange(),
    fileNames = cms.untracked.vstring('file:/home/llr/cms/tsculac/Moriond2016/CMSSW_7_6_3/src/PhysicsTools/TagAndProbe/test/00A623C4-D1B8-E511-955B-78E7D122BCE0.root')
)
process.GsfMatchedSuperClusterCands = cms.EDProducer("ElectronMatchedCandidateProducer",
    ReferenceElectronCollection = cms.untracked.InputTag("goodElectrons"),
    cut = cms.string('abs(eta)<2.5 && !(1.4442< abs(eta) <1.566) && et>7.0'),
    src = cms.InputTag("superClusterCands")
)


process.McMatchHLT = cms.EDProducer("MCTruthDeltaRMatcherNew",
    checkCharge = cms.bool(True),
    distMin = cms.double(0.3),
    matchPDGId = cms.vint32(11),
    matched = cms.InputTag("prunedGenParticles"),
    src = cms.InputTag("goodElectrons")
)


process.McMatchRECO = cms.EDProducer("MCTruthDeltaRMatcherNew",
    checkCharge = cms.bool(True),
    distMin = cms.double(0.2),
    matchPDGId = cms.vint32(11),
    matched = cms.InputTag("prunedGenParticles"),
    src = cms.InputTag("goodElectrons")
)


process.McMatchSC = cms.EDProducer("MCTruthDeltaRMatcherNew",
    checkCharge = cms.bool(False),
    distMin = cms.double(0.3),
    matchPDGId = cms.vint32(11),
    matched = cms.InputTag("prunedGenParticles"),
    src = cms.InputTag("goodSuperClusters")
)


process.McMatchTag = cms.EDProducer("MCTruthDeltaRMatcherNew",
    checkCharge = cms.bool(True),
    distMin = cms.double(0.2),
    matchPDGId = cms.vint32(11),
    matched = cms.InputTag("prunedGenParticles"),
    src = cms.InputTag("goodElectronsTAGCutBasedTight")
)


process.egmGsfElectronIDs = cms.EDProducer("VersionedGsfElectronIdProducer",
    physicsObjectIDs = cms.VPSet(cms.PSet(
        idDefinition = cms.PSet(
            cutFlow = cms.VPSet(cms.PSet(
                cutName = cms.string('MinPtCut'),
                isIgnored = cms.bool(False),
                minPt = cms.double(5.0),
                needsAdditionalProducts = cms.bool(False)
            ), 
                cms.PSet(
                    allowedEtaRanges = cms.VPSet(cms.PSet(
                        maxEta = cms.double(1.479),
                        minEta = cms.double(0.0)
                    ), 
                        cms.PSet(
                            maxEta = cms.double(2.5),
                            minEta = cms.double(1.479)
                        )),
                    cutName = cms.string('GsfEleSCEtaMultiRangeCut'),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False),
                    useAbsEta = cms.bool(True)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleDEtaInCut'),
                    dEtaInCutValueEB = cms.double(0.0105),
                    dEtaInCutValueEE = cms.double(0.00814),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleDPhiInCut'),
                    dPhiInCutValueEB = cms.double(0.115),
                    dPhiInCutValueEE = cms.double(0.182),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleFull5x5SigmaIEtaIEtaCut'),
                    full5x5SigmaIEtaIEtaCutValueEB = cms.double(0.0103),
                    full5x5SigmaIEtaIEtaCutValueEE = cms.double(0.0301),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleHadronicOverEMCut'),
                    hadronicOverEMCutValueEB = cms.double(0.104),
                    hadronicOverEMCutValueEE = cms.double(0.0897),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleDxyCut'),
                    dxyCutValueEB = cms.double(0.0261),
                    dxyCutValueEE = cms.double(0.118),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(True),
                    vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                    vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleDzCut'),
                    dzCutValueEB = cms.double(0.41),
                    dzCutValueEE = cms.double(0.822),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(True),
                    vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                    vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleEInverseMinusPInverseCut'),
                    eInverseMinusPInverseCutValueEB = cms.double(0.102),
                    eInverseMinusPInverseCutValueEE = cms.double(0.126),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleEffAreaPFIsoCut'),
                    effAreasConfigFile = cms.FileInPath('RecoEgamma/ElectronIdentification/data/Spring15/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_25ns.txt'),
                    isIgnored = cms.bool(False),
                    isRelativeIso = cms.bool(True),
                    isoCutEBHighPt = cms.double(0.0893),
                    isoCutEBLowPt = cms.double(0.0893),
                    isoCutEEHighPt = cms.double(0.121),
                    isoCutEELowPt = cms.double(0.121),
                    needsAdditionalProducts = cms.bool(True),
                    ptCutOff = cms.double(20.0),
                    rho = cms.InputTag("fixedGridRhoFastjetAll")
                ), 
                cms.PSet(
                    beamspotSrc = cms.InputTag("offlineBeamSpot"),
                    conversionSrc = cms.InputTag("allConversions"),
                    conversionSrcMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
                    cutName = cms.string('GsfEleConversionVetoCut'),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(True)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleMissingHitsCut'),
                    isIgnored = cms.bool(False),
                    maxMissingHitsEB = cms.uint32(2),
                    maxMissingHitsEE = cms.uint32(1),
                    needsAdditionalProducts = cms.bool(False)
                )),
            idName = cms.string('cutBasedElectronID-Spring15-25ns-V1-standalone-loose')
        ),
        idMD5 = cms.string('4fab9e4d09a2c1a36cbbd2279deb3627'),
        isPOGApproved = cms.untracked.bool(True)
    ), 
        cms.PSet(
            idDefinition = cms.PSet(
                cutFlow = cms.VPSet(cms.PSet(
                    cutName = cms.string('MinPtCut'),
                    isIgnored = cms.bool(False),
                    minPt = cms.double(5.0),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                    cms.PSet(
                        allowedEtaRanges = cms.VPSet(cms.PSet(
                            maxEta = cms.double(1.479),
                            minEta = cms.double(0.0)
                        ), 
                            cms.PSet(
                                maxEta = cms.double(2.5),
                                minEta = cms.double(1.479)
                            )),
                        cutName = cms.string('GsfEleSCEtaMultiRangeCut'),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False),
                        useAbsEta = cms.bool(True)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDEtaInCut'),
                        dEtaInCutValueEB = cms.double(0.0103),
                        dEtaInCutValueEE = cms.double(0.00733),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDPhiInCut'),
                        dPhiInCutValueEB = cms.double(0.0336),
                        dPhiInCutValueEE = cms.double(0.114),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleFull5x5SigmaIEtaIEtaCut'),
                        full5x5SigmaIEtaIEtaCutValueEB = cms.double(0.0101),
                        full5x5SigmaIEtaIEtaCutValueEE = cms.double(0.0283),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleHadronicOverEMCut'),
                        hadronicOverEMCutValueEB = cms.double(0.0876),
                        hadronicOverEMCutValueEE = cms.double(0.0678),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDxyCut'),
                        dxyCutValueEB = cms.double(0.0118),
                        dxyCutValueEE = cms.double(0.0739),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True),
                        vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                        vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDzCut'),
                        dzCutValueEB = cms.double(0.373),
                        dzCutValueEE = cms.double(0.602),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True),
                        vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                        vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleEInverseMinusPInverseCut'),
                        eInverseMinusPInverseCutValueEB = cms.double(0.0174),
                        eInverseMinusPInverseCutValueEE = cms.double(0.0898),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleEffAreaPFIsoCut'),
                        effAreasConfigFile = cms.FileInPath('RecoEgamma/ElectronIdentification/data/Spring15/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_25ns.txt'),
                        isIgnored = cms.bool(False),
                        isRelativeIso = cms.bool(True),
                        isoCutEBHighPt = cms.double(0.0766),
                        isoCutEBLowPt = cms.double(0.0766),
                        isoCutEEHighPt = cms.double(0.0678),
                        isoCutEELowPt = cms.double(0.0678),
                        needsAdditionalProducts = cms.bool(True),
                        ptCutOff = cms.double(20.0),
                        rho = cms.InputTag("fixedGridRhoFastjetAll")
                    ), 
                    cms.PSet(
                        beamspotSrc = cms.InputTag("offlineBeamSpot"),
                        conversionSrc = cms.InputTag("allConversions"),
                        conversionSrcMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
                        cutName = cms.string('GsfEleConversionVetoCut'),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleMissingHitsCut'),
                        isIgnored = cms.bool(False),
                        maxMissingHitsEB = cms.uint32(2),
                        maxMissingHitsEE = cms.uint32(1),
                        needsAdditionalProducts = cms.bool(False)
                    )),
                idName = cms.string('cutBasedElectronID-Spring15-25ns-V1-standalone-medium')
            ),
            idMD5 = cms.string('aa291aba714c148fcba156544907c440'),
            isPOGApproved = cms.untracked.bool(True)
        ), 
        cms.PSet(
            idDefinition = cms.PSet(
                cutFlow = cms.VPSet(cms.PSet(
                    cutName = cms.string('MinPtCut'),
                    isIgnored = cms.bool(False),
                    minPt = cms.double(5.0),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                    cms.PSet(
                        allowedEtaRanges = cms.VPSet(cms.PSet(
                            maxEta = cms.double(1.479),
                            minEta = cms.double(0.0)
                        ), 
                            cms.PSet(
                                maxEta = cms.double(2.5),
                                minEta = cms.double(1.479)
                            )),
                        cutName = cms.string('GsfEleSCEtaMultiRangeCut'),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False),
                        useAbsEta = cms.bool(True)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDEtaInCut'),
                        dEtaInCutValueEB = cms.double(0.00926),
                        dEtaInCutValueEE = cms.double(0.00724),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDPhiInCut'),
                        dPhiInCutValueEB = cms.double(0.0336),
                        dPhiInCutValueEE = cms.double(0.0918),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleFull5x5SigmaIEtaIEtaCut'),
                        full5x5SigmaIEtaIEtaCutValueEB = cms.double(0.0101),
                        full5x5SigmaIEtaIEtaCutValueEE = cms.double(0.0279),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleHadronicOverEMCut'),
                        hadronicOverEMCutValueEB = cms.double(0.0597),
                        hadronicOverEMCutValueEE = cms.double(0.0615),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDxyCut'),
                        dxyCutValueEB = cms.double(0.0111),
                        dxyCutValueEE = cms.double(0.0351),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True),
                        vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                        vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDzCut'),
                        dzCutValueEB = cms.double(0.0466),
                        dzCutValueEE = cms.double(0.417),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True),
                        vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                        vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleEInverseMinusPInverseCut'),
                        eInverseMinusPInverseCutValueEB = cms.double(0.012),
                        eInverseMinusPInverseCutValueEE = cms.double(0.00999),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleEffAreaPFIsoCut'),
                        effAreasConfigFile = cms.FileInPath('RecoEgamma/ElectronIdentification/data/Spring15/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_25ns.txt'),
                        isIgnored = cms.bool(False),
                        isRelativeIso = cms.bool(True),
                        isoCutEBHighPt = cms.double(0.0354),
                        isoCutEBLowPt = cms.double(0.0354),
                        isoCutEEHighPt = cms.double(0.0646),
                        isoCutEELowPt = cms.double(0.0646),
                        needsAdditionalProducts = cms.bool(True),
                        ptCutOff = cms.double(20.0),
                        rho = cms.InputTag("fixedGridRhoFastjetAll")
                    ), 
                    cms.PSet(
                        beamspotSrc = cms.InputTag("offlineBeamSpot"),
                        conversionSrc = cms.InputTag("allConversions"),
                        conversionSrcMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
                        cutName = cms.string('GsfEleConversionVetoCut'),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleMissingHitsCut'),
                        isIgnored = cms.bool(False),
                        maxMissingHitsEB = cms.uint32(2),
                        maxMissingHitsEE = cms.uint32(1),
                        needsAdditionalProducts = cms.bool(False)
                    )),
                idName = cms.string('cutBasedElectronID-Spring15-25ns-V1-standalone-tight')
            ),
            idMD5 = cms.string('4e13b87c0573d3c8ebf91d446fa1d90f'),
            isPOGApproved = cms.untracked.bool(True)
        ), 
        cms.PSet(
            idDefinition = cms.PSet(
                cutFlow = cms.VPSet(cms.PSet(
                    cutName = cms.string('MinPtCut'),
                    isIgnored = cms.bool(False),
                    minPt = cms.double(5.0),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                    cms.PSet(
                        allowedEtaRanges = cms.VPSet(cms.PSet(
                            maxEta = cms.double(1.479),
                            minEta = cms.double(0.0)
                        ), 
                            cms.PSet(
                                maxEta = cms.double(2.5),
                                minEta = cms.double(1.479)
                            )),
                        cutName = cms.string('GsfEleSCEtaMultiRangeCut'),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False),
                        useAbsEta = cms.bool(True)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDEtaInCut'),
                        dEtaInCutValueEB = cms.double(0.0152),
                        dEtaInCutValueEE = cms.double(0.0113),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDPhiInCut'),
                        dPhiInCutValueEB = cms.double(0.216),
                        dPhiInCutValueEE = cms.double(0.237),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleFull5x5SigmaIEtaIEtaCut'),
                        full5x5SigmaIEtaIEtaCutValueEB = cms.double(0.0114),
                        full5x5SigmaIEtaIEtaCutValueEE = cms.double(0.0352),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleHadronicOverEMCut'),
                        hadronicOverEMCutValueEB = cms.double(0.181),
                        hadronicOverEMCutValueEE = cms.double(0.116),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDxyCut'),
                        dxyCutValueEB = cms.double(0.0564),
                        dxyCutValueEE = cms.double(0.222),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True),
                        vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                        vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDzCut'),
                        dzCutValueEB = cms.double(0.472),
                        dzCutValueEE = cms.double(0.921),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True),
                        vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                        vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleEInverseMinusPInverseCut'),
                        eInverseMinusPInverseCutValueEB = cms.double(0.207),
                        eInverseMinusPInverseCutValueEE = cms.double(0.174),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleEffAreaPFIsoCut'),
                        effAreasConfigFile = cms.FileInPath('RecoEgamma/ElectronIdentification/data/Spring15/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_25ns.txt'),
                        isIgnored = cms.bool(False),
                        isRelativeIso = cms.bool(True),
                        isoCutEBHighPt = cms.double(0.126),
                        isoCutEBLowPt = cms.double(0.126),
                        isoCutEEHighPt = cms.double(0.144),
                        isoCutEELowPt = cms.double(0.144),
                        needsAdditionalProducts = cms.bool(True),
                        ptCutOff = cms.double(20.0),
                        rho = cms.InputTag("fixedGridRhoFastjetAll")
                    ), 
                    cms.PSet(
                        beamspotSrc = cms.InputTag("offlineBeamSpot"),
                        conversionSrc = cms.InputTag("allConversions"),
                        conversionSrcMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
                        cutName = cms.string('GsfEleConversionVetoCut'),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleMissingHitsCut'),
                        isIgnored = cms.bool(False),
                        maxMissingHitsEB = cms.uint32(2),
                        maxMissingHitsEE = cms.uint32(3),
                        needsAdditionalProducts = cms.bool(False)
                    )),
                idName = cms.string('cutBasedElectronID-Spring15-25ns-V1-standalone-veto')
            ),
            idMD5 = cms.string('202030579ee3eec90fdc2d236ba3de7e'),
            isPOGApproved = cms.untracked.bool(True)
        ), 
        cms.PSet(
            idDefinition = cms.PSet(
                cutFlow = cms.VPSet(cms.PSet(
                    cutName = cms.string('MinPtCut'),
                    isIgnored = cms.bool(False),
                    minPt = cms.double(35.0),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                    cms.PSet(
                        allowedEtaRanges = cms.VPSet(cms.PSet(
                            maxEta = cms.double(1.4442),
                            minEta = cms.double(0.0)
                        ), 
                            cms.PSet(
                                maxEta = cms.double(2.5),
                                minEta = cms.double(1.566)
                            )),
                        cutName = cms.string('GsfEleSCEtaMultiRangeCut'),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False),
                        useAbsEta = cms.bool(True)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDEtaInSeedCut'),
                        dEtaInSeedCutValueEB = cms.double(0.004),
                        dEtaInSeedCutValueEE = cms.double(0.006),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDPhiInCut'),
                        dPhiInCutValueEB = cms.double(0.06),
                        dPhiInCutValueEE = cms.double(0.06),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleFull5x5SigmaIEtaIEtaCut'),
                        full5x5SigmaIEtaIEtaCutValueEB = cms.double(9999),
                        full5x5SigmaIEtaIEtaCutValueEE = cms.double(0.03),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        cutName = cms.string('GsfEleFull5x5E2x5OverE5x5Cut'),
                        isIgnored = cms.bool(False),
                        minE1x5OverE5x5EB = cms.double(0.83),
                        minE1x5OverE5x5EE = cms.double(-1.0),
                        minE2x5OverE5x5EB = cms.double(0.94),
                        minE2x5OverE5x5EE = cms.double(-1.0),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        constTermEB = cms.double(1.0),
                        constTermEE = cms.double(5),
                        cutName = cms.string('GsfEleHadronicOverEMLinearCut'),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False),
                        slopeStartEB = cms.double(0.0),
                        slopeStartEE = cms.double(0.0),
                        slopeTermEB = cms.double(0.05),
                        slopeTermEE = cms.double(0.05)
                    ), 
                    cms.PSet(
                        constTermEB = cms.double(5.0),
                        constTermEE = cms.double(5.0),
                        cutName = cms.string('GsfEleTrkPtIsoCut'),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False),
                        slopeStartEB = cms.double(0.0),
                        slopeStartEE = cms.double(0.0),
                        slopeTermEB = cms.double(0.0),
                        slopeTermEE = cms.double(0.0)
                    ), 
                    cms.PSet(
                        constTermEB = cms.double(2.0),
                        constTermEE = cms.double(2.5),
                        cutName = cms.string('GsfEleEmHadD1IsoRhoCut'),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True),
                        rho = cms.InputTag("fixedGridRhoFastjetAll"),
                        rhoConstant = cms.double(0.28),
                        slopeStartEB = cms.double(0.0),
                        slopeStartEE = cms.double(50.0),
                        slopeTermEB = cms.double(0.03),
                        slopeTermEE = cms.double(0.03)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleDxyCut'),
                        dxyCutValueEB = cms.double(0.02),
                        dxyCutValueEE = cms.double(0.05),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(True),
                        vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                        vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleMissingHitsCut'),
                        isIgnored = cms.bool(False),
                        maxMissingHitsEB = cms.uint32(1),
                        maxMissingHitsEE = cms.uint32(1),
                        needsAdditionalProducts = cms.bool(False)
                    ), 
                    cms.PSet(
                        barrelCutOff = cms.double(1.479),
                        cutName = cms.string('GsfEleEcalDrivenCut'),
                        ecalDrivenEB = cms.int32(1),
                        ecalDrivenEE = cms.int32(1),
                        isIgnored = cms.bool(False),
                        needsAdditionalProducts = cms.bool(False)
                    )),
                idName = cms.string('heepElectronID-HEEPV60')
            ),
            idMD5 = cms.string('df10ac7e3a9c22f63fa7936573beaafb'),
            isPOGApproved = cms.untracked.bool(True)
        ), 
        cms.PSet(
            idDefinition = cms.PSet(
                cutFlow = cms.VPSet(cms.PSet(
                    cutName = cms.string('GsfEleMVACut'),
                    isIgnored = cms.bool(False),
                    mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Categories"),
                    mvaCuts = cms.vdouble(0.287435, 0.221846, -0.303263, 0.967083, 0.929117, 
                        0.726311),
                    mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
                    needsAdditionalProducts = cms.bool(True)
                )),
                idName = cms.string('mvaEleID-Spring15-25ns-nonTrig-V1-wp80')
            ),
            idMD5 = cms.string('113c47ceaea0fa687b8bd6d880eb4957'),
            isPOGApproved = cms.untracked.bool(True)
        ), 
        cms.PSet(
            idDefinition = cms.PSet(
                cutFlow = cms.VPSet(cms.PSet(
                    cutName = cms.string('GsfEleMVACut'),
                    isIgnored = cms.bool(False),
                    mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Categories"),
                    mvaCuts = cms.vdouble(-0.083313, -0.235222, -0.67099, 0.913286, 0.805013, 
                        0.358969),
                    mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
                    needsAdditionalProducts = cms.bool(True)
                )),
                idName = cms.string('mvaEleID-Spring15-25ns-nonTrig-V1-wp90')
            ),
            idMD5 = cms.string('ac4fdc160eefe9eae7338601c02ed4bb'),
            isPOGApproved = cms.untracked.bool(True)
        )),
    physicsObjectSrc = cms.InputTag("slimmedElectrons")
)


process.eleVarHelper = cms.EDProducer("PatElectronVariableHelper",
    mvaValuesMap = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
    packedPFCandidates = cms.InputTag("packedPFCandidates"),
    photonSrc = cms.InputTag("packedPFCandidates"),
    probes = cms.InputTag("slimmedElectrons"),
    vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.electronMVAValueMapProducer = cms.EDProducer("ElectronMVAValueMapProducer",
    mvaConfigurations = cms.VPSet(cms.PSet(
        mvaName = cms.string('ElectronMVAEstimatorRun2Phys14NonTrig'),
        mvaTag = cms.string('25nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_5_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_5_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_5_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_10_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_10_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_10_oldscenario2phys14_BDT.weights.xml')
    ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring15NonTrig'),
            mvaTag = cms.string('25nsV1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml')
        ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
            mvaTag = cms.string('50nsV1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
        ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
            mvaTag = cms.string('25nsV1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
        )),
    src = cms.InputTag("gedGsfElectrons"),
    srcMiniAOD = cms.InputTag("slimmedElectrons","","@skipCurrentProcess")
)


process.electronRegressionValueMapProducer = cms.EDProducer("ElectronRegressionValueMapProducer",
    ebReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"),
    ebReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedEBRecHits"),
    eeReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsEE"),
    eeReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedEERecHits"),
    esReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsES"),
    esReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedESRecHits"),
    src = cms.InputTag("gedGsfElectrons"),
    srcMiniAOD = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
    useFull5x5 = cms.bool(False)
)


process.goodElectronsMeasureHLT = cms.EDProducer("PatElectronTriggerCandProducer",
    bits = cms.InputTag("TriggerResults","","HLT"),
    dR = cms.double(0.3),
    filterNames = cms.vstring(''),
    inputs = cms.InputTag("goodElectronsProbeMeasureHLT"),
    isAND = cms.bool(False),
    objects = cms.InputTag("selectedPatTrigger")
)


process.goodElectronsPROBECutBasedLoose = cms.EDProducer("PatElectronSelectorByValueMap",
    cut = cms.string('(abs(superCluster.eta)<2.5) && (ecalEnergy*sin(superClusterPosition.theta)>7.0)'),
    id_cut = cms.bool(True),
    input = cms.InputTag("goodElectrons"),
    selection = cms.InputTag("egmGsfElectronIDs","cutBasedElectronID-Spring15-25ns-V1-standalone-loose")
)


process.goodElectronsPROBECutBasedMedium = cms.EDProducer("PatElectronSelectorByValueMap",
    cut = cms.string('(abs(superCluster.eta)<2.5) && (ecalEnergy*sin(superClusterPosition.theta)>7.0)'),
    id_cut = cms.bool(True),
    input = cms.InputTag("goodElectrons"),
    selection = cms.InputTag("egmGsfElectronIDs","cutBasedElectronID-Spring15-25ns-V1-standalone-medium")
)


process.goodElectronsPROBECutBasedTight = cms.EDProducer("PatElectronSelectorByValueMap",
    cut = cms.string('(abs(superCluster.eta)<2.5) && (ecalEnergy*sin(superClusterPosition.theta)>7.0)'),
    id_cut = cms.bool(True),
    input = cms.InputTag("goodElectrons"),
    selection = cms.InputTag("egmGsfElectronIDs","cutBasedElectronID-Spring15-25ns-V1-standalone-tight")
)


process.goodElectronsPROBECutBasedVeto = cms.EDProducer("PatElectronSelectorByValueMap",
    cut = cms.string('(abs(superCluster.eta)<2.5) && (ecalEnergy*sin(superClusterPosition.theta)>7.0)'),
    id_cut = cms.bool(True),
    input = cms.InputTag("goodElectrons"),
    selection = cms.InputTag("egmGsfElectronIDs","cutBasedElectronID-Spring15-25ns-V1-standalone-veto")
)


process.goodElectronsProbeHLT = cms.EDProducer("PatElectronTriggerCandProducer",
    bits = cms.InputTag("TriggerResults","","HLT"),
    dR = cms.double(0.3),
    filterNames = cms.vstring(),
    inputs = cms.InputTag("goodElectrons"),
    isAND = cms.bool(True),
    objects = cms.InputTag("selectedPatTrigger")
)


process.goodElectronsProbeMeasureHLT = cms.EDProducer("PatElectronTriggerCandProducer",
    bits = cms.InputTag("TriggerResults","","HLT"),
    dR = cms.double(0.3),
    filterNames = cms.vstring(),
    inputs = cms.InputTag("goodElectrons"),
    isAND = cms.bool(True),
    objects = cms.InputTag("selectedPatTrigger")
)


process.goodElectronsTAGCutBasedLoose = cms.EDProducer("PatElectronSelectorByValueMap",
    cut = cms.string('(abs(superCluster.eta)<=2.5) && !(1.4442<=abs(superCluster.eta)<=1.566) && pt >= 25.0'),
    id_cut = cms.bool(True),
    input = cms.InputTag("goodElectrons"),
    selection = cms.InputTag("egmGsfElectronIDs","cutBasedElectronID-Spring15-25ns-V1-standalone-loose")
)


process.goodElectronsTAGCutBasedMedium = cms.EDProducer("PatElectronSelectorByValueMap",
    cut = cms.string('(abs(superCluster.eta)<=2.5) && !(1.4442<=abs(superCluster.eta)<=1.566) && pt >= 25.0'),
    id_cut = cms.bool(True),
    input = cms.InputTag("goodElectrons"),
    selection = cms.InputTag("egmGsfElectronIDs","cutBasedElectronID-Spring15-25ns-V1-standalone-medium")
)


process.goodElectronsTAGCutBasedTight = cms.EDProducer("PatElectronSelectorByValueMap",
    cut = cms.string('(abs(superCluster.eta)<=2.5) && !(1.4442<=abs(superCluster.eta)<=1.566) && pt >= 25.0'),
    id_cut = cms.bool(True),
    input = cms.InputTag("goodElectrons"),
    selection = cms.InputTag("egmGsfElectronIDs","cutBasedElectronID-Spring15-25ns-V1-standalone-tight")
)


process.goodElectronsTAGCutBasedVeto = cms.EDProducer("PatElectronSelectorByValueMap",
    cut = cms.string('(abs(superCluster.eta)<=2.5) && !(1.4442<=abs(superCluster.eta)<=1.566) && pt >= 25.0'),
    id_cut = cms.bool(True),
    input = cms.InputTag("goodElectrons"),
    selection = cms.InputTag("egmGsfElectronIDs","cutBasedElectronID-Spring15-25ns-V1-standalone-veto")
)


process.goodElectronsTagHLT = cms.EDProducer("PatElectronTriggerCandProducer",
    bits = cms.InputTag("TriggerResults","","HLT"),
    dR = cms.double(0.3),
    filterNames = cms.vstring('hltEle23WPLooseGsfTrackIsoFilter'),
    inputs = cms.InputTag("goodElectronsTAGCutBasedTight"),
    isAND = cms.bool(True),
    objects = cms.InputTag("selectedPatTrigger")
)


process.goodSuperClustersHLT = cms.EDProducer("RecoEcalCandidateTriggerCandProducer",
    bits = cms.InputTag("TriggerResults","","HLT"),
    dR = cms.double(0.3),
    filterNames = cms.vstring(),
    inputs = cms.InputTag("goodSuperClusters"),
    isAND = cms.bool(True),
    objects = cms.InputTag("selectedPatTrigger")
)


process.pileupReweightingProducer = cms.EDProducer("PileupWeightProducer",
    PileupData = cms.vdouble(111000.0, 551000.0, 791000.0, 1110000.0, 1880000.0, 
        4170000.0, 12100000.0, 44600000.0, 134000000.0, 247000000.0, 
        337000000.0, 382000000.0, 363000000.0, 285000000.0, 181000000.0, 
        94400000.0, 41700000.0, 17200000.0, 7900000.0, 4210000.0, 
        2180000.0, 943000.0, 322000.0, 89000.0, 21600.0, 
        5430.0, 1600.0, 551, 206, 80.1, 
        31.2, 11.9, 4.38, 1.54, 0.518, 
        0.165, 0.0501, 0.0144, 0.00394, 0.00102, 
        0.000251, 5.87e-05, 1.3e-05, 2.74e-06, 5.47e-07, 
        1.04e-07, 1.86e-08, 3.18e-09, 5.16e-10, 9.35e-11, 
        0, 0),
    PileupMC = cms.vdouble(0.000108643, 0.000388957, 0.000332882, 0.00038397, 0.000549167, 
        0.00105412, 0.00459007, 0.0210314, 0.0573688, 0.103986, 
        0.142369, 0.157729, 0.147685, 0.121027, 0.08855, 
        0.0582866, 0.0348526, 0.019457, 0.0107907, 0.00654313, 
        0.00463195, 0.00370927, 0.0031137, 0.00261141, 0.00215499, 
        0.00174491, 0.00138268, 0.00106731, 0.000798828, 0.00057785, 
        0.00040336, 0.00027161, 0.000176535, 0.00011092, 6.75502e-05, 
        4.00323e-05, 2.32123e-05, 1.32585e-05, 7.51611e-06, 4.25902e-06, 
        2.42513e-06, 1.39077e-06, 8.02452e-07, 4.64159e-07, 2.67845e-07, 
        1.5344e-07, 8.68966e-08, 4.84931e-08, 2.6606e-08, 1.433e-08),
    pileupInfoTag = cms.InputTag("slimmedAddPileupInfo")
)


process.sampleInfo = cms.EDProducer("tnp::SampleInfoTree",
    genInfo = cms.InputTag("generator")
)


process.superClusterCands = cms.EDProducer("ConcreteEcalCandidateProducer",
    particleType = cms.int32(11),
    src = cms.InputTag("reducedEgamma","reducedSuperClusters")
)


process.tagTightHLT = cms.EDProducer("CandViewShallowCloneCombiner",
    checkCharge = cms.bool(True),
    cut = cms.string('40<mass<1000'),
    decay = cms.string('goodElectronsTagHLT@+ goodElectronsProbeMeasureHLT@-')
)


process.tagTightRECO = cms.EDProducer("CandViewShallowCloneCombiner",
    checkCharge = cms.bool(True),
    cut = cms.string('40<mass<1000'),
    decay = cms.string('goodElectronsTagHLT@+ goodElectronsProbeHLT@-')
)


process.tagTightSC = cms.EDProducer("CandViewShallowCloneCombiner",
    checkCharge = cms.bool(False),
    cut = cms.string('40<mass<1000'),
    decay = cms.string('goodElectronsTagHLT goodSuperClustersHLT')
)


process.goodElectrons = cms.EDFilter("PATElectronRefSelector",
    cut = cms.string('(abs(superCluster.eta)<2.5) && (ecalEnergy*sin(superClusterPosition.theta)>7.0)'),
    src = cms.InputTag("slimmedElectrons")
)


process.goodSuperClusters = cms.EDFilter("RecoEcalCandidateRefSelector",
    cut = cms.string('abs(eta)<2.5 && !(1.4442< abs(eta) <1.566) && et>7.0'),
    filter = cms.bool(True),
    src = cms.InputTag("superClusterCands")
)


process.hltFilter = cms.EDFilter("HLTHighLevel",
    HLTPaths = cms.vstring('HLT_Ele23_WPLoose_Gsf_v*'),
    TriggerResultsTag = cms.InputTag("TriggerResults","","HLT"),
    andOr = cms.bool(True),
    eventSetupPathsKey = cms.string(''),
    throw = cms.bool(True)
)


process.GsfElectronToRECO = cms.EDAnalyzer("TagProbeFitTreeProducer",
    PUWeightSrc = cms.InputTag("pileupReweightingProducer","pileupWeights"),
    addEventVariablesInfo = cms.bool(True),
    addRunLumiInfo = cms.bool(True),
    allProbes = cms.InputTag("goodElectronsProbeHLT"),
    arbitration = cms.string('Random2'),
    beamSpot = cms.InputTag("offlineBeamSpot"),
    checkCharge = cms.bool(False),
    eventWeight = cms.InputTag("generator"),
    flags = cms.PSet(
        passingLoose = cms.InputTag("goodElectronsPROBECutBasedLoose"),
        passingMedium = cms.InputTag("goodElectronsPROBECutBasedMedium"),
        passingTight = cms.InputTag("goodElectronsPROBECutBasedTight"),
        passingVeto = cms.InputTag("goodElectronsPROBECutBasedVeto")
    ),
    genParticles = cms.InputTag("prunedGenParticles"),
    ignoreExceptions = cms.bool(True),
    isMC = cms.bool(True),
    mcFlags = cms.PSet(
        probe_flag = cms.string('pt>0')
    ),
    mcVariables = cms.PSet(
        probe_abseta = cms.string('abs(eta)'),
        probe_e = cms.string('energy'),
        probe_et = cms.string('et'),
        probe_eta = cms.string('eta')
    ),
    motherPdgId = cms.vint32(),
    pairFlags = cms.PSet(
        mass60to120 = cms.string('60 < mass < 120')
    ),
    pairVariables = cms.PSet(
        abseta = cms.string('abs(eta)'),
        eta = cms.string('eta'),
        mass = cms.string('mass'),
        pt = cms.string('pt')
    ),
    pdgId = cms.int32(11),
    pileupInfoTag = cms.InputTag("slimmedAddPileupInfo"),
    rho = cms.InputTag("fixedGridRhoAll"),
    tagFlags = cms.PSet(
        passingLoose = cms.InputTag("goodElectronsTAGCutBasedLoose"),
        passingMedium = cms.InputTag("goodElectronsTAGCutBasedMedium"),
        passingTight = cms.InputTag("goodElectronsTAGCutBasedTight"),
        passingVeto = cms.InputTag("goodElectronsTAGCutBasedVeto")
    ),
    tagProbePairs = cms.InputTag("tagTightRECO"),
    tagVariables = cms.PSet(
        Ele_abseta = cms.string('abs(eta)'),
        Ele_dxy = cms.InputTag("eleVarHelper","dxy"),
        Ele_dz = cms.InputTag("eleVarHelper","dz"),
        Ele_e = cms.string('energy'),
        Ele_et = cms.string('et'),
        Ele_eta = cms.string('eta'),
        Ele_isGap = cms.string('isGap'),
        Ele_mHits = cms.InputTag("eleVarHelper","missinghits"),
        Ele_nonTrigMVA = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        Ele_phi = cms.string('phi'),
        Ele_pt = cms.string('pt'),
        Ele_px = cms.string('px'),
        Ele_py = cms.string('py'),
        Ele_pz = cms.string('pz'),
        Ele_q = cms.string('charge'),
        Ele_trigMVA = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),
        FSRphoton_e = cms.InputTag("eleVarHelper","FSRe"),
        FSRphoton_px = cms.InputTag("eleVarHelper","FSRpx"),
        FSRphoton_py = cms.InputTag("eleVarHelper","FSRpy"),
        FSRphoton_pz = cms.InputTag("eleVarHelper","FSRpz"),
        sc_abseta = cms.string('abs(superCluster.eta)'),
        sc_energy = cms.string('superCluster.energy'),
        sc_et = cms.string('superCluster.energy*sin(superClusterPosition.theta)'),
        sc_eta = cms.string('superCluster.eta')
    ),
    useTauDecays = cms.bool(False),
    variables = cms.PSet(
        probe_Ele_abseta = cms.string('abs(eta)'),
        probe_Ele_chIso = cms.string('pfIsolationVariables().sumChargedHadronPt'),
        probe_Ele_correctediso = cms.InputTag("eleVarHelper","correctediso"),
        probe_Ele_dEtaIn = cms.string('deltaEtaSuperClusterTrackAtVtx'),
        probe_Ele_dPhiIn = cms.string('deltaPhiSuperClusterTrackAtVtx'),
        probe_Ele_dxy = cms.InputTag("eleVarHelper","dxy"),
        probe_Ele_dz = cms.InputTag("eleVarHelper","dz"),
        probe_Ele_e = cms.string('energy'),
        probe_Ele_ed = cms.InputTag("eleVarHelper","enedens"),
        probe_Ele_effarea = cms.InputTag("eleVarHelper","effarea"),
        probe_Ele_et = cms.string('et'),
        probe_Ele_eta = cms.string('eta'),
        probe_Ele_hoe = cms.string('hadronicOverEm'),
        probe_Ele_ip = cms.InputTag("eleVarHelper","ip"),
        probe_Ele_iperror = cms.InputTag("eleVarHelper","iperror"),
        probe_Ele_isEBEEGap = cms.string('isEBEEGap'),
        probe_Ele_isEBEtaGap = cms.string('isEBEtaGap'),
        probe_Ele_isEBPhiGap = cms.string('isEBPhiGap'),
        probe_Ele_isEEDeeGap = cms.string('isEEDeeGap'),
        probe_Ele_isEERingGap = cms.string('isEERingGap'),
        probe_Ele_isGap = cms.string('isGap'),
        probe_Ele_iso = cms.InputTag("eleVarHelper","iso"),
        probe_Ele_mHits = cms.InputTag("eleVarHelper","missinghits"),
        probe_Ele_neuIso = cms.string('pfIsolationVariables().sumNeutralHadronEt'),
        probe_Ele_nonTrigMVA = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        probe_Ele_ooemoop = cms.string('(1.0/ecalEnergy - eSuperClusterOverP/ecalEnergy)'),
        probe_Ele_phi = cms.string('phi'),
        probe_Ele_phoIso = cms.string('pfIsolationVariables().sumPhotonEt'),
        probe_Ele_pt = cms.string('pt'),
        probe_Ele_px = cms.string('px'),
        probe_Ele_py = cms.string('py'),
        probe_Ele_pz = cms.string('pz'),
        probe_Ele_q = cms.string('charge'),
        probe_Ele_rho = cms.InputTag("eleVarHelper","rho"),
        probe_Ele_sigmaIEtaIEta = cms.string('sigmaIetaIeta'),
        probe_Ele_sip = cms.InputTag("eleVarHelper","sip"),
        probe_Ele_trkIso = cms.string('dr03IsolationVariables().tkSumPt'),
        probe_FSRcorr = cms.InputTag("eleVarHelper","FSRcorr"),
        probe_FSRphoton_e = cms.InputTag("eleVarHelper","FSRe"),
        probe_FSRphoton_px = cms.InputTag("eleVarHelper","FSRpx"),
        probe_FSRphoton_py = cms.InputTag("eleVarHelper","FSRpy"),
        probe_FSRphoton_pz = cms.InputTag("eleVarHelper","FSRpz"),
        probe_passing_MVA = cms.InputTag("eleVarHelper","passingSpring15NonTrig"),
        probe_sc_abseta = cms.string('abs(superCluster.eta)'),
        probe_sc_energy = cms.string('superCluster.energy'),
        probe_sc_et = cms.string('superCluster.energy*sin(superClusterPosition.theta)'),
        probe_sc_eta = cms.string('superCluster.eta')
    ),
    vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.GsfElectronToSC = cms.EDAnalyzer("TagProbeFitTreeProducer",
    PUWeightSrc = cms.InputTag("pileupReweightingProducer","pileupWeights"),
    addEventVariablesInfo = cms.bool(True),
    addRunLumiInfo = cms.bool(True),
    allProbes = cms.InputTag("goodSuperClustersHLT"),
    arbitration = cms.string('Random2'),
    beamSpot = cms.InputTag("offlineBeamSpot"),
    checkCharge = cms.bool(False),
    eventWeight = cms.InputTag("generator"),
    flags = cms.PSet(
        passingRECO = cms.InputTag("GsfMatchedSuperClusterCands","superclusters")
    ),
    genParticles = cms.InputTag("prunedGenParticles"),
    ignoreExceptions = cms.bool(True),
    isMC = cms.bool(True),
    mcFlags = cms.PSet(
        probe_flag = cms.string('pt>0')
    ),
    mcVariables = cms.PSet(
        probe_abseta = cms.string('abs(eta)'),
        probe_e = cms.string('energy'),
        probe_et = cms.string('et'),
        probe_eta = cms.string('eta')
    ),
    motherPdgId = cms.vint32(),
    pairFlags = cms.PSet(
        mass60to120 = cms.string('60 < mass < 120')
    ),
    pairVariables = cms.PSet(
        abseta = cms.string('abs(eta)'),
        eta = cms.string('eta'),
        mass = cms.string('mass'),
        pt = cms.string('pt')
    ),
    pdgId = cms.int32(11),
    pileupInfoTag = cms.InputTag("slimmedAddPileupInfo"),
    rho = cms.InputTag("fixedGridRhoAll"),
    tagFlags = cms.PSet(
        passingLoose = cms.InputTag("goodElectronsTAGCutBasedLoose"),
        passingMedium = cms.InputTag("goodElectronsTAGCutBasedMedium"),
        passingTight = cms.InputTag("goodElectronsTAGCutBasedTight"),
        passingVeto = cms.InputTag("goodElectronsTAGCutBasedVeto")
    ),
    tagProbePairs = cms.InputTag("tagTightSC"),
    tagVariables = cms.PSet(
        Ele_abseta = cms.string('abs(eta)'),
        Ele_dxy = cms.InputTag("eleVarHelper","dxy"),
        Ele_dz = cms.InputTag("eleVarHelper","dz"),
        Ele_e = cms.string('energy'),
        Ele_et = cms.string('et'),
        Ele_eta = cms.string('eta'),
        Ele_isGap = cms.string('isGap'),
        Ele_mHits = cms.InputTag("eleVarHelper","missinghits"),
        Ele_nonTrigMVA = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        Ele_phi = cms.string('phi'),
        Ele_pt = cms.string('pt'),
        Ele_px = cms.string('px'),
        Ele_py = cms.string('py'),
        Ele_pz = cms.string('pz'),
        Ele_q = cms.string('charge'),
        Ele_trigMVA = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),
        FSRphoton_e = cms.InputTag("eleVarHelper","FSRe"),
        FSRphoton_px = cms.InputTag("eleVarHelper","FSRpx"),
        FSRphoton_py = cms.InputTag("eleVarHelper","FSRpy"),
        FSRphoton_pz = cms.InputTag("eleVarHelper","FSRpz"),
        sc_abseta = cms.string('abs(superCluster.eta)'),
        sc_energy = cms.string('superCluster.energy'),
        sc_et = cms.string('superCluster.energy*sin(superClusterPosition.theta)'),
        sc_eta = cms.string('superCluster.eta')
    ),
    useTauDecays = cms.bool(False),
    variables = cms.PSet(
        probe_sc_abseta = cms.string('abs(eta)'),
        probe_sc_e = cms.string('energy'),
        probe_sc_et = cms.string('et'),
        probe_sc_eta = cms.string('eta'),
        probe_sc_pt = cms.string('pt')
    ),
    vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.GsfElectronToTrigger = cms.EDAnalyzer("TagProbeFitTreeProducer",
    PUWeightSrc = cms.InputTag("pileupReweightingProducer","pileupWeights"),
    addEventVariablesInfo = cms.bool(True),
    addRunLumiInfo = cms.bool(True),
    allProbes = cms.InputTag("goodElectronsProbeMeasureHLT"),
    arbitration = cms.string('Random2'),
    beamSpot = cms.InputTag("offlineBeamSpot"),
    checkCharge = cms.bool(False),
    eventWeight = cms.InputTag("generator"),
    flags = cms.PSet(
        passingHLT = cms.InputTag("goodElectronsMeasureHLT")
    ),
    genParticles = cms.InputTag("prunedGenParticles"),
    ignoreExceptions = cms.bool(True),
    isMC = cms.bool(True),
    mcFlags = cms.PSet(
        probe_flag = cms.string('pt>0')
    ),
    mcVariables = cms.PSet(
        probe_abseta = cms.string('abs(eta)'),
        probe_e = cms.string('energy'),
        probe_et = cms.string('et'),
        probe_eta = cms.string('eta')
    ),
    motherPdgId = cms.vint32(),
    pairFlags = cms.PSet(
        mass60to120 = cms.string('60 < mass < 120')
    ),
    pairVariables = cms.PSet(
        abseta = cms.string('abs(eta)'),
        eta = cms.string('eta'),
        mass = cms.string('mass'),
        pt = cms.string('pt')
    ),
    pdgId = cms.int32(11),
    pileupInfoTag = cms.InputTag("slimmedAddPileupInfo"),
    rho = cms.InputTag("fixedGridRhoAll"),
    tagFlags = cms.PSet(
        passingLoose = cms.InputTag("goodElectronsTAGCutBasedLoose"),
        passingMedium = cms.InputTag("goodElectronsTAGCutBasedMedium"),
        passingTight = cms.InputTag("goodElectronsTAGCutBasedTight"),
        passingVeto = cms.InputTag("goodElectronsTAGCutBasedVeto")
    ),
    tagProbePairs = cms.InputTag("tagTightHLT"),
    tagVariables = cms.PSet(
        Ele_abseta = cms.string('abs(eta)'),
        Ele_dxy = cms.InputTag("eleVarHelper","dxy"),
        Ele_dz = cms.InputTag("eleVarHelper","dz"),
        Ele_e = cms.string('energy'),
        Ele_et = cms.string('et'),
        Ele_eta = cms.string('eta'),
        Ele_isGap = cms.string('isGap'),
        Ele_mHits = cms.InputTag("eleVarHelper","missinghits"),
        Ele_nonTrigMVA = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        Ele_phi = cms.string('phi'),
        Ele_pt = cms.string('pt'),
        Ele_px = cms.string('px'),
        Ele_py = cms.string('py'),
        Ele_pz = cms.string('pz'),
        Ele_q = cms.string('charge'),
        Ele_trigMVA = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),
        FSRphoton_e = cms.InputTag("eleVarHelper","FSRe"),
        FSRphoton_px = cms.InputTag("eleVarHelper","FSRpx"),
        FSRphoton_py = cms.InputTag("eleVarHelper","FSRpy"),
        FSRphoton_pz = cms.InputTag("eleVarHelper","FSRpz"),
        sc_abseta = cms.string('abs(superCluster.eta)'),
        sc_energy = cms.string('superCluster.energy'),
        sc_et = cms.string('superCluster.energy*sin(superClusterPosition.theta)'),
        sc_eta = cms.string('superCluster.eta')
    ),
    useTauDecays = cms.bool(False),
    variables = cms.PSet(
        probe_sc_abseta = cms.string('abs(eta)'),
        probe_sc_e = cms.string('energy'),
        probe_sc_et = cms.string('et'),
        probe_sc_eta = cms.string('eta'),
        probe_sc_pt = cms.string('pt')
    ),
    vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.out = cms.OutputModule("PoolOutputModule",
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('p')
    ),
    fileName = cms.untracked.string('edmFile.root')
)


process.allTagsAndProbes = cms.Sequence(process.tagTightRECO)


process.tree_sequence = cms.Sequence(process.GsfElectronToRECO)


process.mc_sequence = cms.Sequence()


process.sc_sequence = cms.Sequence(process.superClusterCands+process.goodSuperClusters+process.goodSuperClustersHLT+process.GsfMatchedSuperClusterCands)


process.egmGsfElectronIDSequence = cms.Sequence(process.electronMVAValueMapProducer+process.egmGsfElectronIDs+process.electronRegressionValueMapProducer)


process.ele_sequence = cms.Sequence(process.goodElectrons+process.egmGsfElectronIDSequence+process.goodElectronsPROBECutBasedVeto+process.goodElectronsPROBECutBasedLoose+process.goodElectronsPROBECutBasedMedium+process.goodElectronsPROBECutBasedTight+process.goodElectronsTAGCutBasedVeto+process.goodElectronsTAGCutBasedLoose+process.goodElectronsTAGCutBasedMedium+process.goodElectronsTAGCutBasedTight+process.goodElectronsTagHLT+process.goodElectronsProbeHLT+process.goodElectronsProbeMeasureHLT+process.goodElectronsMeasureHLT)


process.p = cms.Path(process.sampleInfo+process.hltFilter+process.ele_sequence+process.sc_sequence+process.allTagsAndProbes+process.pileupReweightingProducer+process.mc_sequence+process.eleVarHelper+process.tree_sequence)


process.outpath = cms.EndPath()


process.MessageLogger = cms.Service("MessageLogger",
    FrameworkJobReport = cms.untracked.PSet(
        FwkJob = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True)
        ),
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        optionalPSet = cms.untracked.bool(True)
    ),
    categories = cms.untracked.vstring('FwkJob', 
        'FwkReport', 
        'FwkSummary', 
        'Root_NoDictionary'),
    cerr = cms.untracked.PSet(
        FwkJob = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        FwkReport = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True),
            reportEvery = cms.untracked.int32(1000)
        ),
        FwkSummary = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True),
            reportEvery = cms.untracked.int32(1)
        ),
        INFO = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        Root_NoDictionary = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000)
        ),
        noTimeStamps = cms.untracked.bool(False),
        optionalPSet = cms.untracked.bool(True),
        threshold = cms.untracked.string('')
    ),
    cerr_stats = cms.untracked.PSet(
        optionalPSet = cms.untracked.bool(True),
        output = cms.untracked.string('cerr'),
        threshold = cms.untracked.string('WARNING')
    ),
    cout = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    debugModules = cms.untracked.vstring(),
    debugs = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    default = cms.untracked.PSet(

    ),
    destinations = cms.untracked.vstring('warnings', 
        'errors', 
        'infos', 
        'debugs', 
        'cout', 
        'cerr'),
    errors = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    fwkJobReports = cms.untracked.vstring('FrameworkJobReport'),
    infos = cms.untracked.PSet(
        Root_NoDictionary = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        optionalPSet = cms.untracked.bool(True),
        placeholder = cms.untracked.bool(True)
    ),
    statistics = cms.untracked.vstring('cerr_stats'),
    suppressDebug = cms.untracked.vstring(),
    suppressInfo = cms.untracked.vstring(),
    suppressWarning = cms.untracked.vstring(),
    warnings = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    )
)


process.TFileService = cms.Service("TFileService",
    closeFileFast = cms.untracked.bool(True),
    fileName = cms.string('TnPTree_mc.root')
)


process.CSCGeometryESModule = cms.ESProducer("CSCGeometryESModule",
    alignmentsLabel = cms.string(''),
    appendToDataLabel = cms.string(''),
    applyAlignment = cms.bool(True),
    debugV = cms.untracked.bool(False),
    useCentreTIOffsets = cms.bool(False),
    useDDD = cms.bool(False),
    useGangedStripsInME1a = cms.bool(True),
    useOnlyWiresInME1a = cms.bool(False),
    useRealWireGeometry = cms.bool(True)
)


process.CaloGeometryBuilder = cms.ESProducer("CaloGeometryBuilder",
    SelectedCalos = cms.vstring('HCAL', 
        'ZDC', 
        'CASTOR', 
        'EcalBarrel', 
        'EcalEndcap', 
        'EcalPreshower', 
        'TOWER')
)


process.CaloTopologyBuilder = cms.ESProducer("CaloTopologyBuilder")


process.CaloTowerGeometryFromDBEP = cms.ESProducer("CaloTowerGeometryFromDBEP",
    applyAlignment = cms.bool(False),
    hcalTopologyConstants = cms.PSet(
        maxDepthHB = cms.int32(2),
        maxDepthHE = cms.int32(3),
        mode = cms.string('HcalTopologyMode::LHC')
    )
)


process.CaloTowerTopologyEP = cms.ESProducer("CaloTowerTopologyEP")


process.CastorDbProducer = cms.ESProducer("CastorDbProducer")


process.CastorGeometryFromDBEP = cms.ESProducer("CastorGeometryFromDBEP",
    applyAlignment = cms.bool(False)
)


process.DTGeometryESModule = cms.ESProducer("DTGeometryESModule",
    alignmentsLabel = cms.string(''),
    appendToDataLabel = cms.string(''),
    applyAlignment = cms.bool(True),
    fromDDD = cms.bool(False)
)


process.EcalBarrelGeometryFromDBEP = cms.ESProducer("EcalBarrelGeometryFromDBEP",
    applyAlignment = cms.bool(True)
)


process.EcalElectronicsMappingBuilder = cms.ESProducer("EcalElectronicsMappingBuilder")


process.EcalEndcapGeometryFromDBEP = cms.ESProducer("EcalEndcapGeometryFromDBEP",
    applyAlignment = cms.bool(True)
)


process.EcalLaserCorrectionService = cms.ESProducer("EcalLaserCorrectionService")


process.EcalPreshowerGeometryFromDBEP = cms.ESProducer("EcalPreshowerGeometryFromDBEP",
    applyAlignment = cms.bool(True)
)


process.EcalTrigTowerConstituentsMapBuilder = cms.ESProducer("EcalTrigTowerConstituentsMapBuilder",
    MapFile = cms.untracked.string('Geometry/EcalMapping/data/EndCap_TTMap.txt')
)


process.GlobalTrackingGeometryESProducer = cms.ESProducer("GlobalTrackingGeometryESProducer")


process.HcalAlignmentEP = cms.ESProducer("HcalAlignmentEP")


process.HcalGeometryFromDBEP = cms.ESProducer("HcalGeometryFromDBEP",
    applyAlignment = cms.bool(True),
    hcalTopologyConstants = cms.PSet(
        maxDepthHB = cms.int32(2),
        maxDepthHE = cms.int32(3),
        mode = cms.string('HcalTopologyMode::LHC')
    )
)


process.MuonDetLayerGeometryESProducer = cms.ESProducer("MuonDetLayerGeometryESProducer")


process.ParabolicParametrizedMagneticFieldProducer = cms.ESProducer("AutoParametrizedMagneticFieldProducer",
    label = cms.untracked.string('ParabolicMf'),
    valueOverride = cms.int32(-1),
    version = cms.string('Parabolic')
)


process.RPCGeometryESModule = cms.ESProducer("RPCGeometryESModule",
    compatibiltyWith11 = cms.untracked.bool(True),
    useDDD = cms.untracked.bool(False)
)


process.SiStripRecHitMatcherESProducer = cms.ESProducer("SiStripRecHitMatcherESProducer",
    ComponentName = cms.string('StandardMatcher'),
    NSigmaInside = cms.double(3.0),
    PreFilter = cms.bool(False)
)


process.StripCPEfromTrackAngleESProducer = cms.ESProducer("StripCPEESProducer",
    ComponentName = cms.string('StripCPEfromTrackAngle'),
    ComponentType = cms.string('StripCPEfromTrackAngle'),
    parameters = cms.PSet(
        mLC_P0 = cms.double(-0.326),
        mLC_P1 = cms.double(0.618),
        mLC_P2 = cms.double(0.3),
        mTEC_P0 = cms.double(-1.885),
        mTEC_P1 = cms.double(0.471),
        mTIB_P0 = cms.double(-0.742),
        mTIB_P1 = cms.double(0.202),
        mTID_P0 = cms.double(-1.427),
        mTID_P1 = cms.double(0.433),
        mTOB_P0 = cms.double(-1.026),
        mTOB_P1 = cms.double(0.253),
        maxChgOneMIP = cms.double(6000.0),
        useLegacyError = cms.bool(False)
    )
)


process.TrackerRecoGeometryESProducer = cms.ESProducer("TrackerRecoGeometryESProducer")


process.VolumeBasedMagneticFieldESProducer = cms.ESProducer("VolumeBasedMagneticFieldESProducerFromDB",
    debugBuilder = cms.untracked.bool(False),
    label = cms.untracked.string(''),
    valueOverride = cms.int32(-1)
)


process.ZdcGeometryFromDBEP = cms.ESProducer("ZdcGeometryFromDBEP",
    applyAlignment = cms.bool(False)
)


process.fakeForIdealAlignment = cms.ESProducer("FakeAlignmentProducer",
    appendToDataLabel = cms.string('fakeForIdeal')
)


process.hcalDDDRecConstants = cms.ESProducer("HcalDDDRecConstantsESModule",
    appendToDataLabel = cms.string('')
)


process.hcalDDDSimConstants = cms.ESProducer("HcalDDDSimConstantsESModule",
    appendToDataLabel = cms.string('')
)


process.hcalTopologyIdeal = cms.ESProducer("HcalTopologyIdealEP",
    Exclude = cms.untracked.string(''),
    appendToDataLabel = cms.string(''),
    hcalTopologyConstants = cms.PSet(
        maxDepthHB = cms.int32(2),
        maxDepthHE = cms.int32(3),
        mode = cms.string('HcalTopologyMode::LHC')
    )
)


process.hcal_db_producer = cms.ESProducer("HcalDbProducer",
    dump = cms.untracked.vstring(''),
    file = cms.untracked.string('')
)


process.idealForDigiCSCGeometry = cms.ESProducer("CSCGeometryESModule",
    alignmentsLabel = cms.string('fakeForIdeal'),
    appendToDataLabel = cms.string('idealForDigi'),
    applyAlignment = cms.bool(False),
    debugV = cms.untracked.bool(False),
    useCentreTIOffsets = cms.bool(False),
    useDDD = cms.bool(False),
    useGangedStripsInME1a = cms.bool(True),
    useOnlyWiresInME1a = cms.bool(False),
    useRealWireGeometry = cms.bool(True)
)


process.idealForDigiDTGeometry = cms.ESProducer("DTGeometryESModule",
    alignmentsLabel = cms.string('fakeForIdeal'),
    appendToDataLabel = cms.string('idealForDigi'),
    applyAlignment = cms.bool(False),
    fromDDD = cms.bool(False)
)


process.idealForDigiTrackerGeometry = cms.ESProducer("TrackerDigiGeometryESModule",
    alignmentsLabel = cms.string('fakeForIdeal'),
    appendToDataLabel = cms.string('idealForDigi'),
    applyAlignment = cms.bool(False),
    fromDDD = cms.bool(False)
)


process.siPixelQualityESProducer = cms.ESProducer("SiPixelQualityESProducer",
    ListOfRecordToMerge = cms.VPSet(cms.PSet(
        record = cms.string('SiPixelQualityFromDbRcd'),
        tag = cms.string('')
    ), 
        cms.PSet(
            record = cms.string('SiPixelDetVOffRcd'),
            tag = cms.string('')
        ))
)


process.siStripBackPlaneCorrectionDepESProducer = cms.ESProducer("SiStripBackPlaneCorrectionDepESProducer",
    BackPlaneCorrectionDeconvMode = cms.PSet(
        label = cms.untracked.string('deconvolution'),
        record = cms.string('SiStripBackPlaneCorrectionRcd')
    ),
    BackPlaneCorrectionPeakMode = cms.PSet(
        label = cms.untracked.string('peak'),
        record = cms.string('SiStripBackPlaneCorrectionRcd')
    ),
    LatencyRecord = cms.PSet(
        label = cms.untracked.string(''),
        record = cms.string('SiStripLatencyRcd')
    )
)


process.siStripGainESProducer = cms.ESProducer("SiStripGainESProducer",
    APVGain = cms.VPSet(cms.PSet(
        Label = cms.untracked.string(''),
        NormalizationFactor = cms.untracked.double(1.0),
        Record = cms.string('SiStripApvGainRcd')
    ), 
        cms.PSet(
            Label = cms.untracked.string(''),
            NormalizationFactor = cms.untracked.double(1.0),
            Record = cms.string('SiStripApvGain2Rcd')
        )),
    AutomaticNormalization = cms.bool(False),
    appendToDataLabel = cms.string(''),
    printDebug = cms.untracked.bool(False)
)


process.siStripLorentzAngleDepESProducer = cms.ESProducer("SiStripLorentzAngleDepESProducer",
    LatencyRecord = cms.PSet(
        label = cms.untracked.string(''),
        record = cms.string('SiStripLatencyRcd')
    ),
    LorentzAngleDeconvMode = cms.PSet(
        label = cms.untracked.string('deconvolution'),
        record = cms.string('SiStripLorentzAngleRcd')
    ),
    LorentzAnglePeakMode = cms.PSet(
        label = cms.untracked.string('peak'),
        record = cms.string('SiStripLorentzAngleRcd')
    )
)


process.siStripQualityESProducer = cms.ESProducer("SiStripQualityESProducer",
    ListOfRecordToMerge = cms.VPSet(cms.PSet(
        record = cms.string('SiStripDetVOffRcd'),
        tag = cms.string('')
    ), 
        cms.PSet(
            record = cms.string('SiStripDetCablingRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('RunInfoRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadChannelRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadFiberRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadModuleRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadStripRcd'),
            tag = cms.string('')
        )),
    PrintDebugOutput = cms.bool(False),
    ReduceGranularity = cms.bool(False),
    ThresholdForReducedGranularity = cms.double(0.3),
    UseEmptyRunInfo = cms.bool(False),
    appendToDataLabel = cms.string('')
)


process.sistripconn = cms.ESProducer("SiStripConnectivity")


process.stripCPEESProducer = cms.ESProducer("StripCPEESProducer",
    ComponentName = cms.string('stripCPE'),
    ComponentType = cms.string('SimpleStripCPE'),
    parameters = cms.PSet(

    )
)


process.trackerGeometryDB = cms.ESProducer("TrackerDigiGeometryESModule",
    alignmentsLabel = cms.string(''),
    appendToDataLabel = cms.string(''),
    applyAlignment = cms.bool(True),
    fromDDD = cms.bool(False)
)


process.trackerNumberingGeometryDB = cms.ESProducer("TrackerGeometricDetESModule",
    appendToDataLabel = cms.string(''),
    fromDDD = cms.bool(False)
)


process.trackerTopology = cms.ESProducer("TrackerTopologyEP",
    appendToDataLabel = cms.string('')
)


process.GlobalTag = cms.ESSource("PoolDBESSource",
    DBParameters = cms.PSet(
        authenticationPath = cms.untracked.string(''),
        authenticationSystem = cms.untracked.int32(0),
        connectionRetrialPeriod = cms.untracked.int32(10),
        connectionRetrialTimeOut = cms.untracked.int32(60),
        connectionTimeOut = cms.untracked.int32(60),
        enableConnectionSharing = cms.untracked.bool(True),
        enablePoolAutomaticCleanUp = cms.untracked.bool(False),
        enableReadOnlySessionOnUpdateConnection = cms.untracked.bool(False),
        idleConnectionCleanupPeriod = cms.untracked.int32(10),
        messageLevel = cms.untracked.int32(0)
    ),
    connect = cms.string('frontier://FrontierProd/CMS_CONDITIONS'),
    globaltag = cms.string('76X_mcRun2_asymptotic_v12'),
    toGet = cms.VPSet()
)


process.HepPDTESSource = cms.ESSource("HepPDTESSource",
    pdtFileName = cms.FileInPath('SimGeneral/HepPDTESSource/data/pythiaparticle.tbl')
)


process.eegeom = cms.ESSource("EmptyESSource",
    firstValid = cms.vuint32(1),
    iovIsRunNotTime = cms.bool(True),
    recordName = cms.string('EcalMappingRcd')
)


process.es_hardcode = cms.ESSource("HcalHardcodeCalibrations",
    GainWidthsForTrigPrims = cms.bool(False),
    HERecalibration = cms.bool(False),
    HEreCalibCutoff = cms.double(20.0),
    HFRecalibration = cms.bool(False),
    HcalReLabel = cms.PSet(
        RelabelHits = cms.untracked.bool(False),
        RelabelRules = cms.untracked.PSet(
            CorrectPhi = cms.untracked.bool(False),
            Eta1 = cms.untracked.vint32(1, 2, 2, 2, 3, 
                3, 3, 3, 3, 3, 
                3, 3, 3, 3, 3, 
                3, 3, 3, 3),
            Eta16 = cms.untracked.vint32(1, 1, 2, 2, 2, 
                2, 2, 2, 2, 3, 
                3, 3, 3, 3, 3, 
                3, 3, 3, 3),
            Eta17 = cms.untracked.vint32(1, 1, 2, 2, 3, 
                3, 3, 4, 4, 4, 
                4, 4, 5, 5, 5, 
                5, 5, 5, 5)
        )
    ),
    hcalTopologyConstants = cms.PSet(
        maxDepthHB = cms.int32(2),
        maxDepthHE = cms.int32(3),
        mode = cms.string('HcalTopologyMode::LHC')
    ),
    iLumi = cms.double(-1.0),
    toGet = cms.untracked.vstring('GainWidths')
)


process.prefer("es_hardcode")

process.CondDBSetup = cms.PSet(
    DBParameters = cms.PSet(
        authenticationPath = cms.untracked.string(''),
        authenticationSystem = cms.untracked.int32(0),
        connectionRetrialPeriod = cms.untracked.int32(10),
        connectionRetrialTimeOut = cms.untracked.int32(60),
        connectionTimeOut = cms.untracked.int32(60),
        enableConnectionSharing = cms.untracked.bool(True),
        enablePoolAutomaticCleanUp = cms.untracked.bool(False),
        enableReadOnlySessionOnUpdateConnection = cms.untracked.bool(False),
        idleConnectionCleanupPeriod = cms.untracked.int32(10),
        messageLevel = cms.untracked.int32(0)
    )
)

process.HcalReLabel = cms.PSet(
    RelabelHits = cms.untracked.bool(False),
    RelabelRules = cms.untracked.PSet(
        CorrectPhi = cms.untracked.bool(False),
        Eta1 = cms.untracked.vint32(1, 2, 2, 2, 3, 
            3, 3, 3, 3, 3, 
            3, 3, 3, 3, 3, 
            3, 3, 3, 3),
        Eta16 = cms.untracked.vint32(1, 1, 2, 2, 2, 
            2, 2, 2, 2, 3, 
            3, 3, 3, 3, 3, 
            3, 3, 3, 3),
        Eta17 = cms.untracked.vint32(1, 1, 2, 2, 3, 
            3, 3, 4, 4, 4, 
            4, 4, 5, 5, 5, 
            5, 5, 5, 5)
    )
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.mvaEleID_PHYS14_PU20bx25_nonTrig_V1_producer_config = cms.PSet(
    mvaName = cms.string('ElectronMVAEstimatorRun2Phys14NonTrig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_10_oldscenario2phys14_BDT.weights.xml')
)

process.mvaEleID_PHYS14_PU20bx25_nonTrig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.253, 0.081, -0.081, 0.965, 0.917, 
            0.683),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-PHYS14-PU20bx25-nonTrig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(False)
)

process.mvaEleID_PHYS14_PU20bx25_nonTrig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.483, -0.267, -0.323, 0.933, 0.825, 
            0.337),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-PHYS14-PU20bx25-nonTrig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(False)
)

process.mvaEleID_Spring15_25ns_Trig_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
)

process.mvaEleID_Spring15_25ns_Trig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Categories"),
        mvaCuts = cms.vdouble(0.988153, 0.96791, 0.841729),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-Trig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_25ns_Trig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Categories"),
        mvaCuts = cms.vdouble(0.972153, 0.922126, 0.610764),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-Trig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring15NonTrig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml')
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(0.287435, 0.221846, -0.303263, 0.967083, 0.929117, 
            0.726311),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-nonTrig-V1-wp80')
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.083313, -0.235222, -0.67099, 0.913286, 0.805013, 
            0.358969),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-nonTrig-V1-wp90')
)

process.mvaEleID_Spring15_50ns_Trig_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
    mvaTag = cms.string('50nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
)

process.mvaEleID_Spring15_50ns_Trig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Categories"),
        mvaCuts = cms.vdouble(0.981841, 0.946762, 0.79704),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-50ns-Trig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_50ns_Trig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Categories"),
        mvaCuts = cms.vdouble(0.953843, 0.849994, 0.514118),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-50ns-Trig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(True)
)

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(False)
)

process.mvaConfigsForEleProducer = cms.VPSet(cms.PSet(
    mvaName = cms.string('ElectronMVAEstimatorRun2Phys14NonTrig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_10_oldscenario2phys14_BDT.weights.xml')
), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring15NonTrig'),
        mvaTag = cms.string('25nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml')
    ), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
        mvaTag = cms.string('50nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
    ), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
        mvaTag = cms.string('25nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
    ))

