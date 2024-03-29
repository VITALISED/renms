/**
 * @file analysis.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-12
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "analysis.h"

RENMS_HOOK(
    cTkMetaData__Register,
    renms::SignatureScan("48 89 5C 24 18 48 89 74 24 20 41 54 41 56 41 57 48 81 EC ? ? ? ? 48 83 3D ? ? ? ? ?"), void,
    (const cTkMetaDataClass *lpClassMetadata, void (*lDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *),
     void (*lFixingFunction)(cTkClassPointer *, bool, uint64_t), void (*lValidateFunction)(cTkClassPointer *),
     bool (*lEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *),
     void (*lRenderFunction)(cTkClassPointer *), void (*lCopyFunction)(cTkClassPointer *, const cTkClassPointer *),
     cTkClassPointer *(*lCreateFunction)(cTkClassPointer *result),
     uint64_t (*lHashFunction)(const cTkClassPointer *, uint64_t, bool), void (*lDestroyFunction)(cTkClassPointer *)) {
        std::string lsKey = lpClassMetadata->mpacName;
        bool lbFoundPath  = false;
        std::string lPath = std::filesystem::current_path().string();

        if (lsKey.find_first_of("c") != std::string::npos) { lsKey = lsKey.substr(lsKey.find_first_of("c")); }

        std::transform(lsKey.begin(), lsKey.end(), lsKey.begin(), [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        });

        lPath.append("/");

        std::for_each(
            gClassPaths.begin(), gClassPaths.end(),
            [&lPath, &lbFoundPath, lsKey](std::pair<const char *, const char *> lItem) {
                if (lItem.first == lsKey)
                {
                    lPath.append(lItem.second);
                    lbFoundPath = true;
                }
            });

        if (!lbFoundPath) lPath.append("/unmapped/").append(lsKey).append(".meta.h");

        spdlog::info(lPath);

        HeridiumCXXFile(lPath, lpClassMetadata);

        return PLH::FnCast(cTkMetaData__Register__TRAMPOLINE, cTkMetaData__Register__DETOUR)(
            lpClassMetadata, lDefaultFunction, lFixingFunction, lValidateFunction, lEqualsFunction, lRenderFunction,
            lCopyFunction, lCreateFunction, lHashFunction, lDestroyFunction);
    });

HERIDIUM_BEGIN

void AnalysisInit()
{
    // renms::SignatureScanner<RENMS_POINTER_TYPE> lScanner = renms::SignatureScanner<RENMS_POINTER_TYPE>(
    //     "48 89 5C 24 18 48 89 74 24 20 41 54 41 56 41 57 48 81 EC ? ? ? ? 48 83 3D ? ? ? ? ?");

    // auto guh =
    //     renms::IDAPatternToVec("48 89 5C 24 18 48 89 74 24 20 41 54 41 56 41 57 48 81 EC ? ? ? ? 48 83 3D ? ? ? ?
    //     ?");

    // std::for_each(guh->begin(), guh->end(), [](int lItem) { spdlog::info("wire {}", lItem); });

    // spdlog::info(lScanner.Scan());
    // spdlog::info(
    //     renms::SignatureScan("48 89 5C 24 18 48 89 74 24 20 41 54 41 56 41 57 48 81 EC ? ? ? ? 48 83 3D ? ? ? ? ?"));
    CreateOutputDirectories();
    RENMS_DISPATCH_HOOK(cTkMetaData__Register);
    renms::ResumeModuleThread(renms::GetNMSModuleHandle());
}

HERIDIUM_END