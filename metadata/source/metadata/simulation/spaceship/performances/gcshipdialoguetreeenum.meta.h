#pragma once
#include <metadata/metadata_common.h>
enum eDialogueTree
{
    EDialogueTree_Bribe = 0,
    EDialogueTree_Beg = 1,
    EDialogueTree_Ambush = 2,
    EDialogueTree_Trade = 3,
    EDialogueTree_Help = 4,
    EDialogueTree_Goods = 5,
    EDialogueTree_Hostile = 6,
}

class cGcShipDialogueTreeEnum
{
    static unsigned long long muNameHash = 0xBC8B5F2250F65891;
    static unsigned long long muTemplateHash = 0xCBD94A72AECBA114;

    eDialogueTree DialogueTree;
}
