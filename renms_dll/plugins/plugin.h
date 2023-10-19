#pragma once

#include "../renms.h"

RENMS_BEGIN

class Plugin
{
    const char* mpacName;
    const char* mpacDisplayName;
    const char* mpacAuthor;
    const char* mpacDescription;
    HMODULE mHModule;
};

class PluginManager
{
    std::vector<Plugin> mPlugins;

    PluginManager();
    void LoadPluginFolder();
    void Load(const char* lpacPluginName);
    void Unload(const char* lpacPluginName);
    void Reload(const char* lpacPluginName);
};

RENMS_END