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

#define SIGNATURE                                                                                      \
    const cTkMetaDataClass *, void (*)(cTkClassPointer *, cTkLinearMemoryPool *),                      \
        void (*)(cTkClassPointer *, bool, unsigned __int64), void (*)(cTkClassPointer *),              \
        bool (*)(const cTkClassPointer *, const cTkClassPointer *), void (*)(cTkClassPointer *),       \
        void (*)(cTkClassPointer *, const cTkClassPointer *), cTkClassPointer *(*)(cTkClassPointer *), \
        unsigned __int64 (*)(const cTkClassPointer *, unsigned __int64, bool), void (*)(cTkClassPointer *)

#define ARGUMENTS                                                                                                      \
    const cTkMetaDataClass *lpClassMetadata, void (*lDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *),       \
        void (*lFixingFunction)(cTkClassPointer *, bool, unsigned __int64),                                            \
        void (*lValidateFunction)(cTkClassPointer *),                                                                  \
        bool (*lEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *),                                     \
        void (*lRenderFunction)(cTkClassPointer *), void (*lCopyFunction)(cTkClassPointer *, const cTkClassPointer *), \
        cTkClassPointer *(*lCreateFunction)(cTkClassPointer * result),                                                 \
        unsigned __int64 (*lHashFunction)(const cTkClassPointer *, unsigned __int64, bool),                            \
        void (*lDestroyFunction)(cTkClassPointer *)

RENMS_HOOK(cTkMetaData__Register, void, ARGUMENTS, SIGNATURE, renms::RelToAbsolute(0x248ABC0), {
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

    return cTkMetaData__Register.CallOriginal(
        lpClassMetadata, lDefaultFunction, lFixingFunction, lValidateFunction, lEqualsFunction, lRenderFunction,
        lCopyFunction, lCreateFunction, lHashFunction, lDestroyFunction);
});

HERIDIUM_BEGIN

void AnalysisInit()
{
    CreateOutputDirectories();

    cTkMetaData__Register.Toggle(true);

    renms::ResumeModuleThread(MODULE_BASE);
}

HERIDIUM_END