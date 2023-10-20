#pragma once
#include <metadata/metadata_common.h>
enum eZoomType
{
    EZoomType_None = 0,
    EZoomType_Far = 1,
    EZoomType_Mid = 2,
    EZoomType_Close = 3,
}

class cGcZoomData
{
    static unsigned long long muNameHash = 0x2E92A561CA97070C;
    static unsigned long long muTemplateHash = 0x94899B4FFFB85110;

    eZoomType ZoomType;
    float mfEffectStrength;
    float mfMoveSpeed;
    float mfFoV;
    float mfMinScanDistance;
    float mfMaxScanDistance;
    float mfWalkSpeed;
}
