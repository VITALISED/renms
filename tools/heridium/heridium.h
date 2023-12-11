/**
 * @file heridium.h
 * @author VITALISED & Contributors
 * @since 2023-12-12
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

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "framework.h"
#include "paths.h"

// clang-format off
#define HERIDIUM_BEGIN namespace heridium {
#define HERIDIUM_END }
// clang-format on

HERIDIUM_BEGIN

enum HeridiumLanguageType
{
    EHeridiumLanguageType_CXX,
    EHeridiumLanguageType_None,
};

void CreateOutputDirectories();

HERIDIUM_END