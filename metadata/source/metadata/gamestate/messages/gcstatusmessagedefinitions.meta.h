#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/messages/gcstatusmessagedefinition.meta.h>
#include <metadata/gamestate/messages/gcpetvocabularyentry.meta.h>
#include <metadata/gamestate/messages/gcfriendlydronevocabularyentry.meta.h>

class cGcStatusMessageDefinitions
{
    static unsigned long long muNameHash = 0x434379BF90DDF679;
    static unsigned long long muTemplateHash = 0x16C04EDC7948B399;

    cTkDynamicArray<cGcStatusMessageDefinition> maMessages;
    cTkColour mMissionMarkupColour;
    cTkFixedArray<cGcPetVocabularyEntry> maPetVocabulary;
    cTkFixedArray<cGcPetVocabularyEntry> maPetChatTemplates;
    cTkFixedArray<cGcFriendlyDroneVocabularyEntry> maFriendlyDroneChatTemplates;
}
