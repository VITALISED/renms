#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshiproles.meta.h>
#include <metadata/reality/gcrealitycommonfactions.meta.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshiptypes.meta.h>

class cGcDoShipEscort
{
    static unsigned long long muNameHash = 0x68C0F45A086C1EB;
    static unsigned long long muTemplateHash = 0x122643798D35042D;

    bool mbMatchRole;
    cGcAISpaceshipRoles EscortTargetShipRole;
    bool mbMatchFaction;
    cGcRealityCommonFactions EscortTargetShipFaction;
    bool mbMatchType;
    cGcAISpaceshipTypes EscortTargetShipType;
    float mfMaxSearchDistance;
}
