/**
 * @file EgPrimatives.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cEgBoundingBox
{
  public:
    cTkVector3 mMin;
    cTkVector3 mMax;
};

class cEgJoint
{
  public:
    cTkMatrix34 mInverseBindMatrix;
};

class cEgMorphDiff
{
  public:
    uint32_t muVertexIndex;
    cTkVector3 mPosDiff;
    cTkVector3 mNormDiff;
    cTkVector3 mTanDiff;
    cTkVector3 mBitanDiff;
};

class cEgMorphTarget
{
  public:
    std::string msName;
    cTkVector<cEgMorphDiff> mDiffs;
};

SKYSCRAPER_END