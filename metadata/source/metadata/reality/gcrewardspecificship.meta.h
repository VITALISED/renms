#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcRewardSpecificShip
{
    static unsigned long long muNameHash = 0x977CF58471E48CD1;
    static unsigned long long muTemplateHash = 0x9CAEDE34EE21604C;

    cGcResourceElement ShipResource;
    cGcInventoryLayout ShipLayout;
    cGcInventoryContainer ShipInventory;
    int miCostAmount;
    cGcCurrency CostCurrency;
    cGcSpaceshipClasses ShipType;
    bool mbUseOverrideSizeType;
    cGcInventoryLayoutSizeType OverrideSizeType;
    TkID<256> mNameOverride;
    bool mbIsGift;
    bool mbIsRewardShip;
    bool mbFormatAsSeasonal;
}
