/**
 * @file TkVector4Generic.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-14
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

#include <toolkit/maths/numeric/generic/TkVector4Generic.h>

SKYSCRAPER_BEGIN

cTkVector4::cTkVector4(){};

cTkVector4::cTkVector4(float lfX, float lfY, float lfZ, float lfW)
{
    this->mVal = _mm_set_ps(lfX, lfY, lfZ, lfW);
}

SKYSCRAPER_END