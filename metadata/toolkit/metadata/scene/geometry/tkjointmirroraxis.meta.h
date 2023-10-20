#pragma once
#include <metadata/metadata_common.h>

class cTkJointMirrorAxis
{
    static unsigned long long muNameHash = 0xC37B87DF4F026633;
    static unsigned long long muTemplateHash = 0x68E1534AA565849E;

    float mfTransMirrorAxisX;
    float mfTransMirrorAxisY;
    float mfTransMirrorAxisZ;
    float mfRotAdjustX;
    float mfRotAdjustY;
    float mfRotAdjustZ;
    float mfRotAdjustW;
    float mfRotMirrorAxisX;
    float mfRotMirrorAxisY;
    float mfRotMirrorAxisZ;
    int miMirrorAxisMode;
}
