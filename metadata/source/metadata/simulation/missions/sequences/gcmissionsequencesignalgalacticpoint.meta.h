#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceSignalGalacticPoint
{
    static unsigned long long muNameHash = 0xE9BF52BE754A51E0;
    static unsigned long long muTemplateHash = 0x55246CB1206CD7A7;

    cTkFixedString<128,char> macMessage;
    cGcMissionGalacticPoint Target;
    cTkFixedString<128,char> macDebugText;
}
