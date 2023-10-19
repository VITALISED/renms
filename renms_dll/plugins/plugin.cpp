#include "plugin.h"

RENMS_BEGIN

PluginManager::PluginManager()
{
    this->mPlugins = std::vector<Plugin>();
    this->LoadPluginFolder();
}

void PluginManager::LoadPluginFolder()
{
    
}

RENMS_END