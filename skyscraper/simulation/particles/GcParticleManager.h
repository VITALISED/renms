#pragma once

#include <skyscraper.h>

#include <simulation/particles/GcEffectList.h>
#include <simulation/particles/GcExplosion.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/particles/gcareadamagedata.meta.h>
#include <simulation/particles/gcexplosiondatatable.meta.h>

SKYSCRAPER_BEGIN

enum eHeavyAirType
{
    EHeavyAir_None,
    EHeavyAir_Planet,
    EHeavyAir_Cave,
    EHeavyAir_Underwater,
    EHeavyAir_Space,
    EHeavyAir_AbandonedFreighter,
    EHeavyAir_SpaceStorm,
};

class cGcParticleManager
{
    class cGcHeavyAir
    {
        cTkSmartResHandle mResource;
        TkHandle mRootNode;
        eHeavyAirType meType;
        cTkColour lColour1;
        cTkColour lColour2;
        cTkVector<TkHandle> mChildNodes;
    };

    struct EffectHistory
    {
        TkID<128> mId;
        float mfTime;
    };

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
    cTkVector<cGcParticleManager::EffectHistory> maEffectHistory;
};

SKYSCRAPER_END