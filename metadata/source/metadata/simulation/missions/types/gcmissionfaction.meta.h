#pragma once
#include <metadata/metadata_common.h>
enum eMissionFaction
{
    EMissionFaction_Gek = 0,
    EMissionFaction_Korvax = 1,
    EMissionFaction_Vykeen = 2,
    EMissionFaction_TradeGuild = 3,
    EMissionFaction_WarriorGuild = 4,
    EMissionFaction_ExplorerGuild = 5,
    EMissionFaction_Nexus = 6,
    EMissionFaction_Pirates = 7,
    EMissionFaction_None = 8,
}

class cGcMissionFaction
{
    static unsigned long long muNameHash = 0x1D300E2AA74F7BA7;
    static unsigned long long muTemplateHash = 0x5721A97130AFD54E;

    eMissionFaction MissionFaction;
}
