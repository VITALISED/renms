#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPetVocabularyEntry
{
    static unsigned long long muNameHash = 0x370A2ECAE460B961;
    static unsigned long long muTemplateHash = 0x3574C34B687AFFE5;

    TkID<256> mGenericFallback;
    float mfOddsOfProcReplacement;
    cTkDynamicArray<cGcPetVocabularyTraitEntry> maVocabulary;
}
