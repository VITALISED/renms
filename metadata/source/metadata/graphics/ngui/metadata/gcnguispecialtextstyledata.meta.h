#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcNGuiSpecialTextStyleData
{
    static unsigned long long muNameHash = 0x9C498422BDBE21FE;
    static unsigned long long muTemplateHash = 0x3DE2EB0549638644;

    TkID<128> mName;
    cTkDynamicArray<cTkClassPointer> maStyleProperties;
    cGcNGuiStyleAnimationData Animation;
}
