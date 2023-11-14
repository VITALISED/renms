#pragma once

#include <skyscraper.h>

#include <simulation/environment/scanning/GcMarkerRender.h>

SKYSCRAPER_BEGIN

class cGcFleetPageData
{
    cGcMarkerRenderData mBeginDial;
    cGcFleetExpedition *mpSelectedExpedition;
    cGcFleetFrigate *mpSelectedFrigate;
    int miCurrentFleetPage;
    int miCurrentExpeditionPage;
    int miCurrentExpeditionDetailsPage;
    int miSelectedPowerupIndex;
    eFleetPageMode mePageMode;
    float mfLeaveScreenTimer;
    float mfFeedFrigateStartTime;
    float mfDebriefLetterTimer;
    int miDebriefLogEntryLettersAddedLastFrame;
    int miDebriefLogEntryLettersShown;
    int miDebriefLogEntriesShown;
    eDebriefLogEntryStage meDebriefLogEntryStage;
    bool mbAddedCRDelay;
    bool mbShownDebrief;
    bool mbExpeditionHasBeenChosen;
    cTkVector3 mFocusFrigatePosition;
    cTkVector3 maFocusFrigateTraitPositions[5];
    cGcFleetFrigate mFrigateBeingPurchased;
    const cGcFleetFrigate *mpHighlightedFrigate;
    const cGcFleetFrigate *mpNewHighlightedFrigate;
    const cGcFleetExpedition *mpHighlightedExpedition;
    const cGcFleetExpedition *mpNewHighlightedExpedition;
    eFrontendPage meReturnPage;
    TkHandle mFocusNode;
    TkHandle mNewFocusNode;
    eExpeditionCategory meFrigateListPrimaryCategory;
    bool mbSortFrigateListRequested;
    bool mbPlayingDebriefAudio;
};

SKYSCRAPER_END