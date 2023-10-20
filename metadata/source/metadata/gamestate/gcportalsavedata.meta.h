#pragma once
#include <metadata/metadata_common.h>

class cGcPortalSaveData
{
    static unsigned long long muNameHash = 0x1B40C15E29F0E6FF;
    static unsigned long long muTemplateHash = 0x9A4BE3B0AB0F3DDD;

    cTkSeed mPortalSeed;
    unsigned long long mui64LastPortalUA;
    bool mbIsStoryPortal;
}
