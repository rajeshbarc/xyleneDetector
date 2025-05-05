#ifndef XYLENEDETECTOR_TRACKINGACTION_HH
#define XYLENEDETECTOR_TRACKINGACTION_HH

#include "G4UserTrackingAction.hh"
#include "G4Track.hh"

class xyleneDetector_TrackingAction : public G4UserTrackingAction {
public:
    xyleneDetector_TrackingAction();
    virtual ~xyleneDetector_TrackingAction();
    virtual void PreUserTrackingAction(const G4Track *track);
    virtual void PostUserTrackingAction(const G4Track *track);
};

#endif
