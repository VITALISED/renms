#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCreatureVocalData
{
    static unsigned long long muNameHash = 0x505F7128834EAACA;
    static unsigned long long muTemplateHash = 0xED0EA1EB716B1C8F;

    float mfScaleBias;
    cGcCreatureVocalSoundData IdleVocal;
    cGcCreatureVocalSoundData FleeVocal;
    cGcCreatureVocalSoundData DeathVocal;
    cGcCreatureVocalSoundData AttackVocal;
}
