#pragma once

#include <renms.h>

#include <inicpp.h>
#include <plugins/manager.h>

RENMS_BEGIN

namespace config
{

extern bool gShouldShowWarning;
extern PluginManager *gPluginManager;

void Init();
void Generate(fs::path configPath);

}; // namespace config

RENMS_END