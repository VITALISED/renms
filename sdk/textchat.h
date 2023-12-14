/**
 * @file textchat.h
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

#include <toolkit/graphics/TkColour.h>
#include <toolkit/utilities/string/TkString.h>

#include "helpers.h"

RENMS_SDK_BEGIN

typedef void (*cGcTextChatManager__PostLocalMessage)(
    nms::cGcTextChatManager *thiscall, nms::cTkFixedString<1121, char> *lsMessage,
    nms::cTkFixedString<128, char> *lpRelevantPlayerName, nms::cTkColour *lBackgroundColour, int liRelevantPlayerIndex,
    float lfDisplayDuration);

void SendTextMessage(nms::cTkFixedString<1121, char> *lsMessageBody);

RENMS_SDK_END