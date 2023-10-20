#pragma once
#include <metadata/metadata_common.h>
enum eConflictLevel
{
    EConflictLevel_Low = 0,
    EConflictLevel_Default = 1,
    EConflictLevel_High = 2,
    EConflictLevel_Pirate = 3,
}

class cGcPlayerConflictData
{
    static unsigned long long muNameHash = 0xF47FD4328A49A000;
    static unsigned long long muTemplateHash = 0x422DB53CD492B6BF;

    eConflictLevel ConflictLevel;
}
