#pragma once
#include <metadata/metadata_common.h>
#include <metadata/user/gcvibrationchanneldata.meta.h>

class cGcVibrationDataTable
{
    static unsigned long long muNameHash = 0x75E1ADCE47B381E6;
    static unsigned long long muTemplateHash = 0x7F805411D9D2FB67;

    cTkDynamicArray<cGcVibrationChannelData> maData;
}
