#pragma once
#include <metadata/metadata_common.h>
enum eEmissionRateType
{
    EEmissionRateType_PerParticle = 0,
    EEmissionRateType_Distance = 1,
}

class cTkEmitFromParticleInfo
{
    static unsigned long long muNameHash = 0x56A47F95DD76DC72;
    static unsigned long long muTemplateHash = 0xEF8549DC9D356FDC;

    int miOtherEmitterIndex;
    eEmissionRateType EmissionRateType;
}
