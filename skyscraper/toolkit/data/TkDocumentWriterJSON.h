/**
 * @file TkDocumentWriterJSON.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <toolkit/core/types/TkID.h>
#include <toolkit/data/TkDocumentWriter.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/string/TkStringAssembler.h>
#include <toolkit/voxel/TkHalfVectors.h>

SKYSCRAPER_BEGIN

class cTkDocumentWriterJSON : public ITkDocumentWriter
{
  public:
    cTkStringAssembler *mAssembler;
    int miTabLevel;
    bool mbKeyBeingBuilt;
    bool mbBraceType[20];
    bool mbPrettyOutput;
    bool mbAutoSanitizeFP;
    bool mbHashKeys;
};

SKYSCRAPER_END