/**
 * @file TkNGuiEditor.h
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

#include <toolkit/graphics/2d/ngui/TkNGui.h>
#include <toolkit/graphics/2d/ngui/TkNGuiTextEdit.h>
#include <toolkit/graphics/2d/ngui/TkNGuiUndoable.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <toolkit/ngui/tknguieditorlayout.meta.h>
#include <toolkit/ngui/tknguieditorstyledata.meta.h>
#include <toolkit/ngui/tknguigraphicstyledata.meta.h>
#include <toolkit/ngui/tknguilayoutlist.meta.h>
#include <toolkit/ngui/tknguitextstyledata.meta.h>
#include <toolkit/ngui/tknguiusersettings.meta.h>
#include <toolkit/ngui/tknguiwindowlayoutdata.meta.h>

SKYSCRAPER_BEGIN

class cTkNGuiEditor;

class cTkNGuiPopup
{
  public:
    cTkNGuiEditor *mpGui;
    cTkVector2 mPosition;
    cTkVector2 mSize;

    virtual bool Render();
};

class cTkComboBoxPopup : public cTkNGuiPopup
{
  public:
    const char *mpacLabel;
    int64_t *mpaiSelectionMap;
    const char **mpaacEntries;
    int miNumEntries;
    float mfContentWidth;
    unsigned int *mpuSelected;
    int *mpiSelected;
    int miSelectedSize;
    bool mbDoScrollBars;

    virtual bool Render();
};

class cTkIconSelectPopup : public cTkNGuiPopup
{
  public:
    unsigned int *mpuIcon;

    virtual bool Render();
};

class cTkNGuiScrollData
{
  public:
    float mfScrollX;
    float mfScrollY;
};

class cTkNGuiWindowData
{
  public:
    void (*mGuiCreateCallback)(cTkNGuiElementID, void *);
    void (*mGuiRenderCallback)(void *);
    void *mpCallbackData;
    cTkFixedString<128, char> macTitle;
    cTkNGuiWindowLayoutData *mpLayout;
    bool mbIsDragged;
    bool mbIsResizedX;
    bool mbIsResizedY;
    bool mbSearchActive;
    cTkFixedString<256, char> mSearchFilter;
    cTkVector<cTkFixedString<128, char>> maErrors;
    cTkNGuiElementID mSnappedIdX;
    cTkNGuiElementID mSnappedIdY;
    bool mbRequestClose;
    float mfDragOffsetX;
    float mfDragOffsetY;
    std::vector<cTkNGuiElementID> maTabArray;
};

class cTkNGuiTreeData
{
  public:
    bool mbIsMaximised;
    bool mbTabled;
    cTkVector2 mStartPos;
    cTkVector2 mTitleStartPos;
    float mfHeight;
};

class cTkNGuiToggleData
{
  public:
    bool mbIsActive;
};

class cTkNGuiPanelData
{
  public:
    float mfHeight;
    float mfLabelWidth;
};

class cTkNGuiUndoStack
{
  public:
    cTkVector<cTkNGuiUndoable *> maUndoStack;
    int miUndoStackIndex;
};

class cTkNGuiEditor : public cTkNGui
{
  public:
    enum eMenu
    {
        EMenu_Closed   = 0xFFFFFFFF,
        EMenu_Main     = 0,
        EMenu_Layouts  = 1,
        EMenu_NumMenus = 2,
    };

    struct cTkNGuiCategoryLookup
    {
        cTkFixedString<64, char> mName;
        int miParentIndex;
        cTkVector<cTkNGuiElementID> maMembers;
    };

    struct cTkTaskbarStackItem
    {
        int miIndex;
        float mfYPos;
    };

    cTkNGuiLayoutList *mpLayoutList;
    cTkNGuiUserSettings *mpUserSettings;
    cTkNGuiEditorLayout *mpLayout;
    const char *mpacLayoutFilename;
    bool (*mpPopupRender)(void *);
    void *mpPopupData;
    bool mbPopupRendering;
    cTkComboBoxPopup mComboBoxPopup;
    cTkIconSelectPopup mIconSelectPopup;
    bool mbAdvanceActiveTextEdit;
    cTkNGuiTextEditState mTextEditState;
    cTkNGuiElementID mActiveTextEditID;
    cTkNGuiElementID mPrevActiveTextEditID;
    bool mbHasPrevActiveText;
    cTkNGuiElementID mActiveWindowID;
    cTkNGuiElementID mCurrentWindowID;
    cTkNGuiElementID mMouseOverWindowID;
    cTkNGuiElementID mDragTargetWindowID;
    cTkNGuiElementID mDragTargetCanditateWindowID;
    cTkVector<float> mafLabelWidthStack;
    cTkVector<cTkNGuiEditor::cTkNGuiCategoryLookup> maCategoryLookup;
    cTkVector<cTkNGuiElementID> maActiveWindowStack;
    cTkUiDataMap<cTkNGuiScrollData> mScrollDataMap;
    cTkUiDataMap<cTkNGuiScrollData> mPanelDataMap;
    cTkUiDataMap<cTkNGuiWindowData> mWindowDataMap;
    cTkUiDataMap<cTkNGuiTreeData> mTreeDataMap;
    cTkUiDataMap<cTkNGuiToggleData> mToggleDataMap;
    cTkUiDataMap<cTkNGuiPanelData> mDynamicPanelDataMap;
    cTkVector<cTkNGuiElementID> maDynamicPanelStack;
    cTkVector<cTkNGuiElementID> maTreeNodeStack;
    cTkVector<bool> maTreeNodeFilterStack;
    bool mbTaskbarRendering;
    cTkNGuiEditor::eMenu meTaskbarMenu;
    cTkVector<cTkNGuiEditor::cTkTaskbarStackItem> maTaskbarStack;
    cTkVector<cTkBBox2d> maTaskbarBBox2dList;
    cTkFixedString<64, char> mTaskbarSearch;
    cTkNGuiUndoStack mUndoStack;
    cTkNGuiUndoable *mpPendingUndo;
    cTkNGuiUndoable *mpDeferredUndo;
    bool mbDeferredUndoEnd;
    cTkNGuiEditorStyleData *mpStyleData;
    cTkNGuiGraphicStyleData *maGraphicStylesBuffer;
    cTkNGuiTextStyleData *maTextStylesBuffer;
    cTkColour *maSkinColoursBuffer;
    float mfDragValueAccumulator;
    int miFontID;
};

SKYSCRAPER_END