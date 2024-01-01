/**
 * @file GcGalaxyTypes.h
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

#include <toolkit/graphics/TkColour.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>
#include <toolkit/utilities/containers/TkDeque.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcgalacticaddressdata.meta.h>
#include <simulation/galaxy/gcgalaxystarattributesdata.meta.h>
#include <simulation/galaxy/gcgalaxyvoxelattributesdata.meta.h>

SKYSCRAPER_BEGIN

class cGcGalacticVoxelCoordinate
{
  public:
    int16_t mX;
    int16_t mZ;
    int16_t mY;
    bool mbValid;
};

class cGcGalacticSolarSystemAddress
{
  public:
    cGcGalacticVoxelCoordinate mVoxelCoordinate;
    uint16_t mSolarIndex;
    uint16_t mIteration;
};

class cGcGalaxyAttributesAtAddress
{
  public:
    cGcGalaxyVoxelAttributesData mVoxel;
    cTkColour mVoxelPrimaryColour;
    cTkColour mVoxelSecondaryColour;
    cGcGalaxyStarAttributesData mStar;
    bool mbValid;

    cGcGalaxyAttributesAtAddress(){};
};

class cGcInterstellarEvent
{
  public:
    TkID<256> mID;
    cGcGalacticAddressData mGalacticAddress;
    TkID<128> mMissionID;
    uint64_t mu64MissionSeed;
};

struct UInt64Pair
{
    uint64_t mu64A;
    uint64_t mu64B;
};

template <int MemPoolIdx>
struct UInt64PairBiMap
{
    robin_hood::detail::Table<true, 80, UInt64Pair, void, robin_hood::hash<UInt64Pair, void>, std::equal_to<UInt64Pair>>
        mIDPairMap;
};

namespace GPN
{

class GraphNode;

struct GraphLink
{
    GPN::GraphNode *mpParent;
    GPN::GraphNode *mpChild;
    float mfCost;
    float mfDistance;
};

class GraphNode : public AutoPooled<4>
{
    cTkVector3 mPos;
    uint64_t mu64SystemID;
    unsigned int muLastSearchIndex;
    cTkVector<GPN::GraphLink> mLinks;
    bool mbPopulated;
};

class SearchInterface
{
  public:
    virtual ~SearchInterface();
    virtual GPN::GraphNode *GetOrCreateGraphNode(const cTkVector3 *, uint64_t);
    virtual cTkVector3 *GetGoalPosition(cTkVector3 *result);
    virtual uint64_t GetGoalUA();
    virtual bool HasLevel1Upgrade();
    virtual bool HasLevel2Upgrade();
    virtual bool HasLevel3Upgrade();
    virtual float GetMaximumJumpDistance();
};

struct GoalData
{
    robin_hood::detail::Table<
        true, 80, uint64_t, GPN::GraphNode *, robin_hood::hash<uint64_t, void>, std::equal_to<uint64_t>>
        mNodeMap;
    cTkVector3 mTarget;
    uint64_t mu64TargetSystemID;
};

class SearchContext : public GPN::SearchInterface
{
    enum State
    {
        Invalid,
        Searching,
        Impossible,
        Failed,
        Abandoned,
        Complete,
    };

    GPN::SearchContext::State meState;
    unsigned int muStepIndex;
    unsigned int muVoxelCacheVersioningAtInit;
    float mfVoxelSpaceJumpDistance;
    GPN::GoalData mSearchGoal;
    GPN::GraphNode mRootGraphNode;
    cTkDeque<GPN::GraphNode *> mSearchStack;
    UInt64PairBiMap<4> mSystemLinkMap;
    cTkVector<GPN::GraphNode *> mOptimalPath;
    bool mbPathCompressed;
    bool mbHasLv1Upgrade;
    bool mbHasLv2Upgrade;
    bool mbHasLv3Upgrade;
};

} // namespace GPN

SKYSCRAPER_END