#pragma once

#include <skyscraper.h>

#include <toolkit/maths/geometry/TkSphere.h>
#include <toolkit/utilities/containers/TkStackVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <simulation/solarsystem/gcsolarsystemlocator.meta.h>
#include <simulation/solarsystem/planet/gcspaceskycoloursettinglist.meta.h>

SKYSCRAPER_BEGIN

struct cGcSolarSystemGeometry
{
    cTkStackVector<cTkSphere> mPlanetSpheres;
    cTkStackVector<cTkSphere> mPlanetExclusion;
};

class cGcSolarSystemGenerator
{
  public:
    struct GenerationData
    {
        const cGcSolarSystem *mpSolarSystem;
        cGcSolarSystemData *mMetaData;
        cGcSolarSystemAsteroidFields *mInfomap;
    };

    cTkStackVector<cGcSolarSystemLocator> mGeneratedLocators;
    cTkPersonalRNG mRNG;
    cGcSolarSystemGeometry mGeometry;
    cGcSpaceSkyColourSettingList *mapSkyColours[2];
    bool mbLoggingActive;
};

SKYSCRAPER_END