#pragma once
#include <metadata/metadata_common.h>
enum eSizeType
{
    ESizeType_SciSmall = 0,
    ESizeType_SciMedium = 1,
    ESizeType_SciLarge = 2,
    ESizeType_FgtSmall = 3,
    ESizeType_FgtMedium = 4,
    ESizeType_FgtLarge = 5,
    ESizeType_ShuSmall = 6,
    ESizeType_ShtMedium = 7,
    ESizeType_ShtLarge = 8,
    ESizeType_DrpSmall = 9,
    ESizeType_DrpMedium = 10,
    ESizeType_DrpLarge = 11,
    ESizeType_RoySmall = 12,
    ESizeType_RoyMedium = 13,
    ESizeType_RoyLarge = 14,
    ESizeType_AlienSmall = 15,
    ESizeType_AlienMedium = 16,
    ESizeType_AlienLarge = 17,
    ESizeType_SailSmall = 18,
    ESizeType_SailMedium = 19,
    ESizeType_SailLarge = 20,
    ESizeType_WeaponSmall = 21,
    ESizeType_WeaponMedium = 22,
    ESizeType_WeaponLarge = 23,
    ESizeType_FreighterSmall = 24,
    ESizeType_FreighterMedium = 25,
    ESizeType_FreighterLarge = 26,
    ESizeType_VehicleSmall = 27,
    ESizeType_VehicleMedium = 28,
    ESizeType_VehicleLarge = 29,
    ESizeType_ChestSmall = 30,
    ESizeType_ChestMedium = 31,
    ESizeType_ChestLarge = 32,
    ESizeType_ChestCapsule = 33,
    ESizeType_Suit = 34,
    ESizeType_MaintObject = 35,
    ESizeType_RocketLocker = 36,
}

class cGcInventoryLayoutSizeType
{
    static unsigned long long muNameHash = 0xCFB91CCA40995CDC;
    static unsigned long long muTemplateHash = 0xAC86A11A653B6456;

    eSizeType SizeType;
}
