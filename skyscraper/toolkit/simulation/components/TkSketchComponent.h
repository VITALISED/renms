/**
 * @file TkSketchComponent.h
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

#include <networking/components/GcNetworkComponent.h>
#include <toolkit/system/thread/TkSpinMutex.h>
#include <toolkit/utilities/containers/TkForwardList.h>
#include <toolkit/utilities/containers/TkStackVector.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <metadata/toolkit/components/tksketchcomponentdata.meta.h>

SKYSCRAPER_BEGIN

union sSketchValue {
    char mChars[16];
    unsigned __int64 mUInt64[2];
};

struct sSketchStack
{
    const unsigned int kiSizeIncrease;
    unsigned __int8 *mpStackBuffer;
    unsigned int mBufferPosition;
    unsigned int mBufferUsedBytes;
    unsigned int mBufferSizeBytes;
};

class cTkSketchComponent : public cGcNetworkComponent
{
    struct sVariable
    {
        sSketchValue mName;
        sSketchValue mValue;
    };

    struct sPendingVariable
    {
        sSketchValue mName;
        sSketchValue mNewValue;
        bool mbRequiresNetSync;
    };

    struct sPendingComponentEvent
    {
        unsigned __int64 muComponentHash;
        const char *macEventName;
        sSketchValue mValue;
    };

    struct sPendingBranch
    {
        unsigned int mStartNodeHandle;
        sSketchValue mInputValue;
        bool mbDebugStarted;
        sSketchStack mStackData;
    };

    struct sBranch
    {
        struct NodeInstance
        {
            unsigned int mNodeHandle;
            unsigned int mStackPointer;
            sSketchValue mInputValue;
            unsigned __int8 muCurrentOutput;
        };

        unsigned int mBranchHash;
        unsigned int mStartNodeHandle;
        cTkForwardList<cTkSketchComponent::sBranch::NodeInstance> mNodeStack;
        sSketchStack mStack;
        bool mbBranchStarted;
    };

    cTkVector<cTkSketchComponent::sVariable> mVariables;
    cTkStackVector<cTkSketchComponent::sPendingVariable> mPendingVariables;
    cTkStackVector<cTkSketchComponent::sPendingComponentEvent> mPendingComponentEvents;
    cTkVector<unsigned int> mNodes;
    sSketchStack mNodesBuffer;
    cTkSpinMutex mNodeAccessMutex;
    bool mbDestroyModel;
    float mfApproxSize;
    cTkStackVector<cTkSketchComponent::sPendingBranch> mPendingBranches;
    cTkVector<cTkSketchComponent::sBranch> mBranches;
    cTkSketchComponentData *mpData;
};

SKYSCRAPER_END