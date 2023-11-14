#pragma once

#include <skyscraper.h>

#include <gamestate/GcInventoryStore.h>
#include <simulation/solarsystem/buildings/GcBuilding.h>
#include <toolkit/simulation/components/TkComponent.h>

#include <simulation/components/gameplay/gcmaintenancecomponentdata.meta.h>

SKYSCRAPER_BEGIN

union MaintenanceFlags {
    struct InternalData
    {
        unsigned __int16 mbForcedBroken : 1;
        unsigned __int16 mbForcedFixed : 1;
        unsigned __int16 mbManualOn : 1;
        unsigned __int16 muCounter : 12;
        unsigned __int16 mbDisableSynchronise : 1;
    };

    MaintenanceFlags::InternalData mData;
    unsigned __int16 mBlob;
};

enum ePopupAction : __int32
{
    EPopupAction_None = 0xFFFFFFFF,
    EPopupAction_Transfer,
    EPopupAction_TransferSend,
    EPopupAction_BuildTech,
    EPopupAction_BuildProduct,
    EPopupAction_TechCharge,
    EPopupAction_Repair,
    EPopupAction_Outfitting,
    EPopupAction_ByteBeatSend,
    EPopupAction_NumTypes,
};

class cGcMaintenanceComponent : cTkComponent
{
    cGcMaintenanceComponentData *mpData;
    std::vector<ePopupAction> maMaintenanceEmptySlotActions;
    int mPopupActions;
    cGcInventoryStore mInventoryStore;
    int miMaintenanceSlotsCount;
    unsigned __int64 muiSlotStates;
    MaintenanceFlags mFlags;
    TkHandle mInteractLocator;
    TkHandle mInteractInWorld;
    float mafPreInstalledTechPeriodMultipliers[16];
    float mafItemAmountAccumulators[16];
    float mafItemDamageTimers[16];
    __int64 miLastUpdatedTime;
    bool mbHasBeenInteractedWith;
    cGcBuilding *mpBuilding;
    cGcObjectPlacementComponent *mpObjectPlacement;
    cTkVector3 mCentreOffset;
    TkHandle mModelNode;
    bool mbIsSetup;
    cTkVector3 mLastPosition;
    float mfCheckSetupTimer;
    unsigned __int16 mLastChangeHash;
    sComponentBaseObjectHandle mBaseObjectHandle;
    cTkFixedString<256, char> mTitle;
    unsigned __int64 mCompletedTimestamp;
    unsigned __int64 mBrokenTimestamp;
    bool mbShouldSave;
};

SKYSCRAPER_END