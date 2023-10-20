#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkanimationgamedata.meta.h>

class cTkAnimBlendTree
{
    static unsigned long long muNameHash = 0x1C442B06A4F945F4;
    static unsigned long long muTemplateHash = 0xC6C8FE7E3EC66B68;

    TkID<128> mId;
    cTkClassPointer mTree;
    int miPriority;
    cTkAnimationGameData GameData;
}
