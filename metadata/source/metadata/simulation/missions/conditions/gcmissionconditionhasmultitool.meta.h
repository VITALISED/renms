#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcinventoryclass.meta.h>

class cGcMissionConditionHasMultiTool
{
    static unsigned long long muNameHash = 0xF65D2CFF75A05B47;
    static unsigned long long muTemplateHash = 0xCBBAA8BC9555C8C8;

    cGcInventoryClass InventoryClass;
    bool mbCheckAllTools;
    bool mbBetterClassMatches;
    bool mbTakeValueFromSeasonData;
}
