#pragma once
#include <metadata/metadata_common.h>

class cGcTargetMissionSurveyOptions
{
    static unsigned long long muNameHash = 0x4E7A7CEB00A9346B;
    static unsigned long long muTemplateHash = 0xC5A9DABEAEFD7DEE;

    TkID<128> mTargetMissionSurveyId;
    bool mbTargetMissionSurveyDefinitelyExists;
    cTkFixedString<128,char> macSurveyInactiveHint;
    cTkFixedString<128,char> macSurveySwapHint;
    cTkFixedString<128,char> macSurveyHint;
    cTkFixedString<128,char> macSurveyVehicleHint;
}
