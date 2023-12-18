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

#include <toolkit/maths/numeric/TkTrig.h>
#include <xmmintrin.h>

SKYSCRAPER_BEGIN

// based on https://github.com/pelletier/vector3/blob/master/vector3.h

class _MM_ALIGN16 cTkVector3
{
  public:
    /// Constructors
    inline cTkVector3() : mVal(_mm_setzero_ps()) {}
    inline cTkVector3(float lfX, float lfY, float lfZ) : mVal(_mm_set_ps(0, lfZ, lfY, lfX)) {}
    inline cTkVector3(__m128 m) : mVal(m) {}

    inline cTkVector3 operator+(const cTkVector3 &b) const { return _mm_add_ps(mVal, b.mVal); }
    inline cTkVector3 operator-(const cTkVector3 &b) const { return _mm_sub_ps(mVal, b.mVal); }
    inline cTkVector3 operator*(const cTkVector3 &b) const { return _mm_mul_ps(mVal, b.mVal); }
    inline cTkVector3 operator/(const cTkVector3 &b) const { return _mm_div_ps(mVal, b.mVal); }

    inline cTkVector3 &operator+=(const cTkVector3 &b)
    {
        mVal = _mm_add_ps(mVal, b.mVal);
        return *this;
    }
    inline cTkVector3 &operator-=(const cTkVector3 &b)
    {
        mVal = _mm_sub_ps(mVal, b.mVal);
        return *this;
    }
    inline cTkVector3 &operator*=(const cTkVector3 &b)
    {
        mVal = _mm_mul_ps(mVal, b.mVal);
        return *this;
    }
    inline cTkVector3 &operator/=(const cTkVector3 &b)
    {
        mVal = _mm_div_ps(mVal, b.mVal);
        return *this;
    }

    /// Arithmetic operators with floats
    inline cTkVector3 operator+(float b) const { return _mm_add_ps(mVal, _mm_set1_ps(b)); }
    inline cTkVector3 operator-(float b) const { return _mm_sub_ps(mVal, _mm_set1_ps(b)); }
    inline cTkVector3 operator*(float b) const { return _mm_mul_ps(mVal, _mm_set1_ps(b)); }
    inline cTkVector3 operator/(float b) const { return _mm_div_ps(mVal, _mm_set1_ps(b)); }

    /// Assignation and arithmetic operators with float
    inline cTkVector3 &operator+=(float b)
    {
        mVal = _mm_add_ps(mVal, _mm_set1_ps(b));
        return *this;
    }
    inline cTkVector3 &operator-=(float b)
    {
        mVal = _mm_sub_ps(mVal, _mm_set1_ps(b));
        return *this;
    }
    inline cTkVector3 &operator*=(float b)
    {
        mVal = _mm_mul_ps(mVal, _mm_set1_ps(b));
        return *this;
    }
    inline cTkVector3 &operator/=(float b)
    {
        mVal = _mm_div_ps(mVal, _mm_set1_ps(b));
        return *this;
    }

    /// Equality operators
    inline bool operator==(const cTkVector3 &b) const
    {
        return (((_mm_movemask_ps(_mm_cmpeq_ps(mVal, b.mVal))) & 0xF) == 0xF);
    }
    inline bool operator!=(const cTkVector3 &b) const { return !(*this == b); }

    inline cTkVector3 operator-() const { return _mm_xor_ps(mVal, SIGNMASK); }

    inline const float &operator[](const int i) const { return i == 0 ? this->mfX : (i == 1 ? this->mfY : this->mfZ); }
    inline float &operator[](const int i) { return i == 0 ? this->mfX : (i == 1 ? this->mfY : this->mfZ); }

    inline cTkVector3 Cross(const cTkVector3 &b) const
    {
        return _mm_sub_ps(
            _mm_mul_ps(
                _mm_shuffle_ps(mVal, mVal, _MM_SHUFFLE(3, 0, 2, 1)),
                _mm_shuffle_ps(b.mVal, b.mVal, _MM_SHUFFLE(3, 1, 0, 2))),
            _mm_mul_ps(
                _mm_shuffle_ps(mVal, mVal, _MM_SHUFFLE(3, 1, 0, 2)),
                _mm_shuffle_ps(b.mVal, b.mVal, _MM_SHUFFLE(3, 0, 2, 1))));
    }

    inline float Dot(const cTkVector3 &b) const { return _mm_cvtss_f32(_mm_dp_ps(mVal, b.mVal, 0x71)); }

    inline float Length() const { return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(mVal, mVal, 0x71))); }

    inline cTkVector3 Normalize() const
    {
        // multiplying by rsqrt does not yield an accurate enough result, so we
        // divide by sqrt instead.
        return _mm_div_ps(mVal, _mm_sqrt_ps(_mm_dp_ps(mVal, mVal, 0xFF)));
    }

    inline void *operator new[](size_t x) { return _aligned_malloc(x, 16); }
    inline void operator delete[](void *x)
    {
        if (x) _aligned_free(x);
    }

    // Textual representation
    // friend std::ostream &operator<<(std::ostream &os, const cTkVector3 &t);

    union {
        struct
        {
            float mfX, mfY, mfZ;
        };
        __m128 mVal;
    };

    void SetElement(int liIndex, float lfValue);
    // float NormaliseGetLength();
    // static float AngleBetweenVectors(const cTkVector3 *lVec1, const cTkVector3 *lVec2);
};

SKYSCRAPER_END
