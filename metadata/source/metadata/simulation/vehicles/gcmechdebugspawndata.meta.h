#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMechDebugSpawnData
{
    static unsigned long long muNameHash = 0xCD20631E8DC06987;
    static unsigned long long muTemplateHash = 0xD488D7A5FF6D3F2D;

    cTkVector3 mPosition;
    cTkVector3 mFacing;
    cTkVector3 mUp;
    cTkVector3 mDestination;
    bool mbRunning;
    float mfTitanFallDelay;
    float mfMoveDelay;
    bool mbUseCustomisation;
    cGcCharacterCustomisationSaveData CustomisatonData;
}
