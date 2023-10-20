#pragma once
#include <metadata/metadata_common.h>
enum eVocalEmote
{
    EVocalEmote_EmoteIdle = 0,
    EVocalEmote_EmoteFlee = 1,
    EVocalEmote_EmoteAggression = 2,
    EVocalEmote_EmoteRoar = 3,
    EVocalEmote_EmotePain = 4,
    EVocalEmote_EmoteAttack = 5,
    EVocalEmote_EmoteDie = 6,
    EVocalEmote_EmoteMiniRoarNeutral = 7,
    EVocalEmote_EmoteMiniRoarHappy = 8,
    EVocalEmote_EmoteMiniRoarAngry = 9,
}

class cGcCreatureVocalSoundData
{
    static unsigned long long muNameHash = 0x7FE7156AA587561F;
    static unsigned long long muTemplateHash = 0xE5A63220EF7B73B5;

    TkID<128> mId;
    eVocalEmote VocalEmote;
    float mfPlayFrequency;
    float mfMinCooldown;
    float mfMaxCooldown;
    bool mbPlayImmediately;
    bool mbPlayOnlyOnce;
}
