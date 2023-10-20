#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForWarps
{
    static unsigned long long muNameHash = 0x720D90D0F7901AA2;
    static unsigned long long muTemplateHash = 0x8856BD001530575F;

    cTkFixedString<128,char> macMessage;
    int miAmount;
    cTkFixedString<128,char> macDebugText;
}
