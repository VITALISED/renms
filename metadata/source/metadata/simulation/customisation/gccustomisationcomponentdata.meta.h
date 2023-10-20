#pragma once
#include <metadata/metadata_common.h>
enum eCustomisationDataType
{
    ECustomisationDataType_Player = 0,
    ECustomisationDataType_Vehicle = 1,
    ECustomisationDataType_Weapon = 2,
    ECustomisationDataType_Ship_01 = 3,
    ECustomisationDataType_Ship_02 = 4,
    ECustomisationDataType_Ship_03 = 5,
    ECustomisationDataType_Ship_04 = 6,
    ECustomisationDataType_Ship_05 = 7,
    ECustomisationDataType_Ship_06 = 8,
    ECustomisationDataType_Vehicle_Bike = 9,
    ECustomisationDataType_Vehicle_Truck = 10,
    ECustomisationDataType_Vehicle_WheeledBike = 11,
    ECustomisationDataType_Vehicle_Hovercraft = 12,
    ECustomisationDataType_Vehicle_Submarine = 13,
    ECustomisationDataType_Vehicle_Mech = 14,
    ECustomisationDataType_Freighter = 15,
    ECustomisationDataType_Pet = 16,
    ECustomisationDataType_Ship_07 = 17,
    ECustomisationDataType_Ship_08 = 18,
    ECustomisationDataType_Ship_09 = 19,
    ECustomisationDataType_Ship_10 = 20,
    ECustomisationDataType_Ship_11 = 21,
    ECustomisationDataType_Ship_12 = 22,
}

class cGcCustomisationComponentData
{
    static unsigned long long muNameHash = 0x52B0589631E97AC5;
    static unsigned long long muTemplateHash = 0xD42BD8870A05E97F;

    eCustomisationDataType CustomisationDataType;
}
