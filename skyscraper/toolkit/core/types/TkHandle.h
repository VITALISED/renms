/**
 * @file TkHandle.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

class TkHandle
{
  public:
    enum
    {
        NumLookupBits      = 0x12,
        NumIncrementorBits = 0xE,
        InvalidLookup      = 0x3FFFF,
    };

    union {
        struct
        {
            uint32_t miLookup : NumLookupBits;
            uint32_t miIncrementor : NumIncrementorBits;
        };
        uint32_t miLookupInt;
    };

    uint64_t GetLookup() { return this->miLookupInt & InvalidLookup; }

    TkHandle *Root(TkHandle *result)
    {
        result->miLookup = 0x40000;
        return result;
    }

    bool operator==(TkHandle lHandle)
    {
        return ((lHandle.miLookupInt ^ this->miLookupInt) & InvalidLookup) == 0 &&
               ((lHandle.miLookupInt ^ this->miLookupInt) & 0xFFFC0000) == 0;
    }

    bool operator!=(TkHandle lHandle)
    {
        return ((lHandle.miLookupInt ^ this->miLookupInt) & InvalidLookup) != 0 &&
               ((lHandle.miLookupInt ^ this->miLookupInt) & 0xFFFC0000) != 0;
    }
};

SKYSCRAPER_END