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
#include <gamestate/GcPlayerShipOwnership.h>
#include <simulation/components/gameplay/GcCombatEffectsComponent.h>
#include <simulation/components/effects/GcPlayerEffectsComponent.h>
#include <graphics/camera/behaviours/GcCameraBehaviourCharacter.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/simulation/physics/TkPhysicsComponent.h>

SKYSCRAPER_BEGIN

class cGcPlayer;

class cGcPlayerThirdPerson
{
	typedef cGcPlayerShipOwnership::eMeshRefreshState eMeshRefreshState;

	enum eCharacterVisibility
	{
		InvisibleOnAllClients,
		ShowOnlyLocally,
		ShowOnlyOnRemotes,
		ShowOnlyOnRemotesShowShadowLocally,
		ShowLocallyAndRemotes,
	};

	float mTimeInCurrentState;
	cGcPlayer* mpPlayer;
	cGcCameraBehaviourCharacter* mpThirdPersonCamera;
	cGcPlayerCharacterComponent* mpCharacterComponent;
	cTkPhysicsComponent* mpPhysicsComponent;
	cTkSmartResHandle mThirdPersonModelRes;
	cTkSmartResHandle mBackpackModelRes;
	TkHandle mBackpackNode;
	TkHandle mThirdPersonNode;
	TkHandle mThirdPersonMeshNode;
	TkHandle mThirdPersonHeadMeshNode;
	TkHandle mThirdPersonHeadJointNode;
	TkHandle mWeaponNode;
	std::vector<TkID<128> > maForcingMeshHidden;
	std::vector<TkID<128> > maForcingMeshShown;
	cTkAABB mBackpackAABB;
	TkHandle maCharacterHoldingPoint[2];
	TkHandle maHandsNode[2];
	TkHandle maWristStumpNode[2];
	TkHandle maFingerPointNode[2];
	cTkMatrix34 maWristToController[2];
	cTkVector3 maWristToHoldingPoint[2];
	bool mabIsHandTracking[2];
	bool mbUsingHandControls;
	bool mbVRGhostMode;
	bool mbVRGhostModeChanged;
	bool mbForceMeshVisibilityUpdate;
	cGcPlayerThirdPerson::eCharacterVisibility mCurrentVisibility;
	bool mbShouldRefreshMesh;
	cGcPlayerThirdPerson::eMeshRefreshState mMeshRefreshState;
	cTkSmartResHandle mThirdPersonModelSwapRes;
	cGcPlayerThirdPerson::eMeshRefreshState mBackpackRefreshState;
	cTkSmartResHandle mBackpackSwapRes;
	cTkAttachment* mpAttachment;
	cTkVector3 mvLookAtPoint;
	float mfRoll;
	float mfPitch;
	float mfLookAtRunTimer;
	float mfLookAtGlanceTime;
	float mfLookAtTargetTimer;
	float mfLookAtTargetTime;
	cTkSmoothCD<float> mCameraNearFade;
	float mfVRCameraOffset;
	float mfNoBobVRCameraOffset;
	cTkSmoothCD<float> mfNoBobCameraBlend;
	cGcPlayerEffectsComponent* mpPlayerEffectsComponent;
	cGcCombatEffectsComponent* mpCombatEffectsComponent;
	TkHandle maControllerHandNodes[2];
};

SKYSCRAPER_END