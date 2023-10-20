#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>

class cGcTradingCategoryData
{
    static unsigned long long muNameHash = 0x39D1580ABEEE58C3;
    static unsigned long long muTemplateHash = 0x8CB3BE00363FBA01;

    cTkFixedString<64,char> macName;
    cTkTextureResource Icon;
    float mfProductMultiplierChangePer100;
    float mfSubstanceMultiplierChangePer100;
}
