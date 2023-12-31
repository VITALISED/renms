/**
 * @file GcNetworkSyncMessages.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <networking/GcNetworkBufferHash.h>
#include <networking/messages/GcNetworkMessage.h>

SKYSCRAPER_BEGIN

class cGcNetworkSyncMessage : public cGcNetworkMessage
{
  public:
    uint16_t mu16HashOffset;
    uint64_t mu64HashTimestamp;
    uint16_t mHashIndex;
    sHashValue mHashValue;
    int miDataCount;
};

class cGcNetworkHashMessage : public cGcNetworkMessage
{
  public:
    uint16_t mu16HashOffset;
    uint64_t mu64HashTimestamp;
    uint16_t mBufferHashesTotal;
    uint8_t mHashesCount;
    uint16_t maHashIndexes[100];
    sHashValue maHashValues[100];
};

SKYSCRAPER_END