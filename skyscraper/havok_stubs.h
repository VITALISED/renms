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

struct hkVector4f
{
    __m128 m_quad;
};

struct hkQuaternionf
{
    hkVector4f m_vec;
};

struct hknpMassDistribution
{
    hkVector4f m_centerOfMassAndVolume;
    hkQuaternionf m_majorAxisSpace;
    hkVector4f m_inertiaTensor;
};