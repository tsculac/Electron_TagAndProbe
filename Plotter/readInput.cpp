#include "readInput.hpp"

using namespace std;

// Constructor
// ===============
readInput::readInput()
{
} // end constructor
// ===============



// Destructor
// =======================
readInput::~readInput() {}
// =======================



// ================================================================
void readInput::readDataEff( TString inputDataPath, TString inputFileName )
{
	ifstream inputFileData;
	inputFileData.open( inputDataPath + inputFileName );

   int i = 0;
   
   if ( inputFileData.is_open() )
   {
		while ( !inputFileData.eof() )
		{
			inputFileData >> eff1_[i];
			inputFileData >> eff_error1_[i];
			
			cout << "data eff.       = " << eff1_[i] << endl << "data eff. error = " << eff_error1_[i] << endl;
			
			i++;
		}
   }
	else
	{
		cout << "Skip reading Data input file!!!" << endl;
	}
	inputFileData.close();
} // end ReadData
// ================================================================



// ==============================================================
void readInput::readMCEff( TString inputDataPath, TString inputFileName )
{
	ifstream inputFileMC;
	inputFileMC.open( inputDataPath + inputFileName );
	
   int i = 0;
   cout << endl;
	
	if ( inputFileMC.is_open() )
	{
		while ( !inputFileMC.eof() )
		{
			inputFileMC >> eff2_[i];
			inputFileMC >> eff_error2_[i];
			
			cout << "MC eff.       = " << eff2_[i] << endl << "MC eff. error = " << eff_error2_[i] << endl;
			
			i++;
		}
	}
	else
	{
		cout << "Skip reading MC input file!!!" << endl;
	}
	inputFileMC.close();
} // end ReadMC
// ==============================================================



// ===================================================================
void readInput::readSF( TString inputDataPath, TString inputFileName )
{
	ifstream inputFileSF;
	inputFileSF.open( inputDataPath + inputFileName );
	
   int i = 0;
   cout << endl;
	
	if ( inputFileSF.is_open() )
	{
		while ( !inputFileSF.eof() )
		{
			inputFileSF >> sf_[i];
			inputFileSF >> sf_error_[i];
			
			cout << "Scale factor       = " << sf_[i] << endl << "Scale factor error = " << sf_error_[i] << endl;
			
			i++;
		}
	}
	else
	{
		cout << "Skip reading SF input file!!!" << endl;
	}
	inputFileSF.close();
} // end ReadSF
// ===================================================================



// =============================================
pair<double *, double *> readInput::getDataEff()
{
	pair<double *, double *> data;

	data = make_pair ( eff1_, eff_error1_ );
	
	return data;
}
// =============================================



// ===========================================
pair<double *, double *> readInput::getMCEff()
{
	pair<double *, double *> MC;
	
	MC = make_pair ( eff2_, eff_error2_ );
	
	return MC;
}
// ===========================================



// ========================================
pair<double *, double *> readInput::getSF()
{
	pair<double *, double *> SF;
	
	SF = make_pair ( sf_, sf_error_ );
	
	return SF;
}
// ========================================