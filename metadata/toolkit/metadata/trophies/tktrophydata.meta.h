#pragma once
#include <metadata/metadata_common.h>
#include <metadata/trophies/tktrophyentry.meta.h>

class cTkTrophyData
{
    static unsigned long long muNameHash = 0x75302EADC2AAED35;
    static unsigned long long muTemplateHash = 0x4AAD09A3D87C187F;

    cTkDynamicArray<cTkTrophyEntry> maTrophies;
}
