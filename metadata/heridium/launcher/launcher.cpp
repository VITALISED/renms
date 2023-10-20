
#include <filesystem>
#include <bitset>
#include <Windows.h>
#include <shellapi.h>
#include <iostream>
#include <string>
#include <format>
#include <fstream>

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

bool IsUserAdmin() {
    BOOL isAdmin = FALSE;
    PSID adminSID = NULL;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(&ntAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminSID)) {
        if (!CheckTokenMembership(NULL, adminSID, &isAdmin)) {
            isAdmin = FALSE;
        }
        FreeSid(adminSID);
    }
    return isAdmin == TRUE;
}

void UACPrompt(std::string filepath, std::string args = "") {
    SHELLEXECUTEINFOA sei = {
        sizeof(sei),        // cbSize
        0,                  // fMask
        NULL,               // hwnd
        "runas",            // lpVerb
        filepath.c_str(),   // lpFile
        args.c_str(),       // lpParameters
        NULL,               // lpDirectory
        SW_NORMAL,          // nShow
        NULL,               // hInstApp
        NULL,               // lpIDList
        NULL,               // lpClass
        NULL,               // hkeyClass
        0,                  // dwHotKey
        NULL,               // hIcon
        NULL                // hProcess
    };

    if (!ShellExecuteExA(&sei)) {
        DWORD dwError = GetLastError();
        if (dwError == ERROR_CANCELLED)
            throw std::runtime_error("User refused elevation");
        else
            throw std::runtime_error("Failed to elevate");
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

    //WaitForSingleObject(remoteThread, INFINITE);
    //CloseHandle(remoteThread);
    //VirtualFreeEx(processHandle, remoteString, 0, MEM_RELEASE);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << std::endl <<
        "Heridium Launcher by tractorbeam - Developed for the RE:NMS project\n" <<
        std::format("Usage: launcher.exe <path to NMS.exe>\n") << std::flush;
        return 1;
    }

    try {
        if (!IsUserAdmin()) {
            UACPrompt(argv[0], argv[1]);
            return 0;
        }

        std::filesystem::path nmsPath = argv[1];
        std::filesystem::path heridiumPath = "../libHeridium.dll";
        CheckPath(nmsPath, false);
        CheckPath(heridiumPath, true);
        auto nmsProcess = CreateProcessFrozen(argv[1]);
        auto dllProcess = InjectDLL(heridiumPath, nmsProcess.hProcess);

        std::cout << "Press enter when ready..." << std::flush;
        std::cin.get();

        ResumeThread(nmsProcess.hThread);
        ResumeThread(dllProcess);

        std::cout << "Injection successful!" << std::endl;
        return 0;
    } catch (std::exception& e) {
        std::cout << "Error! " << e.what() << std::endl;
        std::ofstream errorfile("./error.log", std::ios::app);
        errorfile << e.what() << std::endl;
        return 1;
    }
}