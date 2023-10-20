#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/gccreatureikdata.meta.h>
#include <metadata/simulation/ecosystem/gcikpistondata.meta.h>
enum eHeadUpAxis
{
    EHeadUpAxis_X = 0,
    EHeadUpAxis_XNeg = 1,
    EHeadUpAxis_Y = 2,
    EHeadUpAxis_YNeg = 3,
    EHeadUpAxis_Z = 4,
    EHeadUpAxis_ZNeg = 5,
}

class cGcCreatureFullBodyIKComponentData
{
    static unsigned long long muNameHash = 0x741554C15123D097;
    static unsigned long long muTemplateHash = 0xD746E629D444C041;

    cTkDynamicArray<cGcCreatureIkData> maJointData;
    cTkDynamicArray<cGcIkPistonData> maPistonData;
    eHeadUpAxis HeadUpAxis;
    float mfMaxHeadPitch;
    float mfMaxHeadRoll;
    float mfMaxHeadYaw;
    float mfBodyMassWeight;
    float mfOmega;
    float mfOmegaDropOff;
    float mfMovementDamp;
    bool mbUseFootGlue;
    float mfFootPlantSpringTime;
    bool mbUseFootAngle;
    float mfFootAngleSpeed;
    float mfMaxFootAngle;
    bool mbUsePistons;
    bool mbMech;
}
