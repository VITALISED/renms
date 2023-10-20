#pragma once
#include <metadata/metadata_common.h>
enum eLegality
{
    ELegality_Legal = 0,
    ELegality_Illegal = 1,
}

class cGcLegality
{
    static unsigned long long muNameHash = 0x769CBCB21A7D4913;
    static unsigned long long muTemplateHash = 0xADA9902A1B950F4D;

    eLegality Legality;
}
