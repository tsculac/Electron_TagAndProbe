#include "plotter.hpp"

using namespace std;

// Constructor
// ===============
plotter::plotter( bool EBEEonly, bool combination, TString cut, TString pTvtxN )
{
//	gROOT->SetStyle("Plain");
	
	EBEEonly_ = EBEEonly;
	combination_ = combination;
	cut_ = cut;
	pTvtxN_ = pTvtxN;

	if ( combination_ )
	{
		inputDataPath_ = "inputData/Summer_2013/" + cut_ + "/Combination/2012ABCD/" + pTvtxN + "/";
//		outPlotsDir_ = "Plots/Summer_2013/" + cut_ + "/Combination/2012ABCD/" + pTvtxN + "/";
		outPlotsDir_ = "Plots/Summer_2013/4egammaLegacy/";
	}
	else
	{
      inputDataPath_ = "inputData/Moriond_2016/" + cut_ + "/2015/" + pTvtxN + "/";
//		inputDataPath_ = "inputData/Summer_2013/" + cut_ + "/2012ABCD/" + pTvtxN + "/";
//		outPlotsDir_ = "Plots/Summer_2013/" + cut_ + "/2012ABCD/" + pTvtxN + "/";
		outPlotsDir_ = "Plots/Moriond_2016/";
	}
	
		
	if ( EBEEonly_ )
	{
		max_ = 2;
	}
	else
	{
		max_ = 5;
	}


	if ( pTvtxN_ == "pT" )
	{
		numOfPoints_ = 7;
		
		x_[0] = 8.5;
		x_[1] = 12.5;
		x_[2] = 17.5;
		x_[3] = 25;
		x_[4] = 35;
		x_[5] = 45;
		x_[6] = 65;
		
		xRange_[0] = 1.5;
		xRange_[1] = 2.5;
		xRange_[2] = 2.5;
		xRange_[3] = 5;
		xRange_[4] = 5;
		xRange_[5] = 5;
		xRange_[6] = 15;
	}
	else
	{
		numOfPoints_ = 6;

		x_[0] = 3;
		x_[1] = 7.5;
		x_[2] = 12.5;
		x_[3] = 17.5;
		x_[4] = 25;
		x_[5] = 40;

		xRange_[0] = 2;
		xRange_[1] = 2.5;
		xRange_[2] = 2.5;
		xRange_[3] = 2.5;
		xRange_[4] = 5;
		xRange_[5] = 10;
	}

	if ( EBEEonly_ )
	{
		files1_.push_back("eff_DATA_EB.txt");
      files1_.push_back("eff_DATA_EE.txt");

		files2_.push_back("eff_MC_EB.txt");
		files2_.push_back("eff_MC_EE.txt");

		files3_.push_back("SF_EB.txt");
		files3_.push_back("SF_EE.txt");

		etaRegionLegend_.push_back("Probe in barrel: 0 < |#eta_{probe}| < 1.479");
		etaRegionLegend_.push_back("Probe in endcap: 1.479 < |#eta_{probe}| < 2.5");
	}
	else
	{
		files1_.push_back("eff_DATA_EB1.txt");
		files1_.push_back("eff_DATA_EB2.txt");
		files1_.push_back("eff_DATA_EE1.txt");
		files1_.push_back("eff_DATA_EE2.txt");
		files1_.push_back("eff_DATA_TR.txt" );

		files2_.push_back("eff_MC_EB1.txt");
		files2_.push_back("eff_MC_EB2.txt");
		files2_.push_back("eff_MC_EE1.txt");
		files2_.push_back("eff_MC_EE2.txt");
		files2_.push_back("eff_MC_TR.txt" );

		files3_.push_back("SF_EB1.txt");
		files3_.push_back("SF_EB2.txt");
		files3_.push_back("SF_EE1.txt");
		files3_.push_back("SF_EE2.txt");
		files3_.push_back("SF_TR.txt" );
		
		etaRegionLegend_.push_back("0.00 < |#eta| < 0.80");
		etaRegionLegend_.push_back("0.80 < |#eta| < 1.44");
		etaRegionLegend_.push_back("1.56 < |#eta| < 2.00");
		etaRegionLegend_.push_back("2.00 < |#eta| < 2.50");
		etaRegionLegend_.push_back("1.44 < |#eta| < 1.56");
	}
   
   legend_ = new TLegend(0.63, 0.2, 0.87, 0.33, NULL, "brNDC");
   legend_->SetBorderSize(0);
   legend_->SetTextSize(0.03);
   legend_->SetLineColor(1);
   legend_->SetLineStyle(1);
   legend_->SetLineWidth(1);
   legend_->SetFillColor(0);
   legend_->SetFillStyle(1001);

//	texCMS_ = new TLatex(0.12, 0.925, "CMS Preliminary" );
//	texCMS_->SetNDC();
//	texCMS_->SetTextFont(62);
//	texCMS_->SetTextSize(0.03);
//	texCMS_->SetLineWidth(2);

//	texLumi_ = new TLatex(0.665, 0.925, "#sqrt{s} = 8 TeV, L = 19.7 fb^{-1}" );
//	texLumi_->SetNDC();
//	texLumi_->SetTextFont(62);
//	texLumi_->SetTextSize(0.03);
//	texLumi_->SetLineWidth(2);
	
	texZee_ = new TLatex( .67, .40, "Z #rightarrow e^{+} e^{-}");
	texZee_->SetNDC();
	texZee_->SetTextFont(62);
	texZee_->SetTextSize(0.03);
	
	pt_ = new TPaveText( 0.14, 0.94, 0.89, 0.99, "brNDC" );
	pt_->SetBorderSize(0);
	pt_->SetTextAlign(12);
	pt_->SetFillStyle(0);
	pt_->SetTextFont(62);
	pt_->SetTextSize(0.03);
	TText *text = pt_->AddText( 0.01, 0.3, "CMS" );
	text = pt_->AddText( 0.7, 0.3, "#sqrt{s} = 8 TeV, L = 19.7 fb^{-1}" );
   
} // end constructor
// ===============



// Destructor
// ===================
plotter::~plotter()
{



}
// ===================



// =======================================================================
void plotter::setExtension( string extension ) { extension_ = extension; }
// =======================================================================



// =====================================================
void plotter::setOutFilexPrefix( string outFilesPrefix )
{
   outFilesPrefix_ = outFilesPrefix;

	if ( EBEEonly_ )
	{
		outFiles_.push_back(outFilesPrefix_ + "_DATA_MC_EB_" + pTvtxN_);
		outFiles_.push_back(outFilesPrefix_ + "_DATA_MC_EE_" + pTvtxN_);
	}
	else
	{
		outFiles_.push_back(outFilesPrefix_ + "_DATA_MC_EB1_" + pTvtxN_);
		outFiles_.push_back(outFilesPrefix_ + "_DATA_MC_EB2_" + pTvtxN_);
		outFiles_.push_back(outFilesPrefix_ + "_DATA_MC_EE1_" + pTvtxN_);
		outFiles_.push_back(outFilesPrefix_ + "_DATA_MC_EE2_" + pTvtxN_);
		outFiles_.push_back(outFilesPrefix_ + "_DATA_MC_TR_"  + pTvtxN_);
	}
} // end setOutFilexPrefix
// =====================================================



// ====================================================
TLatex *plotter::getSetTexEtaRange( TString etaRegion )
{
   texEtaRange_ = new TLatex( 0.63, 0.35, etaRegion );
   texEtaRange_->SetNDC();
   texEtaRange_->SetTextFont(62);
   texEtaRange_->SetTextSize(0.03);
   texEtaRange_->SetLineWidth(2);
   
   return texEtaRange_;
   
} // end getSetTexEtaRange function
// ====================================================



// =========================
void plotter::setUpCanvas( )
{
   canvas = new TCanvas( "Canvas", "Canvas", 725, 725 );
//	gStyle->SetOptTitle(0);
//	canvas->SetFillColor(0);
//	canvas->SetBorderMode(0);
//	canvas->SetBorderSize(2);
//	canvas->SetGridx(0);
//	canvas->SetGridy(1);
//	canvas->SetLineStyle(3);
//	canvas->SetTickx(1);
//	canvas->SetTicky(1);
//	canvas->SetLeftMargin(0.12);
//	canvas->SetRightMargin(0.12);
//	canvas->SetBottomMargin(0.13);
//	canvas->SetFrameFillStyle(0);
//	canvas->SetFrameLineWidth(2);
//	canvas->SetFrameBorderMode(0);
//	canvas->SetFrameFillStyle(0);
//	canvas->SetFrameLineWidth(2);
//	canvas->SetFrameBorderMode(0);

} // end setUpCanvas function
// ==========================



// ==========================================================================
void plotter::setUpTH1F( TString yAxisLabel, TString xAxisLabel, float yMax )
{
   th1f = new TH1F( "TH1F", "TH1F histogram", 100, 0, 51 );
   th1f->SetMinimum(0);
   th1f->SetMaximum(yMax);
//	th1f->SetStats(0);
	th1f->GetXaxis()->SetLabelSize(0);
//	th1f->GetXaxis()->SetTitle( xAxisLabel );
//	th1f->GetXaxis()->SetTitleSize(0.04);
//	th1f->GetXaxis()->SetTitleOffset(1.1);
//	th1f->GetXaxis()->SetTitleFont(42);
   th1f->GetYaxis()->SetTitle( yAxisLabel );
//	th1f->GetYaxis()->SetTitleOffset(1.1);
//	th1f->GetYaxis()->SetTitleSize(0.04);
//	th1f->GetYaxis()->SetTitleFont(42);

} // end setUpTH1F function
// ==========================================================================



// ==================================================================================
void plotter::setUpSmallSF_TH1F( TString yAxisLabel, TString xAxisLabel, float yMax )
{
   smallSFth1f = new TH1F( "Small TH1F", "Small TH1F histogram", 100, 0, 51 );
   smallSFth1f->SetMinimum(.65);
   smallSFth1f->SetMaximum(yMax);
//	smallSFth1f->SetStats(0);
	smallSFth1f->SetLabelSize(0.08, "XY");
   smallSFth1f->GetXaxis()->SetTitle( xAxisLabel );
	smallSFth1f->SetTitleSize(0.08, "XY");
//	smallSFth1f->GetXaxis()->SetTitleOffset(1.1);
//	smallSFth1f->GetXaxis()->SetTitleFont(42);
   smallSFth1f->GetYaxis()->SetTitle( yAxisLabel );
	smallSFth1f->GetYaxis()->SetTitleOffset(.75);
//	smallSFth1f->GetYaxis()->SetTitleSize(0.04);
//	smallSFth1f->GetYaxis()->SetTitleFont(42);
	
} // end setUpSmallSF_TH1F function
// ==================================================================================



// ==========================================================================
void plotter::setUpTPad( TString padName, TString xAxisLabel, float yMax )
{
} // end setUpTH1F function
// ==========================================================================


//// =========================
//TLatex *plotter::getTexCMS()
//{
//   
//   return texCMS_;
//   
//} // end getTexCMS function
//// =========================



// ======================================
void plotter::plotEff( string extension )
{
   setExtension( extension );
   setOutFilexPrefix( "eff" );

	if ( cut_ == "ID" )
		yAxisLabel_ = "ID efficiency";
	else if ( cut_ == "IsoSip" )
		yAxisLabel_ = "ISO+SIP efficiency";
	else if ( cut_ == "IdIsoSip" )
		yAxisLabel_ = "Efficiency";
	else
		yAxisLabel_ = "Efficiency";

	if ( pTvtxN_ == "pT" )
		xAxisLabel_ = "p_{T} [GeV]";
	else
		xAxisLabel_ = "# vertices";
		

   for( int j = 0; j < max_-1; j++)
	{
		// Read Data and MC input
      input.readDataEff( inputDataPath_, files1_.at(j) );
		eff1_ = input.getDataEff().first;
		eff_error1_ = input.getDataEff().second;
		
		input.readMCEff( inputDataPath_, files2_.at(j) );
		eff2_ = input.getMCEff().first;
		eff_error2_ = input.getMCEff().second;
		
		// Set histogram and canvas
		setUpTH1F( yAxisLabel_, xAxisLabel_, 1.05 );
      setUpCanvas();
		
      TGraphAsymmErrors *tgaeEffData = new TGraphAsymmErrors( numOfPoints_, x_, eff1_, xRange_, xRange_, eff_error1_, eff_error1_);
      tgaeEffData->SetTitle("TGraphAsymmErrors for Data efficiencies");
      tgaeEffData->SetMarkerSize(1);
      tgaeEffData->SetMarkerStyle(9);
		tgaeEffData->SetMarkerColor(kBlack);
//		tgaeEffData->SetFillColor(kGray);
      tgaeEffData->SetLineColor(kBlack);
//    tgaeEffData->SetFillStyle(1001);
		
		TGraphAsymmErrors *tgaeEffMC = new TGraphAsymmErrors( numOfPoints_, x_, eff2_, xRange_, xRange_, eff_error2_, eff_error2_);
      tgaeEffMC->SetTitle("TGraphAsymmErrors for MC efficiencies");
		tgaeEffMC->SetFillColor(kAzure+1);
      tgaeEffMC->SetLineColor(kAzure+1);
		tgaeEffMC->SetMarkerColor(kAzure+1);
		tgaeEffMC->SetLineWidth(1);
		tgaeEffMC->SetMarkerSize(1);
		tgaeEffMC->SetMarkerStyle(1);
				  
		tgaeEffMC->SetHistogram(th1f);
		
      legend_->AddEntry(tgaeEffData,"Data","p");
		legend_->AddEntry(tgaeEffMC,"Simulation","f");
      
		tgaeEffMC->Draw("a2");
		tgaeEffMC->Draw("p");
		tgaeEffData->Draw("p");
		legend_->Draw();
		pt_->Draw();
		texZee_->Draw();
//		texCMS_->Draw();
//		texLumi_->Draw();
		
      getSetTexEtaRange( etaRegionLegend_.at(j) )->Draw();
		
      
      cout << "--------------------------------------------------------------------------------" << endl;
      if ( extension_ == "all" )
      {
         canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".pdf");
         canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".png");
         canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".eps");
//			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".ps");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".C");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".root");
      }
      else
         canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+extension_);
      cout << "--------------------------------------------------------------------------------" << endl;
      
//		getSetTexEtaRange( etaRegionLegend_.at(j) )->Delete();
      canvas->Destructor();
      th1f->Delete();
      legend_->Clear();
      
   } // end for j

// clear out files vector
   outFiles_.clear();

} // end plotEff
// ======================================



// =================================================
void plotter::plotEffOnOneCanvas( string extension )
{
	yAxisLabel_ = "Efficiency";
	xAxisLabel_ = "Electron p_{T} (GeV)";
	
	x_[6] = 125;
	xRange_[6] = 75;
	
	setExtension( extension );
   setOutFilexPrefix( "eff" );
	setUpCanvas();
	
	TMultiGraph *mg = new TMultiGraph();
	
   for( int j = 0; j < max_-1; j++)
	{
		// Read Data input
      input.readDataEff( inputDataPath_, files1_.at(j) );
		eff1_ = input.getDataEff().first;
		eff_error1_ = input.getDataEff().second;
		
      TGraphAsymmErrors *tgaeEffData = new TGraphAsymmErrors( numOfPoints_, x_, eff1_, xRange_, xRange_, eff_error1_, eff_error1_);
      tgaeEffData->SetTitle("TGraphAsymmErrors for Data efficiencies");
      tgaeEffData->SetMarkerSize(1);
      if (j == 0) tgaeEffData->SetMarkerStyle(20);
		else if (j == 1) tgaeEffData->SetMarkerStyle(24);
      else if (j == 2) tgaeEffData->SetMarkerStyle(21);
      else tgaeEffData->SetMarkerStyle(25);
		
		tgaeEffData->SetMarkerColor(kAzure - 2*j);
      tgaeEffData->SetLineColor(kAzure - 2*j);
		
		legend_->SetX1(.60);
		legend_->SetX2(.87);
		legend_->AddEntry(tgaeEffData, etaRegionLegend_.at(j), "p");
		
		mg->Add(tgaeEffData,"p");
   } // end for j
	
	canvas->SetLogx();
	
	mg->SetMinimum(0.4);
	mg->SetMaximum(1);
	mg->Draw("A");
	mg->GetXaxis()->SetMoreLogLabels();
	mg->GetXaxis()->SetTitle( xAxisLabel_ );
   mg->GetYaxis()->SetTitle( yAxisLabel_ );
	mg->GetXaxis()->SetTitleOffset(1.3);
	mg->GetYaxis()->SetTitleOffset(1.25);
	
	legend_->Draw();
	pt_->Draw();
	texZee_->Draw();
//	texCMS_->Draw();
//	texLumi_->Draw();
	
	cout << "--------------------------------------------------------------------------------" << endl;
	TString fileName = "eff_04";
	if ( extension_ == "all" )
	{
		canvas->SaveAs( outPlotsDir_ + fileName + ".pdf" );
		canvas->SaveAs( outPlotsDir_ + fileName + ".png" );
		canvas->SaveAs( outPlotsDir_ + fileName + ".eps" );
//		canvas->SaveAs( outPlotsDir_ + fileName + ".ps"  );
		canvas->SaveAs( outPlotsDir_ + fileName + ".C"   );
		canvas->SaveAs( outPlotsDir_ + fileName + ".root");
	}
	else
		canvas->SaveAs( outPlotsDir_ + fileName + extension_ );
	cout << "--------------------------------------------------------------------------------" << endl;
	
	canvas->Destructor();
	legend_->Clear();
	
	// Clear out files vector
   outFiles_.clear();
	
} // end plotEffOnOneCanvas
// ======================================



// ===============================================
void plotter::plotScaleFactors( string extension )
{
   setExtension( extension );
   setOutFilexPrefix( "sf" );

	if ( pTvtxN_ == "pT" )
		xAxisLabel_ = "p_{T} [GeV]";
	else
		xAxisLabel_ = "# vertices";


   for( int j = 0; j < max_-1; j++)
	{
      // Read Data and MC input
      input.readSF( inputDataPath_, files3_.at(j) );
		sf_ = input.getSF().first;
		sf_error_ = input.getSF().second;
		
		// Set histogram and canvas
		setUpCanvas();
      setUpTH1F( "Scale Factor", xAxisLabel_, 1.15 );
   
      TGraphAsymmErrors *tgaeSF = new TGraphAsymmErrors( numOfPoints_, x_, sf_, xRange_, xRange_, sf_error_, sf_error_);
      tgaeSF->SetTitle("TGraphAsymmErrors for scale factors");
      tgaeSF->SetFillColor(kAzure-9);
		tgaeSF->SetLineColor(kAzure+1);
		tgaeSF->SetFillStyle(1001);
		tgaeSF->SetLineWidth(1);
		tgaeSF->SetLineStyle(1);
      tgaeSF->SetMarkerSize(1);
      tgaeSF->SetMarkerStyle(1);
		tgaeSF->SetMarkerColor(kAzure+1);
      
      tgaeSF->SetHistogram(th1f);
      
      legend_->AddEntry( tgaeSF, "Scale factor", "f" );
      
      tgaeSF->Draw("a2");
      tgaeSF->Draw("p");
		legend_->Draw();
      texCMS_->Draw();
		texLumi_->Draw();
      getSetTexEtaRange( etaRegionLegend_.at(j) )->Draw();
   
      cout << "--------------------------------------------------------------------------------" << endl;
      if ( extension_ == "all" )
      {
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".pdf");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".png");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".eps");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".ps");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".C");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".root");
      }
      else
         canvas->Print(outPlotsDir_+outFiles_.at(j)+extension_);
      cout << "--------------------------------------------------------------------------------" << endl;
   
//		getSetTexEtaRange( etaRegionLegend_.at(j) )->Delete();
      canvas->Destructor();
      th1f->Delete();
      legend_->Clear();
      
   } // end for j
   
// clear out files vector
   outFiles_.clear();
   
} // end plotScaleFactors
// ===============================================



// =====================================================
void plotter::plotScaleFactorsAndEff( string extension )
{
   setExtension( extension );
   setOutFilexPrefix( "eff_and_sf" );

	if ( pTvtxN_ == "pT" )
		xAxisLabel_ = "p_{T} [GeV]";
	else
		xAxisLabel_ = "vtxN";
		
   
   for( int j = 0; j < max_-1; j++)
	{
		// Set histogram and canvas
		setUpCanvas();
      setUpTH1F( "RECO+ID+ISO+SIP eff. and s.f.", xAxisLabel_, 1.5 );
      
		// Read Data and MC input
      input.readDataEff( inputDataPath_, files1_.at(j) );
		eff1_ = input.getDataEff().first;
		eff_error1_ = input.getDataEff().second;
		
		input.readMCEff( inputDataPath_, files2_.at(j) );
		eff2_ = input.getMCEff().first;
		eff_error2_ = input.getMCEff().second;
		
		input.readSF( inputDataPath_, files3_.at(j) );
		sf_ = input.getSF().first;
		sf_error_ = input.getSF().second;
		
		
      TGraphAsymmErrors *tgaeEffData = new TGraphAsymmErrors( numOfPoints_, x_, eff1_, xRange_, xRange_, eff_error1_, eff_error1_);
      tgaeEffData->SetTitle("TGraphAsymmErrors for Data efficiencies");
      tgaeEffData->SetMarkerSize(1);
      tgaeEffData->SetMarkerStyle(9);
		tgaeEffData->SetMarkerColor(kBlack);
      
      TGraphAsymmErrors *tgaeEffMC = new TGraphAsymmErrors( numOfPoints_, x_, eff2_, xRange_, xRange_, eff_error2_, eff_error2_);
      tgaeEffMC->SetTitle("TGraphAsymmErrors for MC efficiencies");
      tgaeEffMC->SetMarkerSize(1);
      tgaeEffMC->SetMarkerStyle(1);
		tgaeEffMC->SetMarkerColor(kAzure+1);
      tgaeEffMC->SetLineColor(kAzure+1);
		tgaeEffMC->SetFillColor(kAzure+1);
      
      TGraphAsymmErrors *tgaeSF = new TGraphAsymmErrors( numOfPoints_, x_, sf_, xRange_, xRange_, sf_error_, sf_error_);
      tgaeSF->SetTitle("TGraphAsymmErrors for scale factors");
      tgaeSF->SetFillColor(kAzure-9);
      tgaeSF->SetLineColor(kAzure-9);
      tgaeSF->SetFillStyle(1001);
      tgaeSF->SetMarkerSize(2);
      tgaeSF->SetMarkerStyle(7);
		tgaeSF->SetMarkerColor(1);
      
      tgaeSF->SetHistogram(th1f);
      
      legend_->AddEntry(tgaeEffData,"Data","p");
      legend_->AddEntry(tgaeEffMC,"Simulation","p");
      legend_->AddEntry(tgaeSF,"Scale factor","f");
      
      tgaeSF->Draw("a2");
      tgaeEffMC->Draw("p");
      tgaeEffData->Draw("p");
		legend_->Draw();
      texCMS_->Draw();
		texLumi_->Draw();
      getSetTexEtaRange( etaRegionLegend_.at(j) )->Draw();
      
      cout << "--------------------------------------------------------------------------------" << endl;
      if ( extension_ == "all" )
      {
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".pdf");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".png");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".eps");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".ps");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".C");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".root");
      }
      else
         canvas->Print(outPlotsDir_+outFiles_.at(j)+extension_);
      cout << "--------------------------------------------------------------------------------" << endl;
      
      //      getSetTexEtaRange( etaRegionLegend_.at(j) )->Delete();
      canvas->Destructor();
      th1f->Delete();
      legend_->Clear();
      
   } // end for j
   
   // clear out files vector
   outFiles_.clear();

} // end plotScaleFactorsAndEff
// =====================================================



// ================================================
void plotter::plotEffAndSmallSF( string extension )
{
   setExtension( extension );
   setOutFilexPrefix( "effAndSmallSF" );
	
	if ( cut_ == "ID" )
		yAxisLabel_ = "ID efficiency";
	else if ( cut_ == "IsoSip" )
		yAxisLabel_ = "ISO+SIP efficiency";
	else if ( cut_ == "IdIsoSip" )
	{
		yAxisLabel_ = "Efficiency";
		yAxisLabelSmallSF_TH1F_ = "Scale Factor";
	}
	else
	{
		yAxisLabel_ = "Efficiency";
		yAxisLabelSmallSF_TH1F_ = "Scale Factor";
	}
		
	if ( pTvtxN_ == "pT" )
		xAxisLabel_ = "p_{T} [GeV]";
	else
		xAxisLabel_ = "# vertices";
	
	
   for( int j = 0; j < max_-1; j++)
	{
		// Read Data and MC input
      input.readDataEff( inputDataPath_, files1_.at(j) );
		eff1_ = input.getDataEff().first;
		eff_error1_ = input.getDataEff().second;
		
		input.readMCEff( inputDataPath_, files2_.at(j) );
		eff2_ = input.getMCEff().first;
		eff_error2_ = input.getMCEff().second;
		
		input.readSF( inputDataPath_, files3_.at(j) );
		sf_ = input.getSF().first;
		sf_error_ = input.getSF().second;
		
		// Set histogram and canvas
		setUpTH1F( yAxisLabel_, xAxisLabel_, 1.05 );
		setUpSmallSF_TH1F(yAxisLabelSmallSF_TH1F_, xAxisLabel_, 1.1);
      setUpCanvas();
		canvas->Range(0, 0, 1, 1);
		
		gStyle->SetGridStyle(3);

		
		TPad *pad1 = new TPad("pad1", "pad1", 0.01, 0.3, 0.99, 0.99);
		pad1->Draw();
//		pad1->Range(-3.947368,0.743,3.947368,1.093);
		pad1->SetGridx();
		pad1->SetGridy();
		pad1->SetLeftMargin(0.14);
		pad1->SetRightMargin(0.12);
		pad1->SetTopMargin(0.1);
		pad1->SetBottomMargin(0.03);
		
		TPad *pad2 = new TPad("pad2", "pad2", 0.01, 0.01, 0.99, 0.3);
		pad2->Draw();
		pad2->SetGridx();
		pad2->SetGridy();
//		pad2->Range(-3.947368,0.8305556,3.947368,1.108333);
		pad2->SetLeftMargin(0.14);
		pad2->SetRightMargin(0.12);
		pad2->SetTopMargin(0.04);
		pad2->SetBottomMargin(0.25);
		
		pad1->cd();
		TGraphAsymmErrors *tgaeEffData = new TGraphAsymmErrors( numOfPoints_, x_, eff1_, xRange_, xRange_, eff_error1_, eff_error1_);
      tgaeEffData->SetTitle("TGraphAsymmErrors for Data efficiencies");
      tgaeEffData->SetMarkerSize(0.7);
      tgaeEffData->SetMarkerStyle(9);
		tgaeEffData->SetMarkerColor(kBlack);
//		tgaeEffData->SetFillColor(kGray);
      tgaeEffData->SetLineColor(kBlack);
//    tgaeEffData->SetFillStyle(1001);
		
		TGraphAsymmErrors *tgaeEffMC = new TGraphAsymmErrors( numOfPoints_, x_, eff2_, xRange_, xRange_, eff_error2_, eff_error2_);
      tgaeEffMC->SetTitle("TGraphAsymmErrors for MC efficiencies");
		tgaeEffMC->SetFillColor(kAzure-9);
      tgaeEffMC->SetLineColor(kAzure+1);
		tgaeEffMC->SetMarkerColor(kAzure+1);
		tgaeEffMC->SetLineWidth(1);
		tgaeEffMC->SetMarkerSize(0.7);
		tgaeEffMC->SetMarkerStyle(22);
		
		tgaeEffMC->SetHistogram(th1f);
		
      legend_->AddEntry(tgaeEffData,"Data","p");
		legend_->AddEntry(tgaeEffMC,"Simulation","fp");
      
		tgaeEffMC->Draw("a2");
		tgaeEffMC->Draw("p");
		tgaeEffData->Draw("p");
		legend_->Draw();
		pt_->Draw();
		texZee_->Draw();
      getSetTexEtaRange( etaRegionLegend_.at(j) )->Draw();
		pad1->Modified();
		
		pad2->cd();
		TGraphAsymmErrors *tgaeSF = new TGraphAsymmErrors( numOfPoints_, x_, sf_, xRange_, xRange_, sf_error_, sf_error_);
      tgaeSF->SetTitle("TGraphAsymmErrors for scale factors");
      tgaeSF->SetFillColor(kAzure-9);
      tgaeSF->SetLineColor(kAzure+1);
		tgaeEffMC->SetMarkerColor(kAzure+1);
      tgaeSF->SetFillStyle(1001);
      tgaeSF->SetMarkerSize(0.7);
      tgaeSF->SetMarkerStyle(1);
		tgaeSF->SetMarkerColor(kAzure+1);
		tgaeSF->SetLineStyle(1);

		tgaeSF->SetHistogram(smallSFth1f);
		
		tgaeSF->Draw("a2");
		tgaeSF->Draw("p");
		pad2->Modified();

		
		
      
      cout << "--------------------------------------------------------------------------------" << endl;
      if ( extension_ == "all" )
      {
         canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".pdf");
         canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".png");
         canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".eps");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".C");
			canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+".root");
      }
      else
		canvas->SaveAs(outPlotsDir_+outFiles_.at(j)+extension_);
      cout << "--------------------------------------------------------------------------------" << endl;
      
		canvas->Destructor();
      th1f->Delete();
		smallSFth1f->Delete();
      legend_->Clear();
		
	} // end for j
	
	// clear out files vector
   outFiles_.clear();
	
} // end plotEff
// ======================================