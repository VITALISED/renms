#pragma once

#include <memory/memory.h>
#include <renms.h>
#include <core/config.h>

void cGcApplicationGameModeSelectorState__RenderWarning__DETOUR(
    uint64_t thiscall, const char *lpacWarningTitle, const char *lpacWarningPress, const char *lStatus1, char *lStatus2,
    float lfTimeout);

bool cTkFileSystem__IsModded__DETOUR(uint64_t thiscall);

RENMS_BEGIN

void CreateWarningHooks();

RENMS_END