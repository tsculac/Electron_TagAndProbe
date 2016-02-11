// run in shell with: root makeScaleFactorFile.C
#include <iostream>
#include <fstream>
#include <algorithm>
#include "TCanvas.h"
#include "sf_SIP_Cracks_76X_2015.h"

using namespace std;

void makeScaleFactorFile_Cracks()
{
	gROOT->SetBatch(kTRUE);
	gStyle->SetOptStat(0);
	
	TString Type = "SIP_Cracks";
	
	Int_t bineta;
	TString Period = "Moriond_2016";
	
	enum NameEfficiencyNumber_t {datamc = 0, datamc_error = 1};
	
//	TFile *outputFile = new TFile( "ScaleFactors_ID_2015.root", "RECREATE", "", 0 );
	TFile *outputFile = new TFile(Period + "/" + Type + ".root", "RECREATE", "", 0 );
	
	std::cout << "[INFO] Creating scale factors TH2F..." << endl;
	
	Float_t localPtBinEdges[] = { 7., 20., 30., 200. }; // Slices in pT
//	Float_t localPtBinEdges[] = { 7., 10., 20., 30., 40., 50., 200. }; // Slices in pT

	Int_t nbinspt = sizeof(localPtBinEdges)/sizeof(Float_t) - 1 ;
	
	Float_t localEtaBinEdges[] = { -2.5, 0., 2.5 }; // Slices in eta
//	Float_t localEtaBinEdges[] = { -2.5, -2.0, -1.479, -0.8, 0., 0.8, 1.479, 2.0, 2.5 }; // Slices in eta

	Int_t nbinseta = sizeof(localEtaBinEdges)/sizeof(Float_t) - 1;
	
	std::cout << "Bins pt / Eta : "<< nbinspt <<" / " << nbinseta << std::endl;
		
//	TH2F *hScaleFactors = new TH2F( "hScaleFactors_ID", "; p_{T}; #eta", nbinspt, localPtBinEdges, nbinseta, localEtaBinEdges );
	TH2F *hScaleFactors = new TH2F( "hScaleFactors_" + Type, "; p_{T}; #eta", nbinspt, localPtBinEdges, nbinseta, localEtaBinEdges );

//	TH2F *hScaleFactors_Reco = new TH2F( "hScaleFactors_Reco", "Scale factors for electron Reconstruction; p_{T}; #eta", nbinspt, localPtBinEdges, nbinseta, localEtaBinEdges );
	
				   
	for ( int ipt = 0; ipt < nbinspt; ipt++ )
	{
            cout << eff_num[0][ipt][datamc] << "   " << eff_num[0][ipt][datamc_error] << endl;
//			cout << sf_reco[bineta][ipt][datamc] << "   " << sf_reco[bineta][ipt][datamc_error] << endl;
			
			hScaleFactors->SetBinContent( ipt + 1, 0 + 1, eff_num[0][ipt][datamc] );
			hScaleFactors->SetBinError( ipt + 1, 0 + 1, eff_num[0][ipt][datamc_error] );
            hScaleFactors->SetBinContent( ipt + 1, 1 + 1, eff_num[0][ipt][datamc] );
            hScaleFactors->SetBinError( ipt + 1, 1 + 1, eff_num[0][ipt][datamc_error] );
			
			// For 2012 Reconstruction
//			hScaleFactors_Reco->SetBinContent( ipt + 1, ieta + 1, sf_reco[ipt][bineta][datamc] );
//			hScaleFactors_Reco->SetBinError( ipt + 1, ieta + 1, sf_reco[ipt][bineta][datamc_error] );
//			hScaleFactors_Reco->SetBinContent( ipt + 1, ieta + 1, sf_reco[bineta][ipt][datamc] );
//			hScaleFactors_Reco->SetBinError( ipt + 1, ieta + 1, sf_reco[bineta][ipt][datamc_error] );
		
	}
	
	TCanvas *c = new TCanvas( "canvas", "canvas", 800, 600 );
	   c->SetRightMargin(0.13);
		hScaleFactors->Draw("COLZ");
	c->SaveAs(Period + "/" + Type + ".pdf");
	c->SaveAs(Period + "/" + Type + ".png");
	c->SaveAs(Period + "/" + Type + ".eps");
//	c->SaveAs(Period + "/" + Type + ".root");
	c->SaveAs(Period + "/" + Type + ".C");

	
//	TCanvas *cReco = new TCanvas( "cReco", "cReco", 800, 600 );
//		cReco->SetRightMargin(0.13);
//		hScaleFactors_Reco->Draw("COLZ");
//		cReco->SaveAs("Plots_2D/" + Period + "/RecoSF.pdf");
//		cReco->SaveAs("Plots_2D/" + Period + "/RecoSF.png");
//		cReco->SaveAs("Plots_2D/" + Period + "/RecoSF.eps");
//		cReco->SaveAs("Plots_2D/" + Period + "/RecoSF.root");
//		cReco->SaveAs("Plots_2D/" + Period + "/RecoSF.C");

	
	hScaleFactors->Write();
//	hScaleFactors_Reco->Write();
	
	outputFile->Close();	
} // end plot_eff