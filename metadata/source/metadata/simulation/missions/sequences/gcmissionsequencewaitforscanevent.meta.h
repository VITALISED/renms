#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceWaitForScanEvent
{
    static unsigned long long muNameHash = 0xCFE8C2198256BF63;
    static unsigned long long muTemplateHash = 0x47C4AA7111F66BA;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macGalaxyMapMessage;
    TkID<256> mEvent;
    float mfTimeout;
    bool mbDistanceTimeout;
    cTkFixedString<128,char> macTimeoutOSD;
    cGcScanEventGPSHint UseGPSInText;
    cTkFixedString<128,char> macSurveyInactiveHint;
    cTkFixedString<128,char> macSurveySwapHint;
    cTkFixedString<128,char> macSurveyHint;
    cTkFixedString<128,char> macSurveyVehicleHint;
    cTkFixedString<128,char> macDebugText;
}
