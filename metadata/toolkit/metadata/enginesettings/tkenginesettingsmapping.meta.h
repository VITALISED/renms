#pragma once
#include <metadata/metadata_common.h>

class cTkEngineSettingsMapping
{
    static unsigned long long muNameHash = 0xC02F1D19584B44D;
    static unsigned long long muTemplateHash = 0x32F9FD324E2BDA4C;

    cTkFixedArray<float> maShadowMultiplier;
    cTkFixedArray<float> maReflectionMultiplier;
    cTkFixedArray<float> maReflectionProbesMultiplier;
    cTkFixedArray<float> maIKFullBodyIterations;
    cTkFixedArray<float> maCloudsResolutionScale;
    cTkFixedArray<int> maCloudsMaxIterations;
    cTkFixedArray<bool> maNeedsGameRestart;
}
