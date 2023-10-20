#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/data/gccreaturevocalsounddata.meta.h>

class cGcCreatureAudioTable
{
    static unsigned long long muNameHash = 0x5CA0AF3D94711819;
    static unsigned long long muTemplateHash = 0x74AF38BF3BB04A72;

    cTkDynamicArray<cGcCreatureVocalSoundData> maTable;
}
