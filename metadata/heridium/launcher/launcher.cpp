
#include <filesystem>
#include <bitset>
#include <Windows.h>
#include <shellapi.h>
#include <vector>
#include <iostream>
#include <string>
#include <format>

#ifdef _MSC_VER
#define HERIDIUM_LIB "Heridium.dll"
#else
#define HERIDIUM_LIB "libHeridium.dll"
#endif

void WaitToClose(int code) {
    if (code == -1) {   //started without elevation
        exit(code);

    } else if (code == 0) {
        std::cout << "\n";
        for (int i = 5; i >= 0; i--) {
            std::cout << std::format("\rClosing in {}...", i) << std::flush;
            Sleep(1000);
        }
        std::cout << std::endl;
        exit(code);

    } else {
        std::cout << "\nPress enter to close..." << std::flush;
        std::cin.get();
        exit(code);
    }
}

void CheckPath(std::filesystem::path path, std::string filename) {
    if (std::filesystem::is_directory(path)) {
        path /= filename;
    }
    
    if (!std::filesystem::exists(path)) {
        throw std::runtime_error(
            std::format("File not found: {}", path.string()));
    }

    if (!std::filesystem::is_regular_file(path)) {
        throw std::runtime_error(
            std::format("Not a file: {}", path.string()));
    }

    if (path.filename() != filename) {
        throw std::runtime_error(
            std::format("Not the right kind of file: got {}, expected {}", path.filename().string(), filename));
    }
}

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
        throw std::runtime_error(std::format(
            "Failed to create process, error: {}", errorBits.to_string()
        ));
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
        CREATE_SUSPENDED,
        NULL
    );

    if (!remoteThread)
        throw std::runtime_error("Failed to create remote thread");

    return remoteThread;
}

int main(int argc, char** argv) {
    std::cout << std::endl <<
    "Heridium Launcher by tractorbeam - Developed for the RE:NMS project\n" << std::flush;

    try {
        std::filesystem::path exePath, nmsPath, heridiumPath;
        exePath = argv[0];

        if (argc < 2) {
            nmsPath = exePath.parent_path();
            nmsPath /= "NMS.exe";
        } else
            nmsPath = argv[1];

        heridiumPath = exePath.parent_path();
        heridiumPath /= HERIDIUM_LIB;
        CheckPath(nmsPath, "NMS.exe");
        CheckPath(heridiumPath, HERIDIUM_LIB);

        std::cout << "Loading NMS.exe...\n" << std::flush;
        auto nmsProcess = CreateProcessFrozen(argv[1]);
        std::cout << "Injecting the DLL...\n" << std::flush;
        auto dllProcess = InjectDLL(heridiumPath, nmsProcess.hProcess);

        std::cout << "Initializing the DLL...\n" << std::flush;
        ResumeThread(dllProcess);
        Sleep(1000);
        ResumeThread(nmsProcess.hThread);

        std::cout << "Injection successful!\n\n" << std::endl;
        WaitToClose(0);
    } catch (std::exception& e) {
        std::cout << "Error! " << e.what() << std::endl;
        WaitToClose(1);
    }
}