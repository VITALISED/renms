#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureMoveAnimData
{
    static unsigned long long muNameHash = 0x50CC62720AB69C5;
    static unsigned long long muTemplateHash = 0x2DC6AD707DCBEFED;

    TkID<128> mAnim;
    TkID<128> mAnimLeft;
    TkID<128> mAnimRight;
    float mfAnimSpeed;
    float mfMinSpeedScale;
    float mfMaxSpeedScale;
    float mfMaxPredatorSpeedScale;
    float mfMinPetSpeedScale;
    float mfMaxPetSpeedScale;
    float mfAnimMoveSpeed;
    bool mbAnimMoveSpeedCached;
}
