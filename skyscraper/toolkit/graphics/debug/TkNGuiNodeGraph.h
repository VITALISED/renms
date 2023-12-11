/**
 * @file TkNGuiNodeGraph.h
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

#include <toolkit/graphics/2d/ngui/TkNGui.h>
#include <toolkit/system/timer/TkTimer.h>

#include <toolkit/ngui/tknguigraphicstyle.meta.h>

SKYSCRAPER_BEGIN

enum eNGuiWindowEdges
{
    EWindowEdge_Top,
    EWindowEdge_Bottom,
    EWindowEdge_Left,
    EWindowEdge_Right,
};

class cTkNGuiNodeGraph
{
  public:
    struct Graph;

    enum ConnectorType
    {
        eConnTypeInput,
        eConnTypeOutput,
    };

    struct LinkInfo
    {
        void *mpInputNodeUserData;
        uint64_t miInputUserData;
        void *mpOutputNodeUserData;
        uint64_t miOutputUserData;
    };

    struct Node
    {
        void *mpUserData;
        cTkNGuiElementID mWinId;
        cTkNGuiElementID mConnectorGrabbed;
        cTkNGuiElementID mSnappedIdX;
        cTkNGuiElementID mSnappedIdY;
        eNGuiWindowEdges mSnappedEdgeX;
        eNGuiWindowEdges mSnappedEdgeY;
        cTkBBox2d mBbox;
        cTkColour mActiveColour;
        float mfActiveAnim;
        bool mbGrabbed;
        bool mbMouseOver;
        bool mbSelected;
        bool mbInCurrentSelect;
        bool mbExpandToContentX;
        int miWindowX;
        int miWindowY;
        cTkVector2 mContentSize;
        float mfSeparator;
        cTkNGuiNodeGraph::Graph *mpGraph;
    };

    struct Graph
    {
        bool mbDragging;
        bool mbNodeGrabbed;
        bool mbNodeConnGrabbed;
        bool mbCommentGrabbed;
        int mNodeDragX;
        int mNodeDragY;
        int mNewNodeDragX;
        int mNewNodeDragY;
        float mfSelectionStartX;
        float mfSelectionStartY;
        float mfSelectionEndX;
        float mfSelectionEndY;
        bool mbSelectionActive;
        bool mbSelectionReset;
        float mfScrollX;
        float mfScrollY;
        float mfScale;
        cTkNGuiNodeGraph::Node *mpCurNode;
        bool mbIsNewNode;
        bool mbIsNewGraph;
        cTkVector2 mContentSize;
    };

    struct Connector
    {
        cTkNGuiElementID mConnId;
        cTkNGuiElementID mFirstLinkId;
        cTkColour mActiveColour;
        uint64_t miUserData;
        cTkNGuiNodeGraph::ConnectorType mType;
        cTkBBox2d mBbox;
        float mfActiveAnim;
        bool mbGrabbed;
    };

    struct Link
    {
        cTkNGuiElementID mInputNodeId;
        cTkNGuiElementID mOutputNodeId;
        cTkNGuiElementID mInputConnId;
        cTkNGuiElementID mOutputConnId;
        cTkNGuiElementID mNextInputLinkId;
        cTkNGuiElementID mNextOutputLinkId;
        cTkColour mActiveColour;
        float mfActiveAnim;
        bool mbSelected;
        bool mbInCurrentSelect;
    };

    bool mbDeoverlapNewNodes;
    bool mbDeoverlapHorizontal;
    bool mbAlwaysDeoverlap;
    bool mbNewNodesRelativeToScroll;
    float mfTitleBarRightMargin;
    cTkUiDataMap<cTkNGuiNodeGraph::Node> maNodes;
    cTkUiDataMap<cTkNGuiNodeGraph::Connector> maInputs;
    cTkUiDataMap<cTkNGuiNodeGraph::Connector> maOutputs;
    cTkUiDataMap<cTkNGuiNodeGraph::Link> maLinks;
    cTkUiDataMap<cTkNGuiNodeGraph::Graph> maGraphs;
    cTkUiDataMap<void *> maSelectedButNotFound;
    cTkVector<void *> mpIdentifierStack;
    cTkNGuiNodeGraph::Graph *mpCurGraph;
    cTkNGuiNodeGraph::Link mNewLink;
    bool mbLinkCreatedThisFrame;
    cTkNGuiGraphicStyle mNodeTitleStyle;
    cTkNGuiGraphicStyle mRectStyle;
    cTkNGuiGraphicStyle mLineStyle;
    float mfSavedSeparator;
    cTkTimerTemplate<0> mScrollInterpTimer;
    cTkVector2 mStartInterpPos;
    cTkVector2 mEndInterpPos;
    cTkNGuiElementID mScrollId;
    bool mbSelectionReset;
};

SKYSCRAPER_END