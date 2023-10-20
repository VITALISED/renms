#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/scheduling/gcmissioncommunitymissiondata.meta.h>

class cGcMissionCommunityData
{
    static unsigned long long muNameHash = 0xDAB99EB4164B2DF1;
    static unsigned long long muTemplateHash = 0xFE24098856D39A9D;

    cTkDynamicArray<TkID<128>> maCommunityMissionsIDs;
    cTkDynamicArray<cGcMissionCommunityMissionData> maCommunityMissionsData;
}
