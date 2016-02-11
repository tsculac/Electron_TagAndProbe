#ifndef readInput_h
#define readInput_h

// C++
#include <iostream>
#include <fstream>

// My include

// ROOT
#include "TString.h"

using namespace std;

class readInput
{

public:
	readInput();
	~readInput();

	void readDataEff( TString, TString );
	void readMCEff( TString, TString );
	void readSF( TString, TString );
   pair<double *, double *> getDataEff();
	pair<double *, double *> getMCEff();
	pair<double *, double *> getSF();

private:

	double eff1_[7], eff_error1_[7];
	double eff2_[7], eff_error2_[7];
   double sf_[7], sf_error_[7];
};
#endif