#pragma once
#include <renms.h>

#include <filesystem>

RENMS_BEGIN

namespace config
{

extern bool bShowWarning;
extern std::vector<std::pair<std::string, std::pair<void *, uint64_t>>> aModFileOverrides;

void init();
void generate(std::filesystem::path configPath);
void AddModFileOverride(std::pair<std::string, std::pair<void *, uint64_t>> lOverride);

}; // namespace config

RENMS_END