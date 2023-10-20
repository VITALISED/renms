#pragma once
#include <metadata/metadata_common.h>
enum eLookAtType
{
    ELookAtType_Player = 0,
}

class cGcLookAtComponentData
{
    static unsigned long long muNameHash = 0xC264A609B1BBACB5;
    static unsigned long long muTemplateHash = 0x53145C2A847F1078;

    eLookAtType LookAtType;
    cTkFixedString<32,char> macNodeName;
    float mfRotationRateFactor;
    float mfMinRotationRateDegrees;
}
