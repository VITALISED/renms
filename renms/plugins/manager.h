#pragma once

#include <renms.h>

#include <inicpp.h>
#include <plugins/plugin.h>

RENMS_BEGIN

class PluginManager
{
  public:
    std::vector<Plugin *> mPluginList;

    Plugin *CreatePluginFromManifest(fs::path lPluginPath);
    PluginManager();
};

RENMS_END