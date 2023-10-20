#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPetAccessoryGroup
{
    static unsigned long long muNameHash = 0x1ED57D0465F00894;
    static unsigned long long muTemplateHash = 0xF708AF671743EDF0;

    TkID<128> mId;
    cTkDynamicArray<cGcPetAccessoryType> maDisallowedAccessories;
}
