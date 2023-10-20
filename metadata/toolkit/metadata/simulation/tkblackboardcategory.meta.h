#pragma once
#include <metadata/metadata_common.h>
enum eBlackboardCategory
{
    EBlackboardCategory_Local = 0,
    EBlackboardCategory_Archetype = 1,
    EBlackboardCategory_PlayerControl = 2,
}

class cTkBlackboardCategory
{
    static unsigned long long muNameHash = 0x29BC4AF5B8027FD;
    static unsigned long long muTemplateHash = 0x9458BEB87AD22C4D;

    eBlackboardCategory BlackboardCategory;
}
