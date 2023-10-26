#pragma once

#include <skyscraper.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

SKYSCRAPER_BEGIN

class cTkCamera
{
	cTkPhysRelMat34 mMatrix;
	cTkPhysRelMat34 mPrevMatrix;
	float mfFOV;
	float mfFOVFixedDist;

	virtual void Transform(const cTkMatrix34*);
};

SKYSCRAPER_END