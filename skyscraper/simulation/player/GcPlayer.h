/**
 * @file GcPlayer.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <graphics/camera/behaviours/GcCameraBehaviourFirstPerson.h>
#include <simulation/player/GcCharacterSit.h>
#include <simulation/player/GcPersonalTeleporter.h>
#include <simulation/player/GcPlayerCommon.h>
#include <simulation/player/GcPlayerEmoteProp.h>
#include <simulation/player/GcPlayerHazard.h>
#include <simulation/player/GcPlayerImpact.h>
#include <simulation/player/GcPlayerInteract.h>
#include <simulation/player/GcPlayerLadderClimb.h>
#include <simulation/player/GcPlayerRespawn.h>
#include <simulation/player/GcPlayerThirdPerson.h>
#include <simulation/player/attachments/GcPlayerAim.h>
#include <simulation/player/attachments/GcPlayerCommunicator.h>
#include <simulation/player/attachments/GcPlayerWeapon.h>
#include <simulation/spaceship/GcSpaceShipWarp.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/utilities/containers/TkDeque.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/ecosystem/creatures/gccreaturetypes.meta.h>

SKYSCRAPER_BEGIN

enum eEmoteState
{
    EEmoteState_None,
    EEmoteState_Playing,
    EEmoteState_Playing_Sit,
};

struct sGrabbedObjectInfo
{
    cTkPhysRelMat34 mGrabMatrix;
    const /*cGcGrabbableComponent*/ uintptr_t *mpGrabbedComponent;
    float mfMovementCompletion;
    int miDataIndex;
    bool mbIsAttached;
    bool mbGrabToggleActive;
    float mfGrabTime;
};

class cGcPlayer : public cGcPlayerCommon
{
  public:
    enum eRocketBootsDoubleTapState
    {
        None,
        WaitingForRelease,
        WaitingForSecondTap,
        SingleTap,
        DoubleTap,
    };

    enum eStaminaState
    {
        EStamina_Available,
        EStamina_Recovering,
    };

    enum PlayerMode
    {
        Unknown,
        InShip,
        OnSurface,
    };

    enum eRocketBootsState
    {
        Inactive,
        WindUp,
        Boost,
        Drift,
        Landing,
    };

    enum eCharacterMode
    {
        ECharacterMode_FirstPerson,
        ECharacterMode_ThirdPerson,
    };

    struct FootstepOnDistanceTravel
    {
        cTkPhysRelVec3 mLastUsedPosition;
        float mfTriggerDistance;
        float mfTriggerDistanceSqr;
        bool mbValidDistance;
        bool mbValidPosition;
    };

    struct cGcSummonPetData
    {
        int miIndex;
        float mfAdultScale;
        float mfGrowthProgress;
        cTkMatrix34 mSpawnMat;
        eCreatureType meCreatureType;
        cTkSeed mBoneScaleSeed;
        bool mbHasFur;
        cTkSmartResHandle mPetResource;
    };

    cTkRigidBody *lpGrabbedBody;
    cGcPlayerThirdPerson *mpThirdPerson;
    cGcCameraBehaviourFirstPerson *mpCamera;
    cGcPlayerController *mpController;
    cTkHavokCharacterController *mpPhysicsController;
    cTkAttachmentPtr mpExternalControlAttachment;
    eCharacterPhysicsDisabledReasons muGravityDisabledReasons;
    eCharacterPhysicsDisabledReasons muCollisionDisabledReasons;
    cTkAttachmentPtr mpGrabbedBy;
    float mfLastGrabbedTime;
    float mfGrabEscapeTimer;
    /*cGcPlayerEffectsComponent*/ uintptr_t *mpEffectsComponent;
    /*cGcPlayerFullBodyIKComponent*/ uintptr_t *mpIkComponent;
    cTkPhysRelMat34 mGraphicsMatrix;
    cTkVector3 mPosition;
    cTkVector<cGcPlayerImpact> maProjectileImpacts;
    TkHandle mEquipmentNode;
    cTkSmartResHandle mPlayerResource;
    cTkUnorderedMap<TkID<128>, cTkSmartResHandle, TkIDUnorderedMap::Hash128> mCreatureFoodResources;
    float mfThrowFoodCooldown;
    TkAudioObject mAudioObject;
    cGcPlayerWeapon mWeapon;
    float mfRecoilSpeed;
    float mfRecoilAmount;
    float mfDamagePerSecondRate;
    cGcWarpJumpTarget mPlayerWarpJumpTarget;
    cGcTeleportEndpoint mPlayerTeleportEndpoint;
    uint8_t meWarpTargetMode[4];
    cTkBitArray<unsigned int, 1, 32> mxMapRequests;
    cTkBitArray<unsigned int, 1, 32> mPostWarpRequests;
    cTkPhysRelMat34 mHandMatrix[2];
    cTkPhysRelMat34 mPreviousHandMatrix[2];
    cTkMatrix34 mLastHandMatrixOffset[2];
    cTkPhysRelMat34 mSmoothHandMatrix[2];
    cTkMatrix34 mFingerFromHandOffset[2];
    bool mbHandMatrixValid[2];
    bool mbReleaseGrabbable[2];
    cTkPhysRelVec3 mSwimHandPos[2];
    cTkVector3 mSwimAccumulator[2];
    bool mbSwimHandPosActive[2];
    bool mbHandTrackingMotionEnabled;
    cGcPersonalTeleporter mTeleporter;
    bool mbSpawned;
    bool mbLanded;
    bool mbRunning;
    float mfHardLandTimer;
    bool mbIsAutoWalking;
    bool mbWeaponSuppressed;
    cTkVector3 mCurrentMoveForce;
    cGcPlayerAim mAiming;
    cGcPlayerStick mStick;
    float mfLastHitTime;
    cTkAttachmentPtr mpLastHitOwner;
    TkID<128> mLastHitDamageId;
    float mfLastWoundTime;
    cTkVector3 mLastHitDir;
    cTkPhysRelVec3 mLastPosition;
    float mfLastDamageTime;
    float mfWoundDamageAccumulator;
    TkID<128> mLastDamageId;
    cTkVector3 mfPullCamToward;
    float mfCamPullStrength;
    float mfCamPullDecay;
    bool mbCamHorizontalOnly;
    float mYawPull;
    cTkVector3 mFacingDir;
    float mfLastFacingImpulse;
    float mfPitch;
    float mfCreatureRideYaw;
    bool mbTurning;
    bool mbMoving;
    uint8_t meCreatureRideState[4];
    cTkPhysRelVec3 mSmoothedPos;
    std::array<cTkVector3, 4> mLastVelocities;
    bool mbFoot;
    float mfBobAmount;
    int miGroundMat;
    bool mbJetpackIgnite;
    bool mbJetpackStart;
    float mfJetpackTimer;
    float mfJetpackTank;
    uint8_t mbFreeJetpack[4];
    float mfJetpackUpForce;
    float mfJetpackForce;
    float mfJetpackIgnitionForce;
    float mfJetpackUpBoost;
    float mfJetpackForwardBoost;
    float mfJetpackIgnitionBoost;
    float mfJetpackFreeDuration;
    float mfJetpackBoostTimer;
    bool mbJetpackBoostOverride;
    bool mbJetpackHeld;
    float mfRequiredJetpackRefillLevel;
    float mfFreeSprintTimer;
    float mfFreeSprintDuration;
    bool mbSprintIsFree;
    float mfAirTimer;
    float mfJetpackLandedTime;
    cTkClassPoolHandle mJetpackShake;
    cTkClassPoolHandle mRocketBootsShake;
    cTkClassPoolHandle mRunShake;
    cTkClassPoolHandle mWarpTransitionShake;
    float mfActionTimer;
    bool mbActionRequiresButtonUp;
    bool mbJumpRequiresButtonUp;
    bool mbInteractBlockingAction;
    bool mbPreviouslyCouldNotFire;
    bool mbAltStarted;
    cGcPlayerHazard mHazard;
    cGcPlayerInteract mInteract;
    cGcPlayerRespawn mRespawn;
    cGcPlayerLadderClimb mLadderClimb;
    cGcCharacterSit mCharacterSit;
    cTkTimerTemplate<0> mUnderwaterTimer;
    float mfRandomUnderwaterValue;
    cGcPlayer::eStaminaState meStaminaState;
    float mfStamina;
    float mfTurnAccelerator;
    bool mbIsTransitioning;
    cTkAttachment *mpAttachment;
    cTkSmartResHandle mAnimHeadSceneRes;
    TkHandle mAnimHeadSceneNode;
    cTkAnimationComponent *mpAnimHeadAnimation;
    cTkAnimLayerHandle mHeadAnimLayer;
    cTkMatrix34 mAnimHeadBaseTrans;
    cTkMatrix34 mHeadMatrixWhenMovementStarted;
    float mfExertion;
    float mfExertionRate;
    float mfDampShoes;
    float mfHitReactFadeSpeed;
    cTkVector2 mHitReactDir;
    cGcPlayer::PlayerMode mePlayerMode;
    bool mbIsDying;
    bool mbModRandomiseWeapon;
    cTkFixedString<128, char> mbModResetWithSeed;
    float mfShieldChargeAccumulator;
    float mfShipShieldRechargeAccumulator;
    float mfLaunchThrustersAccumulator;
    float mfEnergyAccumulator;
    float mfEnergyPainTime;
    float mfLastScanTime;
    float mfLastShipScanTime;
    bool mbAimToggleActive;
    bool mbAimHeld;
    bool mbAimBeingHeld;
    bool mbHasFired;
    bool mbTorchActive;
    bool mbToggleTorch;
    bool mbTorchLightNeeded;
    TkHandle mTorchNode;
    cTkSmoothCD<cTkVector3> mvTorchDir;
    TkHandle mAmbientLightNode;
    cTkPhysRelVec3 mLookAtPoint;
    bool mbForceLookAt;
    float mfLookAtTimeLeft;
    float mfLookAtTime;
    float mTimeLastUsedJetpack;
    float mfTimeInMeleeBoost;
    bool mbMeleeBoostActive;
    float mfTimeOnGround;
    float mfTimeRocketBootsActive;
    float mfRocketBootsBoostStrength;
    float mfRocketBootsHeightAdjust;
    float mfRocketBootsHeightAdjustVel;
    cGcPlayer::eRocketBootsState meRocketBootsState;
    float mfRocketBootsDoubleTapTimer;
    uint8_t meRocketBootsDoubleTapState[4];
    TkAudioID mCurrentSwimAudioEvent;
    TkID<128> mDebugDamageType;
    TkHandle mDeathDropNode;
    cTkDeque<cTkAttachmentPtr> maFriendlyCreatures;
    cTkVector<cTkAttachmentPtr> maPredatorsAttacking;
    float mfTimeSicePredatorAttacked;
    cGcPlayer::FootstepOnDistanceTravel mLadderFootsteps;
    float mfDisabledTimer;
    float mfTimeUntilBodyRealignment;
    uint8_t muiCheckFallenThroughFloorCounter;
    cGcPlayerCommunicator mCommunicator;
    int meSavedFilter;
    int meRequestedFilter;
    cGcPlayer::eCharacterMode meCharacterMode;
    cGcPlayer::eCharacterMode meRequestedCharacterMode;
    cTkVector<std::pair<TkID<128>, enum cGcPlayer::eCharacterMode>> maCharacterModeOverrides;
    uint8_t mCurrentSlopeState[4];
    float mfTimeInCurrentSlopeState;
    cTkMatrix34 maRealignmentTransform[2];
    cTkMatrix34 maLastControllerTransform[2];
    cTkSmoothCD<float> maHandControllersFade[2];
    TkHandle maHandControllers[2];
    TkHandle maHandCollisionNodes[2];
    cTkMatrix34 maGrabChangedMatrix[2];
    cTkMatrix34 maLastGoodGrabTransform[2];
    sGrabbedObjectInfo maPreviousGrabbable[2];
    float mafGrabTimer[2];
    bool mabClenchingFist[2];
    sGrabbedObjectInfo maCurrentGrabbable[2];
    uint64_t mauPointingStartTime[2];
    uint64_t mauPointingEndTime[2];
    cTkVector3 mPlayerShift;
    cTkVector3 mFrameShift;
    bool mbPendingFrameShift;
    eAlienRace meRace;
    bool mbHeadAnimationInProgress;
    eEmoteState meEmoteState;
    cGcPlayerEmoteProp mEmoteProp;
    bool mbIsTargetingUnscannedPlanet;
    cTkPhysRelMat34 mmCurrentTargetPlacement;
    float mfShipRadiusCached;
    float mfFreighterMegaWarpTimer;
    uint64_t mu64LastAutoSaveTimeStamp;
    cGcPlayer::cGcSummonPetData mSummonPetData;

    void SetToPosition(const cTkVector3 *lPos, const cTkVector3 *lDir, const cTkVector3 *lVel);
};

SKYSCRAPER_END