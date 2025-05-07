#include "xyleneDetector_SteppingAction.h"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4UserEventAction.hh"
#include "xyleneDetector_EventAction.h"
#include "G4RunManager.hh"

xyleneDetector_SteppingAction::xyleneDetector_SteppingAction() {}

xyleneDetector_SteppingAction::~xyleneDetector_SteppingAction() {}

void xyleneDetector_SteppingAction::UserSteppingAction(const G4Step* step) {
  G4Track *track = step->GetTrack();
  G4double energy = track->GetKineticEnergy();
  // G4cout << "Energy: " << energy / MeV << " MeV" << G4endl;

  G4UserEventAction *evAction = const_cast<G4UserEventAction *>(G4RunManager::GetRunManager()->GetUserEventAction());
  if (!G4RunManager::GetRunManager()) {
    std::cerr << "Error: RunManager is null!" << std::endl;
    return;
}
  xyleneDetector_EventAction *myEvAction = static_cast<xyleneDetector_EventAction *>(evAction);
  G4String volumeName = track->GetVolume()->GetName();
  G4String particleName = track->GetDefinition()->GetParticleName();
  G4int trackID = track->GetTrackID();
  double edep = step->GetTotalEnergyDeposit();

  if (volumeName == "Xylene") {
    std::cout << "TrackID : " << trackID << "\t ParticleName : " << particleName << "\t VolumeName : " << volumeName
              << "\t Energy Deposited : " << edep << std::endl;
            
      myEvAction->AddEnergy(edep);
      std:: cout<<"Wrote "<<edep<< std::endl;


}
}