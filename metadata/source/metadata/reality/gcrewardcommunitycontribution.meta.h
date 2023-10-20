#pragma once
#include <metadata/metadata_common.h>
#include <metadata/atlas/gcatlassendsubmitcontribution.meta.h>
enum eSubmitType
{
    ESubmitType_Value = 0,
    ESubmitType_Stat = 1,
    ESubmitType_StatsDiff = 2,
}

class cGcRewardCommunityContribution
{
    static unsigned long long muNameHash = 0xCE090483FC7B2C67;
    static unsigned long long muTemplateHash = 0xA8EC14D17EF48A02;

    cGcAtlasSendSubmitContribution Contribution;
    eSubmitType SubmitType;
    TkID<128> mStat;
    TkID<128> mOtherStat;
}
