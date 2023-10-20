#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/interactions/gcinteractionbuffertype.meta.h>

class cGcPersistencyMissionOverride
{
    static unsigned long long muNameHash = 0xD595098569C459AF;
    static unsigned long long muTemplateHash = 0xCFC2C403668DBF4E;

    TkID<128> mMission;
    cGcInteractionBufferType Buffer;
}
