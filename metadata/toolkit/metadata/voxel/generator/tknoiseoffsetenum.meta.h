#pragma once
#include <metadata/metadata_common.h>
enum eOffsetType
{
    EOffsetType_Zero = 0,
    EOffsetType_Base = 1,
    EOffsetType_All = 2,
    EOffsetType_SeaLevel = 3,
}

class cTkNoiseOffsetEnum
{
    static unsigned long long muNameHash = 0xFCAC758E3056BFEF;
    static unsigned long long muTemplateHash = 0xFC67D2D7540961D5;

    eOffsetType OffsetType;
}
