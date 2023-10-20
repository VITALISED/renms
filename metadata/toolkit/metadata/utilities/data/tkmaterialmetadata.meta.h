#pragma once
#include <metadata/metadata_common.h>
enum eShader
{
    EShader_UberShader = 0,
    EShader_Sky = 1,
    EShader_Screen = 2,
    EShader_UberHack = 3,
    EShader_UIScreen = 4,
    EShader_ShaderMillParticle = 5,
    EShader_ShaderMillUber = 6,
}
#include <?>

class cTkMaterialMetaData
{
    static unsigned long long muNameHash = 0xE39CB7AA4D818260;
    static unsigned long long muTemplateHash = 0xC4E74407D409755F;

    cTkFixedString<128,char> macExternalMaterial;
    eShader Shader;
    bool mbTransparent;
    int miTransparencyLayerID;
    bool mbAdditive;
    bool mbVertexColour;
    bool mbDisableZTest;
    bool mbUnlit;
    bool mbReceiveShadow;
    bool mbCastShadow;
    bool mbShadowOnly;
    bool mbUISurface;
    float mfRoughness;
    bool mbRoughnessMask;
    bool mbMetallic;
    bool mbMetallicMask;
    bool mbSubsurfaceMask;
    cTkFixedString<32,char> macMaterialClass;
    cTkFixedString<128,char> macForceDiffuse;
    cTkFixedString<128,char> macForceNormal;
    cTkFixedString<128,char> macForceMask;
    cTkFixedString<128,char> macForceFeature;
    cTkFixedString<128,char> macDetailDiffuse;
    cTkFixedString<128,char> macDetailNormal;
    float mfDetailTiling;
    float mfMultiplyDetailTiling;
    int miDetailImages;
    int miMultiplyDetailImages;
    bool mbAOMap;
    bool mbMultiplySecondUVSet;
    bool mbVertexDetailBlend;
    float mfDetailHeightBlend;
    float mfNormalTiling;
    bool mbSpaceObject;
    float mfGlow;
    bool mbGlowMask;
    bool mbBrightEdge;
    bool mbCameraRelative;
    bool mbColourisable;
    bool mbColourMask;
    bool mbMultitexture;
    bool mbFeatureMap;
    bool mbAlphaCutout;
    bool mbDetailedAlphaCutout;
    bool mbWind;
    bool mbEnvironmentalOverlay;
    bool mbMatchGroundColour;
    float mfTerrainNormalFactor;
    float mfSoftFadeStrength;
    bool mbScreenSpaceFade;
    bool mbAcuteAngleFadeOut;
    bool mbClampAmbientLight;
    bool mbDoubleSided;
    bool mbDecalDiffuse;
    bool mbDecalTerrainOnly;
    eDecalNormal DecalNormal;
    bool mbBillboard;
    bool mbRotateAroundAt;
    bool mbMergedMeshBillboard;
    float mfBillboardSphereFactor;
    bool mbImposter;
    bool mbScanEffect;
    bool mbWriteLogZ;
    bool mbDisableAmbient;
    bool mbDisablePostProcess;
    bool mbWarpedDiffuseLighting;
    bool mbAnisotropicFilter;
    float mfTessellationHeight;
    bool mbDissolve;
    bool mbInvertAlpha;
    bool mbBeforeUI;
    bool mbDepthMaskUI;
    bool mbAlwaysOnTopUI;
    bool mbScreenSpaceReflections;
    bool mbReflectionProbe;
    bool mbDrawToBloom;
    bool mbDrawToLensFlare;
    bool mbDoubleBufferGeometry;
    bool mbCreateFur;
    float mfShellsHeight;
    float mfFurNoiseScale;
    float mfFurNoiseThickness;
    float mfFurNoiseTurbulence;
    float mfFurTurbulenceScale;
    bool mbHighQualityParticle;
    bool mbUVScrolling;
    float mfUVScrollX;
    float mfUVScrollY;
    float mfUVScrollNormalX;
    float mfUVScrollNormalY;
    float mfUVFrameTime;
    bool mbUVAnimation;
    bool mbUVTileAlts;
    float mfUVNumTilesX;
    float mfUVNumTilesY;
    float mfRefraction;
    float mfRefractionIndex;
    bool mbRefractionMask;
    float mfParticleRefractionStrengthX;
    float mfParticleRefractionStrengthY;
    float mfParticleRefractionBrightnessMultiplier;
    float mfParticleRefractionTint;
    bool mbParallaxMapped;
    float mfParallaxDepth;
    int miNumSteps;
    bool mbSelfShadow;
    float mfShadowFactor;
    bool mbDisplacementWave;
    bool mbDisplacementPositionOffset;
    float mfWaveOneSpeed;
    cTkVector3 mWaveOneAmplitude;
    cTkVector3 mWaveOneFrequency;
    cTkVector3 mWaveOneFallOff;
    float mfWaveTwoSpeed;
    cTkVector3 mWaveTwoAmplitude;
    cTkVector3 mWaveTwoFrequency;
    cTkVector3 mWaveTwoFallOff;
    cTkMaterialShaderMillData ShaderMillData;
}
