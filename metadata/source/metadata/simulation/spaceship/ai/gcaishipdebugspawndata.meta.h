#pragma once
#include <metadata/metadata_common.h>

class cGcAIShipDebugSpawnData
{
    static unsigned long long muNameHash = 0xDFA8A7A9DD3ACC08;
    static unsigned long long muTemplateHash = 0xD616A0433497617;

    cTkVector3 mPosition;
    cTkVector3 mFacing;
    cTkVector3 mUp;
    cTkVector3 mFlightDir;
    float mfSpeed;
    float mfIgnitionDelay;
    float mfTakeOffDelay;
    float mfHoverTime;
    float mfHoverHeight;
    float mfWarpOutTime;
    bool mbWingman;
    cTkFixedString<128,char> macSpecificModel;
    cTkSeed mSeed;
}
