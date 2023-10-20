#pragma once
#include <metadata/metadata_common.h>
enum eDensity
{
    EDensity_Sparse = 0,
    EDensity_Normal = 1,
    EDensity_Dense = 2,
    EDensity_VeryDense = 3,
}

class cGcCreatureGenerationDensity
{
    static unsigned long long muNameHash = 0x2CD4E62B393F6930;
    static unsigned long long muTemplateHash = 0x6C76550BC2D8BBE4;

    eDensity Density;
}
