void effAndSmallSF_DATA_MC_EE2_pT()
{
//=========Macro generated from canvas: Canvas/Canvas
//=========  (Sat Jan 30 21:19:13 2016) by ROOT version6.02/05
   TCanvas *Canvas = new TCanvas("Canvas", "Canvas",0,0,725,725);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   Canvas->SetHighLightColor(2);
   Canvas->Range(0,0,1,1);
   Canvas->SetFillColor(0);
   Canvas->SetBorderMode(0);
   Canvas->SetBorderSize(2);
   Canvas->SetTickx(1);
   Canvas->SetTicky(1);
   Canvas->SetLeftMargin(0.15);
   Canvas->SetRightMargin(0.05);
   Canvas->SetTopMargin(0.07);
   Canvas->SetBottomMargin(0.17);
   Canvas->SetFrameFillStyle(0);
   Canvas->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "pad1",0.01,0.3,0.99,0.99);
   pad1->Draw();
   pad1->cd();
   pad1->Range(-15.32432,-0.03620689,94.13513,1.17069);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetGridx();
   pad1->SetGridy();
   pad1->SetTickx(1);
   pad1->SetTicky(1);
   pad1->SetLeftMargin(0.14);
   pad1->SetRightMargin(0.12);
   pad1->SetBottomMargin(0.03);
   pad1->SetFrameFillStyle(0);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameFillStyle(0);
   pad1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx3016[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3016[6] = {
   0.8968,
   0.922,
   0.9547,
   0.9744,
   0.979,
   0.9835};
   Double_t Graph0_felx3016[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3016[6] = {
   0.0088,
   0.0039,
   0.0016,
   0.0008,
   0.0007,
   0.001};
   Double_t Graph0_fehx3016[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3016[6] = {
   0.0088,
   0.0039,
   0.0016,
   0.0008,
   0.0007,
   0.001};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(6,Graph0_fx3016,Graph0_fy3016,Graph0_felx3016,Graph0_fehx3016,Graph0_fely3016,Graph0_fehy3016);
   grae->SetName("Graph0");
   grae->SetTitle("TGraphAsymmErrors for MC efficiencies");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#99ccff");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(22);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_TH1F3016 = new TH1F("Graph_TH1F3016","TH1F histogram",100,0,81);
   Graph_TH1F3016->SetMinimum(0);
   Graph_TH1F3016->SetMaximum(1.05);
   Graph_TH1F3016->SetFillStyle(0);
   Graph_TH1F3016->SetLineStyle(0);
   Graph_TH1F3016->SetMarkerStyle(20);
   Graph_TH1F3016->GetXaxis()->SetLabelFont(42);
   Graph_TH1F3016->GetXaxis()->SetLabelOffset(0.007);
   Graph_TH1F3016->GetXaxis()->SetLabelSize(0);
   Graph_TH1F3016->GetXaxis()->SetTitleSize(0.06);
   Graph_TH1F3016->GetXaxis()->SetTitleFont(42);
   Graph_TH1F3016->GetYaxis()->SetTitle("ID efficiency");
   Graph_TH1F3016->GetYaxis()->SetLabelFont(42);
   Graph_TH1F3016->GetYaxis()->SetLabelOffset(0.007);
   Graph_TH1F3016->GetYaxis()->SetLabelSize(0.05);
   Graph_TH1F3016->GetYaxis()->SetTitleSize(0.06);
   Graph_TH1F3016->GetYaxis()->SetTitleOffset(0.85);
   Graph_TH1F3016->GetYaxis()->SetTitleFont(42);
   Graph_TH1F3016->GetZaxis()->SetLabelFont(42);
   Graph_TH1F3016->GetZaxis()->SetLabelOffset(0.007);
   Graph_TH1F3016->GetZaxis()->SetLabelSize(0.05);
   Graph_TH1F3016->GetZaxis()->SetTitleSize(0.06);
   Graph_TH1F3016->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_TH1F3016);
   
   grae->Draw("a2");
   
   Double_t Graph0_fx3017[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3017[6] = {
   0.8968,
   0.922,
   0.9547,
   0.9744,
   0.979,
   0.9835};
   Double_t Graph0_felx3017[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3017[6] = {
   0.0088,
   0.0039,
   0.0016,
   0.0008,
   0.0007,
   0.001};
   Double_t Graph0_fehx3017[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3017[6] = {
   0.0088,
   0.0039,
   0.0016,
   0.0008,
   0.0007,
   0.001};
   grae = new TGraphAsymmErrors(6,Graph0_fx3017,Graph0_fy3017,Graph0_felx3017,Graph0_fehx3017,Graph0_fely3017,Graph0_fehy3017);
   grae->SetName("Graph0");
   grae->SetTitle("TGraphAsymmErrors for MC efficiencies");

   ci = TColor::GetColor("#99ccff");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(22);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph_TH1F30163017 = new TH1F("Graph_Graph_TH1F30163017","TH1F histogram",100,0,81);
   Graph_Graph_TH1F30163017->SetMinimum(0);
   Graph_Graph_TH1F30163017->SetMaximum(1.05);
   Graph_Graph_TH1F30163017->SetFillStyle(0);
   Graph_Graph_TH1F30163017->SetLineStyle(0);
   Graph_Graph_TH1F30163017->SetMarkerStyle(20);
   Graph_Graph_TH1F30163017->GetXaxis()->SetLabelFont(42);
   Graph_Graph_TH1F30163017->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_TH1F30163017->GetXaxis()->SetLabelSize(0);
   Graph_Graph_TH1F30163017->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_TH1F30163017->GetXaxis()->SetTitleFont(42);
   Graph_Graph_TH1F30163017->GetYaxis()->SetTitle("ID efficiency");
   Graph_Graph_TH1F30163017->GetYaxis()->SetLabelFont(42);
   Graph_Graph_TH1F30163017->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_TH1F30163017->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_TH1F30163017->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_TH1F30163017->GetYaxis()->SetTitleOffset(0.85);
   Graph_Graph_TH1F30163017->GetYaxis()->SetTitleFont(42);
   Graph_Graph_TH1F30163017->GetZaxis()->SetLabelFont(42);
   Graph_Graph_TH1F30163017->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_TH1F30163017->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_TH1F30163017->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_TH1F30163017->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_TH1F30163017);
   
   grae->Draw("p");
   
   Double_t Graph1_fx3018[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph1_fy3018[6] = {
   0.952,
   0.9317,
   0.9563,
   0.9691,
   0.9762,
   0.9791};
   Double_t Graph1_felx3018[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph1_fely3018[6] = {
   0.017,
   0.0049,
   0.0017,
   0.0009,
   0.0007,
   0.0012};
   Double_t Graph1_fehx3018[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph1_fehy3018[6] = {
   0.017,
   0.0049,
   0.0017,
   0.0009,
   0.0007,
   0.0012};
   grae = new TGraphAsymmErrors(6,Graph1_fx3018,Graph1_fy3018,Graph1_felx3018,Graph1_fehx3018,Graph1_fely3018,Graph1_fehy3018);
   grae->SetName("Graph1");
   grae->SetTitle("TGraphAsymmErrors for Data efficiencies");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(9);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph3018 = new TH1F("Graph_Graph3018","TGraphAsymmErrors for Data efficiencies",100,0,87.3);
   Graph_Graph3018->SetMinimum(0.92145);
   Graph_Graph3018->SetMaximum(0.98565);
   Graph_Graph3018->SetDirectory(0);
   Graph_Graph3018->SetStats(0);
   Graph_Graph3018->SetFillStyle(0);
   Graph_Graph3018->SetLineStyle(0);
   Graph_Graph3018->SetMarkerStyle(20);
   Graph_Graph3018->GetXaxis()->SetLabelFont(42);
   Graph_Graph3018->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph3018->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3018->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3018->GetXaxis()->SetTitleFont(42);
   Graph_Graph3018->GetYaxis()->SetLabelFont(42);
   Graph_Graph3018->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3018->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3018->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3018->GetYaxis()->SetTitleOffset(0.85);
   Graph_Graph3018->GetYaxis()->SetTitleFont(42);
   Graph_Graph3018->GetZaxis()->SetLabelFont(42);
   Graph_Graph3018->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3018->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3018->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3018->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3018);
   
   grae->Draw("p");
   
   TLegend *leg = new TLegend(0.63,0.2,0.87,0.33,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph1","Data","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(9);
   entry->SetMarkerSize(0.7);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","Simulation","fp");

   ci = TColor::GetColor("#99ccff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#3399ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#3399ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(0.7);
   entry->SetTextFont(62);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.14,0.94,0.89,0.99,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillStyle(0);
   pt->SetTextAlign(12);
   pt->SetTextSize(0.03);
   TText *AText = pt->AddText(0.01,0.3,"CMS Preliminary");
   AText = pt->AddText(0.7,0.3,"#sqrt{s} = 13 TeV, L = 2.26 fb^{-1}");
   pt->Draw();
      tex = new TLatex(0.67,0.4,"Z #rightarrow e^{+} e^{-}");
tex->SetNDC();
   tex->SetTextSize(0.03);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.63,0.35,"2.00 < |#eta| < 2.50");
tex->SetNDC();
   tex->SetTextSize(0.03);
   tex->SetLineWidth(2);
   tex->Draw();
   pad1->Modified();
   Canvas->cd();
  
// ------------>Primitives in pad: pad2
   TPad *pad2 = new TPad("pad2", "pad2",0.01,0.01,0.99,0.3);
   pad2->Draw();
   pad2->cd();
   pad2->Range(-15.32432,0.4915493,94.13513,1.125352);
   pad2->SetFillColor(0);
   pad2->SetBorderMode(0);
   pad2->SetBorderSize(2);
   pad2->SetGridx();
   pad2->SetGridy();
   pad2->SetTickx(1);
   pad2->SetTicky(1);
   pad2->SetLeftMargin(0.14);
   pad2->SetRightMargin(0.12);
   pad2->SetTopMargin(0.04);
   pad2->SetBottomMargin(0.25);
   pad2->SetFrameFillStyle(0);
   pad2->SetFrameBorderMode(0);
   pad2->SetFrameFillStyle(0);
   pad2->SetFrameBorderMode(0);
   
   Double_t Graph0_fx3019[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3019[6] = {
   1.0616,
   1.0105,
   1.0017,
   0.9945,
   0.9971,
   0.9955};
   Double_t Graph0_felx3019[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3019[6] = {
   0.0248,
   0.0109,
   0.0107,
   0.0023,
   0.0024,
   0.0021};
   Double_t Graph0_fehx3019[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3019[6] = {
   0.0248,
   0.0109,
   0.0107,
   0.0023,
   0.0024,
   0.0021};
   grae = new TGraphAsymmErrors(6,Graph0_fx3019,Graph0_fy3019,Graph0_felx3019,Graph0_fehx3019,Graph0_fely3019,Graph0_fehy3019);
   grae->SetName("Graph0");
   grae->SetTitle("TGraphAsymmErrors for scale factors");

   ci = TColor::GetColor("#99ccff");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_Small TH1F3019 = new TH1F("Graph_Small TH1F3019","Small TH1F histogram",100,0,81);
   Graph_Small TH1F3019->SetMinimum(0.65);
   Graph_Small TH1F3019->SetMaximum(1.1);
   Graph_Small TH1F3019->SetFillStyle(0);
   Graph_Small TH1F3019->SetLineStyle(0);
   Graph_Small TH1F3019->SetMarkerStyle(20);
   Graph_Small TH1F3019->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_Small TH1F3019->GetXaxis()->SetLabelFont(42);
   Graph_Small TH1F3019->GetXaxis()->SetLabelOffset(0.007);
   Graph_Small TH1F3019->GetXaxis()->SetLabelSize(0.08);
   Graph_Small TH1F3019->GetXaxis()->SetTitleSize(0.08);
   Graph_Small TH1F3019->GetXaxis()->SetTitleFont(42);
   Graph_Small TH1F3019->GetYaxis()->SetLabelFont(42);
   Graph_Small TH1F3019->GetYaxis()->SetLabelOffset(0.007);
   Graph_Small TH1F3019->GetYaxis()->SetLabelSize(0.08);
   Graph_Small TH1F3019->GetYaxis()->SetTitleSize(0.08);
   Graph_Small TH1F3019->GetYaxis()->SetTitleOffset(0.75);
   Graph_Small TH1F3019->GetYaxis()->SetTitleFont(42);
   Graph_Small TH1F3019->GetZaxis()->SetLabelFont(42);
   Graph_Small TH1F3019->GetZaxis()->SetLabelOffset(0.007);
   Graph_Small TH1F3019->GetZaxis()->SetLabelSize(0.05);
   Graph_Small TH1F3019->GetZaxis()->SetTitleSize(0.06);
   Graph_Small TH1F3019->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Small TH1F3019);
   
   grae->Draw("a2");
   
   Double_t Graph0_fx3020[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3020[6] = {
   1.0616,
   1.0105,
   1.0017,
   0.9945,
   0.9971,
   0.9955};
   Double_t Graph0_felx3020[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3020[6] = {
   0.0248,
   0.0109,
   0.0107,
   0.0023,
   0.0024,
   0.0021};
   Double_t Graph0_fehx3020[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3020[6] = {
   0.0248,
   0.0109,
   0.0107,
   0.0023,
   0.0024,
   0.0021};
   grae = new TGraphAsymmErrors(6,Graph0_fx3020,Graph0_fy3020,Graph0_felx3020,Graph0_fehx3020,Graph0_fely3020,Graph0_fehy3020);
   grae->SetName("Graph0");
   grae->SetTitle("TGraphAsymmErrors for scale factors");

   ci = TColor::GetColor("#99ccff");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph_Small TH1F30193020 = new TH1F("Graph_Graph_Small TH1F30193020","Small TH1F histogram",100,0,81);
   Graph_Graph_Small TH1F30193020->SetMinimum(0.65);
   Graph_Graph_Small TH1F30193020->SetMaximum(1.1);
   Graph_Graph_Small TH1F30193020->SetFillStyle(0);
   Graph_Graph_Small TH1F30193020->SetLineStyle(0);
   Graph_Graph_Small TH1F30193020->SetMarkerStyle(20);
   Graph_Graph_Small TH1F30193020->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_Graph_Small TH1F30193020->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Small TH1F30193020->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Small TH1F30193020->GetXaxis()->SetLabelSize(0.08);
   Graph_Graph_Small TH1F30193020->GetXaxis()->SetTitleSize(0.08);
   Graph_Graph_Small TH1F30193020->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Small TH1F30193020->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Small TH1F30193020->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Small TH1F30193020->GetYaxis()->SetLabelSize(0.08);
   Graph_Graph_Small TH1F30193020->GetYaxis()->SetTitleSize(0.08);
   Graph_Graph_Small TH1F30193020->GetYaxis()->SetTitleOffset(0.75);
   Graph_Graph_Small TH1F30193020->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Small TH1F30193020->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Small TH1F30193020->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Small TH1F30193020->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Small TH1F30193020->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Small TH1F30193020->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Small TH1F30193020);
   
   grae->Draw("p");
   pad2->Modified();
   Canvas->cd();
   Canvas->Modified();
   Canvas->cd();
   Canvas->SetSelected(Canvas);
}
