#pragma once

#include <skyscraper.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>

SKYSCRAPER_BEGIN

class cTkPhysRelMat34
{
    cTkVector3 mRight, mUp, mAt;
    cTkPhysRelVec3 mPos;
};

SKYSCRAPER_END