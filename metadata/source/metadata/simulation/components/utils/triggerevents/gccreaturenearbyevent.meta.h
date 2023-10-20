#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCreatureNearbyEvent
{
    static unsigned long long muNameHash = 0x42869E79D40A84C1;
    static unsigned long long muTemplateHash = 0x150A3F080C5CF432;

    cTkDynamicArray<cGcCreatureAlertData> maAlertTable;
    bool mbInverse;
}
