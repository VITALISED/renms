#pragma once
#include <metadata/metadata_common.h>
enum eActiveSurvivalBarsDifficulty
{
    EActiveSurvivalBarsDifficulty_None = 0,
    EActiveSurvivalBarsDifficulty_HealthOnly = 1,
    EActiveSurvivalBarsDifficulty_HealthAndHazard = 2,
    EActiveSurvivalBarsDifficulty_All = 3,
}

class cGcActiveSurvivalBarsDifficultyOption
{
    static unsigned long long muNameHash = 0x96CF7C217D988FDF;
    static unsigned long long muTemplateHash = 0x63F32414B145C38C;

    eActiveSurvivalBarsDifficulty ActiveSurvivalBarsDifficulty;
}
