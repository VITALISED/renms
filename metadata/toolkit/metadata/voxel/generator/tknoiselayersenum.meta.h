#pragma once
#include <metadata/metadata_common.h>
enum eNoiseLayerTypes
{
    ENoiseLayerTypes_Base = 0,
    ENoiseLayerTypes_Hill = 1,
    ENoiseLayerTypes_Mountain = 2,
    ENoiseLayerTypes_Rock = 3,
    ENoiseLayerTypes_UnderWater = 4,
    ENoiseLayerTypes_Texture = 5,
    ENoiseLayerTypes_Elevation = 6,
    ENoiseLayerTypes_Continent = 7,
}

class cTkNoiseLayersEnum
{
    static unsigned long long muNameHash = 0xDF72B6BAF8A085A2;
    static unsigned long long muTemplateHash = 0x17A8EF62D5BC39D6;

    eNoiseLayerTypes NoiseLayerTypes;
}
