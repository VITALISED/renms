#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcNPCPropInfo
{
    static unsigned long long muNameHash = 0x9441C44CA7215426;
    static unsigned long long muTemplateHash = 0x38C77ECB344C2FB4;

    cTkFixedString<128,char> macModel;
    bool mbHologram;
    cGcScanEffectData ScanEffect;
    cTkFixedString<64,char> macScanEffectNodeName;
    float mfWeight;
    cGcTechnologyCategory ShopType;
}
