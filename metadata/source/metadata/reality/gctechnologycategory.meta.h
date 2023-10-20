#pragma once
#include <metadata/metadata_common.h>
enum eTechnologyCategory
{
    ETechnologyCategory_Ship = 0,
    ETechnologyCategory_Weapon = 1,
    ETechnologyCategory_Suit = 2,
    ETechnologyCategory_Personal = 3,
    ETechnologyCategory_All = 4,
    ETechnologyCategory_None = 5,
    ETechnologyCategory_Freighter = 6,
    ETechnologyCategory_Maintenance = 7,
    ETechnologyCategory_Exocraft = 8,
    ETechnologyCategory_Submarine = 9,
    ETechnologyCategory_Mech = 10,
    ETechnologyCategory_AllVehicles = 11,
    ETechnologyCategory_AlienShip = 12,
    ETechnologyCategory_AllShips = 13,
}

class cGcTechnologyCategory
{
    static unsigned long long muNameHash = 0xA5FDDD239156B452;
    static unsigned long long muTemplateHash = 0xE7799F4552A81DC2;

    eTechnologyCategory TechnologyCategory;
}
