#pragma once
#include <metadata/metadata_common.h>
enum eAccessibleOverride_Layout
{
    EAccessibleOverride_Layout_PosX = 0,
    EAccessibleOverride_Layout_PosY = 1,
    EAccessibleOverride_Layout_LayerWidth = 2,
    EAccessibleOverride_Layout_LayerHeight = 3,
    EAccessibleOverride_Layout_MaxWidth = 4,
}

class cGcAccessibleOverride_Layout
{
    static unsigned long long muNameHash = 0xCB6432BD8E0191A0;
    static unsigned long long muTemplateHash = 0x9F357DA4F413F0D;

    eAccessibleOverride_Layout AccessibleOverride_Layout;
    float mfFloatValue;
}
