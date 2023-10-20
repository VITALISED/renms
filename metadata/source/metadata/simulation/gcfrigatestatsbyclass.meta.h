#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/gcfrigatestats.meta.h>

class cGcFrigateStatsByClass
{
    static unsigned long long muNameHash = 0x89CF360B576FF51D;
    static unsigned long long muTemplateHash = 0xC6BEB0DF9D15CFF8;

    cTkFixedArray<cGcFrigateStats> maFrigateClass;
}
