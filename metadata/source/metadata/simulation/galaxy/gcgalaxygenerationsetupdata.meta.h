#pragma once
#include <metadata/metadata_common.h>

class cGcGalaxyGenerationSetupData
{
    static unsigned long long muNameHash = 0x74E6E445263E30C1;
    static unsigned long long muTemplateHash = 0xCD69498AB6E7B213;

    float mfSpiralFormChance;
    cTkVector2 mSpiralInclusion;
    cTkVector2 mSpiralFlex;
    float mfSpiralTwistMult;
    cTkVector3 mSpiralPull;
    cTkVector2 mSpiralSizeScale;
    float mfRareSunChance;
    cTkVector2 mConnectionAttractorMax;
    cTkVector2 mConnectionAttractorMin;
    cTkVector2 mConnectionDistortion;
    float mfConnectionDistortionTMult;
    float mfConnectionDistanceLimit;
    cTkVector2 mBaseSize;
    cTkFixedArray<cTkVector2> maStarSize;
    float mfBaseTurbulenceScale;
    float mfBaseTurbulenceLac;
    float mfBaseTurbulenceGain;
    float mfBaseGenerationThreshold;
    float mfFieldGenerationThreshold;
    float mfStarGenerationThreshold;
    cTkVector4 mInnerFieldScales;
    float mfSizeNoiseScale;
    float mfSizeNoisePower;
    float mfSizeField4Inf;
    float mfFieldAlphaBase;
    float mfFieldAlphaField1Inf;
    float mfFieldAlphaField2SqInf;
    float mfStarHighlightChance;
    cTkVector2 mStarHighlightAlpha;
    cTkVector2 mStarHighlightSize;
    float mfColourBaseBlendOnSize;
    cTkFixedArray<cTkColour> maInnerSectorColours;
}
