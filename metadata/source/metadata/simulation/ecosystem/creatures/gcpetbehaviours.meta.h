#pragma once
#include <metadata/metadata_common.h>
enum ePetBehaviour
{
    EPetBehaviour_None = 0,
    EPetBehaviour_Idle = 1,
    EPetBehaviour_Eat = 2,
    EPetBehaviour_Poop = 3,
    EPetBehaviour_LayEgg = 4,
    EPetBehaviour_FollowPlayer = 5,
    EPetBehaviour_AdoptedFollowPlayer = 6,
    EPetBehaviour_ScanForResource = 7,
    EPetBehaviour_FindResource = 8,
    EPetBehaviour_FindHazards = 9,
    EPetBehaviour_AttackHazard = 10,
    EPetBehaviour_FindBuilding = 11,
    EPetBehaviour_Fetch = 12,
    EPetBehaviour_Explore = 13,
    EPetBehaviour_Emote = 14,
    EPetBehaviour_GestureReact = 15,
    EPetBehaviour_OrderedToPos = 16,
    EPetBehaviour_ComeHere = 17,
    EPetBehaviour_Mine = 18,
    EPetBehaviour_Summoned = 19,
    EPetBehaviour_Adopted = 20,
    EPetBehaviour_Hatched = 21,
    EPetBehaviour_PostInteract = 22,
    EPetBehaviour_Rest = 23,
    EPetBehaviour_Attack = 24,
    EPetBehaviour_Watch = 25,
    EPetBehaviour_Greet = 26,
    EPetBehaviour_TeleportToPlayer = 27,
}

class cGcPetBehaviours
{
    static unsigned long long muNameHash = 0x82204A5605D64063;
    static unsigned long long muTemplateHash = 0xD8AD71C286DECFF3;

    ePetBehaviour PetBehaviour;
}
