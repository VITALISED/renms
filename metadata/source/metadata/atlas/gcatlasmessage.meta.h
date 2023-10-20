#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcuniverseaddressdata.meta.h>

class cGcAtlasMessage
{
    static unsigned long long muNameHash = 0x81E5018BD0B4C94D;
    static unsigned long long muTemplateHash = 0x5C61E84BEA8B2ECE;

    cGcUniverseAddressData UniverseAddress;
    cTkFixedString<128,char> macCustomName;
    cTkVector3 mPosition;
    int miColourIndex;
}
