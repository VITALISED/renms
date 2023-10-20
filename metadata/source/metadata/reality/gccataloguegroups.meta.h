#pragma once
#include <metadata/metadata_common.h>
enum eCatalogueGroup
{
    ECatalogueGroup_MaterialsAndItems = 0,
    ECatalogueGroup_CraftingAndTechnology = 1,
    ECatalogueGroup_Buildables = 2,
    ECatalogueGroup_Recipes = 3,
    ECatalogueGroup_Wonders = 4,
}

class cGcCatalogueGroups
{
    static unsigned long long muNameHash = 0x9A93F045019746C1;
    static unsigned long long muTemplateHash = 0x261CB4A6885077DC;

    eCatalogueGroup CatalogueGroup;
}
