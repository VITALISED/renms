#pragma once
#include <metadata/metadata_common.h>
enum eVsyncEx
{
    EVsyncEx_Off = 0,
    EVsyncEx_On = 1,
    EVsyncEx_Adaptive = 2,
    EVsyncEx_Triple = 3,
}
#include <?>
enum eTextureStreamingVk
{
    ETextureStreamingVk_Off = 0,
    ETextureStreamingVk_On = 1,
    ETextureStreamingVk_Auto = 2,
    ETextureStreamingVk_NonDynamic = 3,
}

class cTkGraphicsSettings
{
    static unsigned long long muNameHash = 0x8DDF831D46F0A7E;
    static unsigned long long muTemplateHash = 0xC38F1DD5ADA40497;

    int miVersion;
    bool mbFullScreen;
    bool mbBorderless;
    int miMonitor;
    cTkDynamicArray<cTkFixedString<256,char>> maMonitorNames;
    int miResolutionWidth;
    int miResolutionHeight;
    float mfResolutionScale;
    eVsyncEx VsyncEx;
    cTkGraphicsDetailPreset GraphicsDetail;
    float mfMotionBlurStrength;
    bool mbVignetteAndScanlines;
    float mfFoVOnFoot;
    float mfFoVInShip;
    int miBrightness;
    int miMaxframeRate;
    int miNumHighThreads;
    int miNumLowThreads;
    eTextureStreamingVk TextureStreamingVk;
    bool mbShowRequirementsWarnings;
    bool mbRemoveBaseBuildingRestrictions;
    float mfMouseClickSpeedMultiplier;
    bool mbUseTerrainTextureCache;
    bool mbUseArbSparseTexture;
    eHDRMode HDRMode;
    cTkFixedString<256,char> macAdapterName;
    int miAdapterIndex;
    int miNumGraphicsThreadsBeta;
}
