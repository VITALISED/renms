#pragma once

#include <cstring>
#include <filesystem>
#include "framework.h"
#include <spdlog/spdlog.h>
#include "paths.h"
#include <MinHook.h>
#include <fstream>
#include <fmt/format.h>

#define HERIDIUM_BEGIN namespace heridium {
#define HERIDIUM_END }

HERIDIUM_BEGIN

enum HeridiumLanguageType
{
    EHeridiumLanguageType_CXX,
    EHeridiumLanguageType_None,
};

void CreateOutputDirectories();

HERIDIUM_END