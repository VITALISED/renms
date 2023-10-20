#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>
#include <metadata/wiki/gcwikitopic.meta.h>
#include <metadata/wiki/gcwikitopictype.meta.h>

class cGcWikiCategory
{
    static unsigned long long muNameHash = 0xBCA6917366A88ADB;
    static unsigned long long muTemplateHash = 0xFFE1F2575FBC1177;

    TkID<256> mCategoryID;
    TkID<256> mCategoryIDUpper;
    cTkTextureResource IconOn;
    cTkTextureResource IconOff;
    cTkDynamicArray<cGcWikiTopic> maTopics;
    cGcWikiTopicType Type;
    cTkDynamicArray<TkID<128>> maItems;
    int miUnseenCount;
    int miUnlockedCount;
}
