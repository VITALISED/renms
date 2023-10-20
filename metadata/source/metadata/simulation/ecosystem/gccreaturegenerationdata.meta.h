#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcCreatureGenerationData
{
    static unsigned long long muNameHash = 0x4742E3FE43A533C7;
    static unsigned long long muTemplateHash = 0xB997A39B7E5F90C3;

    cTkFixedArray<cGcCreatureGenerationOptionalWeightedList> maBiomeSpecific;
    cTkFixedArray<cGcCreatureGenerationOptionalWeightedList> maSubBiomeSpecific;
    cGcCreatureGenerationOptionalWeightedList AbandonedSystemSpecific;
    cGcCreatureGenerationOptionalWeightedList EmptySystemSpecific;
    cGcCreatureGenerationWeightedList Generic;
    cTkDynamicArray<cGcCreatureGenerationWeightedListDomainEntry> maAirArchetypesForEmptyGround;
    cTkFixedArray<float> maSandwormPresenceChance;
    cTkFixedArray<float> maLifeChance;
    cTkFixedArray<float> maRoleFrequencyModifiers;
    cTkFixedArray<float> maRarityFrequencyModifiers;
    cTkFixedArray<float> maGroundGroupsPerKm;
    cTkFixedArray<float> maWaterGroupsPerKm;
    cTkFixedArray<float> maAirGroupsPerKm;
    cTkFixedArray<float> maCaveGroupsPerKm;
    cTkFixedArray<float> maDensityModifiers;
    cTkFixedArray<float> maLifeLevelDensityModifiers;
    float mfHerdCreaturePenalty;
}
