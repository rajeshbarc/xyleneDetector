#ifndef XYLENEDETECTOR_DETECTORCONSTRUCTION_HH
#define XYLENEDETECTOR_DETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"

class xyleneDetector_DetectorConstruction : public G4VUserDetectorConstruction {
public:
    xyleneDetector_DetectorConstruction();
    virtual ~xyleneDetector_DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
};

#endif
