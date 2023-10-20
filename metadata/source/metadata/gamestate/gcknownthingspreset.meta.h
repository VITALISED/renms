#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcKnownThingsPreset
{
    static unsigned long long muNameHash = 0x50D7C1FE13F7260D;
    static unsigned long long muTemplateHash = 0xCEACB9E8E146424;

    cTkDynamicArray<TkID<128>> maKnownTech;
    cTkDynamicArray<TkID<128>> maKnownProducts;
    cTkDynamicArray<TkID<128>> maKnownSpecials;
    cTkDynamicArray<TkID<256>> maKnownRefinerRecipes;
    cTkDynamicArray<cGcWordKnowledge> maKnownWords;
    cTkDynamicArray<cGcWordGroupKnowledge> maKnownWordGroups;
}
