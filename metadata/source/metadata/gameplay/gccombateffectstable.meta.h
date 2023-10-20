#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gccombateffectdata.meta.h>

class cGcCombatEffectsTable
{
    static unsigned long long muNameHash = 0x733D7A989F8B9969;
    static unsigned long long muTemplateHash = 0xD0CBFBAB06FD5531;

    cTkFixedArray<cGcCombatEffectData> maEffectsData;
}
