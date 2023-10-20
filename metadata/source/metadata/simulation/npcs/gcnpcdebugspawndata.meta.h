#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcNPCDebugSpawnData
{
    static unsigned long long muNameHash = 0x1D427C136EB50E9D;
    static unsigned long long muTemplateHash = 0x490BCD8D16A8F7C9;

    cTkVector3 mPosition;
    cTkVector3 mFacing;
    cTkVector3 mUp;
    bool mbFollowWaypoints;
    float mfInitialDelay;
    cTkDynamicArray<cTkVector3> maWaypoints;
    bool mbPlayIdles;
    cTkDynamicArray<TkID<128>> maIdles;
    bool mbRun;
    bool mbRidePet;
    cGcAlienRace Race;
    cTkSeed mSeed;
    bool mbAddPetAccessories;
    float mfPetFollowOffset;
    cGcPetData Pet;
    cGcPetCustomisationData PetAccessoryCustomisation;
}
