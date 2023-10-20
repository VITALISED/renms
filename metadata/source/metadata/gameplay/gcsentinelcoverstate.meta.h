#pragma once
#include <metadata/metadata_common.h>
enum eSentinelCoverState
{
    ESentinelCoverState_Deploying = 0,
    ESentinelCoverState_Deployed = 1,
    ESentinelCoverState_ShuttingDown = 2,
    ESentinelCoverState_ShutDown = 3,
}

class cGcSentinelCoverState
{
    static unsigned long long muNameHash = 0x9AFBFA1C253ADF63;
    static unsigned long long muTemplateHash = 0x22072DF17EC2DAE;

    eSentinelCoverState SentinelCoverState;
}
