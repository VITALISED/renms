#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/customisation/gccharactercustomisationdata.meta.h>

class cGcCharacterCustomisationSaveData
{
    static unsigned long long muNameHash = 0xC5B9CCD1978B8755;
    static unsigned long long muTemplateHash = 0x34E14CB75FB4264A;

    TkID<128> mSelectedPreset;
    cGcCharacterCustomisationData CustomData;
}
