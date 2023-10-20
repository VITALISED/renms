#pragma once
#include <metadata/metadata_common.h>
enum eMissionUpdateMessage
{
    EMissionUpdateMessage_Start = 0,
    EMissionUpdateMessage_End = 1,
}
enum ePlayMusicSting
{
    EPlayMusicSting_None = 0,
    EPlayMusicSting_Start = 1,
    EPlayMusicSting_End = 2,
}

class cGcMissionSequenceShowMissionUpdateMessage
{
    static unsigned long long muNameHash = 0x2431FBC75DE4AEB6;
    static unsigned long long muTemplateHash = 0xD729431BCB083995;

    eMissionUpdateMessage MissionUpdateMessage;
    TkID<256> mCustomMessageLocID;
    TkID<256> mCustomObjectiveLocID;
    bool mbSetMissionSelected;
    bool mbWaitForMessageOver;
    bool mbShowChangeMissionNotify;
    ePlayMusicSting PlayMusicSting;
    cTkFixedString<128,char> macDebugText;
}
