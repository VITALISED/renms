#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/gccreaturetypes.meta.h>
#include <metadata/simulation/ecosystem/creatures/gccreaturetagandrarity.meta.h>
enum eMoveArea
{
    EMoveArea_Ground = 0,
    EMoveArea_Water = 1,
    EMoveArea_Air = 2,
    EMoveArea_Space = 3,
}
#include <metadata/reality/gccreaturerarity.meta.h>
#include <metadata/simulation/ecosystem/creatures/gccreaturerolefrequencymodifier.meta.h>

class cGcCreatureData
{
    static unsigned long long muNameHash = 0x132EB7906E53B7A7;
    static unsigned long long muTemplateHash = 0xE8545DE962F52F8E;

    TkID<128> mId;
    bool mbOnlySpawnWhenIdIsForced;
    cGcCreatureTypes ForceType;
    cGcCreatureTypes RealType;
    bool mbEcoSystemCreature;
    bool mbCanBeFemale;
    cTkDynamicArray<cGcCreatureTagAndRarity> maTags;
    eMoveArea MoveArea;
    float mfMinScale;
    float mfMaxScale;
    float mfFurLengthModifierAtMinScale;
    float mfFurLengthModifierAtMaxScale;
    float mfFurChance;
    cGcCreatureRarity Rarity;
    cGcCreatureRoleFrequencyModifier PredatorProbabilityModifier;
    cGcCreatureRoleFrequencyModifier HerbivoreProbabilityModifier;
    cTkDynamicArray<cTkClassPointer> maData;
}
