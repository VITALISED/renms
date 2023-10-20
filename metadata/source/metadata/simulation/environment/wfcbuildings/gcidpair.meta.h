#pragma once
#include <metadata/metadata_common.h>

class cGcIDPair
{
    static unsigned long long muNameHash = 0x89AAE7085D90732B;
    static unsigned long long muTemplateHash = 0x48CF5CDE312FAFA4;

    TkID<128> mItem1;
    TkID<128> mItem2;
}
