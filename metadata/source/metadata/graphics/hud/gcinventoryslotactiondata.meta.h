#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkcurvetype.meta.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>

class cGcInventorySlotActionData
{
    static unsigned long long muNameHash = 0xC08D0836890AA2D6;
    static unsigned long long muTemplateHash = 0xAB981CE0AB2C1075;

    bool mbLoops;
    bool mbGlows;
    bool mbScales;
    float mfTime;
    float mfScaleAtMin;
    float mfScaleAtMax;
    cTkCurveType AnimCurve;
    cGcAudioWwiseEvents SuitAudio;
    cGcAudioWwiseEvents ActionAudio;
}
