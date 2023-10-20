#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceBroadcastMessage
{
    static unsigned long long muNameHash = 0x60741FB7E840229E;
    static unsigned long long muTemplateHash = 0xBB8DE87F79BFFCF0;

    cTkFixedString<128,char> macDebugText;
    TkID<128> mMessageID;
    bool mbSeeded;
    bool mbSendToAllMatchingSeeds;
    bool mbMultiplayer;
    bool mbBroadcastToActiveMultiplayerMission;
}
