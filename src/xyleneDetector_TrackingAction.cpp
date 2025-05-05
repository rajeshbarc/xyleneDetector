#include "xyleneDetector_TrackingAction.h"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

xyleneDetector_TrackingAction::xyleneDetector_TrackingAction()  {
}

xyleneDetector_TrackingAction::~xyleneDetector_TrackingAction() {}

void xyleneDetector_TrackingAction::PreUserTrackingAction(const G4Track *track){
std::cout <<"Tracking Action begin....." << std::endl;
}

void xyleneDetector_TrackingAction::PostUserTrackingAction(const G4Track *track){
std::cout <<"Tracking Action ends....." << std::endl;
}

