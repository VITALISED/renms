#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/TkSeed.h>
#include <gamestate/basebuilding/BaseIndex.h>
#include <simulation/solarsystem/planet/GcPlanet.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <metadata/source/simulation/environment/wfcbuildings/decoration/gcwfcdecorationtheme.meta.h>

SKYSCRAPER_BEGIN

class cGcWFCBuildingState
{
    cTkSeed mSeed;
    BaseIndex mBaseIndex;
    cGcWFCBuildingState *mpBaseOwnerState;
    cTkPhysRelMat34 mTransform;
    cGcMap *mpMap;
    cGcSettlementBuildingState mState;
    cGcPlanet *mpPlanet;
    cGcBuilding *mpBuilding;
    sBaseBuildingMaterial mPalette;
    sBaseBuildingMaterial mPaletteDecoration;
    std::vector<sWFCBuildingPart> mParts;
    std::vector<sBuildingNPCPlacement> mNPCs;
    bool mbReadyToSpawn;
    bool mabStagesComplete[5];
    eWFCDecorationTheme meDecorationTheme;
    bool mabDecorationThemesGenerated[2];
    int miPartsAdded;
    std::vector<int> mNPCsToSpawn;
    int miSpawnedNPCsCount;
    std::vector<sBuildingEntrance> mEntranceNodes;
    TkHandle mClusterNode;
    bool mbUpgraded;
    bool mbInitialUnlock;
    bool mbFirstBaseElevationChangeComplete;
    bool mbRequestClearFoliage;
};

SKYSCRAPER_END