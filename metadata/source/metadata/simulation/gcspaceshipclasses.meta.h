#pragma once
#include <metadata/metadata_common.h>
enum eShipClass
{
    EShipClass_Freighter = 0,
    EShipClass_Dropship = 1,
    EShipClass_Fighter = 2,
    EShipClass_Scientific = 3,
    EShipClass_Shuttle = 4,
    EShipClass_PlayerFreighter = 5,
    EShipClass_Royal = 6,
    EShipClass_Alien = 7,
    EShipClass_Sail = 8,
}

class cGcSpaceshipClasses
{
    static unsigned long long muNameHash = 0xB9B04C0CA0357C57;
    static unsigned long long muTemplateHash = 0xBCA7F95FF0E24D2D;

    eShipClass ShipClass;
}
