#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>

class cGcConsumableItem
{
    static unsigned long long muNameHash = 0xDA5F4DFE0527A693;
    static unsigned long long muTemplateHash = 0x404B0424B3A13ADA;

    TkID<128> mID;
    TkID<128> mRewardID;
    TkID<128> mTutorialRewardID;
    cTkFixedString<64,char> macButtonLocID;
    cTkFixedString<64,char> macButtonSubLocID;
    bool mbCloseInventoryWhenUsed;
    cGcAudioWwiseEvents AudioEventOnOpen;
    cTkFixedString<64,char> macRewardFailedLocID;
    bool mbDestroyItemWhenConsumed;
    bool mbAddCommunityTierClassIcon;
    bool mbSuppressResourceMessage;
    TkID<256> mCustomOSD;
}
