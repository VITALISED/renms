#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshipmodeldata.meta.h>

class cGcAISpaceshipModelDataArray
{
    static unsigned long long muNameHash = 0x5CA5E4883985A60B;
    static unsigned long long muTemplateHash = 0xAB9CF5F265C56FBC;

    cTkDynamicArray<cGcAISpaceshipModelData> maSpaceships;
}
