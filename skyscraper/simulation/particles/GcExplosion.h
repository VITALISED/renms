/**
 * @file GcExplosion.h
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

#include <simulation/scenemanager/GcFadeNode.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

#include <simulation/particles/gcexplosiondata.meta.h>

SKYSCRAPER_BEGIN

class cGcExplosion
{
  public:
    class cGcDebris
    {
      public:
        cGcFadeNode mFade;
        TkHandle mNode;
        /*cTkPhysicsComponent*/ uintptr_t *mpPhysics;
    };
    const cGcExplosionData *mpData;
    cTkMatrix34 mOffset;
    TkHandle mNode;
    TkHandle mParent;
    bool mbUpdateFromParent;
    int miNumDebris;
    TkHandle mDebrisNode;
    std::array<cGcExplosion::cGcDebris, 16> maDebris;
    TkID<128> mUserColourId;
    cTkColour mUserColour;
    TkAudioObject mAudioObject;
    float mfLife;
    bool mbIsPermanent;
    bool mbUserColourChanged;
};

SKYSCRAPER_END