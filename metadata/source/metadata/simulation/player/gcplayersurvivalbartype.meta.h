#pragma once
#include <metadata/metadata_common.h>
enum eSurvivalBar
{
    ESurvivalBar_Health = 0,
    ESurvivalBar_Hazard = 1,
    ESurvivalBar_Energy = 2,
}

class cGcPlayerSurvivalBarType
{
    static unsigned long long muNameHash = 0xBF11E8FC1185AE00;
    static unsigned long long muTemplateHash = 0x6B865C4DF7135393;

    eSurvivalBar SurvivalBar;
}
