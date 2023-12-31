/**
 * @file memory.h
 * @author VITALISED & Contributors
 * @since 2023-12-31
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

#include <common/common_pch.h>

#if !defined(RENMS_POINTER_TYPE)
#define RENMS_POINTER_TYPE uint64_t
#endif

#if !defined(RENMS_HALFPOINTER_TYPE)
#define RENMS_HALFPOINTER_TYPE uint32_t
#endif

RENMS_BEGIN

inline HMODULE GetNMSModuleHandle()
{
    return GetModuleHandleA("NMS.exe");
}

inline RENMS_POINTER_TYPE GetNMSModulePointer()
{
    return reinterpret_cast<uint64_t>(GetNMSModuleHandle());
}

RENMS_POINTER_TYPE RelToAbsolute(RENMS_POINTER_TYPE lpRelPtr);
RENMS_POINTER_TYPE CalculateHalfPointerToFull(
    RENMS_HALFPOINTER_TYPE lpHalf, RENMS_POINTER_TYPE lpFull, int liInstructionOffset = 1, int liInstructionLength = 5);
inline std::shared_ptr<std::vector<int>> IDAPatternToVec(const char *lpacSig);
RENMS_POINTER_TYPE SignatureScan_Internal(std::shared_ptr<std::vector<int>> lpPattern);
RENMS_POINTER_TYPE SignatureScan(const char *lpacSignature);

RENMS_END