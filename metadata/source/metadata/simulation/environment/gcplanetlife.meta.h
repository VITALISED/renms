#pragma once
#include <metadata/metadata_common.h>
enum eLifeSetting
{
    ELifeSetting_Dead = 0,
    ELifeSetting_Low = 1,
    ELifeSetting_Mid = 2,
    ELifeSetting_Full = 3,
}

class cGcPlanetLife
{
    static unsigned long long muNameHash = 0x1E27C6F2466B2426;
    static unsigned long long muTemplateHash = 0xC0116FA38588CC26;

    eLifeSetting LifeSetting;
}
