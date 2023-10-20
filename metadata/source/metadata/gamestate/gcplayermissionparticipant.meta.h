#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPlayerMissionParticipant
{
    static unsigned long long muNameHash = 0xB223E7785971518B;
    static unsigned long long muTemplateHash = 0xEEFEC4DF3E984447;

    unsigned long long mui64UA;
    cTkSeed mBuildingSeed;
    cTkVector3 mBuildingLocation;
    cGcPlayerMissionParticipantType ParticipantType;
}
