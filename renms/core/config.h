#pragma once
#include <filesystem>
#include <renms.h>

RENMS_BEGIN

namespace config
{
    extern bool bShowWarning;

    void init();
    void generate(std::filesystem::path configPath);
};

RENMS_END