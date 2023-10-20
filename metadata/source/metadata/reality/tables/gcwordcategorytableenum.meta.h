#pragma once
#include <metadata/metadata_common.h>
enum egcwordcategorytableEnum
{
    EgcwordcategorytableEnum_MISC = 0,
    EgcwordcategorytableEnum_DIRECTIONS = 1,
    EgcwordcategorytableEnum_HELP = 2,
    EgcwordcategorytableEnum_TRADE = 3,
    EgcwordcategorytableEnum_LORE = 4,
    EgcwordcategorytableEnum_TECH = 5,
    EgcwordcategorytableEnum_THREAT = 6,
}

class cgcwordcategorytableEnum
{
    static unsigned long long muNameHash = 0x4F41C5DCED5937F1;
    static unsigned long long muTemplateHash = 0x54D577DD4FC76430;

    egcwordcategorytableEnum gcwordcategorytableEnum;
}
