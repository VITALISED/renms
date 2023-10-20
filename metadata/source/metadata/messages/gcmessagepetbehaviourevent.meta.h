#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcMessagePetBehaviourEvent
{
    static unsigned long long muNameHash = 0x9465A52B8A2F9FD9;
    static unsigned long long muTemplateHash = 0x2D7AEFE1BF878CE7;

    TkID<128> mBehaviourEvent;
    TkID<256> mUserData;
    cGcPetBehaviours ForceBehaviour;
    cGcAlienMood Mood;
    cTkVector3 mPosition;
    cTkVector3 mDirection;
    TkHandle mSourceNode;
}
