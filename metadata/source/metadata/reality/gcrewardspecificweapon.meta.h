#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcinventorycontainer.meta.h>
#include <metadata/gamestate/gcinventorylayout.meta.h>
#include <metadata/resource/gcexactresource.meta.h>
#include <metadata/simulation/gcweaponclasses.meta.h>

class cGcRewardSpecificWeapon
{
    static unsigned long long muNameHash = 0xF3710AB8A6F40A88;
    static unsigned long long muTemplateHash = 0x7125A5C6424DD767;

    cGcInventoryContainer WeaponInventory;
    cGcInventoryLayout WeaponLayout;
    cGcExactResource WeaponResource;
    cGcWeaponClasses WeaponType;
    TkID<256> mNameOverride;
    bool mbIsGift;
    bool mbIsRewardWeapon;
    bool mbFormatAsSeasonal;
}
