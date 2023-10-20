#pragma once
#include <metadata/metadata_common.h>
enum eUniqueIdType
{
    EUniqueIdType_Invalid = 0,
    EUniqueIdType_Deterministic = 1,
    EUniqueIdType_UserSpawned = 2,
}

class cGcUniqueIdData
{
    static unsigned long long muNameHash = 0xCA58D35FFFB37091;
    static unsigned long long muTemplateHash = 0xB0959B82BA453EF8;

    eUniqueIdType UniqueIdType;
    unsigned long long mui64DeterministicSeed;
    unsigned int muiIteration;
    cTkFixedString<64,char> macOnlineID;
    cTkFixedString<32,char> macPlatformID;
}
