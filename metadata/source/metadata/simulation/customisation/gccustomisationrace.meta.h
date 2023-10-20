#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCustomisationRace
{
    static unsigned long long muNameHash = 0x231919D5AE192450;
    static unsigned long long muTemplateHash = 0x78FC4D1015162EDB;

    TkID<128> mDescriptorGroupOption;
    bool mbIsGek;
    float mfScale;
    cTkDynamicArray<cGcCustomisationGroup> maCustomisationGroups;
    cTkDynamicArray<TkID<128>> maPresets;
}
