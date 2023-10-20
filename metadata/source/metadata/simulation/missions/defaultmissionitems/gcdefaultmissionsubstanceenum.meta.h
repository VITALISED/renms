#pragma once
#include <metadata/metadata_common.h>
enum eDefaultSubstanceType
{
    EDefaultSubstanceType_None = 0,
    EDefaultSubstanceType_PrimarySubstance = 1,
    EDefaultSubstanceType_SecondarySubstance = 2,
}

class cGcDefaultMissionSubstanceEnum
{
    static unsigned long long muNameHash = 0x1BAC8ECF2C7CC8FC;
    static unsigned long long muTemplateHash = 0xB51C8F9B01D93DC9;

    eDefaultSubstanceType DefaultSubstanceType;
}
