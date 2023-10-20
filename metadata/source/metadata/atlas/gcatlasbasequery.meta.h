#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcAtlasBaseQuery
{
    static unsigned long long muNameHash = 0xC263B56059CD6513;
    static unsigned long long muTemplateHash = 0xF3CB570D765D079;

    cGcUniverseAddressData UniverseAddress;
    cGcGameMode GameMode;
    cTkFixedString<32,char> macUserId;
    cTkVector3 mPosition;
}
