#pragma once
#include <metadata/metadata_common.h>
enum eSpawnMode
{
    ESpawnMode_None = 0,
    ESpawnMode_UseSeed = 1,
    ESpawnMode_UseAltID = 2,
}

class cGcSpaceStationSpawnData
{
    static unsigned long long muNameHash = 0x1FD33D08A7082C22;
    static unsigned long long muTemplateHash = 0xB2FF18440DA1DBF7;

    eSpawnMode SpawnMode;
    cTkSeed mSeed;
    cTkFixedString<256,char> macAltId;
    cTkVector3 mSpawnPosition;
    cTkVector3 mSpawnFacing;
}
