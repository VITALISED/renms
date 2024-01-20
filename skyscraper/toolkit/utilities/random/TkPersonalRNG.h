/**
 * @file TkPersonalRNG.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <toolkit/data/TkByteSwap.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/maths/utilities/hash/TkMurmurHash3.h>
#include <toolkit/simulation/TkSeed.h>

SKYSCRAPER_BEGIN

class cTkPersonalRNG
{
  public:
    constexpr uint32_t i2_32ml() { return 1 / (2 ^ 32 - 1); }
    static const uint32_t kiRandContext = 1517746329;

    inline cTkPersonalRNG() { this->Reseed(); }
    inline cTkPersonalRNG(const cTkSeed &lNewSeed) { this->Reseed(lNewSeed); }

    inline void ShuffleState()
    {
        signed int shuffle_a = this->mState1 + kiRandContext * this->mState0;
        uint64_t shuffle_b   = this->mState1 + kiRandContext * (static_cast<uint64_t>(this->mState0) >> 32);

        this->mState0 = shuffle_a;
        this->mState1 = shuffle_b;
    }

    inline void Tumble()
    {
        this->ShuffleState();

        if (this->mState0 % 0xB != -3)
        {
            for (int i = this->mState0 % 0xB + 3; i > 0; i--)
            {
                this->mState0 = this->mState1 + kiRandContext * this->mState0;
                this->mState1 = this->mState1 + kiRandContext * this->mState0;
            }
        }
    }

    inline void Reseed()
    {
        uint64_t lTickCount64 = GetTickCount64();

        uint64_t lHash = TkMurmur3::FMix64StaffordMix02(lTickCount64);

        this->mState0 = cTkByteSwap::GetLowValOf64(lHash ^ (lHash >> 33));
        this->mState1 = cTkByteSwap::GetHighValOf64(lHash ^ (lHash >> 33));
    }

    inline void Reseed(const cTkSeed &lNewSeed)
    {
        if (lNewSeed.mbValid)
        {
            uint64_t lValue = lNewSeed.GetValue();
            this->mState0   = cTkByteSwap::GetLowValOf64(lValue);
            this->mState1   = cTkByteSwap::GetHighValOf64(lValue);
        }
        else { *this = *reinterpret_cast<cTkPersonalRNG *>(1); }
    }

    inline float GenFloatFlip()
    {
        this->ShuffleState();

        if ((this->mState0 & 1) != 0) { return -1.0f; }
        else { return 1.0f; }
    }

    inline float GenFloat(float lfMin, float lfMax)
    {
        this->ShuffleState();

        return (this->mState0 * i2_32ml()) * (lfMax - lfMin) + lfMin;
    }

    inline cTkSeed *GenSeed(cTkSeed *result)
    {
        this->ShuffleState();
        uint64_t lHash  = TkMurmur3::FMix64StaffordMix02(this->mState0 | (static_cast<uint64_t>(this->mState1) >> 32));
        result->mbValid = true;
        result->mu64SeedValue = lHash ^ (lHash >> 33);

        return result;
    }

    inline bool GenPercentage(uint32_t pct)
    {
        if (pct > 100) { ; }
        return this->GenInt32Range(0, 99) < pct;
    }

    inline uint64_t GenUInt64()
    {
        this->ShuffleState();
        uint64_t lHash = TkMurmur3::FMix64StaffordMix02(this->mState0 | (static_cast<uint64_t>(this->mState1) >> 32));

        return lHash ^ (lHash >> 33);
    }

    inline int64_t GenInt32Range(int liMin, int liMax)
    {
        if (liMax < liMin) { ; }

        this->ShuffleState();

        int lRange = liMin + (this->mState0 * (liMax - liMin + 1));

        if (lRange < liMin || lRange > liMax) { ; }

        return lRange;
    }

    template <typename T>
    inline void RandomShuffleContainer(T *lContainer)
    {
        if (lContainer->size() > 1)
        {
            for (int i = lContainer->size(); i > 0; i--)
            {
                this->ShuffleState();

                int lVal = this->mState0 * (lContainer->size() + 1);

                if ((lVal & 0x80000000) != NULL || lVal > lContainer->size()) { ; }

                lContainer[lVal] = lContainer[i];
            }
        }
    }

    // FIXME: this is causing issues with CppSharp. Probably because it's auto**, might need to rewrite the actual
    // implementation

    // template <typename T>
    // inline auto **SelectRandomItemFromContainer(const T *lContainer)
    // {
    //     if (lContainer->size() < 1) { ; }

    //     int lRange = this->GenInt32Range(0, lContainer->size());

    //     if (lRange >= lContainer->size()) { ; }

    //     return lContainer[lRange];
    // }

    uint32_t mState0;
    uint32_t mState1;
};

SKYSCRAPER_END