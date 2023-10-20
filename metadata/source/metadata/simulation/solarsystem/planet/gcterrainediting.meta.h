#pragma once
#include <metadata/metadata_common.h>

class cGcTerrainEditing
{
    static unsigned long long muNameHash = 0x4686D0FAC0A1B9EC;
    static unsigned long long muTemplateHash = 0x8879B10CF4B83AE;

    float mfEditPlaneMaxAdditiveOffsetFactor;
    float mfEditPlaneMinAdditiveOffsetFactor;
    float mfEditPlaneMaxSubtractiveOffsetFactor;
    float mfEditPlaneMinSubtractiveOffsetFactor;
    float mfTerrainEditBeamMaxRange;
    float mfTerrainEditBeamSpherecastRadius;
    float mfTerrainEditBeamAddInterpolationStepFactor;
    float mfTerrainEditBeamSubtractInterpolationStepFactor;
    float mfTerrainBlocksSearchRadiusMultiplier;
    float mfRegionMapSearchRadiusMultiplier;
    float mfMinimumSubstancePresence;
    float mfRegionEditAreaMultiplier;
    float mfDensityBlendDistanceMultiplier;
    float mfTerrainEditBaseDistanceTolerance;
    float mfTerrainUndoBaseDistanceTolerance;
    float mfUndoEditToleranceFactor;
    float mfUndoBaseEditEffectiveScale;
    float mfTerrainEditsNormalCostFactor;
    float mfTerrainEditsSurvivalCostFactor;
    float mfVoxelsDeletedAffectCostFactor;
    bool mbEditGunBeamEnabled;
    bool mbEditGunParticlesEnabled;
    bool mbSubtractGunBeamEnabled;
    bool mbSubtractGunParticlesEnabled;
    cTkFixedArray<float> maEditSizes;
    cTkFixedArray<float> maSubtractSizes;
    cTkFixedArray<float> maBaseEditSizes;
    cTkFixedArray<float> maUndoEditSizes;
    cTkFixedArray<float> maFlatteningSizes;
    float mfEditEffectScale;
}
