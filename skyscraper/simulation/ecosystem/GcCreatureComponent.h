#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/source/simulation/ecosystem/gccreaturecomponentdata.meta.h>
#include <metadata/source/simulation/ecosystem/creatures/gccreaturedata.meta.h>
#include <metadata/source/simulation/ecosystem/gccreatureroledata.meta.h>

SKYSCRAPER_BEGIN

class cGcCreatureComponent : public cTkComponent
{
	cGcCreatureComponentData* mpData;
	cGcOwnerConcept mOwner;
	cGcCreatureData* mpCreatureData;
	cGcCreatureRoleData* mpRoleData;
	int miRoleIndex;
	bool mbClonedForFur;
	cTkVector<cTkSmartResHandle> maClonedFurHandles;
	int miHarvestingProductIndex;
	int miKillingProductIndex;
	eCreatureType mType;
	eCreatureRole mRole;
	eCreatureSizeClass mSize;
	eCreatureSizeClass mAdultSize;
	eCreatureSizeClass mRidingSize;
	TkHandle mHead;
	TkHandle mRidingNode;
	cTkMatrix34 mRidingInvBindRot;
	cTkVector3 mvRidingPostionOffset;
	cTkVector3 mvRidingRotationOffset;
	cTkVector3 mvRidingFirstPersonOffset;
	float mfRidingRelativeScale;
	float mfRidingLegSpreadOffset;
	float mfRidingLeanFwd;
	int miRidingAnimationPartModifier;
	TkHandle mTargetPoint;
	TkHandle mLabelPoint;
	TkAudioObject mAudioObject;
	cGcMarkerPoint mMarkerPoint;
	TkHandle mNodeTransformingFrom;
	TkHandle mAttachedNode;
	int miNumAttachAttempts;
	cGcCreatureBehaviourTree* mpBehaviourTree;
	cGcRobotBehaviourTree* mpRobotTree;
	cTkPhysicsComponent* mpPhysics;
	cTkAnimationComponent* mpAnimation;
	cGcCreatureFullBodyIKComponent* mpIk;
	cTkRandomComponent* mpRandomer;
	cTkRandomComponentData mRandomerData;
	cGcCreatureVocals* mpVocals;
	cGcCreaturePerception* mpPerception;
	cGcCreatureRoutinePtr mpRoutine;
	cTkAttachmentPtr mFeedingAttachment;
	cTkAttachmentPtr mPetInteractionAttachment;
	cGcFadeNode* mpFadeNode;
	float mfSpeedMultiplier;
	cGcCreatureComponent::LookInfo* mpLookInfo;
	cTkPhysRelVec3 mvPrevPushPos;
	cTkVector3 mvSavedInteractionPos;
	cTkPhysRelVec3 mvSavedInitialPos;
	float mfScaler;
	float mfMatScale;
	float mfSizeValue;
	cGcCreatureNavigation* mpNavigation;
	cGcCreatureMovementBase* mpMovementMode;
	cTkSmartResHandle mExtraResource;
	cGcNavPolyHandle mNavHint;
	unsigned __int8 muPreferredRegionLOD;
	bool mbRegionLODFound;
	unsigned int miFrameCount;
	unsigned __int64 mRegionId;
	float mfLifetime;
	float mfBoredOfPlayer;
	float mfPanickedTime;
	cTkAABB mBaseOBB;
	cTkFixedString<128, char>* mpChatter;
	cTkFixedString<128, char>* mpError;
	float mfChatterTime;
	float mfErrorTime;
	float mfHitTime;
	eAttitudeTowardsPlayer meAttitudeTowardsPlayer;
	eFriendlyAttitude meFriendlyAttitude;
	float mfLastDecalTime;
	float mfLastFeedingTime;
	float mfRagdollTime;
	float mfHealRequestDealy;
	float mfSpawnTime;
	int miFeedingTasksToDo;
	int miEatenAmount;
	cGcCreatureGUID mCreatureGUID;
	float mfEnergy;
	float mfHarvestCooldown;
	TkID<128> mFeedingProduct;
	bool mbInPoopPhase;
	int miOverrideHealth;
	TkID<128> mOverrideDamage;
	EgInstancedModelExtension::GrassPusher mGrassPusher;
	bool mbGrassPusherRegistered;
	const cGcPlayerExperienceSpawnData* mpExperienceSpawnData;
	cGcCreatureSwarmDataParams* mpSwarmParams;
	cGcCreatureHoverMovementDataParams* mpHoverParams;
	cGcCreatureComponent::sAccessoryInfo maAccessories[3];
	ePetAccessoryState meLastAccessoryState;
	float mfLastAccessoryStateChangeTime;
	int miPetIndex;
	cTkStackVector<cGcCreatureComponent::DissolveEffectItem, 32, -1> mDissolveEffectItems;
	cGcCreatureComponent::eDissolveMode meDissolveMode;
	float mfDissolveTime;
	cGcCreatureComponent::<unnamed_type_mFlags> mFlags;
	std::vector<float, TkSTLAllocatorShim<float, 4, -1> > mRagdollContactTimes;
};

SKYSCRAPER_END