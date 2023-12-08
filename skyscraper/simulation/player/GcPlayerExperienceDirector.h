/**
 * @file GcPlayerExperienceDirector.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <graphics/2d/GcProceduralTexture.h>
#include <networking/GcNetworkPlayerEventsHandler.h>
#include <networking/GcNetworkRpcCall.h>
#include <simulation/player/GcFrigateFlyby.h>
#include <simulation/vehicle/GcVehicleCheckPointManager.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <toolkit/maths/geometry/TkSphere.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/system/TkAddNodesHandle.h>
#include <toolkit/utilities/containers/TkClassPool.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <gameplay/gcplayerexperiencespawndata.meta.h>
#include <gameplay/gcplayerexperiencespawntable.meta.h>
#include <gameplay/gcsentinelspawnnamedsequence.meta.h>
#include <messages/gcmessagefiendcrime.meta.h>
#include <player/experience/gcexperiencespawntable.meta.h>
#include <reality/gcdiscoveryowner.meta.h>
#include <reality/gcrealitycommonfactions.meta.h>
#include <reality/gcrewardactivatefiends.meta.h>
#include <reality/gcrewardshipassistance.meta.h>
#include <simulation/ecosystem/creatures/gccreaturedata.meta.h>
#include <simulation/ecosystem/creatures/gccreaturetypes.meta.h>
#include <simulation/ecosystem/gccreatureroles.meta.h>
#include <simulation/gcdebugscene.meta.h>
#include <simulation/gcspaceshipclasses.meta.h>
#include <simulation/solarsystem/planet/gcbiometype.meta.h>
#include <simulation/solarsystem/planet/gcplanetcolourdata.meta.h>
#include <simulation/space/gcbackgroundspaceencounterinfo.meta.h>
#include <simulation/space/gcpulseencounterinfo.meta.h>
#include <simulation/spaceship/ai/gcaishipspawndata.meta.h>
#include <simulation/spaceship/ai/gcbountyspawninfo.meta.h>
#include <utilities/data/gcresourceelement.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayer;

enum ePreviousExperienceLocation
{
    EPreviousExperienceLocation_Invalid,
    EPreviousExperienceLocation_Planet,
    EPreviousExperienceLocation_Space,
    EPreviousExperienceLocation_Freighter,
};

enum ePirateSpawn
{
    EPirateSpawn_None = -1,
    EPirateSpawn_CargoAttackStart,
    EPirateSpawn_Probing,
    EPirateSpawn_ProbeHail,
    EPirateSpawn_ProbeSuccess,
    EPirateSpawn_ProbeSuccessSilent,
    EPirateSpawn_AttackWarning,
    EPirateSpawn_Attacking,
    EPirateSpawn_FreighterBattleStart,
    EPirateSpawn_BattleMarker,
    EPirateSpawn_Battling,
    EPirateSpawn_BattleJoined,
    EPirateSpawn_BattleEscaped,
    EPirateSpawn_BountyStart,
    EPirateSpawn_BountyPrepare,
    EPirateSpawn_BountyActive,
    EPirateSpawn_BountyAttacking,
    EPirateSpawn_BountyFleeing,
    EPirateSpawn_PlanetaryRaidStart,
    EPirateSpawn_PlanetaryRaidApproaching,
    EPirateSpawn_PlanetaryRaidAttacking,
    EPirateSpawn_PlanetaryRaidFlee,
    EPirateSpawn_PlanetaryFlyByStart,
    EPirateSpawn_PlanetaryFlyByApproach,
    EPirateSpawn_PlanetaryFlyByAttacking,
    EPirateSpawn_PlanetaryFlyByFlee,
    EPirateSpawn_NumTypes,
};

enum ePoliceEntrance
{
    EPoliceEntrance_None,
    EPoliceEntrance_Start,
    EPoliceEntrance_Probing,
    EPoliceEntrance_Incoming,
    EPoliceEntrance_Arrived,
    EPoliceEntrance_Escalate,
    EPoliceEntrance_EscalateProbing,
    EPoliceEntrance_EscalateIncoming,
    EPoliceEntrance_CargoScanStart,
    EPoliceEntrance_CargoScanProbing,
    EPoliceEntrance_CargoScanAttemptContact,
    EPoliceEntrance_CargoScanInComms,
    EPoliceEntrance_CargoScanStartAttack,
};

enum eDefenceForceSpawn
{
    EDefenceForceSpawn_None,
    EDefenceForceSpawn_Waiting,
    EDefenceForceSpawn_WaitingForFrigateAssignment,
    EDefenceForceSpawn_SpawnFrigate,
    EDefenceForceSpawn_SpawnDefenders,
    EDefenceForceSpawn_Complete,
};

enum ePulseEncounterState
{
    EPulseEncounterState_None = -1,
    EPulseEncounterState_Prepare,
    EPulseEncounterState_Waiting_To_Start,
    EPulseEncounterState_Waiting_To_Exit_Pulse,
    EPulseEncounterState_Loading,
    EPulseEncounterState_Spawning,
    EPulseEncounterState_Active,
    EPulseEncounterState_CleanUp,
    EPulseEncounterState_NumTypes,
};

struct Assistance
{
    eAssistanceType meType;
    float mfTime;
    float mfElapsed;
};

class cGcExperienceSpawn
{
  public:
    cTkAttachmentPtr mpAttachment;
    eAIFaction meFaction;
    cTkClassPoolHandle mSquad;
    cTkMatrix34 mSpawnMatrix;
    cGcAIShipSpawnData *mpData;
    float mfInterestDistance;
    float mfStartSpeed;
    cTkSphere *mpObstruction;
    cTkClassPoolHandle mInvalidAsteroidArea;
    bool mbIsAmbient;
    bool mbIsBattle;
    bool mbIsPoliceFreighter;
    float mfInterestTime;
    float mfInterestCounter;
    ePirateSpawn meBecomeUninterestingPirateSpawnState;
    TkID<128> mAttackDefinition;
    TkID<256> mRewardMessageOverride;
    uint64_t mSeed;
    int miDataIndex;
    bool mbIgnoreWarpEffects;
    bool mbForceComplexCollision;
    bool mbPlayerMustBeInShip;
    bool mbDoAudioPulses;
    float mfFrigateTargetSpeed;
};

class cGcSpawnRequest
{
  public:
    cGcExperienceSpawn mSpawn;
    unsigned int mAudioPulseOverride;
    unsigned int mArrivalAudio;
    float mfTime;
    float mfSpawnTime;
    float mfAbortRange;
    float mfArriveTime;
    float mfPulseSize;
    float mfPulseRate;
    int miAudioPulseCount;
    bool mbSpawned;
    bool mbVirtualSpawn;
    bool mbPlayerMustBeInShip;
    float mafProgress[3][8];
};

template <typename T>
class cGcChooser
{
  public:
    cTkPersonalRNG mRNG;
    std::vector<std::pair<T, float>> mafOdds;
};

class cGcAIShipSpawn
{
  public:
    cTkAttachmentPtr mpMainAttachment;
    TkHandle mNode;
    bool mbUsesAISpaceshipComponent;
    eAIFaction meFaction;
    eAIShipRole meRole;
    eShipClass meClass;
    cTkClassPoolHandle mSquad;
};

class cGcFiendSpawnRequest
{
  public:
    cTkVector3 mvPos;
    TkHandle mNode;
    float mfMinDist;
    float mfMaxDist;
    float mfSpawnDist;
    float mfDespawnDist;
    float mfDelay;
    int miOverrideFiendHealth;
    TkID<128> mOverrideFiendDamage;
    float mfSpawnDistanceMultiplier;
    float mfSpeedMultiplier;
    float mfOverrideFiendScale;
    eCreatureType meCreatureType;
    const cGcPlayerExperienceSpawnData *mpSpawnData;
    cTkAttachmentPtr mpAttachment;
};

class cGcVirtualisedCreature
{
  public:
    const cGcPlayerExperienceSpawnData *mpSpawnData;
    eCreatureType mType;
    eCreatureRole mRole;
    TkID<128> mSpawnId;
    eMoveArea mMoveArea;
    cTkPhysRelMat34 mMatrix;
    cTkSmartResHandle mResource;
    float mfSpawnRadius;
    float mfDespawnRadius;
    bool mbIsSwarmMember;
    bool mbIndoorNavigation;
};

class cGcFiendManagerBase
{
  public:
    cTkVector<cGcFiendSpawnRequest> maSpawnRequests;
    cTkVector<cTkAttachmentPtr> mapAttachments;
    cTkVector<cGcVirtualisedCreature> maVirtualisedCreatures;
    bool mbWantsToClear;

    virtual void Construct();
    virtual void Add(cTkVector<cTkAttachmentPtr> *);
    virtual bool CanVirtualise();
    virtual void ReportCrime(const cGcMessageFiendCrime *, cTkPersonalRNG *, const cGcRewardActivateFiends *);
    virtual bool ActiveFiendCombat(bool);
    virtual void OnTakeControlOfFiend();
    virtual float GetDespawnDistance();
    virtual void Release();
    virtual void Update(float);
    virtual void RenderNGui(const char *, cGcExperienceSpawnTable *, cTkPersonalRNG *, eExperienceSpawnType);
    virtual void DebugDraw();
};

class cGcFiendManagerUnderwater : public cGcFiendManagerBase
{};

class cGcFiendManagerStandard : public cGcFiendManagerBase
{
  public:
    enum eManagerLocation
    {
        EManagerLocation_Planet,
        EManagerLocation_Mission,
        EManagerLocation_Freighter,
        EManagerLocation_Space,
    };
    float mfSpawnTimer;
    float mfSpawnTimeRemaining;
    float mfActiveTimeRemaining;
    unsigned int miMaxFiendstoSpawn;
    unsigned int miOverrideFiendHealth;
    TkID<128> mOverrideFiendDamage;
    float mfSpawnDistanceMultiplier;
    float mfSpeedMultiplier;
    float mfOverrideFiendScale;
    float mfAggroLevel;
    bool mbCanSpawn;
    cTkVector3 mvLastCrimePosition;
    cGcFiendManagerStandard::eManagerLocation meLocation;
};

class cGcSentinelInfo
{
    struct Sentinels
    {
        cTkVector<cTkAttachmentPtr> mapAttachments[9];
    };

    struct SentinelCounts
    {
        int maiCount[9];
    };

    cGcSentinelInfo::Sentinels mSentinels;
    cGcSentinelInfo::SentinelCounts mSizes;
    const cGcSentinelSpawnNamedSequence *mpCurrentSequence;
    int miCurrentWave;
    int miReinforceCount;
    int miWanted;
};

class sOwnedCreatureInfo
{
    enum eLoadState
    {
        ELoadState_Complete,
        ELoadState_LoadResource,
        ELoadState_WaitForResource,
        ELoadState_GetStats,
    };

    enum eEggSenderNameState
    {
        EEggSenderNameState_Unchecked,
        EEggSenderNameState_Processing,
        EEggSenderNameState_Done,
    };

    cGcPlanetColourData mColourPalette;
    TkID<128> mCreatureID;
    uint64_t muFileHash;
    bool mbRequestStarted;
    sOwnedCreatureInfo::eLoadState meLoadState;
    sOwnedCreatureInfo::eEggSenderNameState meEggSenderNameState;
    cTkResourceDescriptor mDescriptor;
    uint64_t mSpeciesSeed;
    uint64_t mGenusSeed;
    TkID<256> mCustomSpeciesName;
    bool mbPredator;
    uint64_t mPackedUA;
    cTkSeed mColourBaseSeed;
    cTkSeed mBoneScaleSeed;
    eBiome meBiome;
    eCreatureType meCreatureType;
    uint64_t muBirthTime;
    uint64_t muLastEggTime;
    uint64_t muLastTrustIncreaseTime;
    uint64_t muLastTrustDecreaseTime;
    cTkFixedString<32, char> mProcName;
    cTkFixedString<32, char> mCustomName;
    bool mbHasFur;
    cGcDiscoveryOwner mSenderData;
    float mfScale;
    float mfHeight;
    float mfWeight;
    float mfTrust;
    float mafTraits[3];
    float mafMoods[2];
    cTkSmoothCD<float> mafSmoothedMoods[2];
    cTkSmartResHandle mResource;
    cGcProceduralTextureManager::TaskContext *mpTC;
    cTkModelResourceRenderer mThumbnailRenderer;
    cTkModelResourceRenderer mLargeThumbnailRenderer;
    bool mbReadyToLayEgg;
    bool mbEggModified;
    bool mbAllowUnmodifiedReroll;
    bool mbHasBeenSummoned;
};

class cGcPlayerExperienceDirector : public INetworkPlayerEventsHandler
{
  public:
    enum eCombatSquad
    {
        ECombatSquad_None,
        ECombatSquad_Deploying,
        ECombatSquad_Deployed,
        ECombatSquad_RequestReinforcements,
    };

    enum eDebugCameraState
    {
        EDebugCameraState_Inactive,
        EDebugCameraState_Playing,
        EDebugCameraState_Paused,
    };

    class cGcArchetypeResource
    {
      public:
        TkID<128> mArchetypeId;
        cGcResourceElement mResource;
    };

    struct TrailerShipData
    {
        cTkAttachmentPtr mpShip;
        cTkSmartResHandle mResource;
    };

    cGcRpcCallBase *RASS;
    std::array<float, 9> mafTimers;
    std::array<float, 9> mafWaitTimes;
    std::array<int, 9> maiRepeatCounters;
    std::array<float, 9> mafTimerAccelerators;
    cGcFrigateFlyby mFrigateFlyby;
    cTkVector<cTkSphere> maSpaceInvalidSpawnAreas;
    cTkVector<cGcExperienceSpawn> maSpawns;
    cTkVector<cTkUserIdBase<cTkFixedString<64, char>>> maPirateKillers;
    cTkVector<Assistance> maRequestedAssistances;
    bool mbPoliceActive;
    ePoliceEntrance mePoliceArrival;
    float mfPoliceArriveTimer;
    float mfPoliceAttackProbeTimer;
    float mfLastPoliceActiveTime;
    float mfPoliceEscapeTime;
    int mbPoliceHasWantedLevel;
    float mfLastCombatEventTime;
    cTkVector<cGcSpawnRequest> maSpawnRequests;
    eDefenceForceSpawn meDefenseForceSpawn;
    float mfDefenceForceStateStartTime;
    ePirateSpawn mePirateSpawn;
    float mfPirateStateActiveTime;
    cTkVector3 mPirateTargetPos;
    cTkVector3 mPirateTargetDir;
    int miNumActivePirateSpawns;
    cGcChooser<ePirateSpawn> maPirateChoosers[4];
    TkHandle mPirateTargetFreighter;
    cTkSeed mPirateSeed;
    cTkAttachmentPtr mpBountyTarget;
    cGcBountySpawnInfo *mpBountyInfo;
    cTkSeed mBountySeed;
    float mfLastSpaceCombatTime;
    float mfLastTraderRequestTime;
    cTkAttachmentPtr mpLastPirateRaidBuildingTarget;
    ePulseEncounterState mePulseEncounterState;
    const cGcPulseEncounterInfo *mpPulseEncounterInfo;
    float mfPulseEncounterActiveTime;
    cTkSmartResHandle mPulseEncounterResource;
    TkAddNodesHandle mPulseEncounterAddNodeHandle;
    TkHandle mPulseEncounterNode;
    TkHandle mPulseEncounterMarkerNode;
    float mfPulseEncounterObjectSpawnScale;
    cGcAIShipSpawn *mpPulseEncounterTraderShipSpawn;
    float mfPulseEncounterOverrideChance;
    TkID<256> mPulseEncounterCustomHailMessage;
    cTkMatrix34 mPulseEncounterSpawnMatrix;
    bool mbPulseEncounterSilentOverride;
    std::pair<TkID<128>, cTkSeed> mPulseEncounterIDSeed;
    float mfPusleEncounterSpawnEffectTimer;
    cTkMatrix34 mPulseEncounterSpawnEffectOriginMatrix;
    ePulseEncounterState meBackgroundSpaceEncounterState;
    const cGcBackgroundSpaceEncounterInfo *mpBackgroundSpaceEncounterInfo;
    cTkSmartResHandle mBackgroundSpaceEncounterResource;
    TkHandle mBackgroundSpaceEncounterNode;
    float mfBackgroundSpaceEncounterActiveTime;
    float mfExtremeWantedEscalator;
    robin_hood::detail::Table<
        true, 80, cTkAttachmentPtr, cTkAttachmentPtr, robin_hood::hash<cTkAttachmentPtr, void>,
        std::equal_to<cTkAttachmentPtr>>
        maRepairTargets;
    cGcSentinelInfo maCombatSquad;
    cGcPlayerExperienceDirector::eCombatSquad meCombatSquad;
    float mfCombatSquadTimer;
    cTkVector3 mCombatBasePos;
    bool mbCombatSquadDeployNotified;
    bool mbInvestigateMessageShown;
    bool mbFinalWaveRewardRequested;
    float mfFireRateModifierScore;
    float mfCrimeBlockedTimer;
    robin_hood::detail::Table<
        1, 80, cTkAttachmentPtr, TkID<128>, robin_hood::hash<cTkAttachmentPtr, void>, std::equal_to<cTkAttachmentPtr>>
        maPendingSentinelSummons;
    cGcFiendManagerStandard mFiendManagerPlanet;
    cGcFiendManagerStandard mFiendManagerMission;
    cGcFiendManagerUnderwater mFiendManagerUnderwater;
    cGcFiendManagerStandard mFiendManagerFreighter;
    cGcFiendManagerStandard mFiendManagerSpace;
    cTkVector<cTkSmartResHandle> maSentinelResources;
    cTkSmartResHandle mSentinelCoverRes;
    cTkSmartResHandle mFiendRes;
    cTkSmartResHandle mScuttlerRes;
    cTkSmartResHandle mFloaterRes;
    cTkSmartResHandle mSpaceFloaterRes;
    cTkSmartResHandle mFreighterSlugRes;
    cTkSmartResHandle mMiniDroneRes;
    cTkSmartResHandle mFishFiendBigRes;
    cTkSmartResHandle mFishFiendSmallRes;
    cGcResourceElement mRockCreatureRes;
    cGcResourceElement mGroundWormRes;
    cTkSmartResHandle mGroundWormSpawnerRes;
    cTkVector<cGcPlayerExperienceDirector::cGcArchetypeResource> mArchetypeResources;
    cGcPlayer *mpPlayer;
    cGcExperienceSpawnTable *mpSpawnTable;
    cTkVector<cTkAttachmentPtr> maRobots;
    cTkVector<cGcPlayerExperienceDirector::TrailerShipData> maTrailerShips[2];
    cTkClassPoolHandle maTrailerShipSquads[2];
    cTkVector<cTkAttachmentPtr> maTrailerMechs;
    cTkVector<cTkSmartResHandle> maTrailerMechResources;
    cTkVector<cTkAttachmentPtr> maTrailerNPCs;
    cTkVector<cTkSmartResHandle> maTrailerNPCResources;
    cTkVector<cTkSmartResHandle> maTrailerNPCBackpackResources;
    cTkVector<cTkAttachmentPtr> maTrailerNPCPets;
    cTkVector<sOwnedCreatureInfo> maTrailerNPCPetData;
    cTkSmartResHandle mTrailerNPCNavArea;
    cTkVector<cTkAttachmentPtr> maTrailerCreatures;
    int miSelectedTrailerCreature;
    cTkPersonalRNG mExperienceRNG;
    bool mDirectorEnabled;
    bool mbAllowPiratesDuringMPMissions;
    bool mbFiendsActive;
    float mfLastActiveFiendCombatTime;
    float mfLastActiveLocalFiendCombatTime;
    bool mbRewardEncounterActive;
    bool mbGroundWormsActive;
    float mfAlienPodAggroFactor;
    cTkSmoothCD<float> mfAlienPodAggroFactorSmoothed;
    float mfLastAlienPodAggroSetTime;
    TkAudioObject mAudioObject;
    int miAmbientSelect;
    float mfAmbientTimer;
    bool mbAllowAmbientFreighters;
    bool mbSpaceBattleRequested;
    bool mbSpaceBattleFlybyRequested;
    bool mbSpaceBattleSunResposition;
    float mfBattleFlyByDelay;
    int miMissionTradersRequested;
    bool mbSpaceBattleActive;
    int miSpaceBattleLevel;
    cTkMatrix34 mSpaceBattleMatrix;
    bool mbSpaceBattlePosGenerated;
    float mfBattleStartTime;
    int miNumSquadsOverride;
    TkID<128> mAttackDefinitionOverride;
    TkID<256> mRewardMessageOverride;
    bool mbPirateAttackSilent;
    float mfPirateAttackDistanceOverride;
    bool mbBlockNextCargoScan;
    float mfLastTraderDialogueStart;
    float mfLastTraderDialogueEnd;
    float mfTraderDialogueWait;
    float mfEndOfSeasonAlertDelay;
    bool mbForceSeasonEnd;
    cTkClassPoolHandle mSpaceBattleFreighterSquad;
    ePirateSpawn meRequestPirateSpawnType;
    ePreviousExperienceLocation mePreviousExperienceLocation;
    cGcVehicleCheckpointManager *mpVehicleRace;
    cTkClassPoolHandle mDebugInputMaskHandle;
    int miDebugDroneStage;
    bool mbDebugFlyby;
    int miRecordNPCWaypoints;
    int miRecordCreatureWaypoints;
    bool mbRecordPlayerRideWaypoints;
    float mfDebugSceneAutoSaveTimer;
    cGcPlayerExperienceDirector::eDebugCameraState meDebugCameraState;
    int miSelectedCamera;
    int miDisableCameraSmoothingFrames;
    bool mbDebugCameraSpin;
    float mfDebugCameraSpinTimer;
    bool mbDebugRepositionPlanets;
    cGcDebugScene *mpDebugScene;
    TkID<128> mDebugSpawnSentinelWave;
    robin_hood::detail::Table<
        false, 80, unsigned int, std::function<void __cdecl(cGcExperienceDebugTriggerAction const *, bool)>,
        robin_hood::hash<unsigned int, void>, std::equal_to<unsigned int>>
        mDebugTriggers;
    cGcRpcCallBase *WANT;
    cGcRpcCallBase *RPJB;
    cGcRpcCallBase *BGBR;
};

SKYSCRAPER_END