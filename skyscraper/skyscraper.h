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
#include <robin_hood.h>
#include <string>
#include <unordered_map>
#include <vulkan/vulkan.h>
#include <windows.h> //see toolkit/system/TkCSMutex.h

// clang-format off
#define SKYSCRAPER_BEGIN namespace nms {
#define SKYSCRAPER_END };
// clang-format on

SKYSCRAPER_BEGIN

template <unsigned int uiLength>
class VFT
{
  public:
    maMembers[uiLength];
};

SKYSCRAPER_END