#pragma once

#include <cstring>
#include <filesystem>
#include "framework.h"
#include <spdlog/spdlog.h>
#include "paths.h"
#include <MinHook.h>

#define HERIDIUM_BEGIN namespace heridium {
#define HERIDIUM_END }

enum HeridiumLanguageType
{
    EHeridiumLanguageType_CXX,
    EHeridiumLanguageType_None,
};

bool Heridium_CreateOutputDirectories(const char* metadata_item_path);