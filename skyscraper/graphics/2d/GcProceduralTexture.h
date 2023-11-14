#pragma once

#include <skyscraper.h>

#include <atlas/WinHttpTask.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/resources/TkResourceDescriptor.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/system/thread/TkRegionThreadManager.h>
#include <toolkit/system/thread/TkSpinMutex.h>
#include <toolkit/utilities/TkStrongType.h>
#include <toolkit/utilities/containers/TkStackVector.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/solarsystem/planet/gcplanetcolourdata.meta.h>
#include <toolkit/tkproceduraltexturechosenoptionlist.meta.h>
#include <toolkit/tkproceduraltexturelist.meta.h>

SKYSCRAPER_BEGIN

class cGcProceduralMaterialSampler
{
    cTkFixedString<256, char> msTextureName;
    cTkProceduralTextureList *mpTextureDescriptor;
    bool mbRequiresAsyncLoad;
    bool mbAsyncLoaded;
    bool mbReleased;
    unsigned __int8 mxFlags;
};

class cGcProceduralMaterialMapping
{
    cTkSmartResHandle mMaterial;
    cGcProceduralMaterialSampler maSamplers[2];
};

class cGcProceduralTextureDescriptor
{
    cTkSpinMutex mMutex;
    bool mbAsyncLoaded;
    bool mbRequiresAsyncLoad;
    int miNumThings;
    cTkProceduralTextureChosenOptionList *mpOptions;
    cTkVector<cGcProceduralMaterialMapping> mMapping;
    TkID<256> mNameHint;
    bool mbTest;
};

class cGcProceduralTextureManager
{
    class cGcProceduralSamplerData
    {
        cTkStackVector<cTkSmartResHandle, 16> mOwnedTextures;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mDiffuseCompressedTexture;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mNormalCompressedTexture;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mMaskCompressedTexture;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mParallaxCompressedTexture;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mFeatureCompressedTexture;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maDiffuseTextures[8];
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maNormalTextures[8];
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maMaskTextures[8];
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maParallaxTextures[8];
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maFeatureTextures[8];
        cTkColour maColours[8];
        cTkColour maAverageColours[8];
        unsigned __int8 miNumDiffuseTextures;
        unsigned __int8 miNumColouredDiffuseTextures;
        unsigned __int8 miNumNormalTextures;
        unsigned __int8 miNumMaskTextures;
        unsigned __int8 miNumParallaxTextures : 4;
        unsigned __int8 miNumFeatureTextures : 4;
        unsigned __int8 mbValidAlpha : 1;
        unsigned __int8 mbDiffuseAlreadyRendered : 1;
        unsigned __int8 mbMaskAlreadyRendered : 1;
        unsigned __int8 mbNormalAlreadyRendered : 1;
        unsigned __int8 mbParallaxAlreadyRendered : 1;
        unsigned __int8 mbFeatureAlreadyRendered : 1;
        unsigned __int8 mbUseTerrainStyleRecolour : 1;
        unsigned __int8 mbDiffuseRequested : 1;
        unsigned __int8 mbMaskRequested : 1;
        unsigned __int8 mbNormalRequested : 1;
        unsigned __int8 mbParallaxRequested : 1;
        unsigned __int8 mbFeatureRequested : 1;
        unsigned __int8 miDiffuseMipRequested : 4;
        unsigned __int8 miMaskMipRequested : 4;
        unsigned __int8 miNormalMipRequested : 4;
        unsigned __int8 miParallaxMipRequested : 4;
        unsigned __int8 miFeatureMipRequested : 4;
    };

    struct DeferredAverageColourTask
    {
        cTkProceduralTextureChosenOption *mpChosenOption;
        cGcProceduralTextureManager::cGcProceduralSamplerData *mpSamplerData;
        cTkSmartResHandle mTextureResHandle;
        int miIndex;
    };

    class cGcProceduralTextureData
    {
        cGcProceduralTextureManager::cGcProceduralSamplerData maSamplers[2];
        cTkSmartResHandle mMaterial;
        cTkSmartResHandle mModel;
        int miRefCount;
        bool mbRequestTexturesAlwaysResident;
        bool mbAbort;
    };

    struct DeferredTextureSetupSampler
    {
        cTkFixedString<256, char> mOutputDiffusePath;
        cTkFixedString<256, char> mOutputNormalPath;
        cTkFixedString<256, char> mOutputMasksPath;
        cTkFixedString<256, char> mOutputParallaxPath;
        cTkFixedString<256, char> mOutputFeaturePath;
    };

    struct DeferredTextureSetupTask
    {
        cTkSmartResHandle mMaterial;
        cGcProceduralTextureDescriptor *mTextureDescriptor;
        cTkResourceDescriptor mResourceDescriptor;
        cGcProceduralTextureManager::cGcProceduralTextureData *mpTextureData;
        cGcProceduralTextureManager::DeferredTextureSetupSampler maSamplers[2];
    };

    struct TaskContext
    {
        typedef WinHttpTask::State::Enum Phase;

        cTkSmartResHandle *mpResultResHandle;
        cTkSmartResHandle *mpResultResHandle2;
        cTkSmartResHandle mResultOwnerResHandle;
        cTkVector<cTkSmartResHandle> mLODResources;
        cTkFixedString<256, char> mModelPath;
        cTkResourceDescriptor mResourceDescriptor;
        cTkProceduralTextureChosenOptionList *mpOptions;
        cTkVector<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>> mGatheredMaterials;
        bool mbGatheredMaterials;
        cGcPlanetColourData *mpColourData;
        cTkColour mForceColour;
        bool mbOverrideColour;
        cTkSeed mOverrideGenerationSeed;
        TkID<256> mNameHint;
        bool mbGenerateFromOptions;
        bool mbCopyOptions;
        bool mbUseLegacyColours;
        bool mbForceReload;
        cTkSmartResHandle mTempResHandle;
        cTkSmartResHandle mModelResHandle;
        cGcProceduralTextureDescriptor mProcTexDescriptor;
        TkID<256> mForceDescriptorId;
        bool mbOwnsChosenOptionListPtr;
        bool mbRequestTexturesAlwaysResident;
        cTkVector<cGcProceduralTextureManager::DeferredAverageColourTask> mDeferredAverageColourTasks;
        cTkVector<cGcProceduralTextureManager::DeferredTextureSetupTask> mDeferredTextureSetupTasks;
        cGcProceduralTextureManager::TaskContext::Phase mPhase;
        cGcProceduralTextureManager::TaskContext *mpLODDependancy;
        cGcProceduralTextureManager::TaskContext *mpDependancyParent;
        bool mbIsEverythingLoaded;
        int miNumAttachmentsToLoadAcrossFrames;
    };

    class cGcProceduralSamplerData
    {
        cTkStackVector<cTkSmartResHandle, 16> mOwnedTextures;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mDiffuseCompressedTexture;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mNormalCompressedTexture;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mMaskCompressedTexture;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mParallaxCompressedTexture;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mFeatureCompressedTexture;
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maDiffuseTextures[8];
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maNormalTextures[8];
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maMaskTextures[8];
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maParallaxTextures[8];
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maFeatureTextures[8];
        cTkColour maColours[8];
        cTkColour maAverageColours[8];
        unsigned __int8 miNumDiffuseTextures;
        unsigned __int8 miNumColouredDiffuseTextures;
        unsigned __int8 miNumNormalTextures;
        unsigned __int8 miNumMaskTextures;
        unsigned __int8 miNumParallaxTextures : 4;
        unsigned __int8 miNumFeatureTextures : 4;
        unsigned __int8 mbValidAlpha : 1;
        unsigned __int8 mbDiffuseAlreadyRendered : 1;
        unsigned __int8 mbMaskAlreadyRendered : 1;
        unsigned __int8 mbNormalAlreadyRendered : 1;
        unsigned __int8 mbParallaxAlreadyRendered : 1;
        unsigned __int8 mbFeatureAlreadyRendered : 1;
        unsigned __int8 mbUseTerrainStyleRecolour : 1;
        unsigned __int8 mbDiffuseRequested : 1;
        unsigned __int8 mbMaskRequested : 1;
        unsigned __int8 mbNormalRequested : 1;
        unsigned __int8 mbParallaxRequested : 1;
        unsigned __int8 mbFeatureRequested : 1;
        unsigned __int8 miDiffuseMipRequested : 4;
        unsigned __int8 miMaskMipRequested : 4;
        unsigned __int8 miNormalMipRequested : 4;
        unsigned __int8 miParallaxMipRequested : 4;
        unsigned __int8 miFeatureMipRequested : 4;
    };

    class cGcProceduralTextureData
    {
        cGcProceduralTextureManager::cGcProceduralSamplerData maSamplers[2];
        cTkSmartResHandle mMaterial;
        cTkSmartResHandle mModel;
        int miRefCount;
        bool mbRequestTexturesAlwaysResident;
        bool mbAbort;
    };

    class cGcProceduralTextureCallback
    {
        TkJobHandle mToken;
        cGcProceduralTextureManager::cGcProceduralTextureData *mpData;
    };

    cTkVector<cGcProceduralTextureManager::cGcProceduralTextureCallback> mCallbacks;
    cTkSmartResHandle mDefaultTexture;
    cTkFixedString<256, char> mDebugCurrentModelString;
};

SKYSCRAPER_END