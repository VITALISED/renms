#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/gcgenericmissionsequence.meta.h>

class cGcMissionTable
{
    static unsigned long long muNameHash = 0x26335C55292A7766;
    static unsigned long long muTemplateHash = 0x8C8424E5F8F49680;

    cTkDynamicArray<cGcGenericMissionSequence> maMissions;
}
