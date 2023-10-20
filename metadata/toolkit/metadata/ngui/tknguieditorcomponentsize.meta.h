#pragma once
#include <metadata/metadata_common.h>
enum eNGuiEditorComponentSize
{
    ENGuiEditorComponentSize_WindowResize = 0,
    ENGuiEditorComponentSize_WindowButton = 1,
    ENGuiEditorComponentSize_Indent = 2,
    ENGuiEditorComponentSize_SeparatorHeight = 3,
    ENGuiEditorComponentSize_SeparatorWidth = 4,
    ENGuiEditorComponentSize_TreeNodeExpander = 5,
    ENGuiEditorComponentSize_CheckBox = 6,
    ENGuiEditorComponentSize_Adjuster = 7,
    ENGuiEditorComponentSize_Cursor = 8,
    ENGuiEditorComponentSize_TextEditSeparator = 9,
    ENGuiEditorComponentSize_DefaultLineHeight = 10,
    ENGuiEditorComponentSize_ColourEditHeight = 11,
    ENGuiEditorComponentSize_ColourEditWidth = 12,
    ENGuiEditorComponentSize_FileBrowser = 13,
    ENGuiEditorComponentSize_EditorResize = 14,
    ENGuiEditorComponentSize_EditorMove = 15,
    ENGuiEditorComponentSize_IconButton = 16,
    ENGuiEditorComponentSize_SliderKnob = 17,
    ENGuiEditorComponentSize_SliderBarWidth = 18,
    ENGuiEditorComponentSize_SliderBarHeight = 19,
    ENGuiEditorComponentSize_CategoryHeight = 20,
    ENGuiEditorComponentSize_WindowTitle = 21,
    ENGuiEditorComponentSize_ScrollSpeed = 22,
    ENGuiEditorComponentSize_ComboBox = 23,
    ENGuiEditorComponentSize_Taskbar = 24,
    ENGuiEditorComponentSize_IconListItem = 25,
    ENGuiEditorComponentSize_Toolbar = 26,
    ENGuiEditorComponentSize_ToolbarOptions = 27,
    ENGuiEditorComponentSize_StartBarWidth = 28,
    ENGuiEditorComponentSize_StartBarHeight = 29,
    ENGuiEditorComponentSize_StartBarSearchWidth = 30,
    ENGuiEditorComponentSize_TreeNodeSpacing = 31,
    ENGuiEditorComponentSize_VectorSpacing = 32,
    ENGuiEditorComponentSize_SliderMinSpacing = 33,
    ENGuiEditorComponentSize_VectorMinSpacing = 34,
    ENGuiEditorComponentSize_ColourAlphaMinsize = 35,
    ENGuiEditorComponentSize_SpacingGap = 36,
    ENGuiEditorComponentSize_Scroll = 37,
    ENGuiEditorComponentSize_TextLabelSeparator = 38,
    ENGuiEditorComponentSize_AlignmentAnchor = 39,
    ENGuiEditorComponentSize_MinimiseHighlightHeight = 40,
    ENGuiEditorComponentSize_TableButtonSpacing = 41,
    ENGuiEditorComponentSize_TableHeaderHeight = 42,
    ENGuiEditorComponentSize_TreeNodeHeight = 43,
    ENGuiEditorComponentSize_ScrollMargin = 44,
    ENGuiEditorComponentSize_ScrollIncrement = 45,
    ENGuiEditorComponentSize_EditorPin = 46,
    ENGuiEditorComponentSize_DynamicPanelTitle = 47,
}

class cTKNGuiEditorComponentSize
{
    static unsigned long long muNameHash = 0xB649393FB6E397AE;
    static unsigned long long muTemplateHash = 0x15C71D80B19E4AE8;

    eNGuiEditorComponentSize NGuiEditorComponentSize;
}
