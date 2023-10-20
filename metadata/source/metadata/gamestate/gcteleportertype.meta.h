#pragma once
#include <metadata/metadata_common.h>
enum eTeleporterDestinationType
{
    ETeleporterDestinationType_Base = 0,
    ETeleporterDestinationType_Spacestation = 1,
    ETeleporterDestinationType_Atlas = 2,
    ETeleporterDestinationType_PlanetAwayFromShip = 3,
    ETeleporterDestinationType_ExternalBase = 4,
    ETeleporterDestinationType_EmergencyGalaxyFix = 5,
    ETeleporterDestinationType_OnNexus = 6,
    ETeleporterDestinationType_SpacestationFixPosition = 7,
    ETeleporterDestinationType_Settlement = 8,
    ETeleporterDestinationType_Freighter = 9,
}

class cGcTeleporterType
{
    static unsigned long long muNameHash = 0xECE6F42F8A522B34;
    static unsigned long long muTemplateHash = 0xC9A0D4A857566650;

    eTeleporterDestinationType TeleporterDestinationType;
}
