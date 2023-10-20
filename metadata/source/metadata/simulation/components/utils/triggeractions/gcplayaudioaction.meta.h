#pragma once
#include <metadata/metadata_common.h>

class cGcPlayAudioAction
{
    static unsigned long long muNameHash = 0x7C82C5EBE3916386;
    static unsigned long long muTemplateHash = 0xC1A655F641271435;

    cTkFixedString<128,char> macSound;
    bool mbUseOcclusion;
    float mfOcclusionRadius;
}
