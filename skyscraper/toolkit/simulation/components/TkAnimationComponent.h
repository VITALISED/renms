/**
 * @file TkAnimationComponent.h
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

#include <toolkit/animation/engine/TkNodeAnimationControllerEngine.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

#include <metadata/toolkit/components/animation/tkanimationcomponentdata.meta.h>
#include <metadata/toolkit/enginesettings/tkanimdetailsettings.meta.h>

SKYSCRAPER_BEGIN

class cTkAnimationComponent;

template <int Length>
struct AnimLookup
{
    cTkAnimationComponent *mpAnim;
    cTkAnimInstanceHandle maAnimHandles[Length];
};

class cTkAnimationComponent : public cTkComponent
{
  public:
    struct AnimSnapshot
    {
        cTkStackVector<cTkAnimCommand, 16> lBuffer;
        uint64_t luTime;
    };

    cTkAnimationComponentData *mpData;
    cTkVector<cTkAnimCommand> mRemoteCommandBuffer;
    std::deque<cTkAnimationComponent::AnimSnapshot> mAnimSnapshots;
    cTkLinearHashTable<TkID<128>, int, cTkLinearHashTableHash<TkID<128>>> mAnimIdToIndexLookup;
    cTkNodeAnimationController mAnimationController;
    TkHandle mModelNode;
    bool mbAnimationLoaded;
    bool mbAnimationPrepared;
    bool mbBreakOnUpdate;
    bool mbIsModelViewerNode;
    bool mbDistanceCulled;
    eCreatureSize meCreatureSize;
    int16_t *mpAnimMappingsReverseLookup;
    cTkAnimDetailSettings *mpaDetailLevels;
    bool mbEverUpdated;
    unsigned int muAnimCullFrameMarker;
    float mfTimeSinceLastUpdateRecvd;
    cTkMatrix34 mRootMotionBuffer;
    bool mbRecordRootMotion;
    bool mDisableAnimation;
    bool mbShowAnimMirrorPairs;
};

SKYSCRAPER_END