/**
 * @file EgMain.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <engine/source/engine/EgScene.h>
#include <engine/source/engine/EgShader.h>
#include <toolkit/animation/engine/TkNodeAnimationControllerEngine.h>
#include <toolkit/graphics/api/TkRenderStateCache.h>
#include <toolkit/maths/numeric/TkIntrinsics.h>
#include <toolkit/simulation/physics/TkLDSWind.h>
#include <toolkit/system/TkIterationState.h>
#include <toolkit/system/TkPollResult.h>
#include <toolkit/system/thread/TkThreadTypes.h>

SKYSCRAPER_BEGIN

struct EgRenderQueueHandle
{
    int miQueueId;
    int miFrameId;
};

enum EgRenderView
{
    __Normal,
    LeftEye,
    RightEye,
};

enum TryStoreMode
{
    Commit,
    Peek,
};

struct EgRenderCullMode
{
    enum Mode
    {
        UpdateEverything_SyncCull,
        UpdateEverything_AsyncCull,
        UpdateEverything_SingleThreadCull,
        NoUpdates_SyncCull,
        NoUpdates_AsyncCull,
        NoUpdates_SingleThreadCull,
        UpdateNodesNotFlags_SyncCull,
        UpdateNodesNotFlags_AsyncCull,
        UpdateNodesNotFlags_SingleThreadCull,
        PassDoesNotUseNodeGraph,
        UpdateEverything_DrawAllEnabled,
        NoUpdates_DrawAllEnabled,
        UpdateNodesNotFlags_DrawAllEnabled,
    };
};

enum TkResourceFindType
{
    Fail,
    Find,
    Overwrite,
};

struct EgOptions
{
    enum List
    {
        MaxLogLevel,
        MaxNumMessages,
        TrilinearFiltering,
        MaxAnisotropy,
        TexCompression,
        LoadTextures,
        FastAnimation,
        ShadowMapSize,
        WireframeMode,
        DebugViewMode,
        DumpFailedShaders,
        GatherTimeStats,
        TextureQuality,
    };
};

/**
 * @class Engine
 * @brief Public entry for engine calls.
 */
class Engine
{
  public:
    class cEgShaderCompilationState;

    static void AddAnimToModelAdditivePose(
        TkHandle lModelNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lAnimationRes, float lfTime,
        float lfWeight, TkID<128> *lpStartNodes, int liNumStartNodes, bool lbMirrored);
    static TkHandle &AddCameraNode(
        TkHandle parent, const char *name, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> pipelineRes);
    static TkHandle &AddGroupNode(TkHandle parent, const char *name);
    static TkHandle &AddLightNode(
        TkHandle parent, const char *name, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes,
        bool lbIsDirectional, const TkID<128> &lightingContext, const TkID<128> &shadowContext);
    static TkHandle &AddLocatorNode(TkHandle parent, const char *name);
    static TkHandle &AddNodes(TkHandle parent, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> sceneGraphRes);
    static void AddNodesStep(int maxNumNodesToAdd);
    static TkAddNodesHandle &AddNodesStep(
        TkHandle parent, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> sceneGraphRes, int maxNumNodesToAdd);
    static cTkSmartResHandle &AddResource(
        int liType, const char *lpcName, int liFlags, cTkResourceDescriptor *lAlternateMaterialId);
    static void AddResourceOwner(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResource,
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lLink);
    static bool AnyRenderTargetScaleChange(
        uint32_t luOldScaleIdx, uint32_t luNewScaleIdx, float lfOldScaleMul, float lfNewScaleMul,
        const char *lpSettingId);
    static bool ApplyAnimCommandList(cTkAnimCommand *lCommands, int liNumCommands);
    static void CheckForDeletedStreamingTextures();
    void CleanupMultithreadedPointers();
    static void ClearCameraBlurAndJitter(TkHandle lCameraNode);
    static void ClearModelAdditivePose(TkHandle modelNode);
    static void ClearNodeMotion(TkHandle lNode);
    cTkSmartResHandle &CloneResource(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lRes, const char *lpacName,
        cTkResourceDescriptor *lpDescriptor);
    static bool CompileAnyUncompiledShaders();
    static void CopyThreadData();
    cTkSmartResHandle &Create3DTexture(
        const char *lpacName, int liWidth, int liHeight, int liFmt, int liFlags, int, TkResourceFindType leFindType,
        cTkResourceDescriptor *lpResourceDescriptor);
    static int64_t CreateModelAnimationMapping(
        TkHandle lModelNode, const TkID<128> &lName, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lAnimationRes,
        cTkFixedString<64, char> *laStartNodes, int liNumStartNodes);
    static void CreateShaderCompilationState();
    cTkSmartResHandle &CreateTexture(
        const char *lpacName, int liWidth, int liHeight, int liFmt, int liFlags, TkResourceFindType leFindType,
        cTkResourceDescriptor *lpResourceDescriptor);
    void DeleteRemovedNodes();
    static void DestroyShaderCompilationState(Engine::cEgShaderCompilationState *lpState);
    static bool DoesHeadNodeUseJoint(TkHandle node, TkHandle joint);
    static bool DoesNodeUseJoint(TkHandle node, TkHandle joint);
    static void EncodeVertexIntoStream(
        TkHandle lMeshNode, const cTkSkinnedVertexData &lVertex, int liIndex, char *lpaVertexStream);
    static void EnqueueClearMaterialSamplers(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes);
    void EnqueueEndScissorTest();
    static void EnqueueFlushTexture(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture);
    static EgRenderQueueHandle EnqueueRender(
        TkHandle *cameraNode, uint32_t leMode, bool lbWakeJobThreads, bool lbHiPriorityJobs, bool lbStereoRender,
        EgRenderQueueHandle lQueueToCopy);
    static void EnqueueSetAsyncComputeEnable(bool lbEnable);
    static void EnqueueSetMaterialSampler(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes, const char *name,
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> texRes);
    static void EnqueueSetMaterialUniform(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes, const char *name, float a, float b, float c,
        float d);
    static void EnqueueSetRenderTarget(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> targetRes, cTkRenderStateCache *lpRenderStateCache, int,
        int liCubeFace);
    static void EnqueueSetResParamI(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res, int elem, int elemIdx, int param, int value);
    static void EnqueueSetSamplerDefaultTexture(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> shaderRes,
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTextureHandle, const char *sampleName, bool);
    static void EnqueueSetupViewport(int liX, int liY, int liWidth, int liHeight, bool lbResizeBuffers);
    static void ExecuteQueuedActions(int lParity);
    static cEgNodeAttachment *FindAttachment(TkHandle lStartNode, int liIndex);
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> &FindRes(
        int liType, const char *lpcName, const cTkResourceDescriptor *lAlternateMaterialId);
    static void ForceEvictTexture(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture, bool);
    static void ForceUpdateNodes(TkHandle lRootNode);
    static void GatherMaterialsForSceneGraph(
        cTkVector<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>> &lMaterials,
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResource);
    static const TkID<128> *GetAnimNameFromMapping(TkHandle lModelNode, int16_t luMapping);
    static void GetCameraProjMat(TkHandle cameraNode, cTkMatrix44 *projMat);
    static void GetCameraViewMat(TkHandle cameraNode, cTkMatrix44 *projMat);
    static cTkResource *GetDefaultTexture();
    static cTkResource *GetDefaultUavTexture();
    static cTkFixedString<256, char> *GetEvictedMips(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture);
    static AnimTransform &GetJointBindXform(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lGeoRes, int lJointIndex);
    static bool GetLocatorForModelAnim(
        TkHandle lModelNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lAnimationRes, const TkID<128> &lLocId,
        float lfPhase, bool lbMirrored, cTkVector3 &lTranslationOut, cTkQuaternion &lRotationOut);
    static bool GetMaterialUniform(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes, const char *name, float *a, float *b, float *c,
        float *d);
    static bool GetMaterialUniform(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes, uint64_t lNameHash, float *a, float *b, float *c,
        float *d);
    static TkHandle &GetModelNode(TkHandle node);
    static bool GetMoveLocatorForModelAnim(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lAnimationRes, const TkID<128> &lLocId, float lfStartPhase,
        float lfEndPhase, bool lbMirrored, float lfFakeMoveAnimSpeed, cTkVector3 &lTranslationOut,
        cTkQuaternion &lRotationOut);
    static char *GetMsg(int *lpiLevel, float *lpfTime);
    static void GetNodeAABB(TkHandle lNode, cTkAABB &lBoundingBox);
    static void GetNodeAbsoluteTransMatrix(TkHandle node, cTkMatrix34 *absMat);
    static bool GetNodeActivation(TkHandle node);
    static const cTkResourceDescriptor *GetNodeAltId(TkHandle node);
    static TkHandle &GetNodeFirstChild(TkHandle node);
    static bool GetIsNodeValid(TkHandle lNode);
    static void GetNodeLocalAABB(TkHandle lNode, cTkAABB &lBoundingBox);
    static uint64_t GetNodeNameHash(TkHandle node);
    static uint32_t GetNodeNetworkId(TkHandle node);
    static TkHandle &GetNodeNextSibling(TkHandle node);
    static int GetNodeNumChildren(TkHandle parent);
    static int GetNodeNumDescendants(TkHandle parent);
    static float GetNodeParamF(TkHandle node, int param, int compIdx);
    static int GetNodeParamI(TkHandle node, int param);
    static TkHandle &GetNodeParent(TkHandle node);
    static void GetNodeTransMats(TkHandle node, VecIntrinsics::V128Matrix *relMat, VecIntrinsics::V128Matrix *absMat);
    static void GetNodeTransMats(TkHandle node, cTkMatrix34 *relMat, cTkMatrix34 *absMat);
    static void GetNodeTransPositions(TkHandle node, cTkVector3 *relPos, cTkVector3 *absPos);
    static int GetNodeType(TkHandle node);
    static cTkFixedString<256, char> *GetRenderBufferObject(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> targetRes);
    static cTkTexture *GetRenderBufferTexture(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> targetRes, int liIndex);
    static cTkTexture *GetRenderBufferTexture(uint32_t liRenderBufferObject);
    static void GetResElemCount(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res, int elem);
    static cTkFixedString<256, char> *GetResName(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle);
    static float GetResParamF(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res, int elem, int elemIdx, int param, int compIdx);
    static int GetResParamI(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res, int elem, int elemIdx, int param);
    static cTkFixedString<256, char> *GetResParamStr(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res, int elem, int elemIdx, int param);
    static int GetResType(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle);
    static cTkAttachmentData *GetResourceData(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResource, int liIndex);
    static int GetResourceDataCount(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResource);
    static cTkResourceDescriptor &GetResourceDescriptor(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res);
    static const cTkResourceDescriptor *GetResourceDescriptorFromNode(TkHandle lNode);
    static TkStrongType<int, TkStrongTypeIDs::TkResHandleID> &GetResourceHandleForNode(TkHandle lNode);
    static cTkAABB &GetSceneGraphResAABB(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lSceneRes, bool lbIgnoreParticles);
    static cTkFixedString<256, char> *GetTexture(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> targetRes);
    static uint32_t GetThreadID(eThreadType leType);
    cTkWindEigenvectors *GetWindEigenvectorSet(TkHandle node);
    static bool InFrustum(TkHandle lCameraNode, const cTkVector3 &lMin, const cTkVector3 &lMax);
    static bool Initialise();
    static bool IsMeshStreamedIn(TkHandle lMeshNode);
    static bool IsNodeAndParentsActive(TkHandle lNode);
    static bool IsResLoaded(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res);
    static bool IsResLoadedIncludingSubResources(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res);
    static bool IsResLoadedIncludingSubResourcesAndGeometry(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res);
    static bool IsSubscribedToOnPostAnimCallback(TkHandle modelNode, cOnPostAnimCallback *animationCallback);
    static bool IsSubscribedToPreAdditiveCallback(TkHandle modelNode, cPreAdditiveCallback *animationCallback);
    static bool IsTextureCommitted(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture);
    static bool IsTextureResident(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture, int liMinMip);
    static bool IterateNode(
        TkHandle lStartNode, const char *lpacName, int liType, std::function<bool(TkHandle)> lFunctor);
    static bool IterateNode(
        TkHandle lStartNode, uint64_t luNameHash, int liType, std::function<bool(TkHandle)> lFunctor);
    static void IterateNodesForNetworkId(uint32_t luNetworkId, std::function<void(TkHandle)> lFunctor);
    static void MakeTextureEvictable(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture, int liStartAtMip, int);
    static bool MapResStream(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res, int elem, int elemIdx, int stream, bool read,
        bool write);
    static bool MapResStreamToNode(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res, int elem, int idx, TkHandle node);
    static void MarkNodeNeedsUpdate(TkHandle lNode);
    static bool MaterialHasSMShader(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lMaterial);
    static void NotifyTextureResidentToMip(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture, int liMip, bool);
    static void PatchRenderTargetMatrices(TkHandle *cameraNode);
    static bool PollToCompilePreloadedShaders(Engine::cEgShaderCompilationState *lpState);
    static bool PollToCompileShaderTaskList(
        cTkStackVector<cEgShaderResource::CombinationCompilationTask, 64> &lTasks,
        TkIterationState<1> &lIterationState);
    static bool PollToCompileUncompiledShaders(Engine::cEgShaderCompilationState *lpState);
    static TkPollResult PollToReleaseUnusedResources(float lfTimeoutMS, bool lbIncludeLazyDeletions);
    static bool RecalculateRenderID(TkHandle lNode);
    static void RecalculateRenderIDChildren(cEgRenderableSceneNode *lpSceneNode);
    void RefreshAllPipelines();
    static void RefreshAllTexturesAniso(float lfNewAniso);
    static void RefreshAllTexturesLodBias(float lfNewLodBias);
    void Release();
    static bool ReleaseUnusedResources(bool lbIncludeLazyDeletions);
    static bool RendererReady();
    static void RequestRemoveNode(TkHandle node);
    static void RequestStream(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> resource);
    static void RequestStream(cTkResource *lpGeometryResource, const cTkResourceDescriptor *lpSceneDescriptor);
    static void RequestStreamNode(cEgSceneNodeTemplate *lpNode, cTkResourceDescriptor *lpDesc);
    static cTkTexture *RequestTextureCommit(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture, int liTexBias, int);
    static bool RequestTextureResident(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture, int liPixelCount, int liStartAtMip);
    static void ResetModelAnimJoints(TkHandle lModelNode);
    static cTkResource *ResolveRes(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResHandle);
    static bool SetAnimJointsLOD(TkHandle lModelNode, int liLod, cTkFixedString<64, char> *lModelNames, int liNumNodes);
    static bool SetAnimLOD(TkHandle lModelNode, int liAnimLOD);
    static void SetBlurParams(TkHandle cameraNode, float lfKLowFreqm, float lfKHighFreq);
    static void SetCameraCustomScissor(TkHandle lCameraNode, cTkVector4 *lpScissor);
    static void SetCameraCustomViewport(TkHandle lCameraNode, cTkVector4 *lpViewport);
    static void SetCameraJumped(TkHandle lCameraNode);
    static void SetCameraVelFromPrevMatrix(
        TkHandle lCameraNode, const cTkPhysRelMat34 &lPrevMatrix, const cTkPhysRelMat34 &lCurMatrix, float lfTimestep,
        float lfShutterTimestep, float lfShutterDegrees, float lfJitterMagnitude, float lfPrevFoV,
        const cTkVector2 &lViewportSize);
    static void SetFurAllowed(bool lbEnable);
    static void SetGameCameraNode(TkHandle lCameraNode);
    static void SetLODsUpdateEnabled(TkHandle modelNode, bool lbEnabled);
    static bool SetMaterialSampler(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes, const char *name,
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> texRes);
    static bool SetMaterialUniform(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes, const char *name, float a, float b, float c,
        float d);
    static bool SetMaterialUniform(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes, uint64_t lNameHash, float a, float b, float c,
        float d);
    static bool SetMaterialUniformArray(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes, const char *name, const float *lpafData,
        int liNumElements);
    static bool SetMaterialUniformArray(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> materialRes, uint64_t lNameHash, const float *lpafData,
        int liNumElements);
    static void SetModelAnimCulledNextUpdate(TkHandle modelNode);
    static void SetModelAnimJointPoseMatrix(TkHandle modelNode, int jointInd, const cTkMatrix34 &worldMat);
    static void SetModelAnimPoseOffset(TkHandle modelNode, const cTkVector3 &offset);
    static void SetNodeActivation(TkHandle lNode, bool lbActive);
    static void SetNodeActivationRecursive(TkHandle lNode, bool lbActive);
    static void SetNodeCastsShadow(TkHandle lNode, bool lbCastShadow);
    static void SetNodeLocalAABB(TkHandle lNode, const cTkAABB &lBoundingBox);
    static void SetNodeName(TkHandle node, const char *name);
    static void SetNodeNetworkId(TkHandle node, uint32_t luNetworkId);
    static void SetNodeParamF(TkHandle node, int param, int compIdx, float value);
    static void SetNodeParamI(TkHandle node, int param, int value);
    static void SetNodeParent(TkHandle node, TkHandle parent);
    static void SetNodeTransMat(TkHandle node, const cTkMatrix34 &lMat);
    static void SetNodeActivation(TkHandle *lpaNodes, bool *lpabActive, int liNumNodes);
    static bool SetOption(EgOptions::List leParam, float lfValue);
    static void SetRenderQueueCameras(
        EgRenderQueueHandle lQueue, const cTkMatrix44 &lProjectionMatrix, const cTkMatrix44 &lViewMatrixWithOffset,
        const cTkMatrix44 &lPrevProjectionMatrix, const cTkMatrix44 &lPrevViewMatrixWithOffset);
    static void SetRenderQueueStereoCameras(
        EgRenderQueueHandle lQueue, const int liEye, const cTkMatrix44 &lProjectionMatrix,
        const cTkMatrix44 &lViewMatrixWithOffset, const cTkMatrix44 &lPrevProjectionMatrix,
        const cTkMatrix44 &lPrevViewMatrixWithOffset);
    static void SetRenderSpaceOffset(const cTkVector3 &lvOffset);
    static bool SetRenderTarget(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> targetRes, cTkRenderStateCache *lpRenderStateCache,
        int liCubeFace, int liMipLevel);
    static void SetResParamI(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res, int elem, int elemIdx, int param, int value);
    static void SetResParamStr(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res, int elem, int elemIdx, int param, const char *value);
    static void SetSamplerDefaultTexture(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> shaderRes,
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTextureHandle, const char *sampleName, bool);
    static void SetShaderPreambles(
        const char *vertPreamble, const char *hullPreamble, const char *domnPreamble, const char *geomPreamble,
        const char *fragPreamble, const char *compPreamble);
    static void SetTextureStreamFunctions(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture, cTkTextureStreamFuncs *lpFuncs, void *lpContext);
    static cTkTexture *SetTextureVirtualBlocksMapped(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexture, int liBlockIndexes, int *laBlocks, int liNumBlocks,
        bool lbMapped);
    static void SetThreadID(eThreadType leType, uint32_t luThreadID);
    static bool SetUniformArrayDefault(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> shaderRes, const char *name, const float *lpafData,
        int liNumVectors);
    static bool SetUniformArrayDefaultMultipleShaders(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> *laShaderRes, int liNumShaders, const char *name,
        const float *lpafData, int liNumVectors);
    static bool SetUniformArrayDefaultMultipleShaders(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> *laShaderRes, int liNumShaders, uint64_t lNameHash,
        const float *lpafData, int liNumVectors);
    static bool SetUniformDefault(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> shaderRes, const char *name, float a, float b, float c,
        float d);
    static cTkWindEigenvectors *SetWindEigenvectorSet(TkHandle node, cTkWindEigenvectors *lEigens);
    static void SetupCameraView(
        TkHandle cameraNode, float fov, float aspect, float nearDist, float farDist, bool lbOrthographic, bool lbHMD);
    static void SetupCameraViewOrthographic(
        TkHandle cameraNode, float lfFrustumNear, float lfFrustumFar, float lfFrustumLeft, float lfFrustumRight,
        float lfFrustumTop, float lfFrustumBottom);
    static void SetupViewport(int liX, int liY, int liWidth, int liHeight, bool lbResizeBuffers);
    static void ShiftAllTransformsForNode(TkHandle lNode, const cTkVector3 &lShift);
    static void SubscribeToOnPostAnimCallback(TkHandle modelNode, cOnPostAnimCallback *animationCallback, int priority);
    static void SubscribeToPreAdditiveCallback(
        TkHandle modelNode, cPreAdditiveCallback *animationCallback, int priority);
    static void SwitchToEditedGeometry(TkHandle modelNode);
    static void SyncGeometryStreaming(float lfTimeout);
    static void TempGetNewRenderContext(cTkRenderStateCache **lppCacheOut, bool lbMultiThreadedOnVulkan);
    static void UnloadResource(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res);
    static void UnmapResStream(TkStrongType<int, TkStrongTypeIDs::TkResHandleID> res, int liStream);
    static void UnsubscribeFromOnPostAnimCallback(TkHandle modelNode, cOnPostAnimCallback *animationCallback);
    static void UnsubscribeFromPreAdditiveCallback(TkHandle modelNode, cPreAdditiveCallback *animationCallback);
    static bool UpdateLodding(TkHandle lModelNode);
    static void UpdateModelGeometry(TkHandle lModelNode);
    static void UpdateModelLODsImmediate(TkHandle lModelNode, const cTkVector3 &lCameraPosition);
    static void UpdateVertexBufferData(TkHandle lMeshNode, uint32_t, uint32_t, uint32_t, void *lpData);

    template <bool unk1>
    static void GetNodeRelativeTransMatrix(TkHandle node, cTkMatrix34 *relMat)
    {
        // TODO: impl me!
    }

    template <bool unk1>
    static void ComputerNodeTransMatInOffsetSpace()
    {
        // TODO: impl me!
    }

    template <bool unk1>
    static const TryStoreMode *GetModelName(TkHandle node)
    {
        // TODO: impl me!
    }

    template <bool unk1>
    static cTkVector3 &GetRenderSpaceOffset()
    {
        // TODO: impl me!
    }

    class cEgShaderCompilationState
    {
      public:
        cTkStackVector<cEgShaderResource::CombinationCompilationTask, 64> mTasks;
        cTkStackVector<cEgShaderResource::CombinationCompilationTask, 64> mPreloadTasks;
        TkIterationState<1> mContextIteration;
        TkIterationState<1> mTaskIteration;
        TkIterationState<1> mPreloadTaskIteration;
    };
};

SKYSCRAPER_END