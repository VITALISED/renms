/**
 * @file GcGalaxyMap.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <atlas/broker/GcAtlasBroker.h>
#include <gamestate/GcDiscoveryManager.h>
#include <gamestate/GcGameKnowledge.h>
#include <simulation/galaxy/GcGalaxyMapUI.h>
#include <simulation/galaxy/GcGalaxySolarSection.h>
#include <simulation/galaxy/GcGalaxyVoxelCache.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/system/memory/TkTransientHeap.h>
#include <toolkit/utilities/containers/TkClassPool.h>

#include <simulation/galaxy/gcgalaxyrendersetupdata.meta.h>
#include <simulation/galaxy/gcgalaxywaypoint.meta.h>

SKYSCRAPER_BEGIN

struct AnomorphicConfig
{
    cTkVector2 mPlacementOffset;
    float mfVertCompression;
    float mfHorizScale;
    float mfContrast;
    float mfAlpha;
    cTkColour mColourOuter;
    cTkColour mColourInner;
};

struct IntroTransition
{
    uint8_t meState[4];
    float mfFadeValue;
    float mfTitleFade;
    float mfTitleTime;
    cTkSmartResHandle mTitleImageResource;
    bool mbStingAudioPlayed;
};

struct RelativeVoxelIndex
{
    int miX;
    int miY;
    int miZ;
};

struct IntroCameraLook
{
    float mfCurrentX;
    float mfCurrentY;
    float mfRateX;
    float mfRateY;
};

struct SolarAudioTracking
{
    TkAudioObject mAudioObject;
    int mLocalArrayIndex;
    uint16_t mSolarID;
    bool mbTrackingActive;
};

struct StarTree
{
    struct LinkNode
    {
        cTkVector3 mPosition;
        unsigned int mJumpIndex;
        uint64_t mu64UniverseAddress;
        cTkStackVector<StarTree::LinkNode *, 10> mChildNodes;
    };

    cTkTransientHeap mTransientHeap;
    StarTree::LinkNode mRoot;
    cGcGalacticVoxelCoordinate mRootCoordinate;
};

struct PushToSelectState
{
    uint64_t mu64LastChosenUA;
    cTkVector3 mLastChosenPosition;
    float mfTimer;
    cTkVector2 mScreenSpacePosition;
    int miLastChosenIndex;
};

struct PCSwipeToSelectState
{
    float mfMousePushDirection;
    float mfActivityTimeout;
    bool mbPushActive;
};

struct PathFindingTask
{
    SolarQueryResult mQueryFrom;
    SolarQueryResult mQueryTo;
    GPN::SearchContext mContext;
    int miFailures;
    std::vector<cTkVector3> mRenderPath;
    std::vector<uint64_t> mPathUAs;
    cGcGalacticVoxelCoordinate mRenderPathRootVoxel;
};

struct RegisteredWaypoint
{
    cGcGalaxyWaypoint mWaypointData;
    SolarQueryResult mQueryResult;
    TkAudioObject mWaypointAudio;
    PathFindingTask *mPathToWaypoint;
    float mfRenderPathAlpha;
    bool mbPathIsPartial;
};

struct RemoteContactManager
{
    cGcGalacticVoxelCoordinate mFetchRootCoordinate;
    float mfFetchIntervalTimeout;
    int miCurrentFetchWalkIndex;
    unsigned int muRequestCounter;
    std::array<RelativeVoxelIndex, 27> *mContactIndexArray;
    std::array<uint64_t, 64> maUA;
    std::array<uint64_t, 64> maRequestHandle;
    std::array<uint64_t, 64> maLastRequestTimestamp;
    std::array<cGcAtlasRecvVoxel, 64> maVoxelData;
};

class cGcIntroFeed
{
    std::array<cTkFixedString<127, char>, 48> mSelectedNames;
    std::array<cTkFixedString<127, char>, 48> mSelectedUsers;
    unsigned int muLoadedNames;
    int miUpdateTimestamp;
    uint64_t mServerUpdateHandle;
    bool mbUpdateTriggered;
    bool mbValid;
};

class cGcGalaxyMap : IKnowledgeEventHandler, IDiscoveryManagerEventHandler, AutoPooled<23>
{
  public:
    enum MapMode
    {
        Game,
        Intro,
        Final,
        Tutorial,
        Warp,
    };

    enum TutorialState
    {
        HoldBeforeFlyHome,
        BeginFlyHome,
        FlyHome,
        HoldHome,
        BeginLookAtTarget,
        LookingAtTarget,
        HoldCamera,
        DrawLines,
        Hold,
        EndLookAtTarget,
    };

    struct Data
    {
        struct InWorldScreen
        {
            cTkClassPoolHandle mHandle;
            cTkPhysRelVec3 mPosition;
            cTkVector2 mAlignment;
            bool mbVisible;
        };

        struct MarkerSystemName
        {
            DiscoveryResolver::NameAndOwnerResult mNameAndOwner;
            uint64_t mUA;
        };

        union {
            struct
            {
                cGcGalaxyMap::MapMode meMode;
                IntroTransition mIntroTransition;
                cGcGalaxyMap::TutorialState meTutorialState;
                uint8_t meCurrentFilter[4];
                float mfFinalAnimationSpeed;
                bool mbFullScreenTransition;
                cGcGalacticAddressData mTutorialTarget;
                cTkSmartResHandle mBGPipeline;
                cTkSmartResHandle mPStreamScene;
                cTkSmartResHandle mBGMaterial;
                cGcGalaxyVoxelCache mVoxelCache;
                TkHandle mMapRootNode;
                TkHandle mLinesNode;
                TkHandle mMapNodeGrid[5][5][5];
                std::array<RelativeVoxelIndex, 125> mVoxelGridSortedWalkIndices;
                std::array<RelativeVoxelIndex, 27> mContactIndexArray;
                cGcGalaxyRenderSetupData mGalaxyRenderSetupData;
                cGcGalaxyRenderSetupData mCurrentGalaxyRenderSetupData;
                unsigned int muCurrentGalaxyRenderSetupDataRealityIndex;
                AnomorphicConfig mAnomorphicConfig;
                TkAudioObject mAudioObject;
                TkAudioObject mAudioObjectForTimer;
                GalaxyNavigationMode meNavigationMode;
                GalaxyNavigationMode meStoredNavigationMode;
                int miNavigationPathIndex;
                bool mbCurrentPathUnavailable;
                IntroCameraLook mIntroCameraLook;
                cTkVector3 mGyroLook;
                cTkVector3 mCameraHeadDir;
                cTkMatrix34 mCameraMatrix;
                cTkMatrix34 mCameraMatrixC;
                cTkMatrix34 mCameraMatrixL;
                cTkMatrix34 mCameraMatrixR;
                cTkMatrix34 mCameraMatrixNoShake;
                cTkMatrix34 mPreviousCameraMatrix;
                cTkMatrix34 mPreviousCameraMatrixNoShake;
                float mfFoV;
                float mfScreenWidth;
                float mfScreenHeight;
                float mfTime;
                float mfTutorialCounter;
                int miRenderColourIndex;
                int miRenderColourLoop;
                cGcGalacticVoxelCoordinate mCurrentGalacticCoordinate;
                SolarQueryResult mCurrentTarget;
                float mTargetSelectionCount;
                cTkVector3 mGoalDirection;
                float mfGoalDistance;
                cTkVector2 mPulseAudioCoordinate;
                float mPulseColorZone;
                uint16_t mPendingLocationAssignment;
                SolarQueryResult mInitialLocationAssignment;
                SolarQueryResult mCustomFlyToQuery;
                bool mPendingFocusPull;
                bool mbCustomFlyToPoint;
                std::array<cTkVector3, 42> mavBlurPoints;
                std::array<float, 42> mavBlurPointDistancesSqr;
                std::array<uint64_t, 10> maNearbyMetadataArray;
                unsigned int muBlurPointCount;
                std::array<SolarAudioTracking, 10> maSolarAudioArray;
                cGcGalaxySolarSelection *mpSolarSelection;
                std::array<cGcGalaxySolarSelection *, 8> maSolarSelectionsRetired;
                cTkTFixedFreeList<cGcGalaxySolarSelection, 23> mSolarSelectionFreeList;
                float mfActiveSelectionT;
                StarTree mSelectionStarTree;
                float mfSelectionStarTreeAlpha;
                PushToSelectState mPushToSelectState;
                float mfPressToAcceptTimer;
                bool mbHandSelectWaitingDebounce;
                PCSwipeToSelectState mPCSwipeToSelectState;
                cGcDiscoveryData mDiscoveryToQuery;
                float mDiscoveryQueryDelay;
            };
            const int kiMaxNumInWorldUIScreens;
        };

        cGcGalaxyMap::Data::InWorldScreen maInWorldUIScreens[16];
        TkHandle mInWorldScreenRootNode;
        cGcGalaxyMapUI mMapUI;
        cTkVector<PathFindingTask *> mPathFindingTasks;
        PathFindingTask *mpPathToCenterTask;
        cTkStackVector<RegisteredWaypoint *, 8> mRegisteredWaypoints;
        cTkVector<cGcInterstellarEvent> mScanEvents;
        float mfClearAllWaypointsTimer;
        bool mbWarpToNextGalaxyRequested;
        unsigned int muPreviousGalaxyRealityIndex;
        bool mbShouldScanWhenPossible;
        RemoteContactManager mRemoteContactManager;
        cGcIntroFeed mIntroFeed;
        std::array<cTkPhysRelVec3, 320> mScreenMarkerInputs;
        std::array<cTkVector4, 320> mScreenMarkerOutputs;
        std::array<uint64_t, 320> mScreenMarkerUAs;
        std::array<int, 320> mScreenMarkerTypes;
        std::array<int, 320> mScreenMarkerVariations;
        std::array<cTkFixedString<64, char>, 320> mScreenMarkerLabels;
        unsigned int muScreenMarkerCount;
        cTkVector<cGcGalaxyMap::Data::MarkerSystemName> mScreenMarkerSystemNames;
        TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> maMarkerIconImages[16];
        eTradingClass meCurrentFilterTradingClass;
        cGcDiscoveryDataRing<6> mContactSelectRingBuffer;
        robin_hood::detail::Table<
            true, 80, uint64_t, unsigned int, robin_hood::hash<uint64_t, void>, std::equal_to<uint64_t>>
            mNameHashMap;
        unsigned int muNextName;
        cTkNGuiInput mGameGuiInput;
        std::array<float, 32> mIntroLabelLYDistances;
        std::array<cTkPhysRelVec3, 32> mIntroLabelInputs;
        std::array<cTkVector4, 32> mIntroLabelOutputs;
        std::array<int, 32> mIntroLabelRandomIndex;
        unsigned int muIntroLabelCount;
        float mfIntroFadeIn;
        SolarQueryResult mLoadingStartLocation;
        TkGalactic::ParticleInstanceData mParticleTemplate;
        cGcGalacticVoxelCoordinate mLastCoordinate;

        ~Data() { EMPTY_CALL_DESTRUCTOR(); }
    };

    cGcGalaxyMap::Data *mpData;
};

SKYSCRAPER_END