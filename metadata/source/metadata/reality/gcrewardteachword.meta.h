#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcalienrace.meta.h>
#include <metadata/reality/tables/gcwordcategorytableenum.meta.h>

class cGcRewardTeachWord
{
    static unsigned long long muNameHash = 0xFE5851C36CE8242F;
    static unsigned long long muTemplateHash = 0xFC048D8A45E3409;

    cGcAlienRace Race;
    bool mbUseCategory;
    cgcwordcategorytableEnum Category;
    int miAmountMin;
    int miAmountMax;
}
