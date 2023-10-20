#pragma once
#include <metadata/metadata_common.h>

class cTkLSystemRuleTemplate
{
    static unsigned long long muNameHash = 0x89F774448E48DD4A;
    static unsigned long long muTemplateHash = 0x8B6983BE023BBC0A;

    cTkFixedString<32,char> macName;
    cTkFixedString<128,char> macLSystem;
}
