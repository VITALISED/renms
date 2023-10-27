/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <simulation/player/GcPlayerCommon.h>
#include <simulation/player/GcPlayerThirdPerson.h>
#include <simulation/player/GcPlayerImpact.h>
#include <simulation/player/attachments/GcPlayerWeapon.h>
#include <simulation/CharacterPhysicsDisabledReasons.h>
#include <simulation/GcWarpJumpTarget.h>
#include <simulation/player/GcPlayerAim.h>
#include <simulation/player/GcPersonalTeleporter.h>
#include <simulation/player/GcPlayerHazard.h>
#include <graphics/camera/behaviours/GcCameraBehaviourFirstPerson.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <metadata/gamestate/gcteleportendpoint.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayer : public cGcPlayerCommon
{
public:
    enum eRocketBootsDoubleTapState
    {
        None,
        WaitingForRelease,
        WaitingForSecondTap,
        SingleTap,
        FEEDBACK_PEN_DOUBLETAP,
    };

    //this shit is so real
    typedef cGcPlayer::eRocketBootsDoubleTapState WarpTargetMode;
    typedef cGcPlayer::eRocketBootsDoubleTapState eCreatureRideState;
    typedef cGcPlayer::eRocketBootsDoubleTapState eFreeJetpackSurface;

    cTkRigidBody* lpGrabbedBody;
    cGcPlayerThirdPerson* mpThirdPerson;
    cGcCameraBehaviourFirstPerson* mpCamera;
    cGcPlayerController* mpController;
    cTkHavokCharacterController* mpPhysicsController;
    cTkAttachmentPtr mpExternalControlAttachment;
    eCharacterPhysicsDisabledReasons muGravityDisabledReasons;
    eCharacterPhysicsDisabledReasons muCollisionDisabledReasons;
    cTkAttachmentPtr mpGrabbedBy;
    float mfLastGrabbedTime;
    float mfGrabEscapeTimer;
    cGcPlayerEffectsComponent* mpEffectsComponent;
    cGcPlayerFullBodyIKComponent* mpIkComponent;
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
    cGcPlayer::WarpTargetMode meWarpTargetMode;
    cTkBitArray<unsigned int, 32> mxMapRequests;
    cTkBitArray<unsigned int, 32> mPostWarpRequests;
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
    eCreatureRideState meCreatureRideState;
    cTkPhysRelVec3 mSmoothedPos;
    std::array<cTkVector3, 4> mLastVelocities;
    bool mbFoot;
    float mfBobAmount;
    int miGroundMat;
    bool mbJetpackIgnite;
    bool mbJetpackStart;
    float mfJetpackTimer;
    float mfJetpackTank;
    eFreeJetpackSurface mbFreeJetpack;
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
    cTkAttachment* mpAttachment;
    cTkSmartResHandle mAnimHeadSceneRes;
    TkHandle mAnimHeadSceneNode;
    cTkAnimationComponent* mpAnimHeadAnimation;
    cTkAnimLayerHandle mHeadAnimLayer;
    cTkMatrix34 mAnimHeadBaseTrans;
    cTkMatrix34 mHeadMatrixWhenMovementStarted;
    float mfExertion;
    float mfExertionRate;
    float mfDampShoes;
    float mfHitReactFadeSpeed;
    cTkVector2 mHitReactDir;
    unsigned char mePlayerMode[4];
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
    cGcPlayer::eRocketBootsDoubleTapState meRocketBootsDoubleTapState;
    TkAudioID mCurrentSwimAudioEvent;
    TkID<128> mDebugDamageType;
    TkHandle mDeathDropNode;
    std::deque<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr, 8, -1> > maFriendlyCreatures;
    cTkVector<cTkAttachmentPtr> maPredatorsAttacking;
    float mfTimeSicePredatorAttacked;
    cGcPlayer::FootstepOnDistanceTravel mLadderFootsteps;
    float mfDisabledTimer;
    float mfTimeUntilBodyRealignment;
    unsigned __int8 muiCheckFallenThroughFloorCounter;
    cGcPlayerCommunicator mCommunicator;
    int meSavedFilter;
    int meRequestedFilter;
    cGcPlayer::eCharacterMode meCharacterMode;
    cGcPlayer::eCharacterMode meRequestedCharacterMode;
    cTkVector<std::pair<TkID<128>, cGcPlayer::eCharacterMode> > maCharacterModeOverrides;
    CharacterSlopeState mCurrentSlopeState;
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
    unsigned __int64 mauPointingStartTime[2];
    unsigned __int64 mauPointingEndTime[2];
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
    unsigned __int64 mu64LastAutoSaveTimeStamp;
    cGcPlayer::cGcSummonPetData mSummonPetData;
    bool mbShowOneContact;
    int miContactToShow;
    int miNumContactsToShow;
};

SKYSCRAPER_END