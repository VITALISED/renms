/**
 * @file TkLDSWind.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 * 
 * Copyright (C) 2023  VITALISED & Contributors
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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