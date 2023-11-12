#pragma once

#include <skyscraper.h>

#include <gamestate/GcDiscoverySearch.h>
#include <graphics/ngui/ScrollBarState.h>
#include <simulation/ecosystem/creatures/behaviours/GcCreatureBehaviour.h>
#include <simulation/solarsystem/GcSolarSystemQuery.h>
#include <toolkit/utilities/TkStrongType.h>
#include <toolkit/utilities/containers/TkStackVector.h>

#include <simulation/solarsystem/planet/gcplanetdata.meta.h>
#include <simulation/solarsystem/planet/gcplanetdataresourcehint.meta.h>

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

class cGcDiscoveryPageDataSearchTask
{
    enum eTaskType
    {
        ESearchTaskType_Invalid,
        ESearchTaskType_SolarSystem,
        ESearchTaskType_Planets,
        ESearchTaskType_PlanetData,
    };

    VFT<5> *__vftable;
    cGcDiscoverySearch *mpSearch;
    cGcDiscoveryPageData *mDiscoveryData;
    cGcDiscoveryPageDataSearchTask::eTaskType meTaskType;
    bool mbComplete;
};

class cGcDiscoveryPageData
{
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
        VFT<1> *__vftable;
        cGcDiscoveryData mDiscoveryData;
        cTkFixedString<127, char> macName;
        cTkFixedString<64, char> macDiscovererName;
        cTkFixedString<3, char> mDiscovererPlatform;
        cGcDiscoveryPageData::eDiscoveryDisplayStatus meDisplayStatus;
        int miTimeDiscovered;
    };

    class DiscoveryPagePlanet : public cGcDiscoveryPageData::DiscoveryPageInfoBase
    {
        struct ExtraFlags
        {
            __int8 mbHasPlanetBase : 1;
            __int8 mbIsCurrentLocation : 1;
            __int8 mbIsCurrentWaypoint : 1;
            __int8 mbIsMoon : 1;
        };

        VFT<1> *__vftable;
        cGcDiscoveryPageData::DiscoveryPagePlanet::ExtraFlags mExtraFlags;
    };

    class DiscoveryPageSystem : public cGcDiscoveryPageData::DiscoveryPageInfoBase
    {
        struct ExtraFlags
        {
            __int8 mbHasPlanetBase : 1;
            __int8 mbIsCurrentLocation : 1;
            __int8 mbIsCurrentWaypoint : 1;
            __int8 mbIsMoon : 1;
            __int8 mbIsFiltered : 1;
        };

        VFT<1> *__vftable;
        std::shared_ptr<cGcGalaxyStarAttributesData> mpStarAttributes;
        cTkVector<cGcDiscoveryPageData::DiscoveryPagePlanet> maPlanets;
        cGcDiscoveryPageData::DiscoveryPageSystem::ExtraFlags mExtraFlags;
    };

    class DiscoveryPageSector : public cGcDiscoveryPageData::DiscoveryPageInfoBase
    {
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mImage;
    };

    class DiscoveryPageDiscovery : public cGcDiscoveryPageData::DiscoveryPageInfoBase
    {
        int miThumbnailIndex;
    };

    struct DiscoveryPagePlanetInfo
    {
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

    struct cGcViewOnOpenRequest
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
    unsigned __int64 mLastPlanetPositionsSystemUA;
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> maTagImages[3];
    cGcSolarSystemQuery mSystemQuery;
    cGcDiscoveryPageData::eDiscoveryPageDataState meDataState;
    cGcDiscoveryPageData::eSystemFilters meSystemFilter;
    cTkVector<cGcDiscoveryPageData::DiscoveryPageSystem> maSystems;
    int miSystemsListWindowStartIndex;
    cTkStackVector<cGcDiscoveryPageDataSearchTask *> maDiscoveryPageTasks;
    cGcDiscoveryData mSelectedSolarSystem;
    int miSelectedSolarSystemIndex;
    cGcDiscoveryData mSelectedPlanet;
    unsigned __int64 mNextPlanetUA;
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