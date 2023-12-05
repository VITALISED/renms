/**
 * @file generic.h
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

#include <renms.h>

RENMS_BEGIN

class ScriptGeneric
{
  public:
    size_t miSize;
    std::string msTypeId;
    void *mpVal;

    ScriptGeneric(size_t liSize, std::string lsTypeId, void *lpVal) : miSize(liSize), msTypeId(lsTypeId), mpVal(lpVal)
    {
    }
};

template <typename T>
T script_cast(ScriptGeneric castee)
{
    if (castee.miSize == sizeof(T) && typeid(T) == castee.msTypeId) { return *reinterpret_cast<T>(castee.mpVal); }

#if defined(_DEBUG)
    spdlog::error("Can't cast to {} (from {})", typeid(T), castee.msTypeId);
#endif

    return NULL;
}

RENMS_END