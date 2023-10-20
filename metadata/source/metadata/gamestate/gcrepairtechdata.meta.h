#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcmaintenancecontainer.meta.h>
#include <metadata/gamestate/gcinventoryindex.meta.h>

class cGcRepairTechData
{
    static unsigned long long muNameHash = 0xD610CA25729E63C3;
    static unsigned long long muTemplateHash = 0xD60BF4F6EBCDA98;

    cGcMaintenanceContainer MaintenanceContainer;
    int miInventoryType;
    int miInventorySubIndex;
    cGcInventoryIndex InventoryIndex;
}
