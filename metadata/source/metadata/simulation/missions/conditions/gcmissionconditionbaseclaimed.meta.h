#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eIsOnCurrentSystem
{
    EIsOnCurrentSystem_DontCare = 0,
    EIsOnCurrentSystem_Yes = 1,
    EIsOnCurrentSystem_No = 2,
}

class cGcMissionConditionBaseClaimed
{
    static unsigned long long muNameHash = 0xD0B8CB5F60C6775;
    static unsigned long long muTemplateHash = 0x66ABFBB0092864D2;

    bool mbClaimed;
    cGcPersistentBaseTypes Base;
    eIsOnCurrentSystem IsOnCurrentSystem;
    bool mbMustBeInBase;
    int miMinParts;
}
