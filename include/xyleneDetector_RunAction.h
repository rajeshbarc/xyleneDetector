#ifndef XYLENEDETECTOR_RUNACTION_HH
#define XYLENEDETECTOR_RUNACTION_HH

class G4Run;

#include "G4UserRunAction.hh"
#include "G4Event.hh"
class xyleneDetector_RunAction : public G4UserRunAction {
public:
    xyleneDetector_RunAction();
    virtual ~xyleneDetector_RunAction();
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};

#endif
