#pragma once
#include <metadata/metadata_common.h>
enum eInventoryStackLimitsDifficulty
{
    EInventoryStackLimitsDifficulty_High = 0,
    EInventoryStackLimitsDifficulty_Normal = 1,
    EInventoryStackLimitsDifficulty_Low = 2,
}

class cGcInventoryStackLimitsDifficultyOption
{
    static unsigned long long muNameHash = 0xBC2BBF55EEB95C06;
    static unsigned long long muTemplateHash = 0x5F13D862186143AB;

    eInventoryStackLimitsDifficulty InventoryStackLimitsDifficulty;
}
