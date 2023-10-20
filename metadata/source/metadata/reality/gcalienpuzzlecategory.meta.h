#pragma once
#include <metadata/metadata_common.h>
enum eAlienPuzzleCategory
{
    EAlienPuzzleCategory_Default = 0,
    EAlienPuzzleCategory_GuildTraderNone = 1,
    EAlienPuzzleCategory_GuildTraderLow = 2,
    EAlienPuzzleCategory_GuildTraderMed = 3,
    EAlienPuzzleCategory_GuildTraderHigh = 4,
    EAlienPuzzleCategory_GuildTraderBest = 5,
    EAlienPuzzleCategory_GuildWarriorNone = 6,
    EAlienPuzzleCategory_GuildWarriorLow = 7,
    EAlienPuzzleCategory_GuildWarriorMed = 8,
    EAlienPuzzleCategory_GuildWarriorHigh = 9,
    EAlienPuzzleCategory_GuildWarriorBest = 10,
    EAlienPuzzleCategory_GuildExplorerNone = 11,
    EAlienPuzzleCategory_GuildExplorerLow = 12,
    EAlienPuzzleCategory_GuildExplorerMed = 13,
    EAlienPuzzleCategory_GuildExplorerHigh = 14,
    EAlienPuzzleCategory_GuildExplorerBest = 15,
    EAlienPuzzleCategory_BiomeHot = 16,
    EAlienPuzzleCategory_BiomeCold = 17,
    EAlienPuzzleCategory_BiomeLush = 18,
    EAlienPuzzleCategory_BiomeDusty = 19,
    EAlienPuzzleCategory_BiomeTox = 20,
    EAlienPuzzleCategory_BiomeRad = 21,
    EAlienPuzzleCategory_BiomeWeird = 22,
    EAlienPuzzleCategory_LocationSpaceStation = 23,
    EAlienPuzzleCategory_LocationShop = 24,
    EAlienPuzzleCategory_LocationOutpost = 25,
    EAlienPuzzleCategory_LocationObservatory = 26,
    EAlienPuzzleCategory_Walking = 27,
    EAlienPuzzleCategory_ExtremeWeather = 28,
    EAlienPuzzleCategory_ExtremeSentinels = 29,
    EAlienPuzzleCategory_WaterPlanet = 30,
    EAlienPuzzleCategory_FreighterCrew = 31,
    EAlienPuzzleCategory_FreighterCrewOwned = 32,
    EAlienPuzzleCategory_ShipShop = 33,
    EAlienPuzzleCategory_SuitShop = 34,
    EAlienPuzzleCategory_WeapShop = 35,
    EAlienPuzzleCategory_VehicleShop = 36,
    EAlienPuzzleCategory_MoodVeryPositive = 37,
    EAlienPuzzleCategory_MoodPositive = 38,
    EAlienPuzzleCategory_MoodNeutral = 39,
    EAlienPuzzleCategory_MoodNegative = 40,
    EAlienPuzzleCategory_MoodVeryNegative = 41,
    EAlienPuzzleCategory_Proc = 42,
    EAlienPuzzleCategory_FirstAbandonedFreighter = 43,
    EAlienPuzzleCategory_StandardAbandonedFreighter = 44,
    EAlienPuzzleCategory_BiomeSwamp = 45,
    EAlienPuzzleCategory_BiomeLava = 46,
    EAlienPuzzleCategory_AbandonedSystem = 47,
    EAlienPuzzleCategory_InhabitedSystem = 48,
    EAlienPuzzleCategory_SettlementOwned = 49,
    EAlienPuzzleCategory_SettlementNotOwned = 50,
    EAlienPuzzleCategory_PirateStation = 51,
    EAlienPuzzleCategory_StandardPilot = 52,
}

class cGcAlienPuzzleCategory
{
    static unsigned long long muNameHash = 0x428DC2A675E89B6D;
    static unsigned long long muTemplateHash = 0x62BB97425837BAD1;

    eAlienPuzzleCategory AlienPuzzleCategory;
}
