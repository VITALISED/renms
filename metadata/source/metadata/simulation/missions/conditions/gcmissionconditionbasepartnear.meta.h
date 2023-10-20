#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionBasePartNear
{
    static unsigned long long muNameHash = 0x12DE4C36058305CA;
    static unsigned long long muTemplateHash = 0x6411000DEAB2BDC4;

    TkID<128> mPartID;
    bool mbTakeIDFromSeasonData;
    float mfDistance;
}
