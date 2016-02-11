// C++
#include <iostream>
#include <fstream>
#include <string>

// ROOT
#include "TApplication.h"
#include <TROOT.h>
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"

// My own files
#include "plotter.hpp"

using namespace std;

int main( int argc, char *argv[] )
{

	gROOT->ProcessLine(".L ./tdrstyle.C++");
	gROOT->ProcessLine("setTDRStyle();");
	
	bool EBEEonly = false; //true for crack probe plots
	bool combination = false;
//	TString cut = "ID";
 	TString cut = "IdIsoSip";
//	TString cut = "Sip";
	TString pTvtxN = "pT"; //pT2 for crack probe plots

   plotter *p = new plotter( EBEEonly, combination, cut, pTvtxN );
   
	// Options are ".pdf", ".png", ".eps", ".ps", ".C", ".root" or "all"
//	p->plotScaleFactors( "all" );
//	p->plotEff( "all" );
//	p->plotEffOnOneCanvas( "all" );
//	p->plotScaleFactorsAndEff( "all" );
	p->plotEffAndSmallSF("all");
//	p->readInput(3);

}
