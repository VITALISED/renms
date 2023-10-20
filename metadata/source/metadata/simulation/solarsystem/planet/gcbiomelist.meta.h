#pragma once
#include <metadata/metadata_common.h>

class cGcBiomeList
{
    static unsigned long long muNameHash = 0xEAB35A5B84B3A47C;
    static unsigned long long muTemplateHash = 0xC4EC0F43200D5194;

    cTkFixedArray<float> maBiomeProbability;
    cTkFixedArray<float> maPrimeBiomeProbability;
}
