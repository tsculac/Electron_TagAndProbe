from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')



config.General.requestName = 'MC_LO_CrackflagsFSRrecovery_matched_76X_PU71_v1'
config.General.transferOutputs = True

config.section_('JobType')
config.JobType.psetName = 'makeTreeMC.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['TnPTree_mc.root']

config.section_('Data')

config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'

config.Data.inputDBS = 'global'


config.Data.outLFNDirBase = '/store/user/tsculac/eID/MC_2016/matched_v6'

config.Data.totalUnits = -1
config.Data.unitsPerJob = 10
config.Data.splitting = 'FileBased'
config.Data.publication = False

config.section_('User')

config.section_('Site')
#config.Site.whitelist = ['T2_FR_GRIF_LLR']
config.Site.blacklist = ['T2_US_Wisconsin']

config.Site.storageSite = 'T2_FR_GRIF_LLR'
    
