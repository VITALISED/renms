#pragma once
#include <metadata/metadata_common.h>
enum eLinkNetworkType
{
    ELinkNetworkType_Power = 0,
    ELinkNetworkType_Resources = 1,
    ELinkNetworkType_Fuel = 2,
    ELinkNetworkType_Portals = 3,
    ELinkNetworkType_PlantGrowth = 4,
    ELinkNetworkType_ByteBeat = 5,
}

class cGcLinkNetworkTypes
{
    static unsigned long long muNameHash = 0xA2D103E3C1ECFE30;
    static unsigned long long muTemplateHash = 0x50A178234C7BFD1C;

    eLinkNetworkType LinkNetworkType;
}
