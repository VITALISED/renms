#pragma once

#include <skyscraper.h>

#include <simulation/particles/GcEffectList.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/particles/gcareadamagedata.meta.h>
#include <simulation/particles/gcexplosiondatatable.meta.h>

SKYSCRAPER_BEGIN

class cGcParticleManager
{
    cTkVector<cGcExplosionDataTable *> mapEffectDataTables;
    cTkUnorderedMap<TkID<128>, cGcExplosionData *, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128>>> maEffectLookup;
    cTkUnorderedMap<TkID<128>, cGcAreaDamageData *, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128>>>
        maAreaDamageLookup;
    cTkSmartResHandle mSpeedLineRes;
    cTkSmartResHandle mLinesRes;
    TkHandle mParticleGroupNode;
    TkHandle mSpeedLinesNode;
    TkHandle mLinesNode;
    cGcEffectList<cGcExplosion, 512> mEffects;
    cTkVector<TkHandle> maEffectsToDestroyOnCompletion;
    cGcParticleManager::cGcHeavyAir mActiveHeavyAir;
    TkID<128> mRequestDebugViewEffect;
    TkID<128> mRequestDebugEditEffect;
    bool mbParticleDebugRender;
    bool mbHeavyAirChangeRequested;
    float mfHeavyAirFade;
    eHeavyAirType meRequestedHeavyAirType;
    cTkSeed mSeed;
    std::vector<cGcParticleManager::EffectHistory, TkSTLAllocatorShim<cGcParticleManager::EffectHistory, 8, -1>>
        maEffectHistory;
};

SKYSCRAPER_END