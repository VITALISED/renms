#pragma once
#include <metadata/metadata_common.h>

class cGcRewardSetCurrentMission
{
    static unsigned long long muNameHash = 0xD8850AC59C3175E1;
    static unsigned long long muTemplateHash = 0xF29DE9D73CE2FBC2;

    TkID<128> mMission;
    bool mbSilent;
    bool mbSeeded;
}
