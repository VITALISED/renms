/**
 * @file TkAudioManager.h
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

#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/utilities/containers/TkDeque.h>

SKYSCRAPER_BEGIN

class cTkAudioParamCache
{
    public:
    robin_hood::detail::Table<
        true, 80, unsigned int, float, robin_hood::hash<unsigned int, void>, std::equal_to<unsigned int>>
        mRTPCPrevValues;
    robin_hood::detail::Table<
        true, 80, unsigned int, TkAudioID, robin_hood::hash<unsigned int, void>, std::equal_to<unsigned int>>
        mSwitchPrevValues;
    cTkVector3 mvPrevPosition;
    cTkVector3 mvPrevOrientation;
    float mfPrevObstruction;
    float mfPrevOcclusion;
};

class cTkAudioManager
{
  public:
    struct AsyncBankStreaming
    {
        enum State
        {
            Empty,
            WaitingOnAlloc,
            LoadBegun,
            DataArrivedLoadingIntoWwise,
            Complete,
            Failed,
        };

        cTkFixedString<128, char> mBankFile;
        int64_t muBankFileSize;
        void *mpBankData;
        int mAsyncHandle;
        cTkAudioManager::AsyncBankStreaming::State meState;
    };

    cTkMatrix34 mLastListenerMatrix;
    std::array<cTkAudioManager::AsyncBankStreaming, 1000> *mpAsyncBankStreamingArray;
    bool mbAsyncBankLoadsInProgress;
    bool mbConstructed;
    robin_hood::detail::Table<
        true, 80, unsigned int, ITkAudioStream *, robin_hood::hash<unsigned int, void>, std::equal_to<unsigned int>>
        mActiveAudioStreams;
    _RTL_CRITICAL_SECTION mAudioStreamMapInterlock;
    uint64_t mPrimaryListener;
    uint64_t mSecondaryListener;
    cTkDeque<TkAudioObject> mUnregistrationQueue;
    robin_hood::detail::Table<
        false, 80, uint64_t, cTkAudioParamCache, robin_hood::hash<uint64_t, void>, std::equal_to<uint64_t>>
        mParameterCache;
    bool mbUsing3dAudio;

    virtual void Update(const cTkMatrix34 *, float, const cTkVector3 *, const cTkMatrix34 *, int);
    virtual void Render();
    virtual bool Release();
    virtual void Destruct();
    virtual void UpdateAuxSendWithFalloffConcrete(const cTkVector3 *, TkAudioObject, const float);
};

SKYSCRAPER_END