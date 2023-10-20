#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceCreateSpecificPulseEncounter
{
    static unsigned long long muNameHash = 0x245D62E60DEB8B1E;
    static unsigned long long muTemplateHash = 0x8DBF2F46DA1B86F5;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macMessageNoShip;
    cTkFixedString<128,char> macMessageNotPulsing;
    cTkFixedString<128,char> macMessageSignalBlocked;
    float mfMinTimeInPulse;
    TkID<128> mPulseEncounterID;
    bool mbAllowAnyEncounter;
    bool mbSilent;
    cTkFixedString<128,char> macDebugText;
}
