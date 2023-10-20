#pragma once
#include <metadata/metadata_common.h>
enum eProceduralTechnologyCategory
{
    EProceduralTechnologyCategory_None = 0,
    EProceduralTechnologyCategory_Combat = 1,
    EProceduralTechnologyCategory_Mining = 2,
    EProceduralTechnologyCategory_Scanning = 3,
    EProceduralTechnologyCategory_Protection = 4,
}

class cGcProceduralTechnologyCategory
{
    static unsigned long long muNameHash = 0xE46F247D87F34DBC;
    static unsigned long long muTemplateHash = 0xDCAA6E426437853B;

    eProceduralTechnologyCategory ProceduralTechnologyCategory;
}
