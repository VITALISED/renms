#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcplayerdamagedata.meta.h>

class cGcPlayerDamageTable
{
    static unsigned long long muNameHash = 0x40154165764DAC5;
    static unsigned long long muTemplateHash = 0xBDBB96DF08A18E8E;

    cTkDynamicArray<cGcPlayerDamageData> maDamageTable;
}
