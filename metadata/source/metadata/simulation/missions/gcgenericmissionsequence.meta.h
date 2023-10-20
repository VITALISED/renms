#pragma once
#include <metadata/metadata_common.h>
enum eMissionClass
{
    EMissionClass_Primary = 0,
    EMissionClass_Secondary = 1,
    EMissionClass_ChainedSecondary = 2,
    EMissionClass_Guide = 3,
    EMissionClass_Wiki = 4,
    EMissionClass_Seasonal = 5,
    EMissionClass_Milestone = 6,
}
#include <metadata/reality/gcnumberedtextlist.meta.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/simulation/missions/types/gcmissioncategory.meta.h>
#include <metadata/simulation/missions/types/gcmissionpagehint.meta.h>
#include <metadata/simulation/missions/defaultmissionitems/gcdefaultmissionitemstable.meta.h>
enum eMessageComplete
{
    EMessageComplete_Default = 0,
    EMessageComplete_Always = 1,
    EMessageComplete_Never = 2,
}
#include <metadata/simulation/missions/gcmissionboardoptions.meta.h>
#include <metadata/reality/gcalienpuzzletable.meta.h>
#include <metadata/simulation/gcscaneventdata.meta.h>
#include <metadata/reality/gcgenericrewardtableentry.meta.h>
#include <metadata/reality/gccosttableentry.meta.h>
#include <metadata/reality/gctradedata.meta.h>
#include <metadata/simulation/missions/types/gcmissionconditiontest.meta.h>
#include <metadata/simulation/missions/gcgenericmissionversionprogress.meta.h>
#include <metadata/simulation/missions/gcgenericmissionstage.meta.h>

class cGcGenericMissionSequence
{
    static unsigned long long muNameHash = 0xFAE86B2801335B6D;
    static unsigned long long muTemplateHash = 0xA5D439E96EBCE89D;

    TkID<128> mMissionID;
    eMissionClass MissionClass;
    bool mbMissionIsCritical;
    cTkFixedString<32,char> macMissionObjective;
    cGcNumberedTextList MissionTitles;
    cGcNumberedTextList MissionSubtitles;
    cGcNumberedTextList MissionDescriptions;
    cTkFixedString<32,char> macMissionDescSwitchOverride;
    cGcNumberedTextList MissionProcDescriptionHeader;
    cGcNumberedTextList MissionProcDescriptionA;
    cGcNumberedTextList MissionProcDescriptionB;
    cGcNumberedTextList MissionProcDescriptionC;
    bool mbUseScanEventDetailsInLogInfo;
    cTkTextureResource MissionIcon;
    cTkTextureResource MissionIconSelected;
    cTkTextureResource MissionIconNotSelected;
    int miMissionPriority;
    cGcMissionCategory MissionCategory;
    cGcMissionPageHint MissionPageHint;
    TkID<256> mMissionPageLocID;
    TkID<128> mMissionBuildMenuHint;
    bool mbMissionHasColourOverride;
    cTkColour mMissionColourOverride;
    int miBeginCheckFrequency;
    cGcDefaultMissionItemsTable DefaultItems;
    bool mbPrefixTitle;
    TkID<128> mNextMissionHint;
    eMessageComplete MessageComplete;
    eMessageStart MessageStart;
    cGcMissionBoardOptions MissionBoardOptions;
    eAutoStart AutoStart;
    bool mbRestartOnCompletion;
    bool mbCancelSetsComplete;
    cGcAlienPuzzleTable Dialog;
    cTkDynamicArray<cGcScanEventData> maScanEvents;
    cTkDynamicArray<cGcGenericRewardTableEntry> maRewards;
    cTkDynamicArray<cGcCostTableEntry> maCosts;
    cGcTradeData TradingDataOverride;
    cGcMissionConditionTest StartConditionTest;
    cGcMissionConditionTest CancelConditionTest;
    bool mbStartIsCancel;
    cTkDynamicArray<cTkClassPointer> maStartingConditions;
    cTkDynamicArray<cTkClassPointer> maCancelingConditions;
    cTkDynamicArray<cGcGenericMissionVersionProgress> maFinalStageVersions;
    cTkDynamicArray<cGcGenericMissionStage> maStages;
    bool mbForcesPageHint;
    bool mbForcesBuildMenuHint;
    bool mbIsProceduralAllowed;
    bool mbIsRecurring;
    bool mbIsLegacy;
    bool mbBlocksPinning;
    bool mbCanRenounce;
    TkID<128> mUseCommunityMissionForLog;
    bool mbTelemetryUpload;
    bool mbUseSeasonTitleOverride;
}
