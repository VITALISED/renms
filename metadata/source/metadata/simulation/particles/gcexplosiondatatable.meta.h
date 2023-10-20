#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/particles/gcexplosiondata.meta.h>

class cGcExplosionDataTable
{
    static unsigned long long muNameHash = 0xF9FB8E431EB1179F;
    static unsigned long long muTemplateHash = 0x87BED22AA91A65F5;

    cTkFixedString<128,char> macName;
    cTkDynamicArray<cGcExplosionData> maTable;
}
