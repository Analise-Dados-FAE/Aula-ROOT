#define Analyze_cxx
#include "Analyze.h"
#include <TH2.h>
#include <TStyle.h>

//**********Definition section**********
TH1* chi2Hist = NULL;

void Analyze::Begin(TTree * /*tree*/)
{
   TString option = GetOption();

   //**********Initialization section**********
   chi2Hist = new TH1D("chi2", "Histogram of Chi2", 100, 0, 20);
   chi2Hist->GetXaxis()->SetTitle("chi2");
   chi2Hist->GetYaxis()->SetTitle("number of events");
}

void Analyze::SlaveBegin(TTree * /*tree*/){}

Bool_t Analyze::Process(Long64_t entry)
{
   // Don’t delete this line! Without it the program will crash
   fReader.SetLocalEntry(entry);

   //**********Loop section**********
   GetEntry(entry);
   chi2Hist->Fill(*chi2);

   return kTRUE;
}

void Analyze::SlaveTerminate(){}

void Analyze::Terminate()
{
    //**********Wrap-up section**********
    chi2Hist->Draw();
}