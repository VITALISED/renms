#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcuniverseaddressdata.meta.h>
#include <metadata/gamestate/gcgamemode.meta.h>

class cGcAtlasBasesRequest
{
    static unsigned long long muNameHash = 0x1E454D73CB415CEA;
    static unsigned long long muTemplateHash = 0x93B2FDEC3B2BFFDA;

    cGcUniverseAddressData UniverseAddress;
    cGcGameMode GameMode;
    int miMaxResults;
    int miMaxBytes;
    int miMinVersion;
    int miMaxVersion;
    cTkFixedString<32,char> macSpecificUserId;
}
