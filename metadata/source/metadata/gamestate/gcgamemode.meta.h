#pragma once
#include <metadata/metadata_common.h>
enum ePresetGameMode
{
    EPresetGameMode_Unspecified = 0,
    EPresetGameMode_Normal = 1,
    EPresetGameMode_Creative = 2,
    EPresetGameMode_Survival = 3,
    EPresetGameMode_Ambient = 4,
    EPresetGameMode_Permadeath = 5,
    EPresetGameMode_Seasonal = 6,
}

class cGcGameMode
{
    static unsigned long long muNameHash = 0x2BFE76ABF5398879;
    static unsigned long long muTemplateHash = 0xC75E9B9C8ED95CD4;

    ePresetGameMode PresetGameMode;
}
