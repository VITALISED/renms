#pragma once

#include "memory.h"
#include "../renms.h"

RENMS_BEGIN

#define INIT_HOOK() namespace __hook_module	\
					{	\
						std::vector<LPVOID*> __ppOriginals = std::vector<LPVOID*>();	\
						MH_STATUS __lastHookRes = MH_UNKNOWN;	\
					}	\

#define HOOK(lpTarget, lpDetour, lpacName) 	LPVOID* __orig__ = (LPVOID*)malloc(sizeof(LPVOID));	\
											__hook_module::__ppOriginals.push_back(__orig__); \
											__hook_module::__lastHookRes = renms::AddHook(lpTarget, lpDetour, __hook_module::__ppOriginals.back(), #lpacName); \

inline MH_STATUS AddHook(LPVOID pTarget, LPVOID pDetour, void *ppOriginal, const char *name)
{
	const char *formatName = fmt::format("{} ({})", name, pTarget).c_str();

	MH_STATUS CreateHook =MH_CreateHook(pTarget, pDetour, (LPVOID *)ppOriginal);

	if (CreateHook == MH_OK)
	{
		MH_STATUS EnableHook = MH_EnableHook(pTarget);

		if (EnableHook == MH_OK) {
			spdlog::info("Enabling hook: {}", formatName);
		} else {
			spdlog::error("MH_EnableHook failed for: {} {}", formatName, MH_StatusToString(EnableHook));
			return EnableHook;
		}
	}
	
	spdlog::error("MH_CreateHook failed for: {} {}", formatName, MH_StatusToString(CreateHook));
	return CreateHook;
}

RENMS_END