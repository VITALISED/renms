#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/wfcbuildings/gcweightedresource.meta.h>
enum eTerrainEdits
{
    ETerrainEdits_None = 0,
    ETerrainEdits_ClearEntireBlock = 1,
    ETerrainEdits_UseScene = 2,
    ETerrainEdits_UseBasebuildingEdits = 3,
}
#include <metadata/simulation/environment/wfcbuildings/gcwfcterrainconstraint.meta.h>
#include <metadata/simulation/environment/wfcbuildings/gcwfcface.meta.h>
enum eFreighterModuleType
{
    EFreighterModuleType_None = 0,
    EFreighterModuleType_Room = 1,
    EFreighterModuleType_Corridor = 2,
}

class cGcWFCModulePrototype
{
    static unsigned long long muNameHash = 0xEB956F6AA5C15F5C;
    static unsigned long long muTemplateHash = 0x74D021303F06166E;

    cTkFixedString<128,char> macName;
    TkID<128> mId;
    cTkFixedString<128,char> macGroup;
    float mfRelativeProbability;
    bool mbInclude;
    bool mbExcludeOnGround;
    bool mbExcludeOnTop;
    bool mbIndoors;
    bool mbLimitToOnePerLevel;
    bool mbExcludeRotatedVariants;
    bool mbDontRotateModel;
    TkID<128> mLayoutGroup;
    cTkDynamicArray<cGcWeightedResource> maScenes;
    eTerrainEdits TerrainEdits;
    cTkDynamicArray<cGcWFCTerrainConstraint> maTerrainConstraints;
    cGcWFCFace Left;
    cGcWFCFace Down;
    cGcWFCFace Back;
    cGcWFCFace Right;
    cGcWFCFace Up;
    cGcWFCFace Forward;
    eFreighterModuleType FreighterModuleType;
}
