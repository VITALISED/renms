/**
 * @file GcCameraBehaviourAmbient.h
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
#include <simulation/solarsystem/buildings/GcBuilding.h>
#include <toolkit/graphics/camera/behaviours/TkCameraBehaviour.h>

SKYSCRAPER_BEGIN

class cGcCameraBehaviourAmbient : public cTkCameraBehaviour
{
  public:
    enum eAmbientCameraMode
    {
        EAmbientCameraMode_AutoMove,
    };

    struct CameraState
    {
        cTkVector3 mViewDir;
        cTkVector3 mBaseViewDir;
        cTkVector3 mMoveDir;
        cTkPhysRelVec3 mPosition;
        bool mbSlowDown;
        float mfFov;
    };

    struct CameraLook
    {
        float mfCurrentX;
        float mfCurrentY;
        float mfRateX;
        float mfRateY;
    };

    class cGcAmbientCameraLayer
    {
      public:
        enum eLayerType
        {
            ELayerType_Normal,
            ELayerType_Post,
        };
        bool mbActive;
        cGcCameraBehaviourAmbient::cGcAmbientCameraLayer::eLayerType meLayerType;

        virtual void Prepare();
        virtual void Update(cGcCameraBehaviourAmbient::CameraState *, float);
        virtual void RenderNGui();
    };

    class cGcGoToPlanetLayer : public cGcAmbientCameraLayer
    {
      public:
        int miTargetPlanetIdx;
        float mfSpeed;
    };

    class cGcStraightMovementLayer : public cGcAmbientCameraLayer
    {
      public:
        float mfCameraHeight;
        float mfMaxCameraHeight;
        float mfMinCameraHeight;
        float mfCameraHeightIncSpeed;
        float mfCameraSpeed;
        float mfMaxCameraSpeed;
        float mfMinCameraSpeed;
        float mfCameraAcceleration;
        float mfCurrentCameraSpeed;
        bool mbDebugSamples;
        float mfStabilizationStrength;
        bool mbUseSampleMax;
        bool mbAverageValues;
        bool mbSpeedCorrection;
        cTkPhysRelVec3 maSamples[19];
        cTkPhysRelVec3 maOriginalSamples[19];
        float mfDistanceTravelled;
        float mfHeightSpeed;
        bool mbValidSamples;
    };

    class cGcCurveMovementLayer : public cGcAmbientCameraLayer
    {
      public:
        float mfIntensity;
        float mfPeriod;
        float mfFrequencyCounter;
    };

    class cGcMoveAroundLayer : public cGcAmbientCameraLayer
    {
      public:
        cTkVector2 mLeftStick;
        cGcCameraBehaviourAmbient::CameraLook mCameraLook;
        float mSensitivity;
        bool mbUseLeftStick;
    };

    class cGcLookAtInterestPointLayer : public cGcAmbientCameraLayer
    {
      public:
        bool mbLookAtBuildings;
        bool mbLookAtBigCreatures;
        bool mbLookAtSmallCreatures;
        bool mbInterestPointNearby;
        cTkPhysRelVec3 mInterestPointPosition;
        /*cGcCreatureComponent*/ uintptr_t *mpCurrentCreature;
        cGcBuilding *mpCurrentBuilding;
        float mfDotLoseInterestBuilding;
        float mfDotLoseInterestCreature;
        bool mbDebugInterestPoint;
        float mfTimeLookingAtCurrentTarget;
        float mfLookAtInterpVal;
    };

    class cGcLookAroundLayer : public cGcAmbientCameraLayer
    {
      public:
        cTkVector2 mRightStick;
        cGcCameraBehaviourAmbient::CameraLook mCameraLook;
        cGcPlayerStick mLookStick;
        float mSensitivity;
        float mfMovementSensitivity;
    };

    class cGcAmbientCameraBehaviourManager
    {
      public:
        cGcCameraBehaviourAmbient::cGcGoToPlanetLayer *mpGoToPlanetLayer;
        cGcCameraBehaviourAmbient::cGcStraightMovementLayer *mpStraightMovementLayer;
        cGcCameraBehaviourAmbient::cGcCurveMovementLayer *mpCurveMovementLayer;
        cGcCameraBehaviourAmbient::cGcMoveAroundLayer *mpMoveAroundLayer;
        cGcCameraBehaviourAmbient::cGcLookAtInterestPointLayer *mpLookAtInterestPointLayer;
        cGcCameraBehaviourAmbient::cGcLookAroundLayer *mpLookAroundLayer;
        bool mbActive;
        float mfSmallCreatureLookAtDelay;
        float mfSmallCreatureLookAtTimer;
        float mfCreatureSlowdownLerpVal;
        float mfCreatureSlowdownLowSpeed;
        float mfOriginalFOV;
        float mfCreatureFOV;
        float mfBuildingFOV;
        float mfFovInterpValue;
        float mfCreatureZoomTime;
        float mfBuildingZoomTime;
    };

    cGcCameraBehaviourAmbient::cGcAmbientCameraBehaviourManager mBehaviourManager;
    cTkVector<cGcCameraBehaviourAmbient::cGcAmbientCameraLayer *> maCameraLayers;
    cGcCameraBehaviourAmbient::CameraState mCameraState;
    cGcCameraBehaviourAmbient::eAmbientCameraMode meMode;
    cTkPhysRelMat34 mMatrix;
    cTkPhysRelMat34 mPrevFullMatrix;
    float mfCameraPosInterpValue;
    float mfCameraRotInterpValue;
    float mfCameraRotInerpExp;
    float mfCameraSlerpValue;
};

SKYSCRAPER_END