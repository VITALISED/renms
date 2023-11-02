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

#include "analysis.h"
#include <tlhelp32.h>

INIT_HOOK()

//Do you want to know what all this is for?
//It's all for resuming a thread knowing just the module handle.
//The Windows API is a nightmare...
void ResumeModuleThread(HMODULE hModule) {
    //Get PID from handle
    DWORD dwPID = GetProcessId(hModule);
    HANDLE h = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, dwPID);
    if (h != INVALID_HANDLE_VALUE) {
        THREADENTRY32 te;
        te.dwSize = sizeof(te);
        if (Thread32First(h, &te)) {
            do {
                if (te.dwSize >= FIELD_OFFSET(THREADENTRY32, th32OwnerProcessID) +
                                 sizeof(te.th32OwnerProcessID)) {
                    //If the thread is suspended, resume it
                    if (te.th32OwnerProcessID == GetCurrentProcessId()
                     && te.th32ThreadID != GetCurrentThreadId()
                     && te.dwSize >= FIELD_OFFSET(THREADENTRY32, th32ThreadID) + sizeof(te.th32ThreadID)) {
                        HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);
                        ResumeThread(hThread);
                        CloseHandle(hThread);
                    }
                }
                te.dwSize = sizeof(te);
            } while (Thread32Next(h, &te));
        }
    CloseHandle(h);
    }
}

void RegisterHook(const cTkMetaDataClass* lpClassMetadata,
    void(* lDefaultFunction)(cTkClassPointer*, cTkLinearMemoryPool*),
    void(* lFixingFunction)(cTkClassPointer*, bool, unsigned __int64),
    void(* lValidateFunction)(cTkClassPointer*),
    void(* lRenderFunction)(cTkClassPointer*),
    bool(* lEqualsFunction)(const cTkClassPointer*, const cTkClassPointer*),
    void(* lCopyFunction)(cTkClassPointer*, const cTkClassPointer*),
    cTkClassPointer* (* lCreateFunction)(cTkClassPointer* result),
    unsigned __int64(* lHashFunction)(const cTkClassPointer*, unsigned __int64, bool),
    void(* lDestroyFunction)(cTkClassPointer*))
{
    std::string lsKey = lpClassMetadata->mpacName;
    
    if (lsKey.find_first_of("c") != std::string::npos)
    {
        lsKey = lsKey.substr(lsKey.find_first_of("c"));
    }

    std::transform(lsKey.begin(), lsKey.end(), lsKey.begin(),
        [](unsigned char c) { return (char)std::tolower(c); });

    std::string lPath = std::filesystem::current_path().string();
    lPath.append("/");

    bool lbFoundPath = false;

    for(std::pair<const char*, const char*> lItem : classPaths)
    {
        if(lItem.first == lsKey)
        {
            lPath.append(lItem.second);
            lbFoundPath = true;
        }
    }

    if(!lbFoundPath)
        lPath.append("/unmapped/").append(lsKey).append(".meta.h");

    spdlog::info(lPath);

    HeridiumCXXFile(lPath.c_str(), lpClassMetadata);

    typedef void(*HOOK_TYPE)(
        const cTkMetaDataClass* lpClassMetadata,
        void(* lDefaultFunction)(cTkClassPointer*, cTkLinearMemoryPool*),
        void(* lFixingFunction)(cTkClassPointer*, bool, unsigned __int64),
        void(* lValidateFunction)(cTkClassPointer*),
        void(* lRenderFunction)(cTkClassPointer*),
        bool(* lEqualsFunction)(const cTkClassPointer*, const cTkClassPointer*),
        void(* lCopyFunction)(cTkClassPointer*, const cTkClassPointer*),
        cTkClassPointer* (* lCreateFunction)(cTkClassPointer* result),
        unsigned __int64(* lHashFunction)(const cTkClassPointer*, unsigned __int64, bool),
        void(* lDestroyFunction)(cTkClassPointer*)
    );

    CALL_ORIGINAL(cTkMetaData::Register, lpClassMetadata, lDefaultFunction, lFixingFunction, lValidateFunction, lRenderFunction, lEqualsFunction, lCopyFunction, lCreateFunction, lHashFunction, lDestroyFunction);
}

void AnalysisInit()
{
    heridium::CreateOutputDirectories();

    HOOK(OFFSET(0x248ABC0), reinterpret_cast<LPVOID>(RegisterHook), cTkMetaData::Register);

    if(HOOK_STATUS() == MH_OK)
        spdlog::info("Ready to analyse some banger metadata");
    else
        spdlog::error("Failed to hook!");
    
    ResumeModuleThread(MODULE_BASE);
}

HERIDIUM_BEGIN

// void DoLookupIter()
// {
//     typedef cTkMetaDataFunctionLookup*(*__cTkMetaData__GetLookup__)(const unsigned __int64 luiNameHash);

//     for(std::pair<const char*, const char*> items : classPaths)
//     {
//         std::string fullName = items.first;
//     }
// }

uintptr_t UnpackClassPointerWriteFunc(LPVOID ClassPointerWriteFunction)
{
    //Get the call to Cast() from the Write function
    uintptr_t castCallInstruction = (uintptr_t)ClassPointerWriteFunction + 0x11;
    LPVOID castPtr = renms::RelToAbsolute(castCallInstruction);

    // return address of what's in the mov call in Cast()
    uintptr_t hashAddr = (uintptr_t)castPtr + 0xC;

    return hashAddr;
}

HERIDIUM_END