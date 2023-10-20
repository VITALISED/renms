#pragma once
#include <metadata/metadata_common.h>

class cTkJointExtentData
{
    static unsigned long long muNameHash = 0xB538605B35EDD12C;
    static unsigned long long muTemplateHash = 0xBFECB029B47E76AA;

    cTkFixedArray<float> maJointExtentMin;
    cTkFixedArray<float> maJointExtentMax;
    cTkFixedArray<float> maJointExtentCenter;
    cTkFixedArray<float> maJointExtentStdDev;
}
