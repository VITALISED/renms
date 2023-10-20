#pragma once
#include <metadata/metadata_common.h>
enum eNGuiEditorText
{
    ENGuiEditorText_Text = 0,
    ENGuiEditorText_Button = 1,
    ENGuiEditorText_WindowTab = 2,
    ENGuiEditorText_WindowTabInactive = 3,
    ENGuiEditorText_TreeNode = 4,
    ENGuiEditorText_CheckBox = 5,
    ENGuiEditorText_TextInput = 6,
    ENGuiEditorText_TextInputLabel = 7,
    ENGuiEditorText_TextInputLabelHeader = 8,
    ENGuiEditorText_Category = 9,
    ENGuiEditorText_TaskBar = 10,
    ENGuiEditorText_GroupTitle = 11,
    ENGuiEditorText_TreeNodeSelected = 12,
    ENGuiEditorText_DynamicPanelTitle = 13,
}

class cTKNGuiEditorTextType
{
    static unsigned long long muNameHash = 0x4780AB6325CE84C6;
    static unsigned long long muTemplateHash = 0xCE328FD208CBB692;

    eNGuiEditorText NGuiEditorText;
}
