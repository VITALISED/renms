#pragma once

#include <renms.h>
#include <tlhelp32.h>

RENMS_BEGIN

// should move this to a source file im just lazy right now
inline void ResumeModuleThread(HMODULE hModule)
{
    // Get PID from handle
    DWORD dwPID = GetProcessId(hModule);
    HANDLE h    = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, dwPID);
    if (h != INVALID_HANDLE_VALUE)
    {
        THREADENTRY32 te;
        te.dwSize = sizeof(te);
        if (Thread32First(h, &te))
        {
            do {
                if (te.dwSize >= FIELD_OFFSET(THREADENTRY32, th32OwnerProcessID) + sizeof(te.th32OwnerProcessID))
                {
                    // If the thread is suspended, resume it
                    if (te.th32OwnerProcessID == GetCurrentProcessId() && te.th32ThreadID != GetCurrentThreadId() &&
                        te.dwSize >= FIELD_OFFSET(THREADENTRY32, th32ThreadID) + sizeof(te.th32ThreadID))
                    {
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

RENMS_END