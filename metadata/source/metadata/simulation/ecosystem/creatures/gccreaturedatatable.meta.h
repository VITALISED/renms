#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/gccreaturedata.meta.h>

class cGcCreatureDataTable
{
    static unsigned long long muNameHash = 0x53E5A2C89515A4E1;
    static unsigned long long muTemplateHash = 0x738C1A4C0B58644E;

    cTkDynamicArray<cGcCreatureData> maTable;
}
