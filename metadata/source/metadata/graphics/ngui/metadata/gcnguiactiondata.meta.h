#pragma once
#include <metadata/metadata_common.h>
enum eAction
{
    EAction_Click = 0,
    EAction_Hover = 1,
    EAction_ArrowLeft = 2,
    EAction_ArrowRight = 3,
}

class cGcNGuiActionData
{
    static unsigned long long muNameHash = 0x2D0ED597896EB5AF;
    static unsigned long long muTemplateHash = 0x79A76EAFBFCDDB6B;

    TkID<128> mLayerID;
    cTkFixedString<128,char> macData;
    eAction Action;
}
