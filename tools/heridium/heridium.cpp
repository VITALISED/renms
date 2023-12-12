/**
 * @file heridium.cpp
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

#include "heridium.h"
#include "framework.h"
#include "paths.h"
#include <cstring>
#include <filesystem>
#include <fmt/format.h>
#include <fstream>
#include <spdlog/spdlog.h>

HERIDIUM_BEGIN

#if HERIDIUM_LANGUAGE_TARGET == EHeridiumLanguageType_CXX
// Might be a thing in the future, will never run the below for now
#else
static_assert("No language target defined for heridium");
#endif

// This also creates the header with all the includes
void CreateOutputDirectories()
{
    std::ofstream lHeaderStream("../metadata/metadata.h");
    lHeaderStream << "#pragma once\n\n";

    for (std::pair<const char *, const char *> lPair : gClassPaths)
    {
        if (std::string(lPair.second) != "source/globals/gcdebugoptions.meta.h")
            lHeaderStream << "#include \"" << lPair.second << "\"\n";

        std::string lpacLocalPath = "/";
        lpacLocalPath.append(lPair.second);

        std::string lpacFullPath = std::filesystem::current_path().string();
        lpacFullPath.append(lpacLocalPath);

        size_t lastindex        = lpacFullPath.find_last_of("/");
        std::string lpacDirPath = lpacFullPath.substr(0, lastindex);

        std::filesystem::create_directories(lpacDirPath);
    }

    lHeaderStream.close();
};

HERIDIUM_END