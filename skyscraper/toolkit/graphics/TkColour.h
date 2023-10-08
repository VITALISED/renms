#pragma once

#include <skyscraper.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>

SKYSCRAPER_BEGIN

class cTkColour : public cTkVector4
{
public:
	cTkColour() : cTkVector4()
    { };

	cTkColour(float r, float g, float b, float a) : cTkVector4(r, g, b, a)
    { };
};

SKYSCRAPER_END