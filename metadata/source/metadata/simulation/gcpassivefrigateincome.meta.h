#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPassiveFrigateIncome
{
    static unsigned long long muNameHash = 0x3FD1F99F13543A98;
    static unsigned long long muTemplateHash = 0x346AB6B64FC22307;

    TkID<128> mIncomeId;
    cGcInventoryType IncomeType;
    int miAmountOfIncomeRewarded;
    int miForEveryXAmountOfTheStat;
}
