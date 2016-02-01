import ROOT

ROOT.gROOT.SetBatch(True)

vars = ["mass","mass2"]

f1 = ROOT.TFile("~/Data/MC_2015_v1/TnPTree_mc_CrackFlagsFSRrecovery_76_PU71_Z_mass_test.root")
t1 = f1.Get("GsfElectronToRECO/fitter_tree")
h1 = []
t1.Draw(vars[0]+">>"+vars[0]+"(60, 60, 120)", "", "GOFF")
h1.append(ROOT.gDirectory.Get(vars[0]))

f2 = ROOT.TFile("~/Data/MC_2015_v1/TnPTree_mc_CrackFlagsFSRrecovery_76_PU71_Z_mass_test.root")
t2 = f2.Get("GsfElectronToRECO/fitter_tree")
h2 = []
t2.Draw(vars[1]+">>"+vars[1]+"(60, 60, 120)", "", "GOFF")
h2.append(ROOT.gDirectory.Get(vars[1]))



c = []
out = ROOT.TFile("Zmass_comparison.root", "recreate")
for i in xrange(len(h1)):
    c.append(ROOT.TCanvas("c"+str(i), ""))
    h2[i].Draw()
    h1[i].Draw("HISTSAME")
    h1[i].SetFillColor(ROOT.kRed)
    h2[i].Draw("SAME")
    h2[i].SetMarkerStyle(20)
    h1[i].Scale(h2[i].Integral()/h1[i].Integral())
    c[-1].Write()


out.Close()
