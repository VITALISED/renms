#pragma once

#include <filesystem>

enum HeridiumLanguageType
{
    EHeridiumLanguageType_CXX,
    EHeridiumLanguageType_None,
};

bool Heridium_CreateOutputDirectories(const char* metadata_item_path);