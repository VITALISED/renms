#pragma once
#include <metadata/metadata_common.h>
enum eAssistanceType
{
    EAssistanceType_Police = 0,
    EAssistanceType_Wingmen = 1,
}

class cGcRewardShipAssistance
{
    static unsigned long long muNameHash = 0x51FB1B6785B647F2;
    static unsigned long long muTemplateHash = 0xAE0E9DF6D9E4C2D3;

    eAssistanceType AssistanceType;
    float mfTime;
}
