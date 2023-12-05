/**
 * @file renms.h
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

#if defined(RENMS)

#include <core/framework.h>
#include <core/log.h>
#include <fmt/format.h>
#include <polyhook2/Detour/NatDetour.hpp>
#include <polyhook2/Enums.hpp>
#include <polyhook2/IHook.hpp>
#include <polyhook2/PE/IatHook.hpp>

#include <array>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

#endif // defined(RENMS)

// clang-format off
#define RENMS_BEGIN namespace renms {
#define RENMS_END }
// clang-format on

// Plugin API for developers
#if !defined(RENMS)
#include "plugins/api.h"
#endif //! defined(RENMS)