#pragma once

#include <skyscraper.h>

#include <simulation/character/npc/GcNPCNavGraph.h>
#include <toolkit/simulation/ai/behaviourtree/TkBehaviourTree.h>

#include <simulation/npcs/gcnpcdebugspawndata.meta.h>

SKYSCRAPER_BEGIN

class cGcNPCComponent;

class cGcNPCBlackboard
{
    enum eMode
    {
        EMode_Normal,
        EMode_CheckNavigability,
        EMode_StayAtSpawnPos,
        EMode_UnableToNav,
        EMode_OwnerTransferred,
    };

    enum eReturnToShipState
    {
        EReturnToShipState_None,
        EReturnToShipState_Stopping,
        EReturnToShipState_Turning,
        EReturnToShipState_Dissolving,
    };

    TkHandle mForceLookAt;
    float mfLastGreetTime;
    float mfLastReactTime;
    float mfLastLookAtPlayerTime;
    cGcNavGraphNodeHandle mBlockedNodeHandle;
    bool mbAllowLookAt;
    bool mbForceLookAtCamera;
    bool mbLookingAtLocalPlayer;
    bool mbInPlayerInteraction;
    bool mbAllowPlayerReaction;
    bool mbAllowFlavourIdles;
    bool mbCanConverse;
    bool mbTalking;
    bool mbDancing;
    bool mbNavDestinationOccupied;
    bool mbMobileReacting;
    cGcNPCBlackboard::eMode meMode;
    cGcNPCBlackboard::eReturnToShipState meReturnToShipState;
};

class cGcNPCBehaviourTree : cTkBehaviourTree
{
    struct NPCLightFader
    {
        TkHandle mNode;
        float mfDefaultIntensity;
    };

    cGcNPCComponent *mpNPC;
    cGcPlayerCharacterComponent *mpCharacter;
    int miCurrentPathNodeIndex;
    cGcNavGraphNodeHandle mDestinationNodeHandle;
    float mfArrivalDist;
    bool mbShouldAvoidNPCs;
    bool mbInteractionInterruptedNavigation;
    cGcNPCNavGraph::NavGraphPath mNavPath;
    cTkPhysRelVec3 mvNavTarget;
    float mfNavPathOffset;
    float mfCurrentNavSegmentDistance;
    cTkVector3 mvSpawnFacing;
    cTkPhysRelVec3 mvPreviousNavPos;
    float mfStaticTime;
    int miFailToReachNodeCount;
    float mfTimeNavigatingToCurrentNode;
    float mfBlockedTime;
    bool mbNoPhysicsFallbackMode;
    cTkPhysRelVec3 mNoPhysicsFallbackStartPosition;
    cGcNPCBlackboard mBlackboard;
    cTkPersonalRNG mRNG;
    cTkVector<cGcNPCBehaviourTree::NPCLightFader> maLights;
    cTkSmoothCD<float> mLightFader;
    cGcNPCDebugSpawnData *mpDebugSpawn;
    bool mbDebugDrawPath;
};

SKYSCRAPER_END