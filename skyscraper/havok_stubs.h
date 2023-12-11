/**
 * @file havok_stubs.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <xmmintrin.h>

#include <atomic>
#include <cstdint>
#include <queue>

struct hkVector4f
{
    __m128 m_quad;
};

struct hkQuaternionf
{
    hkVector4f m_vec;
};

struct hknpBodyId
{
    uint64_t m_value;
};

template <typename T>
struct hkRefPtr
{
    T *m_ptr;
};

struct hknpMassDistribution
{
    hkVector4f m_centerOfMassAndVolume;
    hkQuaternionf m_majorAxisSpace;
    hkVector4f m_inertiaTensor;
};

struct hknpConstraintId
{
    uint64_t m_value;
};

struct hkHalf16
{
    __int16 m_value;
};

struct hknpConvexHull
{
    char __pad__[0x30];
};

struct hknpShapeSignals
{
    char __pad__[0x10];
};

class hknpShape
{
  public:
    uint64_t *typeData;
    char m_type;
    char m_dispatchType;
    char m_flags;
    unsigned char m_numShapeKeyBits;
    float m_convexRadius;
    unsigned __int64 m_userData;
    char m_properties[0x10];

    virtual void stub();
};

struct hknpConvexShape : hknpShape
{
    hknpConvexHull m_hull;
    hkHalf16 m_maxAllowedPenetration;
    uintptr_t m_mutationSignals;
};

struct hkBaseObject
{
    virtual void stubby();
};

struct hkReferencedObject : hkBaseObject
{
    unsigned __int64 m_sizeAndFlags;
    std::atomic<unsigned __int64> m_refCount;
};

struct hknpAction : hkReferencedObject
{
    unsigned __int64 m_userData;
};
