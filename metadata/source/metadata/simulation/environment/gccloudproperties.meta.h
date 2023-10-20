#pragma once
#include <metadata/metadata_common.h>

class cGcCloudProperties
{
    static unsigned long long muNameHash = 0x21C58A0DDEF4EC87;
    static unsigned long long muTemplateHash = 0xACC78F5C88ED57CC;

    float mfHorizonCoverageStart;
    float mfHorizonCoverageEnd;
    cTkColour mCloudBaseColour;
    cTkColour mCloudTopColour;
    float mfLightScalar;
    float mfAmbientScalar;
    float mfSunRayLength;
    float mfConeRadius;
    float mfDensity;
    float mfAmbientDensity;
    float mfForwardScatteringG;
    float mfBackwardScatteringG;
    float mfDarkOutlineScalar;
    float mfAnimationScale;
    cTkVector2 mWindOffset;
    cTkVector2 mStratosphereWindOffset;
    float mfBaseScale;
    float mfSampleScalar;
    float mfSampleThreshold;
    float mfCloudBottomFade;
    cTkVector4 mCloudHeightGradient1;
    cTkVector4 mCloudHeightGradient2;
    cTkVector4 mCloudHeightGradient3;
    float mfDetailScale;
    float mfErosionEdgeSize;
    float mfCloudDistortion;
    float mfCloudDistortionScale;
    float mfMaxIterations;
    float mfRayMinimumY;
    float mfLODDistance;
    float mfHorizonFadeStartAlpha;
    float mfHorizonFadeScalar;
    float mfHorizonDistance;
}
