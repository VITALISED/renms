#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tklocalisationentry.meta.h>

class cTkLocalisationTable
{
    static unsigned long long muNameHash = 0x2969CA92E6538A9A;
    static unsigned long long muTemplateHash = 0xF30F569D3A42CF36;

    cTkDynamicArray<cTkLocalisationEntry> maTable;
}
