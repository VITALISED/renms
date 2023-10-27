/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkVoxel
{
	unsigned __int16 mPack_Edit1_Mat4_Secmat4_Tex6;
	unsigned __int16 mPack_Density16;
	unsigned __int16 mPack_TileBlend16;
};

class cTkVoxelArray
{
	cTkVoxel* mpaVoxels;
	int miSizeX;
	int miSizeY;
	int miSizeZ;
	int miSizeZY;
	unsigned int muVoxelMaterialMask;
};

SKYSCRAPER_END