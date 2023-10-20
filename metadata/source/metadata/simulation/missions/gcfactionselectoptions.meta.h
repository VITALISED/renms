#pragma once
#include <metadata/metadata_common.h>
enum eFactionOption
{
    EFactionOption_DataDefined = 0,
    EFactionOption_CurrentMission = 1,
    EFactionOption_CurrentSystem = 2,
}
#include <?>

class cGcFactionSelectOptions
{
    static unsigned long long muNameHash = 0x49D48E5A22491956;
    static unsigned long long muTemplateHash = 0x9618EF930539519F;

    eFactionOption FactionOption;
    cGcMissionFaction Faction;
}
