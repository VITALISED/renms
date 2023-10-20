#pragma once
#include <metadata/metadata_common.h>
enum eType
{
    EType_Instanced = 0,
    EType_Single = 1,
}
#include <?>
#include <?>
enum ePlacementPriority
{
    EPlacementPriority_Low = 0,
    EPlacementPriority_Normal = 1,
    EPlacementPriority_High = 2,
}
enum eLargeObjectCoverage
{
    ELargeObjectCoverage_DoNotPlace = 0,
    ELargeObjectCoverage_DoNotPlaceIgnoreFootprint = 1,
    ELargeObjectCoverage_DoNotPlaceClose = 2,
    ELargeObjectCoverage_DoNotPlaceAnywhereNear = 3,
    ELargeObjectCoverage_OnlyPlaceAround = 4,
    ELargeObjectCoverage_OnlyPlaceAroundIgnoreFootprint = 5,
    ELargeObjectCoverage_AlwaysPlace = 6,
}
enum eGroundColourIndex
{
    EGroundColourIndex_Auto = 0,
    EGroundColourIndex_Main = 1,
    EGroundColourIndex_Patch = 2,
}
#include <?>

class cGcObjectSpawnData
{
    static unsigned long long muNameHash = 0x43EBB2E6AFAC5863;
    static unsigned long long muTemplateHash = 0xD5427D42870E991C;

    TkID<128> mDebugName;
    eType Type;
    cGcResourceElement Resource;
    cTkDynamicArray<cGcResourceElement> maAltResources;
    cTkDynamicArray<cGcTerrainTileType> maExtraTileTypes;
    TkID<128> mPlacement;
    cTkSeed mSeed;
    ePlacementPriority PlacementPriority;
    eLargeObjectCoverage LargeObjectCoverage;
    eOverlapStyle OverlapStyle;
    float mfMinHeight;
    float mfMaxHeight;
    bool mbRelativeToSeaLevel;
    float mfMinAngle;
    float mfMaxAngle;
    bool mbMatchGroundColour;
    eGroundColourIndex GroundColourIndex;
    bool mbSwapPrimaryForSecondaryColour;
    bool mbSwapPrimaryForRandomColour;
    bool mbAlignToNormal;
    float mfMinScale;
    float mfMaxScale;
    float mfMinScaleY;
    float mfMaxScaleY;
    float mfSlopeScaling;
    float mfPatchEdgeScaling;
    float mfMaxXZRotation;
    bool mbAutoCollision;
    bool mbCollideWithPlayer;
    bool mbCollideWithPlayerVehicle;
    bool mbDestroyedByPlayerVehicle;
    bool mbDestroyedByPlayerShip;
    bool mbDestroyedByTerrainEdit;
    bool mbInvisibleToCamera;
    bool mbCreaturesCanEat;
    float mfShearWindStrength;
    TkID<128> mDestroyedByVehicleEffect;
    cGcObjectSpawnDataVariant QualityVariantData;
    cTkDynamicArray<cGcObjectSpawnDataVariant> maQualityVariants;
}
