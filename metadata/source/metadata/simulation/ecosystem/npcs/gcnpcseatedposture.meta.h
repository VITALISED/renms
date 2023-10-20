#pragma once
#include <metadata/metadata_common.h>
enum eNPCSeatedPosture
{
    ENPCSeatedPosture_Sofa = 0,
    ENPCSeatedPosture_Sit = 1,
}

class cGcNPCSeatedPosture
{
    static unsigned long long muNameHash = 0xDE7AA917D5163592;
    static unsigned long long muTemplateHash = 0x3A01B0DDBBB3040D;

    eNPCSeatedPosture NPCSeatedPosture;
}
