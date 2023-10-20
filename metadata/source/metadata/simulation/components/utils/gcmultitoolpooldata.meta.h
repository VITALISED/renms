#pragma once
#include <metadata/metadata_common.h>

class cGcMultitoolPoolData
{
    static unsigned long long muNameHash = 0xBB8457797F0508AB;
    static unsigned long long muTemplateHash = 0x1D7A18DBB3460588;

    cTkFixedString<128,char> macFile;
    int miMinDraw;
    int miMaxDraw;
    float mfPoolProbability;
    bool mbPoolIsSecret;
}
