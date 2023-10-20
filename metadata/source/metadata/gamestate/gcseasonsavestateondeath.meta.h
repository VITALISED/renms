#pragma once
#include <metadata/metadata_common.h>
enum eSeasonSaveStateOnDeath
{
    ESeasonSaveStateOnDeath_Standard = 0,
    ESeasonSaveStateOnDeath_ResetAndQuit = 1,
    ESeasonSaveStateOnDeath_ResetPosSaveAndQuit = 2,
    ESeasonSaveStateOnDeath_SaveAndQuit = 3,
}

class cGcSeasonSaveStateOnDeath
{
    static unsigned long long muNameHash = 0x800386833E2445B5;
    static unsigned long long muTemplateHash = 0xBEF45E7C90B2A83C;

    eSeasonSaveStateOnDeath SeasonSaveStateOnDeath;
}
