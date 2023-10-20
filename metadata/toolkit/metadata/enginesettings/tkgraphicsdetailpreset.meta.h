#pragma once
#include <metadata/metadata_common.h>
#include <metadata/enginesettings/tkgraphicsdetailtypes.meta.h>
enum eUIQuality
{
    EUIQuality_Normal = 0,
    EUIQuality_4K = 1,
}
enum eAmbientOcclusion
{
    EAmbientOcclusion_Off = 0,
    EAmbientOcclusion_GTAO_Low = 1,
    EAmbientOcclusion_GTAO_Medium = 2,
    EAmbientOcclusion_GTAO_High = 3,
    EAmbientOcclusion_GTAO_Ultra = 4,
    EAmbientOcclusion_HBAO_Low = 5,
    EAmbientOcclusion_HBAO_High = 6,
}
enum eAnisotropyLevel
{
    EAnisotropyLevel_1 = 0,
    EAnisotropyLevel_2 = 1,
    EAnisotropyLevel_4 = 2,
    EAnisotropyLevel_8 = 3,
    EAnisotropyLevel_16 = 4,
}
#include <metadata/enginesettings/tkdynamicresscalingsettings.meta.h>

class cTkGraphicsDetailPreset
{
    static unsigned long long muNameHash = 0x56E0EB96EB3713F0;
    static unsigned long long muTemplateHash = 0xB319768677055F79;

    cTkGraphicsDetailTypes TextureQuality;
    cTkGraphicsDetailTypes AnimationQuality;
    cTkGraphicsDetailTypes ShadowQuality;
    cTkGraphicsDetailTypes PostProcessingEffects;
    cTkGraphicsDetailTypes ReflectionsQuality;
    cTkGraphicsDetailTypes VolumetricsQuality;
    cTkGraphicsDetailTypes TerrainTessellation;
    cTkGraphicsDetailTypes PlanetQuality;
    cTkGraphicsDetailTypes BaseQuality;
    eUIQuality UIQuality;
    eDLSSQuality DLSSQuality;
    eFFXSRQuality FFXSRQuality;
    eFFXSR2Quality FFXSR2Quality;
    eXESSQuality XESSQuality;
    eAmbientOcclusion AmbientOcclusion;
    eAnisotropyLevel AnisotropyLevel;
    eAntiAliasing AntiAliasing;
    cTkDynamicResScalingSettings DynamicResScalingSettings;
}
