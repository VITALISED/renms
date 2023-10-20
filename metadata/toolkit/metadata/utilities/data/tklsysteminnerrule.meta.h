#pragma once
#include <metadata/metadata_common.h>
enum eMergeProbabilityOptions
{
    EMergeProbabilityOptions_Balance = 0,
    EMergeProbabilityOptions_Prioritize = 1,
    EMergeProbabilityOptions_Replace = 2,
}
#include <?>

class cTkLSystemInnerRule
{
    static unsigned long long muNameHash = 0x4F8B68FB20F9A030;
    static unsigned long long muTemplateHash = 0x83F8EF11C161AA7C;

    cTkFixedString<32,char> macLocatorType;
    eMergeProbabilityOptions MergeProbabilityOptions;
    cTkDynamicArray<cTkLSystemLocatorEntry> maEntries;
}
