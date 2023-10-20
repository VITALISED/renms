#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcseasonalmilestone.meta.h>
#include <metadata/tktextureresource.meta.h>

class cGcSeasonalStage
{
    static unsigned long long muNameHash = 0xF1949393FDAF963A;
    static unsigned long long muTemplateHash = 0x9222F3D64367B8B5;

    cTkDynamicArray<cGcSeasonalMilestone> maMilestones;
    cTkTextureResource Icon;
    TkID<256> mTitle;
    TkID<256> mDescription;
}
