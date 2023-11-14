#pragma once

#include <skyscraper.h>

#include <simulation/components/gameplay/GcNPCInteractiveObjectComponent.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/utilities/containers/TkStackVector.h>

SKYSCRAPER_BEGIN

enum eNPCNavGraphNodePhysProbeState
{
    ENPCNavGraphNodePhysProbeState_Untested,
    ENPCNavGraphNodePhysProbeState_Clear,
    ENPCNavGraphNodePhysProbeState_Blocked,
};

class cGcNavGraphNodeHandle
{
    __int16 miIndex;
    unsigned __int16 muId;
};

enum eNPCNavGraphNodeType
{
    ENPCNavGraphNodeType_NavNode,
    ENPCNavGraphNodeType_NavNode_Door,
    ENPCNavGraphNodeType_PointOfInterestNode,
    ENPCNavGraphNodeType_Slope,
    ENPCNavGraphNodeType_NavAreaConnection,
    ENPCNavGraphNodeType_NumTypes,
    ENPCNavGraphNodeType_Invalid,
};

class cGcNavGraphQuadTree
{
    struct sNavNodeData
    {
        cGcNavGraphNodeHandle mNavNodeHnd;
        cTkPhysRelVec3 mvWorldPos;
    };

    struct AABB
    {
        cTkPhysRelMat34 mCentreTransform;
        float mfHalfDimension;
    };

    struct TreeNode
    {
        cGcNavGraphQuadTree::AABB mBoundary;
        cGcNavGraphQuadTree::TreeNode *mpTopLeft;
        cGcNavGraphQuadTree::TreeNode *mpTopRight;
        cGcNavGraphQuadTree::TreeNode *mpBottomLeft;
        cGcNavGraphQuadTree::TreeNode *mpBottomRight;
        cTkStackVector<cGcNavGraphQuadTree::sNavNodeData, 4> maNavNodes;
    };

    cGcNavGraphQuadTree::TreeNode *mpRootNode;
};

class cGcNavGraphNode
{
  public:
    struct NavGraphPath
    {
        cTkVector<cGcNavGraphNodeHandle> maPath;
    };

    struct NodeLink
    {
        cGcNavGraphNodeHandle mToNodeHandle;
        float mfDistance;
        float mfLastPhysProbeTime;
        eNPCNavGraphNodePhysProbeState mePhysProbeState;
    };

    eNPCNavGraphNodeType meType;
    cGcNPCInteractiveObjectComponent *mpInteractionObject;
    TkHandle mWorldNode;
    cTkStackVector<cGcNavGraphNode::NodeLink, 8> maLinks;
    float mfArriveDistance;
    bool mbIsWFCBuildingInterior;
    bool mbMarkedForDeletion;
    TkID<128> mBaseObjectID;
    cTkAttachmentPtr mConnectedNavAreaAttachment;
    cTkPhysRelVec3 mvFloorPoint;
    cGcNavGraphNodeHandle mHandle;
};

class cGcNPCNavGraph
{
    struct NavGraphPath
    {
        cTkVector<cGcNavGraphNodeHandle> maPath;
    };

    cTkStackVector<cGcNavGraphNodeHandle, 64> maGraphNodeHandles;
    cTkStackVector<cGcNavGraphNode, 64> maGraphNodes;
    int miNodeFreelistHead;
    int miNodesAllocated;
    unsigned int muNodeIdIndex;
    cTkPhysRelMat34 mTransform;
    cGcNavGraphQuadTree mQuadTree;
    bool mbSpatialPartitioningEnabled;
    cGcNPCNavigationAreaComponent *mpNavArea;
};

SKYSCRAPER_END