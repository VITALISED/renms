#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForBuild
{
    static unsigned long long muNameHash = 0x15BC2878FF0C535;
    static unsigned long long muTemplateHash = 0x28F5F296CCED4F9A;

    cTkFixedString<128,char> macMessage;
    TkID<128> mTargetTech;
    cTkFixedString<128,char> macDebugText;
}
