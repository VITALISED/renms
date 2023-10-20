#pragma once
#include <metadata/metadata_common.h>

class cGcWeatherHazardTornadoData
{
    static unsigned long long muNameHash = 0x10FCB49CBC61F8AA;
    static unsigned long long muTemplateHash = 0xEDF56AAFCEDF7863;

    float mfSuckInRadius;
    float mfSuckInStrength;
    float mfSuckUpRadius;
    float mfSuckUpStrength;
    float mfSuckUpHeight;
    float mfSuckUpHeightCutoff;
}
