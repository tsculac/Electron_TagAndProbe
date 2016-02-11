#ifndef plotter_h
#define plotter_h

// C++
#include <iostream>
#include <fstream>

// My include
#include "readInput.hpp"

// ROOT
#include "TApplication.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TROOT.h"

using namespace std;

class plotter
{

public:
	plotter( bool, bool, TString, TString );
	~plotter();

	void plotEff( string );
	void plotEffOnOneCanvas ( string );
	void plotScaleFactors( string );
	void plotScaleFactorsAndEff( string );
	void plotEffAndSmallSF( string );
	
   void setExtension( string );
   void setOutFilexPrefix( string );
   void setUpCanvas( );
   void setUpTH1F( TString, TString, float );
	void setUpSmallSF_TH1F( TString, TString, float );
	void setUpTPad( TString, TString, float );
	
   TLatex *getSetTexEtaRange( TString );
//	TLatex *getTexCMS();

private:

   vector<TString> files1_, files2_, files3_, outFiles_, etaRegionLegend_;

	int numOfPoints_, max_;
	bool EBEEonly_, combination_;

   double x_[7], xRange_[7];
	double *eff1_, *eff_error1_, *eff2_, *eff_error2_, *sf_, *sf_error_;
   
   TString extension_, outFilesPrefix_, yAxisLabel_, yAxisLabelSmallSF_TH1F_, xAxisLabel_, cut_, pTvtxN_;
   TString inputDataPath_, outPlotsDir_;
   
   TLegend *legend_;
	TPaveText *pt_;
   TLatex *texEtaRange_, *texLumi_, *texCMS_, *texZee_;
   TH1F *th1f, *smallSFth1f;
   TCanvas *canvas;
	readInput input;
};
#endif