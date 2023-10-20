#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCustomisationThrusterEffect
{
    static unsigned long long muNameHash = 0xE7EC6E83CB496A6C;
    static unsigned long long muTemplateHash = 0x35D1B26990D36E34;

    TkID<128> mName;
    TkID<128> mLinkedSpecialID;
    TkID<256> mTip;
    bool mbAllowedInSeasonalDefaults;
    cTkColour mLightColour;
    cTkDynamicArray<cGcCustomisationThrusterJet> maJets;
}
