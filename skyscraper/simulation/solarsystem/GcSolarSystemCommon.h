/**
 * @file GcSolarSystemCommon.h
 * @author VITALISED & Contributors
 * @since 2023-12-10
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

#include <simulation/solarsystem/asteroid/GcAsteroidPatternGenerator.h>
#include <toolkit/maths/geometry/TkSphere.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/solarsystem/asteroids/gcasteroidgeneratorring.meta.h>
#include <simulation/solarsystem/asteroids/gcasteroidgeneratorslab.meta.h>
#include <simulation/solarsystem/asteroids/gcasteroidgeneratorsurround.meta.h>

SKYSCRAPER_BEGIN

class cGcSolarSystemGeometry
{
  public:
    cTkStackVector<cTkSphere, 6> mPlanetSpheres;
    cTkStackVector<cTkSphere, 6> mPlanetExclusion;
};

class cGcSolarSystemAsteroidFields
{
  public:
    struct AsteroidGenerators
    {
        cTkVector<cGcAsteroidGeneratorRing> mRings;
        cTkVector<cGcAsteroidGeneratorSurround> mSurrounds;
        cTkVector<cGcAsteroidGeneratorSlab> mSlabs;
    };

    cTkMatrix34 mPlayerSpawnTM;
    cGcSolarSystemAsteroidFields::AsteroidGenerators mAsteroidGenerators;
    cGcAsteroidLayout mAsteroids;
};

SKYSCRAPER_END