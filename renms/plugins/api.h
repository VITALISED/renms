#pragma once

// #include <application/GcApplication.h>

typedef uint64_t renmshook_t;

#ifdef RENMS
#define RENMS_ENTRY __declspec(dllimport)
#else
#define RENMS_ENTRY __declspec(dllexport)
#endif

#define RENMS_API extern

#define GCAPPLICATION 0x49707E0

void RENMS_ENTRY PluginMain();
void RENMS_ENTRY PluginUpdate(float lfTimeStep);

typedef decltype(PluginMain) *PluginMain_t;
typedef decltype(PluginUpdate) *PluginUpdate_t;

renmshook_t RENMS_API CreateHook(uint64_t lpTarget, uint64_t lpDetour, uint64_t lpTrampoline);
bool RENMS_API DispatchHook(renmshook_t lpHook);
uint64_t RENMS_API GetGcApplication();

// re-exported from PLH

template <typename FnCastTo>
FnCastTo RENMS_API FnCast(uint64_t fnToCast, FnCastTo);

template <typename FnCastTo>
FnCastTo RENMS_API FnCast(void *fnToCast, FnCastTo);