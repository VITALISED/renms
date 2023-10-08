#pragma once

#include "memory.h"

#include <MinHook.h>
#include <fmt/format.h>
#include <string>
#include <spdlog/spdlog.h>

namespace RENMS_Hooks
{
    constexpr void AddHook(LPVOID pTarget, LPVOID pDetour, void *ppOriginal, const char *name)
    {
        const char* formatName = fmt::format("{} ({})", name, pTarget).c_str(); 

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
}