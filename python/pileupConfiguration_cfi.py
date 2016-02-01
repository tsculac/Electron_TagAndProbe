import FWCore.ParameterSet.Config as cms

#### MC PU DISTRIBUTIONS
from SimGeneral.MixingModule.mix_2015_25ns_Startup_PoissonOOTPU_cfi import mix as mix_2015_25ns
from SimGeneral.MixingModule.mix_2015_50ns_Startup_PoissonOOTPU_cfi import mix as mix_2015_50ns
from SimGeneral.MixingModule.mix_2015_25ns_FallMC_matchData_PoissonOOTPU_cfi import mix as mix_2015_25ns_realistScenario
pu_distribs = { "74X_mcRun2_asymptotic_v2" : mix_2015_25ns.input.nbPileupEvents.probValue,
                "76X_mcRun2_asymptotic_v12" : mix_2015_25ns_realistScenario.input.nbPileupEvents.probValue
                }

#### DATA PU DISTRIBUTIONS
data_pu_distribs = { "Moriond_golden_JSON" : [1.11e+05,5.51e+05,7.91e+05,1.11e+06,1.88e+06,4.17e+06,1.21e+07,4.46e+07,1.34e+08,2.47e+08,3.37e+08,3.82e+08,3.63e+08,2.85e+08,1.81e+08,9.44e+07,4.17e+07,1.72e+07,7.9e+06,4.21e+06,2.18e+06,9.43e+05,3.22e+05,8.9e+04,2.16e+04,5.43e+03,1.6e+03,551,206,80.1,31.2,11.9,4.38,1.54,0.518,0.165,0.0501,0.0144,0.00394,0.00102,0.000251,5.87e-05,1.3e-05,2.74e-06,5.47e-07,1.04e-07,1.86e-08,3.18e-09,5.16e-10,9.35e-11,0,0] }
    
    
pileupProducer = cms.EDProducer("PileupWeightProducer",
                                #hardcodedWeights = cms.untracked.bool(True),
                                pileupInfoTag    = cms.InputTag("slimmedAddPileupInfo"),
                                PileupMC = cms.vdouble(pu_distribs["76X_mcRun2_asymptotic_v12"]),
                                PileupData = cms.vdouble(data_pu_distribs["Moriond_golden_JSON"]),
                                )
