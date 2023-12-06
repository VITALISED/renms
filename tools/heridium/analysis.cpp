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

uint64_t cTkMetaData__Register__TRAMPOLINE = 0;

void cTkMetaData__Register__DETOUR(
    const cTkMetaDataClass *lpClassMetadata, void (*lDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *),
    void (*lFixingFunction)(cTkClassPointer *, bool, unsigned __int64), void (*lValidateFunction)(cTkClassPointer *),
    bool (*lEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *),
    void (*lRenderFunction)(cTkClassPointer *), void (*lCopyFunction)(cTkClassPointer *, const cTkClassPointer *),
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

    HeridiumCXXFile(lPath, lpClassMetadata);

    return PLH::FnCast(cTkMetaData__Register__TRAMPOLINE, cTkMetaData__Register__DETOUR)(
        lpClassMetadata, lDefaultFunction, lFixingFunction, lValidateFunction, lEqualsFunction, lRenderFunction,
        lCopyFunction, lCreateFunction, lHashFunction, lDestroyFunction);
}

PLH::x64Detour cTkMetaData__Register__HOOK(
    (uint64_t)renms::RelToAbsolute(0x248ABC0), (uint64_t)cTkMetaData__Register__DETOUR,
    &cTkMetaData__Register__TRAMPOLINE);

HERIDIUM_BEGIN

void AnalysisInit()
{
    CreateOutputDirectories();

    cTkMetaData__Register__HOOK.hook();

    renms::ResumeModuleThread(renms::GetNMSModuleHandle());
}

HERIDIUM_END