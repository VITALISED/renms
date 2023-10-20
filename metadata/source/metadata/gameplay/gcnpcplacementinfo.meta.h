#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcNPCPlacementInfo
{
    static unsigned long long muNameHash = 0xA12AC584067DF8E0;
    static unsigned long long muTemplateHash = 0xBC234D69742168C;

    TkID<128> mPlacementRuleId;
    cTkFixedString<32,char> macSpawnUnderNodeName;
    cTkFixedString<32,char> macPlacmentNodeName;
    bool mbMustPlace;
    float mfSpawnChance;
    float mfFractionOfNodesActive;
    int miMaxNodesActivated;
    TkID<128> mSpawnSpecific;
    cGcAlienRace Race;
    bool mbSpawnAnyMajorRace;
    cGcInteractionType InteractionOverride;
    cGcTechnologyCategory TechShopCategory;
    TkID<256> mForceInteraction;
    cTkDynamicArray<cGcAlienPuzzleMissionOverride> maPuzzleMissionOverrideTable;
    bool mbDisableInteraction;
    bool mbUseFreighterNPC;
    bool mbPlaceAtLeastOne;
    bool mbSpawnMoving;
    bool mbSpawnInAbandoned;
    cTkDynamicArray<TkID<128>> maHideDuringMissions;
    bool mbOnlyUsePuzzleOverridesIfPlayerOwned;
}
