#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceShowSeasonTimeWarning
{
    static unsigned long long muNameHash = 0x232C5143BAE4E2F9;
    static unsigned long long muTemplateHash = 0xDF027FC6EF251E3D;

    cTkFixedString<128,char> macMessage;
    float mfTimeToShow;
    cTkFixedString<128,char> macDebugText;
}
