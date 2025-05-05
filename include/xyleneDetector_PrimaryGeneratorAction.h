#ifndef XYLENEDETECTOR_PRIMARYGENERATORACTION_HH
#define XYLENEDETECTOR_PRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

class xyleneDetector_PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    xyleneDetector_PrimaryGeneratorAction();
    virtual ~xyleneDetector_PrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event* anEvent);
public:
    G4ParticleGun *fParticleGun;
};

#endif
