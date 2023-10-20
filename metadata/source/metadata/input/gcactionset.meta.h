#pragma once
#include <metadata/metadata_common.h>
#include <metadata/input/gcactionsettype.meta.h>
#include <metadata/input/gcactionusetype.meta.h>
#include <metadata/input/gcactionsetaction.meta.h>

class cGcActionSet
{
    static unsigned long long muNameHash = 0xA14126BE226C6660;
    static unsigned long long muTemplateHash = 0xCC5C5E926EE22A2B;

    cGcActionSetType Type;
    cGcActionUseType Status;
    cTkFixedString<32,char> macExternalId;
    cTkFixedString<32,char> macExternalLoc;
    TkID<256> mLocTag;
    cTkDynamicArray<cGcActionSetAction> maActions;
}
