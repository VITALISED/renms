#pragma once
#include <metadata/metadata_common.h>

class cGcAtmosphereList
{
    static unsigned long long muNameHash = 0x594FCBE47D02F5DF;
    static unsigned long long muTemplateHash = 0xF7CD6DB20A539DD3;

    cTkDynamicArray<cTkFixedString<128,char>> maAtmospheres;
}
