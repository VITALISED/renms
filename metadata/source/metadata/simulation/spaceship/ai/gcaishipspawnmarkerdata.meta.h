#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>
enum eShipsToMark
{
    EShipsToMark_None = 0,
    EShipsToMark_Leader = 1,
    EShipsToMark_All = 2,
}

class cGcAIShipSpawnMarkerData
{
    static unsigned long long muNameHash = 0xDB40771B3EB38336;
    static unsigned long long muTemplateHash = 0x103B4E1E1547DE0E;

    cTkTextureResource MarkerIcon;
    TkID<256> mMarkerLabel;
    bool mbHideDuringCombat;
    float mfMinVisibleRange;
    float mfMaxVisibleRange;
    float mfMinAngleVisible;
    eShipsToMark ShipsToMark;
}
