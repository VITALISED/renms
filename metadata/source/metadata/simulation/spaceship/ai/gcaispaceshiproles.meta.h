#pragma once
#include <metadata/metadata_common.h>
enum eAIShipRole
{
    EAIShipRole_Standard = 0,
    EAIShipRole_PlayerSquadron = 1,
    EAIShipRole_Freighter = 2,
    EAIShipRole_CapitalFreighter = 3,
    EAIShipRole_SmallFreighter = 4,
    EAIShipRole_TinyFreighter = 5,
    EAIShipRole_Frigate = 6,
}

class cGcAISpaceshipRoles
{
    static unsigned long long muNameHash = 0x4533D19670B0A519;
    static unsigned long long muTemplateHash = 0x18E65DC6E8DC9DAA;

    eAIShipRole AIShipRole;
}
