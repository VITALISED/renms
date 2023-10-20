#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gccreaturerarity.meta.h>

class cGcCreatureTagAndRarity
{
    static unsigned long long muNameHash = 0x3DFFD10C388635E7;
    static unsigned long long muTemplateHash = 0x61AE7C6CD6687A47;

    TkID<128> mTag;
    cGcCreatureRarity RarityOverride;
}
