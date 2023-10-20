#pragma once
#include <metadata/metadata_common.h>

class cGcBaseBuildingPartInteractionData
{
    static unsigned long long muNameHash = 0x6A32C67831551CB7;
    static unsigned long long muTemplateHash = 0x9E58CD2435226735;

    TkID<128> mInteractionID;
    cTkVector3 mLocalPos;
    cTkVector3 mAtDir;
}
