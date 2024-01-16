/**
 * @file GcAudioManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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
#include <audio/GcAudioPulseMusic.h>
#include <toolkit/audio/TkAudioManager.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkTFixedFreeList.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <audio/gcaudiopulsedemo.meta.h>
#include <audio/gcbasepartaudiolocation.meta.h>
#include <toolkit/components/physics/tkvolumetriggertype.meta.h>

SKYSCRAPER_BEGIN

struct AkAuxSendValue
{
    uint64_t listenerID;
    unsigned int auxBusID;
    float fControlValue;
};

class cGcAudioManager : public cTkAudioManager
{
  public:
    enum UIState;

    /**
     * Virtuals
     */

    virtual void Update(const cTkMatrix34 *, float, const cTkVector3 *, const cTkMatrix34 *, int) final;
    virtual void Render() final;
    virtual bool Release() final;
    virtual void Destruct() final;
    virtual void UpdateAuxSendWithFalloffConcrete(const cTkVector3 *, TkAudioObject, const float) final;

    /**
     * Methods
     */

    void Construct();
    void BeginLoadingMusic();
    void StopLoadingMusic();
    void OnSimulationStateEnter(bool lbFirstBoot);
    void NextPulseVariant(const cTkFixedString<256, char> &lDebugText);
    void ChangeUIState(cGcAudioManager::UIState leState);
    void UpdateAuxSendFull(TkAudioObject lAudioObject);
    void RunDopplerRequests(float lfTimeStep);
    void SortAndCueFootsteps();
    void RunObstructionQueries(const cTkMatrix34 &lListenerTM, float lfTimeStep);
    void UpdateAudioPulseState(float lfTimeStep);
    void UpdateAudioEnvironment(float lfTimeStep, bool lbForceUpdate);
    void UpdateAudioEnvironment_LocationAndInterest(float lfTimeStep, bool lbForceUpdate);
    void UpdateAudioEnvironment_FreighterTriggers(float lfTimeStep, bool lbForceUpdate);
    void UpdateAudioEnvironment_InteriorTriggers(float lfTimeStep, bool lbForceUpdate);

    /**
     * Members
     */

    enum DopplerMode
    {
        Full,
        IgnoreListenerVelocity,
    };

    enum UIState : uint8_t
    {
        None,
        AmbientCam,
        Frontend,
        Map,
        Overlay,
        Photomode,
        ByteBeat,
    };

    struct PulseMixControl
    {
        cTkVector2 mCurrent;
        cTkVector2 mTarget;
        cTkVector2 mRate;
        cGcAudioPulseMusic::SoundScapeType mSoundScapeType;
        int mSoundScapeVariant;
        int mShuffledVariantIndex;
        cTkVector<int> mShuffledVariants;
        float mOnPlanetTime;
        float mInSpaceTime;
        cTkFixedString<256, char> mDebugTextSetVariantReason;
        float mBuildingInterestTimer;
        float mMixAttackTime;
        float mMixDecayTime;
        float mMixSpeedInterest;
        float mMixSpeedInterestTarget;
        float mMixSpeedInterestTargetTimer;
    };

    struct FootstepToSort
    {
        cTkVector3 mPosition;
        uint64_t mu64ObstructionTag;
        unsigned int muCreatureClass;
        float mfDistanceToListenerSqr;
        float mfSize;
        bool mbIsRunning;
    };

    ShorelineAudio mShorelineAudio;
    cTkVector3 mLastListenerPosDiff;
    TkAudioObject mManagerAudioObject;
    TkAudioObject mManagerAudioObjectField3D;
    TkAudioObject mGameLaunchMusicAudioObject;
    TkAudioObject mFreighterAmbienceAudioObject;
    eVolumeTriggerType mFreighterAmbienceVolumeType;
    eBasePartAudioLocation meFreighterBasePartAudioLocation;
    TkAudioObject mFrigateAmbienceAudioObject;
    eVolumeTriggerType mFrigateAmbienceVolumeType;
    eVolumeTriggerType meLastKnownFrigateAmbienceVolumeType;
    TkAudioObject mSettlementAmbienceAudioObject;
    TkAudioObject mUIAudioObject;
    unsigned int muLoadingBankID;
    unsigned int muLoadingMusicPlayingID;
    float mfLoadingUnloadTimer;
    cTkVector<cGcDopplerRequest> mDopplerRequests;
    cGcAudioManager::DopplerMode mDopplerMode;
    bool mbAppFocusCheck;
    cTkTFixedFreeList<cGcAudioObstructionRequest, 7> *mpObstructionBundleFreeList;
    cTkStackVector<cGcAudioObstructionRequest *, 64> mObstructionBundleLive;
    cTkStackVector<cGcAudioObstructionRequest *, 64> mObstructionBundleProbeResultMap;
    cTkRaycastJob mObstructionProbeJob;
    uint64_t mu64AmbientBoostLastTime;
    cGcAudioPulseDemo *mpPulseDemoData;
    cGcAudioManager::PulseMixControl mPulseMixControl;
    cGcAudioPulseMusic *mPulseMusic;
    bool mbRunPulseDemo;
    cTkVector<cGcAudioManager::FootstepToSort> mFootstepsToSort;
    std::array<TkAudioObject, 32> mFootstepAudioObjects;
    uint64_t mFootstepAudioObjectIndex;
    unsigned int mCurrentLocationID;
    unsigned int mCurrentInterestID;
    uint8_t meWeatherOverlayState[4];
    bool mbThunderFxEnabled;
    bool mbUseSecondaryListener;
    cTkMatrix34 mSecondaryListener;
    cTkVector3 mEffectsZoneCenter;
    float mfEffectsZoneRecpFalloff;
    uint8_t meEffectsZoneState[4];
    AkAuxSendValue mEffectsSendValue;
    int miLastKnownPlayerEnvironment;
    float mfEffectsOutdoorReverbAmount;
    unsigned int muCurrentInteriorRoomSwitch;
    unsigned int muNexusAmbientSwitch;
    bool mbCommsChatterEventsActive;
    bool mbFreighterAmbienceActive;
    bool mbFrigateAmbienceActive;
    bool mbSettlementAmbienceActive;
    bool mbFieldBoundaryEffectActive;
    bool mbSimulationStateLive;
    char mbForceEnvironmentUpdateOverFrames;
    bool mbShowAttenuationSpheres;
};
SKYSCRAPER_END