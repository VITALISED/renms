#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceTeleport
{
    static unsigned long long muNameHash = 0xE586E1C6C9A10307;
    static unsigned long long muTemplateHash = 0xBB4A61849CB9F4C8;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macDebugText;
    cGcTeleporterType TeleporterType;
    bool mbDoCameraShake;
    bool mbDoWhiteout;
    float mfSequenceTime;
    float mfEffectTime;
}
