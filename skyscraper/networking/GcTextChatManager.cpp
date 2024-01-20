/**
 * @file GcTextChatManager.cpp
 * @author VITALISED & Contributors
 * @since 2024-01-02
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

#include <networking/GcTextChatManager.h>

SKYSCRAPER_BEGIN

void cGcTextChatManager::PostLocalMessage(
    const cTkFixedString<1121, char> *lsMessage, const cTkFixedString<128, char> *lpRelevantPlayerName,
    const cTkColour *lBackgroundColour, int liRelevantPlayerIndex, float lfDisplayDuration)
{
    typedef void (*fn_type)(
        cGcTextChatManager *thiscall, const cTkFixedString<1121, char> *lsMessage,
        const cTkFixedString<128, char> *lpRelevantPlayerName, const cTkColour *lBackgroundColour,
        int liRelevantPlayerIndex, float lfDisplayDuration);

    reinterpret_cast<fn_type>(renms::SignatureScan(
        "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 48 89 7C 24 20 41 56 48 81 EC ? ? ? ? 4D 8B D0"))(
        this, lsMessage, lpRelevantPlayerName, lBackgroundColour, liRelevantPlayerIndex, lfDisplayDuration);
}

SKYSCRAPER_END
