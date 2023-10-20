#pragma once
#include <metadata/metadata_common.h>
enum ePalette
{
    EPalette_Grass = 0,
    EPalette_Plant = 1,
    EPalette_Leaf = 2,
    EPalette_Wood = 3,
    EPalette_Rock = 4,
    EPalette_Stone = 5,
    EPalette_Crystal = 6,
    EPalette_Sand = 7,
    EPalette_Dirt = 8,
    EPalette_Metal = 9,
    EPalette_Paint = 10,
    EPalette_Plastic = 11,
    EPalette_Fur = 12,
    EPalette_Scale = 13,
    EPalette_Feather = 14,
    EPalette_Water = 15,
    EPalette_Cloud = 16,
    EPalette_Sky = 17,
    EPalette_Space = 18,
    EPalette_Underbelly = 19,
    EPalette_Undercoat = 20,
    EPalette_Snow = 21,
    EPalette_SkyHorizon = 22,
    EPalette_SkyFog = 23,
    EPalette_SkyHeightFog = 24,
    EPalette_SkySunset = 25,
    EPalette_SkyNight = 26,
    EPalette_WaterNear = 27,
    EPalette_SpaceCloud = 28,
    EPalette_SpaceBottom = 29,
    EPalette_SpaceSolar = 30,
    EPalette_SpaceLight = 31,
    EPalette_Warrior = 32,
    EPalette_Scientific = 33,
    EPalette_Trader = 34,
    EPalette_WarriorAlt = 35,
    EPalette_ScientificAlt = 36,
    EPalette_TraderAlt = 37,
    EPalette_RockSaturated = 38,
    EPalette_RockLight = 39,
    EPalette_RockDark = 40,
    EPalette_PlanetRing = 41,
    EPalette_Custom_Head = 42,
    EPalette_Custom_Torso = 43,
    EPalette_Custom_Chest_Armour = 44,
    EPalette_Custom_Backpack = 45,
    EPalette_Custom_Arms = 46,
    EPalette_Custom_Hands = 47,
    EPalette_Custom_Legs = 48,
    EPalette_Custom_Feet = 49,
    EPalette_Cave = 50,
    EPalette_GrassAlt = 51,
    EPalette_BioShip_Body = 52,
    EPalette_BioShip_Underbelly = 53,
    EPalette_BioShip_Cockpit = 54,
    EPalette_SailShip_Sails = 55,
    EPalette_Freighter = 56,
    EPalette_FreighterPaint = 57,
}

class cTkPaletteTexture
{
    static unsigned long long muNameHash = 0x6A57676B42321253;
    static unsigned long long muTemplateHash = 0xE877E2E7DCA338C7;

    ePalette Palette;
    eColourAlt ColourAlt;
}
