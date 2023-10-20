#pragma once
#include <metadata/metadata_common.h>
enum eBaseDefenceStatus
{
    EBaseDefenceStatus_AttackingTarget = 0,
    EBaseDefenceStatus_Alert = 1,
    EBaseDefenceStatus_SearchingForTarget = 2,
    EBaseDefenceStatus_Disabled = 3,
    EBaseDefenceStatus_Security = 4,
}

class cGcBaseDefenceStatusType
{
    static unsigned long long muNameHash = 0x10D5ED9C9EE19797;
    static unsigned long long muTemplateHash = 0xFB0EDF75D5C71764;

    eBaseDefenceStatus BaseDefenceStatus;
}
