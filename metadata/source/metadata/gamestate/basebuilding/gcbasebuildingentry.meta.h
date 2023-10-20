#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
enum eBaseTerrainEditShape
{
    EBaseTerrainEditShape_Cube = 0,
    EBaseTerrainEditShape_Cylinder = 1,
}
#include <?>

class cGcBaseBuildingEntry
{
    static unsigned long long muNameHash = 0xA6F7B710166F6076;
    static unsigned long long muTemplateHash = 0x2E18738D74B90B8C;

    TkID<128> mID;
    bool mbIsTemporary;
    bool mbIsFromModFolder;
    cGcBaseBuildingPartStyle Style;
    cTkModelResource PlacementScene;
    cGcBaseBuildingObjectDecorationTypes DecorationType;
    bool mbIsPlaceable;
    bool mbIsDecoration;
    cGcBiomeType Biome;
    bool mbBuildableOnPlanetBase;
    bool mbBuildableOnSpaceBase;
    bool mbBuildableOnFreighter;
    bool mbBuildableOnPlanet;
    bool mbBuildableOnPlanetWithProduct;
    bool mbBuildableUnderwater;
    bool mbBuildableAboveWater;
    int miPlanetLimit;
    int miRegionLimit;
    int miPlanetBaseLimit;
    int miFreighterBaseLimit;
    bool mbCheckPlaceholderCollision;
    bool mbCheckPlayerCollision;
    bool mbCanRotate3D;
    bool mbCanScale;
    cTkDynamicArray<cGcBaseBuildingEntryGroup> maGroups;
    int miStorageContainerIndex;
    TkID<256> mColourPaletteGroupId;
    TkID<256> mDefaultColourPaletteId;
    TkID<256> mMaterialGroupId;
    TkID<256> mDefaultMaterialId;
    bool mbCanChangeColour;
    bool mbCanChangeMaterial;
    bool mbCanPickUp;
    bool mbShowInBuildMenu;
    cTkDynamicArray<TkID<128>> maCompositePartObjectIDs;
    cTkDynamicArray<TkID<128>> maFamilyIDs;
    float mfBuildEffectAccelerator;
    bool mbRemovesAttachedDecoration;
    bool mbRemovesWhenUnsnapped;
    bool mbEditsTerrain;
    eBaseTerrainEditShape BaseTerrainEditShape;
    float mfMinimumDeleteDistance;
    bool mbIsSealed;
    bool mbCloseMenuAfterBuild;
    cGcBaseLinkGridData LinkGridData;
    int miGhostsCountOverride;
    bool mbShowGhosts;
    float mfSnappingDistanceOverride;
    int miRegionSpawnLOD;
    cTkModelResource NPCInteractionScene;
}
