#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForStatSeasonal
{
    static unsigned long long muNameHash = 0xCEBA3C32BCAF04F6;
    static unsigned long long muTemplateHash = 0x6384040D3897C2DF;

    cTkFixedString<128,char> macMessage;
    TkID<128> mStat;
    TkID<128> mStatGroup;
    int miAmount;
    bool mbTakeAmountFromSeasonalData;
    cTkFixedString<128,char> macDebugText;
}
