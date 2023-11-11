#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

struct cTkNGuiEditor : cTkNGui
{
    cTkNGuiLayoutList *mpLayoutList;
    cTkNGuiUserSettings *mpUserSettings;
    cTkNGuiEditorLayout *mpLayout;
    const char *mpacLayoutFilename;
    bool(__fastcall *mpPopupRender)(void *);
    void *mpPopupData;
    bool mbPopupRendering;
    __declspec(align(8)) cTkComboBoxPopup mComboBoxPopup;
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
    std::vector<float, TkSTLAllocatorShim<float, 4, -1>> mafLabelWidthStack;
    std::vector<cTkNGuiEditor::cTkNGuiCategoryLookup, TkSTLAllocatorShim<cTkNGuiEditor::cTkNGuiCategoryLookup, 8, -1>>
        maCategoryLookup;
    std::vector<cTkNGuiElementID, TkSTLAllocatorShim<cTkNGuiElementID, 8, -1>> maActiveWindowStack;
    cTkUiDataMap<cTkNGuiScrollData> mScrollDataMap;
    cTkUiDataMap<cTkNGuiScrollData> mPanelDataMap;
    cTkUiDataMap<cTkNGuiWindowData> mWindowDataMap;
    cTkUiDataMap<cTkNGuiTreeData> mTreeDataMap;
    cTkUiDataMap<cTkNGuiToggleData> mToggleDataMap;
    cTkUiDataMap<cTkNGuiPanelData> mDynamicPanelDataMap;
    std::vector<cTkNGuiElementID, TkSTLAllocatorShim<cTkNGuiElementID, 8, -1>> maDynamicPanelStack;
    std::vector<cTkNGuiElementID, TkSTLAllocatorShim<cTkNGuiElementID, 8, -1>> maTreeNodeStack;
    std::vector<bool, TkSTLAllocatorShim<bool, 1, -1>> maTreeNodeFilterStack;
    bool mbTaskbarRendering;
    cTkNGuiEditor::eMenu meTaskbarMenu;
    std::vector<cTkNGuiEditor::cTkTaskbarStackItem, TkSTLAllocatorShim<cTkNGuiEditor::cTkTaskbarStackItem, 4, -1>>
        maTaskbarStack;
    std::vector<cTkBBox2d, TkSTLAllocatorShim<cTkBBox2d, 4, -1>> maTaskbarBBox2dList;
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