#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/hud/gcpunctuationdelay.meta.h>

class cGcPunctuationDelayData
{
    static unsigned long long muNameHash = 0x550D77569C679867;
    static unsigned long long muTemplateHash = 0x8C9ABF2C23D96E50;

    cTkDynamicArray<cGcPunctuationDelay> maPunctuationList;
    float mfDefaultDelay;
}
