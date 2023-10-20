#pragma once
#include <metadata/metadata_common.h>

class cGcSmokeBotStats
{
    static unsigned long long muNameHash = 0xBF03A94511E0F7B0;
    static unsigned long long muTemplateHash = 0x44CC0793E9653419;

    float mfAvgCpuFPS;
    float mfMinCpuFPS;
    float mfMaxCpuFPS;
    cTkVector3 mMinCpuFPSPos;
    cTkVector3 mMinCpuFPSFacing;
    float mfAvgGpuFPS;
    float mfMinGpuFPS;
    float mfMaxGpuFPS;
    cTkVector3 mMinGpuFPSPos;
    cTkVector3 mMinGpuFPSFacing;
    float mfMinMemory;
    cTkVector3 mMinMemoryPos;
    cTkVector3 mMinMemoryFacing;
    float mfTotalCpuFps;
    float mfTotalGpuFps;
    int miFrameCount;
}
