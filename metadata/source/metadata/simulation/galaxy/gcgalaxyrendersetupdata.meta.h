#pragma once
#include <metadata/metadata_common.h>

class cGcGalaxyRenderSetupData
{
    static unsigned long long muNameHash = 0xC3AAF93B598F92B7;
    static unsigned long long muTemplateHash = 0x4935C058DDB98084;

    cTkColour mSunCoreColour;
    float mfSunCoreSmaller;
    float mfSunCoreLarger;
    float mfSunCoreBGContrib;
    float mfSunCoreFGContrib;
    float mfBGCellTraceScale;
    float mfBGCellMoveScale;
    float mfBGCellHorizonInfluence;
    float mfBGColourStage1;
    float mfBGColourStage2;
    float mfBGColourStage3;
    float mfBGColourStage4;
    float mfBGColourCellBlend;
    float mfBGColourPow;
    float mfStarFieldBlendAmount;
    float mfLensFlareBase;
    cTkColour mLensFlareColour;
    cTkVector4 mLensFlareSpread;
    float mfNebulaeAlphaPow;
    float mfNebulaeTraceValueMult;
    float mfNebulaeTraceScale;
    float mfNebulaeTraceDensity;
    float mfNebulaeTraceDensityCutoff;
    cTkVector2 mNebulaeTraceStepRange;
    cTkVector4 mCompositionControlB_S_C_G;
    float mfCompositionSaturationIncreaseError;
    float mfCompositionSaturationIncreaseFilter;
    float mfCompositionSaturationIncreaseSelected;
    float mfVignetteSize;
    float mfVignetteBase;
    float mfVignetteSizeIncreaseError;
    float mfVignetteSizeIncreaseFilter;
    float mfVignetteSizeIncreaseSelected;
    cTkVector2 mLensFlareExpandTowards;
    cTkFixedArray<cTkColour> maMapLargeAreaPrimaryDefaultColours;
    cTkFixedArray<cTkColour> maMapLargeAreaPrimaryHighContrastColours;
    cTkFixedArray<cTkColour> maMapLargeAreaSecondaryDefaultColours;
    cTkFixedArray<cTkColour> maMapLargeAreaSecondaryHighContrastColours;
}
