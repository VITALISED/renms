#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/tkinputenum.meta.h>
#include <metadata/utilities/input/tkplatformbuttonpair.meta.h>

class cTkActionButtonMap
{
    static unsigned long long muNameHash = 0xC1A3BA40B3A88476;
    static unsigned long long muTemplateHash = 0x4BE89D8B8314E3BD;

    TkID<128> mActionId;
    bool mbScaleToFitFont;
    cTkInputEnum PadButtonId;
    cTkDynamicArray<cTkPlatformButtonPair> maPlatforms;
}
