#include "xyleneDetector_EventAction.h"
#include "xyleneDetector_RunAction.h"
#include "G4RunManager.hh"

xyleneDetector_EventAction::xyleneDetector_EventAction()  {
}

xyleneDetector_EventAction::~xyleneDetector_EventAction() {}

void xyleneDetector_EventAction::BeginOfEventAction(const G4Event *event){
    //TODO : All the required logic you want to do at the start
    //       of each event
    totalEnergyDeposited = 0.0;
}

void xyleneDetector_EventAction::AddEnergy(double val)
{
    //std::cout<<"Energy added"<<val;
    totalEnergyDeposited+=val;
}

void xyleneDetector_EventAction::EndOfEventAction(const G4Event *event){
    //TODO : All the required logic you want to do at the end
    //       of each event
    //std::cout << "Total Energy deposited in event : " << event->GetEventID() << " : " << eDep << std::endl;

  G4AnalysisManager *analMan = G4AnalysisManager::Instance();
  if (totalEnergyDeposited > 0) {
    
    analMan->FillNtupleDColumn(0, 0, totalEnergyDeposited);
    G4double resolution = 0.11; // 10% resolution at 1 MeV
    G4double sigma = resolution * std::sqrt(totalEnergyDeposited); // e.g., sigma ∝ sqrt(E)
    G4double smearedEdep = G4RandGauss::shoot(totalEnergyDeposited, sigma);
    smearedEdep = std::max(0.0, smearedEdep);
    analMan->FillNtupleDColumn(0, 1, smearedEdep);
    analMan->AddNtupleRow(0); 

}
}