#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/customisation/gccustomisationgroup.meta.h>

class cGcCustomisationGroups
{
    static unsigned long long muNameHash = 0x1DC53C6BE7A69854;
    static unsigned long long muTemplateHash = 0x8E4B94C6A2E76DCD;

    cTkDynamicArray<cGcCustomisationGroup> maCustomisationGroups;
}
