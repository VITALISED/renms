#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/behaviours/data/gccreatureiktype.meta.h>

class cGcCreatureIkData
{
    static unsigned long long muNameHash = 0x3B356CAA76CA79F8;
    static unsigned long long muTemplateHash = 0x244274B9B0B2910C;

    cGcCreatureIkType Type;
    cTkFixedString<256,char> macJointName;
}
