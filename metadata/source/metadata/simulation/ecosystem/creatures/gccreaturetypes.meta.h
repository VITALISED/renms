#pragma once
#include <metadata/metadata_common.h>
enum eCreatureType
{
    ECreatureType_None = 0,
    ECreatureType_Bird = 1,
    ECreatureType_FlyingLizard = 2,
    ECreatureType_FlyingSnake = 3,
    ECreatureType_Butterfly = 4,
    ECreatureType_FlyingBeetle = 5,
    ECreatureType_Beetle = 6,
    ECreatureType_Fish = 7,
    ECreatureType_Shark = 8,
    ECreatureType_Crab = 9,
    ECreatureType_Snake = 10,
    ECreatureType_Dino = 11,
    ECreatureType_Antelope = 12,
    ECreatureType_Rodent = 13,
    ECreatureType_Cat = 14,
    ECreatureType_Fiend = 15,
    ECreatureType_Drone = 16,
    ECreatureType_Quad = 17,
    ECreatureType_Walker = 18,
    ECreatureType_Predator = 19,
    ECreatureType_PlayerPredator = 20,
    ECreatureType_Prey = 21,
    ECreatureType_Passive = 22,
    ECreatureType_FishPredator = 23,
    ECreatureType_FishPrey = 24,
    ECreatureType_FiendFishSmall = 25,
    ECreatureType_FiendFishBig = 26,
    ECreatureType_Jellyfish = 27,
    ECreatureType_LandJellyfish = 28,
    ECreatureType_RockCreature = 29,
    ECreatureType_MiniFiend = 30,
    ECreatureType_Floater = 31,
    ECreatureType_Scuttler = 32,
    ECreatureType_Slug = 33,
    ECreatureType_MiniDrone = 34,
    ECreatureType_MiniRobo = 35,
    ECreatureType_SpaceFloater = 36,
    ECreatureType_Weird = 37,
    ECreatureType_SeaSnake = 38,
    ECreatureType_SandWorm = 39,
    ECreatureType_ProtoRoller = 40,
    ECreatureType_ProtoFlyer = 41,
    ECreatureType_ProtoDigger = 42,
    ECreatureType_Plough = 43,
    ECreatureType_Digger = 44,
    ECreatureType_Drill = 45,
    ECreatureType_Brainless = 46,
    ECreatureType_Pet = 47,
}

class cGcCreatureTypes
{
    static unsigned long long muNameHash = 0xF848BA9A5DFC4197;
    static unsigned long long muTemplateHash = 0x79FB96ED0674516A;

    eCreatureType CreatureType;
}
