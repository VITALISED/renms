#pragma once
#include <metadata/metadata_common.h>
enum eAxis
{
    EAxis_X = 0,
    EAxis_Y = 1,
    EAxis_Z = 2,
    EAxis_NegativeX = 3,
    EAxis_NegativeY = 4,
    EAxis_NegativeZ = 5,
    EAxis_CustomAxis = 6,
}

class cAxisSpecification
{
    static unsigned long long muNameHash = 0xE46A33ECA1AA62F7;
    static unsigned long long muTemplateHash = 0xE064B06A0D53FBE6;

    eAxis Axis;
    cTkVector3 mCustomAxis;
}
