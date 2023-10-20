#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCustomInventoryComponentData
{
    static unsigned long long muNameHash = 0xB16E966B1CE41461;
    static unsigned long long muTemplateHash = 0x51AD00284F2D2C83;

    TkID<128> mSize;
    cTkDynamicArray<cGcInventoryTechProbability> maDesiredTechs;
    bool mbCool;
}
