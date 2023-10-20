#pragma once
#include <metadata/metadata_common.h>
enum ePetChatType
{
    EPetChatType_Adopted = 0,
    EPetChatType_Hatched = 1,
    EPetChatType_Summoned = 2,
    EPetChatType_Greeting = 3,
    EPetChatType_Hazard = 4,
    EPetChatType_Scanning = 5,
    EPetChatType_PositiveEmote = 6,
    EPetChatType_HungryEmote = 7,
    EPetChatType_LonelyEmote = 8,
    EPetChatType_Go_There = 9,
    EPetChatType_Come_Here = 10,
    EPetChatType_Planet = 11,
    EPetChatType_Mine = 12,
    EPetChatType_Attack = 13,
    EPetChatType_Chase = 14,
    EPetChatType_ReceivedTreat = 15,
    EPetChatType_Tickled = 16,
    EPetChatType_Ride = 17,
    EPetChatType_Egg_Laid = 18,
    EPetChatType_Customise = 19,
    EPetChatType_Unsummoned = 20,
}

class cGcPetChatType
{
    static unsigned long long muNameHash = 0x51175DF2E4A2F863;
    static unsigned long long muTemplateHash = 0x12CAC40DB6314D79;

    ePetChatType PetChatType;
}
