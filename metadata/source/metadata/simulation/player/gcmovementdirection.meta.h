#pragma once
#include <metadata/metadata_common.h>
enum eMovementDirection
{
    EMovementDirection_WorldRelative = 0,
    EMovementDirection_BodyRelative = 1,
    EMovementDirection_HeadRelative = 2,
    EMovementDirection_NotSet = 3,
}

class cGcMovementDirection
{
    static unsigned long long muNameHash = 0x59A54DA2535D6C79;
    static unsigned long long muTemplateHash = 0x4499ADCE00A38AC7;

    eMovementDirection MovementDirection;
}
