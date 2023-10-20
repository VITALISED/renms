#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkCreatureTailParams
{
    static unsigned long long muNameHash = 0xF5A68FEB65BA7107;
    static unsigned long long muTemplateHash = 0x4EBCA4EEA1161646;

    TkID<256> mPartName;
    cTkDynamicArray<cTkCreatureTailJoints> maJoints;
    float mfAnimationMix;
    float mfSwimSpeed;
    float mfSwimReps;
    float mfMaxTurnForSwim;
    float mfSwimBlendInTime;
    float mfSwimBlendOutTime;
    float mfSwimMagnitude;
    float mfSwimRollMagnitude;
    float mfSwimFallOffBegin;
    float mfSwimFallOffEnd;
    float mfMinSwimStrength;
    bool mbHorizontalStrokes;
    cTkDynamicArray<float> maPerBoneSwimStrength;
}
