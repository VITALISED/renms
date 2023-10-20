#pragma once

#include "memory.h"
#include "../renms.h"

RENMS_BEGIN

#define INIT_HOOK() namespace __hook_module	\
					{	\
						std::vector<LPVOID*> __ppOriginals = std::vector<LPVOID*>();	\
						std::vector<const char*> __hook_ids = std::vector<const char*>();	\
						MH_STATUS __lastHookRes = MH_UNKNOWN;	\
					}	\

#define HOOK(lpTarget, lpDetour, lpacName) 	LPVOID* __orig__ = (LPVOID*)malloc(sizeof(LPVOID));	\
											__hook_module::__hook_ids.push_back(#lpacName);	\
											__hook_module::__ppOriginals.push_back(__orig__); \
											__hook_module::__lastHookRes = renms::AddHook(lpTarget, lpDetour, __hook_module::__ppOriginals.back(), #lpacName) \

#define CALL_ORIGINAL(lpacName, ...) auto it = std::find(__hook_module::__hook_ids.begin(), __hook_module::__hook_ids.end(), #lpacName); \
									if(it != __hook_module::__hook_ids.end()) \
									{	\
										auto index = it - __hook_module::__hook_ids.begin();	\
										HOOK_TYPE __original__ = *reinterpret_cast<HOOK_TYPE*>(__hook_module::__ppOriginals[index]);	\
										return __original__(__VA_ARGS__);	\
									}

#define HOOK_STATUS() __hook_module::__lastHookRes

inline MH_STATUS AddHook(LPVOID pTarget, LPVOID pDetour, void *ppOriginal, const char *name)
{
	const char *formatName = fmt::format("{} ({})", name, pTarget).c_str();

	MH_STATUS CreateHook = MH_CreateHook(pTarget, pDetour, (LPVOID *)ppOriginal);

	if (CreateHook == MH_OK)
	{
		MH_STATUS EnableHook = MH_EnableHook(pTarget);

		if (EnableHook == MH_OK) {
			spdlog::info("Enabling hook: {}", formatName);
		} else {
			spdlog::error("MH_EnableHook failed for: {} {}", formatName, MH_StatusToString(EnableHook));
			return EnableHook;
		}
	} else {
		spdlog::error("MH_CreateHook failed for: {} {}", formatName, MH_StatusToString(CreateHook));
	}

	return CreateHook;
}

RENMS_END