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
#include <toolkit/utilities/TkArray.h>
#include <toolkit/utilities/containers/TkStackVector.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/maths/numeric/TkQuaternion.h>
#include <toolkit/system/timer/TkClock.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <metadata/toolkit/animation/blendtree/tkanimblendnode.meta.h>
#include <metadata/toolkit/animation/tkanimationdata.meta.h>
#include <metadata/toolkit/animation/blendtree/tkanimanimnode.meta.h>
#include <metadata/toolkit/animation/tkanimblendtree.meta.h>

SKYSCRAPER_BEGIN

enum eAnimLayerState
{
	EAnimLayer_Inactive,
	EAnimLayer_BlendIn,
	EAnimLayer_BlendOut,
	EAnimLayer_Active,
	ENumLayerStates,
};

class cTkAnimLayerHandle
{
	int miChannelIndex;
	int miAnimIndex;
	int miUid;
};

class cTkAnimInstanceHandle
{
	cTkAnimLayerHandle mLayer;
	int miInstIndex;
	int miAnimDataIndex;
};

class cTkAnimationBlend
{
	enum eBlendType
	{
		EBlendType_Blend = (1 << 0),
		EVectorBlendBit = (1 << 2),
		EBlendType_VectorBlend = EVectorBlendBit + 1,
		EBlendType_VectorAdd = EVectorBlendBit + 2,
		E2dBlendBit = (1 << 3),
		EBlendType_2dBlend = E2dBlendBit + 1,
		EBlendType_2dAdd = E2dBlendBit + 2,
	};

	cTkStackVector<short> mIndices;
	__int16 miNumWeights;
	__int16 miBlendIndex;
	cTkAnimationBlend::eBlendType mBlendType;
};

class cTkAnimationBlendWeight
{
	TkID<128> mBlendId;
	const cTkMetaDataMember* mpWeightInput;
	const cTkAnimBlendNode* mpNodeData;
	float mfWeight;
	float mfWeightVel;
	bool mbIgnoreParamStruct;
	unsigned __int8 miMemberOffset;
};

class cTkAnimationInstance
{
	cTkVector3 mvMoveAnimDelta;
	cTkQuaternion mvMoveAnimRotDelta;
	TkID<128> mInstanceId;
	TkID<128> mAnimName;
	const cTkAnimationData* mpAnimData;
	const cTkAnimAnimNode* mpNodeData;
	const cTkMetaDataMember* mpPhaseInput;
	cTkSmartResHandle mpAnimation;
	int miAnimIndex;
	__int16 miAnimMapping;
	__int16 miAdditiveBaseMapping;
	float mfStartTime;
	float mfUnitTime;
	float mfSpeed;
	float mfAnimationFrame;
	float mfPrevAnimationFrame;
	float mfMoveAnimSpeed;
	bool mbMirrored;
	bool mbRestart;
	bool mbPartial;
	bool mbAdditive;
	bool mbHasAnimDelta;
	bool mbIgnoreParamStruct;
};

class cTkAnimationWeight
{
	cTkClock* mpClock;
	float mfWeight;
	float mfBlendWeightTarget;
	float mfBlendStartTime;
	float mfBlendDuration;
	eCurve miCurve;
	bool mbBlending;
};

class cTkAnimationLayer
{
	cTkVector<cTkAnimationBlend> maBlends;
	cTkVector<cTkAnimationBlendWeight> maWeights;
	cTkStackVector<cTkAnimationInstance> maInstance;
	cTkAnimationWeight mWeight;
	cTkAnimationLayer* mpBlendingOverLayer;
	eAnimLayerState meState;
	cTkClock* mpClock;
	TkID<128> miLayerId;
	int miLayerPrio;
	int miAnimIndex;
	int miUniqueId;
	struct
	{
		__int8 mbReplicate : 1;
		__int8 mbCanBeRemovedEvenIfControl : 1;
		__int8 mbMirrored : 1;
	} mFlags;
};

class cTkAnimCommand
{
	enum eCommandType
	{
		ECommandType_Invalid,
		ECommandType_WriteNilPose,
		ECommandType_WriteBindPose,
		ECommandType_EvalFrame,
		ECommandType_MirrorPose,
		ECommandType_Blend,
		ECommandType_Subtract,
		ECommandType_Add,
		ECommandType_AddReversed,
		ECommandType_Multiply,
		ECommandType_NlerpMultiply,
		ECommandType_NlerpAdd,
		ECommandType_NlerpComplete,
		ECommandType_NumCommands,
	};

	cTkAnimCommand::eCommandType mCmd;
	float mfParam;
	unsigned __int16 muAnim;
};

class cTkNodeAnimationController
{
	cTkStackVector<cTkAnimCommand> mCommandBuffer;
	cTkStackVector<unsigned int> mActiveStages;
	bool mbDirty;
	cTkBitArray<unsigned int, 32> mAnimChannelBitArray;
	std::array<cTkAnimationLayer, 16> maAnimLayer;
	TkHandle mModelNode;
	cTkAnimationData** mpaAnimData;
	cTkSmartResHandle* mpaAnimResources;
	__int16* mpaAnimMappings;
	int miNumAnimations;
	cTkAnimBlendTree* mpaTreeData;
	int miNumTrees;
	cTkUnorderedMap<TkID<128>, TkID<128>, TkIDUnorderedMap::Hash128> mAlternateAnimations;
	cTkClock* mpClock;
	const void* mpParamStruct;
	const cTkMetaDataMember* mpParamMembers;
	float mfCurrentSpeed;
	int miCurrentLOD;
};

SKYSCRAPER_END