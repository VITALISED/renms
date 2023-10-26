#pragma once

#include <skyscraper.h>
#include <graphics/ngui/GcNGui.h>
#include <toolkit/attachments/TkAttachment.h>

SKYSCRAPER_BEGIN

class cGcPlayer;

enum ePlayerInteraction
{
	EPlayerInteraction_None = -1,
	EPlayerInteraction_HoldButton,
	EPlayerInteraction_Shoot,
	EPlayerInteraction_Tap,
	EPlayerInteraction_NumTypes,
};

enum ePlayerInteractIcon
{
	EPlayerInteractIcon_Hold,
	EPlayerInteractIcon_Mine,
	EPlayerInteractIcon_Shoot,
	EPlayerInteractIcon_Deconstruct,
	EPlayerInteractIcon_Armour,
	EPlayerInteractIcon_NumTypes,
};

class cGcTargetHelper
{
	struct InteractLabelMarker
	{
		cTkRigidBodyPtr mpBody;
		cGcCreatureComponent* mpCreature;
		TkHandle mLocator;
		bool mbTerrainResource;
	};

	ePlayerInteraction meTargetType;
	cTkAttachmentPtr mpCurrentTarget;
	cGcTargetHelper::InteractLabelMarker mCurrentTargetHelper;
	float mfFocusTargetTimer;
	bool mbValidInteraction;
	bool mbTargetInfoDynamic;
	ePlayerInteractIcon meIconType;
	cTkFixedString<127, char> mTargetName;
	cTkFixedString<256, char> mTargetSubtitle;
	cTkColour mTargetSubtitleColour;
	cTkFixedString<256, char> mTargetSubtitle2;
	cTkColour mTargetSubtitle2Colour;
	cTkPhysRelVec3 mLabelWorldPos;
	cTkVector4 mLabelScreenPos;
	cGcSimpleScanEffect mHighlight;
	cGcScanEffectData mHighlightData;
	TkHandle mHandInteractLight;
	float mfHandInteractLightIntensity;
	cTkSmoothCD<float> mHandInteractLightActiveFactor;
	float mfHandInteractLightActiveTarget;
	cTkVector4 mLabelScreenPosLeft;
	cTkVector4 mLabelScreenPosRight;
	cTkRaycastJob mRaycastJob;
};

class cGcPlayerInteract
{
	cGcPlayer* mpPlayer;
	cGcNGui mHoldGui;
	cGcTargetHelper mHoldHelper;
	cTkAttachmentPtr mpHoldTarget;
	cTkAttachmentPtr mpInteraction;
	TkHandle mHoldModel;
	TkHandle mHoldMasterModel;
	cGcPlayerInteract::eHoldMode meHoldMode;
	float mfHoldTimer;
	float mfErrorTimer;
	__declspec(align(16)) cGcMarkerRenderData mRenderData;
	cTkSmoothCD<float> mfHoldAlpha;
	cTkVector3 mNetworkLockPosition;
	bool mNetworkLockRequested;
	bool mbCanPickupHoldTarget;
	int meHoldInteractButton;
	cTkPhysRelVec3 mHandHoldStartPos;
	cTkVector3 mHandHoldDirOffset;
	bool mbHandHoldActive;
	bool mbHoldComplete;
	float mfLastGrabbableTargetTime;
	cGcSimpleScanEffect mDeconstructEffect;
	cGcNGui mShootGui;
	cGcTargetHelper mShootHelper;
	cTkRigidBodyPtr mpShootTarget;
	cGcPlayerInteract::eShootMode meShootMode;
	float mfShootHealth;
	cTkSmoothCD<float> mfShootAlpha;
	cGcTargetHelper mTapHelper;
	cGcPlayerInteract::eTapMode meTapMode;
	bool mbTapUp;
	TkAudioObject mAudioObject;
	bool mbHideOnRender;
	bool mbAllowedToInteractBasedOnVehicle;
	TkHandle mViewTarget;
	cTkRaycastJob mViewTargetRaycast;
};


SKYSCRAPER_END