#pragma once
#include <metadata/metadata_common.h>
enum eInteractionAction
{
    EInteractionAction_PressButton = 0,
    EInteractionAction_HoldButton = 1,
    EInteractionAction_Shoot = 2,
}
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
enum eOverrideInteriorExteriorMarker
{
    EOverrideInteriorExteriorMarker_No = 0,
    EOverrideInteriorExteriorMarker_Interior = 1,
    EOverrideInteriorExteriorMarker_Exterior = 2,
}

class cGcInteractionComponentData
{
    static unsigned long long muNameHash = 0xDAB0554EA36957B5;
    static unsigned long long muTemplateHash = 0x345DED12B36153C4;

    eInteractionAction InteractionAction;
    cGcInteractionType InteractionType;
    bool mbUseIntermediateUI;
    cTkModelRendererData Renderer;
    cTkModelRendererData RendererAlt;
    cGcAlienRace Race;
    float mfAttractDistanceSq;
    bool mbSecondaryMeshAlwaysVisible;
    bool mbRepeatInteraction;
    bool mbUseInteractCamera;
    float mfBlendToCameraTime;
    float mfBlendFromCameraTime;
    cGcInteractionActivationCost ActivationCost;
    TkID<128> mTriggerAction;
    TkID<128> mTriggerActionOnPrepare;
    bool mbBroadcastTriggerAction;
    float mfInteractAngle;
    float mfInteractDistance;
    bool mbInteractInvertFace;
    cGcInteractionType SecondaryInteractionType;
    cGcInteractionActivationCost SecondaryActivationCost;
    cTkDynamicArray<cTkModelRendererData> maEventRenderers;
    cTkDynamicArray<cTkModelRendererData> maEventRenderersAlt;
    float mfSecondaryCameraTransitionTime;
    cGcInteractionDof DepthOfField;
    cTkDynamicArray<cGcAlienPuzzleMissionOverride> maPuzzleMissionOverrideTable;
    cGcStoryUtilityOverride StoryUtilityOverrideData;
    eOverrideInteriorExteriorMarker OverrideInteriorExteriorMarker;
    bool mbReseedAfterRewardSuccess;
    bool mbUsePersonalPersistentBuffer;
    float mfInWorldUIScaler;
    float mfInWorldUIMinDistOverride;
    float mfInWorldUIMinDistOverrideV2;
    float mfInWorldUIForcedOffset;
    float mfInWorldUIForcedOffsetV2;
    bool mbInWorldUIUseCameraUp;
    TkID<128> mStartMissionOnUse;
    bool mbAllowMissionUnderwater;
}
