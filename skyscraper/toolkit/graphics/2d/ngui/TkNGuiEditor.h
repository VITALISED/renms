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
    VFT<1> *__vftable;
    cTkNGuiEditor *mpGui;
    cTkVector2 mPosition;
    cTkVector2 mSize;
};

class cTkComboBoxPopup : public cTkNGuiPopup
{
    VFT<1> *__vftable;
    const char *mpacLabel;
    __int64 *mpaiSelectionMap;
    const char **mpaacEntries;
    int miNumEntries;
    float mfContentWidth;
    unsigned int *mpuSelected;
    int *mpiSelected;
    int miSelectedSize;
    bool mbDoScrollBars;
};

struct cTkIconSelectPopup : public cTkNGuiPopup
{
    VFT<1> *__vftable;
    unsigned int *mpuIcon;
};

class cTkNGuiScrollData
{
    float mfScrollX;
    float mfScrollY;
};

class cTkNGuiWindowData
{
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
    bool mbIsMaximised;
    bool mbTabled;
    cTkVector2 mStartPos;
    cTkVector2 mTitleStartPos;
    float mfHeight;
};

class cTkNGuiToggleData
{
    bool mbIsActive;
};

class cTkNGuiPanelData
{
    float mfHeight;
    float mfLabelWidth;
};

class cTkNGuiUndoStack
{
    cTkVector<cTkNGuiUndoable *> maUndoStack;
    int miUndoStackIndex;
};

class cTkNGuiEditor : public cTkNGui
{
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