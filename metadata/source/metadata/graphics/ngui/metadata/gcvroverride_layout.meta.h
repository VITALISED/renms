#pragma once
#include <metadata/metadata_common.h>
enum eVROverride_Layout
{
    EVROverride_Layout_PosX = 0,
    EVROverride_Layout_PosY = 1,
    EVROverride_Layout_LayerWidth = 2,
    EVROverride_Layout_LayerHeight = 3,
    EVROverride_Layout_MaxWidth = 4,
}

class cGcVROverride_Layout
{
    static unsigned long long muNameHash = 0xE16B8EC5F09E6041;
    static unsigned long long muTemplateHash = 0xFEC3DBA59D002B84;

    eVROverride_Layout VROverride_Layout;
    float mfFloatValue;
}
