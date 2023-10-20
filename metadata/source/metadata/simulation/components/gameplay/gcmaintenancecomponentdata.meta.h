#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcmaintenanceelement.meta.h>
enum eInteractable
{
    EInteractable_OnlyWhenComplete = 0,
    EInteractable_OnlyWhenNotComplete = 1,
    EInteractable_Always = 2,
    EInteractable_Never = 3,
}
#include <metadata/tkmodelrendererdata.meta.h>
enum eModelRendererResource
{
    EModelRendererResource_ModelNode = 0,
    EModelRendererResource_MasterModelNode = 1,
}
#include <metadata/simulation/components/utils/gcbroadcastlevel.meta.h>

class cGcMaintenanceComponentData
{
    static unsigned long long muNameHash = 0x479CFCB871ABBE0;
    static unsigned long long muTemplateHash = 0x508485AA3B7F83E0;

    cTkDynamicArray<cGcMaintenanceElement> maPreInstalledTech;
    int miVisibleMaintenanceSlots;
    bool mbAllowRepair;
    bool mbAllowCharge;
    bool mbAllowDismantle;
    bool mbAllowInstallTech;
    bool mbAllowCraftProduct;
    bool mbAllowTransfer;
    bool mbAllowMoveAndStack;
    bool mbAllowTransferIn;
    bool mbAutoCompleteOnStart;
    bool mbUseModelResourceRenderer;
    bool mbUseBoundsForIconCentre;
    eInteractable Interactable;
    bool mbForceNoninteraction;
    float mfCompletedTransitionDelay;
    bool mbShareInteractionModelRender;
    cTkModelRendererData ModelRenderData;
    cTkModelRendererData ModelRenderDataAlt;
    eModelRendererResource ModelRendererResource;
    cGcBroadcastLevel BroadcastLevel;
    TkID<256> mTitle;
    TkID<256> mDescription;
    TkID<256> mActionButtonOverride;
    TkID<256> mActionDescriptionOverride;
    TkID<256> mTransferButtonOverride;
    TkID<256> mTransferDescriptionOverride;
    TkID<256> mDiscardButtonOverride;
    TkID<256> mDiscardDescriptionOverride;
    TkID<256> mActionWarningOverride;
    float mfInWorldUIScaler;
    float mfInWorldUIMinDistOverride;
    float mfInWorldUIMinDistOverrideV2;
    float mfInWorldUIForcedOffset;
    float mfInWorldUIForcedOffsetV2;
    bool mbInWorldUIUseCameraUp;
    bool mbInteractionRequiresPower;
    TkID<128> mStartMissionOnUse;
}
