#include <core/config.h>

extern renms::ConfigFile gConfigSettings = {};

RENMS_BEGIN

ConfigFile::ConfigFile()
{
    path nmsPath          = current_path();
    path settingsFilePath = nmsPath / "RENMS/settings.ini";
    std::ifstream settingsIniFile(settingsFilePath);

    this->mbShowWarning = true;

    if (!settingsIniFile.good())
    {
        spdlog::warn("No config found, you can make one at \"No Man's Sky/BINARIES/RENMS/settings.ini\"");
        return;
    }

    ini::IniFile pluginIni;
    pluginIni.decode(settingsIniFile);

    if (pluginIni["settings"].contains("show_warning"))
        this->mbShowWarning = pluginIni["settings"]["show_warning"].as<bool>();
}

RENMS_END