#pragma once
#include <metadata/metadata_common.h>
enum eBaseBuildingDecorationType
{
    EBaseBuildingDecorationType_Normal = 0,
    EBaseBuildingDecorationType_SurfaceNormal = 1,
    EBaseBuildingDecorationType_Ceiling = 2,
    EBaseBuildingDecorationType_Terrain = 3,
    EBaseBuildingDecorationType_Substance = 4,
    EBaseBuildingDecorationType_Plant = 5,
    EBaseBuildingDecorationType_BuildingSurfaceNormal = 6,
}

class cGcBaseBuildingObjectDecorationTypes
{
    static unsigned long long muNameHash = 0xCBF38A24719D032E;
    static unsigned long long muTemplateHash = 0x83AB64738650BC1D;

    eBaseBuildingDecorationType BaseBuildingDecorationType;
}
