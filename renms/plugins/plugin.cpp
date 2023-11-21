#include <plugins/plugin.h>

RENMS_BEGIN

Plugin::Plugin(std::string lsDisplayName, std::string lsAuthor, std::string lsDescription, fs::path lPluginPath)
    : msDisplayName(lsDisplayName), msAuthor(lsAuthor), msDescription(lsDescription), mPluginPath(lPluginPath)
{
}

void Plugin::LoadScripts()
{
    fs::path lScriptsPath = this->mPluginPath / "scripts";

    if (exists(lScriptsPath / "main.py")) { ExecutePythonFile(lScriptsPath / "main.py"); }
    else { spdlog::info("No scripts found for {}, skipping step.", this->msDisplayName); }
}

void Plugin::LoadExecutable()
{
    // Get library
    fs::path lLibraryPath = this->mPluginPath / PLUGIN_EXT;

    if (!fs::exists(lLibraryPath))
    {
        spdlog::info("No library found for {}, skipping step.", this->msDisplayName);
        return;
    }

    // Load it
    HMODULE PluginHandle = LoadLibraryA(lLibraryPath.string().c_str());
    if (PluginHandle == NULL)
    {
        spdlog::error(
            "Failed to load plugin library {}: couldn't load {} ", this->msDisplayName,
            lLibraryPath.filename().string());
        return;
    }

    // Execute plugin main
    PluginMain_t pluginEntry = reinterpret_cast<PluginMain_t>(GetProcAddress(PluginHandle, "PluginMain"));
    if (pluginEntry) { pluginEntry(); }
    else
    {
        spdlog::error(
            "Failed to load plugin library {}: Couldn't find: void RENMS_ENTRY PluginMain()", this->msDisplayName);
    }
}

RENMS_END