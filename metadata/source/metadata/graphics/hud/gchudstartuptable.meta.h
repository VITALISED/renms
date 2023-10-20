#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/hud/gchudstartup.meta.h>

class cGcHUDStartupTable
{
    static unsigned long long muNameHash = 0xB0A39161047DD10D;
    static unsigned long long muTemplateHash = 0xF927FCB2A4A44546;

    float mfFadeInFlashTime;
    float mfLookSpeed;
    float mfStartHoldTime;
    float mfButtonFlashRate;
    float mfButtonFlashAlpha;
    float mfBackgroundAlpha;
    cTkFixedArray<cGcHUDStartup> maHUDStartup;
}
