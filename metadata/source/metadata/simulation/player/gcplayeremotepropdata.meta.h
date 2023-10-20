#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gchand.meta.h>
#include <metadata/simulation/player/gcscaneffectdata.meta.h>

class cGcPlayerEmotePropData
{
    static unsigned long long muNameHash = 0x7E08658A660A58D4;
    static unsigned long long muTemplateHash = 0x3E4771511FBAD7C7;

    cTkFixedString<128,char> macModel;
    float mfScale;
    cGcHand Hand;
    bool mbIsHologram;
    cTkFixedString<64,char> macScanEffectNodeName;
    cGcScanEffectData ScanEffect;
    float mfDelayTime;
}
