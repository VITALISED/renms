/**
 * @file TkVoxelVertexDefinition.h
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

SKYSCRAPER_BEGIN

class cTkVoxel
{
    uint16_t mPack_Edit1_Mat4_Secmat4_Tex6;
    uint16_t mPack_Density16;
    uint16_t mPack_TileBlend16;
};

class cTkVoxelArray
{
    cTkVoxel *mpaVoxels;
    int32_t miSizeX;
    int32_t miSizeY;
    int32_t miSizeZ;
    int32_t miSizeZY;
    uint32_t muVoxelMaterialMask;
};

SKYSCRAPER_END