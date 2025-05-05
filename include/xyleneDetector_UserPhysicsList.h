#ifndef XYLENEDETECTOR_USERPHYSICSLIST_HH
#define XYLENEDETECTOR_USERPHYSICSLIST_HH

#include "G4VUserPhysicsList.hh"

class xyleneDetector_UserPhysicsList : public G4VUserPhysicsList {
public:
    xyleneDetector_UserPhysicsList();
    virtual ~xyleneDetector_UserPhysicsList();
    virtual void ConstructParticle(); 
    virtual void ConstructProcess(); 
};

#endif
