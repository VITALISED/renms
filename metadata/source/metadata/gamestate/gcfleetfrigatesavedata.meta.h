#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcFleetFrigateSaveData
{
    static unsigned long long muNameHash = 0xE6F863FE26F77270;
    static unsigned long long muTemplateHash = 0x1C0EB21E6164191A;

    cTkSeed mResourceSeed;
    cTkSeed mHomeSystemSeed;
    cTkSeed mForcedTraitsSeed;
    unsigned long long mui64TimeOfLastIncomeCollection;
    cTkFixedString<256,char> macCustomName;
    cGcFrigateClass FrigateClass;
    cGcAlienRace Race;
    cGcInventoryClass InventoryClass;
    int miTotalNumberOfExpeditions;
    int miTotalNumberOfSuccessfulEvents;
    int miTotalNumberOfFailedEvents;
    int miNumberOfTimesDamaged;
    cTkDynamicArray<TkID<128>> maTraitIDs;
    cTkDynamicArray<int> maStats;
    int miRepairsMade;
    int miDamageTaken;
}
