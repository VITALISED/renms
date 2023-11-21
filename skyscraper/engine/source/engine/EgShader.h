#pragma once

#include <skyscraper.h>

#include <engine/source/engine/EgResource.h>
#include <engine/source/engine/EgTerrain.h>
#include <engine/source/engine/EgTexture.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/graphics/shader/TkShader.h>
#include <toolkit/utilities/containers/TkFlatMap.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

SKYSCRAPER_BEGIN

namespace BlendModes
{
typedef cEgTerrain::Actions List;
}

namespace TestModes
{
// note this is probably incorrect, IDA thinks this is a typedef to ItemLookupType from some gamestate struct for some
// reason
enum List
{
    Always,
    IgnoreBroken,
    IgnoreDepleted,
    IgnoreBrokenAndDepleted,
    Upgrades,
    Upgrades_IgnoreBrokenAndDepleted,
};
}; // namespace TestModes

namespace CullModes
{
// note this is probably incorrect, IDA thinks this is a typedef to cGcPlayer::eRocketBootsDoubleTapState for some
// reason
enum List
{
    None,
    WaitingForRelease,
    WaitingForSecondTap,
    SingleTap,
    DoubleTap,
};
}; // namespace CullModes

namespace ShadingRate
{
enum List
{
    NoChange,
    Reduce_1x2,
    Reduce_2x1,
    Reduce_2x2,
    Reduce_2x4,
    Reduce_4x2,
    Reduce_4x4,
};
}; // namespace ShadingRate

namespace FillModes
{
enum List
{
    Solid,
    Wireframe,
};
}; // namespace FillModes

namespace StencilModes
{
enum List
{
    Disabled,
    MaskWrite,
    MaskRead,
    MaskReadInvert,
    MaskWriteInside,
    MaskWriteOnce,
    MaskReadWriteNotEqual,
    MaskReadWriteInvert,
    MaskReadWrite,
};
} // namespace StencilModes

struct cEgCodeResource : public cEgResource
{
  public:
    struct cEgShaderSize
    {
        int32_t miOffset;
        int32_t miLines;
    };
    uint64_t mxFlagMask;
    std::string msCode;
    std::string msCodeAssembledCache;
    cTkVector<std::pair<cTkTypedSmartResHandle<cEgCodeResource>, cEgCodeResource::cEgShaderSize>> mIncludes;
    cTkVector<cEgCodeResource::cEgShaderSize> mEndifs;

    ~cEgCodeResource();
    cTkResource *Clone();
    void CloneInternal(const cTkResource *);
    void Release();
    void InitDefault();
    bool Load(const char *, int);
};

class cEgShaderCombination
{
    uint64_t mxCombMask;
    cTkShader mShaderObject;
    unsigned int muLastUpdateStamp;
    cTkVector<TkShaderBufferHandle> maShaderBuffers;
    std::array<TkShaderConstHandle, 102> maCommonUniforms;
    cTkVector<TkShaderConstHandle> mCustomSamplers;
    cTkVector<TkShaderConstHandle> mCustomUniformsPerMesh;
    cTkVector<short> maiPerMeshIndexLookup;
    cTkVector<signed char> maiSamplerLookup;
    cTkVector<TkShaderConstHandle> mCustomUniformsPerMaterial;
    cTkVector<short> maiPerMaterialIndexLookup;
    cTkShaderAsyncLoadData mAsyncLoadData;
    int8_t mbPersistReflectionData : 1;
    int8_t mbInstanced : 1;
    int8_t mbShadingRate : 1;
    int8_t mbValid : 1;
    int8_t mbLoaded : 1;
};

class cEgShaderContext
{
    TkIDHashed<128> mId;
    uint64_t mxFlagMask;
    BlendModes::List meBlendMode;
    TestModes::List meDepthTest;
    CullModes::List meCullMode;
    ShadingRate::List meShadingRate;
    FillModes::List meFillMode;
    int32_t miUniformBufferIndex;
    int16_t miLoadedCount;
    StencilModes::List meStencilMode;
    uint8_t muStencilMaskRead;
    uint8_t muStencilMaskWrite;
    uint8_t muStencilRef;
    int8_t mbWriteDepth : 1;
    int8_t mbWriteColour : 1;
    int8_t mbAlphaToCoverage : 1;
    int8_t mbPersistReflectionData : 1;
    int8_t mbInstanced : 1;
    int8_t mbShadingRate : 1;
    int8_t mbDepthBounds : 1;
    int8_t mbCompiled : 1;
    cTkFlatMap<uint64_t, uint32_t> mShaderCombinationLookup;
    cTkVector<cEgShaderCombination> mShaderCombinations;
    TkID<128> mShaderMillContext;
    int32_t miVertexCodeIdx;
    int32_t miFragmentCodeIdx;
    int32_t miComputeCodeIdx;
    int32_t miHullCodeIdx;
    int32_t miDomainCodeIdx;
    int32_t miGeometryCodeIdx;
    int64_t miHullFlags;
    int64_t miDomainFlags;
    int64_t miGeometryFlags;
};

class cEgShaderSampler
{
    std::string msId;
    uint64_t mIdHash;
    int8_t miTexUnit;
    uint8_t meAddressMode : 4;
    uint8_t meFilterMode : 4;
    int8_t miMaxAnisotropy;
    bool mbVertexTexture;
    cTkTypedSmartResHandle<cEgTextureResource> mpDefaultTextureResource;
};

class cEgShaderUniform
{
  public:
    std::string msId;
    cTkStackVector<cTkVector4, 1> maDefaultValues;
    uint64_t mHash;
};

enum eSMShaderConnType
{
    eShaderConnType_Invalid,
    eShaderConnType_Vector,
    eShaderConnType_Colour,
    eShaderConnType_Masks,
    eShaderConnType_HSV,
    eShaderConnType_Biome,
    eShaderConnType_NumTypes,
};

class cEgSMShaderContext
{
    struct Conn
    {
        cTkFixedString<64, char> mFriendlyName;
        cTkFixedString<64, char> mProgrammerName;
        int miCount;
        eSMShaderConnType mType;
    };
    TkIDHashed<128> mId;
    cTkStackVector<cEgSMShaderContext::Conn, 4> mFlags;
    cTkStackVector<cEgSMShaderContext::Conn, 4> mInputTextures;
    cTkStackVector<cEgSMShaderContext::Conn, 4> mInputUvs;
    cTkStackVector<cEgSMShaderContext::Conn, 4> mOutputColours;
    cTkStackVector<std::pair<cTkFixedString<64, char>, cTkFixedString<64, char>>, 4> mNeededFlags;
};

class cEgShaderResource : public cEgResource
{
    cTkVector<cEgShaderContext> mContexts;
    cTkLinearHashTable<uint64_t, uint32_t, cTkHashTableHashPassthrough> mContextLookup;
    cTkVector<cEgShaderSampler> mSamplers;
    cTkVector<cEgShaderUniform> mUniforms;
    cTkLinearHashTable<uint64_t, int32_t, cTkHashTableHashPassthrough> mUniformHashLookup;
    cTkVector<cEgCodeResource> mCodeSections;
    cTkVector<cEgSMShaderContext> mShaderMillContexts;
    robin_hood::detail::Table<true, 80, uint64_t, void, robin_hood::hash<uint64_t, void>, std::equal_to<uint64_t>>
        mPreLoadList;

    ~cEgShaderResource();
    void Release();
    bool Load(const char *, int);
    int GetElementCount(int);
    float GetElementParamFloat(int, int, int, int);
    void SetElementParamFloat(int, int, int, int, float);
    const char *GetElementParamStr(int, int, int);
    void SetElementParamStr(int, int, int, const char *);
};

SKYSCRAPER_END