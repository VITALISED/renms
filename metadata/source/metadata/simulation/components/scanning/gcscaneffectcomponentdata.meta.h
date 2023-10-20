#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcScanEffectComponentData
{
    static unsigned long long muNameHash = 0x1FE13AB26770D8C5;
    static unsigned long long muTemplateHash = 0x7958D3C49BD96694;

    cTkDynamicArray<cGcScanEffectData> maScanEffects;
    cTkFixedString<64,char> macNodeName;
}
