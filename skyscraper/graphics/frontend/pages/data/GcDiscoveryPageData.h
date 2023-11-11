#pragma once

#include <skyscraper.h>

#include <graphics/ngui/ScrollBarState.h>
#include <toolkit/utilities/TkStrongType.h>

SKYSCRAPER_BEGIN

class cGcDiscoveryPageData
{
    enum eUploadType
    {
        EUploadType_All,
        EUploadType_Single,
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
    std::vector<
        cGcDiscoveryPageData::DiscoveryPageSystem, TkSTLAllocatorShim<cGcDiscoveryPageData::DiscoveryPageSystem, 8, -1>>
        maSystems;
    int miSystemsListWindowStartIndex;
    cTkStackVector<cGcDiscoveryPageDataSearchTask *, 3, -1> maDiscoveryPageTasks;
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
    std::vector<cGcDiscoveryData, TkSTLAllocatorShim<cGcDiscoveryData, 8, -1>> maRecentlyUploaded;
    float mfLastDiscoveryUploadedTime;
    float mfLastOfflineUploadTime;
    cGcDiscoveryPageData::SelectedDiscoveryAnimData mSelectedDiscoveryAnimData;
    ePlanetDisplayTargetDisplayState meDiscoveryDisplayState;
    ePlanetaryMappingDataState mePlanetaryMappingDataState;
    cTkSmartResHandle mMappingSphereResource;
    cGcDiscoveryPageData::cGcViewOnOpenRequest mViewOnOpenRequest;
};

SKYSCRAPER_END