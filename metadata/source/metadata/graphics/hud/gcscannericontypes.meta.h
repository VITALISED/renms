#pragma once
#include <metadata/metadata_common.h>
enum eScanIconType
{
    EScanIconType_None = 0,
    EScanIconType_Health = 1,
    EScanIconType_Shield = 2,
    EScanIconType_Hazard = 3,
    EScanIconType_LifeSupport = 4,
    EScanIconType_Tech = 5,
    EScanIconType_BluePlant = 6,
    EScanIconType_CaveSubstance = 7,
    EScanIconType_LaunchCrystals = 8,
    EScanIconType_Power = 9,
    EScanIconType_Carbon = 10,
    EScanIconType_CarbonPlus = 11,
    EScanIconType_Oxygen = 12,
    EScanIconType_Mineral = 13,
    EScanIconType_Sodium = 14,
    EScanIconType_SodiumPlus = 15,
    EScanIconType_Crate = 16,
    EScanIconType_Artifact = 17,
    EScanIconType_Plant = 18,
    EScanIconType_HazardPlant = 19,
    EScanIconType_ArtifactCrate = 20,
    EScanIconType_BuriedTech = 21,
    EScanIconType_BuriedRare = 22,
    EScanIconType_Drone = 23,
    EScanIconType_CustomMarker = 24,
    EScanIconType_SignalBooster = 25,
    EScanIconType_Refiner = 26,
    EScanIconType_Grave = 27,
    EScanIconType_Rare1 = 28,
    EScanIconType_Rare2 = 29,
    EScanIconType_Rare3 = 30,
    EScanIconType_Pearl = 31,
    EScanIconType_RareEgg = 32,
    EScanIconType_HazardEgg = 33,
    EScanIconType_FishFiend = 34,
    EScanIconType_Clam = 35,
    EScanIconType_CaveStone = 36,
    EScanIconType_StormCrystal = 37,
    EScanIconType_BiomeTrophy = 38,
    EScanIconType_PowerHotspot = 39,
    EScanIconType_MineralHotspot = 40,
    EScanIconType_GasHotspot = 41,
    EScanIconType_HarvestPlant = 42,
    EScanIconType_Cooker = 43,
    EScanIconType_CreaturePoop = 44,
    EScanIconType_FreighterTeleporter = 45,
    EScanIconType_FreighterDoor = 46,
    EScanIconType_FreighterTerminal = 47,
    EScanIconType_FreighterHeater = 48,
    EScanIconType_FreighterDataPad = 49,
    EScanIconType_LandedPilot = 50,
    EScanIconType_PetEgg = 51,
    EScanIconType_Sandworm = 52,
    EScanIconType_FriendlyDrone = 53,
}

class cGcScannerIconTypes
{
    static unsigned long long muNameHash = 0x8A4027FC041677F0;
    static unsigned long long muTemplateHash = 0xDF9C8B4D08CC8914;

    eScanIconType ScanIconType;
}
