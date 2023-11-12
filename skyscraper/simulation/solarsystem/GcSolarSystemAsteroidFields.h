#pragma once

#include <skyscraper.h>

#include <simulation/solarsystem/asteroid/GcAsteroidLayout.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/solarsystem/asteroids/gcasteroidgeneratorring.meta.h>
#include <simulation/solarsystem/asteroids/gcasteroidgeneratorslab.meta.h>
#include <simulation/solarsystem/asteroids/gcasteroidgeneratorsurround.meta.h>

SKYSCRAPER_BEGIN

class cGcSolarSystemAsteroidFields
{
    struct AsteroidGenerators
    {
        cTkVector<cGcAsteroidGeneratorRing> mRings;
        cTkVector<cGcAsteroidGeneratorSurround> mSurrounds;
        cTkVector<cGcAsteroidGeneratorSlab> mSlabs;
    };

    cTkMatrix34 mPlayerSpawnTM;
    cGcSolarSystemAsteroidFields::AsteroidGenerators mAsteroidGenerators;
    cGcAsteroidLayout mAsteroids;
};

SKYSCRAPER_END