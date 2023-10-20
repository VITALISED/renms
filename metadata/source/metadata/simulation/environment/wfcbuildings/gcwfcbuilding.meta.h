#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/wfcbuildings/gcmoduleoverride.meta.h>
#include <metadata/simulation/environment/wfcbuildings/gcminimumuseconstraint.meta.h>
#include <metadata/simulation/environment/wfcbuildings/gcweightedresource.meta.h>
#include <metadata/simulation/environment/wfcbuildings/gcweightedbuildingsize.meta.h>
#include <metadata/gamestate/basebuilding/gcbasebuildingpartstyle.meta.h>
#include <metadata/simulation/environment/wfcbuildings/gcfreighterbaseroom.meta.h>

class cGcWFCBuilding
{
    static unsigned long long muNameHash = 0x42C648ED396E4B44;
    static unsigned long long muTemplateHash = 0xEFF0648CC00F8AB8;

    cTkFixedString<32,char> macName;
    cTkFixedString<128,char> macModuleSet;
    cTkFixedArray<cTkFixedString<128,char>> maDecoration;
    bool mbImprovedCoherence;
    bool mbRequireNoUnreachableRooms;
    float mfInitialUnlockProbability;
    bool mbDontSpawnNearPlayerBases;
    bool mbRemoveUnreachableBlocks;
    cTkDynamicArray<TkID<128>> maGroupsEnabled;
    cTkDynamicArray<cGcModuleOverride> maModuleOverrides;
    cTkDynamicArray<cGcMinimumUseConstraint> maMinimumUseConstraints;
    cTkDynamicArray<TkID<128>> maNPCs;
    cTkDynamicArray<cGcWeightedResource> maLayouts;
    cTkDynamicArray<cGcWeightedBuildingSize> maSizes;
    cTkDynamicArray<long long> maFallbackSeeds;
    cTkDynamicArray<long long> maPresetFallbackSeeds;
    int miNumberOfPresetsPerPlanet;
    cGcBaseBuildingPartStyle ReplaceMaterials;
    cTkDynamicArray<cGcFreighterBaseRoom> maRooms;
}
