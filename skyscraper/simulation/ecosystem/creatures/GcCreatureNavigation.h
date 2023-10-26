#pragma once

#include <skyscraper.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/animation/utils/TkIKSolver.h>
#include <metadata/simulation/ecosystem/creatures/behaviours/data/gcprimaryaxis.meta.h>

SKYSCRAPER_BEGIN

class cGcCreatureCogConstraint : public cTkIKCenterOfGravityConstraint
{
	cGcCreatureNavTrail* mpNavTrail;
	cTkPhysRelMat34 mModelMat;
	ePrimaryAxis meAxis;
};

class cGcCreaturePelvisConstraint : public cTkIKRotYModifyConstraint
{
	cGcCreatureNavTrail* mpNavTrail;
	cTkPhysRelMat34 mModelMat;
	ePrimaryAxis meAxis;
};

class cGcCreatureNavTrail
{
	cTkVector3 mTrailElts[64];
	cTkVector3 mvOffset;
	cTkVector3 mvFrontFootPos;
	int miNumElts;
	int miIntervalCounter;
	float mfScale;
	float mfFade;
	float mfFadeTarget;
};

SKYSCRAPER_END
