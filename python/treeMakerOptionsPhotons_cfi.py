import FWCore.ParameterSet.Config as cms

def setModules(process, options):

    process.sampleInfo = cms.EDProducer("tnp::SampleInfoTree",
                                        genInfo = cms.InputTag("generator")
                                        )

    from HLTrigger.HLTfilters.hltHighLevel_cfi import hltHighLevel
    process.hltFilter = hltHighLevel.clone()
    process.hltFilter.throw = cms.bool(True)
    process.hltFilter.HLTPaths = options['TnPPATHS']
    
    from PhysicsTools.TagAndProbe.pileupConfiguration_cfi import pileupProducer
    process.pileupReweightingProducer = pileupProducer.clone()    

###################################################################
## ELECTRON MODULES
###################################################################
    
    process.goodPhotons = cms.EDFilter("PATPhotonRefSelector",
                                       src = cms.InputTag(options['PHOTON_COLL']),
                                       cut = cms.string(options['PHOTON_CUTS'])    
                                       )

###################################################################
## PHOTON ISOLATION
###################################################################
    process.load("RecoEgamma/PhotonIdentification/PhotonIDValueMapProducer_cfi")

###################################################################
## HLT MATCHING
###################################################################

    process.goodPhotonsTagHLT = cms.EDProducer("PatPhotonTriggerCandProducer",
                                               filterNames = options['TnPHLTTagFilters'],
                                               inputs      = cms.InputTag("goodPhotonsTAGCutBasedTight"),
                                               bits        = cms.InputTag('TriggerResults::HLT'),
                                               objects     = cms.InputTag('selectedPatTrigger'),
                                               dR          = cms.double(0.3),
                                               isAND       = cms.bool(True)
                                               )
    
    process.goodPhotonsProbeHLT = cms.EDProducer("PatPhotonTriggerCandProducer",
                                                 filterNames = options['TnPHLTProbeFilters'],
                                                 inputs      = cms.InputTag("goodPhotons"),
                                                 bits        = cms.InputTag('TriggerResults::HLT'),
                                                 objects     = cms.InputTag('selectedPatTrigger'),
                                                 dR          = cms.double(0.3),
                                                 isAND       = cms.bool(True)
                                                 )

    process.tagTightRECO = cms.EDProducer("CandViewShallowCloneCombiner",
                                          decay = cms.string("goodPhotonsTagHLT@+ goodPhotonsProbeHLT@-"), 
                                          checkCharge = cms.bool(False),
                                          cut = cms.string("40<mass<1000"),
                                          )
    
###################################################################
## MC MATCHING
###################################################################
    
    process.McMatchTag = cms.EDProducer("MCTruthDeltaRMatcherNew",
                                        matchPDGId = cms.vint32(11),
                                        src = cms.InputTag("goodPhotonsTAGCutBasedTight"),
                                        distMin = cms.double(0.2),
                                        matched = cms.InputTag("prunedGenParticles"),
                                        checkCharge = cms.bool(False)
                                        )
    
    process.McMatchRECO = cms.EDProducer("MCTruthDeltaRMatcherNew",
                                         matchPDGId = cms.vint32(11),
                                         src = cms.InputTag("goodPhotons"),
                                         distMin = cms.double(0.2),
                                         matched = cms.InputTag("prunedGenParticles"),
                                         checkCharge = cms.bool(False)
                                         )
