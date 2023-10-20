#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkcurvetype.meta.h>

class cGcProjectileLineData
{
    static unsigned long long muNameHash = 0xF7D92F84640D5A1D;
    static unsigned long long muTemplateHash = 0xA065C08AD05D6180;

    float mfBulletLength;
    float mfBulletGlowWidthTime;
    float mfBulletGlowWidthMax;
    float mfBulletGlowWidthMin;
    cTkCurveType BulletGlowWidthCurve;
    float mfBulletScaler;
    float mfBulletScalerMinDist;
    float mfBulletScalerMaxDist;
    float mfBulletMinScaleDistance;
    float mfBulletMaxScaleDistance;
}
