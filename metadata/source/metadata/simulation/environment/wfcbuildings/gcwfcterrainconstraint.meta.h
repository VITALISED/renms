#pragma once
#include <metadata/metadata_common.h>
enum eDirection
{
    EDirection_Left = 0,
    EDirection_Back = 1,
    EDirection_Right = 2,
    EDirection_Forward = 3,
    EDirection_LeftBack = 4,
    EDirection_RightBack = 5,
    EDirection_RightForward = 6,
    EDirection_LeftForward = 7,
    EDirection_All = 8,
}

class cGcWFCTerrainConstraint
{
    static unsigned long long muNameHash = 0xF0679B25F5343B25;
    static unsigned long long muTemplateHash = 0x48FCC1BDF4A692B3;

    eDirection Direction;
    eLevels Levels;
    eTerrain Terrain;
}
