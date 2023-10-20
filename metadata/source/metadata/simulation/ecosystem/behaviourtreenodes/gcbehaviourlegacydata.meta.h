#pragma once
#include <metadata/metadata_common.h>
enum eLegacyBehaviour
{
    ELegacyBehaviour_Riding = 0,
    ELegacyBehaviour_Interaction = 1,
    ELegacyBehaviour_Attracted = 2,
    ELegacyBehaviour_Flee = 3,
    ELegacyBehaviour_Defend = 4,
    ELegacyBehaviour_FollowPlayer = 5,
    ELegacyBehaviour_AvoidPlayer = 6,
    ELegacyBehaviour_NoticePlayer = 7,
    ELegacyBehaviour_FollowRoutine = 8,
}

class cGcBehaviourLegacyData
{
    static unsigned long long muNameHash = 0xE727C698F36AF1CA;
    static unsigned long long muTemplateHash = 0x81663F7AA75A4A81;

    eLegacyBehaviour LegacyBehaviour;
}
