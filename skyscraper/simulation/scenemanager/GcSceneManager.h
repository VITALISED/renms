/**
 * @file GcSceneManager.h
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

#include <toolkit/core/types/TkHandle.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/gcscenesettings.meta.h>

SKYSCRAPER_BEGIN

class cGcSceneManager
{
  public:
    cGcSceneSettings *mpSettings;
    cTkFixedString<256, char> mCurrentScene;
    TkHandle mSceneNode;
    TkHandle mSpawnNode;
    TkHandle mLightNode;
    cTkVector<TkHandle> maPlanetSceneNodes;
    cTkSmartResHandle maTrailResources[5];
    cTkSmartResHandle mDefaultTrailRes;
    cTkSmartResHandle maShipFlares[5];
    cTkSmartResHandle mDefaultShipFlareRes;
    cTkSmartResHandle mContrailRes;
    cTkSmartResHandle mMechContrailRes;
    cTkSmartResHandle mMechFoortprintRes;
    cTkSmartResHandle mMissileTrailRes;
    cTkSmartResHandle mAtmosphereGlowRes;
    cTkSmartResHandle mAtmosphereSmokeRes;
    cTkSmartResHandle mLandingSmokeRes;
    cTkSmartResHandle mSpeedCool;
    cTkSmartResHandle mSpeedCoolReverse;
    cTkSmartResHandle mDeathDropRes;
    cTkSmartResHandle mDeathDropSpaceRes;
    cTkSmartResHandle mTeleportEndEffectRes;
    cTkSmartResHandle mTeleportTravelEffectRes;
    cTkSmartResHandle mControllerLeftRes;
    cTkSmartResHandle mControllerRightRes;
    cTkSmartResHandle mLightMaterial;
    bool mbPendingSolarSystemRegenerate;
};

SKYSCRAPER_END