#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcmaintenancegroupentry.meta.h>

class cGcMaintenanceGroup
{
    static unsigned long long muNameHash = 0x989F3C45C63EA6B8;
    static unsigned long long muTemplateHash = 0x824837314D33B4A;

    cTkDynamicArray<cGcMaintenanceGroupEntry> maTable;
}
