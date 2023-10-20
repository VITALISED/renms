#pragma once
#include <metadata/metadata_common.h>

class cGcTelemetryStat
{
    static unsigned long long muNameHash = 0xEBD25F53C92AC4C7;
    static unsigned long long muTemplateHash = 0xADCFA1F25E016AA;

    TkID<128> mId;
    TkID<128> mType;
    int miValue;
}
