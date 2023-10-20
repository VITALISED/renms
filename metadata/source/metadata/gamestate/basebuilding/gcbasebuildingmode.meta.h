#pragma once
#include <metadata/metadata_common.h>
enum eBaseBuildingMode
{
    EBaseBuildingMode_Inactive = 0,
    EBaseBuildingMode_Selection = 1,
    EBaseBuildingMode_Placement = 2,
    EBaseBuildingMode_Browse = 3,
    EBaseBuildingMode_Relatives = 4,
}

class cGcBaseBuildingMode
{
    static unsigned long long muNameHash = 0xC3799C08BEEDFEF6;
    static unsigned long long muTemplateHash = 0x5186B938F0A2437;

    eBaseBuildingMode BaseBuildingMode;
}
