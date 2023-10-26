#pragma once

#include <skyscraper.h>
#include <simulation/navigation/GcNavigationConfig.h>
#include <simulation/navigation/GcNavigationQuery.h>
#include <simulation/navigation/GcNavigationWorkingData.h>

SKYSCRAPER_BEGIN

class cGcNavObstacleTracker
{
	virtual ~cGcNavObstacleTracker();
	virtual void Prepare();
	virtual void Release();
	virtual void Init(const cGcNavigationConfig*);
	virtual void Update(float, const cGcNavigationQuery*, cGcNavigationWorkingData*);
	virtual void RenderNGui();
	virtual void DebugRender(const cGcNavigationQuery*);
};

SKYSCRAPER_END