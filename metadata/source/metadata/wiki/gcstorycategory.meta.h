#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/wiki/gcstorypage.meta.h>

class cGcStoryCategory
{
    static unsigned long long muNameHash = 0x276FB03774F36C9F;
    static unsigned long long muTemplateHash = 0x67F2EBF4F9D4B4B4;

    TkID<256> mCategoryID;
    TkID<256> mCategoryIDUpper;
    cTkTextureResource IconOn;
    cTkTextureResource IconOff;
    cTkDynamicArray<cGcStoryPage> maPages;
}
