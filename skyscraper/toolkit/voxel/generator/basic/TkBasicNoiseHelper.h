#pragma once

#include <skyscraper.h>
#include <metadata/voxel/generator/tknoisevoxeltypeenum.meta.h>

SKYSCRAPER_BEGIN

class cTkBasicNoiseHelper
{
public:
	struct NoisePositionData
	{
		cTkVector3 mPosition;
		cTkVector3 mNormal;
		eNoiseVoxelType mVoxelType;
	};
};


SKYSCRAPER_END