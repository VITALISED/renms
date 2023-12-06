/**
 * @file TkVector3Generic.h
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

#include <xmmintrin.h>

SKYSCRAPER_BEGIN

// We think cTkVector3 (and also cTkVector4) are manually optimised SSE objects. We could also be wrong but who knows.
class cTkVector3
{
  public:
    __m128 mVal;

    cTkVector3();
    cTkVector3(float lfX, float lfY, float lfZ) { this->mVal = _mm_set_ps(lfX, lfY, lfZ, 0.0f); }
    #ifdef _MSC_VER
    float operator[](uint64_t liIndex) { return this->mVal.m128_f32[liIndex]; }
    #else
    float operator[](uint64_t liIndex) { return this->mVal[liIndex]; }
    #endif
};

SKYSCRAPER_END
