#pragma once

#include <skyscraper.h>

#include <simulation/player/GcPlayerCommon.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/utilities/TkArray.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <reality/gcalienrace.meta.h>
#include <reality/gcfrigateclass.meta.h>
#include <reality/gcinventoryclass.meta.h>
#include <simulation/gcfrigatetraitdata.meta.h>

SKYSCRAPER_BEGIN

class cGcFleetExpedition;

class cGcFleetFrigate
{
    std::array<cGcFrigateTraitData const *, 5> maTraits;
    cTkVector<cGcMaintenanceComponent *> mapDamagedMaintenanceComponents;
    cTkVector3 mPirateDefenceSpawnPosition;
    unsigned __int64 mu64TimeOfLastIncomeCollection;
    cTkAABB mAABB;
    cTkSeed mSeed;
    cTkSeed mHomeSystemSeed;
    cTkSeed mForcedTraitsSeed;
    cTkFixedString<32, char> mCustomName;
    eFrigateClass meFrigateClass;
    eInventoryClass meInventoryClass;
    eAlienRace meRace;
    TkID<128> mPrimaryTraitOverride;
    float mfTimeUntilSpawnEvent;
    int miTotalNumberOfSuccessfulEvents;
    int miTotalNumberOfFailedEvents;
    int miTotalNumberOfExpeditions;
    int miNumberOfTimesDamaged;
    int maiStats[11];
    cTkBitArray<unsigned __int64, 8> mDamageTaken;
    TkHandle mOnPlanetFalseFrigateNode;
    cGcAIShipSpawn *mpAIShipSpawn;
    const cGcPlayerCommon *mpPirateDefencePlayer;
    cTkAttachmentPtr mLODAttachment;
    cGcFleetExpedition *mpExpedition;
};

SKYSCRAPER_END