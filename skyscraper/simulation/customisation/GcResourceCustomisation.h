#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/data/TkMetaData.h>
#include <metadata/tkproceduraltexturechosenoptionlist.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetcolourdata.meta.h>
#include <metadata/tkpalettetexture.meta.h>

SKYSCRAPER_BEGIN

struct CustomisationData
{
    cTkSeed mResourceSeed;
    cTkVector<TkID<256> > mDescriptors;
    cTkProceduralTextureChosenOptionList mTextureOptions;
    std::map<TkID<128>,float,std::less<TkID<128> > > mBoneScales;
    bool mbUseLegacyColourPalettes;
    bool mbEditedColours;
    cGcPlanetColourData mEditColours;
    cGcPlanetColourData mFinalColours;
    float mfScale;
};

class cGcResourceCustomisation
{
    CustomisationData mResourceCustomisation;
    TkID<128> mPresetName;
    cTkVector<TkID<128> > mDescriptorGroups;
    std::map<TkID<128>,TkID<256>,std::less<TkID<128> >,std::allocator<std::pair<TkID<128> const ,TkID<256> > > > mChosenTextureOptions;
    TkID<256> mForcedTextureName;
    const ePalette kReplicatedPalettes[11];
    const eColourAlt kReplicatedColourAlts[3];
};


SKYSCRAPER_END