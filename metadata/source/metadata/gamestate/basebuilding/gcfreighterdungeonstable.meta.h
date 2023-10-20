#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/gcfreighterdungeonparams.meta.h>

class cGcFreighterDungeonsTable
{
    static unsigned long long muNameHash = 0x556A3DBA7B5C9168;
    static unsigned long long muTemplateHash = 0x64B04F1B6ACB84E3;

    cTkDynamicArray<cGcFreighterDungeonParams> maDungeons;
}
