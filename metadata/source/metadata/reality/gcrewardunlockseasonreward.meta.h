#pragma once
#include <metadata/metadata_common.h>

class cGcRewardUnlockSeasonReward
{
    static unsigned long long muNameHash = 0x7AB9EBA17278DE9B;
    static unsigned long long muTemplateHash = 0xA07A7DD5110CAC;

    TkID<128> mProductID;
    bool mbSilent;
    TkID<256> mEncryptedText;
    bool mbUseSpecialFormatting;
    bool mbMarkAsClaimedInShop;
    bool mbUniqueInventoryItem;
}
