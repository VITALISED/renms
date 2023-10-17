#pragma once

#include "../renms.h"

#define MODULE_BASE GetModuleHandleA("NMS.exe")
#define OFFSET(lpPtr) (LPVOID)((uintptr_t)MODULE_BASE + (uintptr_t)offset)
#define SIGSCAN(lpacPattern) (LPVOID) RENMS_Memory::ScanPattern(RENMS_Memory::IDAPatternToVec(lpacPattern))

RENMS_BEGIN

constexpr std::vector<int> *IDAPatternToVec(const char *lpacSig)
{
    std::vector<int> *bytes = (std::vector<int> *)malloc(sizeof(std::vector<int>));

    char *cast = const_cast<char *>(lpacSig);
    char *end = const_cast<char *>(lpacSig) + std::strlen(lpacSig);

    for (char *current = cast; current < end; ++current)
    {
        if (*current == '?')
        {
            ++current;

            if (*current == '?')
                ++current;

            bytes->push_back(-1);
        }
        else
        {
            bytes->push_back(std::strtoul(current, &current, 16));
        }
    }

    return bytes;
}

inline LPVOID ScanPattern(std::vector<int> *lpPattern)
{
    const HMODULE module_handle = MODULE_BASE;

    if (!module_handle)
        return NULL;

    PIMAGE_DOS_HEADER dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(module_handle);
    PIMAGE_NT_HEADERS nt_headers =
        reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<std::uint8_t *>(module_handle) + dos_header->e_lfanew);
    DWORD size_of_image = nt_headers->OptionalHeader.SizeOfImage;

    std::array<int, sizeof(*lpPattern)> pattern_bytes = {};
    std::move(lpPattern->begin(), lpPattern->begin() + lpPattern->size(), pattern_bytes.begin());

    free(lpPattern);

    uint8_t *scan_bytes = reinterpret_cast<std::uint8_t *>(module_handle);

    int s = pattern_bytes.size();
    int *d = pattern_bytes.data();

    for (long i = 0ul; i < size_of_image - s; ++i)
    {
        bool found = true;

        for (long j = 0ul; j < s; ++j)
        {
            if (scan_bytes[i + j] != d[j] && d[j] != -1)
            {
                found = false;
                break;
            }
        }
        if (found)
            return (LPVOID)&scan_bytes[i];
    }

    return NULL;
}

RENMS_END