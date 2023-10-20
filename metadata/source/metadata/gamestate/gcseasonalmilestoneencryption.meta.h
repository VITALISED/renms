#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcSeasonalMilestoneEncryption
{
    static unsigned long long muNameHash = 0x9562AF9028346F05;
    static unsigned long long muTemplateHash = 0x668FCE5B1743986A;

    bool mbIsEncrypted;
    TkID<256> mTitleUpper;
    TkID<256> mSubtitle;
    TkID<256> mDescription;
    cTkTextureResource Patch;
    cTkTextureResource HoverPopupIcon;
    TkID<128> mDecryptMissionId;
    int miDecryptMissionSeed;
}
