#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCustomisationDescriptorGroupOptions
{
    static unsigned long long muNameHash = 0x57CBFDF164E923E9;
    static unsigned long long muTemplateHash = 0x3E6EE8A3313E1086;

    TkID<256> mGroupTitle;
    bool mbFirstOptionIsEmpty;
    cTkDynamicArray<cGcCustomisationDescriptorGroupOption> maDescriptorGroupOptions;
    cTkDynamicArray<TkID<128>> maPrerequisiteGroup;
}
