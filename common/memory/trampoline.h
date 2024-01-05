/**
 * @file trampoline.h
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
#include <common/memory/scanner.h>

RENMS_BEGIN

template <typename Fn>
class Trampoline
{
  public:
    inline Trampoline(RENMS_POINTER_TYPE lpAddress) { this->mpAddress = lpAddress; }

    inline Trampoline(std::string lsPattern) : mScanner(lsPattern)
    {
        this->mpAddress  = mScanner.Scan();
        this->mpFunction = Cast(this->mpAddress);
    }

    inline Fn Cast(RENMS_POINTER_TYPE lpFunction) { return reinterpret_cast<Fn>(lpFunction); }

    template <typename... Args>
    inline auto Invoke(Args... lArgs)
    {
        return (mpFunction(std::forward<Args>(lArgs)...));
    }

  private:
    SignatureScanner<RENMS_POINTER_TYPE> mScanner;
    Fn mpFunction;
    RENMS_POINTER_TYPE mpAddress;
};

RENMS_END