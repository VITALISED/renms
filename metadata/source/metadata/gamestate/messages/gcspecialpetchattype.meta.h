#pragma once
#include <metadata/metadata_common.h>
enum eSpecialPetChatType
{
    ESpecialPetChatType_Monster = 0,
    ESpecialPetChatType_Quad = 1,
    ESpecialPetChatType_MiniRobo = 2,
}

class cGcSpecialPetChatType
{
    static unsigned long long muNameHash = 0x3748852F6280E90F;
    static unsigned long long muTemplateHash = 0x4FDA1EC6477A8B8C;

    eSpecialPetChatType SpecialPetChatType;
}
