#pragma once
#include <metadata/metadata_common.h>
enum eSimpleInteractionType
{
    ESimpleInteractionType_Interact = 0,
    ESimpleInteractionType_Treasure = 1,
    ESimpleInteractionType_Beacon = 2,
    ESimpleInteractionType_Scan = 3,
    ESimpleInteractionType_Save = 4,
    ESimpleInteractionType_CallShip = 5,
    ESimpleInteractionType_CallVehicle = 6,
    ESimpleInteractionType_Word = 7,
    ESimpleInteractionType_Tech = 8,
    ESimpleInteractionType_GenericReward = 9,
    ESimpleInteractionType_Feed = 10,
    ESimpleInteractionType_Ladder = 11,
    ESimpleInteractionType_ClaimBase = 12,
    ESimpleInteractionType_TeleportStartPoint = 13,
    ESimpleInteractionType_TeleportEndPoint = 14,
    ESimpleInteractionType_Portal = 15,
    ESimpleInteractionType_Chest = 16,
    ESimpleInteractionType_ResourceHarvester = 17,
    ESimpleInteractionType_BaseCapsule = 18,
    ESimpleInteractionType_Hologram = 19,
    ESimpleInteractionType_NPCTerminalMessage = 20,
    ESimpleInteractionType_VehicleBoot = 21,
    ESimpleInteractionType_BiomeHarvester = 22,
    ESimpleInteractionType_FreighterGalacticMap = 23,
    ESimpleInteractionType_FreighterChest = 24,
    ESimpleInteractionType_Collectable = 25,
    ESimpleInteractionType_Chair = 26,
    ESimpleInteractionType_BaseTreasureChest = 27,
    ESimpleInteractionType_SpawnObject = 28,
    ESimpleInteractionType_NoiseBox = 29,
    ESimpleInteractionType_AbandFreighterTeleporter = 30,
    ESimpleInteractionType_PetEgg = 31,
    ESimpleInteractionType_SubstancePickup = 32,
    ESimpleInteractionType_FreighterTeleport = 33,
    ESimpleInteractionType_MiniPortalTrigger = 34,
    ESimpleInteractionType_SuperDoopaScanner = 35,
}
#include <metadata/reality/gcrarity.meta.h>
#include <metadata/reality/gcsizeindicator.meta.h>
#include <metadata/gameplay/gcfiendcrime.meta.h>
#include <metadata/gameplay/gcinteractionactivationcost.meta.h>
#include <metadata/reality/gcstatsenum.meta.h>
#include <metadata/reality/gcdiscoverytype.meta.h>
#include <metadata/gameplay/gcinteractionbasebuildingstate.meta.h>
#include <metadata/reality/gcrewardmissionoverride.meta.h>
#include <metadata/gameplay/gcpersistencymissionoverride.meta.h>

class cGcSimpleInteractionComponentData
{
    static unsigned long long muNameHash = 0xEAE36C86E1479AF5;
    static unsigned long long muTemplateHash = 0xA08E96856580D0A8;

    eSimpleInteractionType SimpleInteractionType;
    float mfInteractDistance;
    bool mbUse2dInteractDistance;
    TkID<128> mId;
    cGcRarity Rarity;
    cGcSizeIndicator Size;
    TkID<128> mTriggerAction;
    TkID<128> mTriggerActionOnPrepare;
    TkID<128> mTriggerActionToggle;
    bool mbBroadcastTriggerAction;
    float mfDelay;
    bool mbHideContents;
    bool mbInteractIsCrime;
    cGcFiendCrime InteractFiendCrimeType;
    float mfInteractFiendCrimeChance;
    int miInteractCrimeLevel;
    bool mbNotifyEncounter;
    cGcInteractionActivationCost ActivationCost;
    cGcStatsEnum StatToTrack;
    bool mbStartsBuried;
    bool mbMustBeVisibleToInteract;
    bool mbNeedsStorm;
    TkID<256> mName;
    TkID<256> mVRInteractMessage;
    TkID<256> mTerminalHeading;
    TkID<256> mTerminalMessage;
    TkID<256> mScanType;
    TkID<256> mScanData;
    cGcDiscoveryType ScanIcon;
    bool mbActivateLocatorsFromRarity;
    cTkFixedArray<TkID<128>> maRarityLocators;
    cTkDynamicArray<cGcInteractionBaseBuildingState> maBaseBuildingTriggerActions;
    cTkDynamicArray<cGcRewardMissionOverride> maRewardOverrideTable;
    cTkDynamicArray<cGcPersistencyMissionOverride> maPersistencyBufferOverride;
    bool mbUsePersonalPersistentBuffer;
    bool mbReseedOnRewardSuccess;
    bool mbCanCollectInMech;
}
