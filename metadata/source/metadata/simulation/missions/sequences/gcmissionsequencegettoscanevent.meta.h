#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/types/gcscaneventgpshint.meta.h>

class cGcMissionSequenceGetToScanEvent
{
    static unsigned long long muNameHash = 0x4FB6689285BFE7DE;
    static unsigned long long muTemplateHash = 0x39CDC617D97DC33;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macGalaxyMapMessage;
    TkID<256> mEvent;
    float mfDistance;
    bool mbEndEventWhenReached;
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
