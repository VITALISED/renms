#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcuniquenpcspawndata.meta.h>
#include <metadata/gameplay/gcnpcplacementinfo.meta.h>

class cGcNPCSpawnTable
{
    static unsigned long long muNameHash = 0xEF1AB4FE11FCFA6D;
    static unsigned long long muTemplateHash = 0x6CE80CDD523D33CE;

    cTkFixedArray<cTkFixedString<128,char>> maNPCModelNames;
    cTkFixedArray<float> maNPCRaceScale;
    cTkDynamicArray<cGcUniqueNPCSpawnData> maUniqueNPCs;
    cTkDynamicArray<cGcNPCPlacementInfo> maPlacementInfos;
}
