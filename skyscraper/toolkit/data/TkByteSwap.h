/**
 * @file TkByteSwap.h
 * @author VITALISED & Contributors
 * @since 2023-12-23
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

#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkByteSwap
{
  public:
    static uint32_t inline GetLowValOf64(uint64_t lValue)
    {
        uint32_t lowerBitsValue = static_cast<uint32_t>(lValue);

        return lowerBitsValue + (lowerBitsValue == 0 ? 1 : 0);
    }

    static uint32_t GetHighValOf64(uint64_t lValue)
    {
        uint32_t highBitsValue = static_cast<uint32_t>(lValue >> 32);
        uint32_t rotatedValue  = static_cast<uint32_t>((lValue << 16) | (lValue >> 16));

        return static_cast<uint32_t>(lValue) ^ highBitsValue ^ rotatedValue;
    }
};

SKYSCRAPER_END