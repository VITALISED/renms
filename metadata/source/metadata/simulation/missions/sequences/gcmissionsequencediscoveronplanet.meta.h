#pragma once
#include <metadata/metadata_common.h>
enum eDiscoverTargetOnThisPlanet
{
    EDiscoverTargetOnThisPlanet_Animal = 0,
    EDiscoverTargetOnThisPlanet_Vegetable = 1,
    EDiscoverTargetOnThisPlanet_Mineral = 2,
}

class cGcMissionSequenceDiscoverOnPlanet
{
    static unsigned long long muNameHash = 0x368D06565D9CC1;
    static unsigned long long muTemplateHash = 0xC36EF22C8FB1973C;

    float mfPercentToDiscover;
    cTkFixedString<128,char> macMessage;
    eDiscoverTargetOnThisPlanet DiscoverTargetOnThisPlanet;
    cTkFixedString<128,char> macDebugText;
}
