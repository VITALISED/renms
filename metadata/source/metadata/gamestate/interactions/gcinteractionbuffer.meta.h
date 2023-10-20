#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/interactions/gcinteractiondata.meta.h>

class cGcInteractionBuffer
{
    static unsigned long long muNameHash = 0x7355BB5E5AC6EB4A;
    static unsigned long long muTemplateHash = 0x66D42310D501E21;

    cTkDynamicArray<cGcInteractionData> maInteractions;
    int miCurrentPos;
}
