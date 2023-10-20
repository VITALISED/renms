
#include <filesystem>
#include <Windows.h>
#include <iostream>
#include <string>
#include <format>

void CheckPath(std::filesystem::path path, bool isDLL) {
    if (!std::filesystem::exists(path)) {
        throw std::runtime_error(
            std::format("File not found: {}", path.string()));
    }

    if (!std::filesystem::is_regular_file(path)) {
        throw std::runtime_error(
            std::format("Not a file: {}", path.string()));
    }

    if (isDLL) {
        if (path.extension() != ".dll") {
            throw std::runtime_error(
                std::format("Not a DLL: {}", path.string()));
        }
        return;
    }

    if (path.extension() != ".exe") {
        throw std::runtime_error(
            std::format("Not a valid executable: {}", path.string()));
    }
}

HANDLE CreateProcessFrozen(std::filesystem::path path) {
    STARTUPINFOA startupInfo;
    PROCESS_INFORMATION processInfo;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    ZeroMemory(&processInfo, sizeof(processInfo));
    startupInfo.cb = sizeof(startupInfo);

    bool worked = CreateProcessA(
        (LPCSTR)path.c_str(),
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

    if (!worked) {
        throw std::runtime_error("Failed to create process");
    }

    return processInfo.hProcess;
}

void InjectDLL(std::filesystem::path path, HANDLE processHandle) {
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
        (DWORD)NULL,
        NULL
    );

    if (!remoteThread)
        throw std::runtime_error("Failed to create remote thread");

    WaitForSingleObject(remoteThread, INFINITE);
    CloseHandle(remoteThread);
    VirtualFreeEx(processHandle, remoteString, 0, MEM_RELEASE);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << std::endl <<
        "Heridium Launcher by tractorbeam - Developed for the RE:NMS project\n" <<
        std::format("Usage: launcher.exe <path to NMS.exe>\n") <<
        "(Hint: You can just drag and drop the exe over the launcher)\n\n" << std::flush;
        return 1;
    }

    try {
        std::filesystem::path nmsPath = argv[1];
        std::filesystem::path heridiumPath = "../libHeridium.dll";
        CheckPath(nmsPath, false);
        CheckPath(heridiumPath, true);
        HANDLE nmsProcess = CreateProcessFrozen(nmsPath);
        InjectDLL(heridiumPath, nmsProcess);
        ResumeThread(nmsProcess);

        std::cout << "Injection successful!" << std::endl;
        return 0;
    } catch (std::exception& e) {
        std::cout << "Exception Occurred: " << e.what() << std::endl;
        return 1;
    }
}