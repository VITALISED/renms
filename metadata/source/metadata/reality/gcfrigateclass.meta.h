#pragma once
#include <metadata/metadata_common.h>
enum eFrigateClass
{
    EFrigateClass_Combat = 0,
    EFrigateClass_Exploration = 1,
    EFrigateClass_Mining = 2,
    EFrigateClass_Diplomacy = 3,
    EFrigateClass_Support = 4,
    EFrigateClass_Normandy = 5,
    EFrigateClass_DeepSpace = 6,
    EFrigateClass_DeepSpaceCommon = 7,
}

class cGcFrigateClass
{
    static unsigned long long muNameHash = 0xA3C86E46D2A8CA67;
    static unsigned long long muTemplateHash = 0xD7FC9616F212080A;

    eFrigateClass FrigateClass;
}
