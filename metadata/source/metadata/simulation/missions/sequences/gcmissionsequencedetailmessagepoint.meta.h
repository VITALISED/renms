#pragma once
#include <metadata/metadata_common.h>
enum ePointState
{
    EPointState_Statement = 0,
    EPointState_ObjectiveIncomplete = 1,
    EPointState_ObjectiveComplete = 2,
}

class cGcMissionSequenceDetailMessagePoint
{
    static unsigned long long muNameHash = 0xC2F4FABD9EDAFE6A;
    static unsigned long long muTemplateHash = 0x111193B7216264B4;

    TkID<256> mText;
    ePointState PointState;
    TkID<128> mInsertItemName;
}
