#pragma once

#include <skyscraper.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>

SKYSCRAPER_BEGIN

class cTkMatrix34
{
	cTkVector3 mRight, mUp, mAt, mPos;
};

SKYSCRAPER_END