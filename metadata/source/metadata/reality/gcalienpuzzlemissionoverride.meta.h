#pragma once
#include <metadata/metadata_common.h>

class cGcAlienPuzzleMissionOverride
{
    static unsigned long long muNameHash = 0x4A57F915F84ABBCD;
    static unsigned long long muTemplateHash = 0x9609A1E09A79B15;

    TkID<128> mMission;
    cTkSeed mOptionalMissionSeed;
    TkID<256> mPuzzle;
    bool mbForceMissionSeed;
    TkID<128> mAltPriorityMissionForSelection;
}
