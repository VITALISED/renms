/**
 * @file skyscraper.h
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

#if (_ITERATOR_DEBUG_LEVEL > 0)
#pragma message("You're compiling skyscraper structures in Debug. STL containers will be the wrong size.")
#endif

#include <havok_stubs.h>
// #include <nanoflann.hpp>
#include <common/memory/memory.h>
#include <nanoflann_stubs.h>
#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>
#include <robin_hood.h>
#include <vulkan/vulkan.h>
#include <windows.h> //see toolkit/system/TkCSMutex.h

#include <algorithm>
#include <array>
#include <atomic>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <functional>
#include <limits>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>

namespace nms_rapidjson = rapidjson;

// We need to do this weirdly because of the way CppSharp does namespaces
// clang-format off
#if defined(NO_SKYSCRAPER_NAMESPACE)
#define SKYSCRAPER_BEGIN
#define SKYSCRAPER_END
#else
#define SKYSCRAPER_BEGIN namespace nms {
#define SKYSCRAPER_END };
#endif
// clang-format on

#ifdef _MSC_VER
#define ALIGN(size)       __declspec(align(size))
#define NO_UNIQUE_ADDRESS [[msvc::no_unique_address]]
#else
#define ALIGN(size)       __attribute__((aligned(size)))
#define NO_UNIQUE_ADDRESS [[no_unique_address]]
#endif

#define EMPTY_CALL()            return NULL
#define EMPTY_CALL_VOID()       return
#define EMPTY_CALL_DESTRUCTOR() ;

SKYSCRAPER_BEGIN

static const __m128 SIGNMASK = _mm_castsi128_ps(_mm_set1_epi32(0x80000000));

SKYSCRAPER_END