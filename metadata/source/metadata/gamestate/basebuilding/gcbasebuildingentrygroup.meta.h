#pragma once
#include <metadata/metadata_common.h>

class cGcBaseBuildingEntryGroup
{
    static unsigned long long muNameHash = 0xC9CDB8F662EAE0B2;
    static unsigned long long muTemplateHash = 0x7AB148BE845ED462;

    TkID<128> mGroup;
    TkID<128> mSubGroupName;
    int miSubGroup;
}
