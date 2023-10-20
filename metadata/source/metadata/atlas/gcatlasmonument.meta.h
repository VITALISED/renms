#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcAtlasMonument
{
    static unsigned long long muNameHash = 0xBD4D110E1D076CE;
    static unsigned long long muTemplateHash = 0xA60747DE40AB1CA5;

    cGcUniverseAddressData UniverseAddress;
    cTkVector3 mPosition;
    cTkVector3 mAt;
    cTkFixedString<64,char> macRID;
    cTkFixedString<64,char> macCreatorName;
    cTkFixedString<64,char> macCreatorOnlineID;
    cTkFixedString<64,char> macCocreatorName;
    cTkFixedString<64,char> macCocreatorOnlineID;
    unsigned long long mui64Timestamp;
}
