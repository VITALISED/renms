#pragma once
#include <metadata/metadata_common.h>

class cGcRoomSequenceRule
{
    static unsigned long long muNameHash = 0x836CEABBD3EE007D;
    static unsigned long long muTemplateHash = 0xA1B2A3B82AB3ED0D;

    TkID<128> mRoomID;
    int miMinRoomIndex;
    TkID<128> mMustBeBeforeRoom;
    TkID<128> mMustBeAfterRoom;
}
