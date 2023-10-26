#pragma once

#include <skyscraper.h>
#include <simulation/components/utils/GcPlayerCharacterComponent.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <metadata/source/simulation/ecosystem/npcs/gcnpcseatedposture.meta.h>

SKYSCRAPER_BEGIN

class cGcCharacterSit
{
	enum State
	{
		Standing,
		SittingDown,
		Seated,
		GettingUp,
		NumStates,
	};

	cGcPlayerCharacterComponent* mpCharacter;
	TkHandle mpChairNode;
	TkHandle mpSitLocationNode;
	cTkPhysRelMat34 mStartLocation;
	cTkPhysRelMat34 mTargetLocation;
	float mfTimeInState;
	float mfInterpolationProgress;
	cGcCharacterSit::State meState;
	bool mbIsGek;
	float mfNextPostureChangeTime;
	eNPCSeatedPosture meCurrentPosture;
	eNPCSeatedPosture meTargetPosture;
};


SKYSCRAPER_END