#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/gcresourceelement.meta.h>
#include <metadata/simulation/player/gcplayercommunicatormessage.meta.h>

class cGcPulseEncounterSpawnTrader
{
    static unsigned long long muNameHash = 0x61E014828AD14CD;
    static unsigned long long muTemplateHash = 0x7BE1C328EE224011;

    cGcResourceElement CustomShipResource;
    bool mbUseCustomMessage;
    TkID<256> mCustomHailOSD;
    cGcPlayerCommunicatorMessage HailingMessage;
}
