#pragma once

#include <filesystem>
#include <inicpp.h>
#include <renms.h>

using namespace std::filesystem;

RENMS_BEGIN

class ConfigFile
{
  public:
    bool mbShowWarning;

    ConfigFile();
};

RENMS_END

extern renms::ConfigFile gConfigSettings;