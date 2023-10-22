#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/simulation/TkSeed.h>
#include <metadata/gamestate/gcseasonsavestateondeath.meta.h>

SKYSCRAPER_BEGIN

class cGcSeasonState
{
    struct sSeasonalMilestoneProgress
    {
        int miStageIndex;
        int miMilestoneIndex;
        float mfCurrentValue;
        float mfUnitProgress;
        bool mbRewardFitsInInventory;
        bool mbRewardCollected;
        bool mbRevealed;
        bool mbVisible;
    };

    struct sSeasonalStageProgress
    {
        cTkVector<cGcSeasonState::sSeasonalMilestoneProgress> maMilestones;
        float mfProgress;
    };

    struct sPinnedMilestone
    {
        int miStageIndex;
        int miMilestoneIndex;
    };

    struct sPendingMilestoneReward
    {
        int miStageIndex;
        int miMilestoneIndex;
    };

    struct sSeasonInitialBuilding
    {
        cTkVector3 mPosition;
        cTkSeed mSeed;
        float mfRadius;
    };

    struct sBuildingPreventionArea
    {
        cTkVector3 mPosition;
        float mfRadius;
    };

    cTkVector<cGcSeasonState::sSeasonalStageProgress> maStageProgress;
    cGcSeasonState::sPinnedMilestone mPinnedMilestone;
    cGcSeasonState::sPendingMilestoneReward mPendingMilestoneReward;
    cTkVector<unsigned __int64> maRendezvousUAs;
    cTkVector<cGcSeasonState::sSeasonInitialBuilding> maInitialBuildings;
    robin_hood::detail::Table<true,80,unsigned __int64, cTkVector<cGcSeasonState::sBuildingPreventionArea >,robin_hood::hash<unsigned __int64,void>,std::equal_to<unsigned __int64> > mBuildingPreventionAreas;
    cGcSeasonSaveStateOnDeath mStateOnDeath;
    cTkVector<cGcTechnology> maReplacedTechnologies;
    cTkVector<cGcProductData> maReplacedProducts;
    cTkVector<cGcRealitySubstanceData> maReplacedSubstances;
    bool mbWantToUpdateRewardAvailability;
    bool mbHasCollectedFinalReward;
    bool mbFinalRewardFitsInInventory;
};

SKYSCRAPER_END