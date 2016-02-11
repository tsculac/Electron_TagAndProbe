void effAndSmallSF_DATA_MC_EE1_pT()
{
//=========Macro generated from canvas: Canvas/Canvas
//=========  (Mon Feb  8 16:36:23 2016) by ROOT version6.02/05
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
   
   Double_t Graph0_fx3011[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3011[6] = {
   0.9444,
   0.961,
   0.9626,
   0.9604,
   0.9597,
   0.9567};
   Double_t Graph0_felx3011[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3011[6] = {
   0.0053,
   0.0024,
   0.0013,
   0.0008,
   0.0007,
   0.0014};
   Double_t Graph0_fehx3011[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3011[6] = {
   0.0053,
   0.0024,
   0.0013,
   0.0008,
   0.0007,
   0.0014};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(6,Graph0_fx3011,Graph0_fy3011,Graph0_felx3011,Graph0_fehx3011,Graph0_fely3011,Graph0_fehy3011);
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
   
   TH1F *Graph_TH1F3011 = new TH1F("Graph_TH1F3011","TH1F histogram",100,0,81);
   Graph_TH1F3011->SetMinimum(0);
   Graph_TH1F3011->SetMaximum(1.05);
   Graph_TH1F3011->SetFillStyle(0);
   Graph_TH1F3011->SetLineStyle(0);
   Graph_TH1F3011->SetMarkerStyle(20);
   Graph_TH1F3011->GetXaxis()->SetLabelFont(42);
   Graph_TH1F3011->GetXaxis()->SetLabelOffset(0.007);
   Graph_TH1F3011->GetXaxis()->SetLabelSize(0);
   Graph_TH1F3011->GetXaxis()->SetTitleSize(0.06);
   Graph_TH1F3011->GetXaxis()->SetTitleFont(42);
   Graph_TH1F3011->GetYaxis()->SetTitle("SIP efficiency");
   Graph_TH1F3011->GetYaxis()->SetLabelFont(42);
   Graph_TH1F3011->GetYaxis()->SetLabelOffset(0.007);
   Graph_TH1F3011->GetYaxis()->SetLabelSize(0.05);
   Graph_TH1F3011->GetYaxis()->SetTitleSize(0.06);
   Graph_TH1F3011->GetYaxis()->SetTitleOffset(0.85);
   Graph_TH1F3011->GetYaxis()->SetTitleFont(42);
   Graph_TH1F3011->GetZaxis()->SetLabelFont(42);
   Graph_TH1F3011->GetZaxis()->SetLabelOffset(0.007);
   Graph_TH1F3011->GetZaxis()->SetLabelSize(0.05);
   Graph_TH1F3011->GetZaxis()->SetTitleSize(0.06);
   Graph_TH1F3011->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_TH1F3011);
   
   grae->Draw("a2");
   
   Double_t Graph0_fx3012[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3012[6] = {
   0.9444,
   0.961,
   0.9626,
   0.9604,
   0.9597,
   0.9567};
   Double_t Graph0_felx3012[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3012[6] = {
   0.0053,
   0.0024,
   0.0013,
   0.0008,
   0.0007,
   0.0014};
   Double_t Graph0_fehx3012[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3012[6] = {
   0.0053,
   0.0024,
   0.0013,
   0.0008,
   0.0007,
   0.0014};
   grae = new TGraphAsymmErrors(6,Graph0_fx3012,Graph0_fy3012,Graph0_felx3012,Graph0_fehx3012,Graph0_fely3012,Graph0_fehy3012);
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
   
   TH1F *Graph_Graph_TH1F30113012 = new TH1F("Graph_Graph_TH1F30113012","TH1F histogram",100,0,81);
   Graph_Graph_TH1F30113012->SetMinimum(0);
   Graph_Graph_TH1F30113012->SetMaximum(1.05);
   Graph_Graph_TH1F30113012->SetFillStyle(0);
   Graph_Graph_TH1F30113012->SetLineStyle(0);
   Graph_Graph_TH1F30113012->SetMarkerStyle(20);
   Graph_Graph_TH1F30113012->GetXaxis()->SetLabelFont(42);
   Graph_Graph_TH1F30113012->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_TH1F30113012->GetXaxis()->SetLabelSize(0);
   Graph_Graph_TH1F30113012->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_TH1F30113012->GetXaxis()->SetTitleFont(42);
   Graph_Graph_TH1F30113012->GetYaxis()->SetTitle("SIP efficiency");
   Graph_Graph_TH1F30113012->GetYaxis()->SetLabelFont(42);
   Graph_Graph_TH1F30113012->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_TH1F30113012->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_TH1F30113012->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_TH1F30113012->GetYaxis()->SetTitleOffset(0.85);
   Graph_Graph_TH1F30113012->GetYaxis()->SetTitleFont(42);
   Graph_Graph_TH1F30113012->GetZaxis()->SetLabelFont(42);
   Graph_Graph_TH1F30113012->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_TH1F30113012->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_TH1F30113012->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_TH1F30113012->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_TH1F30113012);
   
   grae->Draw("p");
   
   Double_t Graph1_fx3013[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph1_fy3013[6] = {
   1,
   0.9686,
   0.9476,
   0.9463,
   0.9445,
   0.9481};
   Double_t Graph1_felx3013[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph1_fely3013[6] = {
   0.009,
   0.0038,
   0.0072,
   0.0005,
   0.0007,
   0.0013};
   Double_t Graph1_fehx3013[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph1_fehy3013[6] = {
   0.009,
   0.0038,
   0.0072,
   0.0005,
   0.0007,
   0.0013};
   grae = new TGraphAsymmErrors(6,Graph1_fx3013,Graph1_fy3013,Graph1_felx3013,Graph1_fehx3013,Graph1_fely3013,Graph1_fehy3013);
   grae->SetName("Graph1");
   grae->SetTitle("TGraphAsymmErrors for Data efficiencies");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(9);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph3013 = new TH1F("Graph_Graph3013","TGraphAsymmErrors for Data efficiencies",100,0,87.3);
   Graph_Graph3013->SetMinimum(0.93354);
   Graph_Graph3013->SetMaximum(1.01586);
   Graph_Graph3013->SetDirectory(0);
   Graph_Graph3013->SetStats(0);
   Graph_Graph3013->SetFillStyle(0);
   Graph_Graph3013->SetLineStyle(0);
   Graph_Graph3013->SetMarkerStyle(20);
   Graph_Graph3013->GetXaxis()->SetLabelFont(42);
   Graph_Graph3013->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph3013->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3013->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3013->GetXaxis()->SetTitleFont(42);
   Graph_Graph3013->GetYaxis()->SetLabelFont(42);
   Graph_Graph3013->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3013->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3013->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3013->GetYaxis()->SetTitleOffset(0.85);
   Graph_Graph3013->GetYaxis()->SetTitleFont(42);
   Graph_Graph3013->GetZaxis()->SetLabelFont(42);
   Graph_Graph3013->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3013->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3013->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3013->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3013);
   
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
      tex = new TLatex(0.63,0.35,"1.48 < |#eta| < 2.00");
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
   
   Double_t Graph0_fx3014[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3014[6] = {
   1.0589,
   1.0079,
   0.9844,
   0.9853,
   0.9842,
   0.991};
   Double_t Graph0_felx3014[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3014[6] = {
   0.0112,
   0.0047,
   0.0076,
   0.001,
   0.001,
   0.002};
   Double_t Graph0_fehx3014[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3014[6] = {
   0.0112,
   0.0047,
   0.0076,
   0.001,
   0.001,
   0.002};
   grae = new TGraphAsymmErrors(6,Graph0_fx3014,Graph0_fy3014,Graph0_felx3014,Graph0_fehx3014,Graph0_fely3014,Graph0_fehy3014);
   grae->SetName("Graph0");
   grae->SetTitle("TGraphAsymmErrors for scale factors");

   ci = TColor::GetColor("#99ccff");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_Small TH1F3014 = new TH1F("Graph_Small TH1F3014","Small TH1F histogram",100,0,81);
   Graph_Small TH1F3014->SetMinimum(0.65);
   Graph_Small TH1F3014->SetMaximum(1.1);
   Graph_Small TH1F3014->SetFillStyle(0);
   Graph_Small TH1F3014->SetLineStyle(0);
   Graph_Small TH1F3014->SetMarkerStyle(20);
   Graph_Small TH1F3014->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_Small TH1F3014->GetXaxis()->SetLabelFont(42);
   Graph_Small TH1F3014->GetXaxis()->SetLabelOffset(0.007);
   Graph_Small TH1F3014->GetXaxis()->SetLabelSize(0.08);
   Graph_Small TH1F3014->GetXaxis()->SetTitleSize(0.08);
   Graph_Small TH1F3014->GetXaxis()->SetTitleFont(42);
   Graph_Small TH1F3014->GetYaxis()->SetLabelFont(42);
   Graph_Small TH1F3014->GetYaxis()->SetLabelOffset(0.007);
   Graph_Small TH1F3014->GetYaxis()->SetLabelSize(0.08);
   Graph_Small TH1F3014->GetYaxis()->SetTitleSize(0.08);
   Graph_Small TH1F3014->GetYaxis()->SetTitleOffset(0.75);
   Graph_Small TH1F3014->GetYaxis()->SetTitleFont(42);
   Graph_Small TH1F3014->GetZaxis()->SetLabelFont(42);
   Graph_Small TH1F3014->GetZaxis()->SetLabelOffset(0.007);
   Graph_Small TH1F3014->GetZaxis()->SetLabelSize(0.05);
   Graph_Small TH1F3014->GetZaxis()->SetTitleSize(0.06);
   Graph_Small TH1F3014->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Small TH1F3014);
   
   grae->Draw("a2");
   
   Double_t Graph0_fx3015[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3015[6] = {
   1.0589,
   1.0079,
   0.9844,
   0.9853,
   0.9842,
   0.991};
   Double_t Graph0_felx3015[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3015[6] = {
   0.0112,
   0.0047,
   0.0076,
   0.001,
   0.001,
   0.002};
   Double_t Graph0_fehx3015[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3015[6] = {
   0.0112,
   0.0047,
   0.0076,
   0.001,
   0.001,
   0.002};
   grae = new TGraphAsymmErrors(6,Graph0_fx3015,Graph0_fy3015,Graph0_felx3015,Graph0_fehx3015,Graph0_fely3015,Graph0_fehy3015);
   grae->SetName("Graph0");
   grae->SetTitle("TGraphAsymmErrors for scale factors");

   ci = TColor::GetColor("#99ccff");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph_Small TH1F30143015 = new TH1F("Graph_Graph_Small TH1F30143015","Small TH1F histogram",100,0,81);
   Graph_Graph_Small TH1F30143015->SetMinimum(0.65);
   Graph_Graph_Small TH1F30143015->SetMaximum(1.1);
   Graph_Graph_Small TH1F30143015->SetFillStyle(0);
   Graph_Graph_Small TH1F30143015->SetLineStyle(0);
   Graph_Graph_Small TH1F30143015->SetMarkerStyle(20);
   Graph_Graph_Small TH1F30143015->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_Graph_Small TH1F30143015->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Small TH1F30143015->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Small TH1F30143015->GetXaxis()->SetLabelSize(0.08);
   Graph_Graph_Small TH1F30143015->GetXaxis()->SetTitleSize(0.08);
   Graph_Graph_Small TH1F30143015->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Small TH1F30143015->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Small TH1F30143015->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Small TH1F30143015->GetYaxis()->SetLabelSize(0.08);
   Graph_Graph_Small TH1F30143015->GetYaxis()->SetTitleSize(0.08);
   Graph_Graph_Small TH1F30143015->GetYaxis()->SetTitleOffset(0.75);
   Graph_Graph_Small TH1F30143015->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Small TH1F30143015->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Small TH1F30143015->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Small TH1F30143015->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Small TH1F30143015->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Small TH1F30143015->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Small TH1F30143015);
   
   grae->Draw("p");
   pad2->Modified();
   Canvas->cd();
   Canvas->Modified();
   Canvas->cd();
   Canvas->SetSelected(Canvas);
}
