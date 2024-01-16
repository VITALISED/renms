/**
 * @file GcAudioPulseMusic.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <audio/GcAudioAggregates.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

SKYSCRAPER_BEGIN

template <typename T>
class PulseItemList
{
  public:
    PulseItemList<T> *Load(const XMLNode &lNode);
    void Release();

    T *mpCurrent;
    T *mpFirst;
    unsigned int mNumItems;
};

/**
 * @brief Pulse music is the music soundscape system implemented - at least partially by 65daysofstatic, the band who
 * were working on No Man's Sky's soundtrack.
 */
class cGcAudioPulseMusic
{
  public:
    void Construct();
    void Prepare();
    bool LoadProject(const cTkFixedString<256, char> &lProjectFilename);
    void ReleaseProject();
    void StopMusic();
    void Release();
    void SetVariantIndex(int index, const cTkFixedString<256, char> &lDebugText);
    void ResetSoundScapeType();
    uint64_t GetRNDRange(int liMin, int liMax);

    enum PlayingState
    {
        Stopped,
        Stopping,
        StopRequested,
        Playing,
        PlayingInitialize,
    };

    enum SoundScapeType
    {
        SoundScapeType_Map,
        SoundScapeType_Planet,
        SoundScapeType_Space,
        SoundScapeType_Wanted,
        SoundScapeType_AmbientMode,
        SoundScapeType_Silent,
    };

    struct SoundScapeSettings
    {
        int mCurrentVariant;
        int mMaxVairant;
    };

    struct Instrument
    {
        struct InstrumentIndex
        {
            struct InstrumentNote
            {
                cTkFixedString<256, char> msEventName;
                TkAudioID mPlayEventID;
                TkAudioID mStopEventID;
                int miNote;
                int miOctave;
                cGcAudioPulseMusic::Instrument::InstrumentIndex::InstrumentNote *mpNext;
            };

            cTkFixedString<256, char> msKey;
            cTkFixedString<256, char> msSoundGroup;
            cTkFixedString<256, char> msMood;
            unsigned int mAudioBankID;
            bool mLooping;
            bool mDrumLoop;
            PulseItemList<cGcAudioPulseMusic::Instrument::InstrumentIndex::InstrumentNote> mInstrumentNotes;
        };

        cTkFixedString<256, char> msName;
        std::array<cGcAudioPulseMusic::Instrument::InstrumentIndex, 30> mInstrumentVariants;
        cGcAudioPulseMusic::Instrument *mpNext;
    };

    struct SoundScape
    {
        struct SoundScapeIndex
        {
            struct EventGenerator
            {
                void GenerateSubEvents(
                    float lfAttenuation, cGcAudioPulseMusic::SoundScape::SoundScapeIndex *lpParentSoundScape);
                void Update(
                    cGcAudioPulseMusic::SoundScape::SoundScapeIndex *lpParentSoundScape, float lfTimeStep,
                    bool lbBeatTriggered);

                struct ModulatorLink
                {
                    cTkFixedString<256, char> mModulator;
                    int mMin;
                    int mMax;
                    cTkFixedString<256, char> mTarget;
                    cGcAudioPulseMusic::SoundScape::SoundScapeIndex::EventGenerator::ModulatorLink *mpNext;
                };

                struct AudioEvent
                {
                    bool Play();
                    void EndOfEventCallbackFunc(int leType, void *lpCallbackInfo); // TODO: AK types

                    TkAudioObject mAudioObject;
                    float mInitialVolume;
                    TkAudioID mPlayEventID;
                    int mBeatDelay;
                    bool mIsPlaying;
                    bool mStartedSound;
                };

                cTkFixedString<256, char> mName;
                cTkFixedString<256, char> msInstrument;
                cGcAudioPulseMusic::Instrument *mpInstrument;
                int miBeatCount;
                cTkFixedString<256, char> mBus;
                int mGridXpos;
                int mGridYpos;
                int mSlewRate;
                int mQbeat;
                int mQbar;
                bool mContinuousVolume;
                bool mStartImmediately;
                bool mIsLoopingInstrument;
                float mSlewTimeOutCounter;
                bool mProcessStopRequest;
                int mQBeatCounter;
                int mQuantizeBeat;
                bool mbEnabled;
                int mMin_Volume;
                int mMin_Beat;
                int mMin_Events;
                int mMin_Stagger;
                int mMin_Cluster_Shape;
                int mMin_Pan_LR;
                int mMin_Pan_FR;
                int mMin_Polyphony;
                int mMin_Pitch_Range;
                int mMin_InfluenceDist;
                int mMin_Note_Vol_Scale;
                int mMax_Volume;
                int mMax_Beat;
                int mMax_Events;
                int mMax_Stagger;
                int mMax_Cluster_Shape;
                int mMax_Pan_LR;
                int mMax_Pan_FR;
                int mMax_Polyphony;
                int mMax_Pitch_Range;
                int mMax_InfluenceDist;
                int mMax_Note_Vol_Scale;
                int mOval_Ratio_X;
                int mOval_Ratio_Y;
                float mfSendBus_01;
                float mfSendBus_02;
                float mfSendBus_03;
                float mfSendBus_04;
                cTkVector2 mGridPos;
                cTkVector2 mOvalRatioScale;
                float mMinInfluenceDist;
                float mMaxInfluenceDist;
                float mInfluenceDistFalloffRange;
                PulseItemList<cGcAudioPulseMusic::SoundScape::SoundScapeIndex::EventGenerator::ModulatorLink>
                    mModulatorLinks;
                cGcAudioPulseMusic::SoundScape::SoundScapeIndex::EventGenerator *mpNext;
                cTkVector<cGcAudioPulseMusic::SoundScape::SoundScapeIndex::EventGenerator::AudioEvent *>
                    mActiveAudioEvents;
            };

            cTkFixedString<256, char> mKey;
            cTkFixedString<256, char> mMood;
            int miVolume;
            int miInitialVolume;
            int miFadeTimeMs;
            int mBPM;
            int mSignature;
            float mfBeatInterval;
            float mfTime;
            float mfVolume;
            float mfFadeValue;
            int mVariantIndex;
            cGcAudioPulseMusic::PlayingState mPlayingState;
            PulseItemList<cGcAudioPulseMusic::SoundScape::SoundScapeIndex::EventGenerator> mEventGenerators;
        };

        cTkFixedString<256, char> mName;
        cGcAudioPulseMusic::SoundScapeType mSoundScapeType;
        std::array<cGcAudioPulseMusic::SoundScape::SoundScapeIndex, 30> mSoundScapeVariants;
        cGcAudioPulseMusic::SoundScape *mpNext;
    };

    robin_hood::detail::Table<true, 80, int, cTkFixedString<32, char>, robin_hood::hash<int, void>, std::equal_to<int>>
        mSoundScapeTypeMap;
    robin_hood::detail::Table<
        true, 80, int, cGcAudioPulseMusic::SoundScapeSettings, robin_hood::hash<int, void>, std::equal_to<int>>
        mSoundScapeSettings;
    robin_hood::detail::Table<true, 80, int, cTkFixedString<32, char>, robin_hood::hash<int, void>, std::equal_to<int>>
        mPlayingStateDebugText;
    PulseItemList<cGcAudioPulseMusic::Instrument> mInstruments;
    PulseItemList<cGcAudioPulseMusic::SoundScape> mSoundScapes;
    cTkFixedString<256, char> mDebugTextSetVariantReason;
    bool mbEnabled;
    cTkVector2 mListenerPosition;
    cGcAudioPulseMusic::SoundScapeType mSoundScapeType;
    int mCurrentVariantIndex;
    float mCurrentVariantTimer;
    float mCurrentSoundScapeTimer;
    TkAudioObject mPulseAudioObject;
};

SKYSCRAPER_END