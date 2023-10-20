#pragma once
#include <metadata/metadata_common.h>
enum eMissionPlayerLocation
{
    EMissionPlayerLocation_OnPlanet = 0,
    EMissionPlayerLocation_OnPlanetInVehicle = 1,
    EMissionPlayerLocation_InShipLanded = 2,
    EMissionPlayerLocation_InShipInPlanetOrbit = 3,
    EMissionPlayerLocation_InShipInSpace = 4,
    EMissionPlayerLocation_InShipAnywhere = 5,
    EMissionPlayerLocation_InSpaceStation = 6,
    EMissionPlayerLocation_InFreighter = 7,
    EMissionPlayerLocation_InYourFreighter = 8,
    EMissionPlayerLocation_InOtherPlayerFreighter = 9,
    EMissionPlayerLocation_Underground = 10,
    EMissionPlayerLocation_InBuilding = 11,
    EMissionPlayerLocation_Frigate = 12,
    EMissionPlayerLocation_Underwater = 13,
    EMissionPlayerLocation_UnderwaterSwimming = 14,
    EMissionPlayerLocation_DeepUnderwater = 15,
    EMissionPlayerLocation_InSubmarine = 16,
    EMissionPlayerLocation_Frigate_Damaged = 17,
    EMissionPlayerLocation_FreighterConstructionArea = 18,
    EMissionPlayerLocation_FriendsPlanetBase = 19,
    EMissionPlayerLocation_OnPlanetSurface = 20,
    EMissionPlayerLocation_InNexus = 21,
    EMissionPlayerLocation_InNexusOnFoot = 22,
    EMissionPlayerLocation_AbandonedFreighterExterior = 23,
    EMissionPlayerLocation_AbandonedFreighterInterior = 24,
    EMissionPlayerLocation_AbandonedFreighterAirlock = 25,
    EMissionPlayerLocation_AtlasStation = 26,
}

class cGcMissionConditionLocation
{
    static unsigned long long muNameHash = 0x64A394B637C25752;
    static unsigned long long muTemplateHash = 0xF1FF349FCBFB33CA;

    eMissionPlayerLocation MissionPlayerLocation;
}
