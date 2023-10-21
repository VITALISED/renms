#pragma once

#include <skyscraper.h>
#include <application/states/GcApplicationSimulationState.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <simulation/GcSmokeTestScenario.h>

SKYSCRAPER_BEGIN

class cGcApplicationSmokeTestState : public cGcApplicationSimulationState
{
    cTkPhysRelMat34 mTransformForMovement;
    cTkPhysRelMat34 mTransformForLookAt;
    int miCurrentPlanet;
    int miNumPlanetsVisited;
    bool mbSpaceTravel;
    float mfSpaceTravelTimer;
    cTkSmoothCD<float> mfHeightSpring;
    bool mbHeightSpringSet;
    float mfInitialPauseLeft;
    float mfSmokeTestFlashTimeLeft;
    float mfGifTimeBetweenKeyframesLeft;
    int miFrames;
    float mfRightSunPosRandom;
    float mfUpSunPosRandom;
    float mfAtSunPosRandom;
    float mfPlanetFlightTimer;
    float mfPlanetFlightTimeoutTimer;
    cTkColour mFlashColour;
    float mfFullScreenFlashTimer;
    bool mbRenderFullScreenFlash;
    bool mbFinished;
    bool mbIsCompleted;
    bool mbIsExiting;
    cGcSmokeTestScenario *mpSmokeTestScenario;
    cGcSmokeTestScenario *mpSmokeTestCycleScenario;
    cTkVector<float> mafLowMemoryWatermarks;
};

SKYSCRAPER_END