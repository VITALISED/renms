#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcuniverseaddressdata.meta.h>
#include <metadata/reality/gcdiscoverytype.meta.h>

class cGcAtlasDiscoveryData
{
    static unsigned long long muNameHash = 0x34272E24BB717FCB;
    static unsigned long long muTemplateHash = 0x96A8C4489DAC50F2;

    cGcUniverseAddressData UniverseAddress;
    cGcDiscoveryType Type;
    int miPayloadElements;
    cTkFixedArray<unsigned long long> maPayload;
}
