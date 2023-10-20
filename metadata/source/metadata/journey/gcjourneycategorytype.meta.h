#pragma once
#include <metadata/metadata_common.h>
enum eCategoryType
{
    ECategoryType_Journey = 0,
    ECategoryType_Race = 1,
    ECategoryType_Guild = 2,
}

class cGcJourneyCategoryType
{
    static unsigned long long muNameHash = 0x182075982F91C5F8;
    static unsigned long long muTemplateHash = 0x9117FB771CCEB0C5;

    eCategoryType CategoryType;
}
