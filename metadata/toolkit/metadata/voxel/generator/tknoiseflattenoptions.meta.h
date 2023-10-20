#pragma once
#include <metadata/metadata_common.h>
enum eFlattening
{
    EFlattening_None = 0,
    EFlattening_Flatten = 1,
    EFlattening_TerrainEdits = 2,
}

class cTkNoiseFlattenOptions
{
    static unsigned long long muNameHash = 0xB92478FDE531276E;
    static unsigned long long muTemplateHash = 0x34687CDAF17A671D;

    eFlattening Flattening;
    eWaterPlacement WaterPlacement;
}
