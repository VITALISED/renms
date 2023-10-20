#pragma once
#include <metadata/metadata_common.h>
enum ePetVocabularyWord
{
    EPetVocabularyWord_Attack = 0,
    EPetVocabularyWord_Dislike = 1,
    EPetVocabularyWord_Cute = 2,
    EPetVocabularyWord_Good = 3,
    EPetVocabularyWord_Happy = 4,
    EPetVocabularyWord_Hostile = 5,
    EPetVocabularyWord_Like = 6,
    EPetVocabularyWord_Lonely = 7,
    EPetVocabularyWord_Loved = 8,
    EPetVocabularyWord_Noise = 9,
    EPetVocabularyWord_OwnerLove = 10,
    EPetVocabularyWord_SummonedTrait = 11,
    EPetVocabularyWord_Hungry = 12,
    EPetVocabularyWord_Tickles = 13,
    EPetVocabularyWord_Yummy = 14,
}

class cGcPetVocabularyWords
{
    static unsigned long long muNameHash = 0xDCBFB26222DD9DE6;
    static unsigned long long muTemplateHash = 0xA041098462C7EC70;

    ePetVocabularyWord PetVocabularyWord;
}
