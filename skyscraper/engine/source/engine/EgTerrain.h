/**
 * @file EgTerrain.h
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

#define EGTERRAIN_FLAG 10000

SKYSCRAPER_BEGIN

class cEgTerrain
{
  public:
    enum List
    {
        ActionI                       = EGTERRAIN_FLAG + 1,
        ShapeI                        = EGTERRAIN_FLAG + 2,
        NumRegionsI                   = EGTERRAIN_FLAG + 3,
        ModeI                         = EGTERRAIN_FLAG + 4,
        StartPosF                     = EGTERRAIN_FLAG + 5,
        PathVectorAddressI            = EGTERRAIN_FLAG + 6,
        PathStartPosF                 = EGTERRAIN_FLAG + 7,
        PathTargetPosF                = EGTERRAIN_FLAG + 8,
        AddSceneryCallbackAddressI    = EGTERRAIN_FLAG + 9,
        RemoveSceneryCallbackAddressI = EGTERRAIN_FLAG + 10,
        AddCreaturesCallbackAddressI  = EGTERRAIN_FLAG + 11,
        VoxelToGetF                   = EGTERRAIN_FLAG + 12,
        VoxelDensityF                 = EGTERRAIN_FLAG + 13,
        VoxelTileI                    = EGTERRAIN_FLAG + 14,
        ShapePosF                     = EGTERRAIN_FLAG + 15,
        ShapeSizeF                    = EGTERRAIN_FLAG + 16,
    };

    enum Actions
    {
        Add,
        Subtract,
        IncreaseSize,
        DecreaseSize,
        Regenerate,
        CalculatePath,
    };
};

SKYSCRAPER_END