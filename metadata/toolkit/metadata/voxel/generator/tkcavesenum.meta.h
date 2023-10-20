#pragma once
#include <metadata/metadata_common.h>
enum eCaveTypes
{
    ECaveTypes_Underground = 0,
}

class cTkCavesEnum
{
    static unsigned long long muNameHash = 0x380AC5FAFC25FE69;
    static unsigned long long muTemplateHash = 0xC82D553728BC3D02;

    eCaveTypes CaveTypes;
}
