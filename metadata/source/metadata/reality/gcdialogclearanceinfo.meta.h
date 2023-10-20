#pragma once
#include <metadata/metadata_common.h>

class cGcDialogClearanceInfo
{
    static unsigned long long muNameHash = 0x97DBB6FC681295D3;
    static unsigned long long muTemplateHash = 0x7A03DF972A353920;

    TkID<256> mGlobalDialogID;
    TkID<128> mAssociatedMission;
}
