#pragma once

#include <skyscraper.h>

#include <simulation/solarsystem/buildings/GcBuilding.h>
#include <simulation/solarsystem/npcs/navigation/GcNPCNavGraph.h>
#include <toolkit/simulation/components/TkComponent.h>

#include <simulation/solarsystem/npcs/navigation/gcnpcnavigationareacomponentdata.meta.h>

SKYSCRAPER_BEGIN

enum eNavAreaUpdateStage
{
    ENavAreaUpdateStage_WaitToStart,
    ENavAreaUpdateStage_GatherLocators,
    ENavAreaUpdateStage_CalculateNodeFloorPositions,
    ENavAreaUpdateStage_GenerateGraph,
    ENavAreaUpdateStage_ValidateLinks,
    ENavAreaUpdateStage_SimplifyGraph,
    ENavAreaUpdateStage_CleanGraph,
    ENavAreaUpdateStage_ReadyForNavigation,
    ENavAreaUpdateStage_NumStages,
};

class cGcNPCNavigationAreaComponent : cTkComponent
{
    cGcNPCNavigationAreaComponentData *mpData;
    bool mbDebugDrawGraph;
    bool mbDebugDrawPhysProbes;
    TkHandle mRootNode;
    int miWaitFrames;
    eNavAreaUpdateStage meUpdateStage;
    cGcNPCNavGraph mNavGraph;
    cGcBuilding *mpBuilding;
    cTkRaycastJob mRaycastJob;
    cGcNPCNavigationAreaComponent::eLinkValidityStage meLinkValidityStage;
    std::deque<cGcNavGraphNodeHandle, TkSTLAllocatorShim<cGcNavGraphNodeHandle, 2, 20>> maNavNodesPendingCheck;
    std::vector<cGcNavGraphNodeHandle, TkSTLAllocatorShim<cGcNavGraphNodeHandle, 2, 20>> maRayJobToNavNodes;
    std::vector<cGcNPCNavGraph::TestedLink, TkSTLAllocatorShim<cGcNPCNavGraph::TestedLink, 2, -1>> mTestedLinks;
    bool mbUseRecurrentPhysicsValidation;
    bool mbProbesInFlight;
    cGcNPCNavGraphPhysProbeJob *mpProbeJob;
    cTkStackVector<cGcNavGraphLinkHandle, 32, -1> maProbeJobNodeLinks;
};

SKYSCRAPER_END