/**
 * @file GcNGuiNodeGraphViewer.h
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

#include <graphics/ngui/windows/GcNGuiWindow.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/graphics/debug/TkNGuiNodeGraph.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkRandom.h>

SKYSCRAPER_BEGIN

class cGcNGuiNodeGraphViewer : public cGcNGuiWindow
{
  public:
    struct DataNode
    {
        int miPosX;
        int miPosY;
        TkHandle mNode;
        cTkColour mColour;
        cTkNGuiNodeGraph::Node *mpGuiNode;
        const char *mpcNodeName;
    };

    int maiWidthStack[100];
    int maiHeightStack[100];
    int maiCachedHeightStack[100];
    cTkRandom mRnd;
    bool mbDisplayMatrices;
    bool mbDisplayWorldAABBs;
    bool mbDisplayLocalAABBs;
    bool mbDisplayInactiveNodes;
    bool mbDisplayChildNodesOfSelection;
    bool mbCentreNodeGraph;
    cTkVector<cGcNGuiNodeGraphViewer::DataNode *> maNodes;
    cTkVector<cTkNGuiNodeGraph::LinkInfo> maLinks;
    robin_hood::detail::Table<
        true, 80, TkHandle, cGcNGuiNodeGraphViewer::DataNode *, robin_hood::hash<TkHandle, void>,
        std::equal_to<TkHandle>>
        maNodeHashMap;
    cTkNGuiNodeGraph mNodeGraph;
    TkHandle mCurrentNode;
    bool mbFirstRun;
    cTkVector<cGcNGuiNodeGraphViewer::DataNode *> maFoundNodes;
};

SKYSCRAPER_END