#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcfrigatestattype.meta.h>

class cGcExpeditionPowerup
{
    static unsigned long long muNameHash = 0xB76095BD04FCB5D2;
    static unsigned long long muTemplateHash = 0x52724DA9E32E1E14;

    TkID<128> mProductId;
    cGcFrigateStatType StatModified;
    int miValueChange;
    TkID<256> mSelectionDescription;
    TkID<256> mModuleDescription;
}
