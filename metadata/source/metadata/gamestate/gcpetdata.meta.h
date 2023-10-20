#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcbiometype.meta.h>
#include <metadata/simulation/ecosystem/creatures/gccreaturetypes.meta.h>
#include <metadata/reality/gcdiscoveryowner.meta.h>

class cGcPetData
{
    static unsigned long long muNameHash = 0x995CD6C5BC075C98;
    static unsigned long long muTemplateHash = 0x94B8F33BBE978540;

    float mfScale;
    TkID<128> mCreatureID;
    cTkDynamicArray<TkID<256>> maDescriptors;
    cTkSeed mCreatureSeed;
    cTkSeed mCreatureSecondarySeed;
    unsigned long long mui64SpeciesSeed;
    unsigned long long mui64GenusSeed;
    TkID<256> mCustomSpeciesName;
    bool mbPredator;
    unsigned long long mui64UA;
    bool mbAllowUnmodifiedReroll;
    cTkSeed mColourBaseSeed;
    cTkSeed mBoneScaleSeed;
    bool mbHasFur;
    cGcBiomeType Biome;
    cGcCreatureTypes CreatureType;
    unsigned long long mui64BirthTime;
    unsigned long long mui64LastEggTime;
    unsigned long long mui64LastTrustIncreaseTime;
    unsigned long long mui64LastTrustDecreaseTime;
    bool mbEggModified;
    bool mbHasBeenSummoned;
    cTkFixedString<32,char> macCustomName;
    float mfTrust;
    cGcDiscoveryOwner SenderData;
    cTkFixedArray<float> maTraits;
    cTkFixedArray<float> maMoods;
}
