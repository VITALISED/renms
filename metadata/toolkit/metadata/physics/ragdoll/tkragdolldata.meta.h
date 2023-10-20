#pragma once
#include <metadata/metadata_common.h>

class cTkRagdollData
{
    static unsigned long long muNameHash = 0x52912F535A46A50C;
    static unsigned long long muTemplateHash = 0x4C15A6F0B63EEF90;

    float mfDensity;
    float mfGravity;
    cTkDynamicArray<cTkFixedString<32,char>> maChainEnds;
    cTkDynamicArray<cTkFixedString<32,char>> maExcludeJoints;
}
