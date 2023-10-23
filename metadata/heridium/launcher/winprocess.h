#pragma once

#include <iostream>
#include <filesystem>
#include <windows.h>

PROCESS_INFORMATION CreateProcessFrozen(LPCSTR path);
HANDLE InjectDLL(std::filesystem::path path, HANDLE processHandle);