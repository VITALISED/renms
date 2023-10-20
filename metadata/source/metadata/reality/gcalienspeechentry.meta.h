#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/tables/gcwordcategorytableenum.meta.h>
enum eWordInteractEffect
{
    EWordInteractEffect_Pain = 0,
    EWordInteractEffect_Heal = 1,
}
#include <metadata/reality/gcalienrace.meta.h>

class cGcAlienSpeechEntry
{
    static unsigned long long muNameHash = 0xB81D78F21EBE37;
    static unsigned long long muTemplateHash = 0xC9729B0D1412C4AB;

    TkID<128> mId;
    TkID<256> mText;
    TkID<256> mGroup;
    cgcwordcategorytableEnum Category;
    int miFrequency;
    eWordInteractEffect WordInteractEffect;
    cGcAlienRace Race;
    int miLevel;
}
