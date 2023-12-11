/**
 * @file GcWFCScenes.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
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

#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

struct sTransformedBasebuildingPart
{
    const TkID<128> mPartID;
    cTkMatrix34 mTransform;
    const float mfScale;
};

struct sWFCNavigationSubgraphNode
{
    cTkMatrix34 mTransform;
    bool mbIsPOI;
    float mfArriveDistance;
    cTkSmartResHandle mCustomInteractionResHandle;
};

class cGcWFCNavigationSubGraph
{
  public:
    cTkVector<sWFCNavigationSubgraphNode> mNodes;
    int maiConnections[6];
    cTkVector<std::pair<int, int>> mEdges;
    bool mbConnectNodesByDistance;
    cTkVector<std::pair<TkID<128>, cTkMatrix34>> mNPCs;
};

class cGcWFCScene
{
  public:
    cTkSmartResHandle mResHandle;
    bool mbNeedsToParseScene;
    bool mbParsedBasebuildingTerrainEditBoxes;
    cTkVector<sTransformedBasebuildingPart> maBasebuildingParts;
    cGcWFCNavigationSubGraph mNavigationSubGraph;
    cTkVector<std::pair<cTkAABB, cTkMatrix34>> maTerrainEditBoxes;
    cTkVector<std::pair<cTkAABB, cTkMatrix34>> maBasebuildingTerrainEditBoxes;
};

struct sWeightedWFCScene
{
    const cGcWFCScene *mScene;
    const float mfRelativeProbability;
};

class cGcWFCScenes
{
  public:
    cTkVector<sWeightedWFCScene> mItems;
};

SKYSCRAPER_END