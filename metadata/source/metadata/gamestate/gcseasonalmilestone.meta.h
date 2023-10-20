#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcSeasonalMilestone
{
    static unsigned long long muNameHash = 0x4EDC167332F6B824;
    static unsigned long long muTemplateHash = 0x5D65FBCDFF91C956;

    TkID<128> mMission;
    TkID<256> mTitle;
    TkID<256> mTitleUpper;
    TkID<256> mDescription;
    TkID<256> mDescriptionDone;
    TkID<256> mCantRewardMessage;
    TkID<128> mIdToUseInMissionData;
    float mfAmount;
    int miStageIndex;
    int miMilestoneIndex;
    int miRendezvousIndex;
    cTkTextureResource Icon;
    cTkTextureResource IconGrey;
    cTkTextureResource MissionIcon;
    cTkTextureResource MissionIconSelected;
    cTkTextureResource MissionIconNotSelected;
    TkID<128> mReward;
    TkID<128> mRewardSwitchAlt;
    cTkFixedString<512,char> macRewardDescription;
    cTkFixedString<512,char> macCantClaimRewardDescription;
    bool mbIsOptional;
    bool mbIsRendezvous;
    bool mbIsStageControl;
    cGcSeasonalMilestoneEncryption Encryption;
}
