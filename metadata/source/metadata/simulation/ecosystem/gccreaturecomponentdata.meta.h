#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/behaviours/data/gcprimaryaxis.meta.h>
#include <metadata/simulation/particles/gcreplacementeffectdata.meta.h>
#include <metadata/simulation/particles/gccreaturediscoverythumbnailoverride.meta.h>

class cGcCreatureComponentData
{
    static unsigned long long muNameHash = 0x28E8DAB19EC55198;
    static unsigned long long muTemplateHash = 0x1639F80C9E1E506E;

    TkID<128> mId;
    cGcPrimaryAxis Axis;
    float mfScaler;
    float mfPetIndoorScaler;
    TkID<128> mDeathEffect;
    cTkDynamicArray<cGcReplacementEffectData> maReplacementImpacts;
    float mfAccessoryPitchOffset;
    float mfDiscoveryFurScaler;
    float mfDiscoveryUIScaler;
    cTkVector3 mDiscoveryUIOffset;
    cTkDynamicArray<cGcCreatureDiscoveryThumbnailOverride> maThumbnailOverrides;
    bool mbUsePetLargeUIOverride;
    float mfPetLargeUIOverrideScaler;
    cTkVector3 mPetLargeUIOverrideOffset;
}
