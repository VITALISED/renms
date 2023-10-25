#pragma once

#include <skyscraper.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <simulation/navigation/GcNavigationConfig.h>
#include <simulation/navigation/GcNavigationQuery.h>
#include <simulation/navigation/GcNavigationWorkingData.h>

SKYSCRAPER_BEGIN

enum eNavSteeringInterest
{
	ENavSteeringInterest_Attraction,
	ENavSteeringInterest_Danger,
	ENavSteeringInterest_Impassable,
	ENavSteeringInterest_NumTypes = 3,
};

enum eNavSteeringInput
{
	ENavSteeringInput_FollowPath,
	ENavSteeringInput_AvoidDifficultTerrain,
	ENavSteeringInput_AvoidObstruction,
	ENavSteeringInput_NumTypes = 3,
};

class cGcNavSteering
{
	int miNumDirections;
	cTkVector3 mavDirectionsLocal[36];
	cTkVector3 mavDirectionsWorld[36];
	float mafRecipTurnRadius[36];
	float maafInterests[3][36];
	float mfDangerThreshold;
	float mfNearTargetDangerThresholdScaler;

	virtual ~cGcNavSteering();
	virtual void Prepare();
	virtual void Release();
	virtual void Init(const cGcNavigationConfig*);
	virtual void PreUpdate(const cGcNavigationQuery*);
	virtual void Update(float, const cGcNavigationQuery*, cGcNavigationWorkingData*);
	virtual void AddAvoidObstacles(cTkStackVector<cGcPathfindingObstacle>);
	virtual void AddInterest(int, eNavSteeringInterest, float, eNavSteeringInput);
	virtual void RenderNGui();
	virtual void DebugRender(const cGcNavigationQuery*);
};

SKYSCRAPER_END