#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gcplayeremote.meta.h>

class cGcPlayerEmoteList
{
    static unsigned long long muNameHash = 0x24E4352E3DDE4F22;
    static unsigned long long muTemplateHash = 0x9D104D097D8FD132;

    cTkDynamicArray<cGcPlayerEmote> maEmotes;
}
