#pragma once
#include <metadata/metadata_common.h>
enum eCreatureSizeClass
{
    ECreatureSizeClass_Small = 0,
    ECreatureSizeClass_Medium = 1,
    ECreatureSizeClass_Large = 2,
    ECreatureSizeClass_Huge = 3,
}

class cGcCreatureSizeClasses
{
    static unsigned long long muNameHash = 0xB113E9A825921723;
    static unsigned long long muTemplateHash = 0xB638038AE945B25D;

    eCreatureSizeClass CreatureSizeClass;
}
