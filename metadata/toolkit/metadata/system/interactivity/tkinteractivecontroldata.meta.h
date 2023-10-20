#pragma once
#include <metadata/metadata_common.h>

class cTkInteractiveControlData
{
    static unsigned long long muNameHash = 0xF6987FC027F7291;
    static unsigned long long muTemplateHash = 0x5ECF7EC2AF5DF7BD;

    cTkFixedString<32,char> macId;
    TkID<128> mRewardId;
    float mfCooldown;
}
