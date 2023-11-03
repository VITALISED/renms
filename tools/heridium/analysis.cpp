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
#include <memory/thread.h>

INIT_HOOK()

HERIDIUM_BEGIN

void RegisterHook(
    const cTkMetaDataClass *lpClassMetadata, void (*lDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *),
    void (*lFixingFunction)(cTkClassPointer *, bool, unsigned __int64), void (*lValidateFunction)(cTkClassPointer *),
    void (*lRenderFunction)(cTkClassPointer *),
    bool (*lEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *),
    void (*lCopyFunction)(cTkClassPointer *, const cTkClassPointer *),
    cTkClassPointer *(*lCreateFunction)(cTkClassPointer *result),
    unsigned __int64 (*lHashFunction)(const cTkClassPointer *, unsigned __int64, bool),
    void (*lDestroyFunction)(cTkClassPointer *))
{
    std::string lsKey = lpClassMetadata->mpacName;

    if (lsKey.find_first_of("c") != std::string::npos) { lsKey = lsKey.substr(lsKey.find_first_of("c")); }

    std::transform(lsKey.begin(), lsKey.end(), lsKey.begin(), [](unsigned char c) { return (char)std::tolower(c); });

    std::string lPath = std::filesystem::current_path().string();
    lPath.append("/");

    bool lbFoundPath = false;

    for (std::pair<const char *, const char *> lItem : gClassPaths)
    {
        if (lItem.first == lsKey)
        {
            lPath.append(lItem.second);
            lbFoundPath = true;
        }
    }

    if (!lbFoundPath) lPath.append("/unmapped/").append(lsKey).append(".meta.h");

    spdlog::info(lPath);

    HeridiumCXXFile(lPath.c_str(), lpClassMetadata);

    typedef void (*HOOK_TYPE)(
        const cTkMetaDataClass *lpClassMetadata, void (*lDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *),
        void (*lFixingFunction)(cTkClassPointer *, bool, unsigned __int64),
        void (*lValidateFunction)(cTkClassPointer *), void (*lRenderFunction)(cTkClassPointer *),
        bool (*lEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *),
        void (*lCopyFunction)(cTkClassPointer *, const cTkClassPointer *),
        cTkClassPointer *(*lCreateFunction)(cTkClassPointer *result),
        unsigned __int64 (*lHashFunction)(const cTkClassPointer *, unsigned __int64, bool),
        void (*lDestroyFunction)(cTkClassPointer *));

    CALL_ORIGINAL(
        cTkMetaData::Register, lpClassMetadata, lDefaultFunction, lFixingFunction, lValidateFunction, lRenderFunction,
        lEqualsFunction, lCopyFunction, lCreateFunction, lHashFunction, lDestroyFunction);
}

void AnalysisInit()
{
    CreateOutputDirectories();

    HOOK(OFFSET(0x248ABC0), reinterpret_cast<LPVOID>(RegisterHook), cTkMetaData::Register);

    if (HOOK_STATUS() == MH_OK)
        spdlog::info("Ready to analyse some banger metadata");
    else
        spdlog::error("Failed to hook!");

    renms::ResumeModuleThread(MODULE_BASE);
}

HERIDIUM_END