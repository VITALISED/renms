#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbasebuildingpartstyle.meta.h>
#include <metadata/simulation/environment/wfcbuildings/gcweightedcolourid.meta.h>
#include <metadata/simulation/environment/wfcbuildings/gcbuildingcolourpalette.meta.h>

class cGcSettlementColourPalette
{
    static unsigned long long muNameHash = 0x4D5124F6D6062BBF;
    static unsigned long long muTemplateHash = 0x90D3328E9461C8F3;

    TkID<128> mName;
    float mfRelativeProbability;
    cGcBaseBuildingPartStyle LimitToStyle;
    cTkDynamicArray<cGcWeightedColourId> maDefaultPalettes;
    cTkDynamicArray<cGcBuildingColourPalette> maBuildingPalettes;
}
