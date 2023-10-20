#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/gcfrigateflybylayout.meta.h>

class cGcFrigateFlybyTable
{
    static unsigned long long muNameHash = 0x13017671947A0ACE;
    static unsigned long long muTemplateHash = 0xC1F1ACCCA4FC2658;

    cTkDynamicArray<cGcFrigateFlybyLayout> maEntries;
}
