#pragma once
#include <metadata/metadata_common.h>
enum eStatTrackType
{
    EStatTrackType_Set = 0,
    EStatTrackType_Add = 1,
    EStatTrackType_Max = 2,
    EStatTrackType_Min = 3,
}

class cGcStatTrackType
{
    static unsigned long long muNameHash = 0xCCBEF4F753544A3F;
    static unsigned long long muTemplateHash = 0xF3CE45267031CFFA;

    eStatTrackType StatTrackType;
}
