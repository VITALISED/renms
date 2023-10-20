#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/galaxy/gcgalaxystartypes.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetclass.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetsize.meta.h>
#include <metadata/simulation/solarsystem/planet/gcbiometype.meta.h>
#include <metadata/simulation/solarsystem/planet/gcbiomesubtype.meta.h>

class cGcPlanetGenerationInputData
{
    static unsigned long long muNameHash = 0x2E161A5A69971115;
    static unsigned long long muTemplateHash = 0x9F95770CDD1342B2;

    cTkSeed mSeed;
    cGcGalaxyStarTypes Star;
    cGcPlanetClass Class;
    TkID<128> mCommonSubstance;
    TkID<128> mRareSubstance;
    cGcPlanetSize PlanetSize;
    cGcBiomeType Biome;
    cGcBiomeSubType BiomeSubType;
    bool mbHasRings;
    bool mbForceContinents;
    bool mbInEmptySystem;
    bool mbInAbandonedSystem;
    bool mbInPirateSystem;
    bool mbPrime;
    int miRealityIndex;
}
