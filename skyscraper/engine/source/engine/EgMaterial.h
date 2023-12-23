/**
 * @file EgMaterial.h
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

#include <engine/source/engine/EgResource.h>
#include <engine/source/engine/EgShader.h>

#include <toolkit/scene/materials/tkmaterialuniform.meta.h>

SKYSCRAPER_BEGIN

class cEgMaterialSampler
{
  public:
    std::string msName;
    uint64_t mNameHash;
    std::string msTextureName;
    cTkTypedSmartResHandle<cEgTextureResource> mpTextureResource;
    unsigned int miFlags;
};

/**
 * @brief Class based on Horde3D::MaterialResource. See
 * https://github.com/horde3d/Horde3D/blob/master/Horde3D/Source/Horde3DEngine/egMaterial.h
 */
class cEgMaterialResource : public cEgResource
{
  public:
    cTkSmartResHandle mFurMaterialHandle;
    std::atomic<bool> mbBuffersInitialised;
    int32_t mShaderFlags;
    uint64_t muCombMask;
    cTkTypedSmartResHandle<cEgShaderResource> mpShaderResource;
    cTkLinearHashTable<uint64_t, int32_t, cTkHashTableHashPassthrough> mUniformHashLookup;
    cTkLinearHashTable<uint64_t, int32_t, cTkHashTableHashPassthrough> mSamplerLookup;
    cTkVector<cTkMaterialUniform> mUniforms;
    cTkVector<cEgMaterialSampler> mSamplers;
    uint64_t mHashedNames;
    cTkFixedString<32, char> msMaterialClass;
    uint64_t mTextureSortHash;
    uint64_t mStaticMaterialHash;
    uint64_t mStaticMaterialHashShadow;
    uint32_t mbMaterialHasShaderFlagAlphaCutout : 1;
    uint32_t mbDynamicHashNeedsUpdate : 1;
    uint32_t mbDynamicHashNeedsUpdateShadow : 1;
    uint32_t mbTextureSortHashNeedsUpdate : 1;
    uint32_t mbCastShadow : 1;
    uint32_t mbDisableZTest : 1;
    uint32_t mbLODBiasFlag : 1;
    uint32_t mbReservedFlag : 1;
    uint32_t mbCreateFur : 1;
    uint32_t miShaderContextsLoaded : 23;
    int32_t miTransparencyLayerID;

    ~cEgMaterialResource();
    bool OnResourceLoaded();
    cTkResource *Clone();
    void CloneInternal(const cTkResource *);
    void Release();
    void InitDefault();
    bool Load(const char *, int);
    int GetElementCount(int);
    int GetElementParamInt(int, int, int);
    void SetElementParamInt(int, int, int, int);
    float GetElementParamFloat(int, int, int, int);
    void SetElementParamFloat(int, int, int, int, float);
    const char *GetElementParamStr(int, int, int);
    void SetElementParamStr(int, int, int, const char *);
};

SKYSCRAPER_END