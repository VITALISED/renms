#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWait
{
    static unsigned long long muNameHash = 0x47C4BE1F468F66AA;
    static unsigned long long muTemplateHash = 0xA86FC3BDC40CF0D4;

    float mfTime;
    cTkFixedString<128,char> macDebugText;
    bool mbSuppressMessages;
    bool mbMultiplyTimeBySeasonValue;
}
