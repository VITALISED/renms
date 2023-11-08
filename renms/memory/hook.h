#pragma once

#include <memory/memory.h>
#include <renms.h>

RENMS_BEGIN

#define RENMS_HOOK(name, offset, detour)                                     \
    auto name##_fnCastRes = PLH::FnCast(offset, detour);                     \
    renms::HookController<decltype(name##_fnCastRes), PLH::NatDetour> name = \
        renms::HookController<decltype(name##_fnCastRes), PLH::NatDetour>(   \
            PLH::HookType::Detour, reinterpret_cast<uint64_t>(offset), reinterpret_cast<uint64_t>(detour))

#define RENMS_CALLORIGINAL(name, ...) PLH::FnCast(name.mpHookTrampoline, name.mpDetour)(__VA_ARGS__)

template <typename Fn, typename HookClass>
class HookController
{
    uint64_t mpOffset;

  public:
    using type = Fn;

    PLH::HookType mHookType;
    Fn mpDetour;
    HookClass mHook;
    uint64_t mpHookTrampoline;
    HookController(PLH::HookType lHookType, uint64_t lpOffset, uint64_t lpDetour);
    bool Dispatch();
    bool Remove();
};

RENMS_END