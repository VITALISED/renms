#pragma once
#include <metadata/metadata_common.h>

class cGcPlayerCharacterStateData
{
    static unsigned long long muNameHash = 0xCCEE5C02303ACEC6;
    static unsigned long long muTemplateHash = 0xFC07380B8762421C;

    TkID<128> mLocomotion0H;
    TkID<128> mLocomotion1H;
    TkID<128> mLocomotion2H;
    TkID<128> mAimTree1HPitch;
    TkID<128> mAimTree1HYaw;
    TkID<128> mAimTree2HPitch;
    TkID<128> mAimTree2HYaw;
    TkID<128> mHitReact0H;
    TkID<128> mHitReact1H;
    TkID<128> mHitReact2H;
    bool mbKeepHeadForward;
}
