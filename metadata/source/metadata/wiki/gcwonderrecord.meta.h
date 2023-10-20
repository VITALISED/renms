#pragma once
#include <metadata/metadata_common.h>

class cGcWonderRecord
{
    static unsigned long long muNameHash = 0xB6F9D0E7CC7397EC;
    static unsigned long long muTemplateHash = 0xADA26EA67A0AA85C;

    cTkFixedArray<unsigned long long> maGenerationID;
    float mfWonderStatValue;
    bool mbSeenInFrontend;
}
