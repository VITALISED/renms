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

#include <cstdint>
#include <cmath>
#include <windows.h>    //see toolkit/system/TkCSMutex.h
#include <functional>
#include <array>
#include <string>
#include <unordered_map>
#include <memory>
#include <map>
#include <vulkan/vulkan.h>
#include <robin_hood.h>
//#include <Havok/hkVector4f.h>
//#include <Havok/hknpMassDistribution.h>
//#include <Havok/hknpConstraintId.h>
//#include <Havok/hknpBodyId.h>
//#include <Havok/hknpRefPtr.h>
#include <deque>
#include <forward_list>

#define SKYSCRAPER_BEGIN namespace nms {
#define SKYSCRAPER_END };