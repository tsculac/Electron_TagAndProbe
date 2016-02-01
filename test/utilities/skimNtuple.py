import ROOT
import json
import array
import math
from optparse import OptionParser

data = ""

def readJSON(jsonName):
    global data
    json_data=open(jsonName).read()
    data = json.loads(json_data)

def main(options):
    global data
    file = ROOT.TFile(options.input)

    directory = file.Get(options.directory)
    directory.cd()
    tree = directory.Get("fitter_tree")
    entries = tree.GetEntries()  

    #--- Write to new file
    outFile = options.input.split(".root")[0]+"_test.root"
    newFile = ROOT.TFile(outFile, "RECREATE")
    directory_new = newFile.mkdir(options.directory)
    directory_new.cd()
    tree_new = tree.CloneTree(0)
    
    
    dPhi = array.array('f', [0])
    reltrkIso = array.array('f', [0])
    
    mass2 = array.array('f',[0])
    FSRpt = array.array('f',[0])
    
    passIso = array.array('I', [0])
    passSip = array.array('I', [0])
    passMVA = array.array('I', [0])
    passDxyz = array.array('I', [0])
    passSIPDxyz = array.array('I', [0])
    passALL = array.array('I', [0])
    
    tree_new.Branch("mass2", mass2, "mass2/F")
    tree_new.Branch("FSR_pt", FSRpt, "FSRpt/F")
    tree_new.Branch("passingIso", passIso, "passIso/I")
    tree_new.Branch("passingSip", passSip, "passSip/I")
    tree_new.Branch("passingMVA", passMVA, "passMVA/I")
    tree_new.Branch("passingDxyz", passDxyz, "passDxyz/I")
    tree_new.Branch("passingSIPDxyz", passSIPDxyz, "passSIPDxyz/I")
    tree_new.Branch("passingALL", passALL, "passALL/I")
    
    tree_new.Branch("dPhi", dPhi, "dPhi/F")
    tree_new.Branch("reltrkIso", reltrkIso, "reltrkIso/F")
    
    for z in range(entries):
        tree.GetEntry(z)
        if (z%100000 == 0):
            percent = z/float(entries)*100
            print "%.2f %% processed..." %percent
        
        passIso[0] = 0
        passSip[0] = 0
        passMVA[0] = 0
        passDxyz[0] = 0
        passSIPDxyz[0] = 0
        passALL[0] = 0
        
        passCut = False
        
        if(tree.probe_FSRphoton_e > 0. or abs(tree.probe_FSRphoton_px) > 0. or abs(tree.probe_FSRphoton_py) > 0. or abs(tree.probe_FSRphoton_pz) > 0. or tree.tag_FSRphoton_e > 0. or abs(tree.tag_FSRphoton_px) > 0. or abs(tree.tag_FSRphoton_py) > 0. or abs(tree.tag_FSRphoton_pz) > 0.):
            Z_e = tree.probe_Ele_e + tree.tag_Ele_e + tree.probe_FSRphoton_e + tree.tag_FSRphoton_e
            Z_px = tree.probe_Ele_px + tree.tag_Ele_px + tree.probe_FSRphoton_px + tree.tag_FSRphoton_px
            Z_py = tree.probe_Ele_py + tree.tag_Ele_py + tree.probe_FSRphoton_py + tree.tag_FSRphoton_py
            Z_pz = tree.probe_Ele_pz + tree.tag_Ele_pz + tree.probe_FSRphoton_pz + tree.tag_FSRphoton_pz
            
            FSR_px = tree.probe_FSRphoton_px + tree.tag_FSRphoton_px
            FSR_py = tree.probe_FSRphoton_py + tree.tag_FSRphoton_py
            
            passCut = True

            FSRpt[0] = math.sqrt( FSR_px*FSR_px + FSR_py*FSR_py)
            mass2[0] = math.sqrt( Z_e*Z_e - Z_px*Z_px - Z_py*Z_py - Z_pz*Z_pz)
        else:
            mass2[0] = tree.mass
            FSRpt[0] = 0
        
        
        
        if (tree.probe_Ele_iso < 0.35) :
            passIso[0] = 1
        else :
            passIso[0] = 0
        
        if (tree.probe_Ele_sip < 4.0) :
            passSip[0] = 1
        else :
            passSip[0] = 0
        
        if (tree.probe_passing_MVA > 0.5) :
            passMVA[0] = 1
        else :
            passMVA[0] = 0

        if (abs(tree.probe_Ele_dxy) < 0.5 and abs(tree.probe_Ele_dz) < 1.) :
            passDxyz[0] = 1
        else :
            passDxyz[0] = 0
        
        if ( passSip[0] == 1 and passDxyz[0] ==1):
            passSIPDxyz[0] = 1
        else:
            passSIPDxyz[0] = 0
        
        if ( passIso[0] == 1 and passMVA[0] == 1 and passSip[0] == 1 and passDxyz[0] ==1):
            passALL[0] = 1
        else:
            passALL[0] = 0


#        if (tree.tag_Ele_pt > 30. and tree.probe_Ele_isGap == 0):
        reltrkIso[0] = (tree.probe_Ele_trkIso / tree.probe_Ele_pt)
        dPhi[0] = tree.tag_Ele_phi - tree.probe_Ele_phi

#if((tree.probe_Ele_pt < 30. and (tree.probe_Ele_trkIso / tree.probe_Ele_pt) < 0.2) or tree.probe_Ele_pt > 30.):
#passCut = True
           
        
        if (passCut):
            tree_new.Fill()

    tree_new.GetCurrentFile().Write("",ROOT.TObject.kOverwrite)
    tree_new.GetCurrentFile().Close()



if __name__ == "__main__":  
    parser = OptionParser()
    parser.add_option("-i", "--input",     default="~/Moriond2016/CMSSW_7_6_3/src/PhysicsTools/TagAndProbe/test/TnPTree_data.root",           help="Input filename")
    parser.add_option("-d", "--directory", default="GsfElectronToRECO",         help="Directory with tree")
    parser.add_option("--mc", dest="isMC", action="store_true", help="MC file or not", default=False)
    parser.add_option("--json",            default="json_DCSONLY_Run2015B.txt", help="Name of JSON file")

    (options, arg) = parser.parse_args()
     
     #if (not options.isMC):
     #   readJSON(options.json)
    
    main(options)

