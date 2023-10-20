#pragma once
#include <metadata/metadata_common.h>
enum eDestinationSortType
{
    EDestinationSortType_NearestPotal = 0,
    EDestinationSortType_BaseBuildingConnection = 1,
    EDestinationSortType_AbandonedFreighter = 2,
    EDestinationSortType_PortalNearestPlayerShip = 3,
}

class cGcBaseMiniPortalComponentData
{
    static unsigned long long muNameHash = 0xBBBD45634207B79F;
    static unsigned long long muTemplateHash = 0x6B51F3B80FECAB80;

    bool mbAllowVehicles;
    bool mbAllowSpawnedObjects;
    bool mbFlipFacingDirection;
    bool mbSnapFacingDirection;
    float mfSnapFacingAngle;
    bool mbDoPlayerEffects;
    bool mbTeleportCamera;
    int miPowerCost;
    TkID<128> mGroupID;
    TkID<128> mDestinationGroupID;
    eDestinationSortType DestinationSortType;
}
