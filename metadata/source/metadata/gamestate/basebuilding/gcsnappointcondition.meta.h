#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbasesnapstate.meta.h>

class cGcSnapPointCondition
{
    static unsigned long long muNameHash = 0x396BC2038766C20F;
    static unsigned long long muTemplateHash = 0x5A472B0478D3F41E;

    cTkFixedString<128,char> macSnapPoint;
    cGcBaseSnapState SnapState;
    TkID<128> mObjectId;
    int miSnapPointIndex;
}
