#pragma once
#include <metadata/metadata_common.h>
enum eAerialViewMode
{
    EAerialViewMode_FaceDown = 0,
    EAerialViewMode_FaceOut = 1,
    EAerialViewMode_FaceDownThenOut = 2,
}
#include <?>

class cGcCameraAerialViewData
{
    static unsigned long long muNameHash = 0x7AB4D686179F9F82;
    static unsigned long long muTemplateHash = 0xF1087A135ED0653B;

    float mfTime;
    eAerialViewMode AerialViewMode;
    float mfTimeBack;
    float mfStartTime;
    float mfPauseTime;
    float mfDistance;
    float mfTargetOffsetAngle;
    int miStages;
    float mfSpeedLineDist;
    cTkCurveType Curve;
    cTkCurveType CurveDown;
    cTkCurveType SlerpCurve;
}
