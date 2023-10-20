#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/gcfrigateflybytype.meta.h>
#include <metadata/simulation/player/gcplayercommunicatormessage.meta.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>

class cGcRewardFrigateFlyby
{
    static unsigned long long muNameHash = 0x3FACFB36175544A6;
    static unsigned long long muTemplateHash = 0xEC3F6AAE52BA8457;

    cGcFrigateFlybyType FlybyType;
    float mfAppearanceDelay;
    TkID<256> mCommunicatorOSDLocId;
    cGcPlayerCommunicatorMessage CommunicatorMessage;
    cTkTextureResource MarkerIcon;
    cGcAudioWwiseEvents PulseAudio;
    cGcAudioWwiseEvents AudioSting;
    TkID<128> mCameraShake;
}
