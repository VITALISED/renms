#include <memory/memory.h>
#include <plugins/api.h>
#include <polyhook2/Detour/x64Detour.hpp>

nms::cGcApplication *GetGcApplication()
{
    return reinterpret_cast<nms::cGcApplication *>(renms::RelToAbsolute(GCAPPLICATION));
}

renmshook_t RENMS_API CreateHook(uint64_t lpTarget, uint64_t lpDetour, uint64_t lpTrampoline)
{
    PLH::x64Detour *lpHook = new PLH::x64Detour(lpTarget, lpDetour, &lpTrampoline);

    return reinterpret_cast<renmshook_t>(lpHook);
}

bool RENMS_API DispatchHook(renmshook_t lpHook)
{
    PLH::x64Detour *lpHook_casted = reinterpret_cast<PLH::x64Detour *>(lpHook);

    return lpHook_casted->hook();
}

template <typename FnCastTo>
FnCastTo RENMS_API FnCast(uint64_t fnToCast, FnCastTo)
{
    return (FnCastTo)fnToCast;
}

template <typename FnCastTo>
FnCastTo RENMS_API FnCast(void *fnToCast, FnCastTo)
{
    return (FnCastTo)fnToCast;
}
