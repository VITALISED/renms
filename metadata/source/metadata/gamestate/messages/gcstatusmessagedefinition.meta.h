#pragma once
#include <metadata/metadata_common.h>
enum eReplicateTo
{
    EReplicateTo_None = 0,
    EReplicateTo_Fireteam = 1,
    EReplicateTo_Fireteam_SameUA = 2,
    EReplicateTo_Global = 3,
    EReplicateTo_Global_Distance = 4,
    EReplicateTo_Fireteam_Distance = 5,
    EReplicateTo_Fireteam_Global_Distance = 6,
    EReplicateTo_Not_Fireteam = 7,
}
#include <?>

class cGcStatusMessageDefinition
{
    static unsigned long long muNameHash = 0x93C1244DBEE0E0CF;
    static unsigned long long muTemplateHash = 0xDE28BA6FB5EB5CDE;

    TkID<128> mId;
    TkID<256> mMessage;
    bool mbAddPlayerNamePrefix;
    bool mbAddPetNamePrefix;
    bool mbAddFriendlyDronePrefix;
    bool mbIncludePlayerName;
    eReplicateTo ReplicateTo;
    bool mbPostLocally;
    float mfDistance;
    float mfDisplayDurationMultiplier;
    bool mbOnlyInMultiplayer;
    bool mbOnlyOnFireteam;
    cGcStatusMessageMissionMarkup MissionMarkup;
}
