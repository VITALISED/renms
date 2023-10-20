#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/vehicles/gcvehicletype.meta.h>
#include <metadata/tkmodelresource.meta.h>

class cGcVehicleComponentData
{
    static unsigned long long muNameHash = 0x8847908A288010B2;
    static unsigned long long muTemplateHash = 0x15D3F987A25D7FCE;

    cGcVehicleType Class;
    TkID<128> mVehicleType;
    cTkFixedString<128,char> macCockpit;
    float mfMaxHeadTurn;
    float mfMaxHeadPitchUp;
    float mfMaxHeadPitchDown;
    float mfMinTurretAngle;
    float mfFoVFixedDistance;
    int miBaseHealth;
    cTkModelResource WheelModel;
}
