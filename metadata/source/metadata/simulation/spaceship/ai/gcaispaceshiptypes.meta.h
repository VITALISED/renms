#pragma once
#include <metadata/metadata_common.h>
enum eShipType
{
    EShipType_None = 0,
    EShipType_Pirate = 1,
    EShipType_Police = 2,
    EShipType_Trader = 3,
    EShipType_Freighter = 4,
    EShipType_PlayerSquadron = 5,
    EShipType_DefenceForce = 6,
}

class cGcAISpaceshipTypes
{
    static unsigned long long muNameHash = 0x8CBF91F9F8428E08;
    static unsigned long long muTemplateHash = 0xE01BE0B6BD142C64;

    eShipType ShipType;
}
