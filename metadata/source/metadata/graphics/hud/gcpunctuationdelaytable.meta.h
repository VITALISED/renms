#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/hud/gcpunctuationdelaydata.meta.h>

class cGcPunctuationDelayTable
{
    static unsigned long long muNameHash = 0x8A35BC3F94D0949F;
    static unsigned long long muTemplateHash = 0x98FAEC01CF3A50C7;

    cTkFixedArray<cGcPunctuationDelayData> maPunctuationDelays;
}
