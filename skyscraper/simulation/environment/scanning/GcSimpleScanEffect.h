/**
 * @file GcSimpleScanEffect.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <toolkit/core/types/TkHandle.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/utilities/containers/TkClassPool.h>

#include <simulation/player/gcscaneffectdata.meta.h>

SKYSCRAPER_BEGIN

class cGcSimpleScanEffect
{
  public:
    enum eState
    {
        Active,
        ActiveUpdated,
        Inactive,
    };

    cGcScanEffectData *mpSourceData;
    cGcScanEffectData mData;
    cTkSmoothCD<float> mScanPower;
    TkHandle mScanNode;
    cTkColour mColour;
    bool mbColourOverride;
    cGcSimpleScanEffect::eState meState;
};

template <int Amount>
class cGcSimpleScanEffectPool
{
  public:
    struct Data
    {
        cGcSimpleScanEffect mEffect;
        cGcScanEffectData mData;
    };

    cTkClassPool<cGcSimpleScanEffectPool<Amount>::Data, Amount> maPool;
};

SKYSCRAPER_END