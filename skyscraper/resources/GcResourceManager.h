/**
 * @file GcResourceManager.h
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

#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/solarsystem/planet/gcplanetcolourdata.meta.h>
#include <toolkit/tkproceduraltexturechosenoptionlist.meta.h>

SKYSCRAPER_BEGIN

struct CustomisationData
{
    cTkSeed mResourceSeed;
    cTkVector<TkID<256>> mDescriptors;
    cTkProceduralTextureChosenOptionList mTextureOptions;
    std::map<TkID<128>, float> mBoneScales;
    bool mbUseLegacyColourPalettes;
    bool mbEditedColours;
    cGcPlanetColourData mEditColours;
    cGcPlanetColourData mFinalColours;
    float mfScale;
};

class cGcResourceCustomisation
{
  public:
    CustomisationData mResourceCustomisation;
    TkID<128> mPresetName;
    cTkVector<TkID<128>> mDescriptorGroups;
    std::map<TkID<128>, TkID<256>> mChosenTextureOptions;
    TkID<256> mForcedTextureName;
    const ePalette kReplicatedPalettes[11];
    const eColourAlt kReplicatedColourAlts[3];
};

class cGcResourceManager
{
    char __pad__[0x0170];
};

SKYSCRAPER_END