import ROOT

ROOT.gROOT.SetBatch(True)

vars = ["mass","event_nPV"]

f1 = ROOT.TFile("~/Data/MC_2015_v1/TnPTree_mc_CrackFlagsFSRrecovery_76_PU71.root")
t1 = f1.Get("GsfElectronToRECO/fitter_tree")
h1 = []
t1.Draw(vars[0]+">>"+vars[0]+"(60, 60, 120)", "(probe_Ele_pt > 6.)*totWeight", "GOFF")
h1.append(ROOT.gDirectory.Get(vars[0]))
t1.Draw(vars[1]+">>"+vars[1]+"(30, 0, 30)", "(probe_Ele_pt > 0.)*totWeight", "GOFF")
h1.append(ROOT.gDirectory.Get(vars[1]))

f2 = ROOT.TFile("~/Data/RunD2015_Data_v1/TnPTree_RunCD_complete_76_Crackflags.root")
t2 = f2.Get("GsfElectronToRECO/fitter_tree")
h2 = []
t2.Draw(vars[0]+">>"+vars[0]+"(60, 60, 120)", "(probe_Ele_pt > 6.)", "GOFF")
h2.append(ROOT.gDirectory.Get(vars[0]))
t2.Draw(vars[1]+">>"+vars[1]+"(30, 0, 30)", "(probe_Ele_pt > 0.)", "GOFF")
h2.append(ROOT.gDirectory.Get(vars[1]))


c = []
out = ROOT.TFile("nPV.root", "recreate")
for i in xrange(len(h1)):
    c.append(ROOT.TCanvas("c"+str(i), ""))
    h2[i].Draw("PE")
    h1[i].Draw("HISTSAME")
    h1[i].SetFillColor(ROOT.kRed)
    h2[i].Draw("PESAME")
    h2[i].SetMarkerStyle(20)
    h1[i].Scale(h2[i].Integral()/h1[i].Integral())
    c[-1].Write()


out.Close()
