/**
 * @file TkVector3Generic.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-18
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

#include <toolkit/maths/numeric/generic/TkVector3Generic.h>

SKYSCRAPER_BEGIN

void cTkVector3::SetElement(int liIndex, float lfValue)
{
    __m128 lTemp;

    switch (liIndex)
    {
    // set X
    case 0: this->mVal = _mm_move_ss(this->mVal, _mm_set_ss(lfValue)); break;
    // set Y
    case 1:
        lTemp      = _mm_set_ss(lfValue);
        lTemp      = _mm_shuffle_ps(lTemp, lTemp, 0x55);
        this->mVal = _mm_shuffle_ps(this->mVal, lTemp, 0x92);
        break;
    // set Z
    case 2:
        lTemp      = _mm_set_ss(lfValue);
        lTemp      = _mm_shuffle_ps(lTemp, lTemp, 0xAA);
        this->mVal = _mm_shuffle_ps(this->mVal, lTemp, 0x93);
        break;
    default: break;
    }
}

SKYSCRAPER_END