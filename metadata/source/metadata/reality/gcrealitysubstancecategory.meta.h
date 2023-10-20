#pragma once
#include <metadata/metadata_common.h>
enum eSubstanceCategory
{
    ESubstanceCategory_Fuel = 0,
    ESubstanceCategory_Metal = 1,
    ESubstanceCategory_Catalyst = 2,
    ESubstanceCategory_Stellar = 3,
    ESubstanceCategory_Flora = 4,
    ESubstanceCategory_Earth = 5,
    ESubstanceCategory_Exotic = 6,
    ESubstanceCategory_Special = 7,
    ESubstanceCategory_BuildingPart = 8,
}

class cGcRealitySubstanceCategory
{
    static unsigned long long muNameHash = 0x13D76408C6BF207D;
    static unsigned long long muTemplateHash = 0x6B88061EEAA9975A;

    eSubstanceCategory SubstanceCategory;
}
