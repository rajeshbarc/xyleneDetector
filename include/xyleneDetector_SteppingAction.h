#ifndef XYLENEDETECTOR_STEPPINGACTION_HH
#define XYLENEDETECTOR_STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"

class xyleneDetector_SteppingAction : public G4UserSteppingAction {
public:
    xyleneDetector_SteppingAction();
    virtual ~xyleneDetector_SteppingAction();

    virtual void UserSteppingAction(const G4Step*);
};

#endif
