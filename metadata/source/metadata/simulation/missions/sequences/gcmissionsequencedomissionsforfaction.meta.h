#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceDoMissionsForFaction
{
    static unsigned long long muNameHash = 0xBDA9289A7DF468BD;
    static unsigned long long muTemplateHash = 0x46580389AC072212;

    cTkFixedString<128,char> macMessage;
    cGcFactionSelectOptions SelectFrom;
    int miAmountMin;
    int miAmountMax;
    cTkFixedString<128,char> macDebugText;
}
