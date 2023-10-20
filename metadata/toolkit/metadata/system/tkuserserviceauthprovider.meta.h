#pragma once
#include <metadata/metadata_common.h>
enum eAuthProvider
{
    EAuthProvider_Null = 0,
    EAuthProvider_PSN = 1,
    EAuthProvider_Steam = 2,
    EAuthProvider_Galaxy = 3,
    EAuthProvider_Xbox = 4,
    EAuthProvider_WeGame = 5,
    EAuthProvider_NSO = 6,
}

class cTkUserServiceAuthProvider
{
    static unsigned long long muNameHash = 0x91EF3068AEC32FB7;
    static unsigned long long muTemplateHash = 0xBEFB647B9E09BAE7;

    eAuthProvider AuthProvider;
}
