/**
 * @file TkShader.h
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

#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

struct TkShaderModule
{
    struct VkShaderModule_T *mModule;
    void *pShaderBytecode;
    uint64_t BytecodeLength;
};

struct TkShaderBufferHandle
{
    unsigned __int16 muSize;
    unsigned __int16 muOffset;
    __int8 miFragmentSlot : 8;
    __int8 miVertexSlot : 6;
    __int8 mbIsPerFrame : 1;
    __int8 mbIsCustomPerMaterial : 1;
};

class cTkVertexAttributeMapping
{
    int16_t maAttributeLocs[19];
};

class cTkShaderAsyncLoadData
{
    int32_t mVertexShaderOp;
    int32_t mFragmentShaderOp;
    int32_t mHullShaderOp;
    int32_t mDomainShaderOp;
    int32_t mGeometryShaderOp;
    int32_t mComputeShaderOp;
    int32_t mMeshShaderOp;
    uint64_t mxCombMask;
    bool mbShadingRate;
    bool mbPersistReflectionData;
};

struct TkShaderConstHandle
{
    union {
        struct
        {
            int8_t miVertexSlot;
            int8_t miFragmentSlot;
            int16_t miBuffer;
        };
        uint32_t miValid;
    };

    uint16_t muOffset;
    bool mbIsCustomPerMaterial;
    uint8_t meUniformBufferMask;
};

class cTkShaderBase
{
  public:
    virtual ~cTkShaderBase() = 0;
    virtual void CleanUp()   = 0;
};

class cTkShader : public cTkShaderBase
{
  public:
    struct D3D12_INPUT_ELEMENT_DESC_MINIMAL
    {
        unsigned __int8 Location;
        unsigned __int8 SemanticIndex;
    };

    cTkVertexAttributeMapping mVertexAttributeMap;
    TkShaderModule mpVertexShader;
    TkShaderModule mpFragmentShader;
    TkShaderModule mpHullShader;
    TkShaderModule mpDomainShader;
    TkShaderModule mpGeometryShader;
    TkShaderModule mpComputeShader;
    unsigned int mShaderInputsHash;
    unsigned int mInputElementCount;
    cTkShader::D3D12_INPUT_ELEMENT_DESC_MINIMAL mInputElementDesc[24];
    unsigned __int8 mInputElementLocationMap[24];
    unsigned __int8 mInputElementSemanticIdMap[24];
    unsigned int mUsedSamplerBitfield;
    unsigned int mUsedStorageBitfield;
    unsigned int muPerFrameUniformHash;
    unsigned __int16 muTotalSize;
    unsigned __int16 muTotalSizePerFrame;
    bool mbVertexShaderReadsTextures;
    bool mbNeedsHighLayout;
    bool mbAllocated;
    bool mbFailedToLoad;
    std::array<void *, 5> maShaderBufferPtrMap;
    cTkVector<TkShaderBufferHandle> *mpaShaderBuffers;
    std::shared_ptr<std::string> msDebugName;
    cTkVector<unsigned int> maDebugHashes;

    ~cTkShader();
    void CleanUp();
};

SKYSCRAPER_END