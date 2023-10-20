#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/gcpetaccessoryinfo.meta.h>
#include <metadata/simulation/ecosystem/gcpetaccessorygroup.meta.h>

class cGcPetAccessoryTable
{
    static unsigned long long muNameHash = 0x9ED3D0A38623AF53;
    static unsigned long long muTemplateHash = 0x74F47B52F687DFAA;

    cTkFixedArray<cGcPetAccessoryInfo> maAccessories;
    cTkDynamicArray<cGcPetAccessoryGroup> maAccessoryGroups;
}
