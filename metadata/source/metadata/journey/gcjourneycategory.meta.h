#pragma once
#include <metadata/metadata_common.h>
#include <metadata/journey/gcjourneycategorytype.meta.h>
#include <metadata/gamestate/gcgamemode.meta.h>
#include <metadata/simulation/missions/types/gcmissionfaction.meta.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/journey/gcjourneymedal.meta.h>

class cGcJourneyCategory
{
    static unsigned long long muNameHash = 0x88F1E142115EF824;
    static unsigned long long muTemplateHash = 0x6B7881FEB05B98C6;

    cGcJourneyCategoryType Type;
    cGcGameMode GameModeRestriction;
    cGcMissionFaction Faction;
    TkID<256> mNameIDLower;
    TkID<256> mNameIDUpper;
    TkID<256> mDescriptionID;
    cTkTextureResource IconOn;
    cTkTextureResource IconOff;
    cTkDynamicArray<cGcJourneyMedal> maMedals;
}
