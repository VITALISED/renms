#pragma once
#include <metadata/metadata_common.h>
enum eVehicleType
{
    EVehicleType_Buggy = 0,
    EVehicleType_Bike = 1,
    EVehicleType_Truck = 2,
    EVehicleType_WheeledBike = 3,
    EVehicleType_Hovercraft = 4,
    EVehicleType_Submarine = 5,
    EVehicleType_Mech = 6,
}

class cGcVehicleType
{
    static unsigned long long muNameHash = 0x46812D05ED43A48D;
    static unsigned long long muTemplateHash = 0x474D5FA6C924B281;

    eVehicleType VehicleType;
}
