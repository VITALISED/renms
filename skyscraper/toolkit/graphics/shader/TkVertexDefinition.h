/**
 * @file TkVertexDefinition.h
 * @author VITALISED & Contributors
 * @since 2024-01-18
 *
 * Copyright (C) 2024  VITALISED & Contributors
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

#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>

SKYSCRAPER_BEGIN

class cTkSkinnedVertexData
{
  public:
    cTkVector3 mPosition;
    cTkVector3 mNormal;
    cTkVector3 mTangent;
    cTkVector4 mWeights;
    cTkVector4 mJoints;
    cTkVector2 mTexCoords;
};

class cTkVertexBufferSlot
{
  public:
    unsigned int muVertexBufferObject;
    unsigned int muOffset;
    unsigned int muStride;
    int miLayoutElementCount;
    int64_t miHash;
    bool mbIsDirty;
};

SKYSCRAPER_END