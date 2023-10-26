#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <metadata/source/simulation/components/gameplay/gctechnologyattachmentcomponentdata.meta.h>
#include <metadata/source/simulation/vehicles/gcvehicletype.meta.h>

SKYSCRAPER_BEGIN

class cGcTechnologyAttachmentComponent : public cTkComponent
{
	cGcTechnologyAttachmentComponentData* mpData;
	bool mbActive;
	bool mbForceHidden;
	float mfActiveTime;
	eVehicleType meVehicleType;
};

SKYSCRAPER_END