#pragma once

#include <skyscraper.h>

#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

#include <toolkit/components/physics/tkinstancewindcomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cTkWindEigenvalue
{
    float mfEigenValReal;
    float mfEigenValImag;
    float *mfEigenVecReal;
    float *mfEigenVecImag;
    float mfDotX;
    float mfDotY;
    float mfDotZ;
    float mfDotXMassWeighted;
    float mfDotYMassWeighted;
    float mfDotZMassWeighted;
};

class cTkWindEigenvectors
{
    cTkWindEigenvalue *maWindEigens;
    const cTkInstanceWindComponentData *mpWindData;
    int32_t miWindNumUsedEigenvalues;
    int32_t miNumWindEigenvalues;
    int32_t miNumWindJoints;
    cTkVector4 *maPackedSkinVectors;
    uint16_t *maiPackedSkinVectorOrder;
    int32_t miNumPackedJoints;
    cTkMatrix34 *maWindBaseMat;
    int32_t *maWindJointInds;
    int32_t *maParents;
    bool *mbJointShouldUseShearWind;
    float mfWindGenTime;
    float mfWindSolveTime;
    bool mbUseImagComponents;
};

SKYSCRAPER_END