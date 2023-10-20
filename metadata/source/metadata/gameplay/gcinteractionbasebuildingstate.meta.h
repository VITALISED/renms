#pragma once
#include <metadata/metadata_common.h>

class cGcInteractionBaseBuildingState
{
    static unsigned long long muNameHash = 0x914E2AF518E30AB2;
    static unsigned long long muTemplateHash = 0x96073F904BB26814;

    TkID<128> mTriggerAction;
    int miTime;
}
