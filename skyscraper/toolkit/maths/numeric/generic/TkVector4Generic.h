/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>

#include <xmmintrin.h>

SKYSCRAPER_BEGIN

// We think cTkVector4 (and also cTkVector3) are manually optimised SSE objects. We could also be wrong but who knows.
class cTkVector4
{
  public:
    __m128 mVal;

    cTkVector4();
    cTkVector4(float lfX, float lfY, float lfZ, float lfW) { this->mVal = _mm_set_ps(lfX, lfY, lfZ, lfW); }
    float operator[](uint64_t liIndex) { return this->mVal.m128_f32[liIndex]; }
};

SKYSCRAPER_END
