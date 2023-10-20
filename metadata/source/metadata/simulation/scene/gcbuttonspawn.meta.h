#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/tkinputenum.meta.h>
enum eEvent
{
    EEvent_None = 0,
    EEvent_Pirates = 1,
    EEvent_Police = 2,
    EEvent_Traders = 3,
    EEvent_Walker = 4,
}
#include <metadata/simulation/scene/gcbuttonspawnoffset.meta.h>

class cGcButtonSpawn
{
    static unsigned long long muNameHash = 0x7F9FCEDE7E2CBFC0;
    static unsigned long long muTemplateHash = 0xEB2525B3E0B9F658;

    cTkInputEnum Button;
    eEvent Event;
    cGcButtonSpawnOffset Offset;
}
