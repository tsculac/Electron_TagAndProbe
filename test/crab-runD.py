from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')



config.General.requestName = 'data_RunD_CrackflagsFSRrecovery_76_v1'
config.General.transferOutputs = True

config.section_('JobType')
config.JobType.psetName = 'makeTree.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['TnPTree_data.root']

config.section_('Data')

config.Data.inputDataset = '/SingleElectron/Run2015D-16Dec2015-v1/MINIAOD'
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON_v2.txt'
config.Data.inputDBS = 'global'
config.Data.ignoreLocality = True

# Run D on 22/09
#config.Data.runRange = '256675,256801,256734,256677,256676,256729,256801'
#config.Data.runRange = '256676'

config.Data.outLFNDirBase = '/store/user/tsculac/eID/data/Run2015D/SingleElectron/76_Crackflags_v1'

config.Data.totalUnits = -1
config.Data.unitsPerJob = 100
config.Data.splitting = 'LumiBased'
config.Data.publication = False

config.section_('User')

config.section_('Site')
#config.Site.whitelist = ['T2_FR_GRIF_LLR']
#config.Site.blacklist = ['T2_US_Wisconsin']

config.Site.storageSite = 'T2_FR_GRIF_LLR'