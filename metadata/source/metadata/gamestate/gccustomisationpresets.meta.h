#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gccustomisationpreset.meta.h>

class cGcCustomisationPresets
{
    static unsigned long long muNameHash = 0x94F8E55312096B6B;
    static unsigned long long muTemplateHash = 0x69AFB5CD4CBEFC24;

    cTkDynamicArray<cGcCustomisationPreset> maPresets;
}
