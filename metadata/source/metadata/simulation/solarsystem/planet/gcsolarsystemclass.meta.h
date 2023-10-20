#pragma once
#include <metadata/metadata_common.h>
enum eSolarSystemClass
{
    ESolarSystemClass_Default = 0,
    ESolarSystemClass_Initial = 1,
    ESolarSystemClass_Anomaly = 2,
    ESolarSystemClass_GameStart = 3,
}

class cGcSolarSystemClass
{
    static unsigned long long muNameHash = 0xC66C80C1B41A77FD;
    static unsigned long long muTemplateHash = 0xBB8B17B3CC5FF674;

    eSolarSystemClass SolarSystemClass;
}
