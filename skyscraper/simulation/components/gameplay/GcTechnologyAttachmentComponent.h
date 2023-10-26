#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <metadata/simulation/components/gameplay/gctechnologyattachmentcomponentdata.meta.h>
#include <metadata/simulation/vehicles/gcvehicletype.meta.h>

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