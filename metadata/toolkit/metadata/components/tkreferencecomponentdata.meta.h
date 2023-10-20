#pragma once
#include <metadata/metadata_common.h>

class cTkReferenceComponentData
{
    static unsigned long long muNameHash = 0xECF89DFCB0AF1DBF;
    static unsigned long long muTemplateHash = 0x1497A90491689A51;

    cTkFixedString<128,char> macReference;
    cTkFixedString<128,char> macLSystem;
}
