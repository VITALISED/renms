#pragma once
#include <metadata/metadata_common.h>
enum eCombatTimerDifficultyOption
{
    ECombatTimerDifficultyOption_Off = 0,
    ECombatTimerDifficultyOption_Slow = 1,
    ECombatTimerDifficultyOption_Normal = 2,
    ECombatTimerDifficultyOption_Fast = 3,
}

class cGcCombatTimerDifficultyOption
{
    static unsigned long long muNameHash = 0xF407DE9312D729B0;
    static unsigned long long muTemplateHash = 0x39060AAC417BAD2A;

    eCombatTimerDifficultyOption CombatTimerDifficultyOption;
}
