#pragma once

#include <skyscraper.h>

#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/system/TkCSMutex.h>

#include <audio/gcbytebeatdrum.meta.h>
#include <audio/gcbytebeatenvelope.meta.h>
#include <audio/gcbytebeattoken.meta.h>
#include <audio/gcbytebeatwave.meta.h>

SKYSCRAPER_BEGIN

enum eByteBeatSampleRate
{
    EByteBeatSampleRate_Low,
    EByteBeatSampleRate_Med,
    EByteBeatSampleRate_High,
    EByteBeatSampleRate_Ultra,
    EByteBeatSampleRate_NumTypes,
};

class cGcByteBeatTokenInfo
{
    eByteBeatToken meType;
    unsigned int miValue;
};

class cGcByteBeatTree
{
    cGcByteBeatTokenInfo maTokens[64];
    unsigned int miNumTokens;
};

class cGcByteBeatSequencer
{
    class cGcByteBeatSequencerStep
    {
        unsigned __int8 miScaleDegree;
    };

    class cGcByteBeatRhythmTrack
    {
        cGcByteBeatTree mTree;
        unsigned __int8 miTemplateIndex;
        float mfVolume;
        float mfDuration;
        float mfOctaveShift;
        eByteBeatEnvelope meAttackEnvelope;
        eByteBeatEnvelope meDecayEnvelope;
        eByteBeatWave meByteBeatWave;
        float mfAugmentVolume;
        float mfAugmentOverdrive;
        float mfAugmentSineNoiseMix;
        float mfAugmentPitch;
        float mfAugmentPitchFalloff;
        float mfAugmentPitchFalloffPower;
        eAugmentMode meAugmentMode;
    };

    class cGcByteBeatArpeggioStep
    {
        int miChordIndex;
        int miOctaveOffset;
    };

    unsigned __int8 miTempo : 8;
    unsigned __int8 miVolume : 4;
    unsigned __int8 miAttenuation : 4;
    unsigned __int8 miDrumMix : 4;
    __int8 meKey : 5;
    __int8 meArpStepSubdivs : 3;
    __int8 miArpPitchStep : 4;
    __int8 miArpPitchRange : 4;
    unsigned __int8 miOctaveOffset : 4;
    __int32 meWave : 8;
    unsigned __int8 miStepLength : 2;
    __int8 meSequenceLength : 2;
    __int32 meAttackEnvelope : 4;
    __int32 meDecayEnvelope : 4;
    __int8 meArpeggio : 4;
    __int8 meNoteLength : 4;
    __int8 mbActive : 1;
    __int8 mbNoteOnResets : 1;
    __int8 mbArpActive : 1;
    __int8 mbRhythmActive : 1;
    __int8 mbMelodyActive : 1;
    __int8 mbLoop : 1;
    unsigned __int8 miPartSequence : 8;
    cGcByteBeatSequencer::cGcByteBeatSequencerStep maSteps[16];
    bool maRhythmSteps[3][16];
    cGcByteBeatSequencer::cGcByteBeatRhythmTrack maRhythmTracks[3];
    cGcByteBeatSequencer::cGcByteBeatArpeggioStep maArpSteps[16];
};

class cGcByteBeat : public ITkAudioStream
{
    VFT<2> *__vftable;
    TkAudioObject mAudioObject;
    float mfLastAttenuation;
    cTkAttachmentPtr mpAttachment;
    bool mbNotifyConnected;
    bool mbPowered;
    bool mbViewingTree;
    float mfGenerateAudioFade;
    bool mbShouldGenerateAudio;
    bool mbPrepared;
    bool mbConnected;
    unsigned int muiCurrentOutputSample;
    int miLastDrumStep;
    unsigned __int64 mu64FrameCreated;
    float mfVolume;
    float mfSpeakerAmplitude;
    cTkSmartResHandle mSpeakerMaterial;
    cGcNGui mScreenGUI;
    cTkSmartResHandle mScreenDynamicMaterial;
    cTkSmartResHandle mScreenCachedMaterial;
    TkHandle mDynamicScreens;
    TkHandle mStaticScreens;
    int miPooledScreenIndex;
    eByteBeatSampleRate meSampleRate;
    float mfVirtualSampleRate;
    cGcByteBeatTree mMainTree;
    cGcByteBeatTree maRhythmTrees[3];
    cGcByteBeatSequencer mSequencer;
    _RTL_CRITICAL_SECTION mCriticalSection;
};

SKYSCRAPER_END