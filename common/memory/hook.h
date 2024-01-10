/**
 * @file hook.h
 * @author VITALISED & Contributors
 * @since 2023-12-31
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <common/common_pch.h>
#include <common/memory/memory.h>
#include <common/memory/scanner.h>
#include <common/memory/trampoline.h>
#include <common/types/function_traits.h>
#include <polyhook2/Detour/NatDetour.hpp>
#include <polyhook2/Enums.hpp>
#include <polyhook2/IHook.hpp>
#include <polyhook2/PE/IatHook.hpp>

#if RENMS_POINTER_TYPE != uint64_t
#pragma message( \
    "RENMS_POINTER_TYPE does not equal uint64_t, if it isn't implicitly castable PolyHook might have problems.")
#endif

RENMS_BEGIN

inline std::string replace_hookid(std::string lsName)
{
    size_t liPos = lsName.find("__");
    if (liPos != std::string::npos) { return lsName.replace(liPos, 2, "::"); }
    return lsName;
}

struct DetourThreadFlags
{
    inline DetourThreadFlags()
    {
        this->mxCallOriginalWithResult = false;
        this->muiPriority              = 0;
    }

    inline DetourThreadFlags(uint32_t luiPriority, bool lbCallOriginalWithResult)
    {
        this->mxCallOriginalWithResult = lbCallOriginalWithResult;
        this->muiPriority              = luiPriority;
    }

    bool mxCallOriginalWithResult;
    uint32_t muiPriority;
};

#define RENMS_CAST(name, ...) PLH::FnCast(name##__TRAMPOLINE, name##__DETOUR)(__VA_ARGS__)

#define RENMS_HOOK(name, offset, return_type, detour_fn)              \
    RENMS_POINTER_TYPE name##__TRAMPOLINE = NULL;                     \
    return_type name##__DETOUR detour_fn PLH::x64Detour name##__HOOK( \
        offset, reinterpret_cast<RENMS_POINTER_TYPE>(name##__DETOUR), &name##__TRAMPOLINE)

#define RENMS_IAT_HOOK(name, module, return_type, detour_fn)        \
    RENMS_POINTER_TYPE name##__TRAMPOLINE = NULL;                   \
    return_type name##__DETOUR detour_fn PLH::IatHook name##__HOOK( \
        module, #name, reinterpret_cast<RENMS_POINTER_TYPE>(name##__DETOUR), &name##__TRAMPOLINE, L"NMS.exe");

#define RENMS_DISPATCH_HOOK(name)                                                                 \
    if (name##__HOOK.hook()) { spdlog::info("Enabling hook: {}", renms::replace_hookid(#name)); } \
    else { spdlog::error("Failed to enable hook: {}", renms::replace_hookid(#name)); }

#define DECLARE_METHOD_DETAIL(name, typeid, signature)                   \
    class name##_                                                        \
    {                                                                    \
      public:                                                            \
        using TypeID = typeid;                                           \
        static uint64_t gLastSortSize;                                   \
        static std::vector<std::function<TypeID>> gCallbacks;            \
        static std::vector<renms::DetourThreadFlags> gDetourThreadFlags; \
        static RENMS_POINTER_TYPE gTrampoline;                           \
        static constexpr const char *gFunctionSignature = signature;     \
    };

#define DECLARE_DETAIL_IMPL_NOTRAMPOLINE(name)                         \
    std::vector<std::function<name##_::TypeID>> name##_::gCallbacks;   \
    std::vector<renms::DetourThreadFlags> name##_::gDetourThreadFlags; \
    uint64_t name##_::gLastSortSize = 0;                               \
    uint64_t name##_::gTrampoline   = NULL;

#define DECLARE_HOOK(name, hook)         \
    name##_::gCallbacks.push_back(hook); \
    name##_::gDetourThreadFlags.push_back(renms::DetourThreadFlags());

#define DECLARE_HOOK_FLAGS(name, hook, flags) \
    name##_::gCallbacks.push_back(hook);      \
    name##_::gDetourThreadFlags.push_back(renms::DetourThreadFlags(flags));

// Detour must be class##_##name

#define ADD_HOOK_CALLBACK_V(class, name, detour, ...)                                                                  \
    detour                                                                                                             \
    {                                                                                                                  \
        if (class## ::##name##_::gLastSortSize != class## ::##name##_::gCallbacks.size())                              \
        {                                                                                                              \
            std::vector<std::pair<std::function<class## ::##name##_::TypeID>, renms::DetourThreadFlags>> lPairedVec(   \
                class## ::##name##_::gCallbacks.size());                                                               \
            for (size_t i = 0; i < class## ::##name##_::gCallbacks.size(); i++)                                        \
            {                                                                                                          \
                lPairedVec[i] =                                                                                        \
                    std::make_pair(class## ::##name##_::gCallbacks[i], class## ::##name##_::gDetourThreadFlags[i]);    \
            }                                                                                                          \
            std::sort(lPairedVec.begin(), lPairedVec.end(), [](auto &lhs, auto &rhs) {                                 \
                return lhs.second.muiPriority < rhs.second.muiPriority;                                                \
            });                                                                                                        \
            for (size_t i = 0; i < class## ::##name##_::gCallbacks.size(); i++)                                        \
            {                                                                                                          \
                class## ::##name##_::gCallbacks[i]         = lPairedVec[i].first;                                      \
                class## ::##name##_::gDetourThreadFlags[i] = lPairedVec[i].second;                                     \
            }                                                                                                          \
            class## ::##name##_::gLastSortSize = class## ::##name##_::gCallbacks.size();                               \
        }                                                                                                              \
                                                                                                                       \
        for (std::function<class## ::##name##_::TypeID> lFn : class## ::##name##_::gCallbacks)                         \
        {                                                                                                              \
            bool lbShouldReturnImmediately = false;                                                                    \
            std::for_each(                                                                                             \
                class## ::##name##_::gDetourThreadFlags.begin(), class## ::##name##_::gDetourThreadFlags.end(),        \
                [&lbShouldReturnImmediately](renms::DetourThreadFlags &lFlags) {                                       \
                    if (lFlags.mxCallOriginalWithResult) { lbShouldReturnImmediately = true; }                         \
                });                                                                                                    \
            if (lbShouldReturnImmediately)                                                                             \
            {                                                                                                          \
                lFn(__VA_ARGS__);                                                                                      \
                return;                                                                                                \
            }                                                                                                          \
            lFn(__VA_ARGS__);                                                                                          \
        }                                                                                                              \
                                                                                                                       \
        reinterpret_cast<std::add_pointer_t<class## ::##name##_::TypeID>>(class## ::##name##_::gTrampoline)(           \
            __VA_ARGS__);                                                                                              \
        return;                                                                                                        \
    }                                                                                                                  \
    void class##_##name##_ctor()                                                                                       \
    {                                                                                                                  \
        RENMS_POINTER_TYPE class##_##name##__TRAMPOLINE = NULL;                                                        \
        uint64_t offset = renms::SignatureScanner<RENMS_POINTER_TYPE>(class## ::##name##_::gFunctionSignature).Scan(); \
        static PLH::x64Detour class##_##name##__HOOK(                                                                  \
            offset, reinterpret_cast<RENMS_POINTER_TYPE>(class##_##name), &class##_##name##__TRAMPOLINE);              \
        class## ::##name##_::gCallbacks         = std::vector<std::function<class## ::##name##_::TypeID>>();           \
        class## ::##name##_::gDetourThreadFlags = std::vector<renms::DetourThreadFlags>();                             \
        if (class##_##name##__HOOK.hook()) { spdlog::info("Enabling hook: {}", #class "::" #name); }                   \
        else { spdlog::warn("Failed to enable hook: {}", #class "::" #name); }                                         \
    }

#define ADD_HOOK_CALLBACK(class, name, detour, ...)                                                                    \
    detour                                                                                                             \
    {                                                                                                                  \
        if (class## ::##name##_::gLastSortSize != class## ::##name##_::gCallbacks.size())                              \
        {                                                                                                              \
            std::vector<std::pair<std::function<class## ::##name##_::TypeID>, renms::DetourThreadFlags>> lPairedVec(   \
                class## ::##name##_::gCallbacks.size());                                                               \
            for (size_t i = 0; i < class## ::##name##_::gCallbacks.size(); i++)                                        \
            {                                                                                                          \
                lPairedVec[i] =                                                                                        \
                    std::make_pair(class## ::##name##_::gCallbacks[i], class## ::##name##_::gDetourThreadFlags[i]);    \
            }                                                                                                          \
            std::sort(lPairedVec.begin(), lPairedVec.end(), [](auto &lhs, auto &rhs) {                                 \
                return lhs.second.muiPriority < rhs.second.muiPriority;                                                \
            });                                                                                                        \
            for (size_t i = 0; i < class## ::##name##_::gCallbacks.size(); i++)                                        \
            {                                                                                                          \
                class## ::##name##_::gCallbacks[i]         = lPairedVec[i].first;                                      \
                class## ::##name##_::gDetourThreadFlags[i] = lPairedVec[i].second;                                     \
            }                                                                                                          \
            class## ::##name##_::gLastSortSize = class## ::##name##_::gCallbacks.size();                               \
        }                                                                                                              \
                                                                                                                       \
        for (std::function<class## ::##name##_::TypeID> lFn : class## ::##name##_::gCallbacks)                         \
        {                                                                                                              \
            bool lbShouldReturnImmediately = false;                                                                    \
            std::for_each(                                                                                             \
                class## ::##name##_::gDetourThreadFlags.begin(), class## ::##name##_::gDetourThreadFlags.end(),        \
                [&lbShouldReturnImmediately](renms::DetourThreadFlags &lFlags) {                                       \
                    if (lFlags.mxCallOriginalWithResult) { lbShouldReturnImmediately = true; }                         \
                });                                                                                                    \
            if (lbShouldReturnImmediately) { return lFn(__VA_ARGS__); }                                                \
            lFn(__VA_ARGS__);                                                                                          \
        }                                                                                                              \
        return reinterpret_cast<std::add_pointer_t<class## ::##name##_::TypeID>>(class## ::##name##_::gTrampoline)(    \
            __VA_ARGS__);                                                                                              \
    }                                                                                                                  \
    void class##_##name##_ctor()                                                                                       \
    {                                                                                                                  \
        uint64_t offset = renms::SignatureScanner<RENMS_POINTER_TYPE>(class## ::##name##_::gFunctionSignature).Scan(); \
        static PLH::x64Detour class##_##name##__HOOK(                                                                  \
            offset, reinterpret_cast<RENMS_POINTER_TYPE>(class##_##name), &class## ::##name##_::gTrampoline);          \
        class## ::##name##_::gCallbacks         = std::vector<std::function<class## ::##name##_::TypeID>>();           \
        class## ::##name##_::gDetourThreadFlags = std::vector<renms::DetourThreadFlags>();                             \
        if (class##_##name##__HOOK.hook()) { spdlog::info("Enabling hook: {}", #class "::" #name); }                   \
        else { spdlog::warn("Failed to enable hook: {}", #class "::" #name); }                                         \
    }

#define SETUP_CALLBACK_DETOUR_ENTRY(...) \
    void SetupCallbackEntries()          \
    {                                    \
        __VA_ARGS__                      \
    }

#define INVOKE_CALLBACK_CONSTRUCTORS()
#define INVOKE_CALLBACK_ENTRY(class, name)   class##_##name##_ctor();
#define ADD_CALLBACK_DEFINITION(class, name) void class##_##name##_ctor();
#define SKYSCRAPER_CALLBACK_ENTRY_DEF()      void SetupCallbackEntries()
#define SKYSCRAPER_CALLBACK_ENTRY()          nms::SetupCallbackEntries()
#define SKYSCRAPER_CALLBACK_DEFINITIONS(...) __VA_ARGS__

#define DECLARE_METHOD_IMPLEMENTATION(class, method)

RENMS_END