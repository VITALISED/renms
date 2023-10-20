#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/tkemitterfloatproperty.meta.h>

class cTkParticleBurstData
{
    static unsigned long long muNameHash = 0x523281BEC01AA0F4;
    static unsigned long long muTemplateHash = 0x6026455A2E436CAA;

    cTkEmitterFloatProperty BurstAmount;
    cTkEmitterFloatProperty BurstInterval;
    int miLoopCount;
}
