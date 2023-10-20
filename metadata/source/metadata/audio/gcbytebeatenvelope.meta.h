#pragma once
#include <metadata/metadata_common.h>
enum eByteBeatEnvelope
{
    EByteBeatEnvelope_Short = 0,
    EByteBeatEnvelope_Med = 1,
    EByteBeatEnvelope_Long = 2,
}

class cGcByteBeatEnvelope
{
    static unsigned long long muNameHash = 0x3D8CDA50E9CD9F10;
    static unsigned long long muTemplateHash = 0xD80E9187D6043871;

    eByteBeatEnvelope ByteBeatEnvelope;
}
