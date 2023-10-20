#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>
#include <metadata/tktextureresource.meta.h>

class cGcRewardOSDMessage
{
    static unsigned long long muNameHash = 0x53D72723F082671D;
    static unsigned long long muTemplateHash = 0x1D2C471ADB92C5D9;

    float mfTime;
    TkID<256> mMessage;
    cGcAudioWwiseEvents AudioEvent;
    cTkTextureResource Icon;
    cTkColour mMessageColour;
    bool mbUseTimedMessage;
}
