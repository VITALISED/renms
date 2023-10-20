#pragma once
#include <metadata/metadata_common.h>
enum eModifyType
{
    EModifyType_Set = 0,
    EModifyType_Add = 1,
    EModifyType_Subtract = 2,
}

class cGcStatModifyType
{
    static unsigned long long muNameHash = 0xA2CE4FB30A13249B;
    static unsigned long long muTemplateHash = 0xEBD2B9A30628DD26;

    eModifyType ModifyType;
}
