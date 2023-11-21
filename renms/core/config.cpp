#include <core/config.h>

RENMS_BEGIN

bool config::gShouldShowWarning       = true;
PluginManager *config::gPluginManager = NULL;

void config::Init()
{
    fs::path lNNSPath          = fs::current_path();
    fs::path lSettingsFilePath = lNNSPath / "RENMS/settings.ini";
    std::ifstream lSettingsIniFile(lSettingsFilePath);
    ini::IniFile pluginIni;

    bool lbCreatePluginManager = true;

    if (!lSettingsIniFile.good())
    {
        Generate(lSettingsFilePath);
        spdlog::warn("No config found, one has been generated at {}", lSettingsFilePath.string());
        return;
    }
    else { spdlog::info("Config found at {}", lSettingsFilePath.string()); }

    pluginIni.decode(lSettingsIniFile);

    if (pluginIni["settings"].contains("show_warning"))
        gShouldShowWarning = pluginIni["settings"]["show_warning"].as<bool>();

    if (pluginIni["settings"].contains("disable_plugins")) lbCreatePluginManager = false;

    if (lbCreatePluginManager) { gPluginManager = new PluginManager(); }
}

void config::Generate(path configPath)
{
    ini::IniFile pluginIni;

    // Defaults

    pluginIni["settings"]["show_warning"]    = true;
    pluginIni["settings"]["disable_plugins"] = false;

    std::ofstream settingsIniFile(configPath);
    pluginIni.encode(settingsIniFile);
}

RENMS_END