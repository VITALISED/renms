#pragma once
#include <metadata/metadata_common.h>
enum eMissionDifficulty
{
    EMissionDifficulty_Easy = 0,
    EMissionDifficulty_Normal = 1,
    EMissionDifficulty_Hard = 2,
}

class cGcMissionDifficulty
{
    static unsigned long long muNameHash = 0x81EBB5E64823914E;
    static unsigned long long muTemplateHash = 0xD5B1EB7573A2AD22;

    eMissionDifficulty MissionDifficulty;
}
