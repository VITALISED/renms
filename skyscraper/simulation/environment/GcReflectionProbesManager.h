/**
 * @file GcReflectionProbesManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <toolkit/core/types/TkHandle.h>
#include <toolkit/resources/TkResource.h>

SKYSCRAPER_BEGIN

class cGcReflectionProbesManager
{
  public:
    uint8_t mePhase[1];
    int maProbeSamplersIndices[8];
    int miProbeIndex;
    int miProbeRenderIndex;
    int miTileIndex;
    TkHandle mParentNode;
    cTkVector<TkHandle> maProbeNodesAll;
    TkHandle maProbeNodes[8];
    cTkSmartResHandle maProbeCubemapRes[8];
    cTkSmartResHandle mProbeCubemapFlat;
    cTkSmartResHandle mProbeCubemapTile;
    cTkSmartResHandle mProbeSceneRes;
    cTkSmartResHandle mProbeMaterialRes;
    cTkSmartResHandle mSSRShaderRes;
    cTkSmartResHandle mSSRMaterialRes;
    cTkSmartResHandle mPostProcessShaderRes;
    cTkSmartResHandle mProbePipelineTileRes;
    cTkSmartResHandle mProbePipelineBlurRes;
    cTkSmartResHandle mProbePipelineCubeRes;
};

SKYSCRAPER_END