#pragma once

#include <skyscraper.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcModule.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcMap.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcSlot.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <metadata/source/simulation/environment/wfcbuildings/gcwfcmoduleset.meta.h>
#include <metadata/source/simulation/environment/wfcbuildings/gcwfcbuilding.meta.h>
#include <metadata/source/gameplay/gcnpcplacementinfo.meta.h>
#include <metadata/source/simulation/environment/wfcbuildings/decoration/gcwfcdecorationset.meta.h>

SKYSCRAPER_BEGIN

class cGcModuleSet
{
    struct sOptimizeTask
    {
        cGcMap mMap;
        cGcSlot *mCenterSlot;
        cTkVector<cGcModule *> mBoundaryOnlyModules;
        int miModulesOptimized;
    };

    const cTkFixedString<128,char> macFilename;
    const cTkVector3 mBlockSize;
    const int miSize;
    const cGcWFCModuleSet *mMetadata;
    const cGcWFCBuilding *const mpBuildingConfiguration;
    cGcModule **const mpaModules;
    robin_hood::detail::Table<false,80,unsigned char,cGcModuleSubset,robin_hood::hash<unsigned char,void>,std::equal_to<unsigned char> > mModulesExcludedByTerrainPattern;
    robin_hood::detail::Table<true,80,cGcWFCDecorationItem const *,cGcWFCScenes,robin_hood::hash<cGcWFCDecorationItem const *,void>,std::equal_to<cGcWFCDecorationItem const *> > mDecorationScenes;
    cGcModuleSubset maExcludedOnBoundary[6];
    cGcModuleSubset mSymmetricModules;
    cGcModuleSubset mWalkableModules;
    cTkVector<cGcModuleSubset> mGroundLevelModuleGroups;
    cTkVector<cGcNPCPlacementInfo const *> mNPCPlacementInfos;
    cGcWFCDecorationSet *mapDecorationSets[2];
    cTkVector<std::pair<cTkAABB,cTkMatrix34> > mDefaultBlockTerrainEdits;
    cTkVector<cGcMapLayout *> mLayouts;
    robin_hood::detail::Table<true,80,cGcPlanet const *,int *,robin_hood::hash<cGcPlanet const *,void>,std::equal_to<cGcPlanet const *> > mBuildingPresetsByPlanet;
    cTkVector<cGcBuildingPreset *> mBuildingPresets;
    robin_hood::detail::Table<false,80,cTkBitArray<unsigned __int64, 128>,cTkBitArray<unsigned __int64, 128>,robin_hood::hash<cTkBitArray<unsigned __int64, 128>,void>,std::equal_to<cTkBitArray<unsigned __int64, 128> > > mCompatibleConnectors;
    cGcModuleSet::sOptimizeTask *mpOptimizeTask;
};

SKYSCRAPER_END