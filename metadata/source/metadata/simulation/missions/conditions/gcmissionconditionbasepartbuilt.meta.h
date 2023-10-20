#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum ePartInCurrentBase
{
    EPartInCurrentBase_DontCare = 0,
    EPartInCurrentBase_YesAllPlayerOwned = 1,
}

class cGcMissionConditionBasePartBuilt
{
    static unsigned long long muNameHash = 0x75A4AF2BCC689FD2;
    static unsigned long long muTemplateHash = 0xFC34477E2A2EDC37;

    TkID<128> mPartID;
    bool mbTakeIDFromSeasonData;
    int miCount;
    cGcBuildingPartSearchType Type;
    ePartInCurrentBase PartInCurrentBase;
}
