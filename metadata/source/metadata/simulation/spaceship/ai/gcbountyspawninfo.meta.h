#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/spaceship/ai/gcaishipspawndata.meta.h>
#include <metadata/tktextureresource.meta.h>

class cGcBountySpawnInfo
{
    static unsigned long long muNameHash = 0x39C7A4F372F6707C;
    static unsigned long long muTemplateHash = 0x797798746A9643E2;

    TkID<128> mId;
    cGcAIShipSpawnData Data;
    TkID<128> mAttackData;
    cTkTextureResource Icon;
    TkID<256> mLabel;
}
