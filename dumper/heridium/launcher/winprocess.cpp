/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#include <bitset>
#include "winprocess.h"

PROCESS_INFORMATION CreateProcessFrozen(LPCSTR path) {
    STARTUPINFOA startupInfo;
    PROCESS_INFORMATION processInfo;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    ZeroMemory(&processInfo, sizeof(processInfo));
    startupInfo.cb = sizeof(startupInfo);

    CreateProcessA(
        path,
        NULL,
        NULL,
        NULL,
        FALSE,
        CREATE_SUSPENDED,
        NULL,
        NULL,
        &startupInfo,
        &processInfo
    );

    DWORD lastError = GetLastError();
    if (lastError != 0) {
        std::bitset<32> errorBits(lastError);
        throw std::runtime_error(std::string(
            "Failed to create process, error: {}") + errorBits.to_string()
        );
    }

    return processInfo;
}

HANDLE InjectDLL(std::filesystem::path path, HANDLE processHandle) {
    LPVOID loadLibraryAddress = (LPVOID) GetProcAddress(
        GetModuleHandleA("kernel32.dll"),
        "LoadLibraryA"
    );

    if (!loadLibraryAddress)
        throw std::runtime_error("Failed to get LoadLibraryA address");

    LPVOID remoteString = VirtualAllocEx(
        processHandle,
        NULL,
        path.string().length(),
        MEM_RESERVE | MEM_COMMIT,
        PAGE_READWRITE
    );

    if (!remoteString)
        throw std::runtime_error("Failed to allocate memory in process");

    BOOL wrote = WriteProcessMemory(
        processHandle,
        remoteString,
        path.string().c_str(),
        path.string().length(),
        NULL
    );

    if (!wrote)
        throw std::runtime_error("Failed to write to process memory");

    HANDLE remoteThread = CreateRemoteThread(
        processHandle,
        NULL,
        (SIZE_T)NULL,
        reinterpret_cast<LPTHREAD_START_ROUTINE>(loadLibraryAddress),
        remoteString,
        0,
        NULL
    );

    if (!remoteThread)
        throw std::runtime_error("Failed to create remote thread");

    return remoteThread;
}
