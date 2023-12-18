/**
 * @file TkVector4Generic.h
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

class cTkVector4
{
  public:
    inline cTkVector4() : mVal(_mm_setzero_ps()) {}
    inline cTkVector4(float lfX, float lfY, float lfZ, float lfW) : mVal(_mm_set_ps(mfW, lfZ, lfY, lfX)) {}
    inline cTkVector4(__m128 m) : mVal(m) {}

    inline cTkVector4 operator+(const cTkVector4 &b) const { return _mm_add_ps(mVal, b.mVal); }
    inline cTkVector4 operator-(const cTkVector4 &b) const { return _mm_sub_ps(mVal, b.mVal); }
    inline cTkVector4 operator*(const cTkVector4 &b) const { return _mm_mul_ps(mVal, b.mVal); }
    inline cTkVector4 operator/(const cTkVector4 &b) const { return _mm_div_ps(mVal, b.mVal); }

    inline cTkVector4 &operator+=(const cTkVector4 &b)
    {
        mVal = _mm_add_ps(mVal, b.mVal);
        return *this;
    }
    inline cTkVector4 &operator-=(const cTkVector4 &b)
    {
        mVal = _mm_sub_ps(mVal, b.mVal);
        return *this;
    }
    inline cTkVector4 &operator*=(const cTkVector4 &b)
    {
        mVal = _mm_mul_ps(mVal, b.mVal);
        return *this;
    }
    inline cTkVector4 &operator/=(const cTkVector4 &b)
    {
        mVal = _mm_div_ps(mVal, b.mVal);
        return *this;
    }

    inline cTkVector4 operator+(float b) const { return _mm_add_ps(mVal, _mm_set1_ps(b)); }
    inline cTkVector4 operator-(float b) const { return _mm_sub_ps(mVal, _mm_set1_ps(b)); }
    inline cTkVector4 operator*(float b) const { return _mm_mul_ps(mVal, _mm_set1_ps(b)); }
    inline cTkVector4 operator/(float b) const { return _mm_div_ps(mVal, _mm_set1_ps(b)); }

    inline cTkVector4 &operator+=(float b)
    {
        mVal = _mm_add_ps(mVal, _mm_set1_ps(b));
        return *this;
    }
    inline cTkVector4 &operator-=(float b)
    {
        mVal = _mm_sub_ps(mVal, _mm_set1_ps(b));
        return *this;
    }
    inline cTkVector4 &operator*=(float b)
    {
        mVal = _mm_mul_ps(mVal, _mm_set1_ps(b));
        return *this;
    }
    inline cTkVector4 &operator/=(float b)
    {
        mVal = _mm_div_ps(mVal, _mm_set1_ps(b));
        return *this;
    }

    inline const float &operator[](int i) const
    {
        switch (i)
        {
        case 0: return mfX;
        case 1: return mfY;
        case 2: return mfZ;
        case 3: return mfW;
        }
    }

    inline float &operator[](int i)
    {
        switch (i)
        {
        case 0: return mfX;
        case 1: return mfY;
        case 2: return mfZ;
        case 3: return mfW;
        }
    }

    inline void *operator new[](size_t x) { return _aligned_malloc(x, 16); }
    inline void operator delete[](void *x)
    {
        if (x) _aligned_free(x);
    }

    union {
        struct
        {
            float mfX, mfY, mfZ, mfW;
        };
        __m128 mVal;
    };
};

SKYSCRAPER_END
