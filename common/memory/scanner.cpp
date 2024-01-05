/**
 * @file scanner.cpp
 * @author VITALISED & Contributors
 * @since 2024-01-05
 *
 * Copyright (C) 2024  VITALISED & Contributors
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

#include <common/memory/scanner.h>
#include <spdlog/spdlog.h>

RENMS_BEGIN

void SignatureScanner<RENMS_POINTER_TYPE>::IDAPatternToBytes()
{
    std::istringstream iss(this->msPattern);

    std::transform(
        std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(),
        std::back_inserter(*this->mPatternBytes), [](const std::string &s) {
            if (s == "?") { return -1; }
            else { return std::stoi(s, nullptr, 16); }
        });
}

bool SignatureScanner<RENMS_POINTER_TYPE>::ScanInternal(
    uint8_t *lImage, size_t lImageSize, int *lData, size_t lDataSize)
{
    auto it = std::search(lImage, lImage + lImageSize - lDataSize, lData, lData + lDataSize, [](uint8_t lhs, int rhs) {
        return rhs == -1 || lhs == rhs;
    });

    if (it != lImage + lImageSize - lDataSize)
    {
        this->mpResult = reinterpret_cast<SignatureScanner<RENMS_POINTER_TYPE>::PointerType>(it);
        return true;
    }

    return false;
}

SignatureScanner<RENMS_POINTER_TYPE>::PointerType SignatureScanner<RENMS_POINTER_TYPE>::ScanNTDOSHeaders()
{
    const HMODULE lModuleHandle  = GetNMSModuleHandle();
    PIMAGE_DOS_HEADER lDosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(lModuleHandle);
    PIMAGE_NT_HEADERS lNTHeader =
        reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<std::uint8_t *>(lModuleHandle) + lDosHeader->e_lfanew);
    size_t lSizeOfImage = static_cast<size_t>(lNTHeader->OptionalHeader.SizeOfImage);
    uint8_t *lImage     = reinterpret_cast<uint8_t *>(lModuleHandle);

    if (this->ScanInternal(lImage, lSizeOfImage, this->mPatternBytes->data(), this->mPatternBytes->size()))
    {
        spdlog::debug("Found pattern: {}", this->msPattern);
        return this->mpResult;
    }
    else
    {
        spdlog::warn("Could NOT find pattern: {}", this->msPattern);
        return NULL;
    }
}

RENMS_END