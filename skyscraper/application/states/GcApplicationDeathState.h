#pragma once

#include <skyscraper.h>
#include <application/states/GcApplicationState.h>
#include <toolkit/utilities/TkStrongType.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/gamestate/gcinventoryelement.meta.h>

SKYSCRAPER_BEGIN

class cGcApplicationDeathState : public cGcApplicationState
{
    typedef cGcAsyncLoadOps::Operation Phase;

    TkStrongType<int,TkStrongTypeIDs::TkResHandleID> mPipelineResource;
    cTkVector<bool> maPreviousPipelineStageState;
    cTkFixedString<512,char> mDeathQuote;
    cTkFixedString<512,char> mDeathAuthor;
    int miDeathQuoteIndex;
    cTkVector3 mDeathPosition;
    cTkVector<cGcInventoryElement> mTrashedItems;
    cGcNGui mGUI;
    float mfQuoteAlpha;
    cGcApplicationDeathState::Phase mePhase;
    float mfTimeDeadTotal;
    float mfTimeToSpendDead;
    float mfTimeToWaitForQuote;
    float mfTimeToSpendGeneratingSpawnLocation;
    float mfRegenDistractionAlpha;
    bool mbDeleteManualSave;
    bool mbPlayerWasInShipWhenKilled;
    bool mbPlayerWasInVehicleWhenKilled;
    bool mbPlayerWasInsidePlanetRangeWhenKilled;
    bool mbPlayerWasLandedWhenKilled;
    bool mbPlayerCrashingOnPlanetFromShip;
    bool mbPlayerWasInAbandonedFreighter;
    bool mbFirstUpdate;
};

SKYSCRAPER_END