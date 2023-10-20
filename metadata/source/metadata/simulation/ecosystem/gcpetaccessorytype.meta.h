#pragma once
#include <metadata/metadata_common.h>
enum ePetAccessory
{
    EPetAccessory_None = 0,
    EPetAccessory_CargoCylinder = 1,
    EPetAccessory_Containers = 2,
    EPetAccessory_ShieldArmour = 3,
    EPetAccessory_SolarBattery = 4,
    EPetAccessory_Tank = 5,
    EPetAccessory_WingPanel = 6,
    EPetAccessory_TravelPack = 7,
    EPetAccessory_SpacePack = 8,
    EPetAccessory_CargoLong = 9,
    EPetAccessory_Antennae = 10,
    EPetAccessory_Computer = 11,
    EPetAccessory_Toolbelt = 12,
    EPetAccessory_LeftCanisters = 13,
    EPetAccessory_LeftEnergyCoil = 14,
    EPetAccessory_LeftFrigateTurret = 15,
    EPetAccessory_LeftHeadLights = 16,
    EPetAccessory_LeftArmourPlate = 17,
    EPetAccessory_LeftTurret = 18,
    EPetAccessory_LeftSupportSystem = 19,
    EPetAccessory_RightCanisters = 20,
    EPetAccessory_RightEnergyCoil = 21,
    EPetAccessory_RightFrigateTurret = 22,
    EPetAccessory_RightHeadLights = 23,
    EPetAccessory_RightArmourPlate = 24,
    EPetAccessory_RightTurret = 25,
    EPetAccessory_RightSupportSystem = 26,
}

class cGcPetAccessoryType
{
    static unsigned long long muNameHash = 0xB47279F1694E0681;
    static unsigned long long muTemplateHash = 0xD19A2E040F8046A2;

    ePetAccessory PetAccessory;
}
