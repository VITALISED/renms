#pragma once
#include <metadata/metadata_common.h>
enum eFreighterInCurrentSystem
{
    EFreighterInCurrentSystem_DontCare = 0,
    EFreighterInCurrentSystem_Yes = 1,
    EFreighterInCurrentSystem_No = 2,
}

class cGcMissionConditionHasFreighter
{
    static unsigned long long muNameHash = 0x8563E3CD9630D9C;
    static unsigned long long muTemplateHash = 0xD3FFE0FC90CC639;

    eFreighterInCurrentSystem FreighterInCurrentSystem;
}
