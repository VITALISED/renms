#include <core/config.h>
#include <inicpp.h>
using namespace std::filesystem;
using namespace renms::config;

RENMS_BEGIN

// Defaults
bool config::bShowWarning = true;
std::vector<std::pair<std::string, std::pair<void *, uint64_t>>> config::aModFileOverrides =
    std::vector<std::pair<std::string, std::pair<void *, uint64_t>>>();

void config::init()
{
    path nmsPath          = current_path();
    path settingsFilePath = nmsPath / "RENMS/settings.ini";
    std::ifstream settingsIniFile(settingsFilePath);

    if (!settingsIniFile.good())
    {
        generate(settingsFilePath);
        spdlog::warn("No config found, one has been generated at {}", settingsFilePath.string());
        return;
    }
    else { spdlog::info("Config found at {}", settingsFilePath.string()); }

    ini::IniFile pluginIni;
    pluginIni.decode(settingsIniFile);

    if (pluginIni["settings"].contains("show_warning")) bShowWarning = pluginIni["settings"]["show_warning"].as<bool>();
}

void config::generate(path configPath)
{
    ini::IniFile pluginIni;
    pluginIni["settings"]["show_warning"] = bShowWarning;

    std::ofstream settingsIniFile(configPath);
    pluginIni.encode(settingsIniFile);
}

void config::AddModFileOverride(std::pair<std::string, std::pair<void *, uint64_t>> lOverride)
{
    renms::config::aModFileOverrides.push_back(lOverride);
}

RENMS_END