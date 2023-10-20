#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcalienrace.meta.h>
#include <metadata/simulation/character/gccharacteralternateanimation.meta.h>

class cGcNPCComponentData
{
    static unsigned long long muNameHash = 0x5289598B4907DC8E;
    static unsigned long long muTemplateHash = 0xEDE9BF0DD3A33F8F;

    cGcAlienRace Race;
    TkID<128> mHologramEffect;
    bool mbIsOldStyleNPC;
    bool mbIsMech;
    cTkDynamicArray<cGcCharacterAlternateAnimation> maAlternateAnims;
    cTkDynamicArray<TkID<128>> maTags;
}
