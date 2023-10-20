#pragma once
#include <metadata/metadata_common.h>
#include <metadata/wiki/gcstorypageseendata.meta.h>

class cGcStoryPageSeenDataArray
{
    static unsigned long long muNameHash = 0xFCD71DCE44349CB6;
    static unsigned long long muTemplateHash = 0xA6E0EDD093163143;

    cTkDynamicArray<cGcStoryPageSeenData> maPagesData;
}
