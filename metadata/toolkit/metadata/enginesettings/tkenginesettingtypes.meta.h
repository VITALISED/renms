#pragma once
#include <metadata/metadata_common.h>
enum eEngineSetting
{
    EEngineSetting_FullScreen = 0,
    EEngineSetting_Borderless = 1,
    EEngineSetting_ResolutionWidth = 2,
    EEngineSetting_ResolutionHeight = 3,
    EEngineSetting_ResolutionScale = 4,
    EEngineSetting_Monitor = 5,
    EEngineSetting_FoVOnFoot = 6,
    EEngineSetting_FoVInShip = 7,
    EEngineSetting_VSync = 8,
    EEngineSetting_TextureQuality = 9,
    EEngineSetting_AnimationQuality = 10,
    EEngineSetting_ShadowQuality = 11,
    EEngineSetting_ReflectionsMultiplier = 12,
    EEngineSetting_ReflectionProbesMultiplier = 13,
    EEngineSetting_ReflectionProbes = 14,
    EEngineSetting_ScreenSpaceReflections = 15,
    EEngineSetting_ReflectionsQuality = 16,
    EEngineSetting_PostProcessingEffects = 17,
    EEngineSetting_VolumetricsQuality = 18,
    EEngineSetting_TerrainTessellation = 19,
    EEngineSetting_PlanetQuality = 20,
    EEngineSetting_BaseQuality = 21,
    EEngineSetting_UIQuality = 22,
    EEngineSetting_DLSSQuality = 23,
    EEngineSetting_FFXSRQuality = 24,
    EEngineSetting_FFXSR2Quality = 25,
    EEngineSetting_XESSQuality = 26,
    EEngineSetting_DynamicResScaling = 27,
    EEngineSetting_EnableTessellation = 28,
    EEngineSetting_AntiAliasing = 29,
    EEngineSetting_AnisotropyLevel = 30,
    EEngineSetting_Brightness = 31,
    EEngineSetting_VignetteAndScanlines = 32,
    EEngineSetting_AvailableMonitors = 33,
    EEngineSetting_MaxFrameRate = 34,
    EEngineSetting_NumLowThreads = 35,
    EEngineSetting_NumHighThreads = 36,
    EEngineSetting_NumGraphicsThreads = 37,
    EEngineSetting_TextureStreaming = 38,
    EEngineSetting_TexturePageSizeKb = 39,
    EEngineSetting_MotionBlurStrength = 40,
    EEngineSetting_ShowRequirementsWarnings = 41,
    EEngineSetting_AmbientOcclusion = 42,
    EEngineSetting_MaxTextureMemoryMb = 43,
    EEngineSetting_FixedTextureMemory = 44,
    EEngineSetting_UseArbSparseTexture = 45,
    EEngineSetting_UseTerrainTextureCache = 46,
    EEngineSetting_AdapterIndex = 47,
    EEngineSetting_UseHDR = 48,
    EEngineSetting_MinGPUMode = 49,
}

class cTkEngineSettingTypes
{
    static unsigned long long muNameHash = 0x943946549DEC2216;
    static unsigned long long muTemplateHash = 0x644B852D83365033;

    eEngineSetting EngineSetting;
}
