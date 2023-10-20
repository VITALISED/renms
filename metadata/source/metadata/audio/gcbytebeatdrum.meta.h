#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcbytebeatenvelope.meta.h>
#include <metadata/audio/gcbytebeatwave.meta.h>
enum eAugmentMode
{
    EAugmentMode_Add = 0,
    EAugmentMode_Multiply = 1,
    EAugmentMode_Max = 2,
}

class cGcByteBeatDrum
{
    static unsigned long long muNameHash = 0xAAB4AB6EC567BC2F;
    static unsigned long long muTemplateHash = 0xF8AAFC9337502934;

    cTkFixedString<64,char> macTree;
    float mfVolume;
    float mfDuration;
    float mfOctaveShift;
    cGcByteBeatEnvelope AttackEnvelope;
    cGcByteBeatEnvelope DecayEnvelope;
    cGcByteBeatWave WaveType;
    float mfAugmentVolume;
    float mfAugmentOverdrive;
    float mfAugmentSineNoiseMix;
    float mfAugmentPitch;
    float mfAugmentPitchFalloff;
    float mfAugmentPitchFalloffPower;
    eAugmentMode AugmentMode;
}
