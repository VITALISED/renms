#pragma once
#include <metadata/metadata_common.h>

class cGcRobotLaserData
{
    static unsigned long long muNameHash = 0xAAC69095D4C233F5;
    static unsigned long long muTemplateHash = 0x3588D6B453B06BE1;

    TkID<128> mLaserID;
    float mfLaserSpringTime;
    float mfLaserActiveSpringTime;
    int miLaserMiningDamage;
    float mfLaserChargeTime;
    float mfLaserTime;
    float mfLaserLightChargeSize;
    float mfLaserLightAttackSize;
    cTkVector3 mLaserLightOffset;
    cTkColour mLaserColour;
}
