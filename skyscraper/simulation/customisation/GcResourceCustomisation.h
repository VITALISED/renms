/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/data/TkMetaData.h>
#include <metadata/tkproceduraltexturechosenoptionlist.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetcolourdata.meta.h>
#include <metadata/tkpalettetexture.meta.h>

SKYSCRAPER_BEGIN

struct CustomisationData
{
    cTkSeed mResourceSeed;
    cTkVector<TkID<256> > mDescriptors;
    cTkProceduralTextureChosenOptionList mTextureOptions;
    std::map<TkID<128>,float,std::less<TkID<128> > > mBoneScales;
    bool mbUseLegacyColourPalettes;
    bool mbEditedColours;
    cGcPlanetColourData mEditColours;
    cGcPlanetColourData mFinalColours;
    float mfScale;
};

class cGcResourceCustomisation
{
    CustomisationData mResourceCustomisation;
    TkID<128> mPresetName;
    cTkVector<TkID<128> > mDescriptorGroups;
    std::map<TkID<128>,TkID<256>,std::less<TkID<128> >,std::allocator<std::pair<TkID<128> const ,TkID<256> > > > mChosenTextureOptions;
    TkID<256> mForcedTextureName;
    const ePalette kReplicatedPalettes[11];
    const eColourAlt kReplicatedColourAlts[3];
};


SKYSCRAPER_END