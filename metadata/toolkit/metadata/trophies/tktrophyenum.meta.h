#pragma once
#include <metadata/metadata_common.h>
enum eTrophy
{
    ETrophy_None = -1,
    ETrophy_Trophy0 = 0,
    ETrophy_Trophy1 = 1,
    ETrophy_Trophy2 = 2,
    ETrophy_Trophy3 = 3,
    ETrophy_Trophy4 = 4,
}

class cTkTrophyEnum
{
    static unsigned long long muNameHash = 0xF50D34444AC02C1E;
    static unsigned long long muTemplateHash = 0xDCDC4D1713C4B17A;

    eTrophy Trophy;
}
