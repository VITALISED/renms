#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureGroupProbability
{
    static unsigned long long muNameHash = 0xF0E840DA05227000;
    static unsigned long long muTemplateHash = 0xFEECAE1AE6297591;

    TkID<128> mGroup;
    float mfProbability;
}
