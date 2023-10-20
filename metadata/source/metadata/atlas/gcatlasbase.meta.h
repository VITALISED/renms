#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcuniverseaddressdata.meta.h>

class cGcAtlasBase
{
    static unsigned long long muNameHash = 0xF676D3AEF2BB991F;
    static unsigned long long muTemplateHash = 0x60EA1CB605AA45B9;

    cTkFixedString<512,char> macOpaqueData;
    cGcUniverseAddressData UniverseAddress;
    cTkFixedString<128,char> macCustomName;
}
