#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkNGuiRectanglePulseEffect
{
    static unsigned long long muNameHash = 0xED10CD4D4540B757;
    static unsigned long long muTemplateHash = 0xBEFA838B717588ED;

    float mfPulseWidth;
    float mfPulseOffset;
    float mfPulseRate;
    cTkCurveType PulseAlphaCurve;
    cTkCurveType PulseSizeCurve;
}
