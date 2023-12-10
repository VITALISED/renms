/**
 * @file TkNodeAnimationControllerEngine.h
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

#include <toolkit/data/TkMetaData.h>
#include <toolkit/maths/numeric/TkQuaternion.h>
#include <toolkit/system/timer/TkClock.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <metadata/toolkit/animation/blendtree/tkanimanimnode.meta.h>
#include <metadata/toolkit/animation/blendtree/tkanimblendnode.meta.h>
#include <metadata/toolkit/animation/tkanimationdata.meta.h>
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
        EBlendType_Blend       = (1 << 0),
        EVectorBlendBit        = (1 << 2),
        EBlendType_VectorBlend = EVectorBlendBit + 1,
        EBlendType_VectorAdd   = EVectorBlendBit + 2,
        E2dBlendBit            = (1 << 3),
        EBlendType_2dBlend     = E2dBlendBit + 1,
        EBlendType_2dAdd       = E2dBlendBit + 2,
    };

    cTkStackVector<short, 4> mIndices;
    int16_t miNumWeights;
    int16_t miBlendIndex;
    cTkAnimationBlend::eBlendType mBlendType;
};

class cTkAnimationBlendWeight
{
    TkID<128> mBlendId;
    const cTkMetaDataMember *mpWeightInput;
    const cTkAnimBlendNode *mpNodeData;
    float mfWeight;
    float mfWeightVel;
    bool mbIgnoreParamStruct;
    uint8_t miMemberOffset;
};

class cTkAnimationInstance
{
    cTkVector3 mvMoveAnimDelta;
    cTkQuaternion mvMoveAnimRotDelta;
    TkID<128> mInstanceId;
    TkID<128> mAnimName;
    const cTkAnimationData *mpAnimData;
    const cTkAnimAnimNode *mpNodeData;
    const cTkMetaDataMember *mpPhaseInput;
    cTkSmartResHandle mpAnimation;
    int miAnimIndex;
    int16_t miAnimMapping;
    int16_t miAdditiveBaseMapping;
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
    cTkClock *mpClock;
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
    cTkStackVector<cTkAnimationInstance, 1> maInstance;
    cTkAnimationWeight mWeight;
    cTkAnimationLayer *mpBlendingOverLayer;
    eAnimLayerState meState;
    cTkClock *mpClock;
    TkID<128> miLayerId;
    int miLayerPrio;
    int miAnimIndex;
    int miUniqueId;
    struct
    {
        int8_t mbReplicate : 1;
        int8_t mbCanBeRemovedEvenIfControl : 1;
        int8_t mbMirrored : 1;
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
    cTkStackVector<cTkAnimCommand, 16> mCommandBuffer;
    cTkStackVector<unsigned int, 16> mActiveStages;
    bool mbDirty;
    cTkBitArray<unsigned int, true, 32> mAnimChannelBitArray;
    std::array<cTkAnimationLayer, 16> maAnimLayer;
    TkHandle mModelNode;
    cTkAnimationData **mpaAnimData;
    cTkSmartResHandle *mpaAnimResources;
    int16_t *mpaAnimMappings;
    int miNumAnimations;
    cTkAnimBlendTree *mpaTreeData;
    int miNumTrees;
    cTkUnorderedMap<TkID<128>, TkID<128>, TkIDUnorderedMap::Hash128> mAlternateAnimations;
    cTkClock *mpClock;
    const void *mpParamStruct;
    const cTkMetaDataMember *mpParamMembers;
    float mfCurrentSpeed;
    int miCurrentLOD;
};

SKYSCRAPER_END