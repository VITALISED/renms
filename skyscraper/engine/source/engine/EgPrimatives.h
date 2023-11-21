#pragma once

#include <skyscraper.h>

#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cEgBoundingBox
{
    cTkVector3 mMin;
    cTkVector3 mMax;
};

class cEgJoint
{
    cTkMatrix34 mInverseBindMatrix;
};

class cEgMorphDiff
{
    uint32_t muVertexIndex;
    cTkVector3 mPosDiff;
    cTkVector3 mNormDiff;
    cTkVector3 mTanDiff;
    cTkVector3 mBitanDiff;
};

class cEgMorphTarget
{
    std::string msName;
    cTkVector<cEgMorphDiff> mDiffs;
};

SKYSCRAPER_END