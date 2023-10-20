#pragma once
#include <metadata/metadata_common.h>

class cGcPurchaseableSpecial
{
    static unsigned long long muNameHash = 0x3D9281DDAAB505CF;
    static unsigned long long muTemplateHash = 0x56C5A291BA653D60;

    TkID<128> mID;
    int miShopNumber;
    int miMissionTier;
    bool mbIsConsumable;
    bool mbIsCape;
}
