#pragma once
#include <metadata/metadata_common.h>

class cGcPersistentBaseEntry
{
    static unsigned long long muNameHash = 0xD040D4124F0456EF;
    static unsigned long long muTemplateHash = 0xDB39E3870A3CBC82;

    unsigned long long mui64Timestamp;
    TkID<128> mObjectID;
    unsigned long long mui64UserData;
    cTkVector3 mPosition;
    cTkVector3 mUp;
    cTkVector3 mAt;
    cTkFixedString<64,char> macMessage;
}
