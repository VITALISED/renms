/**
 * @file GcDebugEditor.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <toolkit/graphics/debug/TkDebugEditor.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

enum eDebugEditorMode
{
    EDebugEditor_Off,
    EDebugEditor_Edit,
    EDebugEditor_Play,
};

class cGcDebugEditor : public cTkDebugEditor
{
  public:
    enum eUndoTypes
    {
        EUndoType_None,
        EUndoType_EditMatrix,
        EUndoType_AddNode,
        EUndoType_RemoveNode,
    };

    enum eViewTypes
    {
        EViewTypes_None = -1,
        EViewTypes_ProcModel,
        EViewTypes_ToolboxModel,
        EViewTypes_GameModel,
        EViewTypes_NumTypes,
    };

    struct UndoEdit
    {
        cGcDebugEditor::eUndoTypes mUndoType;
        cTkPhysRelMat34 mMatrix;
        TkHandle mNode;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mResource;
        int miNodeID;
    };

    cTkBitArray<uint64_t, true, 64> mxDebugSections;
    int maiViewTypeSelectedIndex[3];
    cGcDebugEditor::eViewTypes meLastKnownViewType;
    bool mbLastKnownChangedViewType;
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mNewGameModelSelection;
    TkHandle mViewNode;
    TkHandle mRootNode;
    bool mbComputeNodeBB;
    cTkAABB mViewNodeBB;
    TkHandle mPreviewNode;
    float mfPlaceAngle;
    cTkVector<TkHandle> mPlacedNodes;
    cTkMatrix34 mPlaceMatrix;
    float mfPlaceScale;
    float mfPlaceHeight;
    bool mbValidPlacePosition;
    float mfAltPlaceDistance;
    bool mbPrepared;
    bool mbUnlockedMouse;
    eDebugEditorMode meMode;
    cGcDebugEditor::UndoEdit mUndoEdits[20];
    int miEditNumber;
};

SKYSCRAPER_END