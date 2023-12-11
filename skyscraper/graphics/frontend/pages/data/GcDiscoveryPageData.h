/**
 * @file GcDiscoveryPageData.h
 * @author VITALISED & Contributors
 * @since 2023-12-10
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <gamestate/GcDiscoveryCommon.h>
#include <gamestate/GcDiscoverySearch.h>
#include <simulation/ecosystem/creatures/behaviours/GcCreatureBehaviour.h>
#include <simulation/solarsystem/GcSolarSystemQuery.h>
#include <toolkit/core/types/TkTypes.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>

#include <simulation/solarsystem/planet/gcplanetdata.meta.h>

SKYSCRAPER_BEGIN

enum ePlanetDisplayTargetDisplayState
{
    ETargetDisplayState_None,
    ETargetDisplayState_System,
    ETargetDisplayState_Planet,
    ETargetDisplayState_PlanetaryMapping,
    ETargetDisplayState_Discovery,
};

enum ePlanetaryMappingDataState
{
    ETargetDisplayState_Idle,
    ETargetDisplayState_SetNodes,
    ETargetDisplayState_Complete,
    ETargetDisplayState_CompleteCurrentPlanet,
    ETargetDisplayState_NumTypes,
};

class cGcDiscoveryPageData;

class cGcDiscoveryPageDataSearchTask
{
  public:
    enum eTaskType
    {
        ESearchTaskType_Invalid,
        ESearchTaskType_SolarSystem,
        ESearchTaskType_Planets,
        ESearchTaskType_PlanetData,
    };

    cGcDiscoverySearch *mpSearch;
    cGcDiscoveryPageData *mDiscoveryData;
    cGcDiscoveryPageDataSearchTask::eTaskType meTaskType;
    bool mbComplete;

    virtual ~cGcDiscoveryPageDataSearchTask();
    virtual bool IsComplete();
    virtual void Start();
    virtual void Update();
    virtual void Destroy();
};

class cGcDiscoveryPageData
{
  public:
    enum eUploadType
    {
        EUploadType_All,
        EUploadType_Single,
    };

    enum eDiscoveryPageDataState
    {
        EDiscoveryPageDataState_Begin,
        EDiscoveryPageDataState_CleanUp,
        EDiscoveryPageDataState_Done,
    };

    enum eSystemFilters
    {
        EDiscoveryPageFilter_Normal,
        EDiscoveryPageFilter_Gek,
        EDiscoveryPageFilter_Korvax,
        EDiscoveryPageFilter_Vykeen,
        EDiscoveryPageFilter_Empty,
        EDiscoveryPageFilter_Abandoned,
        EDiscoveryPageFilter_Red,
        EDiscoveryPageFilter_Green,
        EDiscoveryPageFilter_Blue,
        EDiscoveryPageFilter_Hidden,
        EDiscoveryPageFilter_NumFilters,
    };

    enum eDiscoveryDisplayStatus
    {
        EDiscoveryDisplayStatus_None,
        EDiscoveryDisplayStatus_NotUploaded,
        EDiscoveryDisplayStatus_UploadedByOther,
        EDiscoveryDisplayStatus_UploadedRecently,
        EDiscoveryDisplayStatus_Uploaded,
    };

    class DiscoveryPageInfoBase
    {
      public:
        cGcDiscoveryData mDiscoveryData;
        cTkFixedString<127, char> macName;
        cTkFixedString<64, char> macDiscovererName;
        cTkFixedString<3, char> mDiscovererPlatform;
        cGcDiscoveryPageData::eDiscoveryDisplayStatus meDisplayStatus;
        int miTimeDiscovered;

        virtual ~DiscoveryPageInfoBase();
    };

    class DiscoveryPagePlanet : public DiscoveryPageInfoBase
    {
      public:
        struct ExtraFlags
        {
            int8_t mbHasPlanetBase : 1;
            int8_t mbIsCurrentLocation : 1;
            int8_t mbIsCurrentWaypoint : 1;
            int8_t mbIsMoon : 1;
        };

        cGcDiscoveryPageData::DiscoveryPagePlanet::ExtraFlags mExtraFlags;
    };

    class DiscoveryPageSystem : public DiscoveryPageInfoBase
    {
      public:
        struct ExtraFlags
        {
            int8_t mbHasPlanetBase : 1;
            int8_t mbIsCurrentLocation : 1;
            int8_t mbIsCurrentWaypoint : 1;
            int8_t mbIsMoon : 1;
            int8_t mbIsFiltered : 1;
        };

        std::shared_ptr<cGcGalaxyStarAttributesData> mpStarAttributes;
        cTkVector<cGcDiscoveryPageData::DiscoveryPagePlanet> maPlanets;
        cGcDiscoveryPageData::DiscoveryPageSystem::ExtraFlags mExtraFlags;
    };

    class DiscoveryPageSector : public DiscoveryPageInfoBase
    {
      public:
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mImage;
    };

    class DiscoveryPageDiscovery : public DiscoveryPageInfoBase
    {
      public:
        int miThumbnailIndex;
    };

    struct DiscoveryPagePlanetInfo
    {
      public:
        struct DiscoveryPreview
        {
            int miDiscoveriesIndex;
            int miThumbnailIndex;
            int miNextThumbnailIndex;
        };

        cTkVector<cGcDiscoveryPageData::DiscoveryPageSector> maSectors;
        cTkVector<cGcDiscoveryPageData::DiscoveryPageDiscovery> maDiscoveries;
        cTkVector<cGcDiscoveryPageData::DiscoveryPageDiscovery> maExtinctDiscoveries;
        int miNumAnimals;
        int miNumMinerals;
        int miNumFlora;
        int miDiscoveryMissionProgress;
        bool mabVisibleDiscoveries[9];
        float mfDiscoveryDisplayTimer;
        cGcPlanetData mPlanetGenerationData;
        cGcDiscoveryPageData::DiscoveryPagePlanetInfo::DiscoveryPreview mAnimalPreview;
        cGcDiscoveryPageData::DiscoveryPagePlanetInfo::DiscoveryPreview mFloraPreview;
        cGcDiscoveryPageData::DiscoveryPagePlanetInfo::DiscoveryPreview mMineralPreview;
        int miDiscoveriesPage;
        int miSelectedDiscovery;
        eDiscoveryType meDiscoveryTypeFilter;
    };

    struct SelectedDiscoveryAnimData
    {
        TkHandle mDiscoveryNode;
        cGcIdleAnimList mDiscoveryAnimList;
        bool mbPlayedFirstAnim;
        float mfWaitTimer;
        bool mbRequestAnim;
    };

    class cGcViewOnOpenRequest
    {
        enum eRequestType
        {
            ERequestType_Invalid,
            ERequestType_MostRecentDiscovery,
            ERequestType_SpecificDiscovery,
            ERequestType_CurrentPlanet,
        };

        cGcDiscoveryPageData::cGcViewOnOpenRequest::eRequestType meRequestType;
        eDiscoveryType meDiscoveryType;
        cGcDiscoveryData mDiscovery;
    };

    const float kfPlanetInfoAnimOutTime;
    const float kfDiscoveryInfoAnimOutTime;
    float mfPlanetPageStartTime;
    float mfPlanetInfoStartTime;
    float mfDiscoveryInfoAnimTimer;
    float mfDiscoveryPreviewRefreshTimer;
    ScrollBarState mSystemScrollBarState;
    ScrollBarState mDiscoveriesScrollBarState;
    std::array<float, 11> mafActivityPulses;
    float mfNanitesAwardedTime;
    int miNanitesAwarded;
    cGcDiscoveryPageData::eUploadType meUploadType;
    bool mbUsedPageHint;
    uint64_t mLastPlanetPositionsSystemUA;
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> maTagImages[3];
    cGcSolarSystemQuery mSystemQuery;
    cGcDiscoveryPageData::eDiscoveryPageDataState meDataState;
    cGcDiscoveryPageData::eSystemFilters meSystemFilter;
    cTkVector<cGcDiscoveryPageData::DiscoveryPageSystem> maSystems;
    int miSystemsListWindowStartIndex;
    cTkStackVector<cGcDiscoveryPageDataSearchTask *, 3> maDiscoveryPageTasks;
    cGcDiscoveryData mSelectedSolarSystem;
    int miSelectedSolarSystemIndex;
    cGcDiscoveryData mSelectedPlanet;
    uint64_t mNextPlanetUA;
    cTkFixedString<127, char> mSelectedSolarSystemName;
    cGcDiscoveryPageData::DiscoveryPagePlanetInfo mSelectedPlanetInfo;
    cGcDiscoveryExport *mpDiscoveryExport;
    cGcDiscoveryData mRenameDiscovery;
    cGcDiscoveryData mReportDiscovery;
    cGcDiscoveryData mAssignCustomWonderDiscovery;
    int miNextFreeSectorImageResource;
    std::array<cTkSmartResHandle, 64> mSectorImageResources;
    int miTotalNanitesAwarded;
    cTkVector<cGcDiscoveryData> maRecentlyUploaded;
    float mfLastDiscoveryUploadedTime;
    float mfLastOfflineUploadTime;
    cGcDiscoveryPageData::SelectedDiscoveryAnimData mSelectedDiscoveryAnimData;
    ePlanetDisplayTargetDisplayState meDiscoveryDisplayState;
    ePlanetaryMappingDataState mePlanetaryMappingDataState;
    cTkSmartResHandle mMappingSphereResource;
    cGcDiscoveryPageData::cGcViewOnOpenRequest mViewOnOpenRequest;
};

SKYSCRAPER_END