#pragma once

#include <skyscraper.h>

#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gameplay/gcnpcplacementinfo.meta.h>

SKYSCRAPER_BEGIN

class cGcNPCPlacementComponent : public cTkComponent
{
    struct NPCPlacement
    {
        TkHandle mPlacementNode;
        unsigned __int64 mSeed;
        const cGcNPCPlacementInfo *mpPlacementInfo;
    };

    enum ePlaceObjectState
    {
        EPlaceObjectState_None,
        EPlaceObjectState_Requested,
        EPlaceObjectState_WaitForStablePosition,
        EPlaceObjectState_GeneratePlacementInfo,
        EPlaceObjectState_FindPlacementNodes,
        EPlaceObjectState_GeneratePlacements,
        EPlaceObjectState_DoPlacement,
        EPlaceObjectState_Complete,
    };

    cTkVector<cGcNPCPlacementComponent::NPCPlacement> maPlacements;
    cGcNPCPlacementComponent::ePlaceObjectState meObjectPlacementState;
    TkHandle mGroupNode;
    TkHandle mNode;
    int miNumObjectsAdded;
    int miNumPlacementInfosApplied;
    cTkVector<std::pair<cGcInteractionComponent *, cGcNPCPlacementInfo const>> maInteractionPlacementPairs;
    cTkPersonalRNG mRNG;
    cTkVector<TkHandle> maUsedNodes;
    bool mbPreviousActivation;
    cTkVector<cGcNPCPlacementInfo const *> maPlacementInfosToApply;
    cTkVector<unsigned int> maSpawnUnderNodeNameHashes;
    cTkVector<TkHandle> maPlacementNodes;
    cTkVector<TkHandle> maPlaced;
    cGcBuilding *mpBuilding;
    bool mbDebugDraw;
    cGcNPCPlacementComponentData *mpData;
};

SKYSCRAPER_END