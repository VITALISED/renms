#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPlayerControlState
{
    static unsigned long long muNameHash = 0x9CBA2290362425C1;
    static unsigned long long muTemplateHash = 0x4F23C39FFE413C44;

    TkID<128> mId;
    bool mbStickToGround;
    cGcPlayerControlInput OverrideInput;
    TkID<128> mOverrideCamera;
    cTkDynamicArray<cTkClassPointer> maData;
}
