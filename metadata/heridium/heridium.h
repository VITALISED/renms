#pragma once

#include <filesystem>

enum HeridiumLanguageType
{
    EHeridiumLanguageType_CXX,
    EHeridiumLanguageType_None,
};

constexpr bool Heridium_CreateOutputDirectories(const char* metadata_item_path)
{
#if HERIDIUM_LANGUAGE_TARGET == EHeridiumLanguageType_CXX
    char* local_path = (char*)"/HERIDIUM/cpp";
#else 
    static_assert("No language target defined for heridium");
#endif

    strcat(local_path, metadata_item_path);

    char* full_path = (char*)std::filesystem::current_path().string().c_str(); // peak c++
    strcat(full_path, local_path);

    return std::filesystem::create_directories(full_path);
};