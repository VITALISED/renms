#pragma once
#include <metadata/metadata_common.h>
enum eResponse
{
    EResponse_StayOut = 0,
    EResponse_ReturnHome = 1,
    EResponse_CheckForMoreDamage = 2,
    EResponse_ShowDamagedCaptain = 3,
    EResponse_ShowExpeditionCaptain = 4,
    EResponse_AbortExpedition = 5,
}

class cGcRewardFrigateDamageResponse
{
    static unsigned long long muNameHash = 0xFA9A306017ED3640;
    static unsigned long long muTemplateHash = 0xB26B41C33871BBB;

    eResponse Response;
}
