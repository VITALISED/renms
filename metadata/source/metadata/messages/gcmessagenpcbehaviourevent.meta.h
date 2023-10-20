#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/npcs/gcnpctriggertypes.meta.h>

class cGcMessageNPCBehaviourEvent
{
    static unsigned long long muNameHash = 0x40F7E71C83A33DA0;
    static unsigned long long muTemplateHash = 0x3FC636475190B910;

    TkID<128> mBehaviourEvent;
    TkID<128> mUserData;
    cGcNPCTriggerTypes InteractionTrigger;
    int miInteractionSubType;
    cTkVector3 mPosition;
    TkHandle mSourceNode;
}
