#pragma once
#include <metadata/metadata_common.h>
enum eSectorName
{
    ESectorName_Generic = 0,
    ESectorName_Elevated = 1,
    ESectorName_Low = 2,
    ESectorName_Trees = 3,
    ESectorName_LushTrees = 4,
    ESectorName_Lush = 5,
    ESectorName_Wet = 6,
    ESectorName_Cave = 7,
    ESectorName_Dead = 8,
    ESectorName_Buildings = 9,
    ESectorName_Water = 10,
    ESectorName_Ice = 11,
}

class cGcNameGeneratorSectorTypes
{
    static unsigned long long muNameHash = 0x2FBB792E633BA89B;
    static unsigned long long muTemplateHash = 0x7DFB66DB33ABB5EA;

    eSectorName SectorName;
}
