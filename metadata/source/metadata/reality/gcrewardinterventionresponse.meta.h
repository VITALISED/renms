#pragma once
#include <metadata/metadata_common.h>
enum eResponseType
{
    EResponseType_DontIntervene = 0,
    EResponseType_InterveneWithMission = 1,
    EResponseType_MissionSuccess = 2,
    EResponseType_MissionFailure = 3,
}

class cGcRewardInterventionResponse
{
    static unsigned long long muNameHash = 0x3E904C2466567A08;
    static unsigned long long muTemplateHash = 0x985634C4BE6A9411;

    eResponseType ResponseType;
    TkID<128> mMissionID;
}
