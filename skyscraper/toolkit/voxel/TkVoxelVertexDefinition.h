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