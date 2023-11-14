#pragma once

#include <skyscraper.h>

#include <simulation/GcCharacterInterface.h>
#include <simulation/components/gameplay/interaction/GcInteractionInterface.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <utilities/animation/GcSimpleAnimationQueue.h>

#include <reality/gcalienmood.meta.h>
#include <simulation/components/gameplay/gcnpccomponentdata.meta.h>
#include <simulation/player/gcscaneffectdata.meta.h>

SKYSCRAPER_BEGIN

struct cGcNPCComponent : cTkComponent, cGcCharacterInterface
{
    enum eHoloState
    {
        EHoloState_Init,
        EHoloState_Inactive,
        EHoloState_Active,
        EHoloState_Deactivating,
    };

    struct PropInfo
    {
        TkHandle mNode;
        bool mbVisible;
        cTkSmoothCD<float> mScale;
        float mfDelayTimer;
        TkHandle mLightNode;
        TkHandle mScanEffectNode;
        float mfdefaultLightIntensity;
    };

    cGcNPCComponentData *mpData;
    cGcSimpleAnimationQueue mBaseAnimQueue;
    cGcSimpleAnimationQueue mOverlayAnimQueue;
    TkAudioObject mAudioObject;
    cGcLoopingHelper mAlienChatter;
    cGcScanEffectData *mpHoloEffectLookup;
    cGcScanEffectData mHoloEffectData;
    TkHandle mHoloEffectBaseNode;
    cGcNPCComponent::eHoloState meHoloEffectState;
    float mfHoloEffectTimer;
    int miHoloEffectUpdateDelay;
    TkHandle mNPCModelNode;
    bool mbAllowedToMove;
    bool mbIsRunning;
    float mfSpineAdjustStrength;
    bool mbLookAtActive;
    cTkVector3 mvLookAtPoint;
    cTkReplicatedVariable<signed char> mActiveProp;
    bool mbMobile;
    bool mbIsSitting;
    bool mbHoldingProp;
    TkID<128> mCurrentIdle;
    TkID<128> mLastFlavourIdle;
    eMood meMood;
    cGcNPCComponent::PropInfo maProps[13];
    float mfHoldingPropTimer;
    cTkAttachmentPtr mpShipAttachment;
    TkHandle mPlacementSpawnNode;
    cTkHavokCharacterController *mpPhysicsController;
    cGcNPCBehaviourTree *mpBehaviourTree;
    eCharacterPhysicsDisabledReasons muGravityDisabledReasons;
    eCharacterPhysicsDisabledReasons muCollisionDisabledReasons;
    cTkPhysRelVec3 mSmoothedPos;
    cTkVector3 mCurrentMoveForce;
    cTkPhysRelMat34 mGraphicsMatrix;
    cTkVector3 mFacingDir;
    float mfHeight;
    float mfRaceScale;
    float mfFlavourIdleAnimTimer;
    cGcCharacterSit mCharacterSit;
    cTkRaycastJob mRayJob;
    cGcCreatureSteering mSteering;
    bool mbDebugDrawSteering;
    bool mbBreakOnUpdate;
    cGcNPCComponent::NPCPerception mPerception;
    eAlienRace meSetAudioRace;
    cTkAttachmentPtr mpFreighterBaseAttachment;
    eFreighterNPCType meFreighterNPCType;
    TkID<128> mOverrideBehaviourTree;
    bool mbExternallyManageVisibility;
    cTkStackVector<cGcNPCComponent::DissolveEffectItem, 8, -1> mDissolveEffectItems;
    cGcNPCComponent::eDissolveMode meDissolveMode;
    float mfDissolveTime;
    cTkAttachmentPtr mNPCNavAreaAttachment;
    cGcNPCInteractiveObjectComponent *mpNPCInteraction;
    cTkAnimationComponent *mpAnimation;
    bool mbTurnToFacePlayer;
    TkID<128> mIdleAnim;
    cTkAnimLayerHandle mHandPoseLayer;
    TkHandle mHandSocket;
    unsigned __int64 mPlacementID;
    unsigned __int64 mUA;
    const cTkDynamicArray<TkID<128>> *mpaHideDuringMissions;
    EgInstancedModelExtension::GrassPusher mGrassPusher;
    bool mbGrassPusherRegistered;
    bool mbShowDebugTrail;
    cGcDebugMovementTrail *mpDebugTrail;
};

SKYSCRAPER_END