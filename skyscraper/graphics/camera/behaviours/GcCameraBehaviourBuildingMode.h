/**
 * @file GcCameraBehaviourBuildingMode.h
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

#include <simulation/player/controllers/GcPlayerStick.h>
#include <toolkit/graphics/camera/behaviours/TkCameraBehaviour.h>
#include <toolkit/simulation/physics/havok/TkHavokProxyCharacterController.h>

#include <toolkit/tkmodelresource.meta.h>

SKYSCRAPER_BEGIN

class cGcCameraBehaviourBuildingMode : public cTkCameraBehaviour
{
  public:
    cTkVector3 mInitialPlayerPosition;
    cTkPhysRelVec3 mAnchorPosition;
    cGcPlayerStick mPlayerStick;
    cTkHavokProxyCharacterController mProxy;
    cTkModelResource mCameraRadiusModel;
    TkHandle mCameraBoundaryNode;
    cTkSmartResHandle mCameraMaterialHandle;
    bool mbBoundaryModelLoading;
    bool mbBoundaryModelLoaded;
};

SKYSCRAPER_END