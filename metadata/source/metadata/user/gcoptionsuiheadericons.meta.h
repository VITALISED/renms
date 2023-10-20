#pragma once
#include <metadata/metadata_common.h>
enum eOptionsUIHeaderIconType
{
    EOptionsUIHeaderIconType_General = 0,
    EOptionsUIHeaderIconType_Ship = 1,
    EOptionsUIHeaderIconType_Cog = 2,
    EOptionsUIHeaderIconType_Scanner = 3,
    EOptionsUIHeaderIconType_Advanced = 4,
}

class cGcOptionsUIHeaderIcons
{
    static unsigned long long muNameHash = 0x3CD82FC9BE1CC713;
    static unsigned long long muTemplateHash = 0xD47702419626C73A;

    eOptionsUIHeaderIconType OptionsUIHeaderIconType;
}
