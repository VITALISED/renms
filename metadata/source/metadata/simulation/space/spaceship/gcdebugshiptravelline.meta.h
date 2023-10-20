#pragma once
#include <metadata/metadata_common.h>

class cGcDebugShipTravelLine
{
    static unsigned long long muNameHash = 0x639D09D542659F2F;
    static unsigned long long muTemplateHash = 0xE5E0C2C9BFB8D83D;

    cTkVector3 mOrigin;
    cTkVector3 mDir;
    float mfLength;
    float mfInfluenceRange;
}
