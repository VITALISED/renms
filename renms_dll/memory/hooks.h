#pragma once

#include "memory.h"
#include "../renms.h"

RENMS_BEGIN

inline void AddHook(LPVOID pTarget, LPVOID pDetour, void *ppOriginal, const char *name)
{
	const char *formatName = fmt::format("{} ({})", name, pTarget).c_str();

	if (MH_CreateHook(pTarget, pDetour, (LPVOID *)ppOriginal) == MH_OK)
	{
		if (MH_EnableHook(pTarget) == MH_OK)
			spdlog::info("Enabling hook: {}", formatName);
		else
			spdlog::error("MH_EnableHook failed for: {}", formatName);
	}
	else
		spdlog::error("MH_CreateHook failed for: {}", formatName);
}

RENMS_END