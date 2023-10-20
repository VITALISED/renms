#pragma once
#include <metadata/metadata_common.h>
enum eActionType
{
    EActionType_Repair = 0,
    EActionType_UpdateDamagedComponents = 1,
    EActionType_CargoPhoneCall = 2,
}

class cGcFrigateInteractionAction
{
    static unsigned long long muNameHash = 0xD1183794AF82FF99;
    static unsigned long long muTemplateHash = 0x61DF172F7A9D8DB4;

    eActionType ActionType;
    TkID<256> mCommunicatorDialog;
}
