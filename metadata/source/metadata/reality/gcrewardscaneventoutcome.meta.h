#pragma once
#include <metadata/metadata_common.h>
enum eRewardScanEventOutcome
{
    ERewardScanEventOutcome_Success = 0,
    ERewardScanEventOutcome_Interstellar = 1,
    ERewardScanEventOutcome_BadData = 2,
    ERewardScanEventOutcome_FailedToFindBase = 3,
    ERewardScanEventOutcome_Duplicate = 4,
    ERewardScanEventOutcome_NoBuilding = 5,
    ERewardScanEventOutcome_NoSystem = 6,
}

class cGcRewardScanEventOutcome
{
    static unsigned long long muNameHash = 0x27C5678B5AA766C2;
    static unsigned long long muTemplateHash = 0x5B2510C614EF8484;

    eRewardScanEventOutcome RewardScanEventOutcome;
}
