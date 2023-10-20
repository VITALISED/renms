#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbasegridsearchfilter.meta.h>

class cGcBasePartSearchFilter
{
    static unsigned long long muNameHash = 0x471C446618668C68;
    static unsigned long long muTemplateHash = 0xE31DCBB6E6BAA484;

    TkID<128> mIsSpecificID;
    bool mbPartIsOnline;
    bool mbPartIsNotOnline;
    bool mbPartIsVision;
    bool mbPartIsNotVision;
    bool mbApplyGridFilter;
    cGcBaseGridSearchFilter BaseGridFilter;
}
