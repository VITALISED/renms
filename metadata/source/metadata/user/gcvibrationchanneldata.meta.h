#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcVibrationChannelData
{
    static unsigned long long muNameHash = 0xAF919B46C646D940;
    static unsigned long long muTemplateHash = 0x6704215385A9A4BC;

    TkID<128> mId;
    cTkFixedArray<cGcVibrationData> maData;
}
