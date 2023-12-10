/**
 * @file GcCameraManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <graphics/camera/behaviours/GcCameraBehaviourAerialView.h>
#include <graphics/camera/behaviours/GcCameraBehaviourAmbient.h>
#include <graphics/camera/behaviours/GcCameraBehaviourAnimation.h>
#include <graphics/camera/behaviours/GcCameraBehaviourBuildingMode.h>
#include <graphics/camera/behaviours/GcCameraBehaviourCharacter.h>
#include <graphics/camera/behaviours/GcCameraBehaviourFirstPerson.h>
#include <graphics/camera/behaviours/GcCameraBehaviourFly.h>
#include <graphics/camera/behaviours/GcCameraBehaviourFollowTarget.h>
#include <graphics/camera/behaviours/GcCameraBehaviourFreighterWarp.h>
#include <graphics/camera/behaviours/GcCameraBehaviourGalacticLookAt.h>
#include <graphics/camera/behaviours/GcCameraBehaviourGalacticNavigation.h>
#include <graphics/camera/behaviours/GcCameraBehaviourGalacticTransition.h>
#include <graphics/camera/behaviours/GcCameraBehaviourInteraction.h>
#include <graphics/camera/behaviours/GcCameraBehaviourLookAt.h>
#include <graphics/camera/behaviours/GcCameraBehaviourModelView.h>
#include <graphics/camera/behaviours/GcCameraBehaviourOffset.h>
#include <graphics/camera/behaviours/GcCameraBehaviourPhotoMode.h>
#include <graphics/camera/behaviours/GcCameraBehaviourPlayerThirdPerson.h>
#include <graphics/camera/behaviours/GcCameraBehaviourScreenshot.h>
#include <graphics/camera/behaviours/GcCameraBehaviourShipWarp.h>
#include <graphics/camera/behaviours/GcCameraBehaviourThirdPerson.h>
#include <toolkit/graphics/camera/TkCameraManager.h>
#include <toolkit/graphics/camera/behaviours/TkCameraBehaviourInterpolate.h>

SKYSCRAPER_BEGIN

enum eCameraBehaviours
{
    EBehaviourFly,
    EBehaviourInterpolate,
    EBehaviourOffset,
    EBehaviourCharacter,
    EBehaviourFirstPerson,
    EBehaviourVehicleThirdPerson,
    EBehaviourPlayerThirdPerson,
    EBehaviourGalacticTransition,
    EBehaviourGalacticNavigation,
    EBehaviourGalacticLookAt,
    EBehaviourInteraction,
    EBehaviourLookAt,
    EBehaviourAerialView,
    EBehaviourScreenshot,
    EBehaviourPhotoMode,
    EBehaviourAmbient,
    EBehaviourModelView,
    EBehaviourAnimated,
    EBehaviourFollowTarget,
    EBehaviourShipWarp,
    EBehaviourBuildingMode,
    EBehaviourFreighterWarp,
    EBehaviour_Num,
};

class cGcCameraManager : public cTkCameraManagerTemplate<EBehaviour_Num>
{
  public:
    enum eCameraDebugMode
    {
        EDebug_None,
        EDebug_Fly,
        EDebug_Num,
    };

    cTkCameraBehaviourInterpolate mBehaviourInterpolate;
    cGcCameraBehaviourFly mBehaviourFly;
    cGcCameraBehaviourOffset mBehaviourOffset;
    cGcCameraBehaviourCharacter mBehaviourCharacter;
    cGcCameraBehaviourFirstPerson mBehaviourFirstPerson;
    cGcCameraBehaviourGalacticTransition mBehaviourGalacticTransition;
    cGcCameraBehaviourGalacticNavigation mBehaviourGalacticNavigation;
    cGcCameraBehaviourGalacticLookAt mBehaviourGalacticLookat;
    cGcCameraBehaviourInteraction mBehaviourInteraction;
    cGcCameraBehaviourLookAt mBehaviourLookAt;
    cGcCameraBehaviourAerialView mBehaviourAerialView;
    cGcCameraBehaviourScreenshot mBehaviourScreenshot;
    cGcCameraBehaviourAmbient mBehaviourAmbient;
    cGcCameraBehaviourPhotoMode mBehaviourPhotoMode;
    cGcCameraBehaviourThirdPerson mBehaviourThirdPerson;
    cGcCameraBehaviourPlayerThirdPerson mBehaviourPlayerThirdPerson;
    cGcCameraBehaviourAnimation mBehaviourAnimation;
    cGcCameraBehaviourFollowTarget mBehaviourFollowTarget;
    cGcCameraBehaviourModelView mBehaviourModelView;
    cGcCameraBehaviourShipWarp mBehaviourShipWarp;
    cGcCameraBehaviourFreighterWarp mBehaviourFreighterWarp;
    cGcCameraBehaviourBuildingMode mBehaviourBuildingMode;
    cGcCameraManager::eCameraDebugMode meDebugMode;
    eCameraBehaviours meRequestedBehaviour;
};

SKYSCRAPER_END