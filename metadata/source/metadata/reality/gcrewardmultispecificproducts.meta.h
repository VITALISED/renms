#pragma once
#include <metadata/metadata_common.h>

class cGcRewardMultiSpecificProducts
{
    static unsigned long long muNameHash = 0xC87C94C721C64FAA;
    static unsigned long long muTemplateHash = 0x2408965BFA2525A1;

    TkID<256> mSetName;
    cTkDynamicArray<TkID<128>> maProductIds;
}
