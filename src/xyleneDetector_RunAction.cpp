#include "xyleneDetector_RunAction.h"
#include "G4Run.hh"

xyleneDetector_RunAction::xyleneDetector_RunAction()  {
}

xyleneDetector_RunAction::~xyleneDetector_RunAction() {}

void xyleneDetector_RunAction::BeginOfRunAction(const G4Run*){
    G4AnalysisManager *analMan = G4AnalysisManager::Instance();
    analMan->OpenFile("output.root");
    analMan->CreateNtuple("fEnergyTree", "A simple tree for NaI Data");
    analMan->CreateNtupleDColumn("eDep");
    analMan->FinishNtuple();

}

void xyleneDetector_RunAction::EndOfRunAction(const G4Run*){
    G4AnalysisManager *analMan = G4AnalysisManager::Instance();
    analMan->Write();
    analMan->CloseFile();
}

