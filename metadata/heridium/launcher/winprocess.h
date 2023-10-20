#pragma once

#include <iostream>
#include <filesystem>
#include <format>
#include <windows.h>

PROCESS_INFORMATION CreateProcessFrozen(LPCSTR path);
HANDLE InjectDLL(std::filesystem::path path, HANDLE processHandle);