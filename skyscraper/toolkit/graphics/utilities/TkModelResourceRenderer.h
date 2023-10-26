#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/toolkit/tkmodelrendererdata.meta.h>

SKYSCRAPER_BEGIN

enum EModelResourceRendererViewMode
{
    EModelResourceRendererViewMode_RotateX = (1 << 0),
    EModelResourceRendererViewMode_RotateY = (1 << 1),
    EModelResourceRendererViewMode_RotateZ = (1 << 2),
    EModelResourceRendererViewMode_RotateXYZ = (EModelResourceRendererViewMode_RotateX + EModelResourceRendererViewMode_RotateY + EModelResourceRendererViewMode_RotateZ),
};

enum EModelResourceRendererSyncStage
{
    EModelResourceRendererSyncStage_None,
    EModelResourceRendererSyncStage_RequestLoad,
    EModelResourceRendererSyncStage_WaitForHighestMips,
    EModelResourceRendererSyncStage_WaitForGeometryAndMaterials,
    EModelResourceRendererSyncStage_LoadResources,
    EModelResourceRendererSyncStage_RequestRenderToTexture,
    EModelResourceRendererSyncStage_RenderToTexture,
    EModelResourceRendererSyncStage_GetNodeBoundingBox,
    EModelResourceRendererSyncStage_UpdateCamera,
    EModelResourceRendererSyncStage_RenderToTextureDone,
    EModelResourceRendererSyncStage_RenderToTextureFailed,
    EModelResourceRendererSyncStage_RemoveNode,
};

class cTkModelResourceRenderer
{
    int miShowLod;
    void (*mAllowedComponentsCallback)();
    void (*mAttachmentPrepareCallback)(cTkAttachment *);
    cTkSmartResHandle mResHandle;
    cTkSmartResHandle mViewPipelineRes;
    int mViewPipelineNumStages;
    int maClearModesStages[5];
    cTkSmartResHandle mPostProcessMaterial;
    TkHandle mIconGroup;
    TkHandle mNodeToRender;
    bool mbNodeIsExternal;
    bool mbForceChildNodesVisible;
    cTkSmartResHandle mRenderTargetTextureRes;
    cTkSmartResHandle mBackgroundImageTextureRes;
    cTkSmartResHandle mThumbnailBackgroundImageGUITextureRes;
    cTkSmartResHandle mThumbnailBackgroundImageHUDTextureRes;
    float mfModelScale;
    cTkVector3 mvModelOffset;
    cTkSeed mPetBoneScaleSeed;
    float mfPetBabify;
    float mfFurScaler;
    bool mbFurAllowed;
    cTkMatrix34 mModelMatrix;
    cTkMatrix34 mCameraMatrix;
    cTkPhysRelMat34 mRenderMatrix;
    cTkPhysRelMat34 mPrevRenderMatrix;
    float mfLightRotate;
    float mfLightPitch;
    float mfParallaxOffsetX;
    float mfParallaxOffsetY;
    EModelResourceRendererViewMode mViewMode;
    EModelResourceRendererSyncStage meSyncStage;
    cTkModelRendererData *mpData;
    cTkAABB mSpawnCachedLocalAABBMeshCulled;
    cTkAABB mSceneResourceAABB;
    bool mbReflectionsEnabled;
    bool mbHasRendered;
    bool mbRenderOnlyOnce;
    bool mbNodeHasImpostors;
    bool mbDisableLightingOverride;
    float mfTransitionTime;
    cTkVector<cTkFixedString<128,char> > mNodeNameActivationList;
    cTkVector<cTkFixedString<128,char> > mNodeNameDeactivationList;
    cTkVector<int> mNodeTypeDeactivationList;
    cTkFixedString<128,char> mName_dbg;
};

SKYSCRAPER_END