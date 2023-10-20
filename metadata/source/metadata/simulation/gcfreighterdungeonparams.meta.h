#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/gcdungeongenerationparams.meta.h>

class cGcFreighterDungeonParams
{
    static unsigned long long muNameHash = 0x1186D86C82D48E4E;
    static unsigned long long muTemplateHash = 0xA0D3F2E5C001BA81;

    TkID<128> mName;
    cGcDungeonGenerationParams DungeonParams;
}
