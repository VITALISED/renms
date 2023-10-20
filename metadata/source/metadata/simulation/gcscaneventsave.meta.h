#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gcbuildingclassification.meta.h>
#include <metadata/gamestate/gcplayermissionparticipanttype.meta.h>

class cGcScanEventSave
{
    static unsigned long long muNameHash = 0x434C17159AF37265;
    static unsigned long long muTemplateHash = 0xBB2142F8AFF05E7A;

    int miTable;
    TkID<256> mEvent;
    unsigned long long mui64GalacticAddress;
    cTkSeed mBuildingSeed;
    cTkVector3 mBuildingLocation;
    cGcBuildingClassification BuildingClass;
    float mfTime;
    TkID<128> mMissionID;
    unsigned long long mui64MissionSeed;
    cGcPlayerMissionParticipantType ParticipantType;
}
