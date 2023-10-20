#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/components/gameplay/gcinteractiontype.meta.h>
#include <metadata/reality/gcalienrace.meta.h>
enum eEventStartType
{
    EEventStartType_None = 0,
    EEventStartType_Special = 1,
    EEventStartType_Discovered = 2,
    EEventStartType_Timer = 3,
    EEventStartType_ObjectScan = 4,
    EEventStartType_LeaveBuilding = 5,
}
enum eBuildingLocation
{
    EBuildingLocation_Nearest = 0,
    EBuildingLocation_AllNearest = 1,
    EBuildingLocation_Random = 2,
    EBuildingLocation_RandomOnNearPlanet = 3,
    EBuildingLocation_RandomOnFarPlanet = 4,
    EBuildingLocation_PlanetSearch = 5,
    EBuildingLocation_PlayerSettlement = 6,
}
#include <metadata/simulation/environment/gcbuildingclassification.meta.h>
enum eSolarSystemLocation
{
    ESolarSystemLocation_Local = 0,
    ESolarSystemLocation_Near = 1,
    ESolarSystemLocation_LocalOrNear = 2,
    ESolarSystemLocation_NearWithNoExpeditions = 3,
    ESolarSystemLocation_FromList = 4,
    ESolarSystemLocation_SeasonParty = 5,
}
#include <metadata/simulation/gcscaneventsolarsystemlookup.meta.h>
#include <metadata/simulation/gcscaneventtriggers.meta.h>
#include <metadata/reality/gctechnologycategory.meta.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/graphics/hud/gcscannericonhighlighttypes.meta.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>
#include <metadata/utilities/data/gcresourceelement.meta.h>

class cGcScanEventData
{
    static unsigned long long muNameHash = 0x7BBBCE7D7BC0F1F4;
    static unsigned long long muTemplateHash = 0x5D2C5B4A197F412A;

    TkID<256> mName;
    TkID<256> mForceInteraction;
    cGcInteractionType ForceInteractionType;
    cGcAlienRace RequireInteractionRace;
    bool mbForceBroken;
    bool mbForceFixed;
    bool mbForceOverridesAll;
    TkID<128> mForceOverrideEncounter;
    bool mbIsCommunityPortalOverride;
    bool mbClearForcedInteractionOnCompletion;
    float mfBuildingPreventionRadius;
    bool mbUseMissionTradingDataOverride;
    bool mbAlwaysShow;
    bool mbNeverShow;
    bool mbShowOnlyIfSequenceTarget;
    TkID<256> mPlanetLabelText;
    float mfSurveyDistance;
    TkID<256> mSurveyDiscoveryOSDMessage;
    eEventStartType EventStartType;
    eEventEndType EventEndType;
    eEventPriority EventPriority;
    bool mbCanEndFromOutsideMission;
    bool mbDisableMultiplayerSync;
    bool mbReplaceEventIfAlreadyActive;
    eBuildingLocation BuildingLocation;
    eBuildingType BuildingType;
    cGcBuildingClassification BuildingClass;
    bool mbAllowFriendsBases;
    bool mbForceWideRandom;
    bool mbMustFindSystem;
    bool mbAllowOverriddenBuildings;
    eSolarSystemLocation SolarSystemLocation;
    cGcScanEventSolarSystemLookup SolarSystemAttributes;
    cGcScanEventSolarSystemLookup SolarSystemAttributesFallback;
    bool mbForceRestartInteraction;
    TkID<128> mHasReward;
    TkID<256> mNextOption;
    cGcScanEventTriggers TriggerActions;
    cTkDynamicArray<cTkFixedString<256,char>> maUAsList;
    cGcTechnologyCategory TechShopType;
    cTkFixedString<32,char> macOSDMessage;
    cTkFixedString<32,char> macInterstellarOSDMessage;
    cTkFixedString<32,char> macMarkerLabel;
    cTkTextureResource MarkerIcon;
    cGcScannerIconHighlightTypes MissionMarkerHighlightStyleOverride;
    float mfStartTime;
    float mfMessageTime;
    float mfMessageDisplayTime;
    cGcAudioWwiseEvents MessageAudio;
    float mfIconTime;
    float mfTooltipTime;
    bool mbTooltipRepeats;
    bool mbShowEndTooltip;
    cTkFixedString<32,char> macTooltipMessage;
    cGcResourceElement ResourceOverride;
}
