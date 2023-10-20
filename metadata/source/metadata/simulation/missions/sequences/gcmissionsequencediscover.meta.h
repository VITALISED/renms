#pragma once
#include <metadata/metadata_common.h>
enum eDiscoverTarget
{
    EDiscoverTarget_Animal = 0,
    EDiscoverTarget_Vegetable = 1,
    EDiscoverTarget_Mineral = 2,
}

class cGcMissionSequenceDiscover
{
    static unsigned long long muNameHash = 0x61016ED971A59B9A;
    static unsigned long long muTemplateHash = 0xEE9CFABE1CF4D7A;

    cTkFixedString<128,char> macMessage;
    bool mbPerPlanet;
    eDiscoverTarget DiscoverTarget;
    int miAmountMin;
    int miAmountMax;
    bool mbTakeAmountFromSeasonalData;
    cTkFixedString<128,char> macDebugText;
}
