#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcmaintenanceelementgroups.meta.h>
#include <metadata/reality/gcinventorytype.meta.h>
enum eUpdateType
{
    EUpdateType_UpdatesAlways = 0,
    EUpdateType_UpdateOnlyWhenComplete = 1,
    EUpdateType_UpdateOnlyWhenNotComplete = 2,
}
enum eCompletionRequirement
{
    ECompletionRequirement_FullyChargedAndRepaired = 0,
    ECompletionRequirement_AnyChargeAndRepaired = 1,
    ECompletionRequirement_FullyRepaired = 2,
    ECompletionRequirement_NotFullyCharged = 3,
    ECompletionRequirement_EmptySlot = 4,
    ECompletionRequirement_NoRequirement = 5,
    ECompletionRequirement_UserInstalls = 6,
    ECompletionRequirement_HasIngredients = 7,
}

class cGcMaintenanceElement
{
    static unsigned long long muNameHash = 0x79BDBA7746F3C796;
    static unsigned long long muTemplateHash = 0xC7878A2059B371AB;

    cGcMaintenanceElementGroups ItemGroupOverride;
    cGcInventoryType Type;
    TkID<128> mId;
    float mfMinRandAmount;
    float mfMaxRandAmount;
    int miMaxCapacity;
    float mfAmountEmptyTimePeriod;
    eUpdateType UpdateType;
    int miDamagedAfterTimePeriodMin;
    int miDamagedAfterTimePeriodMax;
    eDamageStatus DamageStatus;
    eCompletionRequirement CompletionRequirement;
}
