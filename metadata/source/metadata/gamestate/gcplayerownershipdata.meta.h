#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcPlayerOwnershipData
{
    static unsigned long long muNameHash = 0xF5D7FBFDE561D6FB;
    static unsigned long long muTemplateHash = 0x58F4C24EAC0D8DC0;

    cTkFixedString<32,char> macName;
    cGcResourceElement Resource;
    cGcInventoryContainer Inventory;
    cGcInventoryContainer Inventory_Cargo;
    cGcInventoryContainer Inventory_TechOnly;
    cGcInventoryLayout InventoryLayout;
    unsigned long long mui64Location;
    cTkVector4 mPosition;
    cTkVector4 mDirection;
}
