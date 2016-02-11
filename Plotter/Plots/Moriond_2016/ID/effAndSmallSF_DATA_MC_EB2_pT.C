void effAndSmallSF_DATA_MC_EB2_pT()
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
   
   Double_t Graph0_fx3006[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3006[6] = {
   0.9602,
   0.9723,
   0.9845,
   0.9911,
   0.9941,
   0.9951};
   Double_t Graph0_felx3006[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3006[6] = {
   0.0057,
   0.0018,
   0.0069,
   0.0003,
   0.0002,
   0.0004};
   Double_t Graph0_fehx3006[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3006[6] = {
   0.0057,
   0.0018,
   0.0069,
   0.0003,
   0.0002,
   0.0004};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(6,Graph0_fx3006,Graph0_fy3006,Graph0_felx3006,Graph0_fehx3006,Graph0_fely3006,Graph0_fehy3006);
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
   
   TH1F *Graph_TH1F3006 = new TH1F("Graph_TH1F3006","TH1F histogram",100,0,81);
   Graph_TH1F3006->SetMinimum(0);
   Graph_TH1F3006->SetMaximum(1.05);
   Graph_TH1F3006->SetFillStyle(0);
   Graph_TH1F3006->SetLineStyle(0);
   Graph_TH1F3006->SetMarkerStyle(20);
   Graph_TH1F3006->GetXaxis()->SetLabelFont(42);
   Graph_TH1F3006->GetXaxis()->SetLabelOffset(0.007);
   Graph_TH1F3006->GetXaxis()->SetLabelSize(0);
   Graph_TH1F3006->GetXaxis()->SetTitleSize(0.06);
   Graph_TH1F3006->GetXaxis()->SetTitleFont(42);
   Graph_TH1F3006->GetYaxis()->SetTitle("ID efficiency");
   Graph_TH1F3006->GetYaxis()->SetLabelFont(42);
   Graph_TH1F3006->GetYaxis()->SetLabelOffset(0.007);
   Graph_TH1F3006->GetYaxis()->SetLabelSize(0.05);
   Graph_TH1F3006->GetYaxis()->SetTitleSize(0.06);
   Graph_TH1F3006->GetYaxis()->SetTitleOffset(0.85);
   Graph_TH1F3006->GetYaxis()->SetTitleFont(42);
   Graph_TH1F3006->GetZaxis()->SetLabelFont(42);
   Graph_TH1F3006->GetZaxis()->SetLabelOffset(0.007);
   Graph_TH1F3006->GetZaxis()->SetLabelSize(0.05);
   Graph_TH1F3006->GetZaxis()->SetTitleSize(0.06);
   Graph_TH1F3006->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_TH1F3006);
   
   grae->Draw("a2");
   
   Double_t Graph0_fx3007[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3007[6] = {
   0.9602,
   0.9723,
   0.9845,
   0.9911,
   0.9941,
   0.9951};
   Double_t Graph0_felx3007[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3007[6] = {
   0.0057,
   0.0018,
   0.0069,
   0.0003,
   0.0002,
   0.0004};
   Double_t Graph0_fehx3007[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3007[6] = {
   0.0057,
   0.0018,
   0.0069,
   0.0003,
   0.0002,
   0.0004};
   grae = new TGraphAsymmErrors(6,Graph0_fx3007,Graph0_fy3007,Graph0_felx3007,Graph0_fehx3007,Graph0_fely3007,Graph0_fehy3007);
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
   
   TH1F *Graph_Graph_TH1F30063007 = new TH1F("Graph_Graph_TH1F30063007","TH1F histogram",100,0,81);
   Graph_Graph_TH1F30063007->SetMinimum(0);
   Graph_Graph_TH1F30063007->SetMaximum(1.05);
   Graph_Graph_TH1F30063007->SetFillStyle(0);
   Graph_Graph_TH1F30063007->SetLineStyle(0);
   Graph_Graph_TH1F30063007->SetMarkerStyle(20);
   Graph_Graph_TH1F30063007->GetXaxis()->SetLabelFont(42);
   Graph_Graph_TH1F30063007->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_TH1F30063007->GetXaxis()->SetLabelSize(0);
   Graph_Graph_TH1F30063007->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_TH1F30063007->GetXaxis()->SetTitleFont(42);
   Graph_Graph_TH1F30063007->GetYaxis()->SetTitle("ID efficiency");
   Graph_Graph_TH1F30063007->GetYaxis()->SetLabelFont(42);
   Graph_Graph_TH1F30063007->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_TH1F30063007->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_TH1F30063007->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_TH1F30063007->GetYaxis()->SetTitleOffset(0.85);
   Graph_Graph_TH1F30063007->GetYaxis()->SetTitleFont(42);
   Graph_Graph_TH1F30063007->GetZaxis()->SetLabelFont(42);
   Graph_Graph_TH1F30063007->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_TH1F30063007->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_TH1F30063007->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_TH1F30063007->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_TH1F30063007);
   
   grae->Draw("p");
   
   Double_t Graph1_fx3008[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph1_fy3008[6] = {
   0.98,
   0.98,
   0.9811,
   0.991,
   0.9935,
   0.995};
   Double_t Graph1_felx3008[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph1_fely3008[6] = {
   0.013,
   0.003,
   0.0009,
   0.0004,
   0.0007,
   0.0004};
   Double_t Graph1_fehx3008[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph1_fehy3008[6] = {
   0.013,
   0.003,
   0.0009,
   0.0004,
   0.0007,
   0.0004};
   grae = new TGraphAsymmErrors(6,Graph1_fx3008,Graph1_fy3008,Graph1_felx3008,Graph1_fehx3008,Graph1_fely3008,Graph1_fehy3008);
   grae->SetName("Graph1");
   grae->SetTitle("TGraphAsymmErrors for Data efficiencies");
   grae->SetFillColor(1);
   grae->SetMarkerStyle(9);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph3008 = new TH1F("Graph_Graph3008","TGraphAsymmErrors for Data efficiencies",100,0,87.3);
   Graph_Graph3008->SetMinimum(0.96416);
   Graph_Graph3008->SetMaximum(0.99824);
   Graph_Graph3008->SetDirectory(0);
   Graph_Graph3008->SetStats(0);
   Graph_Graph3008->SetFillStyle(0);
   Graph_Graph3008->SetLineStyle(0);
   Graph_Graph3008->SetMarkerStyle(20);
   Graph_Graph3008->GetXaxis()->SetLabelFont(42);
   Graph_Graph3008->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph3008->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3008->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3008->GetXaxis()->SetTitleFont(42);
   Graph_Graph3008->GetYaxis()->SetLabelFont(42);
   Graph_Graph3008->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3008->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3008->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3008->GetYaxis()->SetTitleOffset(0.85);
   Graph_Graph3008->GetYaxis()->SetTitleFont(42);
   Graph_Graph3008->GetZaxis()->SetLabelFont(42);
   Graph_Graph3008->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3008->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3008->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3008->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3008);
   
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
      tex = new TLatex(0.63,0.35,"0.80 < |#eta| < 1.48");
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
   
   Double_t Graph0_fx3009[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3009[6] = {
   1.0206,
   1.0075,
   0.9966,
   1,
   0.9993,
   0.9999};
   Double_t Graph0_felx3009[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3009[6] = {
   0.0195,
   0.0107,
   0.008,
   0.0011,
   0.0009,
   0.0008};
   Double_t Graph0_fehx3009[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3009[6] = {
   0.0195,
   0.0107,
   0.008,
   0.0011,
   0.0009,
   0.0008};
   grae = new TGraphAsymmErrors(6,Graph0_fx3009,Graph0_fy3009,Graph0_felx3009,Graph0_fehx3009,Graph0_fely3009,Graph0_fehy3009);
   grae->SetName("Graph0");
   grae->SetTitle("TGraphAsymmErrors for scale factors");

   ci = TColor::GetColor("#99ccff");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_Small TH1F3009 = new TH1F("Graph_Small TH1F3009","Small TH1F histogram",100,0,81);
   Graph_Small TH1F3009->SetMinimum(0.65);
   Graph_Small TH1F3009->SetMaximum(1.1);
   Graph_Small TH1F3009->SetFillStyle(0);
   Graph_Small TH1F3009->SetLineStyle(0);
   Graph_Small TH1F3009->SetMarkerStyle(20);
   Graph_Small TH1F3009->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_Small TH1F3009->GetXaxis()->SetLabelFont(42);
   Graph_Small TH1F3009->GetXaxis()->SetLabelOffset(0.007);
   Graph_Small TH1F3009->GetXaxis()->SetLabelSize(0.08);
   Graph_Small TH1F3009->GetXaxis()->SetTitleSize(0.08);
   Graph_Small TH1F3009->GetXaxis()->SetTitleFont(42);
   Graph_Small TH1F3009->GetYaxis()->SetLabelFont(42);
   Graph_Small TH1F3009->GetYaxis()->SetLabelOffset(0.007);
   Graph_Small TH1F3009->GetYaxis()->SetLabelSize(0.08);
   Graph_Small TH1F3009->GetYaxis()->SetTitleSize(0.08);
   Graph_Small TH1F3009->GetYaxis()->SetTitleOffset(0.75);
   Graph_Small TH1F3009->GetYaxis()->SetTitleFont(42);
   Graph_Small TH1F3009->GetZaxis()->SetLabelFont(42);
   Graph_Small TH1F3009->GetZaxis()->SetLabelOffset(0.007);
   Graph_Small TH1F3009->GetZaxis()->SetLabelSize(0.05);
   Graph_Small TH1F3009->GetZaxis()->SetTitleSize(0.06);
   Graph_Small TH1F3009->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Small TH1F3009);
   
   grae->Draw("a2");
   
   Double_t Graph0_fx3010[6] = {
   8.5,
   15,
   25,
   35,
   45,
   65};
   Double_t Graph0_fy3010[6] = {
   1.0206,
   1.0075,
   0.9966,
   1,
   0.9993,
   0.9999};
   Double_t Graph0_felx3010[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fely3010[6] = {
   0.0195,
   0.0107,
   0.008,
   0.0011,
   0.0009,
   0.0008};
   Double_t Graph0_fehx3010[6] = {
   1.5,
   5,
   5,
   5,
   5,
   15};
   Double_t Graph0_fehy3010[6] = {
   0.0195,
   0.0107,
   0.008,
   0.0011,
   0.0009,
   0.0008};
   grae = new TGraphAsymmErrors(6,Graph0_fx3010,Graph0_fy3010,Graph0_felx3010,Graph0_fehx3010,Graph0_fely3010,Graph0_fehy3010);
   grae->SetName("Graph0");
   grae->SetTitle("TGraphAsymmErrors for scale factors");

   ci = TColor::GetColor("#99ccff");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#3399ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerSize(0.7);
   
   TH1F *Graph_Graph_Small TH1F30093010 = new TH1F("Graph_Graph_Small TH1F30093010","Small TH1F histogram",100,0,81);
   Graph_Graph_Small TH1F30093010->SetMinimum(0.65);
   Graph_Graph_Small TH1F30093010->SetMaximum(1.1);
   Graph_Graph_Small TH1F30093010->SetFillStyle(0);
   Graph_Graph_Small TH1F30093010->SetLineStyle(0);
   Graph_Graph_Small TH1F30093010->SetMarkerStyle(20);
   Graph_Graph_Small TH1F30093010->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_Graph_Small TH1F30093010->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Small TH1F30093010->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Small TH1F30093010->GetXaxis()->SetLabelSize(0.08);
   Graph_Graph_Small TH1F30093010->GetXaxis()->SetTitleSize(0.08);
   Graph_Graph_Small TH1F30093010->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Small TH1F30093010->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Small TH1F30093010->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Small TH1F30093010->GetYaxis()->SetLabelSize(0.08);
   Graph_Graph_Small TH1F30093010->GetYaxis()->SetTitleSize(0.08);
   Graph_Graph_Small TH1F30093010->GetYaxis()->SetTitleOffset(0.75);
   Graph_Graph_Small TH1F30093010->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Small TH1F30093010->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Small TH1F30093010->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Small TH1F30093010->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Small TH1F30093010->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Small TH1F30093010->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Small TH1F30093010);
   
   grae->Draw("p");
   pad2->Modified();
   Canvas->cd();
   Canvas->Modified();
   Canvas->cd();
   Canvas->SetSelected(Canvas);
}
