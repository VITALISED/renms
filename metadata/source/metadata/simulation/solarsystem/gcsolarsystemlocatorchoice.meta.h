#pragma once
#include <metadata/metadata_common.h>
enum eChoice
{
    EChoice_LookupName = 0,
    EChoice_AnyOfType = 1,
    EChoice_SpecificIndex = 2,
    EChoice_InFrontOfPlayer = 3,
}
#include <?>

class cGcSolarSystemLocatorChoice
{
    static unsigned long long muNameHash = 0x84B1F1D780A31A2A;
    static unsigned long long muTemplateHash = 0xFCC48A5DDF4D778C;

    eChoice Choice;
    cTkFixedString<32,char> macName;
    cGcSolarSystemLocatorTypes Type;
    int miIndex;
}
