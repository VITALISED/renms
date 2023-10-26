#pragma once

#include <skyscraper.h>
#include <toolkit/voxel/manager/TkRegion.h>
#include <toolkit/system/thread/TkRegionThreadManager.h>

SKYSCRAPER_BEGIN

class cGcRegionBase : public cTkRegion
{
	class cGcUnmapStreamData
	{
		TkJobHandle mToken;
		TkHandle mNode;
		cTkSmartResHandle mResource;
		int miTileBlendStart;
		bool mbValid;
	};

	std::array<cGcRegionBase::cGcUnmapStreamData, 5> maUnmapStreamData;
};

SKYSCRAPER_END