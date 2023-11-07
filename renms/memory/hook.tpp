#pragma once

#include <memory/hook.h>
#include <renms.h>

RENMS_BEGIN

template <typename Fn, typename HookClass>
HookController<Fn, HookClass>::HookController(PLH::HookType lHookType, uint64_t lpOffset, uint64_t lpDetour)
    : mHookType(lHookType), mpOffset(lpOffset), mpDetour(reinterpret_cast<Fn>(lpDetour))
{
    this->mpHookTrampoline = NULL;

    if (this->mHookType == PLH::HookType::Detour)
    {
        this->mHook = static_cast<PLH::IHook>(PLH::NatDetour(this->mpOffset, this->mpDetour, this->mpHookTrampoline));
    }
}

template <typename Fn, typename HookClass>
bool HookController<Fn, HookClass>::Dispatch()
{
    return this->mHook.hook();
}

template <typename Fn, typename HookClass>
bool HookController<Fn, HookClass>::Remove()
{
    return this->mHook.unHook();
}

RENMS_END