#pragma once
#include <metadata/metadata_common.h>
enum eByteBeatWave
{
    EByteBeatWave_SawTooth = 0,
    EByteBeatWave_Sine = 1,
    EByteBeatWave_Square = 2,
    EByteBeatWave_Triangle = 3,
}

class cGcByteBeatWave
{
    static unsigned long long muNameHash = 0x9860FF852C2CBCD3;
    static unsigned long long muTemplateHash = 0xC9C78044FF5BDB6D;

    eByteBeatWave ByteBeatWave;
}
