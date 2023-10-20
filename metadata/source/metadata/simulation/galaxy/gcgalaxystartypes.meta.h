#pragma once
#include <metadata/metadata_common.h>
enum eGalaxyStarType
{
    EGalaxyStarType_Yellow = 0,
    EGalaxyStarType_Green = 1,
    EGalaxyStarType_Blue = 2,
    EGalaxyStarType_Red = 3,
}

class cGcGalaxyStarTypes
{
    static unsigned long long muNameHash = 0x737DC36BC0894840;
    static unsigned long long muTemplateHash = 0xE3336B93F6817965;

    eGalaxyStarType GalaxyStarType;
}
