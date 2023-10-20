#pragma once
#include <metadata/metadata_common.h>
enum ePersistentBaseTypes
{
    EPersistentBaseTypes_HomePlanetBase = 0,
    EPersistentBaseTypes_FreighterBase = 1,
    EPersistentBaseTypes_ExternalPlanetBase = 2,
    EPersistentBaseTypes_CivilianFreighterBase = 3,
    EPersistentBaseTypes_FriendsPlanetBase = 4,
    EPersistentBaseTypes_FriendsFreighterBase = 5,
    EPersistentBaseTypes_SpaceBase = 6,
    EPersistentBaseTypes_GeneratedPlanetBase = 7,
    EPersistentBaseTypes_GeneratedPlanetBaseEdits = 8,
}

class cGcPersistentBaseTypes
{
    static unsigned long long muNameHash = 0x1E20A14918514C43;
    static unsigned long long muTemplateHash = 0xDC40A2A2CA47998D;

    ePersistentBaseTypes PersistentBaseTypes;
}
