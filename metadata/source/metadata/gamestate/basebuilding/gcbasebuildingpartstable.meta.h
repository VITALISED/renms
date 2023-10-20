#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbasebuildingpart.meta.h>

class cGcBaseBuildingPartsTable
{
    static unsigned long long muNameHash = 0x87AF3D11ECD3C009;
    static unsigned long long muTemplateHash = 0x71DDE519FE03F1AF;

    cTkDynamicArray<cGcBaseBuildingPart> maParts;
}
