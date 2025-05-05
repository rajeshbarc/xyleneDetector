#ifndef XYLENEDETECTOR_SENSITIVEDETECTOR_HH
#define XYLENEDETECTOR_SENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"

class xyleneDetector_SensitiveDetector : public G4VSensitiveDetector {
public:
    xyleneDetector_SensitiveDetector(const G4String& name);
    virtual ~xyleneDetector_SensitiveDetector();

    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
};

#endif
