#pragma once

#include <skyscraper.h>
#include <toolkit/networking/TkReplicatedVariable.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <metadata/source/simulation/components/scanning/gcscaneffectcomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcScanEffectComponent : cTkComponent
{
	cGcScanEffectComponentData* mpData;
	TkHandle mModelNode;
	cTkReplicatedVariable<int> miCurrentEffectIndex;
	int miPreviousEffectIndex;
};

SKYSCRAPER_END