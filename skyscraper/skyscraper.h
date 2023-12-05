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
#pragma warning("You're compiling skyscraper structures in Debug. STL containers will be the wrong size.")
#endif

#include <robin_hood.h>
#include <vulkan/vulkan.h>
#include <windows.h> //see toolkit/system/TkCSMutex.h

#include <array>
#include <atomic>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>

// clang-format off
#define SKYSCRAPER_BEGIN namespace nms {
#define SKYSCRAPER_END };
// clang-format on

#define ALIGN(size) __declspec(align(16))

#define EMPTY_CALL()            return NULL
#define EMPTY_CALL_VOID()       return
#define EMPTY_CALL_DESTRUCTOR() ;