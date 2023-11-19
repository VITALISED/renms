#pragma once

#include <renms.h>

#include <memory/memory.h>

RENMS_BEGIN

inline std::string replace_hookid(std::string lsName)
{
    size_t liPos = lsName.find("__");

    if (liPos != std::string::npos) { return lsName.replace(liPos, 2, "::"); }

    return lsName;
}

#define RENMS_CAST(name, ...) PLH::FnCast(name##__TRAMPOLINE, name##__DETOUR)(__VA_ARGS__)

#define RENMS_HOOK(name, offset, return_type, detour_fn)              \
    uint64_t name##__TRAMPOLINE = NULL;                               \
    return_type name##__DETOUR detour_fn PLH::x64Detour name##__HOOK( \
        reinterpret_cast<uint64_t>(offset), reinterpret_cast<uint64_t>(name##__DETOUR), &name##__TRAMPOLINE)

#define RENMS_IAT_HOOK(name, module, return_type, detour_fn)        \
    uint64_t name##__TRAMPOLINE = NULL;                             \
    return_type name##__DETOUR detour_fn PLH::IatHook name##__HOOK( \
        module, #name, reinterpret_cast<uint64_t>(name##__DETOUR), &name##__TRAMPOLINE, L"NMS.exe");

#define RENMS_DISPATCH_HOOK(name)                                                          \
    if (name##__HOOK.hook()) { spdlog::info("Enabling hook: {}", replace_hookid(#name)); } \
    else { spdlog::error("Failed to enable hook: {}", replace_hookid(#name)); }

RENMS_END