#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcPlayerSpaceshipControlData
{
    static unsigned long long muNameHash = 0x49B6F6CA72CF5A3F;
    static unsigned long long muTemplateHash = 0x96267977B10C1DE0;

    cGcPlayerSpaceshipEngineData SpaceEngine;
    cGcPlayerSpaceshipEngineData PlanetEngine;
    cGcPlayerSpaceshipEngineData CombatEngine;
    cGcPlayerSpaceshipEngineData AtmosCombatEngine;
    float mfExitHeightFactorMin;
    float mfExitHeightFactorMax;
    float mfExitHeightFactorPlungeMin;
    float mfExitHeightFactorPlungeMax;
    float mfExitAngleMin;
    float mfExitAngleMax;
    float mfExitLeaveAngle;
    cTkCurveType ExitCurve;
    cTkCurveType ExitDownCurve;
    float mfAngularFactor;
    float mfMaxTorque;
    float mfShipPlanetBrakeMinSpeed;
    float mfShipPlanetBrakeMaxSpeed;
    float mfShipPlanetBrakeMinHeight;
    float mfShipPlanetBrakeMaxHeight;
    float mfShipPlanetBrakeForce;
    float mfShipPlanetBrakeAlignMinTime;
    float mfShipPlanetBrakeAlignMaxTime;
    float mfShipMinHeightForce;
}
