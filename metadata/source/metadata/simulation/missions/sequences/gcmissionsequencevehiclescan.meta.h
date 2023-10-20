#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceVehicleScan
{
    static unsigned long long muNameHash = 0xD9BAAE731EB23B1;
    static unsigned long long muTemplateHash = 0x606FCE0896D4B123;

    cTkFixedString<128,char> macMessage;
    TkID<256> mScanEventID;
    cTkFixedString<128,char> macDebugText;
}
