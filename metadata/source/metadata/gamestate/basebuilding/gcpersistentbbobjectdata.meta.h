#pragma once
#include <metadata/metadata_common.h>

class cGcPersistentBBObjectData
{
    static unsigned long long muNameHash = 0xCD3485C140AE7B57;
    static unsigned long long muTemplateHash = 0xFAD41A8138D2B51E;

    unsigned long long mui64Timestamp;
    TkID<128> mObjectID;
    unsigned long long mui64GalacticAddress;
    unsigned long long mui64RegionSeed;
    unsigned long long mui64UserData;
    cTkVector3 mPosition;
    cTkVector3 mUp;
    cTkVector3 mAt;
}
