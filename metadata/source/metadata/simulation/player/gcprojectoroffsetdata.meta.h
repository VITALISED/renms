#pragma once
#include <metadata/metadata_common.h>
#include <metadata/ui/hud/gcinworlduiscreendata.meta.h>

class cGcProjectorOffsetData
{
    static unsigned long long muNameHash = 0xB9DD91F357A56979;
    static unsigned long long muTemplateHash = 0x9E692218EF2AC71A;

    float mfScale;
    cTkVector2 mScreenScale;
    cGcInWorldUIScreenData Active;
    cGcInWorldUIScreenData Inactive;
}
