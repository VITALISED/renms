#pragma once
#include <metadata/metadata_common.h>
enum eDepthOfFieldSetting
{
    EDepthOfFieldSetting_Off = 0,
    EDepthOfFieldSetting_Mid = 1,
    EDepthOfFieldSetting_On = 2,
    EDepthOfFieldSetting_Macro = 3,
}

class cGcPhotoModeSettings
{
    static unsigned long long muNameHash = 0xE5075EC0403F94CA;
    static unsigned long long muTemplateHash = 0xA6116160B4E36AE2;

    float mfFog;
    float mfCloudAmount;
    cTkVector4 mSunDir;
    float mfFoV;
    eDepthOfFieldSetting DepthOfFieldSetting;
    float mfDepthOfFieldDistance;
    float mfDepthOfFieldDistanceSpace;
    float mfHalfFocalPlaneDepth;
    float mfHalfFocalPlaneDepthSpace;
    float mfDepthOfFieldPhysConvergence;
    float mfDepthOfFieldPhysAperture;
    float mfVignette;
    int miFilter;
    float mfBloom;
}
