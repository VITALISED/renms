#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCreatureStupidNameTable
{
    static unsigned long long muNameHash = 0x4992418A4C059481;
    static unsigned long long muTemplateHash = 0x5F7DF73BB619AEE1;

    cTkFixedString<128,char> macStupidUserName;
    cTkDynamicArray<cGcCreatureStupidName> maTable;
}
