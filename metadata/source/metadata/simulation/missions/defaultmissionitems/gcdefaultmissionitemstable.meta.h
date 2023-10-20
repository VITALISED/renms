#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcDefaultMissionItemsTable
{
    static unsigned long long muNameHash = 0x87FB8E825C599E66;
    static unsigned long long muTemplateHash = 0x733D84A81936E3FF;

    cTkDynamicArray<cGcDefaultMissionSubstance> maPrimarySubstances;
    cTkDynamicArray<cGcDefaultMissionSubstance> maSecondarySubstances;
    cTkDynamicArray<cGcDefaultMissionProduct> maPrimaryProducts;
    cTkDynamicArray<cGcDefaultMissionProduct> maSecondaryProducts;
}