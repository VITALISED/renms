#pragma once

#include <filesystem>
#include "framework.h"

#define HERIDIUM_BEGIN namespace heridium {
#define HERIDIUM_END }

enum HeridiumLanguageType
{
    EHeridiumLanguageType_CXX,
    EHeridiumLanguageType_None,
};

bool Heridium_CreateOutputDirectories(const char* metadata_item_path);