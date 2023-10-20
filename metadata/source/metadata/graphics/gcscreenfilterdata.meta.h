#pragma once
#include <metadata/metadata_common.h>

class cGcScreenFilterData
{
    static unsigned long long muNameHash = 0xFFDCD21B79EE81DE;
    static unsigned long long muTemplateHash = 0x6C277BE778F63AF4;

    TkID<256> mLocText;
    cTkFixedString<128,char> macFilename;
    float mfFadeDistance;
    bool mbSelectableInPhotoMode;
    float mfHdrAreaAdjust;
}
