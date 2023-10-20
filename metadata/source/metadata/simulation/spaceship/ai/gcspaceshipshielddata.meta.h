#pragma once
#include <metadata/metadata_common.h>

class cGcSpaceshipShieldData
{
    static unsigned long long muNameHash = 0x715B2B315094E969;
    static unsigned long long muTemplateHash = 0xB568E721447691E9;

    TkID<128> mId;
    int miHealth;
    int miLevelledExtraHealth;
    float mfRechargeTime;
    float mfRechargeDelayTime;
}
