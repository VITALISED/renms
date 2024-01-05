/**
 * @file scanner.h
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

#pragma once

#include <common/common_pch.h>
#include <common/memory/memory.h>
#include <common/platform/wine.h>

#include <cstdio>

RENMS_BEGIN

template <typename _PtrTy>
class SignatureScanner
{
  public:
    using PointerType = _PtrTy;

    inline SignatureScanner(std::string lsPattern)
    {
        this->msPattern     = std::string(lsPattern);
        this->mPatternBytes = std::make_shared<std::vector<int>>();
        this->IDAPatternToBytes();
    }

    inline SignatureScanner(std::string &lsPattern)
    {
        this->msPattern     = std::string(lsPattern);
        this->mPatternBytes = std::make_shared<std::vector<int>>();
        this->IDAPatternToBytes();
    }

    inline PointerType Scan()
    {
        if (IsPlatformWine())
        {
            spdlog::warn("Scanning with wine using the internal strategy will probably not work!");
        }
        return this->ScanNTDOSHeaders();
    }

    PointerType ScanNTDOSHeaders();

  private:
    bool ScanInternal(uint8_t *lImage, size_t lImageSize, int *lData, size_t lDataSize);
    void IDAPatternToBytes();
    std::shared_ptr<std::vector<int>> mPatternBytes;
    std::string msPattern;
    PointerType mpResult;
};

RENMS_END