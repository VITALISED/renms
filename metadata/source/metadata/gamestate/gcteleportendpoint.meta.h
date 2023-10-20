#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eTeleporterType
{
    ETeleporterType_Base = 0,
    ETeleporterType_Spacestation = 1,
    ETeleporterType_Atlas = 2,
    ETeleporterType_PlanetAwayFromShip = 3,
    ETeleporterType_ExternalBase = 4,
    ETeleporterType_EmergencyGalaxyFix = 5,
    ETeleporterType_OnNexus = 6,
    ETeleporterType_SpacestationFixPosition = 7,
    ETeleporterType_Settlement = 8,
    ETeleporterType_Freighter = 9,
    ETeleporterType_Frigate = 10,
}

class cGcTeleportEndpoint
{
    static unsigned long long muNameHash = 0x18CD621AAAB1F01D;
    static unsigned long long muTemplateHash = 0xEA4F0B98C8572FC;

    cGcUniverseAddressData UniverseAddress;
    cTkVector3 mPosition;
    cTkVector3 mFacing;
    eTeleporterType TeleporterType;
    cTkFixedString<64,char> macName;
    bool mbCalcWarpOffset;
    bool mbIsFeatured;
}
