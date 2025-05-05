#ifndef XYLENEDETECTOR_EVENTACTION_HH
#define XYLENEDETECTOR_EVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
class xyleneDetector_EventAction : public G4UserEventAction {
public:
    xyleneDetector_EventAction();
    virtual ~xyleneDetector_EventAction();
    virtual void BeginOfEventAction(const G4Event *event);
    virtual void EndOfEventAction(const G4Event *event);
};

#endif
