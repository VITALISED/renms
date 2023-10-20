#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcsyncbuffersavedata.meta.h>

class cGcSyncBufferSaveDataArray
{
    static unsigned long long muNameHash = 0x9488AB827ACAC6C8;
    static unsigned long long muTemplateHash = 0xBD756A38C535E82C;

    cTkDynamicArray<cGcSyncBufferSaveData> maData;
}
