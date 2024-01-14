/**
 * @file TkIntTuples.h
 * @author VITALISED & Contributors
 * @since 2024-01-14
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

SKYSCRAPER_BEGIN

template <typename T, int unk>
class cTkIntTuple2
{
  public:
    T maVals[2];
};

typedef const cTkIntTuple2<unsigned int, 0> *cTkUInt32Vector2Arg;
typedef const cTkIntTuple2<int, 0> *cTkInt32Vector2Arg;

SKYSCRAPER_END