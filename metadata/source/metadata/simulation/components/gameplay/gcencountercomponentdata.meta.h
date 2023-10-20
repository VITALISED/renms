#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcEncounterComponentData
{
    static unsigned long long muNameHash = 0x1BAD68301EABDA5C;
    static unsigned long long muTemplateHash = 0x8B81EF15449C5259;

    cGcEncounterType EncounterType;
    cTkDynamicArray<TkID<128>> maInteractMissionTable;
}
