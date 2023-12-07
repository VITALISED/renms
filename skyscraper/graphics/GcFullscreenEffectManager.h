/**
 * @file GcFullscreenEffectManager.h
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

#include <graphics/gcscreenfilters.meta.h>
#include <graphics/gcscreenfiltertable.meta.h>

SKYSCRAPER_BEGIN

class cGcFullscreenEffectManager
{
  public:
    cTkSmartResHandle mDebugMaterial;
    cTkSmartResHandle mPostProcessMaterial;
    cTkSmartResHandle mLensFlareMaterial;
    cTkSmartResHandle mDepthOfFieldMaterial;
    cTkSmartResHandle mUIMaterial;
    int mDepthOfFieldNewBokehStage;
    int mDepthOfFieldBokehStage;
    int mDepthOfFieldBlurStage;
    int mCloudsStage;
    int maSSR_Stages[6];
    cTkSmartResHandle maLUTTextureResHandle[82];
    eScreenFilter maeActiveFilters[4];
    float mafFilterStrengths[4];
    float mafFilterDistances[4];
    float mafHdrAdjusts[4];
    cGcScreenFilterTable *mpFilterTable;
};

SKYSCRAPER_END