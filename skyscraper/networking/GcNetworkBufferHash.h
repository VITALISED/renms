/**
 * @file GcNetworkBufferHash.h
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

#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

struct sHashValue
{
    uint16_t muHashValue;
    int16_t miTimeStamp;
};

class cGcNetworkBufferHash
{
  public:
    const int kiChunkSize;
    int miChunkHashOffset;
    cTkVector<sHashValue> maChunkHashValues;
    uint64_t mu64Timestamp;
    bool mbInitialised;

    virtual ~cGcNetworkBufferHash();
    virtual sHashValue *GetHashValue(sHashValue *result, unsigned int);
    virtual uint64_t GetHashTimestamp();
    virtual uint16_t GenerateHashValue(int);
    virtual void OnHashOffsetChanged(int);
};

SKYSCRAPER_END