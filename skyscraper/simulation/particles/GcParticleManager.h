/**
 * @file GcParticleManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <simulation/particles/GcEffectList.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/particles/gcareadamagedata.meta.h>
#include <simulation/particles/gcexplosiondatatable.meta.h>

SKYSCRAPER_BEGIN

enum eHeavyAirType
{
    EHeavyAir_None,
    EHeavyAir_Planet,
    EHeavyAir_Cave,
    EHeavyAir_Underwater,
    EHeavyAir_Space,
    EHeavyAir_AbandonedFreighter,
    EHeavyAir_SpaceStorm,
};

class cGcParticleManager
{
  public:
    class cGcHeavyAir
    {
        cTkSmartResHandle mResource;
        TkHandle mRootNode;
        eHeavyAirType meType;
        cTkColour lColour1;
        cTkColour lColour2;
        cTkVector<TkHandle> mChildNodes;
    };

    cTkVector<cGcExplosionDataTable *> mapEffectDataTables;
    cTkUnorderedMap<TkID<128>, cGcExplosionData *, TkIDUnorderedMap::Hash128> maEffectLookup;
    cTkUnorderedMap<TkID<128>, cGcAreaDamageData *, TkIDUnorderedMap::Hash128> maAreaDamageLookup;
    cTkSmartResHandle mSpeedLineRes;
    cTkSmartResHandle mLinesRes;
    TkHandle mParticleGroupNode;
    TkHandle mSpeedLinesNode;
    TkHandle mLinesNode;
    cGcEffectList<cGcExplosion, 512> mEffects;
    cTkVector<TkHandle> maEffectsToDestroyOnCompletion;
    cGcParticleManager::cGcHeavyAir mActiveHeavyAir;
    TkID<128> mRequestDebugViewEffect;
    TkID<128> mRequestDebugEditEffect;
    bool mbParticleDebugRender;
    bool mbHeavyAirChangeRequested;
    float mfHeavyAirFade;
    eHeavyAirType meRequestedHeavyAirType;
    cTkSeed mSeed;
};

SKYSCRAPER_END