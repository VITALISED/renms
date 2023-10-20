#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceWaitForFactionStanding
{
    static unsigned long long muNameHash = 0x10BF10453E33157C;
    static unsigned long long muTemplateHash = 0x652B840F4280AEC5;

    cTkFixedString<128,char> macMessage;
    cGcFactionSelectOptions SelectFrom;
    int miAmountMin;
    int miAmountMax;
    cTkFixedString<128,char> macDebugText;
}
