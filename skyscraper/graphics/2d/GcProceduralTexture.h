/**
 * @file GcProceduralTexture.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <toolkit/graphics/TkColour.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/system/thread/TkRegionThreadManager.h>
#include <toolkit/system/thread/TkSpinMutex.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/solarsystem/planet/gcplanetcolourdata.meta.h>
#include <toolkit/tkproceduraltexturechosenoptionlist.meta.h>
#include <toolkit/tkproceduraltexturelist.meta.h>

SKYSCRAPER_BEGIN

class cGcProceduralMaterialSampler
{
  public:
    cTkFixedString<256, char> msTextureName;
    cTkProceduralTextureList *mpTextureDescriptor;
    bool mbRequiresAsyncLoad;
    bool mbAsyncLoaded;
    bool mbReleased;
    uint8_t mxFlags;
};

class cGcProceduralMaterialMapping
{
  public:
    cTkSmartResHandle mMaterial;
    cGcProceduralMaterialSampler maSamplers[2];
};

class cGcProceduralTextureDescriptor
{
  public:
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
  public:
    class cGcProceduralSamplerData
    {
      public:
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
        uint8_t miNumDiffuseTextures;
        uint8_t miNumColouredDiffuseTextures;
        uint8_t miNumNormalTextures;
        uint8_t miNumMaskTextures;
        uint8_t miNumParallaxTextures : 4;
        uint8_t miNumFeatureTextures : 4;
        uint8_t mbValidAlpha : 1;
        uint8_t mbDiffuseAlreadyRendered : 1;
        uint8_t mbMaskAlreadyRendered : 1;
        uint8_t mbNormalAlreadyRendered : 1;
        uint8_t mbParallaxAlreadyRendered : 1;
        uint8_t mbFeatureAlreadyRendered : 1;
        uint8_t mbUseTerrainStyleRecolour : 1;
        uint8_t mbDiffuseRequested : 1;
        uint8_t mbMaskRequested : 1;
        uint8_t mbNormalRequested : 1;
        uint8_t mbParallaxRequested : 1;
        uint8_t mbFeatureRequested : 1;
        uint8_t miDiffuseMipRequested : 4;
        uint8_t miMaskMipRequested : 4;
        uint8_t miNormalMipRequested : 4;
        uint8_t miParallaxMipRequested : 4;
        uint8_t miFeatureMipRequested : 4;
    };

    class cGcProceduralTextureData
    {
      public:
        cGcProceduralTextureManager::cGcProceduralSamplerData maSamplers[2];
        cTkSmartResHandle mMaterial;
        cTkSmartResHandle mModel;
        int miRefCount;
        bool mbRequestTexturesAlwaysResident;
        bool mbAbort;
    };

    class cGcProceduralTextureCallback
    {
      public:
        TkJobHandle mToken;
        cGcProceduralTextureManager::cGcProceduralTextureData *mpData;
    };

    struct DeferredAverageColourTask
    {
        cTkProceduralTextureChosenOption *mpChosenOption;
        cGcProceduralTextureManager::cGcProceduralSamplerData *mpSamplerData;
        cTkSmartResHandle mTextureResHandle;
        int miIndex;
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
        enum Phase
        {
            GenerationColourData,
            GenerationAddResource,
            GenerationAddLods1,
            GenerationAddLods2,
            GenerationGenerateInstance1,
            GenerationGenerateInstance2,
            LoadAddResource,
            LoadTextureDescriptorMapping,
            ApplyTextureOptions,
            FinalTasks,
            Complete,
        };

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

    std::vector<cGcProceduralTextureManager::cGcProceduralTextureCallback> mCallbacks;
    cTkSmartResHandle mDefaultTexture;
    cTkFixedString<256, char> mDebugCurrentModelString;
};

SKYSCRAPER_END