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

#ifdef RENMS

#include <array>
#include <core/framework.h>
#include <core/log.h>
#include <fmt/format.h>
#include <plugins/api.h>
#include <polyhook2/Detour/NatDetour.hpp>
#include <polyhook2/Enums.hpp>
#include <polyhook2/IHook.hpp>
#include <string>
#include <vector>

#endif // RENMS

// clang-format off
#define RENMS_BEGIN namespace renms {
#define RENMS_END }
// clang-format on

// Plugin API for developers
#ifndef RENMS
#include "plugins/api.h"
#endif