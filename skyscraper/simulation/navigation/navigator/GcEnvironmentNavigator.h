#pragma once

#include <skyscraper.h>
#include <simulation/navigation/GcNavigationConfig.h>
#include <simulation/navigation/GcNavigationQuery.h>
#include <simulation/navigation/GcNavigationWorkingData.h>
#include <simulation/navigation/GcNavSteering.h>

SKYSCRAPER_BEGIN

class cGcEnvironmentNavigator
{
	virtual ~cGcEnvironmentNavigator();
	virtual void Prepare();
	virtual void Release();
	virtual void Init(const cGcNavigationConfig*);
	virtual void Update(float, const cGcNavigationQuery*, cGcNavigationWorkingData*);
	virtual void ApplyToSteering(float, const cGcNavigationQuery*, cGcNavSteering*);
	virtual bool IsPointNavigable(const cGcNavigationConfig*, const cTkPhysRelVec3*);
	virtual bool CanPathToPoint(const cTkPhysRelVec3*);
	virtual bool GetNearestAccessiblePoint(const cGcNavigationConfig*, const cTkPhysRelVec3*, cTkPhysRelVec3*);
	virtual bool IsStuck();
	virtual void RenderNGui();
	virtual void DebugRender(const cGcNavigationQuery*);
};

SKYSCRAPER_END