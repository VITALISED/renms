#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/types/gcconstructionpart.meta.h>
#include <metadata/simulation/missions/types/gcbuildingpartsearchtype.meta.h>

class cGcMissionSequenceConstruct
{
    static unsigned long long muNameHash = 0x694A21AA8BC8BAD4;
    static unsigned long long muTemplateHash = 0xC3530D73DF7B4A6A;

    cTkFixedString<128,char> macMessage;
    int miNumUniquePartsRequired;
    cTkDynamicArray<cGcConstructionPart> maPotentialParts;
    cGcBuildingPartSearchType Type;
    cTkFixedString<128,char> macDebugText;
}
